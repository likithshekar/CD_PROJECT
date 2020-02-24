/* A Bison parser, made by GNU Bison 3.3.2.  */

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
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "c_yacc.y" /* yacc.c:337  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#define LIMIT 1024
	#define MAX_SYMBOLS 100			// defines max no of record in each symbol table
	#define MAX_SCOPE 10			// defines max no of scopes allowed 
	#define NEWSCOPE 1			// denoted new scope
	#define OLDSCOPE 0			// denotes old scope
	#define NO_OF_KEYWORD 11		// denotes no of keywords
	#define LENGTH_OF_KEYWORDS 7	        // max length of keyword string
	#define MAX_MEMBER 10			// max number of member in struct
	#define TYPE_LENGTH 6			// length of type int float void ....
	#define MAX_NO_OF_STRUCT 10		// max_no of structure which can be defined in a scope
	#define STRUCT_FLAG 2			// Flag to know struct which is declared
	
	
	/* the start index for the member of nested struct in the parent struct  initialized at nested_struct rule */ 
	int nested_struct_start_index;
	
	// keyword_Array
	char keywords[NO_OF_KEYWORD][LENGTH_OF_KEYWORDS] = {"char","int","float","bool","if","else","elseif","for","while","break","return"};
	int c = 0;
	int scope = NEWSCOPE;
	void yyerror(const char*);
	int yylex();
	
	// used for ternary construct to denote if condition is true or false
	int ternary_flag = 0;

	// flag to mark if the varaible is not_defined. Used to decide wheather to push the value in the symbol table or not.
	// 1 => the varaible is not defined.
	int not_defined = 0;
	
	int error = 0;
	struct symbol {
		char name[LIMIT];
		char type[LIMIT];
		char value[LIMIT];
	};
	
	struct struct_data{
		char struct_name[LIMIT];
		char member_type[MAX_MEMBER][TYPE_LENGTH];
		char member_name[MAX_MEMBER][LIMIT];
		int index_to_insert_member;				// to know at which index do we have to insert new member
	};
	
	struct stack_for_symbol_tables{
		int index_to_insert;
		int struct_index_to_insert;
		struct struct_data struct_defined[MAX_NO_OF_STRUCT];
		struct symbol symbol_table[MAX_SYMBOLS];
	}symbol_table_stack[MAX_SCOPE];
	
	/* used if know if struct is used as member to declare a variable of its type
	   1 means used 
	*/
	int struct_reference_used = 0;
	
	int top_stack_for_symbol_tables = -1;
	
	// called to perform all artihmatic operations
	void fun(char *result ,char *arg1,char *arg2,char *arg3);
	
	/* called to push the varaibles in the current scope */
	int push_my(char *type,char *name,char *value,int flag);

	/* to pop the scope */
	int pop_my();
	
	/* to check if the varaible of current scope is declared or not
	   return value 1 if not else -1; 
	*/
	int search_my(char *name,int flag);
	
	/* to display the current scope */
	void display();
	void display_struct();
	
	void struct_member(char *type,char *name);
	
	
	/*  update the value of of varaible in symbol table by first checking if varaible is defined or not
		if not defined then this function return value -1  */
	int update_variable_value(char *name,char *value);
	
	int add_struct_member_in_symbol_table(char *struct_name);
	
	/*
		to check if the varaibles in an expression are defined or not
		return type is array of varaibles that are not defined.
	*/
	void check(char *arg1,char *arg3);
	
	void coercion(char *type,char *value);
	
	void init_symbol_table();
	
	void write_to_file();


#line 174 "y.tab.c" /* yacc.c:337  */
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

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ASSIGN = 258,
    LE = 259,
    GE = 260,
    EQ = 261,
    NE = 262,
    LT = 263,
    GT = 264,
    ADD = 265,
    SUB = 266,
    MUL = 267,
    DIV = 268,
    AND = 269,
    OR = 270,
    NOT = 271,
    HASH = 272,
    INCLUDE = 273,
    DEFINE = 274,
    STDIO = 275,
    STDLIB = 276,
    MATH = 277,
    STRING = 278,
    TIME = 279,
    STRING_LITERAL = 280,
    HEADER_LITERAL = 281,
    charconst = 282,
    stringconst = 283,
    MOD = 284,
    SADD = 285,
    SSUB = 286,
    SMUL = 287,
    SDIV = 288,
    SMOD = 289,
    INC = 290,
    DEC = 291,
    IF = 292,
    ELSE = 293,
    ELSEIF = 294,
    FOR = 295,
    WHILE = 296,
    BREAK = 297,
    RETURN = 298,
    INT = 299,
    CHAR = 300,
    FLOAT = 301,
    BOOL = 302,
    ID = 303,
    numconst = 304,
    delimiter = 305,
    SEMI = 306,
    COMMA = 307,
    NL = 308,
    OP = 309,
    CP = 310,
    OB = 311,
    CB = 312,
    OS = 313,
    CS = 314
  };
#endif
/* Tokens.  */
#define ASSIGN 258
#define LE 259
#define GE 260
#define EQ 261
#define NE 262
#define LT 263
#define GT 264
#define ADD 265
#define SUB 266
#define MUL 267
#define DIV 268
#define AND 269
#define OR 270
#define NOT 271
#define HASH 272
#define INCLUDE 273
#define DEFINE 274
#define STDIO 275
#define STDLIB 276
#define MATH 277
#define STRING 278
#define TIME 279
#define STRING_LITERAL 280
#define HEADER_LITERAL 281
#define charconst 282
#define stringconst 283
#define MOD 284
#define SADD 285
#define SSUB 286
#define SMUL 287
#define SDIV 288
#define SMOD 289
#define INC 290
#define DEC 291
#define IF 292
#define ELSE 293
#define ELSEIF 294
#define FOR 295
#define WHILE 296
#define BREAK 297
#define RETURN 298
#define INT 299
#define CHAR 300
#define FLOAT 301
#define BOOL 302
#define ID 303
#define numconst 304
#define delimiter 305
#define SEMI 306
#define COMMA 307
#define NL 308
#define OP 309
#define CP 310
#define OB 311
#define CB 312
#define OS 313
#define CS 314

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 113 "c_yacc.y" /* yacc.c:352  */

	int ival;
	char string[128];

