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

#define LEAF(t) (new TreeNode(t))

int yylex(void);
void yyerror(const char*);

extern FILE* yyin;
extern int yydebug;

TreeNode* root = nullptr;
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
    declList    {root = $1;}
    ;

declList:
    declList decl   {$$ = new TreeNode($1, $2, nullptr);}
    | decl          {$$ = $1;}
    ;

decl:
    varDecl     {$$ = $1;}
    | funDecl   {$$ = $1;}   
    ;

varDecl:
    typeSpec varDeclList SEMICOLON  {$$ = new TreeNode($1, $2, nullptr);}
    ;

scopedVarDecl:
    STATIC typeSpec varDeclList SEMICOLON   {$$ = new TreeNode($2, $3, $1);}
    | typeSpec varDeclList SEMICOLON        {$$ = new TreeNode($1, $2, nullptr);}
    ;

varDeclList:
    varDeclList COMMA varDeclInit   {$$ = new TreeNode($1, $3, $2);}
    | varDeclInit                   {$$ = $1;}
    ;

varDeclInit:
    varDeclId                   {$$ = $1;}
    | varDeclId COLON simpleExp {$$ = new TreeNode($1, $3, $2);}
    ;

varDeclId:
    ID                              {$$ = new TreeNode($1);}
    | ID LBRACKET NUMCONST RBRACKET {$$ = new TreeNode(LEAF($3), $1);} 
    ;

typeSpec:
    INT     {$$ = new TreeNode($1);} 
    | BOOL  {$$ = new TreeNode($1);}
    | CHAR  {$$ = new TreeNode($1);}
    ;

funDecl:
    typeSpec ID LPAREN parms RPAREN stmt    {$$ = new TreeNode($1, $4, $6, $2);}
    | ID LPAREN parms RPAREN stmt           {$$ = new TreeNode($3, $5, $1);}
    ;

parms:
    parmList    {$$ = $1;}
    |           {$$ = nullptr;}
    ;

parmList:
    parmList SEMICOLON parmTypeList {$$ = new TreeNode($1, $3, $2);}
    | parmTypeList                  {$$ = $1;}
    ;

parmTypeList:
    typeSpec parmIdList {$$ = new TreeNode($1, $2, nullptr);}
    ;

parmIdList:
    parmIdList COMMA parmId {$$ = new TreeNode($1, $3, $2);}
    | parmId                {$$ = $1;}
    ;

parmId:
    ID                  {$$ = new TreeNode($1);}
    | ID LPAREN RPAREN  {$$ = new TreeNode($1);}
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
    exp SEMICOLON   {$$ = new TreeNode($1, nullptr);}
    | SEMICOLON     {$$ = nullptr;}
    ;

compoundStmt:
    LBRACE localDecls stmtList RBRACE   {$$ = new TreeNode($2, $3, nullptr);}
    ;

localDecls:
    localDecls scopedVarDecl    {$$ = new TreeNode($1, $2, nullptr);}
    |                           {$$ = nullptr;}
    ;

stmtList:
    stmtList stmt   {$$ = new TreeNode($1, $2, nullptr);}
    |               {$$ = nullptr;}
    ;

selectStmt:
    matchedStmt     {$$ = $1;}
    | unmatchedStmt {$$ = $1;}
    ;

matchedStmt:
    IF simpleExp THEN matchedStmt ELSE matchedStmt  {$$ = new TreeNode($2, $4, $6, $1);}
    | WHILE simpleExp DO matchedStmt                {$$ = new TreeNode($2, $4, $1);}
    | FOR ID ASSIGN iterRange DO matchedStmt        {$$ = new TreeNode(LEAF($2), $4, $6, $1);}
    | otherStmts                                    {$$ = $1;}
    ;

unmatchedStmt:
    IF simpleExp THEN selectStmt                {$$ = new TreeNode($2, $4, $1);}
    | IF matchedStmt ELSE unmatchedStmt         {$$ = new TreeNode($2, $4, $1);}
    | WHILE simpleExp DO unmatchedStmt          {$$ = new TreeNode($2, $4, $1);}
    | FOR ID ASSIGN iterRange DO unmatchedStmt  {$$ = new TreeNode(LEAF($2), $4, $6, $1);}
    ;

iterRange:
    simpleExp                               {$$ = $1;}
    | simpleExp TO simpleExp                {$$ = new TreeNode($1, $3, $2);}
    | simpleExp TO simpleExp BY simpleExp   {$$ = new TreeNode($1, $3, $5, $2);}
    ;

returnStmt:
    RETURN SEMICOLON        {$$ = new TreeNode($1);}
    | RETURN exp SEMICOLON  {$$ = new TreeNode($2, $1);}
    ;

