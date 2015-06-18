/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKNAME = 258,
     TOKINT = 259,
     TOKFLOAT = 260,
     TOKCHAR = 261,
     SEMICOLON = 262,
     COMMA = 263,
     EQUAL = 264,
     PLUS = 265,
     MINUS = 266,
     MULT = 267,
     MOD = 268,
     DIV = 269,
     NUMBER = 270,
     AND = 271,
     OR = 272,
     NOT = 273,
     GREATERTHAN = 274,
     LESSTHAN = 275,
     LESSTHANEQUAL = 276,
     GREATERTHANEQUAL = 277,
     NOTEQUAL = 278,
     OPENPAREN = 279,
     CLOSEPAREN = 280,
     OPENBRACE = 281,
     CLOSEBRACE = 282,
     TOKWHILE = 283,
     TOKFOR = 284,
     TOKIF = 285,
     TOKELSE = 286,
     COMPEQUAL = 287,
     TOKVOID = 288,
     INC = 289,
     DEC = 290,
     TOKRETURN = 291,
     TOKDO = 292
   };
#endif
/* Tokens.  */
#define TOKNAME 258
#define TOKINT 259
#define TOKFLOAT 260
#define TOKCHAR 261
#define SEMICOLON 262
#define COMMA 263
#define EQUAL 264
#define PLUS 265
#define MINUS 266
#define MULT 267
#define MOD 268
#define DIV 269
#define NUMBER 270
#define AND 271
#define OR 272
#define NOT 273
#define GREATERTHAN 274
#define LESSTHAN 275
#define LESSTHANEQUAL 276
#define GREATERTHANEQUAL 277
#define NOTEQUAL 278
#define OPENPAREN 279
#define CLOSEPAREN 280
#define OPENBRACE 281
#define CLOSEBRACE 282
#define TOKWHILE 283
#define TOKFOR 284
#define TOKIF 285
#define TOKELSE 286
#define COMPEQUAL 287
#define TOKVOID 288
#define INC 289
#define DEC 290
#define TOKRETURN 291
#define TOKDO 292




/* Copy the first part of user declarations.  */
#line 1 "grammar.y"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 701
#define YYSTYPE char*

struct symbol
{
 char *name;
 int type; //type is 0 for int,1 for char and 2 for float
};
 
  struct node
  {
    char *identifierName;
    int type; 
    struct node * next;
  };
  
 
  struct node * hashtable[SIZE];
   
  int GetHashCode(char *str);
  struct node * InsertIntoHashTable(char *, int);
  struct node * InsertIntoSLL(struct node *, char *, int);
  void PrintTable();    
  struct node * GetNode(char *,int);
  struct symbol* IsSymbolPresent(char *);
  struct node *ptr;


int yydebug=1;
int presIden=-1;


void yyerror(const char * str)
{
  fprintf(stderr,"error: %s \n",str);
}

int yywrap()
{
  return 1;
}

main()
{
  yyparse();
  PrintTable();
}

//get the hash 
int GetHashCode(char * str)
{
  int i=0;
  int val=0;
  while(str[i]!='\0')
   {
    val=(val+(str[i]-'\0'))%SIZE;
    i++;
   }
  return val;
}

//get a linked list node
struct node * GetNode(char *str, int type)
 {
  struct node *newNode;
  newNode=(struct node *)malloc(sizeof(struct node));
  newNode->identifierName=(char *)malloc((sizeof(char))*(strlen(str)+5));	
  strcpy(newNode->identifierName,str);
  newNode->type=type;
  newNode->next=NULL;
  return newNode;
 }

//insert value into singly linked list
struct node * InsertIntoSLL(struct node * start, char * str, int type)
{
 
 if(start==NULL)
  {
    start=GetNode(str,type);
    return start;
  }
 else
  {
    struct node *tmp;
    tmp=start;
    while(tmp->next!=NULL)
    {
      tmp=tmp->next;
    }
    tmp->next=GetNode(str,type);
    return tmp->next;
  } 
 
}

//insert value in hash table
struct node * InsertIntoHashTable(char * str,int type)
{
   int hash=GetHashCode(str);
   if(IsSymbolPresent(str)==NULL)
    {
   	if(hashtable[hash]==NULL)
    	   {
      		hashtable[hash]=InsertIntoSLL(hashtable[hash],str,type);
      		return hashtable[hash];
    	   }
   	else
    	   {
      		return InsertIntoSLL(hashtable[hash],str,type);
           }
   }
  else
   {
       return NULL;
   } 	
}

