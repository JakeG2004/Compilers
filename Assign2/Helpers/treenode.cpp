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
    this->varType = varType;
    this->nodeType = NodeType::DECLNODE;
}

TreeNode::TreeNode(StmtType stmtType, TokenClass* tokenData, TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild)
    : TreeNode(leftChild, middleChild, rightChild, tokenData)
{
    this->subType.stmt = stmtType;
    this->nodeType = NodeType::STMTNODE;
}

TreeNode::TreeNode(ExpType expType, TokenClass* tokenData, TreeNode* leftChild, TreeNode* middleChild, TreeNode* rightChild)
    : TreeNode(leftChild, middleChild, rightChild, tokenData)
{
    this->subType.exp = expType;
    this->nodeType = NodeType::EXPNODE;
}

void TreeNode::Print(int depth, int childNo, int siblingNo)
{
    int nextDepth = depth;

    // indentation
    for(int i = 0; i < depth; i++)
        std::cout << ".   ";

    // child
    if(childNo != -1)
        std::cout << "Child: " << childNo << "  ";

    // sibling
    if(siblingNo != 0)
        std::cout << "Sibling: " << siblingNo << "  ";

    // print the data in the node
    PrintSelf();

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

void TreeNode::PrintSelf()
{
    switch(nodeType) {
        case NodeType::DECLNODE:
            PrintDecl();
            break;

        case NodeType::STMTNODE:
            PrintStmt();
            break;

        case NodeType::EXPNODE:
            PrintExp();
            break;
    }
}

void TreeNode::PrintDecl()
{
    switch(subType.decl) {
        case DeclType::VARTYPE:
            std::cout << "Var: " << tokenData->tokenStr << GetArrText() << " of type " << GetTypeString();
            break;

        case DeclType::FUNCTYPE:
            std::cout << "Func: " << tokenData->tokenStr << " returns type " << GetTypeString();
            break;

        case DeclType::EXPTYPE:
            std::cout << "Exp: " << tokenData->tokenStr << " of type " << GetTypeString();
            break;

        default:
            std::cout << "Unknown Decl: " << tokenData->tokenStr;
            break;
    }

    std::cout << " [line: " << tokenData->lineNum << "]" << std::endl;
}

void TreeNode::PrintStmt()
{
    switch(subType.stmt) {
        case StmtType::NULLTYPE:
            std::cout << "Null";
            break;

        case StmtType::IFTYPE:
            std::cout << "If";
            break;

        case StmtType::WHILETYPE:
            std::cout << "While";
            break;

        case StmtType::FORTYPE:
            std::cout << "For";
            break;

        case StmtType::COMPOUNDTYPE:
            std::cout << "Compound";
            break;

        case StmtType::RETURNTYPE:
            std::cout << "Return";
            break;

        case StmtType::BREAKTYPE:
            std::cout << "Break";
            break;

        case StmtType::RANGETYPE:
            std::cout << "Range";
            break;

        default:
            std::cout << "Unknown Statment";
            break;
    }

    std::cout << " [line: " << tokenData->lineNum << "]" << std::endl;
}

void TreeNode::PrintExp()
{
    switch(subType.exp) {
        case ExpType::OPTYPE:
            std::cout << "Op: " << GetUnaryOrRegOp();
            break;

        case ExpType::CONSTTYPE:
            std::cout << "Const" << GetArrText() << " of type " << GetTypeString() << ": " << tokenData->stringVal;
            break;

        case ExpType::IDTYPE:
            std::cout << "Id: " << tokenData->tokenStr;
            break;

        case ExpType::PARMTYPE:
            std::cout << "Parm: " << tokenData->tokenStr << GetArrText() << " of type " << GetTypeString();
            break;

        case ExpType::ASSIGNTYPE:
            std::cout << "Assign: " << tokenData->tokenStr;
            break;

        case ExpType::INITTYPE:
            std::cout << "Init: " << tokenData->tokenStr;
            break;

        case ExpType::CALLTYPE:
            std::cout << "Call: " << tokenData->tokenStr;
            break;

        default:
            std::cout << "Unknown Expression";
            break;
    }

    std::cout << " [line: " << tokenData->lineNum << "]" << std::endl;
}

std::string TreeNode::GetTypeString()
{
    switch(varType) {
        case VarType::VOID:
            return "void";

        case VarType::INTEGER:
            return "int";

        case VarType::BOOLEAN:
            return "bool";

        case VarType::STRING:
        case VarType::CHARACTER:
            return "char";

        case VarType::CHARINT:
            return "charint";

        case VarType::EQUAL:
            return "equal";

        case VarType::UNDEFINED:
            return "I DONT KNOW!!!";
            break;

        default:
            return "undefined";
    }
}

std::string TreeNode::GetArrText()
{
    if(isArray)
        return " is array";
    
    return "";
}

std::string TreeNode::GetUnaryOrRegOp()
{
    if(tokenData->tokenStr == "-") {
        if(isUnary) return "CHSIGN";
        else return "-";
    }

    else if(tokenData->tokenStr == "*") {
        if(isUnary) return "SIZEOF";
        else return "*";
    }

    return tokenData->tokenName;
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

TreeNode* TreeNode::CreateVarDecl(TokenClass* index, TokenClass* tokenData)
{
    return new TreeNode(
        DeclType::VARTYPE,
        VarType::VOID,
        tokenData,
        nullptr,
        nullptr,
        nullptr
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

TreeNode* TreeNode::CreateParmExp(TokenClass* tokenData)
{
    return new TreeNode(
        ExpType::PARMTYPE,
        tokenData,
        nullptr,
        nullptr,
        nullptr
    );
}

TreeNode* TreeNode::CreateInitExp(TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData)
{
    return new TreeNode(
        ExpType::INITTYPE,
        tokenData,
        leftChild,
        middleChild,
        nullptr
    );
}

TreeNode* TreeNode::CreateCompoundStmt(TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData)
{
    return new TreeNode(
        StmtType::COMPOUNDTYPE,
        tokenData,
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
    TreeNode* forNode = new TreeNode(
        StmtType::FORTYPE,
        tokenData,
        CreateVarDecl(nullptr, id),
        middleChild,
        rightChild
    );

    forNode->leftChild->varType = VarType::INTEGER;
    return forNode;
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

TreeNode* TreeNode::CreateUnaryOpExp(TokenClass* tokenData)
{
    TreeNode* newNode = new TreeNode(
        ExpType::OPTYPE,
        tokenData,
        nullptr,
        nullptr,
        nullptr
    );

    newNode->isUnary = true;

    return newNode;
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

TreeNode* TreeNode::CreateConstExp(VarType typeDef, TokenClass* tokenData)
{
    TreeNode* newNode = new TreeNode(
        ExpType::CONSTTYPE,
        tokenData,
        nullptr,
        nullptr,
        nullptr
    );

    newNode->varType = typeDef;

    if(typeDef == VarType::STRING) {
        newNode->isArray = true;
    }

    return newNode;
}

TreeNode* TreeNode::CreateAssignExp(TreeNode* leftChild, TreeNode* middleChild, TokenClass* tokenData)
{
    return new TreeNode(
        ExpType::ASSIGNTYPE,
        tokenData,
        leftChild,
        middleChild,
        nullptr
    );
}

TreeNode* TreeNode::CreateIdxExp(TreeNode* exp, TokenClass* id, TokenClass* lbracket)
{
    TreeNode* bracketNode = CreateOpExp(
        CreateIdExp(id),
        exp,
        lbracket
    );

    return bracketNode;
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

void TreeNode::SetNodeListTypes(VarType typeDef, TreeNode* node)
{
    if(node == nullptr)
        return;

    node->varType = typeDef;

    TreeNode* p = node;
    while(p != nullptr) {
        p->varType = typeDef;
        p = p->sibling;
    }
}