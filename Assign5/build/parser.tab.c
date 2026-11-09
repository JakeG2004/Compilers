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
#line 9 "Parser/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "errorhandler.h"
#include "arghandler.h"
#include "treenode.h"
#include "semanticanalyzer.h"

int yylex(void);
void yyerror(const char*);

extern FILE* yyin;
extern int yydebug;
extern int yylineno;

TreeNode* ASTRoot = nullptr;

#line 91 "build/parser.tab.c"

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

#include "parser.tab.h"
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   446

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

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
       0,    42,    42,    46,    47,    51,    52,    53,    57,    61,
      62,    63,    67,    68,    72,    73,    77,    78,    79,    83,
      84,    85,    89,    90,    91,    95,    96,   100,   101,   102,
     106,   110,   111,   115,   116,   117,   121,   125,   126,   127,
     128,   132,   133,   134,   138,   142,   143,   147,   148,   152,
     153,   154,   155,   156,   160,   161,   162,   163,   167,   168,
     169,   170,   174,   175,   179,   180,   184,   185,   189,   190,
     191,   192,   193,   194,   195,   196,   200,   201,   205,   206,
     210,   211,   215,   216,   220,   221,   222,   223,   224,   225,
     229,   230,   234,   235,   239,   240,   244,   245,   249,   250,
     254,   255,   256,   260,   261,   265,   266,   267,   271,   272,
     273,   277,   278,   279,   283,   284,   285,   289,   293,   294,
     298,   299,   303,   304,   305,   306,   307
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
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

#define YYPACT_NINF (-142)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-120)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,    31,    11,  -142,  -142,  -142,    14,    87,  -142,  -142,
      59,  -142,  -142,   232,   100,  -142,  -142,    15,    78,    93,
    -142,    29,    36,   104,  -142,  -142,  -142,  -142,   313,  -142,
    -142,  -142,  -142,   348,   359,   118,    16,   302,   313,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
      40,     8,    20,  -142,  -142,   150,    43,    72,  -142,   373,
    -142,   414,  -142,  -142,  -142,   116,   121,    80,   129,  -142,
    -142,   138,   100,  -142,   127,   313,   394,  -142,   313,    79,
      44,   133,   154,    21,   -17,  -142,    24,     1,   132,   137,
    -142,   149,  -142,   156,  -142,  -142,   313,   313,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,   373,   373,  -142,  -142,
     373,  -142,  -142,  -142,   373,  -142,   313,   313,   313,   313,
     313,  -142,  -142,  -142,   153,   157,   163,  -142,   232,    71,
     170,   169,   173,  -142,     8,   174,  -142,   171,   180,  -142,
    -142,   183,    71,  -142,   127,   209,  -142,   232,  -142,   287,
    -142,   313,  -142,  -142,    20,  -142,   114,    43,    72,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,   184,   121,  -142,  -142,
    -142,   232,  -142,  -142,   313,  -142,   127,   122,  -142,  -142,
    -142,   159,   313,   313,   194,  -142,  -142,   158,   -38,  -142,
    -142,  -142,  -142,   128,  -142,   287,   287,   313,  -142,  -142,
    -142,  -142,  -142,    92,   313,     8
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    19,    20,    21,     0,     0,     4,     5,
       0,     6,     7,     0,     0,     1,     3,     0,    16,     0,
      13,    14,     0,   111,   122,   123,   124,    42,     0,    46,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   125,
     126,    24,    57,    37,    38,    36,    49,    50,    39,    40,
       0,    75,    77,    79,    81,    83,    91,    95,    99,     0,
     104,   109,   108,   115,   116,     0,     0,     0,    25,    28,
      18,     0,     0,     8,     0,     0,    43,   113,     0,     0,
       0,     0,     0,     0,     0,   109,     0,     0,     0,     0,
      64,     0,    66,     0,    80,    41,     0,     0,    84,    85,
      86,    87,    88,    89,    92,    93,     0,     0,    96,    97,
       0,   100,   101,   102,     0,   103,     0,     0,     0,     0,
       0,    73,    74,    29,     0,    33,    30,    32,     0,     0,
       0,     0,    16,    12,    15,     0,   121,     0,   118,   110,
     114,     0,     0,    45,     0,     0,    53,     0,    52,     0,
      51,     0,    65,    67,    76,    78,    82,    90,    94,    98,
      68,    69,    70,    71,    72,    35,     0,     0,    23,    27,
      17,     0,   112,   117,     0,    11,     0,     0,    44,    47,
      58,    49,     0,     0,     0,    55,    60,     0,     0,    34,
      31,    22,   120,     0,    10,     0,     0,     0,     9,    54,
      59,    56,    61,    62,     0,    63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,  -142,  -142,   192,  -142,  -142,  -135,   131,  -142,     4,
    -142,   134,  -142,    82,  -142,    50,  -110,  -142,  -142,  -142,
    -142,  -142,    73,  -117,  -141,  -142,  -142,  -142,   -21,   -31,
     123,   -32,  -142,  -142,   112,  -142,   119,  -142,   111,  -142,
     -47,  -142,  -142,   -33,  -142,  -142,  -142,  -142,  -142
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,     9,   143,    19,    20,    21,    66,
      11,    67,    68,    69,   126,   127,    41,    42,    43,    44,
      82,   145,    45,    46,    47,   187,    48,    49,    50,    51,
      52,    53,    54,   106,    55,   107,    56,   110,    57,   114,
      58,    59,    60,    61,    62,    63,   137,   138,    64
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,    85,    84,    87,    10,    85,    94,    81,   186,   177,
     197,    10,   115,    96,    15,    91,    93,    80,   168,    23,
      24,    25,    26,    90,    14,   147,    85,    70,   139,    28,
     181,   139,   185,    77,    96,   179,    77,   146,    12,    75,
     148,   193,    85,    76,   134,    13,   149,    95,    77,    30,
      31,   139,    96,    32,   200,   202,    77,   135,   136,    96,
      17,   191,    18,    85,    85,   155,     1,   159,     2,    38,
      39,    40,    97,    85,    85,   108,   109,    85,   199,   201,
      80,    85,    23,    24,    25,    26,   144,    -2,     1,    71,
       2,    72,    28,  -119,   128,   160,   161,   162,   163,   164,
      73,    65,    74,     3,     4,     5,   111,   112,   113,     3,
       4,     5,    30,    31,   -26,    78,    32,    79,    85,    88,
     188,    89,   124,   123,   125,     3,     4,     5,    17,   194,
     132,    74,    38,    39,    40,   198,   129,    74,     3,     4,
       5,   204,   130,    96,   104,   105,   176,   140,   150,    85,
      85,    84,    87,   192,   151,   141,   152,   -48,   -48,   -48,
     -48,   -48,   142,   153,    85,   165,   203,   -48,   166,   -48,
     -48,    85,   167,   205,    98,    99,   100,   101,   102,   103,
     104,   105,   170,   171,    71,   173,   172,   -48,   -48,   174,
     175,   -48,     3,     4,     5,   -48,   189,    89,   -48,    16,
     -48,   -48,   195,   196,   -48,   133,   131,   -48,   -48,   -48,
      22,   169,    23,    24,    25,    26,    27,   190,   156,   154,
     180,   158,    28,     0,    29,   178,   157,     0,     0,     0,
       0,     0,     0,    22,     0,    23,    24,    25,    26,    27,
       0,     0,    30,    31,     0,    28,    32,    29,     0,     0,
      33,     0,     0,    34,     0,    35,    36,     0,     0,    37,
       0,     0,    38,    39,    40,    30,    31,     0,     0,    32,
       0,     0,     0,    33,     0,     0,    34,     0,    35,    36,
       0,     0,    37,     0,     0,    38,    39,    40,    22,     0,
      23,    24,    25,    26,    27,     0,     0,     0,     0,     0,
      28,     0,    29,    80,     0,    23,    24,    25,    26,    92,
       0,     0,     0,     0,    80,    28,    23,    24,    25,    26,
      30,    31,     0,     0,    32,     0,    28,     0,   182,     0,
       0,   183,     0,   184,    36,    30,    31,    37,     0,    32,
      38,    39,    40,     0,     0,     0,    30,    31,     0,    83,
      32,    23,    24,    25,    26,    38,    39,    40,     0,     0,
      86,    28,    23,    24,    25,    26,    38,    39,    40,     0,
       0,     0,    28,     0,    80,     0,    23,    24,    25,    26,
       0,    30,    31,     0,     0,    32,    28,     0,     0,     0,
       0,     0,    30,    31,     0,     0,    32,     0,     0,     0,
       0,    38,    39,    40,     0,     0,    30,    31,     0,     0,
      32,     0,    38,    39,    40,     0,     0,     0,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,    39,    40,  -110,
    -110,   116,   117,   118,   119,   120,   121,   122,     0,     0,
       0,     0,     0,     0,     0,  -110,  -110
};

