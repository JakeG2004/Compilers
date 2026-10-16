#include "errorhandler.h"

#include <sstream>

ErrorHandler::ErrorHandler() {}

void ErrorHandler::AddError(std::string content, int lineNum)
{
    GetInstance()->InstAddErrorOrWarning(Error::ErrorType::ERROR, content, lineNum);
}

void ErrorHandler::AddWarning(std::string content, int lineNum)
{
    GetInstance()->InstAddErrorOrWarning(Error::ErrorType::WARNING, content, lineNum);
}

void ErrorHandler::InstAddErrorOrWarning(Error::ErrorType errorType, std::string content, int lineNum)
{
    Error* newError = new Error(errorType, content, lineNum);
    newError->Print();

    if(errorType == Error::ErrorType::ERROR)
        numErrors++;
    if(errorType == Error::ErrorType::WARNING)
        numWarnings++;
}

int ErrorHandler::GetNumErrors()
{
    return GetInstance()->numErrors;
}

int ErrorHandler::GetNumWarnings()
{
    return GetInstance()->numWarnings;
}

void ErrorHandler::AddVarCallError(TreeNode* node)
{
    std::stringstream ss;
    ss << "'" << node->tokenData->tokenStr << "' is a simple variable and cannot be called.";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddFunVarError(TreeNode* node)
{
    std::stringstream ss;
    ss << "Cannot use function '" << node->tokenData->tokenStr << "' as a variable.";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddBothOpArrError(TreeNode* node, bool leftIsArr, bool rightIsArr)
{
    std::stringstream ss;
    ss << "'" << node->tokenData->tokenStr << "' requires both operands be arrays or not but lhs is" << (leftIsArr ? "" : " not") << " an array and rhs is" << (rightIsArr ? "" : " not") << " an array.";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddLHSOpError(TreeNode* node, std::string targetType, std::string lhsType)
{
    std::stringstream ss;
    ss << "'" << node->tokenData->tokenStr << "' requires operands of type " << targetType << " but lhs is of type " << lhsType << ".";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddRHSOpError(TreeNode* node, std::string targetType, std::string rhsType)
{
    std::stringstream ss;
    ss << "'" << node->tokenData->tokenStr << "' requires operands of type " << targetType << " but rhs is of type " << rhsType << ".";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddBothOpTypeError(TreeNode* node, std::string lhsType, std::string rhsType)
{
    std::stringstream ss;
    ss << "'" << node->tokenData->tokenStr << "' requires operands of the same type but lhs is type " << lhsType << " and rhs is type " << rhsType << ".";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddUnaryOpError(TreeNode* node, std::string targetType, std::string actualType)
{
    std::stringstream ss;
    ss << "Unary '" << node->tokenData->tokenStr << "' requires an operand of type " << targetType << " but was given type " << actualType << ".";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddRetArrError(TreeNode* node)
{
    AddError("Cannot return an array.", node->tokenData->lineNum);
}

void ErrorHandler::AddReDeclError(TreeNode* node)
{
    std::stringstream ss;
    ss << "Symbol '" << node->tokenData->tokenStr << "' is already declared at line " << node->initializedAt->tokenData->lineNum << ".";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddUnDeclError(TreeNode* node)
{
    std::stringstream ss;
    ss << "Symbol '" << node->tokenData->tokenStr << "' is not declared.";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddArrIdxTypeError(TreeNode* node, std::string otherType)
{
    std::stringstream ss;
    ss << "Array '" << node->tokenData->tokenStr << "' should be indexed by type int but got " << otherType << ".";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddIdxWithArrError(TreeNode* node, std::string otherArrName)
{
    std::stringstream ss;
    ss << "Array '" << node->leftChild->tokenData->tokenStr << "' index is the unindexed array '" << otherArrName << "'.";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddIdxNonArrError(TreeNode* node)
{
    std::stringstream ss;
    ss << "Cannot index nonarray '" << node->tokenData->tokenStr << "'.";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddNonArrOpError(TreeNode* node)
{
    std::stringstream ss;
    ss << "The operation << '" << node->tokenData->tokenStr << "' does not work with arrays.";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddOnlyArrOpError(TreeNode* node)
{
    std::stringstream ss;
    ss << "The operation << '" << node->tokenData->tokenStr << "' only works with arrays.";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddUnusedVarWarn(TreeNode* node)
{
    std::stringstream ss;
    ss << "The variable '" << node->tokenData->tokenStr << "' seems not to be used.";
    AddWarning(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddUninitVarWarn(TreeNode* node)
{
    std::stringstream ss;
    ss << "Variable '" << node->tokenData->tokenStr << "' may be uninitialized when used here.";
    AddWarning(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddNoMainError(TreeNode* node)
{
    AddError("A function named 'main()' must be defined.", -1);
}