#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include "treenode.h"
#include "symboltable.h"
#include "parser.tab.h"

class SemanticAnalyzer
{
    public:
        SemanticAnalyzer(bool stDebug);
        void Analyze(TreeNode* node, bool isScopeBody = false);
        void StartAnalysis(TreeNode* node);

    public: // Bulk Checks
        void CheckForOperatorErrors(TreeNode* node);
        void CheckForSymbolErrors(TreeNode* node);
        void CheckForReturnErrors(TreeNode* node);
        void CheckForRangeErrors(TreeNode* node);
        static void CheckUsageOnScopeExit(std::string sym, void* node);

    public: // Operator Checks
        void CheckLBracketErrors(TreeNode* node);
        void CheckAssignErrors(TreeNode* node);
        void CheckLHSRHSErrors(TreeNode* node, TreeNode::VarType type);
        void CheckUnaryOpErrors(TreeNode* node);
        void CheckMinusErrors(TreeNode* node);
        void CheckStarErrors(TreeNode* node);
        void CheckComparisonErrors(TreeNode* node);

        void ResolveWithoutWarn(TreeNode* node);
        TreeNode* ResolveOperand(TreeNode* node);

    public: // Symbol Checks
        void CheckUninitIDErrors(TreeNode* node);
        void CheckCallErrors(TreeNode* node);

    public: // ST Node Management
        void InsertNodeIfReqd(TreeNode* node, bool force = false);
        TreeNode* LookupNode(TreeNode* node, bool issueUninitWarn = true);
        TreeNode* LookupNode(std::string node, bool issueUninitWarn = true);

    public: // Basic Helpers
        bool IsArray(TreeNode* node);
        bool IsFunction(TreeNode* node);
        bool IsLoop(TreeNode* node);
        bool IsCompound(TreeNode* node);
        bool IsOperator(TreeNode* node);
        bool IsInArray(TreeNode* node);
        bool IsConst(TreeNode* node);
        static bool IsAssignmentOp(TreeNode* node);
        static bool IsFuncUse(TreeNode* operand, TreeNode* resolved);
        int GetSymbolToken(TreeNode* node);
        TreeNode::VarType GetTypeOf(TreeNode* node);
        std::string GetTypeStringOf(TreeNode* node);
        std::string GetTypeStringOf(TreeNode::VarType type);

    public: // Scope Management
        bool EnterScopeIfReqd(TreeNode* node, bool isScopeBody);
        bool ExitScopeIfReqd(TreeNode* node, bool openedScope);
        void CheckForMain();

    public:
        static SemanticAnalyzer* instance;
        SymbolTable* symbolTable = nullptr;
};

#endif