void PrintSLLNodes(struct node * start)
{
  struct node * tmp;
  tmp=start;
  while(tmp!=NULL)
   {
     printf("%s  ",tmp->identifierName);
     if(tmp->type==0) printf("INT");
     if(tmp->type==1) printf("CHAR");
     if(tmp->type==2) printf("FLOAT");
     tmp=tmp->next;
   }
}

void PrintTable()
{
  int i;
  printf("\nThe hash table is :\n");
  for(i=0;i<SIZE;i++)
   {
      if(hashtable[i]!=NULL)
        {
          PrintSLLNodes(hashtable[i]);
          printf("\n");
        }
   }
}

struct symbol* IsSymbolPresent(char *str)
 {
   int hash=GetHashCode(str);
   struct node *tmp;
   tmp=hashtable[hash];
   struct symbol * newSymbol;
   
   while(tmp!=NULL)
    {
      //identifier is found
      if(strcmp(tmp->identifierName,str)==0)
        {
           newSymbol=(struct symbol *)malloc(sizeof(struct symbol));   
           
           newSymbol->name=(char *)malloc((strlen(str)+1)*sizeof(char));
           strcpy(newSymbol->name,str);
           
           newSymbol->type=tmp->type; 
           
           return newSymbol;
        }
       tmp=tmp->next;
    }
   //identifier is not found
  return NULL;
 }

char * GetType(int type)
{
  if(type==0) return "INT";
  if(type==1) return "CHAR";
  if(type==2) return "FLOAT";
}

void InsertSymbol(char *symName)
{
 struct symbol *sym;
 sym=IsSymbolPresent(symName);
 if(sym==NULL)
   {
     InsertIntoHashTable(symName,presIden);
   } 
 else
   {
     printf("Redeclaration error!\nSymbol %s is declared earlier with type %s",symName,GetType(sym->type));
     yyerror("Symbol redeclared");	
   }
}

