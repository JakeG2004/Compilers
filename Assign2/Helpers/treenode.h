#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include "tokenclass.h"
#include <string.h>

class TreeNode
{
    public:
        TokenClass* tokenData;
        std::string name;

        enum ChildType {
            LEFT,
            MIDDLE,
            RIGHT,
        };

    private:
        TreeNode* leftChild;
        TreeNode* middleChild;
        TreeNode* rightChild;

    public:
        TreeNode(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData);
        TreeNode(TokenClass* tokenData);
        void Print();
};

#endif