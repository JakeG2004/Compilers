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

%token ID NUMCONST CHARCONST STRINGCONST BOOLCONST SEMICOLON STATIC COMMA COLON LBRACKET RBRACKET LPAREN RPAREN LBRACE RBRACE ASSIGN ADDASS SUBASS MULASS DIVASS INC DEC LEQ LT GT GEQ EQ NEQ MIN MAX PLUS MINUS STAR DIVIDE MOD QUESTION INT BOOL CHAR IF ELSE WHILE FOR RETURN BREAK THEN AND OR NOT DO TO BY

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
    | STATIC
    | THEN
    | AND
    | OR
    | NOT
    | DO
    | TO
    | BY
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
    } else {
        yyin = stdin;
    }

    FILE* temp = tmpfile();
    if (!temp) {
        perror("tmpfile");
        if (argc == 2) fclose(yyin);
        return 1;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), yyin)) > 0) {
        fwrite(buffer, 1, bytes, stdout);
        fwrite(buffer, 1, bytes, temp);
    }

    if (argc == 2) {
        fclose(yyin);
    }

    rewind(temp);
    yyin = temp;

    fclose(temp);

    return 0;
}