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

void TreeNode::Print()
{
    std::cout << "== TOKEN ==" << std::endl;

    if(tokenData != nullptr)
        std::cout << tokenData->tokenStr << std::endl;

    if(leftChild != nullptr)
        leftChild->Print();

    if(middleChild != nullptr)
        middleChild->Print();

    if(rightChild != nullptr)
        rightChild->Print();
}