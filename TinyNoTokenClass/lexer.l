%{
#include "parser.tab.h"
#include <stdlib.h>
%}

%option noyywrap
%option yylineno

%%
"if"        { return IF; }
"then"      { return THEN; }
"else"      { return ELSE; }
"end"       { return END; }
"repeat"    { return REPEAT; }
"until"     { return UNTIL; }
"read"      { return READ; }
"write"     { return WRITE; }

";"         { return SEMICOLON; }
"<"         { return LESS_THAN; }
"="         { return EQUAL; }
":="        { return ASSIGN; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MULTIPLY; }
"/"         { return DIVIDE; }
"("         { return LPAREN; }
")"         { return RPAREN; }

[0-9]+      { yylval = atoi(yytext); return NUM; }
[a-zA-Z]+   { return ID; }

[ \t\n]     ;
%%