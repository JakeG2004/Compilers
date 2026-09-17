/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "parser.y"

#include <stdio.h>
#include <stdlib.h>

#include "errorhandler.h"
#include "tokenizer.h"
#include "treenode.h"

#define LEAF(t) (new TreeNode(t))

int yylex(void);
void yyerror(const char*);

extern int yylineno;

TreeNode* root = nullptr;

#line 89 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y"

#include "treenode.h"
#include "tokenclass.h"

#line 126 "parser.tab.c"

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
#line 24 "parser.y"

    int NUMBER;
    TreeNode* node;
    TokenClass* tokenData;

#line 204 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NUMCONST = 4,                   /* NUMCONST  */
  YYSYMBOL_CHARCONST = 5,                  /* CHARCONST  */
  YYSYMBOL_STRINGCONST = 6,                /* STRINGCONST  */
  YYSYMBOL_SEMICOLON = 7,                  /* SEMICOLON  */
  YYSYMBOL_STATIC = 8,                     /* STATIC  */
  YYSYMBOL_COMMA = 9,                      /* COMMA  */
  YYSYMBOL_COLON = 10,                     /* COLON  */
  YYSYMBOL_LBRACKET = 11,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 12,                  /* RBRACKET  */
  YYSYMBOL_LPAREN = 13,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 14,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 15,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 16,                    /* RBRACE  */
  YYSYMBOL_ASSIGN = 17,                    /* ASSIGN  */
  YYSYMBOL_ADDASS = 18,                    /* ADDASS  */
  YYSYMBOL_SUBASS = 19,                    /* SUBASS  */
  YYSYMBOL_MULASS = 20,                    /* MULASS  */
  YYSYMBOL_DIVASS = 21,                    /* DIVASS  */
  YYSYMBOL_INC = 22,                       /* INC  */
  YYSYMBOL_DEC = 23,                       /* DEC  */
  YYSYMBOL_LEQ = 24,                       /* LEQ  */
  YYSYMBOL_LT = 25,                        /* LT  */
  YYSYMBOL_GT = 26,                        /* GT  */
  YYSYMBOL_GEQ = 27,                       /* GEQ  */
  YYSYMBOL_EQ = 28,                        /* EQ  */
  YYSYMBOL_NEQ = 29,                       /* NEQ  */
  YYSYMBOL_MIN = 30,                       /* MIN  */
  YYSYMBOL_MAX = 31,                       /* MAX  */
  YYSYMBOL_PLUS = 32,                      /* PLUS  */
  YYSYMBOL_MINUS = 33,                     /* MINUS  */
  YYSYMBOL_STAR = 34,                      /* STAR  */
  YYSYMBOL_DIVIDE = 35,                    /* DIVIDE  */
  YYSYMBOL_MOD = 36,                       /* MOD  */
  YYSYMBOL_QUESTION = 37,                  /* QUESTION  */
  YYSYMBOL_INT = 38,                       /* INT  */
  YYSYMBOL_BOOL = 39,                      /* BOOL  */
  YYSYMBOL_CHAR = 40,                      /* CHAR  */
  YYSYMBOL_IF = 41,                        /* IF  */
  YYSYMBOL_THEN = 42,                      /* THEN  */
  YYSYMBOL_ELSE = 43,                      /* ELSE  */
  YYSYMBOL_WHILE = 44,                     /* WHILE  */
  YYSYMBOL_DO = 45,                        /* DO  */
  YYSYMBOL_FOR = 46,                       /* FOR  */
  YYSYMBOL_RETURN = 47,                    /* RETURN  */
  YYSYMBOL_TO = 48,                        /* TO  */
  YYSYMBOL_BY = 49,                        /* BY  */
  YYSYMBOL_BREAK = 50,                     /* BREAK  */
  YYSYMBOL_OR = 51,                        /* OR  */
  YYSYMBOL_AND = 52,                       /* AND  */
  YYSYMBOL_NOT = 53,                       /* NOT  */
  YYSYMBOL_TRUE = 54,                      /* TRUE  */
  YYSYMBOL_FALSE = 55,                     /* FALSE  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_program = 57,                   /* program  */
  YYSYMBOL_declList = 58,                  /* declList  */
  YYSYMBOL_decl = 59,                      /* decl  */
  YYSYMBOL_varDecl = 60,                   /* varDecl  */
  YYSYMBOL_scopedVarDecl = 61,             /* scopedVarDecl  */
  YYSYMBOL_varDeclList = 62,               /* varDeclList  */
  YYSYMBOL_varDeclInit = 63,               /* varDeclInit  */
  YYSYMBOL_varDeclId = 64,                 /* varDeclId  */
  YYSYMBOL_typeSpec = 65,                  /* typeSpec  */
  YYSYMBOL_funDecl = 66,                   /* funDecl  */
  YYSYMBOL_parms = 67,                     /* parms  */
  YYSYMBOL_parmList = 68,                  /* parmList  */
  YYSYMBOL_parmTypeList = 69,              /* parmTypeList  */
  YYSYMBOL_parmIdList = 70,                /* parmIdList  */
  YYSYMBOL_parmId = 71,                    /* parmId  */
  YYSYMBOL_stmt = 72,                      /* stmt  */
  YYSYMBOL_otherStmts = 73,                /* otherStmts  */
  YYSYMBOL_expStmt = 74,                   /* expStmt  */
  YYSYMBOL_compoundStmt = 75,              /* compoundStmt  */
  YYSYMBOL_localDecls = 76,                /* localDecls  */
  YYSYMBOL_stmtList = 77,                  /* stmtList  */
  YYSYMBOL_selectStmt = 78,                /* selectStmt  */
  YYSYMBOL_matchedStmt = 79,               /* matchedStmt  */
  YYSYMBOL_unmatchedStmt = 80,             /* unmatchedStmt  */
  YYSYMBOL_iterRange = 81,                 /* iterRange  */
  YYSYMBOL_returnStmt = 82,                /* returnStmt  */
  YYSYMBOL_breakStmt = 83,                 /* breakStmt  */
  YYSYMBOL_exp = 84,                       /* exp  */
  YYSYMBOL_simpleExp = 85,                 /* simpleExp  */
  YYSYMBOL_andExp = 86,                    /* andExp  */
  YYSYMBOL_unaryRelExp = 87,               /* unaryRelExp  */
  YYSYMBOL_relExp = 88,                    /* relExp  */
  YYSYMBOL_relop = 89,                     /* relop  */
  YYSYMBOL_minmaxExp = 90,                 /* minmaxExp  */
  YYSYMBOL_minmaxop = 91,                  /* minmaxop  */
  YYSYMBOL_sumExp = 92,                    /* sumExp  */
  YYSYMBOL_sumop = 93,                     /* sumop  */
  YYSYMBOL_mulExp = 94,                    /* mulExp  */
  YYSYMBOL_mulop = 95,                     /* mulop  */
  YYSYMBOL_unaryExp = 96,                  /* unaryExp  */
  YYSYMBOL_unaryop = 97,                   /* unaryop  */
  YYSYMBOL_factor = 98,                    /* factor  */
  YYSYMBOL_mutable = 99,                   /* mutable  */
  YYSYMBOL_immutable = 100,                /* immutable  */
  YYSYMBOL_call = 101,                     /* call  */
  YYSYMBOL_args = 102,                     /* args  */
  YYSYMBOL_argList = 103,                  /* argList  */
  YYSYMBOL_constant = 104                  /* constant  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   328

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  205

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   310


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    35,    35,    39,    40,    44,    45,    49,    53,    54,
      58,    59,    63,    64,    68,    69,    73,    74,    75,    79,
      80,    84,    85,    89,    90,    94,    98,    99,   103,   104,
     108,   112,   113,   114,   115,   119,   120,   124,   128,   129,
     133,   134,   138,   139,   143,   144,   145,   146,   150,   151,
     152,   153,   157,   158,   159,   163,   164,   168,   169,   173,
     174,   175,   176,   177,   178,   179,   180,   184,   185,   189,
     190,   194,   195,   199,   200,   204,   205,   206,   207,   208,
     209,   213,   214,   218,   219,   223,   224,   228,   229,   233,
     234,   238,   239,   240,   244,   245,   249,   250,   251,   255,
     256,   260,   261,   265,   266,   267,   271,   275,   276,   280,
     281,   285,   286,   287,   288,   289
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUMCONST",
  "CHARCONST", "STRINGCONST", "SEMICOLON", "STATIC", "COMMA", "COLON",
  "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "ASSIGN",
  "ADDASS", "SUBASS", "MULASS", "DIVASS", "INC", "DEC", "LEQ", "LT", "GT",
  "GEQ", "EQ", "NEQ", "MIN", "MAX", "PLUS", "MINUS", "STAR", "DIVIDE",
  "MOD", "QUESTION", "INT", "BOOL", "CHAR", "IF", "THEN", "ELSE", "WHILE",
  "DO", "FOR", "RETURN", "TO", "BY", "BREAK", "OR", "AND", "NOT", "TRUE",
  "FALSE", "$accept", "program", "declList", "decl", "varDecl",
  "scopedVarDecl", "varDeclList", "varDeclInit", "varDeclId", "typeSpec",
  "funDecl", "parms", "parmList", "parmTypeList", "parmIdList", "parmId",
  "stmt", "otherStmts", "expStmt", "compoundStmt", "localDecls",
  "stmtList", "selectStmt", "matchedStmt", "unmatchedStmt", "iterRange",
  "returnStmt", "breakStmt", "exp", "simpleExp", "andExp", "unaryRelExp",
  "relExp", "relop", "minmaxExp", "minmaxop", "sumExp", "sumop", "mulExp",
  "mulop", "unaryExp", "unaryop", "factor", "mutable", "immutable", "call",
  "args", "argList", "constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-156)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      54,     4,  -156,  -156,  -156,    28,    54,  -156,  -156,    43,
    -156,    71,  -156,  -156,   105,    75,  -156,    40,    50,    64,
      61,  -156,    84,    71,  -156,    98,    66,    78,    93,  -156,
     200,    71,   100,   111,   126,  -156,   115,  -156,  -156,  -156,
      66,  -156,  -156,  -156,    66,  -156,  -156,    82,    90,  -156,
    -156,   263,    29,    88,  -156,    21,  -156,  -156,  -156,  -156,
    -156,   127,    50,  -156,  -156,   215,    66,   152,   268,   273,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,   149,
      82,   294,  -156,  -156,   200,    66,    66,   143,  -156,    66,
      66,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,    21,
      21,  -156,  -156,    21,  -156,  -156,  -156,    21,  -156,  -156,
    -156,    -2,    66,    66,   155,   116,   -32,   -29,   144,  -156,
     157,  -156,   159,  -156,    66,    66,    66,    66,    66,  -156,
    -156,  -156,   160,  -156,   153,   162,  -156,    90,  -156,    65,
      29,    88,  -156,    71,  -156,    98,   147,   -28,   -12,   158,
      39,   200,   200,    66,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,    66,    98,   122,  -156,  -156,   215,   215,
      66,   215,    66,   166,  -156,  -156,   131,  -156,  -156,   132,
     -16,  -156,   125,  -156,   131,   133,   -21,     0,   165,   215,
     200,    66,  -156,   215,   200,    39,    66,  -156,  -156,  -156,
      89,   138,    66,    39,    82
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    16,    17,    18,     0,     2,     4,     5,     0,
       6,    22,     1,     3,    14,     0,    11,    12,     0,     0,
      21,    24,     0,    22,     7,     0,     0,    28,    25,    27,
       0,     0,     0,     0,    14,    10,   101,   111,   112,   113,
       0,    96,    97,    98,     0,   114,   115,    13,    68,    70,
      72,    74,    82,    86,    90,     0,    95,   100,    99,   104,
     105,     0,     0,    36,    39,     0,     0,     0,     0,     0,
      20,    47,    31,    32,    30,    42,    43,    33,    34,     0,
      66,   100,    23,    15,     0,     0,   108,     0,    71,     0,
       0,    75,    76,    77,    78,    79,    80,    83,    84,     0,
       0,    87,    88,     0,    91,    92,    93,     0,    94,    29,
      26,    41,     0,     0,     0,     0,    66,     0,     0,    55,
       0,    57,     0,    35,     0,     0,     0,     0,     0,    64,
      65,    19,     0,   110,     0,   107,   103,    67,    69,    73,
      81,    85,    89,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    58,    59,    60,    61,    62,
      63,   102,   106,     0,     0,     0,    37,    40,     0,     0,
       0,     0,     0,     0,    49,    48,    42,    45,    50,     0,
      52,   109,     0,     9,     0,     0,    66,     0,     0,     0,
       0,     0,     8,     0,     0,     0,     0,    44,    46,    51,
      53,     0,     0,     0,    54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,  -156,   179,  -156,  -156,  -133,   161,  -156,     2,
    -156,   164,  -156,   167,  -156,   128,   -79,  -156,  -156,  -156,
    -156,  -156,  -150,   -54,  -143,  -155,  -156,  -156,   -20,   -23,
     103,   -31,  -156,  -156,    96,  -156,    99,  -156,    86,  -156,
     -51,  -156,  -156,   -26,  -156,  -156,  -156,  -156,  -156
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,   144,    15,    16,    17,    18,
      10,    19,    20,    21,    28,    29,    70,    71,    72,    73,
     111,   146,    74,    75,    76,   179,    77,    78,    79,    80,
      48,    49,    50,    99,    51,   100,    52,   103,    53,   107,
      54,    55,    56,    81,    58,    59,   134,   135,    60
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,   175,     9,    47,   108,   131,   143,   174,     9,   178,
     151,   115,   165,    88,   168,   185,   152,    11,    57,    89,
      87,   194,    89,    89,    36,    37,    38,    39,    12,    57,
      89,   182,   191,   169,    40,    89,     2,     3,     4,    89,
      57,   201,   116,   117,   175,   195,    14,   199,   120,   122,
      26,    89,   178,    27,    41,    42,   142,     1,    43,   138,
     199,   101,   102,    57,    57,   132,   133,   167,    31,    36,
      37,    38,    39,    57,    57,    45,    46,    57,    30,    40,
     171,    57,    24,   172,    25,   173,    57,    57,    32,   147,
     148,    61,     2,     3,     4,    97,    98,   176,   177,    41,
      42,    34,    62,    43,   156,   157,   158,   159,   160,     2,
       3,     4,    83,   145,   184,   177,    22,   115,    23,    44,
      45,    46,   104,   105,   106,    84,    85,    57,    86,   183,
     180,    25,   192,    89,    25,   197,   198,    22,   202,   198,
      89,   109,    90,   181,    57,   164,    57,   180,   186,   187,
      36,    37,    38,    39,    63,   118,   123,   136,   149,   150,
      40,   153,    64,   166,   154,    57,   155,   162,   200,   188,
      57,   163,   161,   180,   189,   170,    57,   190,   193,   204,
      41,    42,   196,   203,    43,    13,    35,    33,    65,   141,
     110,    66,   137,    67,    68,   139,     0,    69,    82,   140,
      44,    45,    46,    36,    37,    38,    39,    63,     0,     0,
       0,     0,     0,    40,     0,    64,     0,     0,    36,    37,
      38,    39,    63,     0,     0,     0,     0,     0,    40,     0,
      64,     0,     0,    41,    42,     0,     0,    43,     0,     0,
       0,    65,     0,     0,    66,     0,    67,    68,    41,    42,
      69,     0,    43,    44,    45,    46,   112,     0,     0,   113,
       0,   114,    68,     0,     0,    69,     0,     0,    44,    45,
      46,    36,    37,    38,    39,   119,    36,    37,    38,    39,
     121,    40,     0,     0,     0,     0,    40,    91,    92,    93,
      94,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,    41,    42,     0,     0,    43,    41,    42,     0,     0,
      43,   124,   125,   126,   127,   128,   129,   130,     0,     0,
       0,    44,    45,    46,     0,     0,    44,    45,    46
};

static const yytype_int16 yycheck[] =
{
      26,   151,     0,    26,    55,    84,     8,   150,     6,   152,
      42,    65,   145,    44,    42,   170,    45,    13,    44,    51,
      40,    42,    51,    51,     3,     4,     5,     6,     0,    55,
      51,   164,    48,    45,    13,    51,    38,    39,    40,    51,
      66,   196,    65,    66,   194,    45,     3,   190,    68,    69,
      10,    51,   195,     3,    33,    34,   107,     3,    37,    90,
     203,    32,    33,    89,    90,    85,    86,   146,     7,     3,
       4,     5,     6,    99,   100,    54,    55,   103,    14,    13,
      41,   107,     7,    44,     9,    46,   112,   113,     4,   112,
     113,    13,    38,    39,    40,    30,    31,   151,   152,    33,
      34,     3,     9,    37,   124,   125,   126,   127,   128,    38,
      39,    40,    12,   111,   168,   169,    11,   171,    13,    53,
      54,    55,    34,    35,    36,    14,    11,   153,    13,     7,
     153,     9,     7,    51,     9,   189,   190,    11,    49,   193,
      51,    14,    52,   163,   170,   143,   172,   170,   171,   172,
       3,     4,     5,     6,     7,     3,     7,    14,     3,    43,
      13,    17,    15,    16,     7,   191,     7,    14,   191,     3,
     196,     9,    12,   196,    43,    17,   202,    45,    45,   202,
      33,    34,    17,    45,    37,     6,    25,    23,    41,   103,
      62,    44,    89,    46,    47,    99,    -1,    50,    31,   100,
      53,    54,    55,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    15,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      15,    -1,    -1,    33,    34,    -1,    -1,    37,    -1,    -1,
      -1,    41,    -1,    -1,    44,    -1,    46,    47,    33,    34,
      50,    -1,    37,    53,    54,    55,    41,    -1,    -1,    44,
      -1,    46,    47,    -1,    -1,    50,    -1,    -1,    53,    54,
      55,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,    13,    -1,    -1,    -1,    -1,    13,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    -1,    37,    33,    34,    -1,    -1,
      37,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    53,    54,    55,    -1,    -1,    53,    54,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    38,    39,    40,    57,    58,    59,    60,    65,
      66,    13,     0,    59,     3,    62,    63,    64,    65,    67,
      68,    69,    11,    13,     7,     9,    10,     3,    70,    71,
      14,     7,     4,    67,     3,    63,     3,     4,     5,     6,
      13,    33,    34,    37,    53,    54,    55,    85,    86,    87,
      88,    90,    92,    94,    96,    97,    98,    99,   100,   101,
     104,    13,     9,     7,    15,    41,    44,    46,    47,    50,
      72,    73,    74,    75,    78,    79,    80,    82,    83,    84,
      85,    99,    69,    12,    14,    11,    13,    84,    87,    51,
      52,    24,    25,    26,    27,    28,    29,    30,    31,    89,
      91,    32,    33,    93,    34,    35,    36,    95,    96,    14,
      71,    76,    41,    44,    46,    79,    85,    85,     3,     7,
      84,     7,    84,     7,    17,    18,    19,    20,    21,    22,
      23,    72,    84,    84,   102,   103,    14,    86,    87,    90,
      92,    94,    96,     8,    61,    65,    77,    85,    85,     3,
      43,    42,    45,    17,     7,     7,    84,    84,    84,    84,
      84,    12,    14,     9,    65,    62,    16,    72,    42,    45,
      17,    41,    44,    46,    80,    78,    79,    79,    80,    81,
      85,    84,    62,     7,    79,    81,    85,    85,     3,    43,
      45,    48,     7,    45,    42,    45,    17,    79,    79,    80,
      85,    81,    49,    45,    85
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    70,    70,    71,    71,
      72,    73,    73,    73,    73,    74,    74,    75,    76,    76,
      77,    77,    78,    78,    79,    79,    79,    79,    80,    80,
      80,    80,    81,    81,    81,    82,    82,    83,    83,    84,
      84,    84,    84,    84,    84,    84,    84,    85,    85,    86,
      86,    87,    87,    88,    88,    89,    89,    89,    89,    89,
      89,    90,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    95,    95,    95,    96,    96,    97,    97,    97,    98,
      98,    99,    99,   100,   100,   100,   101,   102,   102,   103,
     103,   104,   104,   104,   104,   104
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     4,     3,
       3,     1,     1,     3,     1,     4,     1,     1,     1,     6,
       5,     1,     0,     3,     1,     2,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     2,     1,     4,     2,     0,
       2,     0,     1,     1,     6,     4,     6,     1,     4,     4,
       4,     6,     1,     3,     5,     2,     3,     2,     3,     3,
       3,     3,     3,     3,     2,     2,     1,     3,     1,     3,
       1,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     1,     1,     4,     1,     0,     3,
       1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declList  */
