/* Define c headers. Need to iniclude yylex and yyerror or it throws a fit! */
%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char*);

extern int yylineno;
%}

/* These are the valid tokens in the language */
%token SEMICOLON IF THEN ELSE END REPEAT UNTIL ASSIGN READ WRITE LESS_THAN EQUAL PLUS MINUS MULTIPLY DIVIDE LPAREN RPAREN NUM ID

/* Define these tokens as left associative */
%left PLUS MINUS
%left MULTIPLY DIVIDE

%%
program:
    stmt-seq
    ;

stmt-seq:
    stmt-seq SEMICOLON stmt
    | stmt
    ;

stmt:
    if-stmt
    | repeat-stmt
    | assign-stmt
    | read-stmt
    | write-stmt
    ;

if-stmt:
    IF exp THEN stmt-seq END
    | IF exp THEN stmt-seq ELSE stmt-seq END
    ;

repeat-stmt:
    REPEAT stmt-seq UNTIL exp
    ;

assign-stmt:
    ID ASSIGN exp
    ;

read-stmt:
    READ ID
    ;

write-stmt:
    WRITE exp
    ;

exp:
    simple-exp LESS_THAN simple-exp
    | simple-exp EQUAL simple-exp
    | simple-exp
    ;

simple-exp:
    simple-exp PLUS term
    | simple-exp MINUS term
    | term
    ;

term:
    term MULTIPLY factor
    | term DIVIDE factor { if($3 == 0) {yyerror("Divide by zero"); YYABORT;} }
    | factor
    ;

factor:
    LPAREN exp RPAREN
    | NUM { $$ = $1; }
    | ID { $$ = $1; }
    ;

%%

// This prints errors as they are generated for example in DIVIDE
void yyerror(const char* s)
{
    fprintf(stderr, "Error on line %i: %s\n", yylineno, s);
}

// Main guy
int main()
{
    printf("Enter expression or exit\n");
    yyparse();
    return 0;
}