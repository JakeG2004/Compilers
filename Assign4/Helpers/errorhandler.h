#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include "error.h"
#include "treenode.h"

#include <iostream>
#include <vector>
#include <string>

class ErrorHandler
{
    public:
        static ErrorHandler* GetInstance()
        {
            static ErrorHandler obj;
            return &obj;
        }
        static int GetNumErrors();
        static int GetNumWarnings();

    public: // Errors
        static void AddVarCallError(TreeNode* node);
        static void AddFunVarError(TreeNode* node);

        static void AddBothOpArrError(TreeNode* node, bool leftIsArr, bool rightIsArr);
        static void AddLHSOpError(TreeNode* node, std::string targetType, std::string lhsType);
        static void AddRHSOpError(TreeNode* node, std::string targetType, std::string rhsType);
        static void AddBothOpTypeError(TreeNode* node, std::string lhsType, std::string rhsType);
        static void AddUnaryOpError(TreeNode* node, std::string targetType, std::string actualType);

        static void AddRetArrError(TreeNode* node);

        static void AddReDeclError(TreeNode* node);
        static void AddUnDeclError(TreeNode* node);

        static void AddArrIdxTypeError(TreeNode* node, std::string otherType);
        static void AddIdxWithArrError(TreeNode* node, std::string otherArrName);
        static void AddIdxNonArrError(TreeNode* node);
        static void AddNonArrOpError(TreeNode* node);
        static void AddOnlyArrOpError(TreeNode* node);

        // ASSIGN 4
        
        static void AddBreakOutsideLoopError(TreeNode* node);

        static void AddArrAsTestConditionError(TreeNode* node, std::string stmtType);
        static void AddNonBoolTestConditionError(TreeNode* node, std::string stmtType, std::string actualType);
        
        static void AddArrInRangeError(TreeNode* node, int pos);
        static void AddWrongTypeInRangeError(TreeNode* node, std::string expectedType, std::string actualType, int pos);

        static void AddWrongTypeInCallError(TreeNode* node, std::string expectedType, std::string actualType, std::string functionName, int pos, int funcLineNum);
        static void AddExpectArrInCallError(TreeNode* node, std::string functionName, int functionLineNum, int parmNum);
        static void AddNotExpectArrInCallError(TreeNode* node, std::string funcLineNum, int functionLineNum, int parmNum);
        static void AddTooFewParmsInCallError(TreeNode* node, std::string functionName, int funcLineNum);
        static void AddTooManyParmsInCallError(TreeNode* node, std::string functionName, int functionLineNum);

        static void AddUnexpectedRetValError(TreeNode* node, std::string funcName, int funcLineNum);
        static void AddExpectedRetValError(TreeNode* node, std::string funcName, std::string expectedType, int funcLineNum);
        static void AddRetValTypeError(TreeNode* node, std::string funcName, std::string expectedType, std::string actualType, int funcLineNum);

        static void AddNonConstInitError(TreeNode* node);
        static void AddInitTypeError(TreeNode* node, std::string expectedType, std::string actualType);
        static void AddInitArrError(TreeNode* node, std::string lhsIsArr, std::string rhsIsArr);
    
    public: // Warnings
        static void AddUnusedVarWarn(TreeNode* node, bool isGlobal);
        static void AddUninitVarWarn(TreeNode* node);

        static void AddMissingRetWarn(TreeNode* node, std::string funcName, std::string expectedType);

    public: // Weird things like linker
        static void AddNoMainError();

    protected:
        void InstAddErrorOrWarning(Error::ErrorType errorType, std::string content, int lineNum);
        static void AddError(std::string content, int lineNum);
        static void AddWarning(std::string content, int lineNum);

    protected:
        static std::string GetUnaryVersionOfOperator(TreeNode* node);
        static std::string GetScopeType(TreeNode* node, bool isGlobal);
    
    protected:
        int numWarnings = 0;
        int numErrors = 0;

    private:
        ErrorHandler();
};

#endif