#line 35 "parser.y"
                {root = (yyvsp[0].node);}
#line 1458 "parser.tab.c"
    break;

  case 3: /* declList: declList decl  */
#line 39 "parser.y"
                    {(yyval.node) = new TreeNode((yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr);}
#line 1464 "parser.tab.c"
    break;

  case 4: /* declList: decl  */
#line 40 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1470 "parser.tab.c"
    break;

  case 5: /* decl: varDecl  */
#line 44 "parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 1476 "parser.tab.c"
    break;

  case 6: /* decl: funDecl  */
#line 45 "parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 1482 "parser.tab.c"
    break;

  case 7: /* varDecl: typeSpec varDeclList SEMICOLON  */
#line 49 "parser.y"
                                    {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[-1].node), nullptr, nullptr);}
#line 1488 "parser.tab.c"
    break;

  case 8: /* scopedVarDecl: STATIC typeSpec varDeclList SEMICOLON  */
#line 53 "parser.y"
                                            {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[-1].node), nullptr, (yyvsp[-3].tokenData));}
#line 1494 "parser.tab.c"
    break;

  case 9: /* scopedVarDecl: typeSpec varDeclList SEMICOLON  */
#line 54 "parser.y"
                                            {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[-1].node), nullptr, nullptr);}
#line 1500 "parser.tab.c"
    break;

  case 10: /* varDeclList: varDeclList COMMA varDeclInit  */
