%{
#include "parser.tab.h"
#include "tokenizer.h"
#include "errorhandler.h"

#include <stdlib.h>
#include <string.h>

#define TOKEN(t) { return AddToken(t); }

int AddToken(int tokenClass);

%}

%option noyywrap
%option yylineno

digit               [0-9]
letter              [a-zA-Z_]
letdig              {digit}|{letter}
char                "'"([^'\\\n]|\\.)*"'"
string              "\""([^"\\\n]|\\.)*"\""
comment             "//"[^\n]*

%%
"int"               TOKEN(INT)
"bool"              TOKEN(BOOL)
"char"              TOKEN(CHAR)
"if"                TOKEN(IF)
"else"              TOKEN(ELSE)
"while"             TOKEN(WHILE)
"for"               TOKEN(FOR)
"return"            TOKEN(RETURN)
"break"             TOKEN(BREAK)
"true"              TOKEN(BOOLCONST)
"false"             TOKEN(BOOLCONST)
"static"            TOKEN(STATIC)
"in"                TOKEN(IN)

";"                 TOKEN(SEMICOLON)
":"                 TOKEN(COLON)
","                 TOKEN(COMMA)
"["                 TOKEN(LBRACKET)
"]"                 TOKEN(RBRACKET)
"("                 TOKEN(LPAREN)
")"                 TOKEN(RPAREN)
"{"                 TOKEN(LBRACE)
"}"                 TOKEN(RBRACE)
"="                 TOKEN(ASSIGN)
"+="                TOKEN(ADDASS)
"-="                TOKEN(SUBASS)
"*="                TOKEN(MULASS)
"/="                TOKEN(DIVASS)
"++"                TOKEN(INC)
"--"                TOKEN(DEC)
"<="                TOKEN(LEQ)
"<"                 TOKEN(LT)
">"                 TOKEN(GT)
">="                TOKEN(GEQ)
"=="                TOKEN(EQ)
"!="                TOKEN(NEQ)
"<<"                TOKEN(MIN)
">>"                TOKEN(MAX)
"+"                 TOKEN(PLUS)
"-"                 TOKEN(MINUS)
"*"                 TOKEN(STAR)
"/"                 TOKEN(DIVIDE)
"%"                 TOKEN(MOD)
"?"                 TOKEN(QUESTION)
"!"                 TOKEN(EXCLAMATION)
"|"                 TOKEN(PIPE)
"&"                 TOKEN(AMPERSAND)

''                  { ErrorHandler::AddError(Error::ErrorType::EMPTY_CHAR, yytext, yylineno); }

{letter}{letdig}*   TOKEN(ID)
{digit}+            TOKEN(NUMCONST)
{char}              TOKEN(CHARCONST)
{string}            TOKEN(STRINGCONST)

{comment}           ;
[ \t\n]             ;
.                   { ErrorHandler::AddError(Error::ErrorType::INVALID_CHAR, yytext, yylineno); }
%%

int AddToken(int tokenClass)
{
    char c = '\0';
    long long int nVal = 0;

    switch(tokenClass) {
        case ID:
            break;

        case NUMCONST:
            nVal = atoi(yytext);
            break;

        case CHARCONST: {
            int len = strlen(yytext);
            if (yytext[1] == '\\') {
                if (len > 4)
                    ErrorHandler::AddError(Error::ErrorType::LONG_CHAR, yytext, yylineno);
                switch (yytext[2]) {
                    case '0':  c = '\0'; break;
                    case 'n':  c = '\n'; break;
                    case 't':  c = '\t'; break;
                    case '\\': c = '\\'; break;
                    case '\'': c = '\''; break;
                    default:   c = yytext[2]; break;
                }
            } else {
                if (len > 3) {
                    ErrorHandler::AddError(Error::ErrorType::LONG_CHAR, yytext, yylineno);
                }
                c = yytext[1];
            }
            break;
        }

        case STRINGCONST:
            break;

        case BOOLCONST:
            if(strcmp("true", yytext) == 0) {
                nVal = 1;
            }
            else {
                nVal = 0;
            }
            break;

        default:
            break;
    };

    Tokenizer::AddToken(tokenClass, yylineno, yytext, c, nVal);
    return tokenClass;
}