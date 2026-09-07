%{
#include <stdio.h>
#include <stdlib.h>

#include "errorhandler.h"
#include "tokenizer.h"

int yylex(void);
void yyerror(const char*);

extern int yylineno;
%}

%token ID NUMCONST CHARCONST STRINGCONST SEMICOLON STATIC COMMA COLON LBRACKET RBRACKET LPAREN RPAREN LBRACE RBRACE ASSIGN PLUSEQ MINUSEQ MULTEQ DIVEQ INCR DECR LTE LT GT GTE EQ NEQ MIN MAX PLUS MINUS STAR DIVIDE MOD QUESTION INT BOOL CHAR IF THEN ELSE WHILE DO FOR RETURN TO BY BREAK OR AND NOT TRUE FALSE

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
    expStmt
    | compoundStmt
    | selectStmt
    | iterStmt
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
    IF simpleExp THEN stmt
    | IF simpleExp THEN stmt ELSE stmt
    ;

iterStmt:
    WHILE simpleExp DO stmt
    | FOR ID ASSIGN iterRange DO stmt
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
    | mutable PLUSEQ exp
    | mutable MINUSEQ exp
    | mutable MULTEQ exp
    | mutable DIVEQ exp
    | mutable INCR
    | mutable DECR
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
    LTE
    | LT
    | GT
    | GTE
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