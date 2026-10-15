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

void SemanticAnalyzer::Analyze(TreeNode* node, bool canAddNewScope)
{
    if(node == nullptr)
        return;

    EnterScopeIfReqd(node, &canAddNewScope);

    InsertNodeIfReqd(node);

    CheckForOperatorErrors(node);

    Analyze(node->leftChild);
    Analyze(node->middleChild);
    Analyze(node->rightChild);
    Analyze(node->sibling);

    ExitScopeIfReqd(node);
}

void SemanticAnalyzer::EnterScopeIfReqd(TreeNode* node, bool* canAddNewScope)
{
    bool addScope = false;

    // Compound statements when the flag is set
    if(node->nodeType == TreeNode::NodeType::STMTNODE && (node->subType.stmt == TreeNode::StmtType::COMPOUNDTYPE))  {
        if(*canAddNewScope == false) // reset the canaddnewscope variable
            *canAddNewScope = true;
        else
            addScope = true;
    }

    // functions always
    if(node->nodeType == TreeNode::NodeType::DECLNODE && (node->subType.decl == TreeNode::DeclType::FUNCTYPE))
        addScope = true;
    
    if(addScope)
        symbolTable->enter(node->tokenData->tokenStr);
}

void SemanticAnalyzer::ExitScopeIfReqd(TreeNode* node)
{
    if(node->subType.stmt == TreeNode::StmtType::COMPOUNDTYPE && symbolTable->depth() > 1) {
        symbolTable->applyToAll(CheckForSymbolWarnings);
        symbolTable->leave();
    }
}

void SemanticAnalyzer::InsertNodeIfReqd(TreeNode* node)
{
    if(node->nodeType != TreeNode::NodeType::DECLNODE)
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

TreeNode* SemanticAnalyzer::LookupNode(TreeNode* node)
{
    if(node->initializedAt != nullptr)
        return node->initializedAt;

    if(node->nodeType == TreeNode::NodeType::EXPNODE && node->subType.exp == TreeNode::ExpType::CONSTTYPE)
        return node;

    void* lookupResult = nullptr;
    if(symbolTable->depth() == 1)
        lookupResult = symbolTable->lookupGlobal(node->tokenData->tokenStr);
    else
        lookupResult = symbolTable->lookup(node->tokenData->tokenStr);

    if(lookupResult == nullptr) {
        ErrorHandler::AddUnDeclError(node);
    }

    node->initializedAt = (TreeNode*)lookupResult;
    node->initializedAt->isUsed = true;
    return (TreeNode*)lookupResult;
}

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
            if(node->leftChild->varType != TreeNode::VarType::BOOLEAN)
                ErrorHandler::AddLHSOpError(node, GetTypeStringOf(TreeNode::VarType::BOOLEAN), GetTypeStringOf(node->leftChild->varType));
            break;
    }
}

void SemanticAnalyzer::CheckForSymbolWarnings(std::string sym, void* node)
{
    printf("Test\n");
    TreeNode* treeNode = (TreeNode*)node;
    if(!(treeNode->isUsed) && sym != "main")
        ErrorHandler::AddUnusedVarWarn(treeNode);
}

void SemanticAnalyzer::CheckLBracketErrors(TreeNode* node)
{
    TreeNode* baseArr = LookupNode(node->leftChild);
    TreeNode* idx = LookupNode(node->middleChild);

    if(GetTypeOf(baseArr) != TreeNode::VarType::INTEGER) {
        ErrorHandler::AddArrIdxTypeError(node, GetTypeStringOf(baseArr));
    }

    if(IsArray(idx)) {
        ErrorHandler::AddIdxWithArrError(node, idx->tokenData->tokenStr);
    }

    if(!IsArray(baseArr)) {
        ErrorHandler::AddIdxNonArrError(node->leftChild);
    }
}

void SemanticAnalyzer::CheckAssignErrors(TreeNode* node)
{
    TreeNode* lhs = LookupNode(node->leftChild);
    TreeNode* rhs = LookupNode(node->middleChild);

    bool leftIsArr = IsArray(lhs);
    bool rightIsArr = IsArray(rhs);

    TreeNode::VarType leftType = GetTypeOf(lhs);
    TreeNode::VarType rightType = GetTypeOf(rhs);

    if(leftType != rightType)
        ErrorHandler::AddBothOpTypeError(node, GetTypeStringOf(leftType), GetTypeStringOf(rightType));

    if(!(leftIsArr && rightIsArr))
        ErrorHandler::AddBothOpArrError(node, leftIsArr, rightIsArr);
}

void SemanticAnalyzer::CheckLHSRHSErrors(TreeNode* node, TreeNode::VarType type)
{
    TreeNode* lhs = LookupNode(node->leftChild);
    TreeNode* rhs = LookupNode(node->middleChild);

    if(GetTypeOf(rhs) != type)
        ErrorHandler::AddRHSOpError(node, GetTypeStringOf(type), GetTypeStringOf(rhs));

    if(GetTypeOf(lhs) != type)
        ErrorHandler::AddLHSOpError(node, GetTypeStringOf(type), GetTypeStringOf(lhs));
}

void SemanticAnalyzer::CheckUnaryOpErrors(TreeNode* node) 
{
    TreeNode* lhs = LookupNode(node->leftChild);

    if(GetTypeOf(lhs) != TreeNode::VarType::INTEGER)
        ErrorHandler::AddUnaryOpError(node, GetTypeStringOf(TreeNode::VarType::INTEGER), GetTypeStringOf(lhs));
}

void SemanticAnalyzer::CheckMinusErrors(TreeNode* node)
{
    if(node->isUnary)
        CheckLHSRHSErrors(node, TreeNode::VarType::BOOLEAN);
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
            return std::string("Void");
            break;

        case TreeNode::VarType::INTEGER:
            return std::string("Integer");
            break;

        case TreeNode::VarType::BOOLEAN:
            return std::string("Boolean");
            break;

        case TreeNode::VarType::CHARACTER:
            return std::string("Character");
            break;

        case TreeNode::VarType::STRING:
            return std::string("String");
            break;

        case TreeNode::VarType::UNDEFINED:
            return std::string("Undefined");
            break;

        default:
            return std::string("Unknown");
            break;
    }
}

bool SemanticAnalyzer::IsArray(TreeNode* node)
{
    return node->isArray;
}