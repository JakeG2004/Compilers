#include "treenode.h"

TreeNode::TreeNode(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData)
{
    this->leftChild = leftChild;
    this->middleChild = middleChild;
    this->rightChild = rightChild;

    this->tokenData = tokenData;
}

TreeNode::TreeNode(TokenClass* tokenData)
{
    this->leftChild = nullptr;
    this->middleChild = nullptr;
    this->rightChild = nullptr;

    this->tokenData = tokenData;
}

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