#line 340 "y.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#define YYFINAL  66
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   447

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

#define YYUNDEFTOK  2
#define YYMAXUTOK   314

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
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   136,   136,   137,   139,   140,   142,   143,   145,   146,
     147,   148,   149,   151,   152,   153,   155,   156,   158,   181,
     205,   206,   207,   208,   210,   211,   213,   216,   222,   223,
     224,   225,   226,   227,   229,   230,   232,   233,   235,   237,
     238,   240,   241,   243,   244,   246,   247,   249,   250,   251,
     252,   253,   254,   256,   257,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   272,   273,   275,
     276,   278,   279,   281,   285,   287,   288,   289,   290,   291,
     292,   294,   298,   300,   301,   303,   307,   309,   310,   311,
     313,   314,   316,   317,   319,   320,   322,   323,   325,   345,
     346,   348,   349,   350,   352,   353,   355,   356,   357
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "LE", "GE", "EQ", "NE", "LT",
  "GT", "ADD", "SUB", "MUL", "DIV", "AND", "OR", "NOT", "HASH", "INCLUDE",
  "DEFINE", "STDIO", "STDLIB", "MATH", "STRING", "TIME", "STRING_LITERAL",
  "HEADER_LITERAL", "charconst", "stringconst", "MOD", "SADD", "SSUB",
  "SMUL", "SDIV", "SMOD", "INC", "DEC", "IF", "ELSE", "ELSEIF", "FOR",
  "WHILE", "BREAK", "RETURN", "INT", "CHAR", "FLOAT", "BOOL", "ID",
  "numconst", "delimiter", "SEMI", "COMMA", "NL", "OP", "CP", "OB", "CB",
  "OS", "CS", "$accept", "external", "s", "headers", "libraries",
  "program", "declarationList", "varDeclaration", "scopedVarDeclaration",
  "typeSpecifier", "varDeclList", "varDeclInitialize", "statement",
  "expressionStmt", "compoundStmt", "new_scope", "new_scope_end",
  "localDeclarations", "statementList", "elsifList", "selectionStmt",
  "iterationStmt", "returnStmt", "breakStmt", "expression",
  "simpleExpression", "andExpression", "unaryRelExpression",
  "relExpression", "relop", "sumExpression", "sumop", "mulExpression",
  "mulop", "unaryExpression", "unaryop", "factor", "mutable", "immutable",
  "call", "args", "argList", "constant", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF -54

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-54)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     220,   -54,   -54,   383,    -8,   -54,   -54,   -32,   -32,   383,
     -34,   -11,     8,   365,   -54,   -54,   -54,   -54,     5,   -54,
     -54,   393,   -54,   144,   -54,   -54,   301,    62,   -54,     3,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,    18,    26,    55,
     -54,   -54,   198,    13,   -54,    65,   -54,     4,   -54,   -54,
     -54,   -54,    12,     1,   -54,    12,    12,   266,   -37,   383,
     -54,   -54,    22,   393,    29,   -54,   -54,   -54,   -54,   -54,
      70,   -35,   -54,   -54,   383,   383,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,    65,    65,   -54,   -54,   -54,    65,
     -54,   393,   393,   393,   393,   393,   393,   -54,   -54,   393,
      33,   -54,   -54,    17,    35,    -9,   -54,   -54,    32,    36,
     -54,    62,   383,   -54,     3,    55,   -54,    20,    13,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,    38,   -54,   -54,   -54,
     -54,   -54,    82,    25,    39,    -3,   383,   301,   -54,   393,
     -54,     3,   185,    26,   -54,   -54,   -54,   301,   383,   301,
     104,    -1,   -54,   -54,   -31,   -54,   -54,   -54,   266,   -54,
     301,    40,   336,   -54,   -54,   -54,   -54,   301,   301,    43,
     -54,   -54,   301,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    92,    93,     0,     0,   107,   108,     0,     0,     0,
       0,     0,     0,     0,    20,    21,    22,    23,    96,   106,
      35,     0,    37,     0,     2,     4,     5,    13,    17,     0,
      15,    28,    29,    30,    31,    32,    33,     0,    66,    68,
      70,    72,    74,    82,    86,     0,    91,    95,    94,    99,
     100,    71,    95,     0,    96,    64,    65,     0,     0,     0,
      55,    53,     0,   103,     0,    40,     1,     3,    14,    16,
      26,     0,    25,    34,     0,     0,    75,    78,    79,    80,
      76,    77,    83,    84,     0,     0,    87,    88,    89,     0,
      90,     0,     0,     0,     0,     0,     0,    62,    63,     0,
       0,     6,    44,     0,     0,     0,    54,   105,     0,   102,
      98,    42,     0,    18,     0,    67,    69,    73,    81,    85,
      56,    57,    58,    59,    60,    61,     0,     8,     9,    10,
      11,    12,     0,    45,     0,     0,     0,     0,   101,     0,
      39,     0,     0,    27,    24,    97,     7,     0,     0,     0,
       0,     0,    47,   104,     0,    38,    41,    46,     0,    52,
       0,     0,     0,    19,    36,    43,    51,     0,     0,     0,
      49,    50,     0,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -54,    78,   -54,   -54,   -54,   -54,    75,   -54,    10,
     -38,   -53,   -25,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -13,    -7,    37,     0,   -54,   -54,
      41,   -54,    45,   -54,   -41,   -54,   -54,    15,   -54,   -54,
     -54,   -54,   -54
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,    25,   132,    26,    27,    28,   140,    29,
      71,    72,    30,    31,    32,    65,   164,   111,   142,   133,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    84,
      42,    85,    43,    89,    44,    45,    46,    47,    48,    49,
     108,   109,    50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      62,    68,    57,    51,    90,   104,    74,    91,    64,   100,
      53,    70,    74,   103,    74,   113,    54,   114,    52,   163,
      58,   114,    55,    56,    52,    86,    87,   101,     1,     2,
      82,    83,   102,     3,    92,    93,    94,    95,    96,    97,
      98,    74,    88,    59,     5,     6,   137,   150,   119,   162,
     107,    70,   105,   127,   128,   129,   130,   131,    60,    63,
      52,   144,    99,   147,   148,    18,    19,   134,    73,    75,
      99,    21,   106,   112,    52,   116,     1,     2,   120,   121,
     122,   123,   124,   125,   110,   136,   126,   138,   139,    52,
      52,   146,     5,     6,   149,   167,   135,   145,   172,    52,
      52,    67,    69,   154,    52,   143,    14,    15,    16,    17,
       0,   115,   152,    18,    19,     1,     2,   156,    52,    21,
       3,   141,   157,     0,   159,   117,   153,    52,     0,   151,
     118,     5,     6,   165,     0,   166,     0,   161,     0,     7,
       8,   158,   170,   171,    66,     0,     0,   173,     0,   169,
       0,    52,    18,    19,     0,     1,     2,     0,    21,   160,
       3,     4,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     5,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     1,     2,    21,     0,
      22,     3,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     0,     5,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,     0,    10,    11,    12,    13,     0,
       0,     1,     2,    18,    19,    20,     3,     4,     0,    21,
       0,    22,   155,     0,     0,     0,     0,     5,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,     0,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,    21,     0,    22,     1,     2,     0,
       0,    74,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     9,     0,     0,    10,    11,    12,    13,
       0,     0,     1,     2,    18,    19,    20,     3,     0,     0,
      21,     0,    22,     0,     0,     0,     0,     0,     5,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,     0,
       0,    10,    11,    12,    13,     0,     0,     1,     2,    18,
      19,    20,     3,     0,     0,    21,     0,    22,     0,     0,
       0,     0,     0,     5,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     1,     2,     0,     0,
       0,     3,     0,     0,    18,    19,     0,     0,     0,     0,
      21,   168,     5,     6,     1,     2,     0,     0,     0,     3,
       7,     8,     0,     0,     1,     2,     0,     0,     0,     3,
       5,     6,     0,    18,    19,    61,     0,     0,     0,    21,
       5,     6,     0,     0,     0,     0,     0,     0,     7,     8,
       0,    18,    19,     0,     0,     0,     0,    21,     0,     0,
       0,    18,    19,     0,     0,     0,     0,    21
};

