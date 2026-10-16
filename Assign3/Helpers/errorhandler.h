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
    
    public: // Warnings
        static void AddUnusedVarWarn(TreeNode* node);
        static void AddUninitVarWarn(TreeNode* node);

    public: // Weird things like linker
        static void AddNoMainError(TreeNode* node);

    protected:
        void InstAddErrorOrWarning(Error::ErrorType errorType, std::string content, int lineNum);
        static void AddError(std::string content, int lineNum);
        static void AddWarning(std::string content, int lineNum);

    protected:
        static std::string GetUnaryVersionOfOperator(TreeNode* node);
    
    protected:
        int numWarnings = 0;
        int numErrors = 0;

    private:
        ErrorHandler();
};

#endif