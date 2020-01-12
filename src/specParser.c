/* A Bison parser, made by GNU Bison 3.4.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         zzparse
#define yylex           zzlex
#define yyerror         zzerror
#define yydebug         zzdebug
#define yynerrs         zznerrs

#define yylval          zzlval
#define yychar          zzchar

/* First part of user prologue.  */
#line 1 "specParser.y"

#include <stdio.h>
#include <string.h>
#include "ast.h"

int zzlex();
void zzerror(char*);
void lex_free();
extern int yylineno;
extern FILE* zzin;

ast specTree;


#line 93 "specParser.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_ZZ_SPECPARSER_H_INCLUDED
# define YY_ZZ_SPECPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int zzdebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    INT_VAL = 259,
    DOUBLE_VAL = 260,
    STRING = 261,
    COMMENT = 262,
    ASSIGN = 263,
    IF = 264,
    WHILE = 265,
    ELSE = 266,
    FOR = 267,
    MACRO = 268,
    MAIN = 269,
    RETURN = 270,
    INT = 271,
    DOUBLE = 272,
    VOID = 273,
    INC = 274,
    DEC = 275,
    PRINTF = 276,
    AND_OP = 277,
    OR_OP = 278,
    GEQ_OP = 279,
    LEQ_OP = 280,
    EQ_OP = 281,
    NEQ_OP = 282,
    UMINUS = 283
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INT_VAL 259
#define DOUBLE_VAL 260
#define STRING 261
#define COMMENT 262
#define ASSIGN 263
#define IF 264
#define WHILE 265
#define ELSE 266
#define FOR 267
#define MACRO 268
#define MAIN 269
#define RETURN 270
#define INT 271
#define DOUBLE 272
#define VOID 273
#define INC 274
#define DEC 275
#define PRINTF 276
#define AND_OP 277
#define OR_OP 278
#define GEQ_OP 279
#define LEQ_OP 280
#define EQ_OP 281
#define NEQ_OP 282
#define UMINUS 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "specParser.y"

    char* string;
    int int_val;
    double double_val;
    ast specTree;

#line 199 "specParser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE zzlval;

int zzparse (void);

#endif /* !YY_ZZ_SPECPARSER_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

#define YYUNDEFTOK  2
#define YYMAXUTOK   283

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      33,    34,    30,    28,    37,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
      42,     2,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      25,    26,    27,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    88,    92,    96,   115,   120,   127,   131,
     138,   142,   150,   156,   164,   165,   166,   167,   168,   172,
     173,   177,   184,   193,   194,   198,   199,   200,   204,   205,
     209,   210,   211,   215,   223,   234,   248,   252,   259,   260,
     264,   269,   277,   278,   282,   287,   292,   301,   305,   312,
     321,   337,   349,   372,   373,   377,   383,   389,   395,   401,
     407,   413,   419,   425,   432,   436,   443,   449,   455,   461,
     467,   471,   476,   480,   484,   495,   499
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INT_VAL", "DOUBLE_VAL",
  "STRING", "COMMENT", "ASSIGN", "IF", "WHILE", "ELSE", "FOR", "MACRO",
  "MAIN", "RETURN", "INT", "DOUBLE", "VOID", "INC", "DEC", "PRINTF",
  "AND_OP", "OR_OP", "GEQ_OP", "LEQ_OP", "EQ_OP", "NEQ_OP", "'+'", "'-'",
  "'*'", "'/'", "UMINUS", "'('", "')'", "'{'", "'}'", "','", "';'", "'['",
  "']'", "'>'", "'<'", "$accept", "axiom", "function_list", "function",
  "arg_list", "arg", "return", "statement_list", "statement",
  "initialisation_list", "initialisation", "declaration", "type",
  "assign_list", "element", "table", "size_list", "init_table_list",
  "init_table", "update_list", "update", "increment_action", "selection",
  "iteration", "condition_list", "condition", "expression_list",
  "expression", "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    43,    45,
      42,    47,   283,    40,    41,   123,   125,    44,    59,    91,
      93,    62,    60
};
# endif