static const yytype_int16 yycheck[] =
{
      13,    26,     9,     3,    45,    58,    15,     3,    21,     8,
      18,    48,    15,    50,    15,    50,    48,    52,     3,    50,
      54,    52,     7,     8,     9,    12,    13,    26,    11,    12,
      10,    11,    57,    16,    30,    31,    32,    33,    34,    35,
      36,    15,    29,    54,    27,    28,    55,    50,    89,    50,
      63,    48,    59,    20,    21,    22,    23,    24,    50,    54,
      45,   114,    58,    38,    39,    48,    49,    50,    50,    14,
      58,    54,    50,     3,    59,    75,    11,    12,    91,    92,
      93,    94,    95,    96,    55,    50,    99,    55,    52,    74,
      75,     9,    27,    28,    55,    55,   103,    59,    55,    84,
      85,    23,    27,   141,    89,   112,    44,    45,    46,    47,
      -1,    74,   137,    48,    49,    11,    12,   142,   103,    54,
      16,   111,   147,    -1,   149,    84,   139,   112,    -1,   136,
      85,    27,    28,   158,    -1,   160,    -1,   150,    -1,    35,
      36,   148,   167,   168,     0,    -1,    -1,   172,    -1,   162,
      -1,   136,    48,    49,    -1,    11,    12,    -1,    54,    55,
      16,    17,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    11,    12,    54,    -1,
      56,    16,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    -1,    -1,    40,    41,    42,    43,    -1,
      -1,    11,    12,    48,    49,    50,    16,    17,    -1,    54,
      -1,    56,    57,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    54,    -1,    56,    11,    12,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    -1,    -1,    40,    41,    42,    43,
      -1,    -1,    11,    12,    48,    49,    50,    16,    -1,    -1,
      54,    -1,    56,    -1,    -1,    -1,    -1,    -1,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,
      -1,    40,    41,    42,    43,    -1,    -1,    11,    12,    48,
      49,    50,    16,    -1,    -1,    54,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    -1,    -1,    -1,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,
      54,    55,    27,    28,    11,    12,    -1,    -1,    -1,    16,
      35,    36,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,
      27,    28,    -1,    48,    49,    50,    -1,    -1,    -1,    54,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      -1,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    48,    49,    -1,    -1,    -1,    -1,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    12,    16,    17,    27,    28,    35,    36,    37,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    54,    56,    61,    62,    63,    65,    66,    67,    69,
      72,    73,    74,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    90,    92,    94,    95,    96,    97,    98,    99,
     102,    87,    97,    18,    48,    97,    97,    85,    54,    54,
      50,    50,    84,    54,    84,    75,     0,    62,    72,    67,
      48,    70,    71,    50,    15,    14,     4,     5,     6,     7,
       8,     9,    10,    11,    89,    91,    12,    13,    29,    93,
      94,     3,    30,    31,    32,    33,    34,    35,    36,    58,
       8,    26,    72,    50,    71,    85,    50,    84,   100,   101,
      55,    77,     3,    50,    52,    86,    87,    90,    92,    94,
      84,    84,    84,    84,    84,    84,    84,    20,    21,    22,
      23,    24,    64,    79,    50,    85,    50,    55,    55,    52,
      68,    69,    78,    85,    71,    59,     9,    38,    39,    55,
      50,    85,    72,    84,    70,    57,    72,    72,    85,    72,
      55,    84,    50,    50,    76,    72,    72,    55,    55,    84,
      72,    72,    55,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      64,    64,    64,    65,    65,    65,    66,    66,    67,    68,
      69,    69,    69,    69,    70,    70,    71,    71,    72,    72,
      72,    72,    72,    72,    73,    73,    74,    75,    76,    77,
      77,    78,    78,    79,    79,    80,    80,    81,    81,    81,
      81,    81,    81,    82,    82,    83,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    85,    85,    86,
      86,    87,    87,    88,    88,    89,    89,    89,    89,    89,
      89,    90,    90,    91,    91,    92,    92,    93,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    98,    98,
      98,    99,   100,   100,   101,   101,   102,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     5,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     3,     3,
       1,     1,     1,     1,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     2,     1,     6,     0,     0,     2,
       0,     2,     0,     4,     0,     4,     6,     5,     9,     8,
       8,     7,     6,     2,     3,     2,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     1,     3,     1,     3,
       1,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     4,     3,     1,
       1,     4,     1,     0,     3,     1,     1,     1,     1
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
  YYUSE (yytype);
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
        case 5:
#line 140 "c_yacc.y" /* yacc.c:1652  */
    {write_to_file();}
#line 1623 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 158 "c_yacc.y" /* yacc.c:1652  */
    {
	char *type = (yyvsp[-2].string);
	if(index((yyvsp[-1].string),'?') != NULL){
		char *_ = index((yyvsp[-1].string), '?');
		int _index = (int)(_ - (yyvsp[-1].string));
		int value_length = strlen((yyvsp[-1].string)) - _index;
		char name[_index];
		strncpy(name,(yyvsp[-1].string),_index);
		name[_index] = '\0';
		char value[value_length];
		strncpy(value,(yyvsp[-1].string)+_index+1,value_length);
		value[value_length] = '\0';
		coercion(type,value);
		if(not_defined == 0)
			push_my(type,name,value,scope);
		not_defined = 0;
	}
	else{
		char name[strlen((yyvsp[-1].string))+1];
		strcpy(name,(yyvsp[-1].string));
		push_my(type,name,"",scope);
	}
}
#line 1651 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 182 "c_yacc.y" /* yacc.c:1652  */
    {
	char *type = (yyvsp[-2].string);
	if(index((yyvsp[-1].string),'?') != NULL){
		char *_ = index((yyvsp[-1].string), '?');
		int _index = (int)(_ - (yyvsp[-1].string));
		int value_length = strlen((yyvsp[-1].string)) - _index;
		char name[_index];
		strncpy(name,(yyvsp[-1].string),_index);
		name[_index] = '\0';
		char value[value_length];
		strncpy(value,(yyvsp[-1].string)+_index+1,value_length);
		value[value_length] = '\0';
		coercion(type,value);
		if(not_defined == 0)
			push_my(type,name,value,scope);
		not_defined = 0;
	}
	else{
		char name[strlen((yyvsp[-1].string))+1];
		strcpy(name,(yyvsp[-1].string));
		push_my(type,name,"",scope);
	}
}
#line 1679 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 213 "c_yacc.y" /* yacc.c:1652  */
    {
	strncpy((yyval.string),(yyvsp[0].string),strlen((yyvsp[0].string)) - 1);(yyval.string)[strlen((yyval.string))] = '\0';
}
#line 1687 "y.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 216 "c_yacc.y" /* yacc.c:1652  */
    {
	strncpy((yyval.string)+strlen((yyval.string)), "?", 2);
	(yyval.string)[strlen((yyval.string))] = '\0';
	strncpy((yyval.string)+strlen((yyval.string)), (yyvsp[0].string), sizeof((yyvsp[0].string)));
}
#line 1697 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 233 "c_yacc.y" /* yacc.c:1652  */
    {scope = NEWSCOPE;}
#line 1703 "y.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 235 "c_yacc.y" /* yacc.c:1652  */
    {scope = OLDSCOPE;write_to_file();pop_my();}
#line 1709 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 281 "c_yacc.y" /* yacc.c:1652  */
    {
	check((yyvsp[-2].string),(yyvsp[0].string));
	fun((yyval.string),(yyvsp[-2].string),(yyvsp[-1].string),(yyvsp[0].string));
}
#line 1718 "y.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 294 "c_yacc.y" /* yacc.c:1652  */
    {
	check((yyvsp[-2].string),(yyvsp[0].string));
	fun((yyval.string),(yyvsp[-2].string),(yyvsp[-1].string),(yyvsp[0].string));
}
#line 1727 "y.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 303 "c_yacc.y" /* yacc.c:1652  */
    {
	check((yyvsp[-2].string),(yyvsp[0].string));
	fun((yyval.string),(yyvsp[-2].string),(yyvsp[-1].string),(yyvsp[0].string));
}
#line 1736 "y.tab.c" /* yacc.c:1652  */
    break;

  case 98:
#line 325 "c_yacc.y" /* yacc.c:1652  */
    {
	int flag = 1;
	int i=0;
	while((yyvsp[-1].string)[i] != '\0'){
		if(!isdigit((yyvsp[-1].string)[i])){
			flag = 0;
			break;
		}
		i++;
	}
	if(!flag){
		strcpy((yyval.string),"(");
		strcpy((yyval.string)+1,(yyvsp[-1].string));
		strcat((yyval.string),")");
		(yyval.string)[strlen((yyval.string))] = '\0';
	}
	else{
		strcpy((yyval.string),(yyvsp[-1].string));
	}
}
#line 1761 "y.tab.c" /* yacc.c:1652  */
    break;


#line 1765 "y.tab.c" /* yacc.c:1652  */
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
#line 359 "c_yacc.y" /* yacc.c:1918  */


void yyerror(const char *str)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", str);
}
int main(){
	init_symbol_table();
	if(!yyparse())
	{
		printf("Successful\n");
	}
	else
		printf("Unsuccessful\n");

	return 0;
}


