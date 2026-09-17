#include "treenode.h"

TreeNode::TreeNode(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData)
{
    this->leftChild = leftChild;
    this->middleChild = middleChild;
    this->rightChild = rightChild;

    this->tokenData = tokenData;
}

TreeNode::TreeNode(TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData)
    : TreeNode(leftChild, middleChild, nullptr, tokenData)
{}

TreeNode::TreeNode(TreeNode* leftChild, TokenClass* tokenData)
    : TreeNode(leftChild, nullptr, nullptr, tokenData)
{}

TreeNode::TreeNode(TokenClass* tokenData) 
    : TreeNode(nullptr, nullptr, nullptr, tokenData)
{}

void TreeNode::Print(int depth)
{
    int nextDepth = depth;

    if(tokenData != nullptr) {
        for(int i = 0; i < depth; i++) std::cout << "  ";
        std::cout << "== TOKEN ==" << std::endl;

        for(int i = 0; i < depth; i++) std::cout << "  ";
        std::cout << tokenData->tokenStr << std::endl;

        nextDepth++;
    }

    if(leftChild != nullptr)
        leftChild->Print(nextDepth);

    if(middleChild != nullptr)
        middleChild->Print(nextDepth);

    if(rightChild != nullptr)
        rightChild->Print(nextDepth);
}