#define YYPACT_NINF -128

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-128)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     145,  -128,  -128,  -128,    23,   145,  -128,    25,  -128,  -128,
       8,   145,   -15,    40,    12,   145,  -128,   118,  -128,     4,
      -4,    31,    33,    38,    34,  -128,  -128,  -128,  -128,    44,
     118,    51,     6,    54,  -128,  -128,  -128,   106,  -128,  -128,
    -128,   109,    52,    52,     9,  -128,    65,    65,    70,    77,
    -128,  -128,    52,    52,  -128,   137,  -128,  -128,  -128,  -128,
      54,     6,  -128,  -128,   149,   120,     7,    52,    65,    61,
     116,    -5,    74,   111,   144,  -128,   119,    90,  -128,   142,
      52,    52,    52,    52,  -128,  -128,  -128,     7,  -128,   149,
     124,    91,    76,    65,    65,   121,    52,    52,    52,    52,
      52,    52,   134,    65,    52,    70,    65,   151,  -128,   153,
     153,  -128,  -128,   150,  -128,   152,   149,  -128,  -128,  -128,
     163,   118,   149,   149,   149,   149,   149,   149,   118,    74,
     149,  -128,   154,    52,  -128,   139,  -128,    52,   157,   158,
      30,   149,  -128,   149,   179,  -128,   112,    56,  -128,   160,
     161,    30,   118,   118,  -128,   162,   164,  -128,  -128
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    25,    26,    27,     0,     2,     4,     0,     1,     3,
       0,     0,     0,     0,     0,     0,     7,     0,     6,     0,
      30,     0,     0,     0,     0,    47,    48,    18,    17,     0,
      13,     0,     0,    24,    29,    31,    32,     0,    15,    16,
       9,     0,     0,     0,    33,    45,     0,     0,     0,    72,
      75,    76,     0,     0,    10,     0,    73,     5,    12,    14,
      23,     0,    44,     8,    46,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     0,    20,     0,    74,    71,     0,
       0,     0,     0,     0,    11,    28,    37,     0,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    66,
      67,    68,    69,     0,    39,     0,    65,    36,    63,    56,
      55,     0,    57,    59,    61,    62,    58,    60,     0,    53,
      22,    19,     0,     0,    41,     0,    40,     0,     0,     0,
       0,    21,    38,    64,    49,    51,     0,     0,    43,     0,
       0,     0,     0,     0,    42,     0,     0,    50,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,  -128,   192,  -128,  -128,  -128,   -29,  -128,  -128,
      94,  -128,     3,   169,   141,  -128,   155,  -128,   -81,  -128,
    -127,   -20,  -128,  -128,    97,   -41,  -128,   -22,  -128
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    12,    18,    28,    29,    30,    74,
      75,    31,    32,    33,    34,    35,    44,   113,    88,   147,
      36,    37,    38,    39,    71,    72,   115,    70,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      45,    58,    55,     7,    42,    69,   114,    40,     7,    20,
      49,    50,    51,   148,    13,    25,    26,    66,    19,    14,
      64,    65,    15,     8,   154,    25,    26,    91,    10,   102,
      78,    79,   103,   146,    41,    43,    52,    49,    50,    51,
      53,    11,    87,    16,    89,    90,    92,    17,    67,    25,
      26,    76,   119,   120,   142,    49,    50,    51,   109,   110,
     111,   112,   129,    52,    46,   116,    47,    53,    49,    50,
      51,    48,    54,    73,   122,   123,   124,   125,   126,   127,
      57,    52,   130,    93,    94,    53,     1,     2,     3,    59,
     150,    61,   138,   151,    52,    95,    93,    94,    68,   139,
      96,    97,    98,    99,    80,    81,    82,    83,    76,    62,
     108,   141,    63,    93,    94,   143,    43,   100,   101,   104,
      42,    20,   107,   155,   156,   118,    45,    21,    22,    67,
      23,    25,    26,    24,     1,     2,     3,    25,    26,    27,
      96,    97,    98,    99,    80,    81,    82,    83,    80,    81,
      82,    83,    80,    81,    82,    83,   121,   100,   101,   133,
      86,     1,     2,     3,   117,    80,    81,    82,    83,   128,
      80,    81,    82,    83,    87,    84,   108,    80,    81,    82,
      83,   105,   106,    82,    83,    93,   134,   135,   136,   137,
     149,   103,   140,   144,   145,   152,   153,     9,   157,   131,
     158,    60,    85,   132,    77
};