void init_symbol_table()
{
	FILE *fptr = fopen("symbol_table.txt","w");
	fclose(fptr);
	FILE *fptr1 = fopen("error.txt","w");
	fclose(fptr1);
	top_stack_for_symbol_tables = 0;
	int *index_to_insert = &symbol_table_stack[top_stack_for_symbol_tables].index_to_insert;
	int i;
	//printf("index_to_insert %d\n",*index_to_insert);
	for(i=0;i<NO_OF_KEYWORD;i++)
	{
		strcpy(symbol_table_stack[top_stack_for_symbol_tables].symbol_table[*index_to_insert].name,keywords[i]);
		//printf("init_symbol_table %s\n",symbol_table_stack[top_stack_for_symbol_tables].symbol_table[*index_to_insert].name);
		strcpy(symbol_table_stack[top_stack_for_symbol_tables].symbol_table[*index_to_insert].type,"KEYWORD");
		strcpy(symbol_table_stack[top_stack_for_symbol_tables].symbol_table[*index_to_insert].value,"");
		//*(index_to_insert)++;
		symbol_table_stack[top_stack_for_symbol_tables].index_to_insert++;
		//printf("hello");
	}
	//display();
	//printf("\n");
	write_to_file();
}

void write_to_file()
{
	FILE *fptr = fopen("symbol_table.txt","a");
	int i = 0;
	if(top_stack_for_symbol_tables != -1)
	{
		int length = symbol_table_stack[top_stack_for_symbol_tables].index_to_insert;
		for(i=0;i<length;i++)
		{
			fprintf(fptr,"TYPE : %5s\t\tNAME : %5s\t\tVALUE : %5s\n",symbol_table_stack[top_stack_for_symbol_tables].symbol_table[i].type,symbol_table_stack[top_stack_for_symbol_tables].symbol_table[i].name,symbol_table_stack[top_stack_for_symbol_tables].symbol_table[i].value);
		}
	}
	fprintf(fptr,"\n");
	fclose(fptr);
}