void SearchSymbol(char * symName)
{
   struct symbol *sym; 
   sym=IsSymbolPresent(symName); 
   if(sym==NULL)
     {
	printf("Symbol: %s is not declared",symName);
        yyerror("Symbol not declared"); 
     }
}
/*End of hash-table operations*/


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 392 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    19,    22,
      25,    29,    35,    36,    39,    44,    46,    50,    52,    54,
      56,    61,    67,    69,    71,    75,    79,    83,    86,    89,
      92,    95,    97,    99,   101,   103,   105,   108,   112,   116,
     120,   124,   128,   132,   136,   140,   144,   148,   152,   156,
     160,   164,   168,   172,   176,   180,   184,   188,   192,   196,
     200,   204,   208,   212,   216,   219,   227,   235,   247,   260,
     273,   285,   294
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    -1,    39,    40,    -1,    39,    44,    -1,
      39,    48,    -1,    39,    49,    -1,    39,    50,    -1,    39,
      52,    -1,    39,    51,    -1,    43,    42,     7,    -1,    43,
      42,     9,    45,     7,    -1,    -1,    43,     3,    -1,    41,
       8,    43,     3,    -1,     3,    -1,    42,     8,     3,    -1,
       4,    -1,     5,    -1,     6,    -1,     3,     9,    45,     7,
      -1,     3,    46,     9,    45,     7,    -1,     3,    -1,    15,
      -1,    45,    46,    15,    -1,    45,    46,     3,    -1,    24,
      45,    25,    -1,     3,    34,    -1,    34,     3,    -1,     3,
      35,    -1,    35,     3,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,    14,    -1,    18,    47,    -1,    24,    47,
      25,    -1,     3,    19,     3,    -1,     3,    20,     3,    -1,
       3,    19,    15,    -1,    15,    19,     3,    -1,    15,    19,
      15,    -1,     3,    20,    15,    -1,    15,    20,     3,    -1,
      15,    20,    15,    -1,     3,    22,     3,    -1,     3,    22,
      15,    -1,    15,    22,     3,    -1,    15,    22,    15,    -1,
       3,    21,     3,    -1,     3,    21,    15,    -1,    15,    21,
       3,    -1,    15,    21,    15,    -1,     3,    32,     3,    -1,
       3,    32,    15,    -1,    15,    32,     3,    -1,    15,    32,
      15,    -1,     3,    23,     3,    -1,     3,    23,    15,    -1,
      15,    23,     3,    -1,    15,    23,    15,    -1,     3,    16,
       3,    -1,     3,    17,     3,    -1,    18,     3,    -1,    28,
      24,    47,    25,    26,    39,    27,    -1,    30,    24,    47,
      25,    26,    39,    27,    -1,    30,    24,    47,    25,    26,
      39,    27,    31,    26,    39,    27,    -1,    29,    24,    44,
      47,     7,     3,     9,    45,    25,    26,    39,    27,    -1,
      29,    24,    40,    47,     7,     3,     9,    45,    25,    26,
      39,    27,    -1,    43,     3,    24,    41,    25,    26,    39,
      36,    45,     7,    27,    -1,    33,     3,    24,    41,    25,
      26,    39,    27,    -1,    37,    26,    39,    27,    28,    24,
      47,    25,     7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   216,   216,   217,   218,   219,   220,   221,   222,   223,
     226,   227,   230,   231,   232,   235,   236,   239,   240,   241,
     244,   245,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   259,   260,   261,   262,   263,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   323,   326,   327,   330,   331,
     334,   335,   338
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKNAME", "TOKINT", "TOKFLOAT",
  "TOKCHAR", "SEMICOLON", "COMMA", "EQUAL", "PLUS", "MINUS", "MULT", "MOD",
  "DIV", "NUMBER", "AND", "OR", "NOT", "GREATERTHAN", "LESSTHAN",
  "LESSTHANEQUAL", "GREATERTHANEQUAL", "NOTEQUAL", "OPENPAREN",
  "CLOSEPAREN", "OPENBRACE", "CLOSEBRACE", "TOKWHILE", "TOKFOR", "TOKIF",
  "TOKELSE", "COMPEQUAL", "TOKVOID", "INC", "DEC", "TOKRETURN", "TOKDO",
  "$accept", "lines", "decl", "funcdecl", "var", "iden", "def", "exp",
  "optr", "cond", "whl", "ifelse", "forloop", "func", "dowhl", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    39,    39,    39,    39,    39,    39,
      40,    40,    41,    41,    41,    42,    42,    43,    43,    43,
      44,    44,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    46,    46,    46,    46,    46,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    48,    49,    49,    50,    50,
      51,    51,    52
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       3,     5,     0,     2,     4,     1,     3,     1,     1,     1,
       4,     5,     1,     1,     3,     3,     3,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     7,     7,    11,    12,    12,
      11,     8,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    17,    18,    19,     0,     0,     0,
       0,     0,     3,     0,     4,     5,     6,     7,     9,     8,
       0,    31,    32,    33,    34,    35,     0,     0,     0,     0,
       0,     2,    15,     0,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,    12,    10,     0,     0,    27,    29,     0,    28,
      30,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    36,
       0,     0,     0,    15,     0,     0,     0,     0,     0,     0,
      16,     0,    26,    25,    24,    21,    62,    63,    38,    40,
      39,    43,    50,    51,    46,    47,    58,    59,    54,    55,
      41,    42,    44,    45,    52,    53,    48,    49,    60,    61,
      56,    57,    37,     2,     0,     0,     2,     0,     0,    13,
       0,     0,    11,     0,     0,     0,     0,     0,     2,     0,
       2,    65,     0,     0,    66,    14,     0,     0,     0,     0,
       0,     0,    71,     0,     0,     0,     0,     2,    72,     0,
       2,     2,     0,     0,     0,     0,    67,    70,    69,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    12,    86,    33,    13,    14,    39,    62,    45,
      15,    16,    17,    18,    19
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -33
static const yytype_int16 yypact[] =
{
     -33,     6,   -33,   252,   -33,   -33,   -33,   -19,    -9,    -6,
      48,    30,   -33,    54,   -33,   -33,   -33,   -33,   -33,   -33,
      -2,   -33,   -33,   -33,   -33,   -33,    50,    57,   221,    57,
      53,   -33,    56,    33,    14,   -33,    -2,    80,    82,   222,
      -2,   164,   133,    58,    57,    61,    57,   101,    57,    93,
     140,    25,   140,   -33,   116,    -2,   -33,   -33,   193,   -33,
     -33,   -33,    11,   230,   118,   124,    35,    64,    81,    88,
      91,   102,   105,   161,   174,   176,   185,   216,   164,   -33,
     117,   115,   154,   -33,   155,   171,    -1,   163,   162,    12,
     -33,   238,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   196,   217,   -33,   140,   175,   -33,
     197,   204,   -33,    41,   213,   229,    60,   236,   -33,    57,
     -33,   -33,    -2,    -2,   215,   -33,   110,   242,    95,   198,
     203,   228,   -33,   240,    -2,   243,   244,   -33,   -33,   246,
     -33,   -33,   130,   241,   145,   165,   -33,   -33,   -33,   -33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -33,   -31,   227,   219,   -33,   -25,   245,   -32,   269,   -27,
     -33,   -33,   -33,   -33,   -33
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      51,    34,    49,    47,    58,    27,     2,   127,    63,     3,
       4,     5,     6,    35,    93,    28,    79,    80,    29,    82,
     127,    84,    36,    91,   128,    87,    94,    87,     3,     4,
       5,     6,    37,    38,     7,     8,     9,   131,    98,    10,
      53,    54,    55,    11,     3,     4,     5,     6,    56,    57,
      99,    30,    88,     7,     8,     9,    31,    32,    10,    40,
      41,    78,    11,     3,     4,     5,     6,   100,   141,     7,
       8,     9,    42,    42,    10,    43,    43,    50,    11,   101,
      52,    44,    44,    59,   102,    60,    81,   144,     7,     8,
       9,   104,   133,    10,   106,   136,   103,    11,     3,     4,
       5,     6,   137,   105,    83,   108,   107,   146,   110,   148,
     149,   150,   147,     3,     4,     5,     6,   109,    85,    90,
     111,    96,   159,     7,     8,     9,   162,    97,    10,   164,
     165,   154,    11,     3,     4,     5,     6,   152,     7,     8,
       9,   123,   122,    10,     4,     5,     6,    11,     3,     4,
       5,     6,    72,    73,    74,    75,    76,   166,     7,     8,
       9,   124,   125,    10,   112,    77,   129,    11,     3,     4,
       5,     6,   168,     7,     8,     9,   113,   114,    10,   116,
      64,    65,    11,    66,    67,    68,    69,    70,   118,   115,
     130,   117,   169,     7,     8,     9,    71,   126,    10,   134,
     119,   138,    11,    21,    22,    23,    24,    25,    21,    22,
      23,    24,    25,    21,    22,    23,    24,    25,    92,   120,
     135,   139,   142,   155,     3,     4,     5,     6,   156,    61,
     140,   121,    21,    22,    23,    24,    25,    95,   143,   145,
      21,    22,    23,    24,    25,   132,   151,   158,    21,    22,
      23,    24,    25,   163,   157,    46,    21,    22,    23,    24,
      25,    20,    21,    22,    23,    24,    25,   153,   167,   160,
     161,    89,    26,    48
};

