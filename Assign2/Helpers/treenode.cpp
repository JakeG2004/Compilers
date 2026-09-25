#include "treenode.h"

TreeNode::TreeNode(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData)
{
    this->leftChild = leftChild;
    this->middleChild = middleChild;
    this->rightChild = rightChild;

    this->tokenData = tokenData;
}

TreeNode::TreeNode(DeclType declType, VarType varType, TokenClass* tokenData, TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild)
    : TreeNode(leftChild, middleChild, rightChild, tokenData)
{
    this->subType.decl = declType;
    this->expType = expType;
}

TreeNode::TreeNode(StmtType stmtType, TokenClass* tokenData, TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild)
    : TreeNode(leftChild, middleChild, rightChild, tokenData)
{
    this->subType.stmt = stmtType;
}

TreeNode::TreeNode(ExpType expType, TokenClass* tokenData, TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild)
    : TreeNode(leftChild, middleChild, rightChild, tokenData)
{
    this->subType.exp = expType;
}

void TreeNode::Print(int depth, int childNo, int siblingNo)
{
    int nextDepth = depth;

    for(int i = 0; i < depth; i++)
        std::cout << ".   ";

    if(childNo != -1)
        std::cout << "Child: " << childNo << "  ";

    if(siblingNo != 0)
        std::cout << "Sibling: " << siblingNo << " ";

    if(tokenData != nullptr)
        std::cout << tokenData->tokenStr << std::endl;
    else
        std::cout << "no" << std::endl;
    nextDepth++;

    if(leftChild != nullptr) {
        leftChild->Print(nextDepth, 0);
    }

    if(middleChild != nullptr) {
        middleChild->Print(nextDepth, 1);
    }

    if(rightChild != nullptr) {
        rightChild->Print(nextDepth, 2);
    }

    if(sibling != nullptr) {
        sibling->Print(depth, -1, siblingNo + 1);
    }
}

void TreeNode::SetSibling(TreeNode* newSibling) 
{
    if(sibling != nullptr) {
        std::cout << "ATTEMPTING TO OVERWRITE NOT NULL SIBLING!" << std::endl;
        return;
    }

    sibling = newSibling;
}

void TreeNode::SetChild(int childIdx, TreeNode* newChild)
{
    if(childIdx == 0) {
        if(leftChild != nullptr) {
            std::cout << "ATTEMPTING TO OVERWRITE NOT NULL LEFT CHILD" << std::endl;
            return;
        }

        leftChild = newChild;
    }

    if(childIdx == 1) {
        if(middleChild != nullptr) {
            std::cout << "ATTEMPTING TO OVERWRITE NOT NULL MIDDLE CHILD" << std::endl;
            return;
        }

        middleChild = newChild;
    }

    if(childIdx == 2) {
        if(rightChild != nullptr) {
            std::cout << "ATTEMPTING TO OVERWRITE NOT NULL RIGHT CHILD" << std::endl;
            return;
        }

        rightChild = newChild;
    }
}

void TreeNode::SetTypeFromTypedef(TreeNode* typeDef)
{
    if(typeDef == nullptr) {
        varType = VarType::VOID;
        return;
    }

    varType = typeDef->varType;
}

TreeNode* TreeNode::CreateVarDecl(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData)
{
    return new TreeNode(
        DeclType::VARTYPE,
        VarType::VOID,
        tokenData,
        leftChild,
        middleChild,
        rightChild
    );
}

TreeNode* TreeNode::CreateFuncDecl(VarType typeDef, TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData)
{
    return new TreeNode(
        DeclType::FUNCTYPE,
        typeDef,
        tokenData,
        leftChild,
        middleChild,
        nullptr
    ); 
}

TreeNode* TreeNode::CreateIdExp(TokenClass* tokenData)
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
        tokenData,
        leftChild,
        middleChild,
        rightChild
    );
}

TreeNode* TreeNode::CreateWhileStmt(TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData)
{
    return new TreeNode(
        StmtType::WHILETYPE,
        tokenData,
        leftChild,
        middleChild,
        nullptr
    );
}

TreeNode* TreeNode::CreateForStmt(TokenClass* id, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData)
{
    return new TreeNode(
        StmtType::FORTYPE,
        tokenData,
        CreateIdExp(id),
        middleChild,
        rightChild
    );
}

TreeNode* TreeNode::CreateRangeStmt(TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild, TokenClass* tokenData)
{
    return new TreeNode(
        StmtType::RANGETYPE,
        tokenData,
        leftChild,
        middleChild,
        rightChild
    );
}

TreeNode* TreeNode::CreateReturnStmt(TreeNode* leftChild, TokenClass* tokenData)
{
    return new TreeNode(
        StmtType::RETURNTYPE,
        tokenData,
        leftChild,
        nullptr,
        nullptr
    );
}

TreeNode* TreeNode::CreateBreakStmt(TreeNode* leftChild, TokenClass* tokenData)
{
    return new TreeNode(
        StmtType::BREAKTYPE,
        tokenData,
        leftChild,
        nullptr,
        nullptr
    );
}

TreeNode* TreeNode::CreateOpExp(TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData)
{
    return new TreeNode(
        ExpType::OPTYPE,
        tokenData,
        leftChild,
        middleChild,
        nullptr
    );
}

TreeNode* TreeNode::CreateCallExp(TreeNode* leftChild, TokenClass* tokenData)
{
    return new TreeNode(
        ExpType::CALLTYPE,
        tokenData,
        leftChild,
        nullptr,
        nullptr
    );
}

TreeNode* TreeNode::CreateConstExp(TokenClass* tokenData)
{
    return new TreeNode(
        ExpType::CONSTTYPE,
        tokenData,
        nullptr,
        nullptr,
        nullptr
    );
}

TreeNode* TreeNode::PullUpNode(TreeNode* rootNode, TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild)
{
    if(rootNode == nullptr)
        return nullptr;

    rootNode->SetChild(0, leftChild);
    rootNode->SetChild(1, middleChild);
    rootNode->SetChild(2, rightChild);

    return rootNode;
}

TreeNode* TreeNode::NodeList(TreeNode* rootNode, TreeNode* newSibling)
{
    if(rootNode == nullptr)
        return newSibling;

    TreeNode* p = rootNode;

    while(p->sibling != nullptr)
        p = p->sibling;

    p->SetSibling(newSibling);
    return rootNode;
}

TreeNode* TreeNode::PullUpTypeNode(TreeNode* rootNode, VarType typeDef)
{
    if(rootNode == nullptr)
        return rootNode;

    rootNode->varType = typeDef;

    return rootNode;
}