static const yytype_int16 yycheck[] =
{
      33,    34,    33,    34,     0,    38,    38,    28,   149,   144,
      48,     7,    59,    51,     0,    36,    37,     1,   128,     3,
       4,     5,     6,     7,    13,    42,    59,    12,     7,    13,
     147,     7,   149,    12,    51,   145,    12,    16,     7,    10,
      16,   176,    75,     7,    75,    14,    45,     7,    12,    33,
      34,     7,    51,    37,   195,   196,    12,    78,    79,    51,
       1,   171,     3,    96,    97,    97,     1,   114,     3,    53,
      54,    55,    52,   106,   107,    32,    33,   110,   195,   196,
       1,   114,     3,     4,     5,     6,    82,     0,     1,    11,
       3,    13,    13,    14,    14,   116,   117,   118,   119,   120,
       7,     1,     9,    38,    39,    40,    34,    35,    36,    38,
      39,    40,    33,    34,    14,    11,    37,    13,   151,     1,
     151,     3,     1,     7,     3,    38,    39,    40,     1,     7,
       3,     9,    53,    54,    55,     7,     7,     9,    38,    39,
      40,    49,     4,    51,    30,    31,   142,    14,    16,   182,
     183,   182,   183,   174,    17,     1,     7,     3,     4,     5,
       6,     7,     8,     7,   197,    12,   197,    13,    11,    15,
      16,   204,     9,   204,    24,    25,    26,    27,    28,    29,
      30,    31,    12,    14,    11,    14,    12,    33,    34,     9,
       7,    37,    38,    39,    40,    41,    12,     3,    44,     7,
      46,    47,    43,    45,    50,    74,    72,    53,    54,    55,
       1,   129,     3,     4,     5,     6,     7,   167,   106,    96,
     147,   110,    13,    -1,    15,    16,   107,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    33,    34,    -1,    13,    37,    15,    -1,    -1,
      41,    -1,    -1,    44,    -1,    46,    47,    -1,    -1,    50,
      -1,    -1,    53,    54,    55,    33,    34,    -1,    -1,    37,
      -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    46,    47,
      -1,    -1,    50,    -1,    -1,    53,    54,    55,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    15,     1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,     1,    13,     3,     4,     5,     6,
      33,    34,    -1,    -1,    37,    -1,    13,    -1,    41,    -1,
      -1,    44,    -1,    46,    47,    33,    34,    50,    -1,    37,
      53,    54,    55,    -1,    -1,    -1,    33,    34,    -1,     1,
      37,     3,     4,     5,     6,    53,    54,    55,    -1,    -1,
       1,    13,     3,     4,     5,     6,    53,    54,    55,    -1,
      -1,    -1,    13,    -1,     1,    -1,     3,     4,     5,     6,
      -1,    33,    34,    -1,    -1,    37,    13,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    53,    54,    55,    -1,    -1,    33,    34,    -1,    -1,
      37,    -1,    53,    54,    55,    -1,    -1,    -1,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    54,    55,    35,
      36,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    38,    39,    40,    57,    58,    59,    60,
      65,    66,     7,    14,    13,     0,    59,     1,     3,    62,
      63,    64,     1,     3,     4,     5,     6,     7,    13,    15,
      33,    34,    37,    41,    44,    46,    47,    50,    53,    54,
      55,    72,    73,    74,    75,    78,    79,    80,    82,    83,
      84,    85,    86,    87,    88,    90,    92,    94,    96,    97,
      98,    99,   100,   101,   104,     1,    65,    67,    68,    69,
      12,    11,    13,     7,     9,    10,     7,    12,    11,    13,
       1,    84,    76,     1,    85,    99,     1,    85,     1,     3,
       7,    84,     7,    84,    87,     7,    51,    52,    24,    25,
      26,    27,    28,    29,    30,    31,    89,    91,    32,    33,
      93,    34,    35,    36,    95,    96,    17,    18,    19,    20,
      21,    22,    23,     7,     1,     3,    70,    71,    14,     7,
       4,    67,     3,    63,    85,    84,    84,   102,   103,     7,
      14,     1,     8,    61,    65,    77,    16,    42,    16,    45,
      16,    17,     7,     7,    86,    87,    90,    92,    94,    96,
      84,    84,    84,    84,    84,    12,    11,     9,    72,    69,
      12,    14,    12,    14,     9,     7,    65,    62,    16,    72,
      78,    79,    41,    44,    46,    79,    80,    81,    85,    12,
      71,    72,    84,    62,     7,    43,    45,    48,     7,    79,
      80,    79,    80,    85,    49,    85
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    60,    61,
      61,    61,    62,    62,    63,    63,    64,    64,    64,    65,
      65,    65,    66,    66,    66,    67,    67,    68,    68,    68,
      69,    70,    70,    71,    71,    71,    72,    73,    73,    73,
      73,    74,    74,    74,    75,    76,    76,    77,    77,    78,
      78,    78,    78,    78,    79,    79,    79,    79,    80,    80,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      84,    84,    84,    84,    84,    84,    85,    85,    86,    86,
      87,    87,    88,    88,    89,    89,    89,    89,    89,    89,
      90,    90,    91,    91,    92,    92,    93,    93,    94,    94,
      95,    95,    95,    96,    96,    97,    97,    97,    98,    98,
      98,    99,    99,    99,   100,   100,   100,   101,   102,   102,
     103,   103,   104,   104,   104,   104,   104
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     2,     3,     4,
       3,     2,     3,     1,     1,     3,     1,     4,     2,     1,
       1,     1,     6,     5,     3,     1,     0,     3,     1,     2,
       2,     3,     1,     1,     3,     2,     1,     1,     1,     1,
       1,     2,     1,     2,     4,     2,     0,     2,     0,     1,
       1,     3,     3,     3,     6,     4,     6,     1,     4,     6,
       4,     6,     3,     5,     2,     3,     2,     3,     3,     3,
       3,     3,     3,     2,     2,     1,     3,     1,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     4,     2,     3,     1,     1,     4,     1,     0,
       3,     1,     1,     1,     1,     1,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
#line 42 "Parser/parser.y"
                {ASTRoot = (yyvsp[0].node);}
#line 1650 "build/parser.tab.c"
    break;

  case 3: /* declList: declList decl  */
#line 46 "Parser/parser.y"
                    {(yyval.node) = TreeNode::NodeList((yyvsp[-1].node), (yyvsp[0].node));}
#line 1656 "build/parser.tab.c"
    break;

  case 4: /* declList: decl  */
#line 47 "Parser/parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1662 "build/parser.tab.c"
    break;

  case 5: /* decl: varDecl  */
#line 51 "Parser/parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1668 "build/parser.tab.c"
    break;

  case 6: /* decl: funDecl  */
#line 52 "Parser/parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1674 "build/parser.tab.c"
    break;

  case 7: /* decl: error SEMICOLON  */
#line 53 "Parser/parser.y"
                        {(yyval.node) = nullptr; yyerrok; }
#line 1680 "build/parser.tab.c"
    break;

  case 8: /* varDecl: typeSpec varDeclList SEMICOLON  */
#line 57 "Parser/parser.y"
                                    {(yyval.node) = TreeNode::PullUpTypeNode((yyvsp[-1].node), (yyvsp[-2].varType)); TreeNode::SetNodeListTypes((yyvsp[-2].varType), (yyvsp[-1].node));}
#line 1686 "build/parser.tab.c"
    break;

  case 9: /* scopedVarDecl: STATIC typeSpec varDeclList SEMICOLON  */
#line 61 "Parser/parser.y"
                                            {(yyval.node) = TreeNode::PullUpTypeNode((yyvsp[-1].node), (yyvsp[-2].varType)); for(TreeNode* v = (yyval.node); v != nullptr; v = v->sibling) v->isStatic = true; TreeNode::SetNodeListTypes((yyvsp[-2].varType), (yyvsp[-1].node));}
#line 1692 "build/parser.tab.c"
    break;

  case 10: /* scopedVarDecl: typeSpec varDeclList SEMICOLON  */
#line 62 "Parser/parser.y"
                                            {(yyval.node) = TreeNode::PullUpTypeNode((yyvsp[-1].node), (yyvsp[-2].varType)); TreeNode::SetNodeListTypes((yyvsp[-2].varType), (yyvsp[-1].node));}
#line 1698 "build/parser.tab.c"
    break;

  case 11: /* scopedVarDecl: error SEMICOLON  */
#line 63 "Parser/parser.y"
                                            {(yyval.node) = nullptr; yyerrok; }
#line 1704 "build/parser.tab.c"
    break;

  case 12: /* varDeclList: varDeclList COMMA varDeclInit  */
#line 67 "Parser/parser.y"
                                    {(yyval.node) = TreeNode::NodeList((yyvsp[-2].node), (yyvsp[0].node));}
#line 1710 "build/parser.tab.c"
    break;

  case 13: /* varDeclList: varDeclInit  */
#line 68 "Parser/parser.y"
                                    {(yyval.node) = (yyvsp[0].node);}
#line 1716 "build/parser.tab.c"
    break;

  case 14: /* varDeclInit: varDeclId  */
#line 72 "Parser/parser.y"
                                {(yyval.node) = (yyvsp[0].node);}
#line 1722 "build/parser.tab.c"
    break;

  case 15: /* varDeclInit: varDeclId COLON simpleExp  */
#line 73 "Parser/parser.y"
                                {(yyval.node) = TreeNode::PullUpNode((yyvsp[-2].node), (yyvsp[0].node), nullptr, nullptr);}
#line 1728 "build/parser.tab.c"
    break;

  case 16: /* varDeclId: ID  */
#line 77 "Parser/parser.y"
                                    {(yyval.node) = TreeNode::CreateVarDecl(nullptr, (yyvsp[0].tokenData));}
#line 1734 "build/parser.tab.c"
    break;

  case 17: /* varDeclId: ID LBRACKET NUMCONST RBRACKET  */
#line 78 "Parser/parser.y"
                                    {(yyval.node) = TreeNode::CreateVarDecl((yyvsp[-1].tokenData), (yyvsp[-3].tokenData)); (yyval.node)->isArray = true;}
#line 1740 "build/parser.tab.c"
    break;

  case 18: /* varDeclId: error RBRACKET  */
#line 79 "Parser/parser.y"
                                    {(yyval.node) = nullptr; yyerrok; }
#line 1746 "build/parser.tab.c"
    break;

  case 19: /* typeSpec: INT  */
#line 83 "Parser/parser.y"
            {(yyval.varType) = TreeNode::VarType::INTEGER;}
#line 1752 "build/parser.tab.c"
    break;

  case 20: /* typeSpec: BOOL  */
#line 84 "Parser/parser.y"
            {(yyval.varType) = TreeNode::VarType::BOOLEAN;}
#line 1758 "build/parser.tab.c"
    break;

  case 21: /* typeSpec: CHAR  */
#line 85 "Parser/parser.y"
            {(yyval.varType) = TreeNode::VarType::CHARACTER;}
#line 1764 "build/parser.tab.c"
    break;

  case 22: /* funDecl: typeSpec ID LPAREN parms RPAREN stmt  */
#line 89 "Parser/parser.y"
                                            {(yyval.node) = TreeNode::CreateFuncDecl((yyvsp[-5].varType), (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-4].tokenData));}
