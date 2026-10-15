#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include "treenode.h"
#include "symboltable.h"
#include "parser.tab.h"

class SemanticAnalyzer
{
    public:
        SemanticAnalyzer(bool stDebug);
        void Analyze(TreeNode* node, bool canAddNewScope = true);
        bool IsArray(TreeNode* node);
        int GetSymbolToken(TreeNode* node);
        TreeNode::VarType GetTypeOf(TreeNode* node);
        std::string GetTypeStringOf(TreeNode* node);
        std::string GetTypeStringOf(TreeNode::VarType type);

    public:
        void InsertNodeIfReqd(TreeNode* node);
        TreeNode* LookupNode(TreeNode* node);

    public:
        void CheckForOperatorErrors(TreeNode* node);
        static void CheckForSymbolWarnings(std::string sym, void* node);

    public:
        void CheckLBracketErrors(TreeNode* node);
        void CheckAssignErrors(TreeNode* node);
        void CheckMinusErrors(TreeNode* node);
        void CheckStarErrors(TreeNode* node);
        void CheckComparisonErrors(TreeNode* node);

    public:
        void CheckLHSRHSErrors(TreeNode* node, TreeNode::VarType type);
        void CheckUnaryOpErrors(TreeNode* node);

    public:
        void EnterScopeIfReqd(TreeNode* node, bool* canAddNewScope);
        void ExitScopeIfReqd(TreeNode* node);

    public:
        SymbolTable* symbolTable = nullptr;
};

#endif