void struct_member_name(char* struct_name,int struct_index_to_insert)
{
	//printf("In struct_member_name function %s\n",symbol_table_stack[top_stack_for_symbol_tables].struct_defined[struct_index_to_insert].struct_name);
	int index_to_insert_member = symbol_table_stack[top_stack_for_symbol_tables].struct_defined[struct_index_to_insert].index_to_insert_member;
	int i;
	//printf("nested_struct_start_index %d\n",nested_struct_start_index);
	for(i=0;i<index_to_insert_member;i++)
	{
		strcat(symbol_table_stack[top_stack_for_symbol_tables].struct_defined[struct_index_to_insert].member_name[i],".");
		strcat(symbol_table_stack[top_stack_for_symbol_tables].struct_defined[struct_index_to_insert].member_name[i],struct_name);
	}
	//printf("nested struct name %s\n",symbol_table_stack[top_stack_for_symbol_tables].struct_defined[struct_index_to_insert].member_name[i-1]);
}

void coercion(char *type,char *value)
{	
	char buf[6];
	int i=0;
	int is_digit = 1;
	int is_decimal = 0;
	//printf("Type : %s Value : %s\n",type,value);
	while(value[i] != '\0')
	{
		if( isdigit(value[i]) || value[i] == '.')
		{
			if(value[i] == '.')
				is_decimal = 1; 
			//printf("value[%d] : %c\n",i,value[i]);
		}
		else
		{
			is_digit = 0;
			break;
		}
		i++;
	}
	//printf("is_digit : %d\n",is_digit);
	if(!strcmp(type,"int") && is_digit)
	{
		int temp = atoi(value);
		gcvt(temp,6,buf);
		buf[strlen(buf)] = '\0';
		strcpy(value,buf);
		if(is_decimal)
		{
			FILE *fptr = fopen("error.txt","a");
			error = 1;
			fprintf(fptr,"Warning : data loss may occur.Converting float to int\n");
			fclose(fptr);
		}
	}
	else if(!strcmp(type,"float") && is_digit)
	{
		float temp = atof(value);
		gcvt(temp,6,buf);
		buf[strlen(buf)] = '\0';
		strcpy(value,buf);
		//printf("Warning : Converting from int to float'\n");
	}
}
int search_my(char *name,int flag)
{
	//printf("Hello, I'm in search_my()");
	/*
	printf("-------------Inside Search--------------- \n");
	printf("scope %d\n",flag);
	printf("Name %s\n",name);
	printf("index_to_insert %d\n",symbol_table_stack[top_stack_for_symbol_tables].index_to_insert);
	printf("Symbol table's top Varaible Name %s\n",symbol_table_stack[top_stack_for_symbol_tables].symbol_table[0].name);
	printf("-------------Inside Search--------------- \n");
	*/
	if(!flag)
	{
		int length = symbol_table_stack[top_stack_for_symbol_tables].index_to_insert;
		int i = 0;
		while(i<length)
		{
			//printf("stuck here");
			if(!strcmp(name,symbol_table_stack[top_stack_for_symbol_tables].symbol_table[i].name))
				return -1;
			i++;
		}
	}

	return 1;
}