#line 1770 "build/parser.tab.c"
    break;

  case 23: /* funDecl: ID LPAREN parms RPAREN stmt  */
#line 90 "Parser/parser.y"
                                            {(yyval.node) = TreeNode::CreateFuncDecl(TreeNode::VarType::VOID, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-4].tokenData));}
#line 1776 "build/parser.tab.c"
    break;

  case 24: /* funDecl: error RPAREN stmt  */
#line 91 "Parser/parser.y"
                                            {(yyval.node) = nullptr; yyerrok; }
#line 1782 "build/parser.tab.c"
    break;

  case 25: /* parms: parmList  */
#line 95 "Parser/parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 1788 "build/parser.tab.c"
    break;

  case 26: /* parms: %empty  */
#line 96 "Parser/parser.y"
                {(yyval.node) = nullptr;}
#line 1794 "build/parser.tab.c"
    break;

  case 27: /* parmList: parmList SEMICOLON parmTypeList  */
#line 100 "Parser/parser.y"
                                    {(yyval.node) = TreeNode::NodeList((yyvsp[-2].node), (yyvsp[0].node));}
#line 1800 "build/parser.tab.c"
    break;

  case 28: /* parmList: parmTypeList  */
#line 101 "Parser/parser.y"
                                    {(yyval.node) = (yyvsp[0].node);}