static const yytype_uint8 yycheck[] =
{
      20,    30,    24,     0,     8,    46,    87,     3,     5,     3,
       3,     4,     5,   140,    11,    19,    20,     8,    15,    34,
      42,    43,    37,     0,   151,    19,    20,    68,     3,    34,
      52,    53,    37,     3,    30,    39,    29,     3,     4,     5,
      33,    33,    35,     3,    66,    67,    68,    35,    39,    19,
      20,    48,    93,    94,   135,     3,     4,     5,    80,    81,
      82,    83,   103,    29,    33,    87,    33,    33,     3,     4,
       5,    33,    38,     3,    96,    97,    98,    99,   100,   101,
      36,    29,   104,    22,    23,    33,    16,    17,    18,    38,
      34,    37,   121,    37,    29,    34,    22,    23,    33,   128,
      24,    25,    26,    27,    28,    29,    30,    31,   105,     3,
      34,   133,     3,    22,    23,   137,    39,    41,    42,     8,
       8,     3,     3,   152,   153,    34,   146,     9,    10,    39,
      12,    19,    20,    15,    16,    17,    18,    19,    20,    21,
      24,    25,    26,    27,    28,    29,    30,    31,    28,    29,
      30,    31,    28,    29,    30,    31,    35,    41,    42,     8,
      40,    16,    17,    18,    40,    28,    29,    30,    31,    35,
      28,    29,    30,    31,    35,    38,    34,    28,    29,    30,
      31,    37,    38,    30,    31,    22,    36,    37,    36,    37,
      11,    37,    38,    36,    36,    35,    35,     5,    36,   105,
      36,    32,    61,   106,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    17,    18,    44,    45,    46,    55,     0,    46,
       3,    33,    47,    55,    34,    37,     3,    35,    48,    55,
       3,     9,    10,    12,    15,    19,    20,    21,    49,    50,
      51,    54,    55,    56,    57,    58,    63,    64,    65,    66,
       3,    30,     8,    39,    59,    64,    33,    33,    33,     3,
       4,     5,    29,    33,    38,    70,    71,    36,    50,    38,
      56,    37,     3,     3,    70,    70,     8,    39,    33,    68,
      70,    67,    68,     3,    52,    53,    55,    59,    70,    70,
      28,    29,    30,    31,    38,    57,    40,    35,    61,    70,
      70,    68,    70,    22,    23,    34,    24,    25,    26,    27,
      41,    42,    34,    37,     8,    37,    38,     3,    34,    70,
      70,    70,    70,    60,    61,    69,    70,    40,    34,    68,
      68,    35,    70,    70,    70,    70,    70,    70,    35,    68,
      70,    53,    67,     8,    36,    37,    36,    37,    50,    50,
      38,    70,    61,    70,    36,    36,     3,    62,    63,    11,
      34,    37,    35,    35,    63,    50,    50,    36,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    47,    47,    48,    48,
      49,    49,    50,    50,    51,    51,    51,    51,    51,    52,
      52,    53,    53,    54,    54,    55,    55,    55,    56,    56,
      57,    57,    57,    58,    58,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    63,    63,    63,    64,    64,    65,
      65,    66,    66,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     8,     3,     2,     3,     2,
       2,     3,     2,     1,     2,     1,     1,     1,     1,     3,
       1,     4,     3,     2,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     2,     4,     4,     4,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     3,     1,     1,     7,
      11,     7,    11,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     2,     1,     1,     2,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
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
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
  case 2:
#line 79 "specParser.y"
    {   
            specTree = new_list(LIST_FUNC);
            add_child_node(specTree, (yyvsp[0].specTree));
            printf("\nFOUND\n");
            return 0;
        }
#line 1414 "specParser.c"
    break;

  case 3:
#line 89 "specParser.y"
    {
            (yyval.specTree) = add_brother_node((yyvsp[-1].specTree), (yyvsp[0].specTree));
        }
#line 1422 "specParser.c"
    break;

  case 4:
#line 92 "specParser.y"
    { (yyval.specTree) = (yyvsp[0].specTree); }
#line 1428 "specParser.c"
    break;

  case 5:
#line 97 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_FUNC);

            add_child_node((yyvsp[-7].specTree), new_id((yyvsp[-6].string)));
            add_child_node((yyval.specTree), (yyvsp[-7].specTree));

            ast list = new_list(LIST_ARG);
            add_child_node(list, (yyvsp[-4].specTree));

            ast statements = new_list(LIST_STAT);
            add_child_node(statements, (yyvsp[-1].specTree));

            add_child_node((yyval.specTree), list);
            add_child_node((yyval.specTree), statements);
        }
