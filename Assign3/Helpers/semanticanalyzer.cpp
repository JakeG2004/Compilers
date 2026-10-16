#include <iostream>

#include "semanticanalyzer.h"
#include "errorhandler.h"
#include "symboltable.h"
#include "parser.tab.h"

SemanticAnalyzer::SemanticAnalyzer(bool stDebug)
{
    symbolTable = new SymbolTable();
    symbolTable->debug(stDebug);
    symbolTable->enter(std::string("Global"));
}

void SemanticAnalyzer::Analyze(TreeNode* node, bool isScopeBody)
{
    if(node == nullptr)
        return;

    InsertNodeIfReqd(node);
    bool openedScope = EnterScopeIfReqd(node, isScopeBody);

    CheckForOperatorErrors(node);
    CheckForSymbolErrors(node);

    Analyze(node->leftChild);
    Analyze(node->middleChild, IsFunction(node));
    Analyze(node->rightChild, IsLoop(node));

    ExitScopeIfReqd(node, openedScope);
    Analyze(node->sibling);
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

        case NOT:
            if(GetTypeOf(node->leftChild) != TreeNode::VarType::BOOLEAN)
                ErrorHandler::AddLHSOpError(node, GetTypeStringOf(TreeNode::VarType::BOOLEAN), GetTypeStringOf(node->leftChild->varType));
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

void SemanticAnalyzer::CheckUsageOnScopeExit(std::string sym, void* node)
{
    TreeNode* treeNode = (TreeNode*)node;
    bool isVar = (treeNode->subType.decl == TreeNode::DeclType::VARTYPE);
    bool isParm = (treeNode->subType.decl == TreeNode::DeclType::PARMTYPE);

    if ((treeNode->declaredAt == nullptr) && (isVar || isParm) && sym != "main") {
        ErrorHandler::AddUnusedVarWarn(treeNode);
    }
}

// ========================
// === OPERATOR CHECKS ===
// =======================

void SemanticAnalyzer::CheckLBracketErrors(TreeNode* node)
{
    TreeNode* baseArr = LookupNode(node->leftChild);
    TreeNode* idx = LookupNode(node->middleChild);

    if(IsFunction(baseArr))
        ErrorHandler::AddFunVarError(node->leftChild);
    if(IsFunction(idx))
        ErrorHandler::AddFunVarError(node->middleChild);

    if(GetTypeOf(idx) != TreeNode::VarType::INTEGER) {
        ErrorHandler::AddArrIdxTypeError(node, GetTypeStringOf(idx));
    }

    if(IsArray(idx))
        ErrorHandler::AddIdxWithArrError(node, idx->tokenData->tokenStr);

    if(!IsArray(baseArr))
        ErrorHandler::AddIdxNonArrError(node->leftChild);
}

void SemanticAnalyzer::CheckAssignErrors(TreeNode* node)
{
    TreeNode* rhs = IsOperator(node->middleChild) ? node->middleChild : LookupNode(node->middleChild);
    TreeNode* lhs = LookupNode(node->leftChild, false);

    if(!rhs || !lhs)
        return;

    lhs->initializedAt = rhs;

    bool leftIsArr = IsArray(lhs);
    bool rightIsArr = IsArray(rhs);

    TreeNode::VarType leftType = GetTypeOf(lhs);
    TreeNode::VarType rightType = GetTypeOf(rhs);

    if(leftType != rightType)
        ErrorHandler::AddBothOpTypeError(node, GetTypeStringOf(leftType), GetTypeStringOf(rightType));

    if((leftIsArr && !rightIsArr) || (!leftIsArr && rightIsArr))
        ErrorHandler::AddBothOpArrError(node, leftIsArr, rightIsArr);
}

void SemanticAnalyzer::CheckLHSRHSErrors(TreeNode* node, TreeNode::VarType type)
{
    TreeNode* lhs = IsOperator(node->leftChild) ? node->leftChild : LookupNode(node->leftChild);
    TreeNode* rhs = IsOperator(node->middleChild) ? node->middleChild : LookupNode(node->middleChild);

    if(rhs == nullptr || lhs == nullptr)
        return;

    lhs->inspectedAt = node;
    rhs->inspectedAt = node;

    if(IsArray(lhs) || IsArray(rhs)) {
        ErrorHandler::AddNonArrOpError(node);
        return;
    }

    if(GetTypeOf(rhs) != type)
        ErrorHandler::AddRHSOpError(node, GetTypeStringOf(type), GetTypeStringOf(rhs));

    if(GetTypeOf(lhs) != type)
        ErrorHandler::AddLHSOpError(node, GetTypeStringOf(type), GetTypeStringOf(lhs));
}

void SemanticAnalyzer::CheckUnaryOpErrors(TreeNode* node) 
{
    TreeNode* lhs = LookupNode(node->leftChild);

    if(lhs->isArray) {
        ErrorHandler::AddNonArrOpError(node);
        return;
    }

    if(GetTypeOf(lhs) != TreeNode::VarType::INTEGER)
        ErrorHandler::AddUnaryOpError(node, GetTypeStringOf(TreeNode::VarType::INTEGER), GetTypeStringOf(lhs));
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

    TreeNode* lhs = LookupNode(node->leftChild);

    if(!(lhs->isArray))
        ErrorHandler::AddOnlyArrOpError(node);
}

void SemanticAnalyzer::CheckComparisonErrors(TreeNode* node)
{
    TreeNode* lhs = LookupNode(node->leftChild);
    TreeNode* rhs = LookupNode(node->middleChild);

    if(GetTypeOf(lhs) != GetTypeOf(rhs))
        ErrorHandler::AddBothOpTypeError(node, GetTypeStringOf(lhs), GetTypeStringOf(rhs));
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
    TreeNode* result = LookupNode(node);
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
    if(node->declaredAt != nullptr)
        return node->declaredAt;

    if(node->nodeType == TreeNode::NodeType::EXPNODE && node->subType.exp == TreeNode::ExpType::CONSTTYPE)
        return node;

    void* lookupResult = nullptr;
    if(symbolTable->depth() == 1)
        lookupResult = symbolTable->lookupGlobal(node->tokenData->tokenStr);
    else
        lookupResult = symbolTable->lookup(node->tokenData->tokenStr);

    TreeNode* treeResult = (TreeNode*)lookupResult;

    if(treeResult == nullptr && node->inspectedAt == nullptr) {
        ErrorHandler::AddUnDeclError(node);
        return treeResult;
    }

    if(treeResult->initializedAt == nullptr && node->nodeType != TreeNode::NodeType::DECLNODE && issueUninitWarn && !IsFunction(treeResult)) {
        ErrorHandler::AddUninitVarWarn(node);
        treeResult->initializedAt = treeResult;
    }

    node->declaredAt = treeResult;
    return treeResult;
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

int SemanticAnalyzer::GetSymbolToken(TreeNode* node)
{
    return node->tokenData->tokenClass;
}

TreeNode::VarType SemanticAnalyzer::GetTypeOf(TreeNode* node)
{
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
    if(openedScope && symbolTable->depth() > 1) {
        symbolTable->applyToAll(CheckUsageOnScopeExit);
        symbolTable->leave();
        return true;
    }

    return false;
}