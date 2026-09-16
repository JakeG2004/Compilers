%code requires {
#include "syntaxtree.h"
}

%{
#include <stdio.h>
#include <stdlib.h>

#include "errorhandler.h"
#include "tokenizer.h"

int yylex(void);
void yyerror(const char*);

extern int yylineno;
%}

%union {
    int NUMBER;
    TreeNodePtr node;
};

%token ID NUMCONST CHARCONST STRINGCONST SEMICOLON STATIC COMMA COLON LBRACKET RBRACKET LPAREN RPAREN LBRACE RBRACE ASSIGN ADDASS SUBASS MULASS DIVASS INC DEC LEQ LT GT GEQ EQ NEQ MIN MAX PLUS MINUS STAR DIVIDE MOD QUESTION INT BOOL CHAR IF THEN ELSE WHILE DO FOR RETURN TO BY BREAK OR AND NOT TRUE FALSE

%type <node> program declList decl varDecl scopedVarDecl varDeclList varDeclInit varDeclId typeSpec funDecl parms parmList parmTypeList parmIdList parmId stmt otherStmts expStmt compoundStmt localDecls stmtList selectStmt matchedStmt unmatchedStmt iterRange returnStmt breakStmt exp simpleExp andExp unaryRelExp relExp relop minmaxExp minmaxop sumExp sumop mulExp mulop unaryExp unaryop factor mutable immutable call args argList constant

%%
program:
    declList
    ;

declList:
    declList decl
    | decl
    ;

decl:
    varDecl
    | funDecl
    ;

varDecl:
    typeSpec varDeclList SEMICOLON
    ;

scopedVarDecl:
    STATIC typeSpec varDeclList SEMICOLON
    | typeSpec varDeclList SEMICOLON
    ;

varDeclList:
    varDeclList COMMA varDeclInit
    | varDeclInit
    ;

varDeclInit:
    varDeclId
    | varDeclId COLON simpleExp
    ;

varDeclId:
    ID 
    | ID LBRACKET NUMCONST RBRACKET
    ;

typeSpec:
    INT
    | BOOL
    | CHAR
    ;

funDecl:
    typeSpec ID LPAREN parms RPAREN stmt
    | ID LPAREN parms RPAREN stmt
    ;

parms:
    parmList
    |
    ;

parmList:
    parmList SEMICOLON parmTypeList
    | parmTypeList
    ;

parmTypeList:
    typeSpec parmIdList
    ;

parmIdList:
    parmIdList COMMA parmId
    | parmId
    ;

parmId:
    ID
    | ID LPAREN RPAREN
    ;

stmt:
    selectStmt
    ;

otherStmts:
    expStmt
    | compoundStmt
    | returnStmt
    | breakStmt
    ;

expStmt:
    exp SEMICOLON
    | SEMICOLON
    ;

compoundStmt:
    LBRACE localDecls stmtList RBRACE
    ;

localDecls:
    localDecls scopedVarDecl
    |
    ;

stmtList:
    stmtList stmt
    |
    ;

selectStmt:
    matchedStmt
    | unmatchedStmt
    ;

matchedStmt:
    IF simpleExp THEN matchedStmt ELSE matchedStmt
    | WHILE simpleExp DO matchedStmt
    | FOR ID ASSIGN iterRange DO matchedStmt
    | otherStmts
    ;

unmatchedStmt:
    IF simpleExp THEN selectStmt
    | IF matchedStmt ELSE unmatchedStmt
    | WHILE simpleExp DO unmatchedStmt
    | FOR ID ASSIGN iterRange DO unmatchedStmt
    ;

iterRange:
    simpleExp
    | simpleExp TO simpleExp
    | simpleExp TO simpleExp BY simpleExp
    ;

returnStmt:
    RETURN SEMICOLON
    | RETURN exp SEMICOLON
    ;

breakStmt:
    BREAK SEMICOLON
    | BREAK exp SEMICOLON
    ;

exp:
    mutable ASSIGN exp
    | mutable ADDASS exp
    | mutable SUBASS exp
    | mutable MULASS exp
    | mutable DIVASS exp
    | mutable INC
    | mutable DEC
    | simpleExp
    ;

simpleExp:
    simpleExp OR andExp
    | andExp
    ;

andExp:
    andExp AND unaryRelExp
    | unaryRelExp
    ;

unaryRelExp:
    NOT unaryRelExp
    | relExp
    ;

relExp:
    minmaxExp relop minmaxExp
    | minmaxExp
    ;

relop:
    LEQ
    | LT
    | GT
    | GEQ
    | EQ
    | NEQ
    ;

minmaxExp:
    minmaxExp minmaxop sumExp
    | sumExp
    ;

minmaxop:
    MIN
    | MAX
    ;

sumExp:
    sumExp sumop mulExp
    | mulExp
    ;

sumop:
    PLUS
    | MINUS
    ;

mulExp:
    mulExp mulop unaryExp
    | unaryExp
    ;

mulop:
    STAR
    | DIVIDE
    | MOD
    ;

unaryExp:
    unaryop unaryExp
    | factor
    ;

unaryop:
    MINUS
    | STAR
    | QUESTION
    ;

factor:
    immutable 
    | mutable
    ;

mutable:
    ID
    | ID LBRACKET exp RBRACKET
    ;

immutable:
    LPAREN exp RPAREN
    | call
    | constant
    ;

call:
    ID LPAREN args RPAREN
    ;

args:
    argList
    |
    ;

argList:
    argList COMMA exp
    | exp
    ;

constant:
    NUMCONST
    | CHARCONST
    | STRINGCONST
    | TRUE
    | FALSE
    ;

%%

void yyerror(const char* s)
{
    //ErrorHandler::AddError(Error::ErrorType::PARSER, s, yylineno);
}

int main()
{
    yyparse();

    Tokenizer::PrintTokens();
    return 0;
}