#line 58 "parser.y"
                                    {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-1].tokenData));}
#line 1506 "parser.tab.c"
    break;

  case 11: /* varDeclList: varDeclInit  */
#line 59 "parser.y"
                                    {(yyval.node) = (yyvsp[0].node);}
#line 1512 "parser.tab.c"
    break;

  case 12: /* varDeclInit: varDeclId  */
#line 63 "parser.y"
                                {(yyval.node) = (yyvsp[0].node);}
#line 1518 "parser.tab.c"
    break;

  case 13: /* varDeclInit: varDeclId COLON simpleExp  */
#line 64 "parser.y"
                                {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-1].tokenData));}
#line 1524 "parser.tab.c"
    break;

  case 14: /* varDeclId: ID  */
#line 68 "parser.y"
                                    {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 1530 "parser.tab.c"
    break;

  case 15: /* varDeclId: ID LBRACKET NUMCONST RBRACKET  */
#line 69 "parser.y"
                                    {(yyval.node) = new TreeNode(LEAF((yyvsp[-1].tokenData)), nullptr, nullptr, (yyvsp[-3].tokenData));}
#line 1536 "parser.tab.c"
    break;

  case 16: /* typeSpec: INT  */
#line 73 "parser.y"
            {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 1542 "parser.tab.c"
    break;

  case 17: /* typeSpec: BOOL  */
#line 74 "parser.y"
            {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 1548 "parser.tab.c"
    break;

  case 18: /* typeSpec: CHAR  */
#line 75 "parser.y"
            {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 1554 "parser.tab.c"
    break;

  case 19: /* funDecl: typeSpec ID LPAREN parms RPAREN stmt  */
#line 79 "parser.y"
                                            {(yyval.node) = new TreeNode((yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-4].tokenData));}
#line 1560 "parser.tab.c"
    break;

  case 20: /* funDecl: ID LPAREN parms RPAREN stmt  */
#line 80 "parser.y"
                                            {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-4].tokenData));}
