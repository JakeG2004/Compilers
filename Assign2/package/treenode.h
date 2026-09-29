#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <string.h>

#include "tokenclass.h"

class TreeNode
{
    public:
        enum NodeType {
            DECLNODE,
            STMTNODE,
            EXPNODE,
            UNDEFNODE,
        };

        enum DeclType {
            VARTYPE,
            FUNCTYPE,
        };

        enum StmtType {
            IFTYPE,
            WHILETYPE,
            FORTYPE,
            COMPOUNDTYPE,
            RETURNTYPE,
            BREAKTYPE,
            RANGETYPE,
        };

        enum ExpType {
            OPTYPE,
            CONSTTYPE,
            IDTYPE,
            ASSIGNTYPE,
            INITTYPE,
            CALLTYPE,
            PARMTYPE,
        };

        enum VarType{
            VOID,
            INTEGER,
            BOOLEAN,
            CHARACTER,
            STRING,
            UNDEFINED,
        };

        enum ScopeType {
            NONE,
            LOCAL,
            GLOBAL,
            PARAMETER,
            LOCALSTATIC,
        };

    public:
        TokenClass* tokenData = nullptr;

        NodeType nodeType = NodeType::UNDEFNODE;
        VarType varType = VarType::UNDEFINED;

        bool isArray = false;
        bool isStatic = false;
        bool isUnary = false;

        union {
            DeclType decl;
            StmtType stmt;
            ExpType exp;
        } subType;

        long long int indexOrSize = 0;

    protected:
        TreeNode* leftChild = nullptr;
        TreeNode* middleChild = nullptr;
        TreeNode* rightChild = nullptr;
        TreeNode* sibling = nullptr;

    public:
        TreeNode(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData);
        TreeNode(DeclType declType, VarType varType, TokenClass* tokenData, TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild);
        TreeNode(StmtType stmtType, TokenClass* tokenData, TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild);
        TreeNode(ExpType expType, TokenClass* tokenData, TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild);

        void SetSibling(TreeNode* newSibling);
        void SetChild(int childIdx, TreeNode* newChild);
        void SetTypeFromTypedef(TreeNode* typeDef);
        void Print(int depth = 0, int childNo = -1, int siblingNo = 0);

    protected:
        void PrintSelf();
        void PrintDecl();
        void PrintStmt();
        void PrintExp();

        std::string GetTypeString();
        std::string GetArrText();
        std::string GetUnaryOrRegOp();

    public:
        static TreeNode* CreateVarDecl(TokenClass* indexOrSize, TokenClass* id);
        static TreeNode* CreateFuncDecl(VarType varType, TreeNode* parms, TreeNode* stmt, TokenClass* id);

        static TreeNode* CreateCompoundStmt(TreeNode* localDecls, TreeNode* stmtList, TokenClass* lbrace);
        static TreeNode* CreateIfStmt(TreeNode* condition, TreeNode* thenStmt, TreeNode* elseStmt, TokenClass* ifToken);
        static TreeNode* CreateWhileStmt(TreeNode* condition, TreeNode* stmt, TokenClass* whileToken);
        static TreeNode* CreateForStmt(TreeNode* range, TreeNode* stmt, TokenClass* id, TokenClass* forToken);
        static TreeNode* CreateRangeStmt(TreeNode* lowExp, TreeNode* highExp, TreeNode* byExp, TokenClass* toToken);
        static TreeNode* CreateReturnStmt(TreeNode* retVal, TokenClass* returnToken);
        static TreeNode* CreateBreakStmt(TreeNode* breakVal, TokenClass* breakToken);

        static TreeNode* CreateOpExp(TreeNode* lhs, TreeNode* rhs, TokenClass* opToken);
        static TreeNode* CreateUnaryOpExp(TokenClass* unaryOpToken);
        static TreeNode* CreateCallExp(TreeNode* args, TokenClass* id);
        static TreeNode* CreateConstExp(VarType typeDef, TokenClass* constToken);
        static TreeNode* CreateIdExp(TokenClass* id);
        static TreeNode* CreateParmExp(TokenClass* parmToken);
        static TreeNode* CreateAssignExp(TreeNode* lhs, TreeNode* rhs, TokenClass* assignToken);
        static TreeNode* CreateIdxExp(TreeNode* idxExp, TokenClass* id, TokenClass* lbracket);

        static TreeNode* PullUpNode(TreeNode* rootNode, TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild);
        static TreeNode* NodeList(TreeNode* rootNode, TreeNode* newSibling);
        static TreeNode* PullUpTypeNode(TreeNode* rootNode, VarType typeDef);
        static void SetNodeListTypes(VarType typeDef, TreeNode* node);
};

#endif