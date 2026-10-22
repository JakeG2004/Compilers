#include <iostream>

#include "semanticanalyzer.h"
#include "errorhandler.h"
#include "symboltable.h"
#include "parser.tab.h"

SemanticAnalyzer* SemanticAnalyzer::instance = nullptr;

SemanticAnalyzer::SemanticAnalyzer(bool stDebug)
{
    symbolTable = new SymbolTable();
    symbolTable->debug(stDebug);
}

void SemanticAnalyzer::Analyze(TreeNode* node, bool isScopeBody)
{
    if(node == nullptr)
        return;

    InsertNodeIfReqd(node);

    // initialized declarations and parameters never trigger uninitialized warnings
    if(node->nodeType == TreeNode::NodeType::DECLNODE &&
       (node->subType.decl == TreeNode::DeclType::PARMTYPE || (node->subType.decl == TreeNode::DeclType::VARTYPE && node->leftChild != nullptr)))
        node->initializedAt = node;

    bool openedScope = EnterScopeIfReqd(node, isScopeBody);

    if(node->nodeType == TreeNode::NodeType::STMTNODE && node->subType.stmt == TreeNode::StmtType::FORTYPE && node->leftChild)
        node->leftChild->initializedAt = node->leftChild;

    // the target of an assignment is written, not read, so nothing in it warns about being uninitialized
    if(node->leftChild != nullptr && IsAssignmentOp(node))
        ResolveWithoutWarn(node->leftChild);

    CheckForSymbolErrors(node);

    // identifiers in a for-range are never resolved: no undeclared errors, no uninit warnings, and they don't count as uses
    bool isRange = node->nodeType == TreeNode::NodeType::STMTNODE && node->subType.stmt == TreeNode::StmtType::RANGETYPE;

    if(!isRange) {
        Analyze(node->leftChild);
        Analyze(node->middleChild, IsFunction(node));
        Analyze(node->rightChild, IsLoop(node));
    }

    // compound assignment (+=, ...) also leaves its target initialized
    if(node->leftChild != nullptr && IsAssignmentOp(node) && GetSymbolToken(node) != ASSIGN && GetSymbolToken(node) != COLON) {
        TreeNode* target = IsInArray(node->leftChild) ? LookupNode(node->leftChild->leftChild, false) : LookupNode(node->leftChild, false);
        if(target != nullptr)
            target->initializedAt = node;
    }

    // operator checks run after the operands so errors come out operands first
    CheckForOperatorErrors(node);
    CheckForReturnErrors(node);
    CheckForRangeErrors(node);

    ExitScopeIfReqd(node, openedScope);
    Analyze(node->sibling);
}

void SemanticAnalyzer::StartAnalysis(TreeNode* node)
{
    instance = this;

    Analyze(node, true);
    symbolTable->applyToAll(CheckUsageOnScopeExit);
    CheckForMain();
}

// ============================
// === BULK CHECK FUNCTIONS ===
// ============================

void SemanticAnalyzer::CheckForOperatorErrors(TreeNode* node) 
{
    int symToken = GetSymbolToken(node);

    switch(symToken) {
        case LBRACKET:
            CheckLBracketErrors(node);
            break;

        case ASSIGN:
        case COLON:
            CheckAssignErrors(node);
            break;

        case ADDASS:
        case SUBASS:
        case MULASS:
        case DIVASS:
        case MIN:
        case MAX:
        case PLUS:
        case DIVIDE:
        case MOD:
            CheckLHSRHSErrors(node, TreeNode::VarType::INTEGER);
            break;

        case LEQ:
        case LT:
        case GT:
        case GEQ:
        case EQ:
        case NEQ:
            CheckComparisonErrors(node);
            break;

        case INC:
        case DEC:
        case QUESTION:
        case NOT:
            CheckUnaryOpErrors(node);
            break;

        case MINUS:
            CheckMinusErrors(node);
            break;

        case STAR:
            CheckStarErrors(node);
            break;

        case AND:
        case OR:
            CheckLHSRHSErrors(node, TreeNode::VarType::BOOLEAN);
            break;
    }
}