int push_my(char *type,char *name,char *value,int flag)
{
	if(top_stack_for_symbol_tables == MAX_SCOPE)
		printf("Cannot have more than %d Scope in a program",MAX_SCOPE);
	else
	{
		if( top_stack_for_symbol_tables != -1 && strlen(type) != 0 && search_my(name,flag) == -1 )
		//if(0)
		{
			FILE *fptr = fopen("error.txt","a");
			error = 1;
			fprintf(fptr,"Cannot have multiple decleration for same variable %s\n",name);
			fclose(fptr);
			return -1;	
		}
		else
		{
			if(flag == NEWSCOPE)
			{
				top_stack_for_symbol_tables++;
				scope = OLDSCOPE;
			}
			//if(flag != STRUCT_FLAG)
			{
				int index_to_insert = symbol_table_stack[top_stack_for_symbol_tables].index_to_insert;
				if(symbol_table_stack[top_stack_for_symbol_tables].index_to_insert <= MAX_SYMBOLS)
				{
					strcpy(symbol_table_stack[top_stack_for_symbol_tables].symbol_table[index_to_insert].name,name);
					strcpy(symbol_table_stack[top_stack_for_symbol_tables].symbol_table[index_to_insert].type,type);
					/*
					char buf[6];
					if(!strcmp(type,"float"))
					{
						float temp = atof(value);
						char buf[6];
						gcvt(temp,6,buf);
						buf[strlen(buf)] = '\0';
					}
					else if(!strcmp(type,"int"))
					{
						int temp = atoi(value);
						gcvt(temp,6,buf);
						buf[strlen(buf)] = '\0';
					}
					*/
					strcpy(symbol_table_stack[top_stack_for_symbol_tables].symbol_table[index_to_insert].value,value);
					symbol_table_stack[top_stack_for_symbol_tables].index_to_insert += 1;
					//printf("Name %s\n",symbol_table_stack[top_stack_for_symbol_tables].symbol_table[0].name);
					//printf("Value %s\n",symbol_table_stack[top_stack_for_symbol_tables].symbol_table[0].value);
					//printf("Type %s\n",symbol_table_stack[top_stack_for_symbol_tables].symbol_table[0].type);
				}
				else
				{
					printf("Cannot have more than %d Symbols in each scope",MAX_SYMBOLS);
					return -1;
				}
			}
			/*
			else
			{
				
			}
			*/
			return 0;
		}
	}
}

int pop_my()
{
	if(top_stack_for_symbol_tables == -1)
	{
		printf("No Scope Present");
		return -1;
	}
	// poping all the content of top_stack_for_symbol_tables by making corresponding index to zero.
	else
	{
		// setting index_to_insert of top_stack_for_symbol_tables to 0 
		symbol_table_stack[top_stack_for_symbol_tables].index_to_insert = 0;
		
		// setting struct_index_to_insert of top_stack_for_symbol_tables to 0 and also all the index_to_insert_member of struct_defined
		int struct_index_to_insert =  symbol_table_stack[top_stack_for_symbol_tables].struct_index_to_insert;
		int i;
		for(i = 0;i<struct_index_to_insert;i++)
			symbol_table_stack[top_stack_for_symbol_tables].struct_defined[i].index_to_insert_member = 0;
		symbol_table_stack[top_stack_for_symbol_tables].struct_index_to_insert = 0;
		
		// need to clear stack top before decrementing
		top_stack_for_symbol_tables--; 
		return 0;
	}
}

void display_struct()
{
	int i = 0;
	int j;
	if(top_stack_for_symbol_tables != -1)
	{
		int struct_index_to_insert = symbol_table_stack[top_stack_for_symbol_tables].struct_index_to_insert;
		for(i=0;i<struct_index_to_insert;i++)
		{
			//printf("Structure name %s\n",symbol_table_stack[top_stack_for_symbol_tables].struct_defined[i].struct_name);
			int index_to_insert_member = symbol_table_stack[top_stack_for_symbol_tables].struct_defined[i].index_to_insert_member;
			//printf("index_to_insert_member %d\n",index_to_insert_member);
			for(j=0;j<index_to_insert_member;j++)
			{
				printf("Type: %s NAME: %s ",symbol_table_stack[top_stack_for_symbol_tables].struct_defined[i].member_type[j],symbol_table_stack[top_stack_for_symbol_tables].struct_defined[i].member_name[j]);
			}
			printf("\n");
		}
	}
}


void display()
{
	//printf("Display\n");
	int i = 0;
	if(top_stack_for_symbol_tables != -1)
	{
		//printf("Display\n");
		//printf("Display top_stack_for_symbol_tables %d \n",top_stack_for_symbol_tables);
		int length = symbol_table_stack[top_stack_for_symbol_tables].index_to_insert;
		//printf("Display index_to_insert %d \n",length);
		for(i=0;i<length;i++)
		{
			//printf("helllo");
			printf("TYPE : %s\tNAME : %s\tVALUE : %s\n",symbol_table_stack[top_stack_for_symbol_tables].symbol_table[i].type,symbol_table_stack[top_stack_for_symbol_tables].symbol_table[i].name,symbol_table_stack[top_stack_for_symbol_tables].symbol_table[i].value);
		}
	}
}

