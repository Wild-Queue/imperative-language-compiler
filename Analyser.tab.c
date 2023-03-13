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
#line 2 "Analyser.y"

    #include <iostream>
    #include <string>
    #include <vector>
    #include <typeinfo>

    #include "NodeDecl.h"
    extern FILE *yyin;
    extern int yylineno;
    int yylex();
    using namespace std;
    void yyerror(std::string s) {
        cout << "Syntax Error in the line " << line_no << endl;
        //cerr << s << ", line " << yylineno << endl;
        exit(0);
    };

    typedef struct {
        Node* nodeLink;
        vector<Node*> nodeList;

        long long int integer;
        double real;
        std::string string;
        char character;
        int boolean;
    } YYSTYPE;
    #define YYSTYPE YYSTYPE

    Node* root = new Node(Token("root", "root"));


#line 104 "Analyser.tab.c"

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

#include "Analyser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_FOR = 3,                      /* T_FOR  */
  YYSYMBOL_T_WHILE = 4,                    /* T_WHILE  */
  YYSYMBOL_T_LOOP = 5,                     /* T_LOOP  */
  YYSYMBOL_T_IN = 6,                       /* T_IN  */
  YYSYMBOL_T_REVERSE = 7,                  /* T_REVERSE  */
  YYSYMBOL_T_IF = 8,                       /* T_IF  */
  YYSYMBOL_T_THEN = 9,                     /* T_THEN  */
  YYSYMBOL_T_ELSE = 10,                    /* T_ELSE  */
  YYSYMBOL_T_END = 11,                     /* T_END  */
  YYSYMBOL_T_TYPE = 12,                    /* T_TYPE  */
  YYSYMBOL_T_VAR = 13,                     /* T_VAR  */
  YYSYMBOL_T_IS = 14,                      /* T_IS  */
  YYSYMBOL_T_PRINT = 15,                   /* T_PRINT  */
  YYSYMBOL_T_RETURN = 16,                  /* T_RETURN  */
  YYSYMBOL_T_INTEGER = 17,                 /* T_INTEGER  */
  YYSYMBOL_T_REAL = 18,                    /* T_REAL  */
  YYSYMBOL_T_BOOLEAN = 19,                 /* T_BOOLEAN  */
  YYSYMBOL_T_CHAR = 20,                    /* T_CHAR  */
  YYSYMBOL_T_ROUTINE = 21,                 /* T_ROUTINE  */
  YYSYMBOL_T_ARRAY = 22,                   /* T_ARRAY  */
  YYSYMBOL_T_RECORD = 23,                  /* T_RECORD  */
  YYSYMBOL_T_TRUE = 24,                    /* T_TRUE  */
  YYSYMBOL_T_FALSE = 25,                   /* T_FALSE  */
  YYSYMBOL_T_LEXERROR = 26,                /* T_LEXERROR  */
  YYSYMBOL_T_ID = 27,                      /* T_ID  */
  YYSYMBOL_T_ICONST = 28,                  /* T_ICONST  */
  YYSYMBOL_T_RCONST = 29,                  /* T_RCONST  */
  YYSYMBOL_T_CCONST = 30,                  /* T_CCONST  */
  YYSYMBOL_T_EOF = 31,                     /* T_EOF  */
  YYSYMBOL_T_LESS = 32,                    /* T_LESS  */
  YYSYMBOL_T_GREAT = 33,                   /* T_GREAT  */
  YYSYMBOL_T_LESSOREQU = 34,               /* T_LESSOREQU  */
  YYSYMBOL_T_GREATOREQU = 35,              /* T_GREATOREQU  */
  YYSYMBOL_T_NOTEQU = 36,                  /* T_NOTEQU  */
  YYSYMBOL_T_EQU = 37,                     /* T_EQU  */
  YYSYMBOL_T_COLONEQU = 38,                /* T_COLONEQU  */
  YYSYMBOL_T_AND = 39,                     /* T_AND  */
  YYSYMBOL_T_OR = 40,                      /* T_OR  */
  YYSYMBOL_T_XOR = 41,                     /* T_XOR  */
  YYSYMBOL_T_ADDOP = 42,                   /* T_ADDOP  */
  YYSYMBOL_T_MULTOP = 43,                  /* T_MULTOP  */
  YYSYMBOL_T_SUBTROP = 44,                 /* T_SUBTROP  */
  YYSYMBOL_T_DIVOP = 45,                   /* T_DIVOP  */
  YYSYMBOL_T_MODOP = 46,                   /* T_MODOP  */
  YYSYMBOL_T_LPAREN = 47,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 48,                  /* T_RPAREN  */
  YYSYMBOL_T_LBRACK = 49,                  /* T_LBRACK  */
  YYSYMBOL_T_RBRACK = 50,                  /* T_RBRACK  */
  YYSYMBOL_T_DOTDOT = 51,                  /* T_DOTDOT  */
  YYSYMBOL_T_DOT = 52,                     /* T_DOT  */
  YYSYMBOL_T_COMMA = 53,                   /* T_COMMA  */
  YYSYMBOL_T_COLON = 54,                   /* T_COLON  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_Program = 56,                   /* Program  */
  YYSYMBOL_Programs = 57,                  /* Programs  */
  YYSYMBOL_SimpleDeclaration = 58,         /* SimpleDeclaration  */
  YYSYMBOL_VariableDeclaration = 59,       /* VariableDeclaration  */
  YYSYMBOL_TypeDeclaration = 60,           /* TypeDeclaration  */
  YYSYMBOL_RoutineDeclaration = 61,        /* RoutineDeclaration  */
  YYSYMBOL_Parameters = 62,                /* Parameters  */
  YYSYMBOL_ParameterDeclarations = 63,     /* ParameterDeclarations  */
  YYSYMBOL_ParameterDeclaration = 64,      /* ParameterDeclaration  */
  YYSYMBOL_Type = 65,                      /* Type  */
  YYSYMBOL_PrimitiveType = 66,             /* PrimitiveType  */
  YYSYMBOL_RecordType = 67,                /* RecordType  */
  YYSYMBOL_VariableDeclarations = 68,      /* VariableDeclarations  */
  YYSYMBOL_ArrayType = 69,                 /* ArrayType  */
  YYSYMBOL_Body = 70,                      /* Body  */
  YYSYMBOL_Bodies = 71,                    /* Bodies  */
  YYSYMBOL_Statement = 72,                 /* Statement  */
  YYSYMBOL_Assignment = 73,                /* Assignment  */
  YYSYMBOL_RoutineCall = 74,               /* RoutineCall  */
  YYSYMBOL_Expressions = 75,               /* Expressions  */
  YYSYMBOL_WhileLoop = 76,                 /* WhileLoop  */
  YYSYMBOL_ForLoop = 77,                   /* ForLoop  */
  YYSYMBOL_Range = 78,                     /* Range  */
  YYSYMBOL_IfStatement = 79,               /* IfStatement  */
  YYSYMBOL_Expression = 80,                /* Expression  */
  YYSYMBOL_Relation = 81,                  /* Relation  */
  YYSYMBOL_Simple = 82,                    /* Simple  */
  YYSYMBOL_Factor = 83,                    /* Factor  */
  YYSYMBOL_Summand = 84,                   /* Summand  */
  YYSYMBOL_Primary = 85,                   /* Primary  */
  YYSYMBOL_ModifiablePrimary = 86,         /* ModifiablePrimary  */
  YYSYMBOL_ID_ARRAY = 87,                  /* ID_ARRAY  */
  YYSYMBOL_Identifiers_ARRAY = 88          /* Identifiers_ARRAY  */
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
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   309


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   140,   140,   141,   144,   145,   146,   149,   150,   156,
     157,   158,   161,   167,   168,   171,   175,   176,   179,   182,
     183,   184,   185,   188,   189,   190,   191,   194,   198,   199,
     202,   207,   208,   209,   212,   213,   214,   217,   218,   219,
     220,   221,   222,   223,   226,   230,   231,   235,   236,   239,
     242,   245,   246,   249,   250,   254,   255,   256,   257,   269,
     270,   271,   272,   273,   274,   275,   279,   280,   281,   282,
     287,   288,   289,   292,   293,   296,   297,   298,   299,   300,
     301,   316,   317,   320,   321,   322,   325,   326
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
  "\"end of file\"", "error", "\"invalid token\"", "T_FOR", "T_WHILE",
  "T_LOOP", "T_IN", "T_REVERSE", "T_IF", "T_THEN", "T_ELSE", "T_END",
  "T_TYPE", "T_VAR", "T_IS", "T_PRINT", "T_RETURN", "T_INTEGER", "T_REAL",
  "T_BOOLEAN", "T_CHAR", "T_ROUTINE", "T_ARRAY", "T_RECORD", "T_TRUE",
  "T_FALSE", "T_LEXERROR", "T_ID", "T_ICONST", "T_RCONST", "T_CCONST",
  "T_EOF", "T_LESS", "T_GREAT", "T_LESSOREQU", "T_GREATOREQU", "T_NOTEQU",
  "T_EQU", "T_COLONEQU", "T_AND", "T_OR", "T_XOR", "T_ADDOP", "T_MULTOP",
  "T_SUBTROP", "T_DIVOP", "T_MODOP", "T_LPAREN", "T_RPAREN", "T_LBRACK",
  "T_RBRACK", "T_DOTDOT", "T_DOT", "T_COMMA", "T_COLON", "$accept",
  "Program", "Programs", "SimpleDeclaration", "VariableDeclaration",
  "TypeDeclaration", "RoutineDeclaration", "Parameters",
  "ParameterDeclarations", "ParameterDeclaration", "Type", "PrimitiveType",
  "RecordType", "VariableDeclarations", "ArrayType", "Body", "Bodies",
  "Statement", "Assignment", "RoutineCall", "Expressions", "WhileLoop",
  "ForLoop", "Range", "IfStatement", "Expression", "Relation", "Simple",
  "Factor", "Summand", "Primary", "ModifiablePrimary", "ID_ARRAY",
  "Identifiers_ARRAY", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-123)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      91,   -14,    -2,     3,    33,    71,  -123,  -123,    71,    22,
      -6,    24,  -123,  -123,  -123,    71,    71,  -123,   121,    95,
     121,    17,  -123,  -123,  -123,  -123,  -123,  -123,     0,    68,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,    47,  -123,  -123,
    -123,    95,  -123,    67,    96,   -31,   -41,  -123,  -123,    49,
      85,    59,    69,    62,    95,    68,   115,    95,    90,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,   118,    95,   121,    -3,    17,  -123,    99,
    -123,  -123,   100,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,    82,   121,    62,   121,    97,   124,    95,    95,   105,
     116,    28,    82,   153,    82,  -123,  -123,  -123,  -123,  -123,
     127,   152,  -123,  -123,    95,  -123,   161,   163,   160,    95,
      95,    29,    82,  -123,    82,  -123,  -123,    95,    82,   120,
      -1,   166,    82,    82,   125,   126,    95,   128,  -123,  -123,
    -123,  -123,   164,    97,    95,   129,    82,   167,    51,  -123,
    -123,    29,  -123,  -123,  -123,   130,    95,   168,  -123,    82,
    -123,  -123,    95,  -123,  -123,   171,  -123,  -123
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     1,     4,     2,     0,     0,     3,     0,     0,
       0,     0,     5,     6,    23,    24,    25,    26,     0,    28,
      22,    12,    19,    21,    20,    78,    79,    83,    75,    77,
      76,     0,    11,    55,    59,    66,    70,    73,    80,    81,
      10,     0,     0,    16,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
      29,    27,     0,    74,    56,    57,    58,    60,    62,    61,
      63,    65,    64,    67,    68,    69,    71,    72,    82,     9,
      18,    31,     0,    16,     0,    84,     0,     0,     0,     0,
       0,    45,    34,     0,    34,    37,    38,    39,    40,    41,
       0,     0,    17,    30,     0,    85,     0,     0,     0,     0,
       0,     0,    34,    32,    34,    14,    33,     0,    31,     0,
       0,     0,    31,    31,     0,     0,     0,     0,    47,    35,
      36,    44,     0,    86,     0,     0,    31,     0,     0,    43,
      42,     0,    46,    13,    87,     0,     0,     0,    49,    31,
      54,    48,     0,    51,    50,     0,    52,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,    52,     2,   -24,  -123,   172,  -123,    74,   106,
     -11,  -123,  -123,   131,  -123,  -122,   -95,   -62,  -123,  -123,
      23,  -123,  -123,  -123,  -123,   -19,  -123,    92,     7,  -123,
    -123,   -69,  -123,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,    14,   112,     6,     7,    16,    52,    78,    53,
      31,    32,    33,    56,    34,   113,   133,   114,   115,   116,
     147,   117,   118,   141,   119,   148,    43,    44,    45,    46,
      47,    48,    49,   125
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    71,     5,    72,    98,    55,   154,    15,    19,    50,
      15,   101,    68,     9,    69,    70,   152,    15,    15,   136,
     157,   158,    58,    35,    36,    10,    37,    38,    39,    40,
      11,    55,   120,    12,   167,    79,    18,   149,    82,   150,
      84,    85,    86,   120,    51,   120,    41,   175,    20,    54,
     134,   102,   134,    35,    36,    99,    37,    38,    39,    40,
      17,   169,   170,   120,   100,   120,   -83,    22,    23,   120,
     134,    21,   134,   120,   120,   131,    41,    57,    96,    97,
     -83,     2,   146,     1,     2,   106,   107,   120,   127,   128,
     108,   121,     3,   123,     1,     2,    57,   109,   110,    74,
     120,    73,    13,     1,     2,   139,    59,    60,    61,   111,
     144,   145,     3,    75,   132,    77,   132,    76,   151,    35,
      36,   155,    37,    38,    39,    40,    81,   161,    62,    63,
      64,    65,    66,    67,   132,   165,   132,    83,    24,    25,
      26,    27,    41,    28,    29,    37,   124,   173,    30,   104,
     105,   126,   129,   176,    87,    88,    89,    90,    91,    92,
      93,    94,    95,   130,   135,   137,   138,   140,   142,   143,
     153,   156,     8,   159,   160,   163,   162,   122,   168,   174,
     166,   172,   177,   103,   171,   164,    80
};

