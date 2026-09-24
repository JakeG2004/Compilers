/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BUILD_PARSER_TAB_H_INCLUDED
# define YY_YY_BUILD_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "Parser/parser.y"

#include "treenode.h"
#include "tokenclass.h"

#line 54 "build/parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    NUMCONST = 259,                /* NUMCONST  */
    CHARCONST = 260,               /* CHARCONST  */
    STRINGCONST = 261,             /* STRINGCONST  */
    SEMICOLON = 262,               /* SEMICOLON  */
    STATIC = 263,                  /* STATIC  */
    COMMA = 264,                   /* COMMA  */
    COLON = 265,                   /* COLON  */
    LBRACKET = 266,                /* LBRACKET  */
    RBRACKET = 267,                /* RBRACKET  */
    LPAREN = 268,                  /* LPAREN  */
    RPAREN = 269,                  /* RPAREN  */
    LBRACE = 270,                  /* LBRACE  */
    RBRACE = 271,                  /* RBRACE  */
    ASSIGN = 272,                  /* ASSIGN  */
    ADDASS = 273,                  /* ADDASS  */
    SUBASS = 274,                  /* SUBASS  */
    MULASS = 275,                  /* MULASS  */
    DIVASS = 276,                  /* DIVASS  */
    INC = 277,                     /* INC  */
    DEC = 278,                     /* DEC  */
    LEQ = 279,                     /* LEQ  */
    LT = 280,                      /* LT  */
    GT = 281,                      /* GT  */
    GEQ = 282,                     /* GEQ  */
    EQ = 283,                      /* EQ  */
    NEQ = 284,                     /* NEQ  */
    MIN = 285,                     /* MIN  */
    MAX = 286,                     /* MAX  */
    PLUS = 287,                    /* PLUS  */
    MINUS = 288,                   /* MINUS  */
    STAR = 289,                    /* STAR  */
    DIVIDE = 290,                  /* DIVIDE  */
    MOD = 291,                     /* MOD  */
    QUESTION = 292,                /* QUESTION  */
    INT = 293,                     /* INT  */
    BOOL = 294,                    /* BOOL  */
    CHAR = 295,                    /* CHAR  */
    IF = 296,                      /* IF  */
    THEN = 297,                    /* THEN  */
    ELSE = 298,                    /* ELSE  */
    WHILE = 299,                   /* WHILE  */
    DO = 300,                      /* DO  */
    FOR = 301,                     /* FOR  */
    RETURN = 302,                  /* RETURN  */
    TO = 303,                      /* TO  */
    BY = 304,                      /* BY  */
    BREAK = 305,                   /* BREAK  */
    OR = 306,                      /* OR  */
    AND = 307,                     /* AND  */
    NOT = 308,                     /* NOT  */
    TRUE = 309,                    /* TRUE  */
    FALSE = 310                    /* FALSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "Parser/parser.y"

    int NUMBER;
    TreeNode* node;
    TokenClass* tokenData;

#line 132 "build/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_PARSER_TAB_H_INCLUDED  */