#line 1448 "specParser.c"
    break;

  case 6:
#line 116 "specParser.y"
    {
            
            (yyval.specTree) = add_brother_node((yyvsp[-2].specTree), (yyvsp[0].specTree));
        }
#line 1457 "specParser.c"
    break;

  case 7:
#line 121 "specParser.y"
    {
            (yyval.specTree) = add_child_node((yyvsp[-1].specTree), new_id((yyvsp[0].string))); 
        }
#line 1465 "specParser.c"
    break;

  case 8:
#line 128 "specParser.y"
    {
            (yyval.specTree) = add_child_node((yyvsp[-2].specTree), new_id((yyvsp[0].string)));
        }
#line 1473 "specParser.c"
    break;

  case 9:
#line 132 "specParser.y"
    {
            (yyval.specTree) = add_child_node((yyvsp[-1].specTree), new_id((yyvsp[0].string)));
        }
#line 1481 "specParser.c"
    break;

  case 10:
#line 139 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_RETURN);
        }
#line 1489 "specParser.c"
    break;

  case 11:
#line 143 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_RETURN);
            add_child_node((yyval.specTree), (yyvsp[-1].specTree));
        }
#line 1498 "specParser.c"
    break;

  case 12:
#line 151 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_STAT);
            add_brother_node((yyval.specTree), (yyvsp[0].specTree));
            add_child_node((yyval.specTree), (yyvsp[-1].specTree));
         }
#line 1508 "specParser.c"
    break;

  case 13:
#line 157 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_STAT);
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 1517 "specParser.c"
    break;

  case 14:
#line 164 "specParser.y"
    { (yyval.specTree) = (yyvsp[-1].specTree); }
#line 1523 "specParser.c"
    break;

  case 15:
#line 165 "specParser.y"
    { (yyval.specTree) = (yyvsp[0].specTree); }
#line 1529 "specParser.c"
    break;

  case 16:
#line 166 "specParser.y"
    { (yyval.specTree) = (yyvsp[0].specTree); }
#line 1535 "specParser.c"
    break;

  case 17:
#line 167 "specParser.y"
    { (yyval.specTree) = (yyvsp[0].specTree); }
#line 1541 "specParser.c"
    break;

  case 18:
#line 168 "specParser.y"
    { (yyval.specTree) = new_printf((yyvsp[0].string)); }
#line 1547 "specParser.c"
    break;

  case 19:
#line 172 "specParser.y"
    { (yyval.specTree) = add_brother_node((yyvsp[-2].specTree), (yyvsp[0].specTree)); }
#line 1553 "specParser.c"
    break;

  case 20:
#line 173 "specParser.y"
    { (yyval.specTree) = (yyvsp[0].specTree); }
#line 1559 "specParser.c"
    break;

  case 21:
#line 178 "specParser.y"
    {
            ast assign = new_node(AST_ASSIGN);
            add_child_node(assign, new_id((yyvsp[-2].string)));
            add_child_node(assign, (yyvsp[0].specTree));
            (yyval.specTree) = add_child_node((yyvsp[-3].specTree), assign); 
        }
#line 1570 "specParser.c"
    break;

  case 22:
#line 185 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_ASSIGN);
            add_child_node((yyval.specTree), new_id((yyvsp[-2].string)));
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 1580 "specParser.c"
    break;

  case 23:
#line 193 "specParser.y"
    { (yyval.specTree) = add_child_node((yyvsp[-1].specTree), (yyvsp[0].specTree)); }
