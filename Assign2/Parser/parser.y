%code requires {
#include "treenode.h"
#include "tokenclass.h"
}

%{
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "errorhandler.h"
#include "treenode.h"

int yylex(void);
void yyerror(const char*);

extern FILE* yyin;
extern int yydebug;

TreeNode* ASTRoot = nullptr;
%}

%union {
    int NUMBER;
    TreeNode* node;
    TokenClass* tokenData;
};

%token <tokenData> ID NUMCONST CHARCONST STRINGCONST SEMICOLON STATIC COMMA COLON LBRACKET RBRACKET LPAREN RPAREN LBRACE RBRACE ASSIGN ADDASS SUBASS MULASS DIVASS INC DEC LEQ LT GT GEQ EQ NEQ MIN MAX PLUS MINUS STAR DIVIDE MOD QUESTION INT BOOL CHAR IF THEN ELSE WHILE DO FOR RETURN TO BY BREAK OR AND NOT TRUE FALSE
%type <node> program declList decl varDecl scopedVarDecl varDeclList varDeclInit varDeclId typeSpec funDecl parms parmList parmTypeList parmIdList parmId stmt otherStmts expStmt compoundStmt localDecls stmtList selectStmt matchedStmt unmatchedStmt iterRange returnStmt breakStmt exp simpleExp andExp unaryRelExp relExp relop minmaxExp minmaxop sumExp sumop mulExp mulop unaryExp unaryop factor mutable immutable call args argList constant

%%
program:
    declList    {ASTRoot = $1;}
    ;

declList:
    declList decl   {$$ = $1; $$->SetSibling($2);}
    | decl          {$$ = $1;}
    ;

decl:
    varDecl     {$$ = $1;}
    | funDecl   {$$ = $1;}   
    ;

varDecl:
    typeSpec varDeclList SEMICOLON  {$$ = new TreeNode($1, $2, nullptr, $3);}
    ;

scopedVarDecl:
    STATIC typeSpec varDeclList SEMICOLON   {$$ = new TreeNode($2, $3, nullptr, $1);}
    | typeSpec varDeclList SEMICOLON        {$$ = new TreeNode($1, $2, nullptr, nullptr);}
    ;

varDeclList:
    varDeclList COMMA varDeclInit   {$$ = $1; $$->SetSibling($3);}
    | varDeclInit                   {$$ = $1;}
    ;

varDeclInit:
    varDeclId                   {$$ = $1;}
    | varDeclId COLON simpleExp {$$ = TreeNode::CreateVarDecl($1, $3, nullptr, $2);}
    ;

varDeclId:
    ID                              {$$ = TreeNode::CreateIdNode($1);}
    | ID LBRACKET NUMCONST RBRACKET {$$ = TreeNode::CreateIdNode($1);} 
    ;

typeSpec:
    INT     {$$ = TreeNode::CreateIdNode($1);} 
    | BOOL  {$$ = TreeNode::CreateIdNode($1);}
    | CHAR  {$$ = TreeNode::CreateIdNode($1);}
    ;

funDecl:
    typeSpec ID LPAREN parms RPAREN stmt    {$$ = TreeNode::CreateFuncDecl($1, $4, $6, $2);}
    | ID LPAREN parms RPAREN stmt           {$$ = TreeNode::CreateFuncDecl(nullptr, $3, $5, $1);}
    ;

parms:
    parmList    {$$ = $1;}
    |           {$$ = nullptr;}
    ;

parmList:
    parmList SEMICOLON parmTypeList {$$ = $1; $$->SetSibling($3);}
    | parmTypeList                  {$$ = $1;}
    ;

parmTypeList:
    typeSpec parmIdList {$$ = new TreeNode($1, $2, nullptr, nullptr);}
    ;

parmIdList:
    parmIdList COMMA parmId {$$ = $1; $$->SetSibling($3);}
    | parmId                {$$ = $1;}
    ;

parmId:
    ID                  {$$ = TreeNode::CreateIdNode($1);}
    | ID LPAREN RPAREN  {$$ = TreeNode::CreateIdNode($1);}
    ;

stmt:
    selectStmt  {$$ = $1;}
    ;

otherStmts:
    expStmt         {$$ = $1;}
    | compoundStmt  {$$ = $1;}
    | returnStmt    {$$ = $1;}
    | breakStmt     {$$ = $1;}
    ;