static const yytype_uint8 yycheck[] =
{
      19,    42,     0,    44,    73,    29,     7,     5,    14,    20,
       8,    14,    43,    27,    45,    46,   138,    15,    16,   114,
     142,   143,    41,    24,    25,    27,    27,    28,    29,    30,
      27,    55,   101,     0,   156,    54,    14,   132,    57,   134,
      59,    60,    61,   112,    27,   114,    47,   169,    54,    49,
     112,    54,   114,    24,    25,    74,    27,    28,    29,    30,
       8,    10,    11,   132,    75,   134,    38,    15,    16,   138,
     132,    47,   134,   142,   143,    47,    47,    49,    71,    72,
      52,    13,    53,    12,    13,     3,     4,   156,   107,   108,
       8,   102,    21,   104,    12,    13,    49,    15,    16,    14,
     169,    52,    31,    12,    13,   124,    39,    40,    41,    27,
     129,   130,    21,    54,   112,    53,   114,    48,   137,    24,
      25,   140,    27,    28,    29,    30,    11,   146,    32,    33,
      34,    35,    36,    37,   132,   154,   134,    47,    17,    18,
      19,    20,    47,    22,    23,    27,    49,   166,    27,    50,
      50,    27,    47,   172,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    47,    11,    38,    14,     6,     5,     9,
      50,     5,     0,    48,    48,    11,    48,   103,    11,    11,
      51,    51,    11,    77,   161,   153,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    13,    21,    56,    58,    59,    60,    61,    27,
      27,    27,     0,    31,    57,    58,    61,    57,    14,    14,
      54,    47,    57,    57,    17,    18,    19,    20,    22,    23,
      27,    65,    66,    67,    69,    24,    25,    27,    28,    29,
      30,    47,    80,    81,    82,    83,    84,    85,    86,    87,
      65,    27,    62,    64,    49,    59,    68,    49,    80,    39,
      40,    41,    32,    33,    34,    35,    36,    37,    43,    45,
      46,    42,    44,    52,    14,    54,    48,    53,    63,    80,
      68,    11,    80,    47,    80,    80,    80,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    83,    83,    86,    80,
      65,    14,    54,    64,    50,    50,     3,     4,     8,    15,
      16,    27,    58,    70,    72,    73,    74,    76,    77,    79,
      86,    65,    63,    65,    49,    88,    27,    80,    80,    47,
      47,    47,    58,    71,    72,    11,    71,    38,    14,    80,
       6,    78,     5,     9,    80,    80,    53,    75,    80,    71,
      71,    80,    70,    50,     7,    80,     5,    70,    70,    48,
      48,    80,    48,    11,    88,    80,    51,    70,    11,    10,
      11,    75,    51,    80,    11,    70,    80,    11
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    57,    58,    58,    59,
      59,    59,    60,    61,    61,    62,    63,    63,    64,    65,
      65,    65,    65,    66,    66,    66,    66,    67,    68,    68,
      69,    70,    70,    70,    71,    71,    71,    72,    72,    72,
      72,    72,    72,    72,    73,    74,    74,    75,    75,    76,
      77,    78,    78,    79,    79,    80,    80,    80,    80,    81,
      81,    81,    81,    81,    81,    81,    82,    82,    82,    82,
      83,    83,    83,    84,    84,    85,    85,    85,    85,    85,
      85,    86,    86,    87,    87,    87,    88,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     2,     1,     1,     6,
       4,     4,     4,    10,     8,     2,     0,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     2,
       5,     0,     2,     2,     0,     2,     2,     1,     1,     1,
       1,     1,     4,     4,     3,     1,     4,     1,     3,     5,
       6,     4,     5,     7,     5,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     4,     5,     3,     4
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
  case 2: /* Program: SimpleDeclaration Programs  */
#line 140 "Analyser.y"
                                        {root = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "root", "ROOT");}
