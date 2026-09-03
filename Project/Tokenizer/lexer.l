%{
#include "Tokenizer.h"

#ifdef CPLUSPLUS
extern int yylex();
#endif

%}

%option c++ noyywrap

%%
[0-9]*  { Tokenizer::CreateAndAddNewToken(yytext, 0, 0); }
"+"     { return '+'; }

[ \t\n] {/* Ignore whitespace */}
.       {/* Ignore extra characters */}
%%

int main()
{
    yylex();
    return 0;
}