#line 1566 "parser.tab.c"
    break;

  case 21: /* parms: parmList  */
#line 84 "parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 1572 "parser.tab.c"
    break;

  case 22: /* parms: %empty  */
#line 85 "parser.y"
                {(yyval.node) = nullptr;}
#line 1578 "parser.tab.c"
    break;

  case 23: /* parmList: parmList SEMICOLON parmTypeList  */
#line 89 "parser.y"
                                    {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-1].tokenData));}
#line 1584 "parser.tab.c"
    break;

  case 24: /* parmList: parmTypeList  */
#line 90 "parser.y"
                                    {(yyval.node) = (yyvsp[0].node);}
#line 1590 "parser.tab.c"
    break;

  case 25: /* parmTypeList: typeSpec parmIdList  */
#line 94 "parser.y"
                        {(yyval.node) = new TreeNode((yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr);}
#line 1596 "parser.tab.c"
    break;

  case 26: /* parmIdList: parmIdList COMMA parmId  */
#line 98 "parser.y"
                            {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-1].tokenData));}
#line 1602 "parser.tab.c"
    break;

  case 27: /* parmIdList: parmId  */
#line 99 "parser.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 1608 "parser.tab.c"
    break;

  case 28: /* parmId: ID  */
#line 103 "parser.y"
                        {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 1614 "parser.tab.c"
    break;

  case 29: /* parmId: ID LPAREN RPAREN  */
#line 104 "parser.y"
                        {(yyval.node) = new TreeNode((yyvsp[-2].tokenData));}
#line 1620 "parser.tab.c"
    break;

  case 30: /* stmt: selectStmt  */
#line 108 "parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 1626 "parser.tab.c"
    break;

  case 31: /* otherStmts: expStmt  */
#line 112 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1632 "parser.tab.c"
    break;

  case 32: /* otherStmts: compoundStmt  */
#line 113 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1638 "parser.tab.c"
    break;

  case 33: /* otherStmts: returnStmt  */
#line 114 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1644 "parser.tab.c"
    break;

  case 34: /* otherStmts: breakStmt  */
#line 115 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1650 "parser.tab.c"
    break;

  case 35: /* expStmt: exp SEMICOLON  */
#line 119 "parser.y"
                    {(yyval.node) = new TreeNode((yyvsp[-1].node), nullptr, nullptr, nullptr);}
#line 1656 "parser.tab.c"
    break;

  case 36: /* expStmt: SEMICOLON  */
#line 120 "parser.y"
                    {(yyval.node) = nullptr;}
#line 1662 "parser.tab.c"
    break;

  case 37: /* compoundStmt: LBRACE localDecls stmtList RBRACE  */
#line 124 "parser.y"
                                        {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[-1].node), nullptr, nullptr);}