#line 1302 "Analyser.tab.c"
    break;

  case 3: /* Program: RoutineDeclaration Programs  */
#line 141 "Analyser.y"
                                        {root = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "root", "ROOT");}
#line 1308 "Analyser.tab.c"
    break;

  case 4: /* Programs: T_EOF  */
#line 144 "Analyser.y"
                                         {(yyval.nodeList) = vector<Node*>();}
#line 1314 "Analyser.tab.c"
    break;

  case 5: /* Programs: SimpleDeclaration Programs  */
#line 145 "Analyser.y"
                                        {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1320 "Analyser.tab.c"
    break;

  case 6: /* Programs: RoutineDeclaration Programs  */
#line 146 "Analyser.y"
                                        {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1326 "Analyser.tab.c"
    break;

  case 7: /* SimpleDeclaration: VariableDeclaration  */
#line 149 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1332 "Analyser.tab.c"
    break;

  case 8: /* SimpleDeclaration: TypeDeclaration  */
#line 150 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1338 "Analyser.tab.c"
    break;

  case 9: /* VariableDeclaration: T_VAR T_ID T_COLON Type T_IS Expression  */
#line 156 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-4].string))), (yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "var_decl_colon_is", "colon is");}
#line 1344 "Analyser.tab.c"
    break;

  case 10: /* VariableDeclaration: T_VAR T_ID T_COLON Type  */
#line 157 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-2].string))), (yyvsp[0].nodeLink), "var_decl_colon", "colon");}
#line 1350 "Analyser.tab.c"
    break;

  case 11: /* VariableDeclaration: T_VAR T_ID T_IS Expression  */
#line 158 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-2].string))), (yyvsp[0].nodeLink), "var_decl_is", "is");}
#line 1356 "Analyser.tab.c"
    break;

  case 12: /* TypeDeclaration: T_TYPE T_ID T_IS Type  */
#line 161 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-2].string))), (yyvsp[0].nodeLink), "type_decl_is", "is");}
#line 1362 "Analyser.tab.c"
    break;

  case 13: /* RoutineDeclaration: T_ROUTINE T_ID T_LPAREN Parameters T_RPAREN T_COLON Type T_IS Body T_END  */
#line 167 "Analyser.y"
                                                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-8].string))), (yyvsp[-6].nodeLink), (yyvsp[-3].nodeLink),(yyvsp[-1].nodeLink), "routin_decl_type", "routine");}