#line 1586 "specParser.c"
    break;

  case 24:
#line 194 "specParser.y"
    { (yyval.specTree) = (yyvsp[0].specTree); }
#line 1592 "specParser.c"
    break;

  case 25:
#line 198 "specParser.y"
    { (yyval.specTree) = new_node(AST_INT); }
#line 1598 "specParser.c"
    break;

  case 26:
#line 199 "specParser.y"
    { (yyval.specTree) = new_node(AST_DOUBLE); }
#line 1604 "specParser.c"
    break;

  case 27:
#line 200 "specParser.y"
    { (yyval.specTree) = new_node(AST_VOID); }
#line 1610 "specParser.c"
    break;

  case 28:
#line 204 "specParser.y"
    { (yyval.specTree) = add_brother_node((yyvsp[-2].specTree), (yyvsp[0].specTree)); }
#line 1616 "specParser.c"
    break;

  case 29:
#line 205 "specParser.y"
    { (yyval.specTree) = (yyvsp[0].specTree); }
#line 1622 "specParser.c"
    break;

  case 30:
#line 209 "specParser.y"
    { (yyval.specTree) = new_id((yyvsp[0].string)); }
#line 1628 "specParser.c"
    break;

  case 31:
#line 210 "specParser.y"
    { (yyval.specTree) = (yyvsp[0].specTree) ;}
#line 1634 "specParser.c"
    break;

  case 32:
#line 211 "specParser.y"
    { (yyval.specTree) = (yyvsp[0].specTree); }
#line 1640 "specParser.c"
    break;

  case 33:
#line 216 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_TABLE);
            add_child_node((yyval.specTree), new_id((yyvsp[-1].string)));
            ast dimensions = new_node(AST_DIM);
            add_child_node(dimensions, (yyvsp[0].specTree));
            add_child_node((yyval.specTree), dimensions);
        }
#line 1652 "specParser.c"
    break;

  case 34:
#line 224 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_ASSIGN);
            ast table = new_node(AST_TABLE);
            add_child_node(table, new_id((yyvsp[-3].string)));
            ast dimensions = new_node(AST_DIM);
            add_child_node(dimensions, (yyvsp[-2].specTree));
            add_child_node(table, dimensions);
            add_child_node((yyval.specTree), table);
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 1667 "specParser.c"
    break;

  case 35:
#line 235 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_ASSIGN);
            ast table = new_node(AST_TABLE);
            add_child_node(table, new_id((yyvsp[-3].string)));
            ast dimensions = new_node(AST_DIM);
            add_child_node(dimensions, (yyvsp[-2].specTree));
            add_child_node(table, dimensions);
            add_child_node((yyval.specTree), table);
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 1682 "specParser.c"
    break;

  case 36:
#line 249 "specParser.y"
    {
            (yyval.specTree) = add_brother_node((yyvsp[-3].specTree), (yyvsp[-1].specTree));
        }
#line 1690 "specParser.c"
    break;

  case 37:
#line 253 "specParser.y"
    {
            (yyval.specTree) = (yyvsp[-1].specTree);
        }
#line 1698 "specParser.c"
    break;

  case 38:
#line 259 "specParser.y"
    { (yyval.specTree) = add_brother_node((yyvsp[-2].specTree), (yyvsp[0].specTree));  }
#line 1704 "specParser.c"
    break;

  case 39:
#line 260 "specParser.y"
    { (yyval.specTree) = (yyvsp[0].specTree); }
#line 1710 "specParser.c"
    break;

  case 40:
#line 265 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_ARRAY);
            add_child_node((yyval.specTree), (yyvsp[-1].specTree));
        }
#line 1719 "specParser.c"
    break;

  case 41:
#line 270 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_ARRAY);
            add_child_node((yyval.specTree), (yyvsp[-1].specTree));
        }
#line 1728 "specParser.c"
    break;

  case 42:
#line 277 "specParser.y"
    { (yyval.specTree) = add_brother_node((yyvsp[-2].specTree), (yyvsp[0].specTree));  }
#line 1734 "specParser.c"
    break;

  case 43:
#line 278 "specParser.y"
    { (yyval.specTree) = (yyvsp[0].specTree); }
#line 1740 "specParser.c"
    break;

  case 44:
#line 283 "specParser.y"
    {   
            // TODO : REVOIR PRECEDENCE OPERATEUR UNAIRES
            (yyval.specTree) = add_child_node((yyvsp[-1].specTree), new_id((yyvsp[0].string)));
        }
#line 1749 "specParser.c"
    break;

  case 45:
#line 288 "specParser.y"
    {
            // TODO : REVOIR PRECEDENCE OPERATEUR UNAIRES
            (yyval.specTree) = add_child_node((yyvsp[0].specTree), (yyval.specTree) = new_id((yyvsp[-1].string)));
        }
#line 1758 "specParser.c"
    break;

  case 46:
#line 293 "specParser.y"
    {   
            (yyval.specTree) = new_node(AST_ASSIGN);
            add_child_node((yyval.specTree), new_id((yyvsp[-2].string)));
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 1768 "specParser.c"
    break;

  case 47:
#line 302 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_INC);
        }
#line 1776 "specParser.c"
    break;

  case 48:
#line 306 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_DEC);
        }
#line 1784 "specParser.c"
    break;

  case 49:
#line 313 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_IF);
            add_child_node((yyval.specTree), (yyvsp[-4].specTree));

            ast statements = new_list(LIST_STAT);
            add_child_node(statements, (yyvsp[-1].specTree));
            add_child_node((yyval.specTree), statements);
        }
#line 1797 "specParser.c"
    break;

  case 50:
#line 322 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_IF);
            add_child_node((yyval.specTree), (yyvsp[-8].specTree));
            
            ast statements = new_list(LIST_STAT);
            add_child_node(statements, (yyvsp[-5].specTree));
            add_child_node((yyval.specTree), statements);

            statements = new_list(LIST_STAT);
            add_child_node(statements, (yyvsp[-1].specTree));
            add_child_node((yyval.specTree), statements);
        }
#line 1814 "specParser.c"
    break;

  case 51:
#line 338 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_WHILE);

            ast condition = new_list(LIST_COND);
            add_child_node(condition, (yyvsp[-4].specTree));
            add_child_node((yyval.specTree), condition);

            ast statements = new_list(LIST_STAT);
            add_child_node(statements, (yyvsp[-1].specTree));
            add_child_node((yyval.specTree), statements);
        }
#line 1830 "specParser.c"
    break;

  case 52:
#line 350 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_FOR);

            ast init = new_list(LIST_INIT);
            add_child_node(init, (yyvsp[-8].specTree));
            add_child_node((yyval.specTree), init);

            ast condition = new_list(LIST_COND);
            add_child_node(condition, (yyvsp[-6].specTree));
            add_child_node((yyval.specTree), condition);

            ast update = new_list(LIST_UPDATE);
            add_child_node(update, (yyvsp[-4].specTree));
            add_child_node((yyval.specTree), update);

            ast statements = new_list(LIST_STAT);
            add_child_node(statements, (yyvsp[-1].specTree));
            add_child_node((yyval.specTree), statements);
        }
#line 1854 "specParser.c"
    break;

  case 53:
#line 372 "specParser.y"
    { (yyval.specTree) = add_brother_node((yyvsp[-2].specTree), (yyvsp[0].specTree)); }
#line 1860 "specParser.c"
    break;

  case 54:
#line 373 "specParser.y"
    { (yyval.specTree) = (yyvsp[0].specTree); }
#line 1866 "specParser.c"
    break;

  case 55:
#line 378 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_OR_OP);
            add_child_node((yyval.specTree), (yyvsp[-2].specTree));
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 1876 "specParser.c"
    break;

  case 56:
#line 384 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_AND_OP);
            add_child_node((yyval.specTree), (yyvsp[-2].specTree));
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 1886 "specParser.c"
    break;

  case 57:
#line 390 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_GEQ_OP);
            add_child_node((yyval.specTree), (yyvsp[-2].specTree));
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 1896 "specParser.c"
    break;

  case 58:
#line 396 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_GT_OP);
            add_child_node((yyval.specTree), (yyvsp[-2].specTree));
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 1906 "specParser.c"
    break;

  case 59:
#line 402 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_LEQ_OP);
            add_child_node((yyval.specTree), (yyvsp[-2].specTree));
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 1916 "specParser.c"
    break;

  case 60:
#line 408 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_LT_OP);
            add_child_node((yyval.specTree), (yyvsp[-2].specTree));
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 1926 "specParser.c"
    break;

  case 61:
#line 414 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_EQ_OP);
            add_child_node((yyval.specTree), (yyvsp[-2].specTree));
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 1936 "specParser.c"
    break;

  case 62:
#line 420 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_NEQ_OP);
            add_child_node((yyval.specTree), (yyvsp[-2].specTree));
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 1946 "specParser.c"
    break;

  case 63:
#line 426 "specParser.y"
    {
            (yyval.specTree) = (yyvsp[-1].specTree);
        }
#line 1954 "specParser.c"
    break;

  case 64:
#line 433 "specParser.y"
    {
            (yyval.specTree) = add_brother_node((yyvsp[-2].specTree), (yyvsp[0].specTree));
        }
#line 1962 "specParser.c"
    break;

  case 65:
#line 437 "specParser.y"
    {
            (yyval.specTree) = (yyvsp[0].specTree);
        }
#line 1970 "specParser.c"
    break;

  case 66:
#line 444 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_ADD);
            add_child_node((yyval.specTree), (yyvsp[-2].specTree));
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 1980 "specParser.c"
    break;

  case 67:
#line 450 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_MINUS);
            add_child_node((yyval.specTree), (yyvsp[-2].specTree));
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 1990 "specParser.c"
    break;

  case 68:
#line 456 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_MUL);
            add_child_node((yyval.specTree), (yyvsp[-2].specTree));
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 2000 "specParser.c"
    break;

  case 69:
#line 462 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_DIV);
            add_child_node((yyval.specTree), (yyvsp[-2].specTree));
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 2010 "specParser.c"
    break;

  case 70:
#line 468 "specParser.y"
    {
            (yyval.specTree) = (yyvsp[-1].specTree);
        }
#line 2018 "specParser.c"
    break;

  case 71:
#line 472 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_UMINUS);
            add_child_node((yyval.specTree), (yyvsp[0].specTree));
        }
#line 2027 "specParser.c"
    break;

  case 72:
#line 477 "specParser.y"
    {
            (yyval.specTree) = new_id((yyvsp[0].string));
        }
#line 2035 "specParser.c"
    break;

  case 73:
#line 481 "specParser.y"
    {
            (yyval.specTree) = (yyvsp[0].specTree);
        }
#line 2043 "specParser.c"
    break;

  case 74:
#line 485 "specParser.y"
    {
            (yyval.specTree) = new_node(AST_TABLE);
            add_child_node((yyval.specTree), new_id((yyvsp[-1].string)));
            ast dimensions = new_node(AST_DIM);
            add_child_node(dimensions, (yyvsp[0].specTree));
            add_child_node((yyval.specTree), dimensions);
        }
#line 2055 "specParser.c"
    break;

  case 75:
#line 496 "specParser.y"
    {
            (yyval.specTree) = new_int((yyvsp[0].int_val));
        }
#line 2063 "specParser.c"
    break;

  case 76:
#line 500 "specParser.y"
    {
            (yyval.specTree) = new_double((yyvsp[0].double_val));
        }
#line 2071 "specParser.c"
    break;


#line 2075 "specParser.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 505 "specParser.y"


void zzerror (char *s) {
    fprintf(stderr, "[Yacc] error line %d: %s\n", yylineno, s);
}

#ifndef SPEC_PARSER
int main() {

    ////////// parse a test file ///
    FILE* f = fopen ("spec.c", "r");
    if (f == NULL) {
        fprintf(stderr, "Unable to open file");
        return 1;
    }
    yyin = f;
    ////////////////////////////////

    specParser();

    // Affichage de l'specTree 
    print_ast(specTree);

    print_code(specTree, 0);

    // Clean
    delete_node(specTree);
    lex_free();
    fclose(f);

    return 0;
}
#endif