expStmt:
    exp SEMICOLON   {$$ = $1;}
    | SEMICOLON     {$$ = nullptr;}
    ;

compoundStmt:
    LBRACE localDecls stmtList RBRACE   {$$ = TreeNode::CreateCompoundStmt($2, $3);}
    ;

localDecls:
    localDecls scopedVarDecl    {$$ = $1; $$->SetSibling($2);}
    |                           {$$ = nullptr;}
    ;

stmtList:
    stmtList stmt   {$$ = $1; $$->SetSibling($2);}
    |               {$$ = nullptr;}
    ;

selectStmt:
    matchedStmt     {$$ = $1;}
    | unmatchedStmt {$$ = $1;}
    ;

matchedStmt:
    IF simpleExp THEN matchedStmt ELSE matchedStmt  {$$ = TreeNode::CreateIfStmt($2, $4, $6, $1);}
    | WHILE simpleExp DO matchedStmt                {$$ = TreeNode::CreateWhileStmt($2, $4, $1);}
    | FOR ID ASSIGN iterRange DO matchedStmt        {$$ = TreeNode::CreateForStmt($2, $4, $6, $1);}
    | otherStmts                                    {$$ = $1;}
    ;

unmatchedStmt:
    IF simpleExp THEN selectStmt                            {$$ = TreeNode::CreateIfStmt($2, $4, nullptr, $1);}
    | IF simpleExp THEN matchedStmt ELSE unmatchedStmt      {$$ = TreeNode::CreateIfStmt($2, $4, $6, $1);}
    | WHILE simpleExp DO unmatchedStmt                      {$$ = TreeNode::CreateWhileStmt($2, $4, $1);}
    | FOR ID ASSIGN iterRange DO unmatchedStmt              {$$ = TreeNode::CreateForStmt($2, $4, $6, $1);}
    ;

iterRange:
    simpleExp                               {$$ = $1;}
    | simpleExp TO simpleExp                {$$ = TreeNode::CreateRangeStmt($1, $3, nullptr, $2);}
    | simpleExp TO simpleExp BY simpleExp   {$$ = TreeNode::CreateRangeStmt($1, $3, $5, $2);}
    ;

returnStmt:
    RETURN SEMICOLON        {$$ = TreeNode::CreateReturnStmt(nullptr, $1);}
    | RETURN exp SEMICOLON  {$$ = TreeNode::CreateReturnStmt($2, $1);}
    ;

breakStmt:
    BREAK SEMICOLON         {$$ = TreeNode::CreateBreakStmt(nullptr, $1);}
    | BREAK exp SEMICOLON   {$$ = TreeNode::CreateBreakStmt($2, $1);}
    ;

exp:
    mutable ASSIGN exp      {$$ = TreeNode::CreateOpExp($1, $3, $2);}
    | mutable ADDASS exp    {$$ = TreeNode::CreateOpExp($1, $3, $2);}
    | mutable SUBASS exp    {$$ = TreeNode::CreateOpExp($1, $3, $2);}
    | mutable MULASS exp    {$$ = TreeNode::CreateOpExp($1, $3, $2);}
    | mutable DIVASS exp    {$$ = TreeNode::CreateOpExp($1, $3, $2);}
    | mutable INC           {$$ = TreeNode::CreateOpExp($1, nullptr, $2);}
    | mutable DEC           {$$ = TreeNode::CreateOpExp($1, nullptr, $2);}
    | simpleExp             {$$ = $1;}
    ;

simpleExp:
    simpleExp OR andExp {$$ = TreeNode::CreateOpExp($1, $3, $2);}
    | andExp            {$$ = $1;}
    ;

andExp:
    andExp AND unaryRelExp  {$$ = TreeNode::CreateOpExp($1, $3, $2);}
    | unaryRelExp           {$$ = $1;}
    ;

unaryRelExp:
    NOT unaryRelExp {$$ = TreeNode::CreateOpExp($2, nullptr, $1);}
    | relExp        {$$ = $1;}
    ;

relExp:
    minmaxExp relop minmaxExp   {$$ = TreeNode::CreateOpExp($1, $3, $2);}
    | minmaxExp                 {$$ = $1;}
    ;