#line 1368 "Analyser.tab.c"
    break;

  case 14: /* RoutineDeclaration: T_ROUTINE T_ID T_LPAREN Parameters T_RPAREN T_IS Body T_END  */
#line 168 "Analyser.y"
                                                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-6].string))), (yyvsp[-4].nodeLink), (yyvsp[-1].nodeLink), "routin_decl", "routine");}
#line 1374 "Analyser.tab.c"
    break;

  case 15: /* Parameters: ParameterDeclaration ParameterDeclarations  */
#line 171 "Analyser.y"
                                                                                                {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "parameters", "()");}
#line 1380 "Analyser.tab.c"
    break;

  case 16: /* ParameterDeclarations: %empty  */
#line 175 "Analyser.y"
                                                                                                {(yyval.nodeList) = vector<Node*>();}
#line 1386 "Analyser.tab.c"
    break;

  case 17: /* ParameterDeclarations: T_COMMA ParameterDeclaration ParameterDeclarations  */
#line 176 "Analyser.y"
                                                                                                {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1392 "Analyser.tab.c"
    break;

  case 18: /* ParameterDeclaration: T_ID T_COLON Type  */
#line 179 "Analyser.y"
                                            {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-2].string))), (yyvsp[0].nodeLink), "T_COLON", ":");}
