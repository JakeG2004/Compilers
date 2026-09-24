#include "treenode.h"

TreeNode::TreeNode(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData)
{
    this->leftChild = leftChild;
    this->middleChild = middleChild;
    this->rightChild = rightChild;

    this->tokenData = tokenData;
}

TreeNode::TreeNode(DeclType declType, ExpType expType, TokenClass* tokenData, TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild)
    : TreeNode(leftChild, middleChild, rightChild, tokenData)
{
    this->subType = declType;
    this->expType = expType;
}

TreeNode::TreeNode(StmtType stmtType, TokenClass* tokenData, TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild)
    : TreeNode(leftChild, middleChild, rightChild, tokenData)
{
    this->subType = stmtType;
}

TreeNode::TreeNode(ExpType expType, TokenClass* tokenData, TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild)
    : TreeNode(leftChild, middleChild, rightChild, tokenData)
{
    this->subType = expType;
}

void TreeNode::Print(int depth)
{
    int nextDepth = depth;

    if(tokenData != nullptr) {
        for(int i = 0; i < depth; i++)
            std::cout << ".   ";

        std::cout << tokenData->tokenClass << ": " << tokenData->tokenStr << "[line: " << tokenData->lineNum << "]" << std::endl;
        nextDepth++;
    }

    if(leftChild != nullptr)
        leftChild->Print(nextDepth);

    if(middleChild != nullptr)
        middleChild->Print(nextDepth);

    if(rightChild != nullptr)
        rightChild->Print(nextDepth);
}

void TreeNode::SetSibling(TreeNode* newSibling) {
    sibling = newSibling;
}

TreeNode* TreeNode::CreateVarDecl(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData)
{
    return new TreeNode(
        DeclType::VARTYPE,
        ExpType::INITTYPE,
        tokenData,
        leftChild,
        middleChild,
        rightChild
    );
}

TreeNode* TreeNode::CreateFuncDecl(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData)
{
    return new TreeNode(
        DeclType::FUNCTYPE,
        ExpType::IDTYPE,
        tokenData,
        leftChild,
        middleChild,
        rightChild
    );
}

TreeNode* TreeNode::CreateIdNode(TokenClass* tokenData)
{
    return new TreeNode(
        ExpType::IDTYPE,
        tokenData,
        nullptr,
        nullptr,
        nullptr
    );
}

TreeNode* TreeNode::CreateCompoundStmt(TreeNode* leftChild, TreeNode* middleChild)
{
    return new TreeNode(
        StmtType::COMPOUNDTYPE,
        nullptr,
        leftChild,
        middleChild,
        nullptr
    );
}

TreeNode* TreeNode::CreateIfStmt(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData)
{
    return new TreeNode(
        StmtType::IFTYPE,
        leftChild,
        middleChild,
        rightChild,
        tokenData
    );
}

TreeNode* TreeNode::CreateWhileStmt(TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData)
{
    return new TreeNode(
        StmtType::WHILETYPE,
        leftChild,
        middleChild,
        nullptr,
        tokenData
    );
}

TreeNode* TreeNode::CreateForStmt(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData)
{
    return new TreeNode(
        StmtType::FORTYPE,
        leftChild,
        middleChild,
        rightChild,
        tokenData
    );
}

TreeNode* TreeNode::CreateRangeStmt(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData)
{
    return new TreeNode(
        StmtType::RANGETYPE,
        leftChild,
        middleChild,
        rightChild,
        tokenData
    );
}

TreeNode* TreeNode::CreateReturnStmt(TreeNode* leftChild, TokenClass* tokenData)
{
    return new TreeNode(
        StmtType::RETURNTYPE,
        leftChild,
        nullptr,
        nullptr,
        tokenData
    );
}

TreeNode* TreeNode::CreateBreakStmt(TreeNode* leftChild, TokenClass* tokenData)
{
    return new TreeNode(
        StmtType::BREAKTYPE,
        leftChild,
        nullptr,
        nullptr,
        tokenData
    );
}

TreeNode* TreeNode::CreateOpExp(TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData)
{
    return new TreeNode(
        ExpType::OPTYPE,
        leftChild,
        middleChild,
        nullptr,
        tokenData
    );
}

TreeNode* TreeNode::CreateCallExp(TreeNode* leftChild, TokenClass* tokenData)
{
    return new TreeNode(
        ExpType::CALLTYPE,
        leftChild,
        nullptr,
        nullptr,
        tokenData
    );
}

TreeNode* TreeNode::CreateConstExp(TokenClass* tokenData)
{
    return new TreeNode(
        ExpType::CONSTTYPE,
        nullptr,
        nullptr,
        nullptr,
        tokenData
    );
}