void SemanticAnalyzer::CheckForSymbolErrors(TreeNode* node)
{
    if(node->nodeType == TreeNode::NodeType::EXPNODE) {
        switch(node->subType.exp) {
            case TreeNode::ExpType::IDTYPE:
                CheckUninitIDErrors(node);
                break;

            case TreeNode::ExpType::CALLTYPE:
                CheckCallErrors(node);
                break;
        }
    }
}

void SemanticAnalyzer::CheckForReturnErrors(TreeNode* node)
{
    if(node->nodeType == TreeNode::NodeType::STMTNODE && node->subType.stmt == TreeNode::StmtType::RETURNTYPE && node->leftChild != nullptr)
        if(IsArray(ResolveOperand(node->leftChild)))
            ErrorHandler::AddRetArrError(node);
}

static void ClearRangeTypes(TreeNode* node)
{
    if(node == nullptr)
        return;

    if(!(node->nodeType == TreeNode::NodeType::EXPNODE && node->subType.exp == TreeNode::ExpType::CONSTTYPE))
        node->varType = TreeNode::VarType::UNDEFINED;

    ClearRangeTypes(node->leftChild);
    ClearRangeTypes(node->middleChild);
    ClearRangeTypes(node->rightChild);
}

void SemanticAnalyzer::CheckForRangeErrors(TreeNode* node)
{
    if(node->nodeType == TreeNode::NodeType::STMTNODE && node->subType.stmt == TreeNode::StmtType::RANGETYPE) {
        ClearRangeTypes(node->leftChild);
        ClearRangeTypes(node->middleChild);
        ClearRangeTypes(node->rightChild);
    }
}

void SemanticAnalyzer::ResolveWithoutWarn(TreeNode* node)
{
    if(node == nullptr)
        return;

    if(node->nodeType == TreeNode::NodeType::EXPNODE && node->subType.exp == TreeNode::ExpType::IDTYPE)
        node->declaredAt = LookupNode(node, false);

    ResolveWithoutWarn(node->leftChild);
    ResolveWithoutWarn(node->middleChild);
    ResolveWithoutWarn(node->rightChild);
}

// Operator nodes are their own result; everything else is looked up in the symbol table
TreeNode* SemanticAnalyzer::ResolveOperand(TreeNode* node)
{
    return IsOperator(node) ? node : LookupNode(node);
}

void SemanticAnalyzer::CheckUsageOnScopeExit(std::string sym, void* node)
{
    TreeNode* treeNode = (TreeNode*)node;
    bool isVar = (treeNode->subType.decl == TreeNode::DeclType::VARTYPE);
    bool isParm = (treeNode->subType.decl == TreeNode::DeclType::PARMTYPE);
    bool isFunc = (treeNode->subType.decl == TreeNode::DeclType::FUNCTYPE);

    if ((treeNode->declaredAt == nullptr) && !treeNode->isUsed && (isVar || isParm || isFunc) && sym != "main") {
        ErrorHandler::AddUnusedVarWarn(treeNode, instance->symbolTable->depth() == 1);
    }
}

// ========================
// === OPERATOR CHECKS ===
// =======================

void SemanticAnalyzer::CheckLBracketErrors(TreeNode* node)
{
    // inspectedAt == node means this '[' was already checked (CheckLHSRHSErrors sets it to the parent, so no clash)
    if(node->inspectedAt == node)
        return;
    node->inspectedAt = node;

    TreeNode* baseArr = LookupNode(node->leftChild);
    TreeNode* idx = IsOperator(node->middleChild) ? node->middleChild : LookupNode(node->middleChild);

    node->varType = GetTypeOf(baseArr);

    if(IsFuncUse(node->leftChild, baseArr))
        ErrorHandler::AddFunVarError(node->leftChild);
    if(IsFuncUse(node->middleChild, idx))
        ErrorHandler::AddFunVarError(node->middleChild);

    if(!IsArray(baseArr))
        ErrorHandler::AddIdxNonArrError(node->leftChild);

    if(idx == nullptr)
        return;

    if(GetTypeOf(idx) != TreeNode::VarType::INTEGER)
        ErrorHandler::AddArrIdxTypeError(node, GetTypeStringOf(idx));

    if(IsArray(idx))
        ErrorHandler::AddIdxWithArrError(node, idx->tokenData->tokenStr);
}