#line 1398 "Analyser.tab.c"
    break;

  case 19: /* Type: PrimitiveType  */
#line 182 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1404 "Analyser.tab.c"
    break;

  case 20: /* Type: ArrayType  */
#line 183 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1410 "Analyser.tab.c"
    break;

  case 21: /* Type: RecordType  */
#line 184 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1416 "Analyser.tab.c"
    break;

  case 22: /* Type: T_ID  */
#line 185 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_ID", (yyvsp[0].string));}
#line 1422 "Analyser.tab.c"
    break;

  case 23: /* PrimitiveType: T_INTEGER  */
#line 188 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_INTEGER", "integer");}
#line 1428 "Analyser.tab.c"
    break;

  case 24: /* PrimitiveType: T_REAL  */
#line 189 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_REAL", "real");}
#line 1434 "Analyser.tab.c"
    break;

  case 25: /* PrimitiveType: T_BOOLEAN  */
#line 190 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_BOOLEAN", "boolean");}
#line 1440 "Analyser.tab.c"
    break;

  case 26: /* PrimitiveType: T_CHAR  */
#line 191 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_CHAR", "char");}
#line 1446 "Analyser.tab.c"
    break;

  case 27: /* RecordType: T_RECORD VariableDeclarations T_END  */
#line 194 "Analyser.y"
                                                 {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeList), "T_RECORD", "record");}
