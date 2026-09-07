%{
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "errorhandler.h"
#include "tokenizer.h"

int yylex(void);
void yyerror(const char*);

extern FILE* yyin;
extern int yydebug;

extern int yylineno;
%}

%token ID NUMCONST CHARCONST STRINGCONST BOOLCONST SEMICOLON STATIC COMMA COLON LBRACKET RBRACKET LPAREN RPAREN LBRACE RBRACE ASSIGN ADDASS SUBASS MULASS DIVASS INC DEC LEQ LT GT GEQ EQ NEQ MIN MAX PLUS MINUS STAR DIVIDE MOD QUESTION INT BOOL CHAR IF ELSE WHILE FOR RETURN BREAK IN EXCLAMATION PIPE AMPERSAND

%%
tokenlist:
    tokenlist token
    | token
    ;

token:
      ID
    | NUMCONST
    | CHARCONST
    | STRINGCONST
    | BOOLCONST
    | SEMICOLON
    | COMMA
    | COLON
    | LBRACKET
    | RBRACKET
    | LPAREN
    | RPAREN
    | LBRACE
    | RBRACE
    | ASSIGN
    | ADDASS
    | SUBASS
    | MULASS
    | DIVASS
    | INC
    | DEC
    | LEQ
    | LT
    | GT
    | GEQ
    | EQ
    | NEQ
    | MIN
    | MAX
    | PLUS
    | MINUS
    | STAR
    | DIVIDE
    | MOD
    | QUESTION
    | INT
    | BOOL
    | CHAR
    | IF
    | ELSE
    | WHILE
    | FOR
    | RETURN
    | BREAK
    | IN
    | STATIC
    | EXCLAMATION
    | PIPE
    | AMPERSAND
    ;
%%

void yyerror(const char* s)
{
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
    return 0;
}