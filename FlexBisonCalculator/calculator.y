/* Define c headers. Need to iniclude yylex and yyerror or it throws a fit! */
%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(char*);
%}

/* These are the valid tokens in the language */
%token INTEGER PLUS MINUS MULTIPLY DIVIDE LPAREN RPAREN EOL ERROR

/* Define these tokens as left associative */
%left PLUS MINUS
%left MULTIPLY DIVIDE
%left UMINUS

%%
input:
    | input line
    ;

line:
    EOL
    | exp EOL { printf("= %d\n", $1); }
    | error EOL { yyerrok; }
    ;

exp:
    INTEGER { $$ = $1; }
    | exp PLUS exp { $$ = $1 + $3; }
    | exp MINUS exp { $$ = $1 - $3; }
    | exp MULTIPLY exp { $$ = $1 * $3; }
    | exp DIVIDE exp {
            if($3 == 0) {
                yyerror("Division by 0");
                YYABORT;
            }
            $$ = $1 / $3;
        }
    | LPAREN exp RPAREN { $$ = $2; }
    | MINUS exp %prec UMINUS { $$ = -$2; }
    ;
%%

// This prints errors as they are generated for example in DIVIDE
void yyerror(char* s)
{
    fprintf(stderr, "Error: %s\n", s);
}

// Main guy
int main()
{
    printf("Enter expression or exit\n");
    yyparse();
    return 0;
}