#line 1452 "Analyser.tab.c"
    break;

  case 28: /* VariableDeclarations: %empty  */
#line 198 "Analyser.y"
                                                                {(yyval.nodeList) = vector<Node*>();}
#line 1458 "Analyser.tab.c"
    break;

  case 29: /* VariableDeclarations: VariableDeclaration VariableDeclarations  */
#line 199 "Analyser.y"
                                                                {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1464 "Analyser.tab.c"
    break;

  case 30: /* ArrayType: T_ARRAY T_LBRACK Expression T_RBRACK Type  */
#line 202 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_ARRAY", "array");}
#line 1470 "Analyser.tab.c"
    break;

  case 31: /* Body: %empty  */
#line 207 "Analyser.y"
                                    {(yyval.nodeLink) = createNode("BODY", "BODY");}
#line 1476 "Analyser.tab.c"
    break;

  case 32: /* Body: SimpleDeclaration Bodies  */
#line 208 "Analyser.y"
                                    {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "BODY", "BODY");}
#line 1482 "Analyser.tab.c"
    break;

  case 33: /* Body: Statement Bodies  */
#line 209 "Analyser.y"
                                    {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "BODY", "BODY");}
#line 1488 "Analyser.tab.c"
    break;

  case 34: /* Bodies: %empty  */
#line 212 "Analyser.y"
                                    {(yyval.nodeList) = vector<Node*>();}
#line 1494 "Analyser.tab.c"
    break;

  case 35: /* Bodies: SimpleDeclaration Bodies  */
