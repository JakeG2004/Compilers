#include <iostream>

#include "semanticanalyzer.h"
#include "errorhandler.h"
#include "symboltable.h"
#include "parser.tab.h"

SemanticAnalyzer::SemanticAnalyzer(bool stDebug)
{
    symbolTable = new SymbolTable();
    symbolTable->debug(stDebug);
}

void SemanticAnalyzer::Analyze(TreeNode* node)
{
    CheckForOperatorErrors(node);
    CheckForSymbolErrors(node);

    if(node->leftChild != nullptr)
        Analyze(node->leftChild);
    if(node->middleChild != nullptr)
        Analyze(node->middleChild);
    if(node->rightChild != nullptr)
        Analyze(node->rightChild);
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
                ErrorHandler::AddLHSOpError(node, TreeNode::VarTYpe::BOOLEAN, node->leftChild->varType);
            break;
    }
}

void SemanticAnalyzer::CheckForSymbolErrors(TreeNode* node)
{

}

void SemanticAnalyzer::CheckForSymbolWarnings(TreeNode* node)
{

}

void CheckLBracketErrors(TreeNode* node)
{
    if(GetTypeOf(node->middleChild) != TreeNode::VarType::INTEGER) {
        ErrorHandler::AddArrIdxTypeError(node, GetTypeStringOf(node->middleChild));
    }

    if(IsArray(node->middleChild)) {
        ErrorHandler::AddIdxWithArrError(node, node->middleChild->tokenData->tokenStr);
    }

    if(!IsArray(node->leftChild)) {
        ErrorHandler::AddIdxNonArrError(node);
    }
}

void CheckAssignErrors(TreeNode* node)
{
    if(GetTypeOf(node->leftChild) != GetTypeOf(node->middleChild)) {
        ErrorHandler::AddBothOpTypeError(node, GetTypeStringOf(node->leftChild), GetTypeStringOf(node->middleChild));
    }

    if(!(IsArray(node->leftChild) && IsArray(node->middleChild))) {
        ErrorHandler::AddBothOpArrError(node, IsArray(node->leftChild), IsArray(node->middleChild));
    }
}

void CheckLHSRHSErrors(TreeNode* node, TreeNode::VarType type)
{
    if(GetTypeOf(node->middleChild) != type) {
        ErrorHandler::AddRHSOpError(node, type, GetTypeStringOf(node->middleChild));
    }

    if(GetTypeOf(node->leftChild) != type) {
        ErrorHandler::AddLHSOpError(node, type, GetTypeStringOf(node->leftChild));
    }
}

void CheckUnaryOpErrors(TreeNode* node) 
{
    if(GetTypeOf(node->leftChild) != TreeNode::VarType::INTEGER) {
        ErrorHandler::AddUnaryOpError(node, TreeNode::VarType::INTEGER, GetTypeStringOf(node->leftChild));
    }
}

void CheckMinusErrors(TreeNode* node)
{
    if(node->isUnary)
        CheckLHSRHSErrors(node, TreeNode::VarType::BOOLEAN);
    else
        CheckLHSRHSErrors(node, TreeNode::VarType::INTEGER);
}

void CheckStarErrors(TreeNode* node)
{
    if(!(node->isUnary)) {
        CheckLHSRHSErrors(node, TreeNode::VarType::INTEGER);
        return;
    }

    if(!(node->leftChild->isArray)) {
        ErrorHandler::AddOnlyArrOpError(node);
    }
}

void CheckComparisonErrors(TreeNode* node)
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
    switch(GetTypeOf(node)) {
        case VOID:
            return std::string("Void");
            break;

        case INTEGER:
            return std::string("Integer");
            break;

        case BOOLEAN:
            return std::string("Boolean");
            break;

        case STRING:
            return std::string("String");
            break;

        case UNDEFINED:
            return std::string("Undefined");
            break;
    }
}

bool SemanticAnalyzer::IsArray(TreeNode* node)
{
    return node->isArray;
}