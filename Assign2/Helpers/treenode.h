#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include "tokenclass.h"
#include <string.h>

class TreeNode
{
    public:
        TokenClass* tokenData;

    private:
        TreeNode* leftChild;
        TreeNode* middleChild;
        TreeNode* rightChild;

    public:
        TreeNode(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData);
        TreeNode(TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData);
        TreeNode(TreeNode* leftChild, TokenClass* tokenData);
        TreeNode(TokenClass* tokenData);
        void Print(int depth = 0);
};

#endif