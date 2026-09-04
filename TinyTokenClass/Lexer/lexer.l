%{
#include "parser.tab.h"
#include "tokenizer.h"

#include <stdlib.h>

#define TOKEN(t) { return AddToken(t); }

int AddToken(int tokenClass);

%}

%option noyywrap
%option yylineno

%%
"if"        TOKEN(IF)
"then"      TOKEN(THEN)
"else"      TOKEN(ELSE)
"end"       TOKEN(END)
"repeat"    TOKEN(REPEAT)
"until"     TOKEN(UNTIL)
"read"      TOKEN(READ)
"write"     TOKEN(WRITE)

";"         TOKEN(SEMICOLON)
"<"         TOKEN(LESS_THAN)
"="         TOKEN(EQUAL)
":="        TOKEN(ASSIGN)
"+"         TOKEN(PLUS)
"-"         TOKEN(MINUS)
"*"         TOKEN(MULTIPLY)
"/"         TOKEN(DIVIDE)
"("         TOKEN(LPAREN)
")"         TOKEN(RPAREN)

[0-9]+      { yylval = atoi(yytext); TOKEN(NUM); }
[a-zA-Z]+   TOKEN(ID)

[ \t\n]     ;
%%

int AddToken(int tokenClass)
{
    Tokenizer::AddToken(tokenClass, yylineno, yytext, yylval);
    return tokenClass;
}