void fun(char *result ,char *arg1,char *arg2,char *arg3)
{
	/*
	int i = 0;
	int flag = 0;
	if(arg1[i] == '(')
	{
		i+=1;
		flag = 1;
	}
	*/
	int arg1_length = strlen(arg1);
	int arg3_length = strlen(arg3);
	int i=arg1_length-1;
	int j = 0;
	if((isdigit(arg1[i]) | arg1[i] == '.') || (isdigit(arg3[j])  | arg3[j] == '.'))
	{
		float temp; 
		//if(!strcmp(arg2,"*"))
		{
			//printf("result %s arg1 %s arg2 %s arg3 %s\n",result,arg1,arg2,arg3);
			//int arg1_length = strlen(arg1);
			//int arg3_length = strlen(arg3);
			//int i=arg1_length-1;
			//int j = 0;
			while((i >= 0) && (isdigit(arg1[i]) | arg1[i] == '.'))
			{
				//printf("stuck\n");
				i--;
			}
			
			while((j < arg3_length) && (isdigit(arg3[j])  | arg3[j] == '.'))
			{
				//printf("stuck\n");
				j++;
			}
			
			if(i+1 <= arg1_length-1 && j-1 >= 0)
			{
				//printf("i %d\n",i);
				char temp_arg3[j];
				strncpy(temp_arg3,arg3,j);
				//printf("j %d\n",j-1);
				//printf("arg1 %s \n",arg1+(i+1));
				//printf("arg3 %s \n",temp_arg3);
				if(!strcmp(arg2,"*"))
					temp = atof(arg1+(i+1)) * atof(temp_arg3);
				else if(!strcmp(arg2,"/"))
					temp = atof(arg1+(i+1)) / atof(temp_arg3);
				else if(!strcmp(arg2,"%"))
					temp = atoi(arg1+(i+1)) % atoi(temp_arg3);
				else if(!strcmp(arg2,"+"))
					temp = atof(arg1+(i+1)) + atof(temp_arg3);
				else if(!strcmp(arg2,"-"))
					temp = atof(arg1+(i+1)) - atof(temp_arg3);
				else if(!strcmp(arg2,"<"))
					temp = atof(arg1+(i+1)) < atof(temp_arg3);
				else if(!strcmp(arg2,">"))
					temp = atof(arg1+(i+1)) > atof(temp_arg3);
				else if(!strcmp(arg2,">="))
					temp = atof(arg1+(i+1)) >= atof(temp_arg3);
				else if(!strcmp(arg2,"<="))
					temp = atof(arg1+(i+1)) <= atof(temp_arg3);
				else if(!strcmp(arg2,"!="))
					temp = atof(arg1+(i+1)) != atof(temp_arg3);
				else if(!strcmp(arg2,"=="))
					temp = atof(arg1+(i+1)) == atof(temp_arg3);
				
				char buf[128];
				gcvt(temp,6,buf);
				/*
				if(!strcmp(buf,"inf"))
				{
					printf("Error\n");
					exit(0);
				}
				*/
				//buf[strlen(buf)] = '\0';
				strcat(buf,arg3+j);
				//printf("result %s\n",result);
				//printf("arg1 %s \n",arg1);
				//printf("arg2 %s \n",arg2);
				//printf("arg3 %s \n",arg3);
				//printf("buf %s\n",buf);
				//printf("arg1+i+1 %s\n",arg1+i+1);
				//printf("arg1 %s\n",arg1);
				strncpy(arg1+i+1,buf,sizeof(buf));
				//arg1[strlen(arg1)] = '\0';
				
				//printf("\n");
				strcpy(result,arg1);
				//printf("arg1 %s \n",arg1);
				//printf("result %s \n",result);
				//strcat(result,buf);
				return;
			}
			else
			{
				//printf("in else part of fun function arg1 =  %s arg3 = %s\n",arg1,arg3);
				strncpy(result,arg1,sizeof(arg1));
				strcat(result,arg2);
				//result[strlen(result)] = '\0';
				strcat(result,arg3);
				result[strlen(result)] = '\0';
				//printf("res %s\n",result);
				return;
			}
			//temp = atof(arg1) * atof(arg3);
		}
		/*
		else if(!strcmp(arg2,"/"))
			temp = atof(arg1) / atof(arg3);
		else if(!strcmp(arg2,"%"))
			temp = atoi(arg1) % atoi(arg3);
		else if(!strcmp(arg2,"+"))
			temp = atof(arg1) + atof(arg3);
		else if(!strcmp(arg2,"-"))
			temp = atof(arg1) - atof(arg3);
		else if(!strcmp(arg2,"<"))
			temp = atof(arg1) < atof(arg3);
		else if(!strcmp(arg2,">"))
			temp = atof(arg1) > atof(arg3);
		else if(!strcmp(arg2,"="))
		{
		}
		gcvt(temp,6,result);
		result[strlen(result)] = '\0';
		printf("In Else -> Result for %s * %s : %s\n",arg1,arg3,result);
		*/
	}
	else
	{
		char *p[128];
		strncpy(result,arg1,sizeof(arg1));
		//strcat(result,arg1);
		result[strlen(result)] = '\0';
		//printf("result 1 %s\n",result);
		//printf("arg2 %s\n",arg2);
		//strncpy(result+strlen(result),arg2,2);
		strcat(result,arg2);
		result[strlen(result)] = '\0';
		//printf("result 2 %s \n",result);
		//printf("arg3 %s \n",arg3);
		//strncpy(result+strlen(result),arg3,strlen(arg3));
		strcat(result,arg3);
		result[strlen(result)] = '\0';
		//printf("In If -> Result for %s * %s : %s\n",arg1,arg3,result);
	}	
}