static const yytype_uint8 yycheck[] =
{
      31,     3,    29,    28,    36,    24,     0,     8,    40,     3,
       4,     5,     6,    15,     3,    24,    43,    44,    24,    46,
       8,    48,    24,    55,    25,    50,    15,    52,     3,     4,
       5,     6,    34,    35,    28,    29,    30,    25,     3,    33,
       7,     8,     9,    37,     3,     4,     5,     6,    34,    35,
      15,     3,    27,    28,    29,    30,    26,     3,    33,     9,
       3,     3,    37,     3,     4,     5,     6,     3,    27,    28,
      29,    30,    15,    15,    33,    18,    18,    24,    37,    15,
      24,    24,    24,     3,     3,     3,    25,    27,    28,    29,
      30,     3,   123,    33,     3,   126,    15,    37,     3,     4,
       5,     6,   127,    15,     3,     3,    15,   138,     3,   140,
     142,   143,   139,     3,     4,     5,     6,    15,    25,     3,
      15,     3,   154,    28,    29,    30,   157,     3,    33,   160,
     161,    36,    37,     3,     4,     5,     6,    27,    28,    29,
      30,    26,    25,    33,     4,     5,     6,    37,     3,     4,
       5,     6,    19,    20,    21,    22,    23,    27,    28,    29,
      30,     7,     7,    33,     3,    32,     3,    37,     3,     4,
       5,     6,    27,    28,    29,    30,    15,     3,    33,     3,
      16,    17,    37,    19,    20,    21,    22,    23,     3,    15,
      28,    15,    27,    28,    29,    30,    32,    26,    33,     3,
      15,    26,    37,    10,    11,    12,    13,    14,    10,    11,
      12,    13,    14,    10,    11,    12,    13,    14,    25,     3,
       3,    24,     9,    25,     3,     4,     5,     6,    25,     7,
      26,    15,    10,    11,    12,    13,    14,     7,     9,     3,
      10,    11,    12,    13,    14,     7,    31,     7,    10,    11,
      12,    13,    14,     7,    26,    28,    10,    11,    12,    13,
      14,     9,    10,    11,    12,    13,    14,    25,    27,    26,
      26,    52,     3,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,     0,     3,     4,     5,     6,    28,    29,    30,
      33,    37,    40,    43,    44,    48,    49,    50,    51,    52,
       9,    10,    11,    12,    13,    14,    46,    24,    24,    24,
       3,    26,     3,    42,     3,    15,    24,    34,    35,    45,
       9,     3,    15,    18,    24,    47,    40,    43,    44,    47,
      24,    39,    24,     7,     8,     9,    34,    35,    45,     3,
       3,     7,    46,    45,    16,    17,    19,    20,    21,    22,
      23,    32,    19,    20,    21,    22,    23,    32,     3,    47,
      47,    25,    47,     3,    47,    25,    41,    43,    27,    41,
       3,    45,    25,     3,    15,     7,     3,     3,     3,    15,
       3,    15,     3,    15,     3,    15,     3,    15,     3,    15,
       3,    15,     3,    15,     3,    15,     3,    15,     3,    15,
       3,    15,    25,    26,     7,     7,    26,     8,    25,     3,
      28,    25,     7,    39,     3,     3,    39,    43,    26,    24,
      26,    27,     9,     9,    27,     3,    39,    47,    39,    45,
      45,    31,    27,    25,    36,    25,    25,    26,     7,    45,
      26,    26,    39,     7,    39,    39,    27,    27,    27,    27
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 13:
#line 231 "grammar.y"
    {InsertSymbol((yyvsp[(2) - (2)]));}
    break;

  case 14:
#line 232 "grammar.y"
    {InsertSymbol((yyvsp[(4) - (4)]));}
    break;

  case 15:
#line 235 "grammar.y"
    {InsertSymbol((yyvsp[(1) - (1)]));}
    break;

  case 16:
#line 236 "grammar.y"
    {InsertSymbol((yyvsp[(3) - (3)]));}
    break;

  case 17:
#line 239 "grammar.y"
    {presIden=0;}
    break;

  case 18:
#line 240 "grammar.y"
    {presIden=2;}
    break;

  case 19:
#line 241 "grammar.y"
    {presIden=1;}
    break;

  case 20:
#line 244 "grammar.y"
    {/*printf("Definition found");*/SearchSymbol((yyvsp[(1) - (4)]));}
    break;

  case 21:
#line 245 "grammar.y"
    {SearchSymbol((yyvsp[(1) - (5)]));}
    break;

  case 22:
#line 248 "grammar.y"
    {SearchSymbol((yyvsp[(1) - (1)]));}
    break;

  case 25:
#line 251 "grammar.y"
    {SearchSymbol((yyvsp[(3) - (3)]));}
    break;

  case 27:
#line 253 "grammar.y"
    {SearchSymbol((yyvsp[(1) - (2)]));}
    break;

  case 28:
#line 254 "grammar.y"
    {SearchSymbol((yyvsp[(2) - (2)]));}
    break;

  case 29:
#line 255 "grammar.y"
    {SearchSymbol((yyvsp[(1) - (2)]));}
    break;

  case 30:
#line 256 "grammar.y"
    {SearchSymbol((yyvsp[(2) - (2)]));}
    break;

  case 65:
#line 323 "grammar.y"
    {printf("\nWhile loop found!");}
    break;

  case 66:
#line 326 "grammar.y"
    {printf("\nIf found!");}
    break;

  case 67:
#line 327 "grammar.y"
    {printf("\nIf-else found!");}
    break;

  case 68:
#line 330 "grammar.y"
    {printf("\nfor loop found!");}
    break;

  case 69:
#line 331 "grammar.y"
    {printf("\nfor loop found!");}
    break;

  case 72:
#line 338 "grammar.y"
    {printf("\nDo while loop found!");}
    break;


/* Line 1267 of yacc.c.  */
#line 1851 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 344 "grammar.y"



