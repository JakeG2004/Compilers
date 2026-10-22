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

        static void AddBreakOutsideLoopError(TreeNode* node);

        static void AddArrAsTestConditionError(TreeNode* node, std::string stmtType);
        static void AddNonBoolTestConditionError(TreeNode* node, std::string stmtType, std::string actualType);
        
        static void AddArrInRangeError(TreeNode* node, int pos);
        static void AddWrongTypeInRangeError(TreeNode* node, std::string expectedType, std::string actualType, int pos);

        static void AddWrongTypeInCallError(TreeNode* node, std::string expectedType, std::string actualType, std::string functionName, int pos, int funcLineNum);
        static void AddExpectArrInCallError(TreeNode* node);
        static void AddNotExpectArrInCallError(TreeNode* node);
        static void AddTooFewParmsInCallError(TreeNode* node);
        static void AddTooManyParmsInCallError(TreeNode* node);

        static void AddUnexpectedRetValError(TreeNode* node);
        static void AddExpectedRetValError(TreeNode* node);
        static void AddRetValTypeError(TreeNode* node);

        static void AddNonConstInitError(TreeNode* node);
        static void AddInitTypeError(TreeNode* node);
        static void AddInitArrError(TreeNode* node);
    
    public: // Warnings
        static void AddUnusedVarWarn(TreeNode* node, bool isGlobal);
        static void AddUninitVarWarn(TreeNode* node);

        static void AddMissingRetWarn(TreeNode* node);

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