int update_variable_value(char *name,char *value)
{
	int i,j;
	int index_to_insert;
	char *temp_name;
	for(i=top_stack_for_symbol_tables;i>=0;i--)
	{
		index_to_insert = symbol_table_stack[i].index_to_insert;
	//printf("name : %s",name);
		for(j=0;j<index_to_insert;j++)
		{
			temp_name = symbol_table_stack[i].symbol_table[j].name;
			//printf("temp_name : %s",temp_name);
			if(!strcmp(temp_name,name))
			{
				if(strlen(value) == 0)
					return 1;
				value[strlen(value)] = '\0';	// to ensure value string is null terminated
				strcpy(symbol_table_stack[i].symbol_table[j].value,value);
				return 1;
			}
		}
	}
	return -1;	
}

void check(char *arg1,char *arg3)
{
	char temp_name[128];
	int i=0;
	//printf("arg1 : %s arg3 : %s\n",arg1,arg3);
	int flag_operator = 0;	// means argument passed doesn't have operator
	int value;
	if( !isdigit(arg1[0]) && arg1[0] != '(' )
	{
		// for ensuring no operator is present in argument passed. Ex = (p*q-1)	gives arg1 = p*q and arg3 = 1
		while( arg1[i] != '\0' )
		{
			if( !isalnum(arg1[i]) )
			{
				flag_operator = 1;				
				break;
			}
			i++;
		}
		//printf("check flag %d\n",flag_operator);	
		if( !flag_operator )
		{
			// check if varaible in arg1 is present in symbol table or not
			value = update_variable_value(arg1,"");
			if(value == -1)
			{
				not_defined = 1;
				FILE *fptr = fopen("error.txt","a");
				fprintf(fptr,"Varaible %s is not defined\n",arg1);
				error = 1;
				fclose(fptr);
			}
		}
	}
	i=0;
	flag_operator = 0;
	if( !isdigit(arg3[0]) && arg3[0] != '(' )
	{
		while( arg3[i] != '\0' )
		{
			if( !isalnum(arg3[i]) )
			{
				flag_operator = 1;				
				break;
			}
			i++;
		}
		if( !flag_operator )
		{
			//check if varaible in arg1 is present in symbol table or not
			value = update_variable_value(arg3,"");
			if(value == -1)
			{
				not_defined = 1;
				FILE *fptr = fopen("error.txt","a");
				fprintf(fptr,"Varaible %s is not defined\n",arg3);
				error = 1;
				fclose(fptr);
			}
		}
	}
	
}

int add_struct_member_in_symbol_table(char *struct_name)
{
	// to make sure struct_name is null terminated
	//printf("struct name : %s\n",struct_name);
	struct_name[strlen(struct_name)] = '\0';
	
	//int index_to_insert = symbol_table_stack[top_stack_for_symbol_tables].index_to_insert;
	int last_struct_inserted_index = symbol_table_stack[top_stack_for_symbol_tables].struct_index_to_insert - 1;
	
	int last_insert_index_member_struct = symbol_table_stack[top_stack_for_symbol_tables].struct_defined[last_struct_inserted_index].index_to_insert_member;
	
	int j=0,i;	// index for member of struct;
	char *type;
	char *var_name;
	char name[128];
	for(i=0;i<last_insert_index_member_struct;i++)
	{
		type = symbol_table_stack[top_stack_for_symbol_tables].struct_defined[last_struct_inserted_index].member_type[j];
		var_name = symbol_table_stack[top_stack_for_symbol_tables].struct_defined[last_struct_inserted_index].member_name[j];
		strcpy(name,struct_name);
		strcat(name,".");
		strcat(name,var_name);
		name[strlen(name)] = '\0';
		j++;
		push_my(type,name,"",scope);
	}
}

void struct_member(char *type,char *name)
{
	if(scope == NEWSCOPE)
	{
		++top_stack_for_symbol_tables;
		scope = OLDSCOPE;
		//printf("inside struct\n");
	}
	int *struct_index_to_insert = &symbol_table_stack[top_stack_for_symbol_tables].struct_index_to_insert;
	//int *index_to_insert_member = &symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].index_to_insert_member;
	if(strlen(type) != 0 && strlen(name) != 0)
	{
		//printf("Struct member name %s\n",name);
		//printf("Struct member type %s\n",type);
		int *index_to_insert_member;
		if(struct_reference_used == 0 && !strcmp(type,"struct")) 
		{
			//printf("!!!!!!!!!!!!!\n");
			*struct_index_to_insert -= 1;
			symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].struct_name[0] = '\0';
			index_to_insert_member = &symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].index_to_insert_member;
			int i;
			//printf("nested_struct_start_index %d\n",nested_struct_start_index);
			char new_name[2*LIMIT];
			for(i=nested_struct_start_index;i<*index_to_insert_member;i++)
			{
				strcpy(new_name,name);
				strcat(new_name,".");
				strcat(new_name,symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].member_name[i]);
				//printf("new name %s\n"new_name);
				strcpy(symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].member_name[i],new_name);
				//strcat(symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].member_name[i],".");
				//strcat(symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].member_name[i],name);
			}
			//printf("nested struct name %s\n",symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].member_name[i-1]);
			//printf("nested struct name %s\n",symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].member_type[i-1]);
		}
		else
		{
			index_to_insert_member = &symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].index_to_insert_member;
			//printf("struct_index_to_insert %d\n",*struct_index_to_insert);

			//printf("index_to_insert_member %d\n",*index_to_insert_member);
			strcpy(symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].member_type[*index_to_insert_member],type);
			strcpy(symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].member_name[*index_to_insert_member],name);
			*index_to_insert_member += 1;
			struct_reference_used = 0;
		}
	}
	else
	{
		//printf("Struct name %s\n",name);
		strcpy(symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].struct_name,name);
		*struct_index_to_insert += 1;
	}
}