void SemanticAnalyzer::CheckAssignErrors(TreeNode* node)
{
    TreeNode* lhs = IsInArray(node->leftChild) ? node->leftChild : LookupNode(node->leftChild, false);
    TreeNode* rhs = IsOperator(node->middleChild) ? node->middleChild : LookupNode(node->middleChild);
    
    if(!rhs || !lhs)
        return;

    lhs->initializedAt = rhs;

    // assigning to an element counts as initializing the array
    if(IsInArray(node->leftChild)) {
        TreeNode* arrDecl = LookupNode(node->leftChild->leftChild, false);
        if(arrDecl != nullptr)
            arrDecl->initializedAt = rhs;
    }

    bool leftIsArr = IsArray(lhs);
    bool rightIsArr = IsArray(rhs);

    TreeNode::VarType leftType = GetTypeOf(lhs);
    TreeNode::VarType rightType = GetTypeOf(rhs);

    node->varType = rightType;

    if(leftType == TreeNode::VarType::UNDEFINED || rightType == TreeNode::VarType::UNDEFINED)
        return;

    if(IsFunction(lhs)) {
        ErrorHandler::AddFunVarError(node->leftChild);
        return;
    }

    if(leftType != rightType)
        ErrorHandler::AddBothOpTypeError(node, GetTypeStringOf(leftType), GetTypeStringOf(rightType));

    if((leftIsArr && !rightIsArr) || (!leftIsArr && rightIsArr))
        ErrorHandler::AddBothOpArrError(node, leftIsArr, rightIsArr);
}

void SemanticAnalyzer::CheckLHSRHSErrors(TreeNode* node, TreeNode::VarType type)
{
    node->varType = type;

    TreeNode* lhs = IsOperator(node->leftChild) ? node->leftChild : LookupNode(node->leftChild);
    TreeNode* rhs = IsOperator(node->middleChild) ? node->middleChild : LookupNode(node->middleChild);

    if(rhs == nullptr || lhs == nullptr)
        return;

    bool leftIsFunc = IsFuncUse(node->leftChild, lhs);
    bool rightIsFunc = IsFuncUse(node->middleChild, rhs);
    if(leftIsFunc)
        ErrorHandler::AddFunVarError(node->leftChild);
    if(rightIsFunc)
        ErrorHandler::AddFunVarError(node->middleChild);
    if(leftIsFunc || rightIsFunc)
        return;

    lhs->inspectedAt = node;
    rhs->inspectedAt = node;

    TreeNode::VarType leftType = GetTypeOf(lhs);
    TreeNode::VarType rightType = GetTypeOf(rhs);

    if(leftType == TreeNode::VarType::UNDEFINED || rightType == TreeNode::VarType::UNDEFINED) {
        if(IsArray(lhs) || IsArray(rhs))
            ErrorHandler::AddNonArrOpError(node);
        return;
    }

    if(leftType != type)
        ErrorHandler::AddLHSOpError(node, GetTypeStringOf(type), GetTypeStringOf(leftType));

    if(rightType != type)
        ErrorHandler::AddRHSOpError(node, GetTypeStringOf(type), GetTypeStringOf(rightType));

    if(IsArray(lhs) || IsArray(rhs))
        ErrorHandler::AddNonArrOpError(node);
}

void SemanticAnalyzer::CheckUnaryOpErrors(TreeNode* node) 
{
    TreeNode* lhs = ResolveOperand(node->leftChild);
    if(lhs == nullptr)
        return;

    if(IsFuncUse(node->leftChild, lhs)) {
        ErrorHandler::AddFunVarError(node->leftChild);
        return;
    }

    TreeNode::VarType checkType = TreeNode::VarType::INTEGER;

    if(node->tokenData->tokenClass == NOT) {
        checkType = TreeNode::VarType::BOOLEAN;
    }

    if(GetTypeOf(lhs) != checkType)
        ErrorHandler::AddUnaryOpError(node, GetTypeStringOf(checkType), GetTypeStringOf(lhs));

    if(lhs->isArray)
        ErrorHandler::AddNonArrOpError(node);
}

