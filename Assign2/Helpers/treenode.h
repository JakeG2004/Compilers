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
        };

        enum DeclType {
            VARTYPE,
            FUNCTYPE,
            EXPTYPE,
        };

        enum StmtType {
            NULLTYPE,
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
            CHARINT,
            EQUAL,
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
        TokenClass* tokenData;
        NodeType nodeType;
        VarType varType;

        bool isArray;
        bool isStatic;
        bool isUnary;

        union {
            DeclType decl;
            StmtType stmt;
            ExpType exp;
        } subType;

    protected:
        TreeNode* leftChild;
        TreeNode* middleChild;
        TreeNode* rightChild;
        TreeNode* sibling;

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
        static TreeNode* CreateVarDecl(TokenClass* index, TokenClass* tokenData);
        static TreeNode* CreateFuncDecl(VarType varType, TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData);

        static TreeNode* CreateCompoundStmt(TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData);
        static TreeNode* CreateIfStmt(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData);
        static TreeNode* CreateWhileStmt(TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData);
        static TreeNode* CreateForStmt(TokenClass* id, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData);
        static TreeNode* CreateRangeStmt(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData);
        static TreeNode* CreateReturnStmt(TreeNode* leftChild, TokenClass* tokenData);
        static TreeNode* CreateBreakStmt(TreeNode* leftChild, TokenClass* tokenData);

        static TreeNode* CreateOpExp(TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData);
        static TreeNode* CreateUnaryOpExp(TokenClass* tokenData);
        static TreeNode* CreateCallExp(TreeNode* leftChild, TokenClass* tokenData);
        static TreeNode* CreateConstExp(VarType typeDef, TokenClass* tokenData);
        static TreeNode* CreateIdExp(TokenClass* tokenData);
        static TreeNode* CreateParmExp(TokenClass* tokenData);
        static TreeNode* CreateInitExp(TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData);
        static TreeNode* CreateAssignExp(TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData);
        static TreeNode* CreateIdxExp(TreeNode* exp, TokenClass* id, TokenClass* lbracket);

        static TreeNode* PullUpNode(TreeNode* rootNode, TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild);
        static TreeNode* NodeList(TreeNode* rootNode, TreeNode* newSibling);
        static TreeNode* PullUpTypeNode(TreeNode* rootNode, VarType typeDef);
        static void SetNodeListTypes(VarType typeDef, TreeNode* node);
};

#endif