#line 1668 "parser.tab.c"
    break;

  case 38: /* localDecls: localDecls scopedVarDecl  */
#line 128 "parser.y"
                                {(yyval.node) = new TreeNode((yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr);}
#line 1674 "parser.tab.c"
    break;

  case 39: /* localDecls: %empty  */
#line 129 "parser.y"
                                {(yyval.node) = nullptr;}
#line 1680 "parser.tab.c"
    break;

  case 40: /* stmtList: stmtList stmt  */
#line 133 "parser.y"
                    {(yyval.node) = new TreeNode((yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr);}
#line 1686 "parser.tab.c"
    break;

  case 41: /* stmtList: %empty  */
#line 134 "parser.y"
                    {(yyval.node) = nullptr;}
#line 1692 "parser.tab.c"
    break;

  case 42: /* selectStmt: matchedStmt  */
#line 138 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1698 "parser.tab.c"
    break;

  case 43: /* selectStmt: unmatchedStmt  */
#line 139 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1704 "parser.tab.c"
    break;

  case 44: /* matchedStmt: IF simpleExp THEN matchedStmt ELSE matchedStmt  */
#line 143 "parser.y"
                                                    {(yyval.node) = new TreeNode((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-5].tokenData));}
#line 1710 "parser.tab.c"
    break;

  case 45: /* matchedStmt: WHILE simpleExp DO matchedStmt  */
#line 144 "parser.y"
                                                    {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-3].tokenData));}