#line 1806 "build/parser.tab.c"
    break;

  case 29: /* parmList: error SEMICOLON  */
#line 102 "Parser/parser.y"
                                    {(yyval.node) = nullptr; yyerrok; }
#line 1812 "build/parser.tab.c"
    break;

  case 30: /* parmTypeList: typeSpec parmIdList  */
#line 106 "Parser/parser.y"
                        {(yyval.node) = (yyvsp[0].node); TreeNode::SetNodeListTypes((yyvsp[-1].varType), (yyvsp[0].node));}
#line 1818 "build/parser.tab.c"
    break;

  case 31: /* parmIdList: parmIdList COMMA parmId  */
#line 110 "Parser/parser.y"
                            {(yyval.node) = TreeNode::NodeList((yyvsp[-2].node), (yyvsp[0].node));}
#line 1824 "build/parser.tab.c"
    break;

  case 32: /* parmIdList: parmId  */
#line 111 "Parser/parser.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 1830 "build/parser.tab.c"
    break;

  case 33: /* parmId: ID  */
#line 115 "Parser/parser.y"
                            {(yyval.node) = TreeNode::CreateParmDecl((yyvsp[0].tokenData));}
#line 1836 "build/parser.tab.c"
    break;

  case 34: /* parmId: ID LBRACKET RBRACKET  */
#line 116 "Parser/parser.y"
                            {(yyval.node) = TreeNode::CreateParmDecl((yyvsp[-2].tokenData)); (yyval.node)->isArray = true;}
#line 1842 "build/parser.tab.c"
    break;

  case 35: /* parmId: error RBRACKET  */
#line 117 "Parser/parser.y"
                            {(yyval.node) = nullptr; yyerrok; }
#line 1848 "build/parser.tab.c"
    break;

  case 36: /* stmt: selectStmt  */
#line 121 "Parser/parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 1854 "build/parser.tab.c"
    break;

  case 37: /* otherStmts: expStmt  */
#line 125 "Parser/parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1860 "build/parser.tab.c"
    break;

  case 38: /* otherStmts: compoundStmt  */
#line 126 "Parser/parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1866 "build/parser.tab.c"
    break;

  case 39: /* otherStmts: returnStmt  */
#line 127 "Parser/parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1872 "build/parser.tab.c"
    break;

  case 40: /* otherStmts: breakStmt  */
#line 128 "Parser/parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1878 "build/parser.tab.c"
    break;

  case 41: /* expStmt: exp SEMICOLON  */
#line 132 "Parser/parser.y"
                        {(yyval.node) = (yyvsp[-1].node); (yyval.node)->isStmtExp = true;}
#line 1884 "build/parser.tab.c"
    break;

  case 42: /* expStmt: SEMICOLON  */
#line 133 "Parser/parser.y"
                        {(yyval.node) = nullptr;}
#line 1890 "build/parser.tab.c"
    break;

  case 43: /* expStmt: error SEMICOLON  */
#line 134 "Parser/parser.y"
                        {(yyval.node) = nullptr; yyerrok; }
#line 1896 "build/parser.tab.c"
    break;

  case 44: /* compoundStmt: LBRACE localDecls stmtList RBRACE  */
#line 138 "Parser/parser.y"
                                        {(yyval.node) = TreeNode::CreateCompoundStmt((yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[-3].tokenData));}
#line 1902 "build/parser.tab.c"
    break;

  case 45: /* localDecls: localDecls scopedVarDecl  */
#line 142 "Parser/parser.y"
                                {(yyval.node) = TreeNode::NodeList((yyvsp[-1].node), (yyvsp[0].node));}
#line 1908 "build/parser.tab.c"
    break;

  case 46: /* localDecls: %empty  */
#line 143 "Parser/parser.y"
                                {(yyval.node) = nullptr;}
#line 1914 "build/parser.tab.c"
    break;

  case 47: /* stmtList: stmtList stmt  */
