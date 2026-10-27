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
    if(lineNum == -1)
        return;
    
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

// ==============
// === ERRORS ===
// ==============

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
    ss << "Unary '" << GetUnaryVersionOfOperator(node) << "' requires an operand of type " << targetType << " but was given type " << actualType << ".";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddRetArrError(TreeNode* node)
{
    AddError("Cannot return an array.", node->tokenData->lineNum);
}

void ErrorHandler::AddReDeclError(TreeNode* node)
{
    std::stringstream ss;
    ss << "Symbol '" << node->tokenData->tokenStr << "' is already declared at line " << node->declaredAt->tokenData->lineNum << ".";
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
    ss << "Array '" << node->leftChild->tokenData->tokenStr << "' should be indexed by type int but got type " << otherType << ".";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddIdxWithArrError(TreeNode* node, std::string otherArrName)
{
    std::stringstream ss;
    ss << "Array index is the unindexed array '" << otherArrName << "'.";
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
    ss << "The operation '" << GetUnaryVersionOfOperator(node) << "' does not work with arrays.";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddOnlyArrOpError(TreeNode* node)
{
    std::stringstream ss;
    ss << "The operation '" << GetUnaryVersionOfOperator(node) << "' only works with arrays.";
    AddError(ss.str(), node->tokenData->lineNum);
}

// Assignment 4

void ErrorHandler::AddBreakOutsideLoopError(TreeNode* node)
{
    std::stringstream ss;
    ss << "Cannot have a break statement outside of loop.";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddArrAsTestConditionError(TreeNode* node, std::string stmtType)
{
    std::stringstream ss;
    ss << "Cannot use array as test condition in " << stmtType << " statement.";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddNonBoolTestConditionError(TreeNode* node, std::string stmtType, std::string actualType)
{
    std::stringstream ss;
    ss << "Expecting Boolean test condition in " << stmtType << " statement but got " << actualType << ".";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddArrInRangeError(TreeNode* node, int pos)
{
    std::stringstream ss;
    ss << "Cannot use array in position " << pos << " in range of for statement.";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddWrongTypeInRangeError(TreeNode* node, std::string expectedType, std::string actualType, int pos)
{
    std::stringstream ss;
    ss << "Expecting " << expectedType << " in position " << pos << " in range of for statement but got " << actualType << ".";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddWrongTypeInCallError(TreeNode* node, std::string expectedType, std::string actualType, std::string functionName, int pos, int funcLineNum)
{
    std::stringstream ss;
    ss << "Expecting " << expectedType << " in parameter " << pos << " of call to '" << functionName << "' declared on line " << funcLineNum << " but got " << actualType << ".";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddExpectArrInCallError(TreeNode* node, std::string functionName, int functionLineNum, int parmNum)
{
    std::stringstream ss;
    ss << "Expecting array in parameter " << parmNum << " of call to '" << functionName << "' declared on line " << functionLineNum << ".";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddNotExpectArrInCallError(TreeNode* node, std::string functionName, int functionLineNum, int parmNum)
{
    std::stringstream ss;
    ss << "Not expecting array in parameter " << parmNum << " of call to '" << functionName << "' declared on line " << functionLineNum << ".";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddTooFewParmsInCallError(TreeNode* node, std::string functionName, int functionLineNum)
{
    std::stringstream ss;
    ss << "Too few parameters passed for function '" << functionName << "' declared on line " << functionLineNum << ".";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddTooManyParmsInCallError(TreeNode* node, std::string functionName, int functionLineNum)
{
    std::stringstream ss;
    ss << "Too many parameters passed for function '" << functionName << "' declared on line " << functionLineNum << ".";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddUnexpectedRetValError(TreeNode* node, std::string funcName, int funcLineNum)
{
    std::stringstream ss;
    ss << "Function '" << funcName << "' at line " << funcLineNum << " is expecting no return value, but return has a value.";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddExpectedRetValError(TreeNode* node, std::string funcName, std::string expectedType, int funcLineNum)
{
    std::stringstream ss;
    ss << "Function '" << funcName << "' at line " << funcLineNum << " is expecting to return " << expectedType << " but return has no value.";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddRetValTypeError(TreeNode* node, std::string funcName, std::string expectedType, std::string actualType, int funcLineNum)
{
    std::stringstream ss;
    ss << "Function '" << funcName << "' at line " << funcLineNum << " is expecting to return " << expectedType << " but returns " << actualType << ".";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddNonConstInitError(TreeNode* node)
{
    std::stringstream ss;
    ss << "Initializer for variable '" << node->tokenData->tokenStr << "' is not a constant expression.";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddInitTypeError(TreeNode* node, std::string expectedType, std::string actualType)
{
    std::stringstream ss;
    ss << "Initializer for variable '" << node->tokenData->tokenStr << "' of " << expectedType << " is of " << actualType << ".";
    AddError(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddInitArrError(TreeNode* node, std::string lhsIsArr, std::string rhsIsArr)
{
    std::stringstream ss;
    ss << "Initializer for variable '" << node->tokenData->tokenStr << "' requires both operands be arrays or not but variable is " << lhsIsArr << " an array and rhs is " << rhsIsArr << " and array.";
    AddError(ss.str(), node->tokenData->lineNum);
}

// ================
// === WARNINGS ===
// ================

void ErrorHandler::AddUnusedVarWarn(TreeNode* node, bool isGlobal)
{
    if(node->tokenData->lineNum == -1)
        return;

    std::stringstream ss;
    ss << "The " << GetScopeType(node, isGlobal) << " '" << node->tokenData->tokenStr << "' seems not to be used.";
    AddWarning(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddUninitVarWarn(TreeNode* node)
{
    std::stringstream ss;
    ss << "Variable '" << node->tokenData->tokenStr << "' may be uninitialized when used here.";
    AddWarning(ss.str(), node->tokenData->lineNum);
}

void ErrorHandler::AddMissingRetWarn(TreeNode* node, std::string funcName, std::string expectedType)
{
    std::stringstream ss;
    ss << "Expecting to return " << expectedType << " but function '" << funcName << "' has no return statement.";
    AddWarning(ss.str(), node->tokenData->lineNum);
}

// ===================
// === WEIRD OTHER ===
// ===================

void ErrorHandler::AddNoMainError()
{
    AddError("A function named 'main()' must be defined.", -1);
}

std::string ErrorHandler::GetUnaryVersionOfOperator(TreeNode* node)
{
    if(node->tokenData->tokenStr == "-")
        return std::string("chsign");
    else if(node->tokenData->tokenStr == "*")
        return std::string("sizeof");
    else
        return node->tokenData->tokenStr;
}

std::string ErrorHandler::GetScopeType(TreeNode* node, bool isGlobal)
{
    if(node == nullptr)
        return "GetScopeType GOT NULLPTR";

    switch(node->subType.decl) {
        case TreeNode::DeclType::VARTYPE:
            if(isGlobal)
                return "global variable";
            else
                return "local variable";

        case TreeNode::DeclType::FUNCTYPE:
            return "function";

        case TreeNode::DeclType::PARMTYPE:
            return "parameter";

        default:
            return "WHAT THE HELL IS THIS THANG?";
    }
}