#line 1716 "parser.tab.c"
    break;

  case 46: /* matchedStmt: FOR ID ASSIGN iterRange DO matchedStmt  */
#line 145 "parser.y"
                                                    {(yyval.node) = new TreeNode(LEAF((yyvsp[-4].tokenData)), (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-5].tokenData));}
#line 1722 "parser.tab.c"
    break;

  case 47: /* matchedStmt: otherStmts  */
#line 146 "parser.y"
                                                    {(yyval.node) = (yyvsp[0].node);}
#line 1728 "parser.tab.c"
    break;

  case 48: /* unmatchedStmt: IF simpleExp THEN selectStmt  */
#line 150 "parser.y"
                                                {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-3].tokenData));}
#line 1734 "parser.tab.c"
    break;

  case 49: /* unmatchedStmt: IF matchedStmt ELSE unmatchedStmt  */
#line 151 "parser.y"
                                                {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-3].tokenData));}
#line 1740 "parser.tab.c"
    break;

  case 50: /* unmatchedStmt: WHILE simpleExp DO unmatchedStmt  */
#line 152 "parser.y"
                                                {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-3].tokenData));}
#line 1746 "parser.tab.c"
    break;

  case 51: /* unmatchedStmt: FOR ID ASSIGN iterRange DO unmatchedStmt  */
#line 153 "parser.y"
                                                {(yyval.node) = new TreeNode(LEAF((yyvsp[-4].tokenData)), (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-5].tokenData));}
#line 1752 "parser.tab.c"
    break;

  case 52: /* iterRange: simpleExp  */
#line 157 "parser.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 1758 "parser.tab.c"
    break;

  case 53: /* iterRange: simpleExp TO simpleExp  */
#line 158 "parser.y"
                                            {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-1].tokenData));}
#line 1764 "parser.tab.c"
    break;

  case 54: /* iterRange: simpleExp TO simpleExp BY simpleExp  */