#line 147 "Parser/parser.y"
                    {(yyval.node) = TreeNode::NodeList((yyvsp[-1].node), (yyvsp[0].node));}
#line 1920 "build/parser.tab.c"
    break;

  case 48: /* stmtList: %empty  */
#line 148 "Parser/parser.y"
                    {(yyval.node) = nullptr;}
#line 1926 "build/parser.tab.c"
    break;

  case 49: /* selectStmt: matchedStmt  */
#line 152 "Parser/parser.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 1932 "build/parser.tab.c"
    break;

  case 50: /* selectStmt: unmatchedStmt  */
#line 153 "Parser/parser.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 1938 "build/parser.tab.c"
    break;

  case 51: /* selectStmt: FOR error RBRACE  */
#line 154 "Parser/parser.y"
                            {(yyval.node) = nullptr; yyerrok; }
#line 1944 "build/parser.tab.c"
    break;

  case 52: /* selectStmt: WHILE error RBRACE  */
#line 155 "Parser/parser.y"
                            {(yyval.node) = nullptr; yyerrok; }
#line 1950 "build/parser.tab.c"
    break;

  case 53: /* selectStmt: IF error RBRACE  */
#line 156 "Parser/parser.y"
                            {(yyval.node) = nullptr; yyerrok; }
#line 1956 "build/parser.tab.c"
    break;

  case 54: /* matchedStmt: IF simpleExp THEN matchedStmt ELSE matchedStmt  */
#line 160 "Parser/parser.y"
                                                    {(yyval.node) = TreeNode::CreateIfStmt((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-5].tokenData));}
#line 1962 "build/parser.tab.c"
    break;

  case 55: /* matchedStmt: WHILE simpleExp DO matchedStmt  */
#line 161 "Parser/parser.y"
                                                    {(yyval.node) = TreeNode::CreateWhileStmt((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-3].tokenData));}
#line 1968 "build/parser.tab.c"
    break;

  case 56: /* matchedStmt: FOR ID ASSIGN iterRange DO matchedStmt  */
#line 162 "Parser/parser.y"
                                                    {(yyval.node) = TreeNode::CreateForStmt((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-4].tokenData), (yyvsp[-5].tokenData));}
#line 1974 "build/parser.tab.c"
    break;

  case 57: /* matchedStmt: otherStmts  */
#line 163 "Parser/parser.y"
                                                    {(yyval.node) = (yyvsp[0].node);}
#line 1980 "build/parser.tab.c"
    break;

  case 58: /* unmatchedStmt: IF simpleExp THEN selectStmt  */
#line 167 "Parser/parser.y"
                                                            {(yyval.node) = TreeNode::CreateIfStmt((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-3].tokenData));}
#line 1986 "build/parser.tab.c"
    break;

  case 59: /* unmatchedStmt: IF simpleExp THEN matchedStmt ELSE unmatchedStmt  */
#line 168 "Parser/parser.y"
                                                            {(yyval.node) = TreeNode::CreateIfStmt((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-5].tokenData));}
#line 1992 "build/parser.tab.c"
    break;

  case 60: /* unmatchedStmt: WHILE simpleExp DO unmatchedStmt  */
#line 169 "Parser/parser.y"
                                                            {(yyval.node) = TreeNode::CreateWhileStmt((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-3].tokenData));}
#line 1998 "build/parser.tab.c"
    break;

  case 61: /* unmatchedStmt: FOR ID ASSIGN iterRange DO unmatchedStmt  */
#line 170 "Parser/parser.y"
                                                            {(yyval.node) = TreeNode::CreateForStmt((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-4].tokenData), (yyvsp[-5].tokenData));}
#line 2004 "build/parser.tab.c"
    break;

  case 62: /* iterRange: simpleExp TO simpleExp  */
#line 174 "Parser/parser.y"
                                          {(yyval.node) = TreeNode::CreateRangeStmt((yyvsp[-2].node), (yyvsp[0].node), nullptr, (yyvsp[-1].tokenData));}
#line 2010 "build/parser.tab.c"
    break;

  case 63: /* iterRange: simpleExp TO simpleExp BY simpleExp  */
#line 175 "Parser/parser.y"
                                            {(yyval.node) = TreeNode::CreateRangeStmt((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-3].tokenData));}
#line 2016 "build/parser.tab.c"
    break;

  case 64: /* returnStmt: RETURN SEMICOLON  */
#line 179 "Parser/parser.y"
                            {(yyval.node) = TreeNode::CreateReturnStmt(nullptr, (yyvsp[-1].tokenData));}
#line 2022 "build/parser.tab.c"
    break;

  case 65: /* returnStmt: RETURN exp SEMICOLON  */
#line 180 "Parser/parser.y"
                            {(yyval.node) = TreeNode::CreateReturnStmt((yyvsp[-1].node), (yyvsp[-2].tokenData));}
#line 2028 "build/parser.tab.c"
    break;

  case 66: /* breakStmt: BREAK SEMICOLON  */
#line 184 "Parser/parser.y"
                            {(yyval.node) = TreeNode::CreateBreakStmt(nullptr, (yyvsp[-1].tokenData));}
#line 2034 "build/parser.tab.c"
    break;

  case 67: /* breakStmt: BREAK exp SEMICOLON  */
#line 185 "Parser/parser.y"
                            {(yyval.node) = TreeNode::CreateBreakStmt((yyvsp[-1].node), (yyvsp[-2].tokenData));}
#line 2040 "build/parser.tab.c"
    break;

  case 68: /* exp: mutable ASSIGN exp  */
#line 189 "Parser/parser.y"
                            {(yyval.node) = TreeNode::CreateAssignExp((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].tokenData)); (yyval.node)->varType = (yyvsp[0].node)->varType; }
#line 2046 "build/parser.tab.c"
    break;

  case 69: /* exp: mutable ADDASS exp  */
#line 190 "Parser/parser.y"
                            {(yyval.node) = TreeNode::CreateAssignExp((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].tokenData)); (yyval.node)->varType = TreeNode::VarType::INTEGER; }
#line 2052 "build/parser.tab.c"
    break;

  case 70: /* exp: mutable SUBASS exp  */
#line 191 "Parser/parser.y"
                            {(yyval.node) = TreeNode::CreateAssignExp((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].tokenData)); (yyval.node)->varType = TreeNode::VarType::INTEGER; }