void SemanticAnalyzer::CheckMinusErrors(TreeNode* node)
{
    if(node->isUnary)
        CheckUnaryOpErrors(node);
    else
        CheckLHSRHSErrors(node, TreeNode::VarType::INTEGER);
}

void SemanticAnalyzer::CheckStarErrors(TreeNode* node)
{
    if(!(node->isUnary)) {
        CheckLHSRHSErrors(node, TreeNode::VarType::INTEGER);
        return;
    }

    TreeNode* lhs = ResolveOperand(node->leftChild);

    if(IsFuncUse(node->leftChild, lhs)) {
        ErrorHandler::AddFunVarError(node->leftChild);
        return;
    }

    if(lhs != nullptr && !(lhs->isArray))
        ErrorHandler::AddOnlyArrOpError(node);
}

void SemanticAnalyzer::CheckComparisonErrors(TreeNode* node)
{
    TreeNode* lhs = ResolveOperand(node->leftChild);
    TreeNode* rhs = ResolveOperand(node->middleChild);

    bool leftIsFunc = IsFuncUse(node->leftChild, lhs);
    bool rightIsFunc = IsFuncUse(node->middleChild, rhs);
    if(leftIsFunc)
        ErrorHandler::AddFunVarError(node->leftChild);
    if(rightIsFunc)
        ErrorHandler::AddFunVarError(node->middleChild);
    if(leftIsFunc || rightIsFunc)
        return;

    if(GetTypeOf(lhs) == TreeNode::VarType::UNDEFINED || GetTypeOf(rhs) == TreeNode::VarType::UNDEFINED)
        return;

    if(GetTypeOf(lhs) != GetTypeOf(rhs))
        ErrorHandler::AddBothOpTypeError(node, GetTypeStringOf(lhs), GetTypeStringOf(rhs));

    bool leftIsArr = IsArray(lhs);
    bool rightIsArr = IsArray(rhs);
    if(leftIsArr != rightIsArr)
        ErrorHandler::AddBothOpArrError(node, leftIsArr, rightIsArr);
}

// =====================
// === SYMBOL CHECKS ===
// =====================

void SemanticAnalyzer::CheckUninitIDErrors(TreeNode* node)
{
    LookupNode(node);
}

void SemanticAnalyzer::CheckCallErrors(TreeNode* node)
{
    TreeNode* result = LookupNode(node, false);

    for(TreeNode* arg = node->leftChild; arg != nullptr; arg = arg->sibling) {
        if(arg->nodeType == TreeNode::NodeType::EXPNODE && arg->subType.exp == TreeNode::ExpType::IDTYPE && IsFunction(LookupNode(arg, false)))
            ErrorHandler::AddFunVarError(arg);
    }

    if(!result)
        return;

    if(result->nodeType == TreeNode::NodeType::DECLNODE && result->subType.decl != TreeNode::DeclType::FUNCTYPE)
        ErrorHandler::AddVarCallError(node);
}

// ==========================
// === ST NODE MANAGEMENT ===
// ==========================

void SemanticAnalyzer::InsertNodeIfReqd(TreeNode* node, bool force)
{
    if(node->nodeType != TreeNode::NodeType::DECLNODE && !force)
        return;

    bool cleanInsert = true;

    if(symbolTable->depth() == 1)
        cleanInsert = symbolTable->insertGlobal(node->tokenData->tokenStr, (void*)node);
    else
        cleanInsert = symbolTable->insert(node->tokenData->tokenStr, (void*)node);

    if(!cleanInsert) {
        LookupNode(node);
        ErrorHandler::AddReDeclError(node);
    }
}