#line 159 "parser.y"
                                            {(yyval.node) = new TreeNode((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-3].tokenData));}
#line 1770 "parser.tab.c"
    break;

  case 55: /* returnStmt: RETURN SEMICOLON  */
#line 163 "parser.y"
                            {(yyval.node) = new TreeNode((yyvsp[-1].tokenData));}
#line 1776 "parser.tab.c"
    break;

  case 56: /* returnStmt: RETURN exp SEMICOLON  */
#line 164 "parser.y"
                            {(yyval.node) = new TreeNode((yyvsp[-1].node), nullptr, nullptr, (yyvsp[-2].tokenData));}
#line 1782 "parser.tab.c"
    break;

  case 57: /* breakStmt: BREAK SEMICOLON  */
#line 168 "parser.y"
                            {(yyval.node) = new TreeNode((yyvsp[-1].tokenData));}
#line 1788 "parser.tab.c"
    break;

  case 58: /* breakStmt: BREAK exp SEMICOLON  */
#line 169 "parser.y"
                            {(yyval.node) = new TreeNode((yyvsp[-1].node), nullptr, nullptr, (yyvsp[-2].tokenData));}
#line 1794 "parser.tab.c"
    break;

  case 59: /* exp: mutable ASSIGN exp  */
#line 173 "parser.y"
                            {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-1].tokenData));}
#line 1800 "parser.tab.c"
    break;

  case 60: /* exp: mutable ADDASS exp  */
#line 174 "parser.y"
                            {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-1].tokenData));}
#line 1806 "parser.tab.c"
    break;

  case 61: /* exp: mutable SUBASS exp  */
#line 175 "parser.y"
                            {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-1].tokenData));}
#line 1812 "parser.tab.c"
    break;

  case 62: /* exp: mutable MULASS exp  */
#line 176 "parser.y"
                            {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-1].tokenData));}
#line 1818 "parser.tab.c"
    break;

  case 63: /* exp: mutable DIVASS exp  */
#line 177 "parser.y"
                            {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-1].tokenData));}
#line 1824 "parser.tab.c"
    break;

  case 64: /* exp: mutable INC  */
#line 178 "parser.y"
                            {(yyval.node) = new TreeNode((yyvsp[-1].node), nullptr, nullptr, (yyvsp[0].tokenData));}
#line 1830 "parser.tab.c"
    break;

  case 65: /* exp: mutable DEC  */
#line 179 "parser.y"
                            {(yyval.node) = new TreeNode((yyvsp[-1].node), nullptr, nullptr, (yyvsp[0].tokenData));}
#line 1836 "parser.tab.c"
    break;

  case 66: /* exp: simpleExp  */
#line 180 "parser.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 1842 "parser.tab.c"
    break;

  case 67: /* simpleExp: simpleExp OR andExp  */
#line 184 "parser.y"
                        {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-1].tokenData));}
#line 1848 "parser.tab.c"
    break;

  case 68: /* simpleExp: andExp  */
#line 185 "parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1854 "parser.tab.c"
    break;

  case 69: /* andExp: andExp AND unaryRelExp  */
#line 189 "parser.y"
                            {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-1].tokenData));}
#line 1860 "parser.tab.c"
    break;

  case 70: /* andExp: unaryRelExp  */
#line 190 "parser.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 1866 "parser.tab.c"
    break;

  case 71: /* unaryRelExp: NOT unaryRelExp  */
#line 194 "parser.y"
                    {(yyval.node) = new TreeNode((yyvsp[0].node), nullptr, nullptr, (yyvsp[-1].tokenData));}
#line 1872 "parser.tab.c"
    break;

  case 72: /* unaryRelExp: relExp  */
#line 195 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1878 "parser.tab.c"
    break;

  case 73: /* relExp: minmaxExp relop minmaxExp  */
#line 199 "parser.y"
                                {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), nullptr);}
#line 1884 "parser.tab.c"
    break;

  case 74: /* relExp: minmaxExp  */
#line 200 "parser.y"
                                {(yyval.node) = (yyvsp[0].node);}
#line 1890 "parser.tab.c"
    break;

  case 75: /* relop: LEQ  */