#line 2058 "build/parser.tab.c"
    break;

  case 71: /* exp: mutable MULASS exp  */
#line 192 "Parser/parser.y"
                            {(yyval.node) = TreeNode::CreateAssignExp((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].tokenData)); (yyval.node)->varType = TreeNode::VarType::INTEGER; }
#line 2064 "build/parser.tab.c"
    break;

  case 72: /* exp: mutable DIVASS exp  */
#line 193 "Parser/parser.y"
                            {(yyval.node) = TreeNode::CreateAssignExp((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].tokenData)); (yyval.node)->varType = TreeNode::VarType::INTEGER; }
#line 2070 "build/parser.tab.c"
    break;

  case 73: /* exp: mutable INC  */
#line 194 "Parser/parser.y"
                            {(yyval.node) = TreeNode::CreateAssignExp((yyvsp[-1].node), nullptr, (yyvsp[0].tokenData)); (yyval.node)->varType = TreeNode::VarType::INTEGER; }
#line 2076 "build/parser.tab.c"
    break;

  case 74: /* exp: mutable DEC  */
#line 195 "Parser/parser.y"
                            {(yyval.node) = TreeNode::CreateAssignExp((yyvsp[-1].node), nullptr, (yyvsp[0].tokenData)); (yyval.node)->varType = TreeNode::VarType::INTEGER; }
#line 2082 "build/parser.tab.c"
    break;

  case 75: /* exp: simpleExp  */
#line 196 "Parser/parser.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2088 "build/parser.tab.c"
    break;

  case 76: /* simpleExp: simpleExp OR andExp  */
#line 200 "Parser/parser.y"
                        {(yyval.node) = TreeNode::CreateOpExp((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].tokenData)); (yyval.node)->varType = TreeNode::VarType::BOOLEAN; }
#line 2094 "build/parser.tab.c"
    break;

  case 77: /* simpleExp: andExp  */
#line 201 "Parser/parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2100 "build/parser.tab.c"
    break;

  case 78: /* andExp: andExp AND unaryRelExp  */
#line 205 "Parser/parser.y"
                            {(yyval.node) = TreeNode::CreateOpExp((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].tokenData)); (yyval.node)->varType = TreeNode::VarType::BOOLEAN; }
#line 2106 "build/parser.tab.c"
    break;

  case 79: /* andExp: unaryRelExp  */
#line 206 "Parser/parser.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2112 "build/parser.tab.c"
    break;

  case 80: /* unaryRelExp: NOT unaryRelExp  */
#line 210 "Parser/parser.y"
                    {(yyval.node) = TreeNode::CreateOpExp((yyvsp[0].node), nullptr, (yyvsp[-1].tokenData)); (yyval.node)->varType = TreeNode::VarType::BOOLEAN; }
#line 2118 "build/parser.tab.c"
    break;

  case 81: /* unaryRelExp: relExp  */
#line 211 "Parser/parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 2124 "build/parser.tab.c"
    break;

  case 82: /* relExp: minmaxExp relop minmaxExp  */
#line 215 "Parser/parser.y"
                                {(yyval.node) = TreeNode::PullUpNode((yyvsp[-1].node), (yyvsp[-2].node), (yyvsp[0].node), nullptr); (yyval.node)->varType = TreeNode::VarType::BOOLEAN; }
#line 2130 "build/parser.tab.c"
    break;

  case 83: /* relExp: minmaxExp  */
#line 216 "Parser/parser.y"
                                {(yyval.node) = (yyvsp[0].node);}
#line 2136 "build/parser.tab.c"
    break;

  case 84: /* relop: LEQ  */
#line 220 "Parser/parser.y"
            {(yyval.node) = TreeNode::CreateOpExp(nullptr, nullptr, (yyvsp[0].tokenData));}
#line 2142 "build/parser.tab.c"
    break;

  case 85: /* relop: LT  */
#line 221 "Parser/parser.y"
            {(yyval.node) = TreeNode::CreateOpExp(nullptr, nullptr, (yyvsp[0].tokenData));}
#line 2148 "build/parser.tab.c"
    break;

  case 86: /* relop: GT  */
#line 222 "Parser/parser.y"
            {(yyval.node) = TreeNode::CreateOpExp(nullptr, nullptr, (yyvsp[0].tokenData));}
#line 2154 "build/parser.tab.c"
    break;

  case 87: /* relop: GEQ  */
#line 223 "Parser/parser.y"
            {(yyval.node) = TreeNode::CreateOpExp(nullptr, nullptr, (yyvsp[0].tokenData));}
#line 2160 "build/parser.tab.c"
    break;

  case 88: /* relop: EQ  */
#line 224 "Parser/parser.y"
            {(yyval.node) = TreeNode::CreateOpExp(nullptr, nullptr, (yyvsp[0].tokenData));}
#line 2166 "build/parser.tab.c"
    break;

  case 89: /* relop: NEQ  */
#line 225 "Parser/parser.y"
            {(yyval.node) = TreeNode::CreateOpExp(nullptr, nullptr, (yyvsp[0].tokenData));}
#line 2172 "build/parser.tab.c"
    break;

  case 90: /* minmaxExp: minmaxExp minmaxop sumExp  */
#line 229 "Parser/parser.y"
                                {(yyval.node) = TreeNode::PullUpNode((yyvsp[-1].node), (yyvsp[-2].node), (yyvsp[0].node), nullptr); (yyval.node)->varType = TreeNode::VarType::INTEGER; }
#line 2178 "build/parser.tab.c"
    break;

  case 91: /* minmaxExp: sumExp  */
#line 230 "Parser/parser.y"
                                {(yyval.node) = (yyvsp[0].node);}
#line 2184 "build/parser.tab.c"
    break;

  case 92: /* minmaxop: MIN  */
#line 234 "Parser/parser.y"
            {(yyval.node) = TreeNode::CreateOpExp(nullptr, nullptr, (yyvsp[0].tokenData)); (yyval.node)->varType = TreeNode::VarType::INTEGER; }
#line 2190 "build/parser.tab.c"
    break;

  case 93: /* minmaxop: MAX  */
#line 235 "Parser/parser.y"
            {(yyval.node) = TreeNode::CreateOpExp(nullptr, nullptr, (yyvsp[0].tokenData)); (yyval.node)->varType = TreeNode::VarType::INTEGER; }