relop:
    LEQ     {$$ = TreeNode::CreateOpExp(nullptr, nullptr, $1);}
    | LT    {$$ = TreeNode::CreateOpExp(nullptr, nullptr, $1);}
    | GT    {$$ = TreeNode::CreateOpExp(nullptr, nullptr, $1);}
    | GEQ   {$$ = TreeNode::CreateOpExp(nullptr, nullptr, $1);}
    | EQ    {$$ = TreeNode::CreateOpExp(nullptr, nullptr, $1);}
    | NEQ   {$$ = TreeNode::CreateOpExp(nullptr, nullptr, $1);}
    ;

minmaxExp:
    minmaxExp minmaxop sumExp   {$$ = TreeNode::CreateOpExp($1, $3, $2);}
    | sumExp                    {$$ = $1;}
    ;

minmaxop:
    MIN     {$$ = TreeNode::CreateOpExp(nullptr, nullptr, $1);}
    | MAX   {$$ = TreeNode::CreateOpExp(nullptr, nullptr, $1);}
    ;

sumExp:
    sumExp sumop mulExp {$$ = TreeNode::CreateOpExp($1, $3, $2);}
    | mulExp            {$$ = $1;}
    ;

sumop:
    PLUS    {$$ = TreeNode::CreateOpExp(nullptr, nullptr, $1);}
    | MINUS {$$ = TreeNode::CreateOpExp(nullptr, nullptr, $1);}
    ;

mulExp:
    mulExp mulop unaryExp   {$$ = TreeNode::CreateOpExp($1, $3, $2));}
    | unaryExp              {$$ = $1;}
    ;

mulop:
    STAR        {$$ = TreeNode::CreateOpExp(nullptr, nullptr, $1);}
    | DIVIDE    {$$ = TreeNode::CreateOpExp(nullptr, nullptr, $1);}
    | MOD       {$$ = TreeNode::CreateOpExp(nullptr, nullptr, $1);}
    ;

unaryExp:
    unaryop unaryExp    {$$ = TreeNode::CreateOpExp($2, nullptr, $1);}
    | factor            {$$ = $1;}
    ;

unaryop:
    MINUS       {$$ = TreeNode::CreateOpExp(nullptr, nullptr, $1);}
    | STAR      {$$ = TreeNode::CreateOpExp(nullptr, nullptr, $1);}
    | QUESTION  {$$ = TreeNode::CreateOpExp(nullptr, nullptr, $1);}
    ;

factor:
    immutable   {$$ = $1;}
    | mutable   {$$ = $1;}
    ;

mutable:
    ID                          {$$ = TreeNode::CreateIdNode($1);}
    | ID LBRACKET exp RBRACKET  {$$ = TreeNode::CreateIdNode($1);}
    ;

immutable:
    LPAREN exp RPAREN   {$$ = $2;}
    | call              {$$ = $1;}
    | constant          {$$ = $1;}
    ;

call:
    ID LPAREN args RPAREN   {$$ = TreeNode::CreateCallExp($3, $1);}
    ;

args:
    argList {$$ = $1;}
    |       {$$ = nullptr;}
    ;

argList:
    argList COMMA exp   {$$ = $1; $$->SetSibling($3);}
    | exp               {$$ = $1;}
    ;

constant:
    NUMCONST        {$$ = TreeNode::CreateConstExp($1);}
    | CHARCONST     {$$ = TreeNode::CreateConstExp($1);}
    | STRINGCONST   {$$ = TreeNode::CreateConstExp($1);}
    | TRUE          {$$ = TreeNode::CreateConstExp($1);}
    | FALSE         {$$ = TreeNode::CreateConstExp($1);}
    ;

%%

void yyerror(const char* s)
{
    printf("Error!\n");
}

int main(int argc, char* argv[])
{
    if(argc > 2 || (argc == 1 && isatty(fileno(stdin)))) {
        printf("Invalid Usage! Correct usage is\n./c- <filename>\nor cat <filename> | ./c-\nor ./c- < <filename>\n");
        return 2;
    }

    if(argc == 2) {
        FILE* file = fopen(argv[1], "r");
        if(!file) {
            perror(argv[1]);
            return 1;
        }

        yyin = file;
    }

    yyparse();

    ASTRoot->Print();
    return 0;
}