#line 213 "Analyser.y"
                                    {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1500 "Analyser.tab.c"
    break;

  case 36: /* Bodies: Statement Bodies  */
#line 214 "Analyser.y"
                                    {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1506 "Analyser.tab.c"
    break;

  case 37: /* Statement: Assignment  */
#line 217 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1512 "Analyser.tab.c"
    break;

  case 38: /* Statement: RoutineCall  */
#line 218 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1518 "Analyser.tab.c"
    break;

  case 39: /* Statement: WhileLoop  */
#line 219 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1524 "Analyser.tab.c"
    break;

  case 40: /* Statement: ForLoop  */
#line 220 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1530 "Analyser.tab.c"
    break;

  case 41: /* Statement: IfStatement  */
#line 221 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1536 "Analyser.tab.c"
    break;

  case 42: /* Statement: T_RETURN T_LPAREN Expression T_RPAREN  */
#line 222 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode((yyvsp[-1].nodeLink), "T_RETURN", "return");}
#line 1542 "Analyser.tab.c"
    break;

  case 43: /* Statement: T_PRINT T_LPAREN Expression T_RPAREN  */
#line 223 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode((yyvsp[-1].nodeLink), "T_PRINT", "print");}
#line 1548 "Analyser.tab.c"
    break;

  case 44: /* Assignment: ModifiablePrimary T_COLONEQU Expression  */
#line 226 "Analyser.y"
                                                     {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_COLONEQU", ":=");}
#line 1554 "Analyser.tab.c"
    break;

  case 45: /* RoutineCall: T_ID  */
#line 230 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode("T_ID", (yyvsp[0].string));}
#line 1560 "Analyser.tab.c"
    break;

  case 46: /* RoutineCall: T_ID T_LPAREN Expressions T_RPAREN  */
#line 231 "Analyser.y"
                                                    {(yyval.nodeLink) = combineNodes(new Node(Token("T_ID", (yyvsp[-3].string))), (yyvsp[-1].nodeList), "RoutineCall", "ROUTINECALL");}
#line 1566 "Analyser.tab.c"
    break;

  case 47: /* Expressions: Expression  */
#line 235 "Analyser.y"
                                                    {(yyval.nodeList) = collectNodes((yyvsp[0].nodeLink));}
#line 1572 "Analyser.tab.c"
    break;

  case 48: /* Expressions: T_COMMA Expression Expressions  */
#line 236 "Analyser.y"
                                                    {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1578 "Analyser.tab.c"
    break;

  case 49: /* WhileLoop: T_WHILE Expression T_LOOP Body T_END  */
#line 239 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode((yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), "T_WHILE", "while");}
#line 1584 "Analyser.tab.c"
    break;

  case 50: /* ForLoop: T_FOR T_ID Range T_LOOP Body T_END  */
#line 242 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-4].string))), (yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), "T_FOR", "for");}
#line 1590 "Analyser.tab.c"
    break;

  case 51: /* Range: T_IN Expression T_DOTDOT Expression  */
#line 245 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_IN", "in");}
#line 1596 "Analyser.tab.c"
    break;

  case 52: /* Range: T_IN T_REVERSE Expression T_DOTDOT Expression  */
#line 246 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_IN_REVERSE", "in_reverse");}
#line 1602 "Analyser.tab.c"
    break;

  case 53: /* IfStatement: T_IF Expression T_THEN Body T_ELSE Body T_END  */
#line 249 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode((yyvsp[-5].nodeLink), (yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), "T_IF_ELSE", "if else");}
#line 1608 "Analyser.tab.c"
    break;

  case 54: /* IfStatement: T_IF Expression T_THEN Body T_END  */
#line 250 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode((yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), "T_IF", "if");}
#line 1614 "Analyser.tab.c"
    break;

  case 55: /* Expression: Relation  */
#line 254 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1620 "Analyser.tab.c"
    break;

  case 56: /* Expression: Relation T_AND Expression  */
#line 255 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_AND", "and");}
#line 1626 "Analyser.tab.c"
    break;

  case 57: /* Expression: Relation T_OR Expression  */
#line 256 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_OR", "or");}
#line 1632 "Analyser.tab.c"
    break;

  case 58: /* Expression: Relation T_XOR Expression  */
#line 257 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_XOR", "xor");}
#line 1638 "Analyser.tab.c"
    break;

  case 59: /* Relation: Simple  */
#line 269 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1644 "Analyser.tab.c"
    break;

  case 60: /* Relation: Simple T_LESS Simple  */
#line 270 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_LESS", "<");}
#line 1650 "Analyser.tab.c"
    break;

  case 61: /* Relation: Simple T_LESSOREQU Simple  */
#line 271 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_LESSOREQU", "<=");}
#line 1656 "Analyser.tab.c"
    break;

  case 62: /* Relation: Simple T_GREAT Simple  */
#line 272 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_GREAT", ">");}
#line 1662 "Analyser.tab.c"
    break;

  case 63: /* Relation: Simple T_GREATOREQU Simple  */
#line 273 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_GREATOREQU", ">=");}
#line 1668 "Analyser.tab.c"
    break;

  case 64: /* Relation: Simple T_EQU Simple  */
#line 274 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_EQU", "=");}
#line 1674 "Analyser.tab.c"
    break;

  case 65: /* Relation: Simple T_NOTEQU Simple  */
#line 275 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_NOTEQU", "/=");}
#line 1680 "Analyser.tab.c"
    break;

  case 66: /* Simple: Factor  */
#line 279 "Analyser.y"
                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1686 "Analyser.tab.c"
    break;

  case 67: /* Simple: Factor T_MULTOP Simple  */
#line 280 "Analyser.y"
                                   {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_MULTOP", "*");}
#line 1692 "Analyser.tab.c"
    break;

  case 68: /* Simple: Factor T_DIVOP Simple  */
#line 281 "Analyser.y"
                                   {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_DIVOP", "/");}
#line 1698 "Analyser.tab.c"
    break;

  case 69: /* Simple: Factor T_MODOP Simple  */
#line 282 "Analyser.y"
                                   {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_MODOP", "%");}
#line 1704 "Analyser.tab.c"
    break;

  case 70: /* Factor: Summand  */
#line 287 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1710 "Analyser.tab.c"
    break;

  case 71: /* Factor: Summand T_ADDOP Factor  */
#line 288 "Analyser.y"
                                      {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_ADDOP", "+");}
#line 1716 "Analyser.tab.c"
    break;

  case 72: /* Factor: Summand T_SUBTROP Factor  */
#line 289 "Analyser.y"
                                      {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_SUBTROP", "-");}
#line 1722 "Analyser.tab.c"
    break;

  case 73: /* Summand: Primary  */
#line 292 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1728 "Analyser.tab.c"
    break;

  case 74: /* Summand: T_LPAREN Expression T_LPAREN  */
#line 293 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[-1].nodeLink);}
#line 1734 "Analyser.tab.c"
    break;

  case 75: /* Primary: T_ICONST  */
#line 296 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_ICONST", to_string((yyvsp[0].integer)));}
#line 1740 "Analyser.tab.c"
    break;

  case 76: /* Primary: T_CCONST  */
#line 297 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_CCONST", (yyvsp[0].string));}
#line 1746 "Analyser.tab.c"
    break;

  case 77: /* Primary: T_RCONST  */
#line 298 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_RCONST", to_string((yyvsp[0].real)));}
#line 1752 "Analyser.tab.c"
    break;

  case 78: /* Primary: T_TRUE  */
#line 299 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_TRUE", "true");}
#line 1758 "Analyser.tab.c"
    break;

  case 79: /* Primary: T_FALSE  */
#line 300 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_FALSE", "false");}
#line 1764 "Analyser.tab.c"
    break;

  case 80: /* Primary: ModifiablePrimary  */
#line 301 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1770 "Analyser.tab.c"
    break;

  case 81: /* ModifiablePrimary: ID_ARRAY  */
#line 316 "Analyser.y"
                                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1776 "Analyser.tab.c"
    break;

  case 82: /* ModifiablePrimary: ID_ARRAY T_DOT ModifiablePrimary  */
#line 317 "Analyser.y"
                                                                    {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink),"T_DOT", ".");}
#line 1782 "Analyser.tab.c"
    break;

  case 83: /* ID_ARRAY: T_ID  */
#line 320 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode("T_ID", (yyvsp[0].string));}
#line 1788 "Analyser.tab.c"
    break;

  case 84: /* ID_ARRAY: T_ID T_LBRACK Expression T_RBRACK  */
#line 321 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-3].string))), (yyvsp[-1].nodeLink), "BRACKS", "[]");}
#line 1794 "Analyser.tab.c"
    break;

  case 85: /* ID_ARRAY: T_ID T_LBRACK Expression T_RBRACK Identifiers_ARRAY  */
#line 322 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-4].string))), (yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "BRACKS", "[]");}
#line 1800 "Analyser.tab.c"
    break;

  case 86: /* Identifiers_ARRAY: T_LBRACK Expression T_RBRACK  */
#line 325 "Analyser.y"
                                                                    {(yyval.nodeLink) = createNode((yyvsp[-1].nodeLink), "BRACKS", "[]");}
#line 1806 "Analyser.tab.c"
    break;

  case 87: /* Identifiers_ARRAY: T_LBRACK Expression T_RBRACK Identifiers_ARRAY  */
#line 326 "Analyser.y"
                                                                    {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "BRACKS", "[]");}
#line 1812 "Analyser.tab.c"
    break;


#line 1816 "Analyser.tab.c"

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

#line 329 "Analyser.y"


Node* generateAST (string inputfile) {
    yyin = fopen(inputfile.c_str(), "r");
    yyparse();
    fclose(yyin);

    return root;
}
