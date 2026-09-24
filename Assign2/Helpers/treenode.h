#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include "tokenclass.h"
#include <string.h>

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
        };

        enum VarType{
            VOID,
            INTEGER,
            BOOLEAN,
            CHAR,
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

        ExpType expType;
        bool isArray;
        bool isStatic;

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
        TreeNode(DeclType declType, ExpType expType, TokenClass* tokenData, TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild);
        TreeNode(StmtType stmtType, TokenClass* tokenData, TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild);
        TreeNode(ExpType expType, TokenClass* tokenData, TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild);

        void SetSibling(TreeNode* newSibling);
        void Print(int depth = 0);

    public:
        static TreeNode* CreateVarDecl(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData);
        static TreeNode* CreateFuncDecl(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData);
        static TreeNode* CreateIdNode(TokenClass* tokenData);
        static TreeNode* CreateCompoundStmt(TreeNode* leftChild, TreeNode* middleChild);
        static TreeNode* CreateIfStmt(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData);
        static TreeNode* CreateWhileStmt(TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData);
        static TreeNode* CreateForStmt(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData);
        static TreeNode* CreateRangeStmt(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData);
        static TreeNode* CreateReturnStmt(TreeNode* leftChild, TokenClass* tokenData);
        static TreeNode* CreateBreakStmt(TreeNode* leftChild, TokenClass* tokenData);
        static TreeNode* CreateOpExp(TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData);
        static TreeNode* CreateCallExp(TreeNode* leftChild, TokenClass* tokenData);
        static TreeNode* CreateConstExp(TokenClass* tokenData);
};

#endif