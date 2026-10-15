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
    if(node == nullptr) {
        return;
    }

    CheckForOperatorErrors(node);
    CheckForSymbolErrors(node);

    Analyze(node->leftChild);
    Analyze(node->middleChild);
    Analyze(node->rightChild);
    Analyze(node->sibling);
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

void SemanticAnalyzer::CheckForSymbolErrors(TreeNode* node)
{

}

void SemanticAnalyzer::CheckForSymbolWarnings(TreeNode* node)
{

}

void SemanticAnalyzer::CheckLBracketErrors(TreeNode* node)
{
    if(GetTypeOf(node->middleChild) != TreeNode::VarType::INTEGER) {
        ErrorHandler::AddArrIdxTypeError(node, GetTypeStringOf(node->middleChild));
    }

    if(IsArray(node->middleChild)) {
        ErrorHandler::AddIdxWithArrError(node, node->middleChild->tokenData->tokenStr);
    }

    if(!IsArray(node->leftChild)) {
        ErrorHandler::AddIdxNonArrError(node->leftChild);
    }
}

void SemanticAnalyzer::CheckAssignErrors(TreeNode* node)
{
    bool leftIsArr = IsArray(node->leftChild);
    bool rightIsArr = IsArray(node->middleChild);

    TreeNode::VarType leftType = GetTypeOf(node->leftChild);
    TreeNode::VarType rightType = GetTypeOf(node->middleChild);

    if(leftType != rightType) {
        ErrorHandler::AddBothOpTypeError(node, GetTypeStringOf(leftType), GetTypeStringOf(rightType));
    }

    if(!(leftIsArr && rightIsArr)) {
        ErrorHandler::AddBothOpArrError(node, leftIsArr, rightIsArr);
    }
}

void SemanticAnalyzer::CheckLHSRHSErrors(TreeNode* node, TreeNode::VarType type)
{
    if(GetTypeOf(node->middleChild) != type) {
        ErrorHandler::AddRHSOpError(node, GetTypeStringOf(type), GetTypeStringOf(node->middleChild));
    }

    if(GetTypeOf(node->leftChild) != type) {
        ErrorHandler::AddLHSOpError(node, GetTypeStringOf(type), GetTypeStringOf(node->leftChild));
    }
}

void SemanticAnalyzer::CheckUnaryOpErrors(TreeNode* node) 
{
    if(GetTypeOf(node->leftChild) != TreeNode::VarType::INTEGER) {
        ErrorHandler::AddUnaryOpError(node, GetTypeStringOf(TreeNode::VarType::INTEGER), GetTypeStringOf(node->leftChild));
    }
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

    if(!(node->leftChild->isArray)) {
        ErrorHandler::AddOnlyArrOpError(node);
    }
}

void SemanticAnalyzer::CheckComparisonErrors(TreeNode* node)
{
    if(GetTypeOf(node->middleChild) != GetTypeOf(node->leftChild)) {
        ErrorHandler::AddBothOpTypeError(node, GetTypeStringOf(node->leftChild), GetTypeStringOf(node->middleChild));
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
            return std::string("Void");
            break;

        case TreeNode::VarType::INTEGER:
            return std::string("Integer");
            break;

        case TreeNode::VarType::BOOLEAN:
            return std::string("Boolean");
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