#line 2196 "build/parser.tab.c"
    break;

  case 94: /* sumExp: sumExp sumop mulExp  */
#line 239 "Parser/parser.y"
                        {(yyval.node) = TreeNode::PullUpNode((yyvsp[-1].node), (yyvsp[-2].node), (yyvsp[0].node), nullptr); (yyval.node)->varType = TreeNode::VarType::INTEGER; }
#line 2202 "build/parser.tab.c"
    break;

  case 95: /* sumExp: mulExp  */
#line 240 "Parser/parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2208 "build/parser.tab.c"
    break;

  case 96: /* sumop: PLUS  */
#line 244 "Parser/parser.y"
            {(yyval.node) = TreeNode::CreateOpExp(nullptr, nullptr, (yyvsp[0].tokenData));}
#line 2214 "build/parser.tab.c"
    break;

  case 97: /* sumop: MINUS  */
#line 245 "Parser/parser.y"
            {(yyval.node) = TreeNode::CreateOpExp(nullptr, nullptr, (yyvsp[0].tokenData));}
#line 2220 "build/parser.tab.c"
    break;

  case 98: /* mulExp: mulExp mulop unaryExp  */
#line 249 "Parser/parser.y"
                            {(yyval.node) = TreeNode::PullUpNode((yyvsp[-1].node), (yyvsp[-2].node), (yyvsp[0].node), nullptr); (yyval.node)->varType = TreeNode::VarType::INTEGER; }
#line 2226 "build/parser.tab.c"
    break;

  case 99: /* mulExp: unaryExp  */
#line 250 "Parser/parser.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2232 "build/parser.tab.c"
    break;

  case 100: /* mulop: STAR  */
#line 254 "Parser/parser.y"
                {(yyval.node) = TreeNode::CreateOpExp(nullptr, nullptr, (yyvsp[0].tokenData));}
#line 2238 "build/parser.tab.c"
    break;

  case 101: /* mulop: DIVIDE  */
#line 255 "Parser/parser.y"
                {(yyval.node) = TreeNode::CreateOpExp(nullptr, nullptr, (yyvsp[0].tokenData));}
#line 2244 "build/parser.tab.c"
    break;

  case 102: /* mulop: MOD  */
#line 256 "Parser/parser.y"
                {(yyval.node) = TreeNode::CreateOpExp(nullptr, nullptr, (yyvsp[0].tokenData));}
#line 2250 "build/parser.tab.c"
    break;

  case 103: /* unaryExp: unaryop unaryExp  */
