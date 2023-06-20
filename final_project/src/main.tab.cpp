/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/main.y" /* yacc.c:339  */

    #include "common.h"
    #define YYstype TreeNode *  
    TreeNode* root;
    Node_Stack *top,*bottle;
    extern int lineno;
    extern int depth;
    int yylex();
    int yyerror( char const * );

#line 77 "src/main.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "main.tab.h".  */
#ifndef YY_YY_SRC_MAIN_TAB_H_INCLUDED
# define YY_YY_SRC_MAIN_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_CHAR = 258,
    T_INT = 259,
    T_STRING = 260,
    T_BOOL = 261,
    T_VOID = 262,
    IF = 263,
    MAIN = 264,
    ELSE = 265,
    FOR = 266,
    WHILE = 267,
    PRINTF = 268,
    SCANF = 269,
    BREAK = 270,
    CONTINUE = 271,
    RETURN = 272,
    LBRACE = 273,
    RBRACE = 274,
    SEMI = 275,
    PLUS = 276,
    MINUS = 277,
    TIMES = 278,
    OVER = 279,
    ASSIGN = 280,
    INC = 281,
    DEC = 282,
    MOD = 283,
    LT = 284,
    EQ = 285,
    GT = 286,
    NZ = 287,
    GE = 288,
    LE = 289,
    SHL = 290,
    SAR = 291,
    AND = 292,
    OR = 293,
    OPPSITE = 294,
    LPAREN = 295,
    RPAREN = 296,
    COMMA = 297,
    LSQUARE = 298,
    RSQUARE = 299,
    B_AND = 300,
    IDENTIFIER = 301,
    INTEGER = 302,
    CHAR = 303,
    BOOL = 304,
    STRING = 305,
    CONST = 306,
    OPPOSITE = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MAIN_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 181 "src/main.tab.cpp" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   613

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  264

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    36,    36,    43,    48,    52,    57,    64,    74,    83,
      93,   100,   104,   107,   115,   124,   129,   133,   140,   145,
     148,   149,   153,   157,   163,   173,   178,   181,   191,   196,
     199,   202,   206,   213,   219,   224,   227,   237,   242,   245,
     259,   269,   271,   276,   282,   287,   290,   297,   304,   311,
     318,   325,   329,   334,   338,   347,   357,   364,   369,   374,
     380,   385,   392,   401,   402,   405,   406,   413,   414,   415,
     422,   429,   436,   443,   452,   456,   459,   475,   481,   485,
     492,   501,   505,   512,   519,   528,   532,   539,   545,   551,
     557,   563,   569,   575,   581,   589,   598,   603,   606,   611,
     618,   623,   631,   635,   639,   643,   644,   647,   653,   657,
     661,   671,   675,   679,   688,   692,   696,   703,   712,   716,
     720,   727,   734,   741,   753,   754,   755,   756,   757
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_CHAR", "T_INT", "T_STRING", "T_BOOL",
  "T_VOID", "IF", "MAIN", "ELSE", "FOR", "WHILE", "PRINTF", "SCANF",
  "BREAK", "CONTINUE", "RETURN", "LBRACE", "RBRACE", "SEMI", "PLUS",
  "MINUS", "TIMES", "OVER", "ASSIGN", "INC", "DEC", "MOD", "LT", "EQ",
  "GT", "NZ", "GE", "LE", "SHL", "SAR", "AND", "OR", "OPPSITE", "LPAREN",
  "RPAREN", "COMMA", "LSQUARE", "RSQUARE", "B_AND", "IDENTIFIER",
  "INTEGER", "CHAR", "BOOL", "STRING", "CONST", "OPPOSITE", "$accept",
  "program", "CompUnit", "FuncDef", "FuncFParams", "CommaFuncFParam",
  "FuncFParam", "MultiExp", "Block", "MultiBlockItem", "BlockItem", "Decl",
  "ConstDecl", "CommaConstDef", "ConstDef", "MultiConstExp", "ConstExp",
  "ConstInitVal", "CommaConstInitVal", "VarDecl", "CommaVarDef", "VarDef",
  "InitVal", "CommaInitVal", "Stmt", "Exp1", "Exp2", "Exp3", "ElseStmt",
  "LVal", "Exp", "AddExp", "MulExp", "UnaryExp", "FuncRParams", "CommaExp",
  "UnaryOp", "SpecialUnaryOp", "PrimaryExp", "Cond", "LOrExp", "LAndExp",
  "EqExp", "RelExp", "type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF -146

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-146)))