TreeNode* SemanticAnalyzer::LookupNode(TreeNode* node, bool issueUninitWarn)
{
    if(node->declaredAt != nullptr) {
        node->varType = node->declaredAt->varType;
        return node->declaredAt;
    }

    if(node->nodeType == TreeNode::NodeType::EXPNODE && node->subType.exp == TreeNode::ExpType::CONSTTYPE)
        return node;

    TreeNode* treeResult = LookupNode(node->tokenData->tokenStr, issueUninitWarn);

    if(treeResult == nullptr) {
        if(node->inspectedAt == nullptr) {
            ErrorHandler::AddUnDeclError(node);
            node->inspectedAt = node;
        }
        return treeResult;
    }

    node->varType = treeResult->varType;

    bool isDeclNode = (node->nodeType == TreeNode::NodeType::DECLNODE);
    if(!isDeclNode)
        treeResult->isUsed = true;

    bool isGlobalSym = (symbolTable->lookupGlobal(node->tokenData->tokenStr) == (void*)treeResult);

    if(treeResult->initializedAt == nullptr && !isDeclNode && issueUninitWarn && !(node->nodeType == TreeNode::NodeType::EXPNODE && node->subType.exp == TreeNode::ExpType::CALLTYPE) && !IsFunction(treeResult) && !isGlobalSym && !treeResult->isStatic) {
        ErrorHandler::AddUninitVarWarn(node);
        treeResult->initializedAt = treeResult;
    }

    // Don't cache a silent lookup of a still-uninitialized variable, or the warning is lost later
    if(issueUninitWarn || treeResult->initializedAt != nullptr || isDeclNode || isGlobalSym || IsFunction(treeResult))
        node->declaredAt = treeResult;
    return treeResult;
}

TreeNode* SemanticAnalyzer::LookupNode(std::string node, bool issueUninitWarn)
{
    void* lookupResult = nullptr;
    if(symbolTable->depth() == 1)
        lookupResult = symbolTable->lookupGlobal(node);
    else
        lookupResult = symbolTable->lookup(node);

    return (TreeNode*)lookupResult;
}

// =====================
// === BASIC HELPERS ===
// =====================

bool SemanticAnalyzer::IsArray(TreeNode* node)
{
    if(node == nullptr)
        return false;

    return node->isArray;
}

bool SemanticAnalyzer::IsFunction(TreeNode* node)
{
    if(node == nullptr)
        return false;

    if(node->nodeType == TreeNode::NodeType::DECLNODE && node->subType.decl == TreeNode::DeclType::FUNCTYPE)
        return true;

    return false;
}

bool SemanticAnalyzer::IsLoop(TreeNode* node)
{
    if(node == nullptr)
        return false;

    if(node->nodeType == TreeNode::NodeType::STMTNODE && node->subType.stmt == TreeNode::StmtType::WHILETYPE)
        return true;

    if(node->nodeType == TreeNode::NodeType::STMTNODE && node->subType.stmt == TreeNode::StmtType::FORTYPE)
        return true;

    return false;
}

bool SemanticAnalyzer::IsCompound(TreeNode* node)
{
    if(node == nullptr)
        return false;

    if(node->nodeType == TreeNode::NodeType::STMTNODE && node->subType.stmt == TreeNode::StmtType::COMPOUNDTYPE)
        return true;

    return false;
}

bool SemanticAnalyzer::IsOperator(TreeNode* node)
{
    int symToken = GetSymbolToken(node);

    switch(symToken) {
        case LBRACKET:
        case ASSIGN:
        case COLON:
        case ADDASS:
        case SUBASS:
        case MULASS:
        case DIVASS:
        case MIN:
        case MAX:
        case PLUS:
        case DIVIDE:
        case MOD:
        case LEQ:
        case LT:
        case GT:
        case GEQ:
        case EQ:
        case NEQ:
        case INC:
        case DEC:
        case QUESTION:
        case MINUS:
        case STAR:
        case AND:
        case OR:
        case NOT:
            return true;

        default:
            return false;
    }
}

bool SemanticAnalyzer::IsInArray(TreeNode* node)
{
    int symToken = GetSymbolToken(node);
    if(symToken != LBRACKET)
        return false;

    return true;
}

