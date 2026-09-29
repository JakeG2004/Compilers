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

        default:
            std::cout << "Unknown Decl: " << tokenData->tokenStr;
            break;
    }

    std::cout << " [line: " << tokenData->lineNum << "]" << std::endl;
}

void TreeNode::PrintStmt()
{
    switch(subType.stmt) {
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

// ========================
// === HELPER FUNCTIONS ===
// ========================

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

        case VarType::UNDEFINED:
            return "undefined (the defined one)";
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

// ======================
// === DECL FACTORIES ===
// ======================

TreeNode* TreeNode::CreateVarDecl(TokenClass* indexOrSize, TokenClass* id)
{
    TreeNode* newNode = new TreeNode(
        DeclType::VARTYPE,
        VarType::VOID,
        id,
        nullptr,
        nullptr,
        nullptr
    );

    if(indexOrSize != nullptr)
        newNode->indexOrSize = indexOrSize->numVal;

    return newNode;
}

TreeNode* TreeNode::CreateFuncDecl(VarType varType, TreeNode* parms, TreeNode* stmt, TokenClass* id)
{
    return new TreeNode(
        DeclType::FUNCTYPE,
        varType,
        id,
        parms,
        stmt,
        nullptr
    ); 
}

// ======================
// === STMT FACTORIES ===
// ======================

TreeNode* TreeNode::CreateCompoundStmt(TreeNode* localDecls, TreeNode* stmtList, TokenClass* lbrace)
{
    return new TreeNode(
        StmtType::COMPOUNDTYPE,
        lbrace,
        localDecls,
        stmtList,
        nullptr
    );
}

TreeNode* TreeNode::CreateIfStmt(TreeNode* condition, TreeNode* thenStmt, TreeNode* elseStmt, TokenClass* ifToken)
{
    return new TreeNode(
        StmtType::IFTYPE,
        ifToken,
        condition,
        thenStmt,
        elseStmt
    );
}

TreeNode* TreeNode::CreateWhileStmt(TreeNode* condition, TreeNode* stmt, TokenClass* whileToken)
{
    return new TreeNode(
        StmtType::WHILETYPE,
        whileToken,
        condition,
        stmt,
        nullptr
    );
}

TreeNode* TreeNode::CreateForStmt(TreeNode* range, TreeNode* stmt, TokenClass* id, TokenClass* forToken)
{
    TreeNode* forNode = new TreeNode(
        StmtType::FORTYPE,
        forToken,
        CreateVarDecl(nullptr, id),
        range,
        stmt
    );

    forNode->leftChild->varType = VarType::INTEGER;
    return forNode;
}

TreeNode* TreeNode::CreateRangeStmt(TreeNode* lowExp, TreeNode* highExp, TreeNode* byExp, TokenClass* toToken)
{
    return new TreeNode(
        StmtType::RANGETYPE,
        toToken,
        lowExp,
        highExp,
        byExp
    );
}

TreeNode* TreeNode::CreateReturnStmt(TreeNode* retVal, TokenClass* returnToken)
{
    return new TreeNode(
        StmtType::RETURNTYPE,
        returnToken,
        retVal,
        nullptr,
        nullptr
    );
}

TreeNode* TreeNode::CreateBreakStmt(TreeNode* breakVal, TokenClass* breakToken)
{
    return new TreeNode(
        StmtType::BREAKTYPE,
        breakToken,
        breakVal,
        nullptr,
        nullptr
    );
}

// =====================
// === EXP FACTORIES ===
// =====================

TreeNode* TreeNode::CreateOpExp(TreeNode* lhs, TreeNode* rhs, TokenClass* opToken)
{
    return new TreeNode(
        ExpType::OPTYPE,
        opToken,
        lhs,
        rhs,
        nullptr
    );
}

TreeNode* TreeNode::CreateUnaryOpExp(TokenClass* unaryOpToken)
{
    TreeNode* newNode = new TreeNode(
        ExpType::OPTYPE,
        unaryOpToken,
        nullptr,
        nullptr,
        nullptr
    );

    newNode->isUnary = true;

    return newNode;
}

TreeNode* TreeNode::CreateCallExp(TreeNode* args, TokenClass* id)
{
    return new TreeNode(
        ExpType::CALLTYPE,
        id,
        args,
        nullptr,
        nullptr
    );
}

TreeNode* TreeNode::CreateConstExp(VarType typeDef, TokenClass* constToken)
{
    TreeNode* newNode = new TreeNode(
        ExpType::CONSTTYPE,
        constToken,
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

TreeNode* TreeNode::CreateIdExp(TokenClass* id)
{
    return new TreeNode(
        ExpType::IDTYPE,
        id,
        nullptr,
        nullptr,
        nullptr
    );
}

TreeNode* TreeNode::CreateParmExp(TokenClass* parmToken)
{
    return new TreeNode(
        ExpType::PARMTYPE,
        parmToken,
        nullptr,
        nullptr,
        nullptr
    );
}

TreeNode* TreeNode::CreateAssignExp(TreeNode* lhs, TreeNode* rhs, TokenClass* assignToken)
{
    return new TreeNode(
        ExpType::ASSIGNTYPE,
        assignToken,
        lhs,
        rhs,
        nullptr
    );
}

TreeNode* TreeNode::CreateIdxExp(TreeNode* idxExp, TokenClass* id, TokenClass* lbracket)
{
    TreeNode* bracketNode = CreateOpExp(
        CreateIdExp(id),
        idxExp,
        lbracket
    );

    return bracketNode;
}

// ======================
// === NODE FUNCTIONS ===
// ======================

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