#include "treenode.h"
#include "parser.tab.h"

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

void TreeNode::Print(int depth, int childNo, int siblingNo, bool printType)
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
    PrintSelf(printType);

    nextDepth++;

    if(leftChild != nullptr) {
        leftChild->Print(nextDepth, 0, 0, printType);
    }

    if(middleChild != nullptr) {
        middleChild->Print(nextDepth, 1, 0, printType);
    }

    if(rightChild != nullptr) {
        rightChild->Print(nextDepth, 2, 0, printType);
    }

    if(sibling != nullptr) {
        sibling->Print(depth, -1, siblingNo + 1, printType);
    }
}

void TreeNode::PrintSelf(bool printType)
{
    switch(nodeType) {
        case NodeType::DECLNODE:
            PrintDecl(printType);
            break;

        case NodeType::STMTNODE:
            PrintStmt(printType);
            break;

        case NodeType::EXPNODE:
            PrintExp(printType);
            break;

        default:
            std::cout << "NODE: IDK!!!!" << std::endl;
            break;
    }
}

void TreeNode::PrintDecl(bool printType)
{
    switch(subType.decl) {
        case DeclType::VARTYPE:
            std::cout << "Var: " << tokenData->tokenStr << GetArrText() << " of " << GetTypeString();
            break;

        case DeclType::FUNCTYPE:
            std::cout << "Func: " << tokenData->tokenStr << " returns " << GetTypeString();
            break;

        case DeclType::PARMTYPE:
            std::cout << "Parm: " << tokenData->tokenStr << GetArrText() << " of " << GetTypeString();
            break;

        default:
            std::cout << "Unknown Decl: " << tokenData->tokenStr;
            break;
    }

    std::cout << " [line: " << tokenData->lineNum << "]" << PrintType(printType) << std::endl;
}

void TreeNode::PrintStmt(bool printType)
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

    std::cout << " [line: " << tokenData->lineNum << "]" << PrintType(printType) << std::endl;
}

void TreeNode::PrintExp(bool printType)
{
    switch(subType.exp) {
        case ExpType::OPTYPE:
            std::cout << "Op: " << GetUnaryOrRegOp() << " of " << GetTypeString();
            break;

        case ExpType::CONSTTYPE:
            std::cout << "Const" << GetArrText() << " ";
            if(varType == VarType::INTEGER)
                std::cout << tokenData->numVal;
            else
                std::cout << tokenData->stringVal;
            std::cout << " of " << GetTypeString();
            break;

        case ExpType::IDTYPE:
            std::cout << "Id: " << tokenData->tokenStr << " of " << GetTypeString();
            break;

        case ExpType::ASSIGNTYPE:
            std::cout << "Assign: " << tokenData->tokenStr << " of " << GetTypeString();
            break;

        case ExpType::INITTYPE:
            std::cout << "Init: " << tokenData->tokenStr << " of " << GetTypeString();
            break;

        case ExpType::CALLTYPE:
            std::cout << "Call: " << tokenData->tokenStr << " of " << GetTypeString();
            break;

        default:
            std::cout << "Unknown Expression";
            break;
    }

    std::cout << " [line: " << tokenData->lineNum << "]" << PrintType(printType) << std::endl;
}

// ========================
// === HELPER FUNCTIONS ===
// ========================

std::string TreeNode::PrintType(bool printType)
{
    if(printType) {
        return " OF TYPE: " + GetTypeString() + " "; 
    }

    else return "";
}

std::string TreeNode::GetTypeString()
{
    switch(varType) {
        case VarType::VOID:
            return "type void";

        case VarType::INTEGER:
            return "type int";

        case VarType::BOOLEAN:
            return "type bool";

        case VarType::STRING:
        case VarType::CHARACTER:
            return "type char";

        case VarType::UNDEFINED:
            return "undefined type";
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
    switch(tokenData->tokenClass) {
        case MINUS:
            if(isUnary) return "chsign";
            else return "-";

        case STAR:
            if(isUnary) return "sizeof";
            else return "*";

        case NOT:
            return "not";

        case OR:
            return "or";

        case AND:
            return "and";

        default:
            return tokenData->tokenName;
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


TreeNode* TreeNode::CreateParmDecl(TokenClass* parmToken)
{
    TreeNode* newNode = new TreeNode(
        DeclType::PARMTYPE,
        VarType::VOID,
        parmToken,
        nullptr,
        nullptr,
        nullptr
    );

    newNode->initializedAt = newNode;

    return newNode;
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
    TreeNode* newNode = new TreeNode(
        ExpType::OPTYPE,
        opToken,
        lhs,
        rhs,
        nullptr
    );

    if(lhs != nullptr && rhs != nullptr)
        newNode->isConst = (lhs->isConst && rhs->isConst);
    else if (lhs != nullptr)
        newNode->isConst = lhs->isConst;
    else if (rhs != nullptr)
        newNode->isConst = rhs->isConst;

    return newNode;
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
    newNode->varType = VarType::INTEGER;

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
    rootNode->UpdateIsConst();

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

void TreeNode::UpdateIsConst()
{
    if(nodeType != NodeType::EXPNODE || subType.exp != ExpType::OPTYPE)
        return;

    if(tokenData->tokenClass == QUESTION) {   // ?x is random, so never constant
        isConst = false;
        return;
    }

    TreeNode* kids[3] = {leftChild, middleChild, rightChild};
    bool any = false, all = true;
    for(TreeNode* k : kids) {
        if(k == nullptr) continue;
        any = true;
        all = all && k->isConst;
    }
    isConst = any && all;
}