bool SemanticAnalyzer::IsAssignmentOp(TreeNode* node)
{
    switch(node->tokenData->tokenClass) {
        case ASSIGN:
        case COLON:
        case ADDASS:
        case SUBASS:
        case MULASS:
        case DIVASS:
            return true;
        default:
            return false;
    }
}

bool SemanticAnalyzer::IsFuncUse(TreeNode* operand, TreeNode* resolved)
{
    return operand != nullptr && resolved != nullptr &&
           operand->nodeType == TreeNode::NodeType::EXPNODE && operand->subType.exp == TreeNode::ExpType::IDTYPE &&
           resolved->nodeType == TreeNode::NodeType::DECLNODE && resolved->subType.decl == TreeNode::DeclType::FUNCTYPE;
}

int SemanticAnalyzer::GetSymbolToken(TreeNode* node)
{
    return node->tokenData->tokenClass;
}

TreeNode::VarType SemanticAnalyzer::GetTypeOf(TreeNode* node)
{
    if(node == nullptr)
        return TreeNode::VarType::UNDEFINED;

    if(IsInArray(node))
        return GetTypeOf(LookupNode(node->leftChild, false));

    if(node->varType == TreeNode::VarType::UNDEFINED && IsOperator(node)) {
        int symToken = GetSymbolToken(node);
        switch(symToken) {
            case PLUS:
            case MINUS:
            case STAR:
            case DIVIDE:
            case MOD:
            case ADDASS:
            case SUBASS:
            case MULASS:
            case DIVASS:
            case MIN:
            case MAX:
            case INC:
            case DEC:
                return TreeNode::VarType::INTEGER;

            case LEQ:
            case LT:
            case GT:
            case GEQ:
            case EQ:
            case NEQ:
            case AND:
            case OR:
            case NOT:
                return TreeNode::VarType::BOOLEAN;

            case COLON:
            case ASSIGN:
                return GetTypeOf(LookupNode(node->middleChild, false));

            case LBRACKET:
                return GetTypeOf(LookupNode(node->leftChild, false));

            default:
                break;
        }
    }

    return node->varType;
}

std::string SemanticAnalyzer::GetTypeStringOf(TreeNode* node)
{
    return GetTypeStringOf(GetTypeOf(node));
}

std::string SemanticAnalyzer::GetTypeStringOf(TreeNode::VarType type)
{
    switch(type) {
        case TreeNode::VarType::VOID:
            return std::string("void");
            break;

        case TreeNode::VarType::INTEGER:
            return std::string("int");
            break;

        case TreeNode::VarType::BOOLEAN:
            return std::string("bool");
            break;

        case TreeNode::VarType::CHARACTER:
            return std::string("char");
            break;

        case TreeNode::VarType::STRING:
            return std::string("string");
            break;

        case TreeNode::VarType::UNDEFINED:
            return std::string("undef");
            break;

        default:
            return std::string("unknown");
            break;
    }
}

// ========================
// === SCOPE MANAGEMENT ===
// ========================

bool SemanticAnalyzer::EnterScopeIfReqd(TreeNode* node, bool isScopeBody)
{
    bool addScope = IsFunction(node) || IsLoop(node) || (IsCompound(node) && !isScopeBody);
    if(addScope) symbolTable->enter(node->tokenData->tokenStr);
    return addScope;
}

bool SemanticAnalyzer::ExitScopeIfReqd(TreeNode* node, bool openedScope)
{
    instance = this;

    if(openedScope && symbolTable->depth() > 1) {
        symbolTable->applyToAll(CheckUsageOnScopeExit);
        symbolTable->leave();
        return true;
    }
    return false;
}

void SemanticAnalyzer::CheckForMain()
{
    TreeNode* mainNode = LookupNode("main");
    // main() must be a function that takes no parameters
    if(mainNode == nullptr || !IsFunction(mainNode) || mainNode->leftChild != nullptr) {
        ErrorHandler::AddNoMainError();
    }
}

bool SemanticAnalyzer::IsConst(TreeNode* node)
{
    if(node == nullptr)
        return false;

    if(node->nodeType == TreeNode::NodeType::EXPNODE && node->subType.exp == TreeNode::ExpType::CONSTTYPE)
        return true;

    return false;
}