#define YYTABLE_NINF -78

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,  -146,  -146,  -146,  -146,  -146,   135,    23,  -146,     6,
       6,  -146,  -146,     9,   -21,  -146,  -146,  -146,     1,    29,
       7,    11,    22,    38,    25,   450,    82,    64,    91,   100,
     -21,    96,   109,   109,    73,    88,    85,  -146,  -146,   450,
     450,   450,  -146,    54,  -146,  -146,  -146,  -146,    99,  -146,
    -146,    49,    94,   481,   450,  -146,   153,    11,     7,  -146,
     370,    22,  -146,   220,  -146,  -146,   109,   135,  -146,    92,
    -146,  -146,   103,  -146,   441,   450,  -146,    11,   450,   450,
     450,   450,  -146,  -146,   450,   490,    57,    57,   324,  -146,
    -146,  -146,   359,  -146,  -146,  -146,   105,   110,   112,   130,
     133,   157,   162,   401,  -146,  -146,   113,   220,  -146,  -146,
     136,   164,    64,  -146,  -146,   148,  -146,  -146,   152,   154,
     158,  -146,  -146,  -146,  -146,  -146,  -146,   521,   155,   156,
    -146,   166,    55,    95,  -146,   168,  -146,   169,   490,   270,
     490,   450,   450,  -146,  -146,  -146,   186,  -146,  -146,   182,
     183,   187,   188,   450,  -146,   175,   450,  -146,  -146,   175,
     530,   178,   179,    72,    62,  -146,   490,   530,   530,   521,
     450,   450,   450,   450,   153,   202,   370,   210,  -146,   189,
    -146,  -146,   410,   198,   152,   152,  -146,   450,   450,   450,
     450,   221,  -146,   152,  -146,   561,    -6,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,   168,
    -146,   169,  -146,   313,  -146,   450,   224,   313,   204,   207,
     229,   230,   231,   232,  -146,  -146,   450,    62,  -146,  -146,
     243,   213,   165,  -146,  -146,  -146,   235,   236,  -146,  -146,
    -146,  -146,   178,   313,  -146,   313,   233,   234,   237,   238,
     450,  -146,  -146,  -146,  -146,   450,   450,   450,   450,  -146,
    -146,  -146,  -146,  -146
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   125,   124,   127,   126,   128,     0,     0,     2,     3,
       4,    22,    23,     0,     0,     1,     6,     5,     0,    29,
      38,    29,    26,     0,     0,     0,    39,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     0,    98,   100,     0,
       0,     0,   101,    16,   104,   105,   106,    99,     0,   103,
      30,    78,    81,     0,     0,    85,     0,    29,    38,    36,
       0,    26,    24,    19,     9,     8,     0,     0,    10,    14,
      91,    92,     0,    77,     0,     0,    76,    29,     0,     0,
       0,     0,    93,    94,     0,     0,    88,    90,     0,    40,
      41,    37,     0,    31,    27,    25,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,     0,    19,    21,    20,
     103,     0,     0,     7,    11,     0,   102,    87,    97,     0,
       0,    28,    79,    80,    82,    83,    84,     0,   118,     0,
     107,   108,   111,   114,    43,    45,    33,    35,     0,     0,
       0,     0,     0,    57,    58,    60,     0,    17,    18,     0,
       0,     0,     0,     0,    51,    16,     0,    95,    86,    16,
       0,   118,     0,     0,   114,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,     0,
      63,    64,     0,     0,    97,    97,    59,     0,     0,     0,
       0,     0,    13,    97,    15,     0,     0,   119,   109,   112,
     115,   110,   116,   117,   113,   120,   121,   123,   122,    45,
      42,    35,    32,     0,    66,    68,     0,     0,     0,     0,
       0,     0,     0,     0,    46,    96,     0,     0,    44,    34,
      75,     0,   103,    67,    65,    56,     0,     0,    47,    48,
      49,    50,     0,     0,    54,     0,     0,     0,     0,     0,
       0,    61,    62,    74,    55,     0,     0,     0,     0,    69,
      70,    71,    72,    73
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,    89,  -146,  -146,  -146,   190,   -77,   -13,   172,
    -146,   -55,  -146,   200,   239,   -14,   255,   -86,    53,   150,
     240,   264,   -85,    86,  -137,  -146,  -146,  -146,  -146,   -62,
     -41,    -4,   -38,    -3,  -146,  -145,  -146,  -146,  -146,  -124,
     128,  -110,  -100,  -122,    -2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    34,    68,    35,    76,   105,   106,
     107,    10,    11,    31,    22,    26,    93,    94,   177,    12,
      28,    20,    89,   175,   109,   182,   215,   231,   244,    49,
     111,    73,    51,    52,   119,   157,    53,    54,    55,   129,
     130,   131,   132,   133,    13
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      72,   110,   181,   135,    14,   164,   137,    29,   108,     1,
       2,     3,     4,     5,   179,    90,   183,   162,    18,    64,
      65,    50,    36,    15,   167,    21,   168,   163,     1,     2,
       3,     4,     5,   118,   120,   199,    70,    71,   164,   218,
     219,    23,   124,   125,    72,   110,   126,    90,   225,    27,
      86,    87,   108,   113,    25,    19,    50,     6,   216,   204,
     196,   112,   146,   121,    30,    36,    33,   202,   203,    24,
      78,    79,    25,   227,   122,   123,   230,   110,   192,    32,
     235,   128,   194,    82,    83,   167,    72,   168,    50,   209,
     211,   170,   169,   171,    74,   172,   173,    75,    16,    17,
     184,   185,   167,   200,   168,   112,   253,    56,   254,   169,
      57,    59,   191,   199,    66,   193,    62,    80,    81,    72,
      82,    83,    84,   161,   170,    60,   171,    63,   172,   173,
      67,    69,   147,    90,   178,   115,   178,   112,     1,     2,
       3,     4,     5,    77,   116,   138,   220,   221,   222,   223,
     139,   110,   140,   232,    72,   110,   161,   149,   150,   151,
     152,   153,   178,   178,   178,   178,   205,   206,   207,   208,
     141,    88,    50,   142,   233,    37,    38,   143,   178,    39,
      40,   110,   144,   110,   154,    72,   246,   247,   248,   249,
     250,   161,   155,    41,   156,   158,   -77,   165,    42,    43,
      44,    45,   159,    46,   166,    47,   186,   187,   188,   259,
     174,   176,   189,   190,   260,   261,   262,   263,    75,   197,
     198,   210,   242,     1,     2,     3,     4,     5,    96,   212,
     213,    97,    98,    99,   100,   101,   102,   103,    63,   217,
     104,   224,    37,    38,   234,   236,    39,    40,   237,   238,
     239,   240,   241,   243,   245,   251,   252,   114,   255,   256,
      41,    95,   257,   258,   229,    42,    43,    44,    45,    61,
      46,     6,    47,     1,     2,     3,     4,     5,    96,   148,
      48,    97,    98,    99,   100,   101,   102,   103,    63,   180,
     104,    58,    37,    38,   201,   228,    39,    40,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,     0,    42,    43,    44,    45,     0,
      46,    96,    47,     0,    97,    98,    99,   100,   101,   102,
     103,    63,     0,   104,     0,    37,    38,     0,     0,    39,
      40,     0,    88,   134,     0,     0,    37,    38,     0,     0,
      39,    40,     0,    41,     0,     0,     0,     0,    42,    43,
      44,    45,     0,    46,    41,    47,     0,     0,     0,    42,
      43,    44,    45,     0,    46,     0,    47,    92,   136,     0,
       0,    37,    38,     0,     0,    39,    40,     0,    92,     0,
       0,     0,    37,    38,     0,     0,    39,    40,     0,    41,
       0,     0,     0,     0,    42,    43,    44,    45,     0,    46,
      41,    47,     0,     0,     0,    42,    43,    44,    45,     0,
      46,   145,    47,    37,    38,     0,     0,    39,    40,     0,
     214,     0,    37,    38,     0,     0,    39,    40,     0,     0,
       0,    41,     0,     0,     0,     0,    42,    43,    44,    45,
     127,    46,     0,    47,     0,    42,    43,    44,    45,     0,
      46,     0,    47,    37,    38,     0,     0,    39,    40,     0,
       0,     0,    37,    38,     0,     0,    39,    40,     0,     0,
       0,    41,   117,     0,     0,     0,    42,    43,    44,    45,
      41,    46,     0,    47,     0,    42,    43,    44,    45,     0,
      46,     0,    47,    37,    38,     0,     0,    39,    40,     0,
       0,     0,    37,    38,     0,     0,    39,    40,     0,     0,
       0,    85,     0,     0,     0,     0,    42,    43,    44,    45,
     127,    46,     0,    47,     0,    42,    43,    44,    45,     0,
      46,     0,    47,    37,    38,     0,     0,    39,    40,     0,
       0,     0,    37,    38,     0,     0,    39,    40,     0,     0,
       0,   160,     0,     0,     0,     0,    42,    43,    44,    45,
     195,    46,     0,    47,     0,    42,    43,    44,    45,     0,
      46,     0,    47,    37,    38,     0,     0,    39,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   226,     0,     0,     0,     0,    42,    43,    44,    45,
       0,    46,     0,    47
};

