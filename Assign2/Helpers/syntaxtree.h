#ifndef SYNTAXTREE_H
#define SYNTAXTREE_H

#include <iostream>
#include "tokenclass.h"

struct TreeNode {
    TokenClass token;
    TreeNode* left;
    TreeNode* middle;
    TreeNode* right;
};

typedef struct TreeNode* TreeNodePtr;

class AST 
{
    public:
        enum INSERT_TYPE
        {
            LEFT,
            MIDDLE,
            RIGHT,
        };

        TreeNode* root;

    public:
        AST();
        void Print();
};

#endif