#line 204 "parser.y"
            {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 1896 "parser.tab.c"
    break;

  case 76: /* relop: LT  */
#line 205 "parser.y"
            {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 1902 "parser.tab.c"
    break;

  case 77: /* relop: GT  */
#line 206 "parser.y"
            {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 1908 "parser.tab.c"
    break;

  case 78: /* relop: GEQ  */
#line 207 "parser.y"
            {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 1914 "parser.tab.c"
    break;

  case 79: /* relop: EQ  */
#line 208 "parser.y"
            {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 1920 "parser.tab.c"
    break;

  case 80: /* relop: NEQ  */
#line 209 "parser.y"
            {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 1926 "parser.tab.c"
    break;

  case 81: /* minmaxExp: minmaxExp minmaxop sumExp  */
#line 213 "parser.y"
                                {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), nullptr);}
#line 1932 "parser.tab.c"
    break;

  case 82: /* minmaxExp: sumExp  */
#line 214 "parser.y"
                                {(yyval.node) = (yyvsp[0].node);}
#line 1938 "parser.tab.c"
    break;

  case 83: /* minmaxop: MIN  */
#line 218 "parser.y"
            {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 1944 "parser.tab.c"
    break;

  case 84: /* minmaxop: MAX  */
#line 219 "parser.y"
            {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 1950 "parser.tab.c"
    break;

  case 85: /* sumExp: sumExp sumop mulExp  */
#line 223 "parser.y"
                        {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), nullptr);}
#line 1956 "parser.tab.c"
    break;

  case 86: /* sumExp: mulExp  */
#line 224 "parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1962 "parser.tab.c"
    break;

  case 87: /* sumop: PLUS  */
#line 228 "parser.y"
            {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 1968 "parser.tab.c"
    break;

  case 88: /* sumop: MINUS  */
#line 229 "parser.y"
            {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 1974 "parser.tab.c"
    break;

  case 89: /* mulExp: mulExp mulop unaryExp  */
#line 233 "parser.y"
                            {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), nullptr);}
#line 1980 "parser.tab.c"
    break;

  case 90: /* mulExp: unaryExp  */
#line 234 "parser.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 1986 "parser.tab.c"
    break;

  case 91: /* mulop: STAR  */
#line 238 "parser.y"
                {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 1992 "parser.tab.c"
    break;

  case 92: /* mulop: DIVIDE  */
#line 239 "parser.y"
                {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 1998 "parser.tab.c"
    break;

  case 93: /* mulop: MOD  */
#line 240 "parser.y"
                {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 2004 "parser.tab.c"
    break;

  case 94: /* unaryExp: unaryop unaryExp  */
#line 244 "parser.y"
                        {(yyval.node) = new TreeNode((yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr);}
#line 2010 "parser.tab.c"
    break;

  case 95: /* unaryExp: factor  */
#line 245 "parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2016 "parser.tab.c"
    break;

  case 96: /* unaryop: MINUS  */
#line 249 "parser.y"
                {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 2022 "parser.tab.c"
    break;

  case 97: /* unaryop: STAR  */
#line 250 "parser.y"
                {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 2028 "parser.tab.c"
    break;

  case 98: /* unaryop: QUESTION  */
#line 251 "parser.y"
                {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 2034 "parser.tab.c"
    break;

  case 99: /* factor: immutable  */
#line 255 "parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 2040 "parser.tab.c"
    break;

  case 100: /* factor: mutable  */
#line 256 "parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 2046 "parser.tab.c"
    break;

  case 101: /* mutable: ID  */
#line 260 "parser.y"
                                {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 2052 "parser.tab.c"
    break;

  case 102: /* mutable: ID LBRACKET exp RBRACKET  */
#line 261 "parser.y"
                                {(yyval.node) = new TreeNode((yyvsp[-1].node), nullptr, nullptr, (yyvsp[-3].tokenData));}
#line 2058 "parser.tab.c"
    break;

  case 103: /* immutable: LPAREN exp RPAREN  */
#line 265 "parser.y"
                        {(yyval.node) = (yyvsp[-1].node);}
#line 2064 "parser.tab.c"
    break;

  case 104: /* immutable: call  */
#line 266 "parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2070 "parser.tab.c"
    break;

  case 105: /* immutable: constant  */
#line 267 "parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2076 "parser.tab.c"
    break;

  case 106: /* call: ID LPAREN args RPAREN  */
#line 271 "parser.y"
                            {(yyval.node) = new TreeNode((yyvsp[-1].node), nullptr, nullptr, (yyvsp[-3].tokenData));}
#line 2082 "parser.tab.c"
    break;

  case 107: /* args: argList  */
#line 275 "parser.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 2088 "parser.tab.c"
    break;

  case 108: /* args: %empty  */
#line 276 "parser.y"
            {(yyval.node) = nullptr;}
#line 2094 "parser.tab.c"
    break;

  case 109: /* argList: argList COMMA exp  */
#line 280 "parser.y"
                        {(yyval.node) = new TreeNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-1].tokenData));}
#line 2100 "parser.tab.c"
    break;

  case 110: /* argList: exp  */
#line 281 "parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2106 "parser.tab.c"
    break;

  case 111: /* constant: NUMCONST  */
#line 285 "parser.y"
                    {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 2112 "parser.tab.c"
    break;

  case 112: /* constant: CHARCONST  */
#line 286 "parser.y"
                    {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 2118 "parser.tab.c"
    break;

  case 113: /* constant: STRINGCONST  */
#line 287 "parser.y"
                    {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 2124 "parser.tab.c"
    break;

  case 114: /* constant: TRUE  */
#line 288 "parser.y"
                    {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 2130 "parser.tab.c"
    break;

  case 115: /* constant: FALSE  */
#line 289 "parser.y"
                    {(yyval.node) = new TreeNode((yyvsp[0].tokenData));}
#line 2136 "parser.tab.c"
    break;


#line 2140 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 292 "parser.y"


void yyerror(const char* s)
{
    //ErrorHandler::AddError(Error::ErrorType::PARSER, s, yylineno);
}

int main()
{
    yyparse();

    //root->Print();
    return 0;
}