static const yytype_int16 yycheck[] =
{
      41,    63,   139,    88,     6,   127,    92,    21,    63,     3,
       4,     5,     6,     7,   138,    56,   140,   127,     9,    32,
      33,    25,    24,     0,    30,    46,    32,   127,     3,     4,
       5,     6,     7,    74,    75,    41,    39,    40,   160,   184,
     185,    40,    80,    81,    85,   107,    84,    88,   193,    42,
      53,    54,   107,    66,    43,    46,    60,    51,   182,   169,
     160,    63,   103,    77,    42,    67,    41,   167,   168,    40,
      21,    22,    43,   195,    78,    79,   213,   139,   155,    41,
     217,    85,   159,    26,    27,    30,   127,    32,    92,   174,
     176,    29,    37,    31,    40,    33,    34,    43,     9,    10,
     141,   142,    30,    41,    32,   107,   243,    25,   245,    37,
      46,    20,   153,    41,    41,   156,    20,    23,    24,   160,
      26,    27,    28,   127,    29,    25,    31,    18,    33,    34,
      42,    46,    19,   174,   138,    43,   140,   139,     3,     4,
       5,     6,     7,    44,    41,    40,   187,   188,   189,   190,
      40,   213,    40,   215,   195,   217,   160,    21,    22,    23,
      24,    25,   166,   167,   168,   169,   170,   171,   172,   173,
      40,    18,   176,    40,   215,    22,    23,    20,   182,    26,
      27,   243,    20,   245,    20,   226,    21,    22,    23,    24,
      25,   195,    44,    40,    42,    41,    41,    41,    45,    46,
      47,    48,    44,    50,    38,    52,    20,    25,    25,   250,
      42,    42,    25,    25,   255,   256,   257,   258,    43,    41,
      41,    19,   226,     3,     4,     5,     6,     7,     8,    19,
      41,    11,    12,    13,    14,    15,    16,    17,    18,    41,
      20,    20,    22,    23,    20,    41,    26,    27,    41,    20,
      20,    20,    20,    10,    41,    20,    20,    67,    25,    25,
      40,    61,    25,    25,   211,    45,    46,    47,    48,    30,
      50,    51,    52,     3,     4,     5,     6,     7,     8,   107,
      25,    11,    12,    13,    14,    15,    16,    17,    18,   139,
      20,    27,    22,    23,   166,   209,    26,    27,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    -1,
      50,     8,    52,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    20,    -1,    22,    23,    -1,    -1,    26,
      27,    -1,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      26,    27,    -1,    40,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    -1,    50,    40,    52,    -1,    -1,    -1,    45,
      46,    47,    48,    -1,    50,    -1,    52,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    26,    27,    -1,    18,    -1,
      -1,    -1,    22,    23,    -1,    -1,    26,    27,    -1,    40,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    -1,    50,
      40,    52,    -1,    -1,    -1,    45,    46,    47,    48,    -1,
      50,    20,    52,    22,    23,    -1,    -1,    26,    27,    -1,
      20,    -1,    22,    23,    -1,    -1,    26,    27,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      40,    50,    -1,    52,    -1,    45,    46,    47,    48,    -1,
      50,    -1,    52,    22,    23,    -1,    -1,    26,    27,    -1,
      -1,    -1,    22,    23,    -1,    -1,    26,    27,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    45,    46,    47,    48,
      40,    50,    -1,    52,    -1,    45,    46,    47,    48,    -1,
      50,    -1,    52,    22,    23,    -1,    -1,    26,    27,    -1,
      -1,    -1,    22,    23,    -1,    -1,    26,    27,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      40,    50,    -1,    52,    -1,    45,    46,    47,    48,    -1,
      50,    -1,    52,    22,    23,    -1,    -1,    26,    27,    -1,
      -1,    -1,    22,    23,    -1,    -1,    26,    27,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      40,    50,    -1,    52,    -1,    45,    46,    47,    48,    -1,
      50,    -1,    52,    22,    23,    -1,    -1,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      -1,    50,    -1,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    51,    54,    55,    56,
      64,    65,    72,    97,    97,     0,    55,    55,     9,    46,
      74,    46,    67,    40,    40,    43,    68,    42,    73,    68,
      42,    66,    41,    41,    57,    59,    97,    22,    23,    26,
      27,    40,    45,    46,    47,    48,    50,    52,    69,    82,
      84,    85,    86,    89,    90,    91,    25,    46,    74,    20,
      25,    67,    20,    18,    61,    61,    41,    42,    58,    46,
      86,    86,    83,    84,    40,    43,    60,    44,    21,    22,
      23,    24,    26,    27,    28,    40,    86,    86,    18,    75,
      83,    73,    18,    69,    70,    66,     8,    11,    12,    13,
      14,    15,    16,    17,    20,    61,    62,    63,    64,    77,
      82,    83,    97,    61,    59,    43,    41,    41,    83,    87,
      83,    68,    84,    84,    85,    85,    85,    40,    84,    92,
      93,    94,    95,    96,    19,    75,    19,    70,    40,    40,
      40,    40,    40,    20,    20,    20,    83,    19,    62,    21,
      22,    23,    24,    25,    20,    44,    42,    88,    41,    44,
      40,    84,    94,    95,    96,    41,    38,    30,    32,    37,
      29,    31,    33,    34,    42,    76,    42,    71,    84,    92,
      72,    77,    78,    92,    83,    83,    20,    25,    25,    25,
      25,    83,    60,    83,    60,    40,    95,    41,    41,    41,
      41,    93,    95,    95,    94,    84,    84,    84,    84,    75,
      19,    70,    19,    41,    20,    79,    92,    41,    88,    88,
      83,    83,    83,    83,    20,    88,    40,    96,    76,    71,
      77,    80,    82,    83,    20,    77,    41,    41,    20,    20,
      20,    20,    84,    10,    81,    41,    21,    22,    23,    24,
      25,    20,    20,    77,    77,    25,    25,    25,    25,    83,
      83,    83,    83,    83
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    55,    55,    56,    56,    56,
      57,    58,    58,    59,    59,    60,    60,    61,    62,    62,
      63,    63,    64,    64,    65,    66,    66,    67,    68,    68,
      69,    70,    70,    70,    71,    71,    72,    73,    73,    74,
      74,    75,    75,    75,    76,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    78,    79,    79,    80,    80,    80,
      80,    80,    80,    80,    81,    81,    82,    83,    84,    84,
      84,    85,    85,    85,    85,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    87,    88,    88,    89,    89,
      90,    90,    91,    91,    91,    91,    91,    92,    93,    93,
      93,    94,    94,    94,    95,    95,    95,    95,    96,    96,
      96,    96,    96,    96,    97,    97,    97,    97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     6,     5,     5,
       2,     2,     0,     5,     2,     4,     0,     3,     2,     0,
       1,     1,     1,     1,     5,     3,     0,     4,     4,     0,
       1,     1,     4,     2,     3,     0,     4,     3,     0,     2,
       4,     1,     4,     2,     3,     0,     4,     5,     5,     5,
       5,     2,     1,     1,     6,     7,     5,     2,     2,     3,
       2,     6,     6,     1,     1,     2,     1,     1,     0,     3,
       4,     4,     4,     4,     2,     0,     2,     1,     1,     3,
       3,     1,     3,     3,     3,     1,     4,     3,     2,     4,
       2,     2,     2,     2,     2,     2,     3,     0,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
            /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
| yyreduce -- Do a reduction.  |
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
#line 37 "src/main.y" /* yacc.c:1646  */
    {
    root=new TreeNode((yyvsp[0])->lineno,NODE_PROG);
    root->addChild((yyvsp[0]));
}
#line 1516 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 44 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[0])->lineno,NODE_COMP);
    (yyval)->addChild((yyvsp[0]));
}
#line 1525 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 49 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 1533 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 53 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-1]);
    (yyval)->addSibling((yyvsp[0]));
}
#line 1542 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 58 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-1]);
    (yyval)->addSibling((yyvsp[0]));
}
#line 1551 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 65 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-5])->lineno,NODE_FUNC);
    (yyval)->type=new Type(COMPOSE_FUNCTION);
    (yyval)->var_name=(yyvsp[-4])->var_name;
    (yyval)->addChild((yyvsp[-5]));
    (yyval)->addChild((yyvsp[-4]));
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 1565 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 75 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-4])->lineno,NODE_FUNC);
    (yyval)->type=new Type(COMPOSE_FUNCTION);
    (yyval)->var_name=(yyvsp[-3])->var_name;
    (yyval)->addChild((yyvsp[-4]));
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[0]));
}
#line 1578 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 84 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-4])->lineno,NODE_FUNC);
    (yyval)->type=new Type(COMPOSE_FUNCTION);
    (yyval)->var_name="main";
    (yyval)->addChild((yyvsp[-4]));
    (yyval)->addChild((yyvsp[0]));
}
#line 1590 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 94 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-1]);
    (yyval)->addSibling((yyvsp[0]));
}
#line 1599 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 101 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 1607 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 104 "src/main.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1613 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 108 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-4])->lineno,NODE_STMT);
    (yyval)->stype=STMT_DECL;
    (yyval)->addChild((yyvsp[-4]));
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[0]));
}
#line 1625 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 116 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode(lineno,NODE_STMT);
    (yyval)->stype=STMT_DECL;
    (yyval)->addChild((yyvsp[-1]));
    (yyval)->addChild((yyvsp[0]));    
}
#line 1636 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 125 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-2]);
    (yyval)->addSibling((yyvsp[0]));
}
#line 1645 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 129 "src/main.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1651 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 134 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode(lineno,NODE_BLOCK);
    (yyval)->addChild((yyvsp[-1]));
}
#line 1660 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 141 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-1]);
    (yyval)->addSibling((yyvsp[0]));
}
#line 1669 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 145 "src/main.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1675 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 148 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1681 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 149 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1687 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 154 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 1695 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 158 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 1703 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 164 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode(lineno,NODE_STMT);
    (yyval)->stype=STMT_DECL;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[-1]));
}
#line 1715 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 174 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-1]);
    (yyval)->addSibling((yyvsp[0]));
}
#line 1724 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 178 "src/main.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1730 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 182 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode(lineno,NODE_EXPR);
    (yyval)->optype=OP_assign;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 1742 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 192 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-2]);
    (yyval)->addSibling((yyvsp[0]));
}
#line 1751 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 196 "src/main.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1757 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 199 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1763 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 203 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 1771 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 207 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_STMT);
    (yyval)->stype=STMT_DECL;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[-1]));
}
#line 1782 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 214 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=NULL;
}
#line 1790 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 220 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-1]);
    (yyval)->addSibling((yyvsp[0]));
}
#line 1799 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 224 "src/main.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1805 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 228 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode(lineno,NODE_STMT);
    (yyval)->stype=STMT_DECL;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[-1]));
}
#line 1817 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 238 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-1]);
    (yyval)->addSibling((yyvsp[0]));
}
#line 1826 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 242 "src/main.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1832 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 246 "src/main.y" /* yacc.c:1646  */
    {
    if((yyvsp[0])!=NULL)
    {
        (yyval)=new TreeNode(lineno,NODE_TYPE);
        (yyval)->type=new Type(COMPOSE_ARRAY);
        (yyval)->addChild((yyvsp[-1]));
        (yyval)->addChild((yyvsp[0]));
    }
    else 
    {
        (yyval)=(yyvsp[-1]);
    }
}
#line 1850 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 260 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode(lineno,NODE_EXPR);
    (yyval)->optype=OP_assign;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));    
}
#line 1862 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 270 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1868 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 272 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-2]);
    (yyval)->addSibling((yyvsp[-1]));
}
#line 1877 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 277 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=NULL;
}
#line 1885 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 283 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-1]);
    (yyval)->addSibling((yyvsp[0]));
}
#line 1894 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 287 "src/main.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1900 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 291 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-3])->lineno,NODE_EXPR);
    (yyval)->optype=OP_assign;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[-1]));
}
#line 1911 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 298 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-4])->lineno,NODE_EXPR);
    (yyval)->optype=OP_plus_assign;
    (yyval)->addChild((yyvsp[-4]));
    (yyval)->addChild((yyvsp[-1]));
}
#line 1922 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 305 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-4])->lineno,NODE_EXPR);
    (yyval)->optype=OP_minus_assign;
    (yyval)->addChild((yyvsp[-4]));
    (yyval)->addChild((yyvsp[-1]));
}
#line 1933 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 312 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-4])->lineno,NODE_EXPR);
    (yyval)->optype=OP_times_assign;
    (yyval)->addChild((yyvsp[-4]));
    (yyval)->addChild((yyvsp[-1]));
}
#line 1944 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 319 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-4])->lineno,NODE_EXPR);
    (yyval)->optype=OP_over_assign;
    (yyval)->addChild((yyvsp[-4]));
    (yyval)->addChild((yyvsp[-1]));
}
#line 1955 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 326 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-1]);
}
#line 1963 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 330 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode(lineno,NODE_STMT);
    (yyval)->stype=STMT_SKIP;
}
#line 1972 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 335 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 1980 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 339 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode *node=new TreeNode((yyvsp[-3])->lineno,NODE_STMT);
    node->stype=STMT_IF;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    node->addChild((yyvsp[0]));
    (yyval)=node;
}
#line 1993 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 348 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode *node=new TreeNode((yyvsp[-4])->lineno,NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild((yyvsp[-4]));
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval)=node;
}
#line 2007 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 358 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_STMT);
    (yyval)->stype=STMT_WHILE;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2018 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 365 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode(lineno,NODE_STMT);
    (yyval)->stype=STMT_BREAK;
}
#line 2027 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 370 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode(lineno,NODE_STMT);
    (yyval)->stype=STMT_CONTINUE;
}
#line 2036 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 375 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode(lineno,NODE_STMT);
    (yyval)->stype=STMT_RETURN;
    (yyval)->addChild((yyvsp[-1]));
}
#line 2046 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 381 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode(lineno,NODE_STMT);
    (yyval)->stype=STMT_RETURN;
}
#line 2055 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 386 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-3])->lineno,NODE_STMT);
    (yyval)->stype=STMT_PRINTF;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[-2]));
}
#line 2066 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 393 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-3])->lineno,NODE_STMT);
    (yyval)->stype=STMT_SCANF;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[-2]));
}
#line 2077 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 401 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2083 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 402 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2089 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 405 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 2095 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 407 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode(lineno,NODE_STMT);
    (yyval)->stype=STMT_SKIP;
}
#line 2104 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 413 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2110 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 414 "src/main.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 2116 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 416 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_EXPR);
    (yyval)->optype=OP_assign;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2127 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 423 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-3])->lineno,NODE_EXPR);
    (yyval)->optype=OP_plus_assign;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2138 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 430 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-3])->lineno,NODE_EXPR);
    (yyval)->optype=OP_minus_assign;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2149 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 437 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-3])->lineno,NODE_EXPR);
    (yyval)->optype=OP_times_assign;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2160 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 444 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-3])->lineno,NODE_EXPR);
    (yyval)->optype=OP_over_assign;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2171 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 453 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 2179 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 456 "src/main.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 2185 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 460 "src/main.y" /* yacc.c:1646  */
    {
    if((yyvsp[0])!=NULL)
    {
        (yyval)=new TreeNode((yyvsp[-1])->lineno,NODE_STMT);  //需要改，暂时用不到
        (yyval)->stype=STMT_DECL;
        (yyval)->addChild((yyvsp[-1]));
        (yyval)->addChild((yyvsp[0]));
    }
    else 
    {
        (yyval)=(yyvsp[-1]);
    }
}
#line 2203 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 476 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 2211 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 482 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 2219 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 486 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_EXPR);
    (yyval)->optype=OP_plus;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2230 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 493 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_EXPR);
    (yyval)->optype=OP_minus;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2241 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 502 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 2249 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 506 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_EXPR);
    (yyval)->optype=OP_times;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2260 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 513 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_EXPR);
    (yyval)->optype=OP_over;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2271 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 520 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_EXPR);
    (yyval)->optype=OP_mod;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2282 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 529 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 2290 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 533 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-3])->lineno,NODE_STMT);
    (yyval)->stype=STMT_DECL;
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[-1]));    
}
#line 2301 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 540 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_STMT);
    (yyval)->stype=STMT_DECL;
    (yyval)->addChild((yyvsp[-2]));   
}
#line 2311 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 546 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-1])->lineno,NODE_UNARY_EXPR);
    (yyval)->addChild((yyvsp[-1]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2321 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 552 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-3])->lineno,NODE_UNARY_EXPR);
    (yyval)->addChild((yyvsp[-3]));
    (yyval)->addChild((yyvsp[-1]));
}
#line 2331 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 558 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-1])->lineno,NODE_UNARY_EXPR);
    (yyval)->addChild((yyvsp[-1]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2341 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 564 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-1])->lineno,NODE_EXPR);
    (yyval)->optype=OP_pre_inc;
    (yyval)->addChild((yyvsp[0]));    
}
#line 2351 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 570 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-1])->lineno,NODE_EXPR);
    (yyval)->optype=OP_pre_dec;
    (yyval)->addChild((yyvsp[0]));    
}
#line 2361 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 576 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-1])->lineno,NODE_EXPR);
    (yyval)->optype=OP_suf_inc;
    (yyval)->addChild((yyvsp[-1]));    
}
#line 2371 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 582 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-1])->lineno,NODE_EXPR);
    (yyval)->optype=OP_suf_inc;
    (yyval)->addChild((yyvsp[-1]));    
}
#line 2381 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 590 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-1])->lineno,NODE_STMT);   //需要改，暂时用不到
    (yyval)->stype=STMT_DECL;
    (yyval)->addChild((yyvsp[-1]));
    (yyval)->addChild((yyvsp[0]));    
}
#line 2392 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 599 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-1]);
    (yyval)->addSibling((yyvsp[0]));
}
#line 2401 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 603 "src/main.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 2407 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 607 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[0])->lineno,NODE_EXPR);
    (yyval)->optype=OP_uminus;    
}
#line 2416 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 612 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[0])->lineno,NODE_EXPR);
    (yyval)->optype=OP_opposite;    
}
#line 2425 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 619 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[0])->lineno,NODE_EXPR);
    (yyval)->optype=OP_get_context;
}
#line 2434 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 624 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[0])->lineno,NODE_EXPR);
    (yyval)->optype=OP_get_address;
}
#line 2443 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 632 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-1]);
}
#line 2451 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 636 "src/main.y" /* yacc.c:1646  */
    { 
    (yyval) = (yyvsp[0]);
}
#line 2459 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 640 "src/main.y" /* yacc.c:1646  */
    { 
    (yyval) = (yyvsp[0]);
}
#line 2467 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 643 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2473 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 644 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2479 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 648 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 2487 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 654 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 2495 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 658 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-1]);
}
#line 2503 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 662 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_EXPR);
    (yyval)->optype=OP_or;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2514 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 672 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 2522 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 676 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-1]);
}
#line 2530 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 680 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_EXPR);
    (yyval)->optype=OP_and;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));    
}
#line 2541 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 689 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 2549 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 693 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-1]);
}
#line 2557 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 697 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_EXPR);
    (yyval)->optype=OP_eq;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2568 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 704 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_EXPR);
    (yyval)->optype=OP_nz;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2579 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 713 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 2587 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 717 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[-1]);
}
#line 2595 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 721 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_EXPR);
    (yyval)->optype=OP_lt;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2606 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 728 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_EXPR);
    (yyval)->optype=OP_gt;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2617 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 735 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_EXPR);
    (yyval)->optype=OP_le;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2628 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 742 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_EXPR);
    (yyval)->optype=OP_ge;
    (yyval)->addChild((yyvsp[-2]));
    (yyval)->addChild((yyvsp[0]));
}
#line 2639 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 753 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_INT;(yyval)->check_type=IntegerT;}
#line 2645 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 754 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_CHAR;(yyval)->check_type=CharT;}
#line 2651 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 755 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_BOOL;(yyval)->check_type=BooleanT;}
#line 2657 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 756 "src/main.y" /* yacc.c:1646  */
    {(yyval)=new TreeNode(lineno,NODE_TYPE);(yyval)->type=TYPE_STRING;(yyval)->check_type=StringT;}
#line 2663 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 757 "src/main.y" /* yacc.c:1646  */
    {(yyval)=new TreeNode(lineno,NODE_TYPE);(yyval)->type=TYPE_VOID;(yyval)->check_type=VoidT;}
#line 2669 "src/main.tab.cpp" /* yacc.c:1646  */
    break;


#line 2673 "src/main.tab.cpp" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
#line 760 "src/main.y" /* yacc.c:1906  */


int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