breakStmt:
    BREAK SEMICOLON         {$$ = new TreeNode($1);}
    | BREAK exp SEMICOLON   {$$ = new TreeNode($2, $1);}
    ;

exp:
    mutable ASSIGN exp      {$$ = new TreeNode($1, $3, $2);}
    | mutable ADDASS exp    {$$ = new TreeNode($1, $3, $2);}
    | mutable SUBASS exp    {$$ = new TreeNode($1, $3, $2);}
    | mutable MULASS exp    {$$ = new TreeNode($1, $3, $2);}
    | mutable DIVASS exp    {$$ = new TreeNode($1, $3, $2);}
    | mutable INC           {$$ = new TreeNode($1, $2);}
    | mutable DEC           {$$ = new TreeNode($1, $2);}
    | simpleExp             {$$ = $1;}
    ;

simpleExp:
    simpleExp OR andExp {$$ = new TreeNode($1, $3, $2);}
    | andExp            {$$ = $1;}
    ;

andExp:
    andExp AND unaryRelExp  {$$ = new TreeNode($1, $3, $2);}
    | unaryRelExp           {$$ = $1;}
    ;

unaryRelExp:
    NOT unaryRelExp {$$ = new TreeNode($2, $1);}
    | relExp        {$$ = $1;}
    ;

relExp:
    minmaxExp relop minmaxExp   {$$ = new TreeNode($1, $2, $3, nullptr);}
    | minmaxExp                 {$$ = $1;}
    ;

relop:
    LEQ     {$$ = new TreeNode($1);}
    | LT    {$$ = new TreeNode($1);}
    | GT    {$$ = new TreeNode($1);}
    | GEQ   {$$ = new TreeNode($1);}
    | EQ    {$$ = new TreeNode($1);}
    | NEQ   {$$ = new TreeNode($1);}
    ;

minmaxExp:
    minmaxExp minmaxop sumExp   {$$ = new TreeNode($1, $2, $3, nullptr);}
    | sumExp                    {$$ = $1;}
    ;

minmaxop:
    MIN     {$$ = new TreeNode($1);}
    | MAX   {$$ = new TreeNode($1);}
    ;

sumExp:
    sumExp sumop mulExp {$$ = new TreeNode($1, $2, $3, nullptr);}
    | mulExp            {$$ = $1;}
    ;

sumop:
    PLUS    {$$ = new TreeNode($1);}
    | MINUS {$$ = new TreeNode($1);}
    ;

mulExp:
    mulExp mulop unaryExp   {$$ = new TreeNode($1, $2, $3, nullptr);}
    | unaryExp              {$$ = $1;}
    ;

mulop:
    STAR        {$$ = new TreeNode($1);}
    | DIVIDE    {$$ = new TreeNode($1);}
    | MOD       {$$ = new TreeNode($1);}
    ;

unaryExp:
    unaryop unaryExp    {$$ = new TreeNode($1, $2, nullptr);}
    | factor            {$$ = $1;}
    ;

unaryop:
    MINUS       {$$ = new TreeNode($1);}
    | STAR      {$$ = new TreeNode($1);}
    | QUESTION  {$$ = new TreeNode($1);}
    ;

factor:
    immutable   {$$ = $1;}
    | mutable   {$$ = $1;}
    ;

mutable:
    ID                          {$$ = new TreeNode($1);}
    | ID LBRACKET exp RBRACKET  {$$ = new TreeNode($3, $1);}
    ;

immutable:
    LPAREN exp RPAREN   {$$ = $2;}
    | call              {$$ = $1;}
    | constant          {$$ = $1;}
    ;

call:
    ID LPAREN args RPAREN   {$$ = new TreeNode($3, $1);}
    ;

args:
    argList {$$ = $1;}
    |       {$$ = nullptr;}
    ;

argList:
    argList COMMA exp   {$$ = new TreeNode($1, $3, $2);}
    | exp               {$$ = $1;}
    ;

constant:
    NUMCONST        {$$ = new TreeNode($1);}
    | CHARCONST     {$$ = new TreeNode($1);}
    | STRINGCONST   {$$ = new TreeNode($1);}
    | TRUE          {$$ = new TreeNode($1);}
    | FALSE         {$$ = new TreeNode($1);}
    ;

%%

void yyerror(const char* s)
{
    printf("Error!\n");
}

int main(int argc, char* argv[])
{
    if(argc > 2 || (argc == 1 && isatty(fileno(stdin)))) {
        printf("Invalid Usage! ./c- <filename> or cat <filename> | ./c-\n");
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

    root->Print();
    return 0;
}