#line 260 "Parser/parser.y"
                        {(yyval.node) = TreeNode::PullUpNode((yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr);}
#line 2256 "build/parser.tab.c"
    break;

  case 104: /* unaryExp: factor  */
#line 261 "Parser/parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2262 "build/parser.tab.c"
    break;

  case 105: /* unaryop: MINUS  */
#line 265 "Parser/parser.y"
                {(yyval.node) = TreeNode::CreateUnaryOpExp((yyvsp[0].tokenData));}
#line 2268 "build/parser.tab.c"
    break;

  case 106: /* unaryop: STAR  */
#line 266 "Parser/parser.y"
                {(yyval.node) = TreeNode::CreateUnaryOpExp((yyvsp[0].tokenData));}
#line 2274 "build/parser.tab.c"
    break;

  case 107: /* unaryop: QUESTION  */
#line 267 "Parser/parser.y"
                {(yyval.node) = TreeNode::CreateUnaryOpExp((yyvsp[0].tokenData));}
#line 2280 "build/parser.tab.c"
    break;

  case 108: /* factor: immutable  */
#line 271 "Parser/parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2286 "build/parser.tab.c"
    break;

  case 109: /* factor: mutable  */
#line 272 "Parser/parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2292 "build/parser.tab.c"
    break;

  case 110: /* factor: error SEMICOLON  */
#line 273 "Parser/parser.y"
                        {(yyval.node) = nullptr; yyerrok; }
#line 2298 "build/parser.tab.c"
    break;

  case 111: /* mutable: ID  */
#line 277 "Parser/parser.y"
                                {(yyval.node) = TreeNode::CreateIdExp((yyvsp[0].tokenData));}
#line 2304 "build/parser.tab.c"
    break;

  case 112: /* mutable: ID LBRACKET exp RBRACKET  */
#line 278 "Parser/parser.y"
                                {(yyval.node) = TreeNode::CreateIdxExp((yyvsp[-1].node), (yyvsp[-3].tokenData), (yyvsp[-2].tokenData)); (yyval.node)->varType = (yyvsp[-1].node)->varType; }
#line 2310 "build/parser.tab.c"
    break;

  case 113: /* mutable: error RBRACKET  */
#line 279 "Parser/parser.y"
                                {(yyval.node) = nullptr; yyerrok; }
#line 2316 "build/parser.tab.c"
    break;

  case 114: /* immutable: LPAREN exp RPAREN  */
#line 283 "Parser/parser.y"
                        {(yyval.node) = (yyvsp[-1].node);}
#line 2322 "build/parser.tab.c"
    break;

  case 115: /* immutable: call  */
#line 284 "Parser/parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2328 "build/parser.tab.c"
    break;

  case 116: /* immutable: constant  */
#line 285 "Parser/parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2334 "build/parser.tab.c"
    break;

  case 117: /* call: ID LPAREN args RPAREN  */
#line 289 "Parser/parser.y"
                            {(yyval.node) = TreeNode::CreateCallExp((yyvsp[-1].node), (yyvsp[-3].tokenData));}
#line 2340 "build/parser.tab.c"
    break;

  case 118: /* args: argList  */
#line 293 "Parser/parser.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 2346 "build/parser.tab.c"
    break;

  case 119: /* args: %empty  */
#line 294 "Parser/parser.y"
            {(yyval.node) = nullptr;}
#line 2352 "build/parser.tab.c"
    break;

  case 120: /* argList: argList COMMA exp  */
#line 298 "Parser/parser.y"
                        {(yyval.node) = TreeNode::NodeList((yyvsp[-2].node), (yyvsp[0].node));}
#line 2358 "build/parser.tab.c"
    break;

  case 121: /* argList: exp  */
#line 299 "Parser/parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2364 "build/parser.tab.c"
    break;

  case 122: /* constant: NUMCONST  */
#line 303 "Parser/parser.y"
                    {(yyval.node) = TreeNode::CreateConstExp(TreeNode::VarType::INTEGER, (yyvsp[0].tokenData)); (yyval.node)->isConst = true; }
#line 2370 "build/parser.tab.c"
    break;

  case 123: /* constant: CHARCONST  */
#line 304 "Parser/parser.y"
                    {(yyval.node) = TreeNode::CreateConstExp(TreeNode::VarType::CHARACTER, (yyvsp[0].tokenData));(yyval.node)->isConst = true; }
#line 2376 "build/parser.tab.c"
    break;

  case 124: /* constant: STRINGCONST  */
#line 305 "Parser/parser.y"
                    {(yyval.node) = TreeNode::CreateConstExp(TreeNode::VarType::CHARACTER, (yyvsp[0].tokenData)); (yyval.node)->isArray = true; (yyval.node)->isConst = true; }
#line 2382 "build/parser.tab.c"
    break;

  case 125: /* constant: TRUE  */
#line 306 "Parser/parser.y"
                    {(yyval.node) = TreeNode::CreateConstExp(TreeNode::VarType::BOOLEAN, (yyvsp[0].tokenData)); (yyval.node)->isConst = true; }
#line 2388 "build/parser.tab.c"
    break;

  case 126: /* constant: FALSE  */
#line 307 "Parser/parser.y"
                    {(yyval.node) = TreeNode::CreateConstExp(TreeNode::VarType::BOOLEAN, (yyvsp[0].tokenData)); (yyval.node)->isConst = true; }
#line 2394 "build/parser.tab.c"
    break;


#line 2398 "build/parser.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 310 "Parser/parser.y"


static const struct { const char* name; const char* spelling; } tokenSpellings[] = {
    {"SEMICOLON", "';'"}, {"COLON", "':'"}, {"COMMA", "','"},
    {"LBRACKET", "'['"}, {"RBRACKET", "']'"}, {"LPAREN", "'('"}, {"RPAREN", "')'"}, {"LBRACE", "'{'"}, {"RBRACE", "'}'"},
    {"ASSIGN", "'='"}, {"ADDASS", "'+='"}, {"SUBASS", "'-='"}, {"MULASS", "'*='"}, {"DIVASS", "'/='"},
    {"INC", "'++'"}, {"DEC", "'--'"}, {"LEQ", "'<='"}, {"LT", "'<'"}, {"GT", "'>'"}, {"GEQ", "'>='"},
    {"EQ", "'=='"}, {"NEQ", "'!='"}, {"MIN", "'<<'"}, {"MAX", "'>>'"},
    {"PLUS", "'+'"}, {"MINUS", "'-'"}, {"STAR", "'*'"}, {"DIVIDE", "'/'"}, {"MOD", "'%'"}, {"QUESTION", "'?'"},
    {"STATIC", "'static'"}, {"INT", "'int'"}, {"BOOL", "'bool'"}, {"CHAR", "'char'"},
    {"IF", "'if'"}, {"THEN", "'then'"}, {"ELSE", "'else'"}, {"WHILE", "'while'"}, {"DO", "'do'"}, {"FOR", "'for'"},
    {"RETURN", "'return'"}, {"TO", "'to'"}, {"BY", "'by'"}, {"BREAK", "'break'"},
    {"OR", "'or'"}, {"AND", "'and'"}, {"NOT", "'not'"}, {"TRUE", "'true'"}, {"FALSE", "'false'"},
};

void yyerror(const char* s)
{
    std::string in(s), out;

    for(size_t i = 0; i < in.size();) {
        size_t j = i;
        while(j < in.size() && ((in[j] >= 'A' && in[j] <= 'Z') || in[j] == '_'))
            j++;

        if(j == i) {
            out += in[i++];
            continue;
        }

        std::string word = in.substr(i, j - i);
        for(const auto& t : tokenSpellings)
            if(word == t.name) {
                word = t.spelling;
                break;
            }
        out += word;
        i = j;
    }

    ErrorHandler::AddSyntaxError(out, yylineno);
}

bool ProcessFlags(bool* stDebugFlag, bool* printFlag, bool* typePrintFlag)
{
    if(ArgHandler::IsFlagSet("-d"))
        yydebug = 1;
    if(ArgHandler::IsFlagSet("-D"))
        *stDebugFlag = true;
    if(ArgHandler::IsFlagSet("-h")) {
        ArgHandler::PrintHelp();
        return false;
    }
    if(ArgHandler::IsFlagSet("-p"))
        *printFlag = true;
    if(ArgHandler::IsFlagSet("-P"))
        *printFlag = true;

    return true;
}

bool OpenFile(int argc, char* argv[])
{
    const char* filePath = nullptr;
    for(int i = 1; i < argc; i++) {
        if(argv[i][0] != '-')
            filePath = argv[i];
    }

    if(filePath) {
        FILE* file = fopen(filePath, "r");
        if(!file) {
            perror(filePath);
            return false;
        }
        yyin = file;
    } else {
        yyin = stdin;
    }

    if(yyin == NULL) {
        printf("YYIN IS NULL!!!!!! BAD!!!!\n");
        return false;
    }

    //printf("====================================\n");
    //printf("FILE: %s\n", filePath);

    return true;
}

int main(int argc, char* argv[])
{
    // argument flags
    yydebug = 0;
    bool printFlag = false;
    bool typePrintFlag = false;
    bool stDebugFlag = false;

    ArgHandler::ProcessArgs(argc, argv);
    if(!ProcessFlags(&stDebugFlag, &printFlag, &typePrintFlag))
        return 0;

    if(!OpenFile(argc, argv))
        return 2;

    int result = yyparse();

    if(ErrorHandler::GetNumErrors() != 0) {
        std::cout << "Number of warnings: " << ErrorHandler::GetNumWarnings() << std::endl;
        std::cout << "Number of errors: " << ErrorHandler::GetNumErrors() << std::endl;
        return 3;
    }

    SemanticAnalyzer* analyzer = new SemanticAnalyzer(stDebugFlag);
    analyzer->StartAnalysis(ASTRoot);

    if((printFlag || typePrintFlag) && ASTRoot && ErrorHandler::GetNumErrors() == 0)
        ASTRoot->Print(0, -1, 0, typePrintFlag);

    std::cout << "Number of warnings: " << ErrorHandler::GetNumWarnings() << std::endl;
    std::cout << "Number of errors: " << ErrorHandler::GetNumErrors() << std::endl;

    return 0;
}
