%{
#include "calculator.tab.h"
#include <stdlib.h>
%}

%option noyywrap

%%
[0-9]+      { yylval = atoi(yytext); return INTEGER; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MULTIPLY; }
"/"         { return DIVIDE; }
"("         { return LPAREN; }
")"         { return RPAREN; }
[ \t]       ;
\n          { return EOL; }
.           { return ERROR; }
%%