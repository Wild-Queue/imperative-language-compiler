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
        cout << "Syntax Error on Line " << "some line" << endl;
        cerr << s << ", line " << yylineno << endl;
        exit(1);
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
  YYSYMBOL_T_ID = 26,                      /* T_ID  */
  YYSYMBOL_T_ICONST = 27,                  /* T_ICONST  */
  YYSYMBOL_T_RCONST = 28,                  /* T_RCONST  */
  YYSYMBOL_T_CCONST = 29,                  /* T_CCONST  */
  YYSYMBOL_T_EOF = 30,                     /* T_EOF  */
  YYSYMBOL_T_LESS = 31,                    /* T_LESS  */
  YYSYMBOL_T_GREAT = 32,                   /* T_GREAT  */
  YYSYMBOL_T_LESSOREQU = 33,               /* T_LESSOREQU  */
  YYSYMBOL_T_GREATOREQU = 34,              /* T_GREATOREQU  */
  YYSYMBOL_T_NOTEQU = 35,                  /* T_NOTEQU  */
  YYSYMBOL_T_EQU = 36,                     /* T_EQU  */
  YYSYMBOL_T_COLONEQU = 37,                /* T_COLONEQU  */
  YYSYMBOL_T_AND = 38,                     /* T_AND  */
  YYSYMBOL_T_OR = 39,                      /* T_OR  */
  YYSYMBOL_T_XOR = 40,                     /* T_XOR  */
  YYSYMBOL_T_ADDOP = 41,                   /* T_ADDOP  */
  YYSYMBOL_T_MULTOP = 42,                  /* T_MULTOP  */
  YYSYMBOL_T_SUBTROP = 43,                 /* T_SUBTROP  */
  YYSYMBOL_T_DIVOP = 44,                   /* T_DIVOP  */
  YYSYMBOL_T_MODOP = 45,                   /* T_MODOP  */
  YYSYMBOL_T_LPAREN = 46,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 47,                  /* T_RPAREN  */
  YYSYMBOL_T_LBRACK = 48,                  /* T_LBRACK  */
  YYSYMBOL_T_RBRACK = 49,                  /* T_RBRACK  */
  YYSYMBOL_T_DOTDOT = 50,                  /* T_DOTDOT  */
  YYSYMBOL_T_DOT = 51,                     /* T_DOT  */
  YYSYMBOL_T_COMMA = 52,                   /* T_COMMA  */
  YYSYMBOL_T_COLON = 53,                   /* T_COLON  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_Program = 55,                   /* Program  */
  YYSYMBOL_Programs = 56,                  /* Programs  */
  YYSYMBOL_SimpleDeclaration = 57,         /* SimpleDeclaration  */
  YYSYMBOL_VariableDeclaration = 58,       /* VariableDeclaration  */
  YYSYMBOL_TypeDeclaration = 59,           /* TypeDeclaration  */
  YYSYMBOL_RoutineDeclaration = 60,        /* RoutineDeclaration  */
  YYSYMBOL_Parameters = 61,                /* Parameters  */
  YYSYMBOL_ParameterDeclarations = 62,     /* ParameterDeclarations  */
  YYSYMBOL_ParameterDeclaration = 63,      /* ParameterDeclaration  */
  YYSYMBOL_Type = 64,                      /* Type  */
  YYSYMBOL_PrimitiveType = 65,             /* PrimitiveType  */
  YYSYMBOL_RecordType = 66,                /* RecordType  */
  YYSYMBOL_VariableDeclarations = 67,      /* VariableDeclarations  */
  YYSYMBOL_ArrayType = 68,                 /* ArrayType  */
  YYSYMBOL_Body = 69,                      /* Body  */
  YYSYMBOL_Bodies = 70,                    /* Bodies  */
  YYSYMBOL_Statement = 71,                 /* Statement  */
  YYSYMBOL_Assignment = 72,                /* Assignment  */
  YYSYMBOL_RoutineCall = 73,               /* RoutineCall  */
  YYSYMBOL_Expressions = 74,               /* Expressions  */
  YYSYMBOL_WhileLoop = 75,                 /* WhileLoop  */
  YYSYMBOL_ForLoop = 76,                   /* ForLoop  */
  YYSYMBOL_Range = 77,                     /* Range  */
  YYSYMBOL_IfStatement = 78,               /* IfStatement  */
  YYSYMBOL_Expression = 79,                /* Expression  */
  YYSYMBOL_Relation = 80,                  /* Relation  */
  YYSYMBOL_Simple = 81,                    /* Simple  */
  YYSYMBOL_Factor = 82,                    /* Factor  */
  YYSYMBOL_Summand = 83,                   /* Summand  */
  YYSYMBOL_Primary = 84,                   /* Primary  */
  YYSYMBOL_ModifiablePrimary = 85,         /* ModifiablePrimary  */
  YYSYMBOL_ID_ARRAY = 86,                  /* ID_ARRAY  */
  YYSYMBOL_Identifiers_ARRAY = 87          /* Identifiers_ARRAY  */
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
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   139,   139,   140,   143,   144,   145,   148,   149,   155,
     156,   157,   160,   166,   167,   170,   174,   175,   178,   181,
     182,   183,   184,   187,   188,   189,   190,   193,   197,   198,
     201,   206,   207,   208,   211,   212,   213,   216,   217,   218,
     219,   220,   221,   222,   225,   229,   230,   234,   235,   238,
     241,   244,   245,   248,   249,   253,   254,   255,   256,   268,
     269,   270,   271,   272,   273,   274,   278,   279,   280,   281,
     286,   287,   288,   291,   292,   295,   296,   297,   298,   299,
     300,   315,   316,   319,   320,   321,   324,   325
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
  "T_FALSE", "T_ID", "T_ICONST", "T_RCONST", "T_CCONST", "T_EOF", "T_LESS",
  "T_GREAT", "T_LESSOREQU", "T_GREATOREQU", "T_NOTEQU", "T_EQU",
  "T_COLONEQU", "T_AND", "T_OR", "T_XOR", "T_ADDOP", "T_MULTOP",
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

#define YYPACT_NINF (-124)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      83,   -20,    -2,     5,    37,    41,  -124,  -124,    41,    34,
      -9,    20,  -124,  -124,  -124,    41,    41,  -124,   120,   104,
     120,    44,  -124,  -124,  -124,  -124,  -124,  -124,    27,    85,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,    60,  -124,  -124,
    -124,   104,  -124,    63,   132,     7,   -29,  -124,  -124,    58,
      98,    62,    66,    65,   104,    85,   108,   104,    74,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,    96,   104,   120,    -3,    44,  -124,    75,
    -124,  -124,    76,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,    64,   120,    65,   120,    78,    97,   104,   104,    95,
      99,    46,    64,   133,    64,  -124,  -124,  -124,  -124,  -124,
     111,   135,  -124,  -124,   104,  -124,   145,   147,   160,   104,
     104,    32,    64,  -124,    64,  -124,  -124,   104,    64,   121,
       1,   166,    64,    64,   125,   126,   104,   127,  -124,  -124,
    -124,  -124,   164,    78,   104,   128,    64,   165,    71,  -124,
    -124,    32,  -124,  -124,  -124,   129,   104,   169,  -124,    64,
    -124,  -124,   104,  -124,  -124,   170,  -124,  -124
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
    -124,  -124,    91,     2,   -16,  -124,   177,  -124,    79,   106,
     -11,  -124,  -124,   130,  -124,  -123,   -98,  -111,  -124,  -124,
      23,  -124,  -124,  -124,  -124,   -19,  -124,    92,    14,  -124,
    -124,   -69,  -124,    33
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
      42,   134,     5,   134,    98,    19,     9,    15,   154,    50,
      15,   101,    71,    55,    72,   152,   136,    15,    15,   157,
     158,   134,    58,   134,    10,    35,    36,    37,    38,    39,
      40,    11,   120,   167,   149,    79,   150,    12,    82,    55,
      84,    85,    86,   120,    20,   120,   175,    41,    18,    68,
     102,    69,    70,     1,     2,    99,    35,    36,    37,    38,
      39,    40,     3,   120,   100,   120,    21,   106,   107,   120,
      51,    13,   108,   120,   120,    54,     1,     2,    41,   109,
     110,   169,   170,   -83,   146,    96,    97,   120,   127,   128,
     111,   121,   131,   123,    57,     1,     2,   -83,     2,    17,
     120,    59,    60,    61,     3,   139,    22,    23,    57,    73,
     144,   145,    74,    76,   132,    75,   132,    77,   151,    81,
      83,   155,    37,   126,   104,   105,   124,   161,    35,    36,
      37,    38,    39,    40,   132,   165,   132,    24,    25,    26,
      27,   129,    28,    29,   135,   130,    30,   173,   137,   138,
      41,   140,   142,   176,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    62,    63,    64,    65,    66,    67,   143,
     153,   156,   159,   160,   162,   163,   168,     8,   166,   172,
     174,   177,   122,   103,   171,    80,   164
};

static const yytype_uint8 yycheck[] =
{
      19,   112,     0,   114,    73,    14,    26,     5,     7,    20,
       8,    14,    41,    29,    43,   138,   114,    15,    16,   142,
     143,   132,    41,   134,    26,    24,    25,    26,    27,    28,
      29,    26,   101,   156,   132,    54,   134,     0,    57,    55,
      59,    60,    61,   112,    53,   114,   169,    46,    14,    42,
      53,    44,    45,    12,    13,    74,    24,    25,    26,    27,
      28,    29,    21,   132,    75,   134,    46,     3,     4,   138,
      26,    30,     8,   142,   143,    48,    12,    13,    46,    15,
      16,    10,    11,    37,    52,    71,    72,   156,   107,   108,
      26,   102,    46,   104,    48,    12,    13,    51,    13,     8,
     169,    38,    39,    40,    21,   124,    15,    16,    48,    51,
     129,   130,    14,    47,   112,    53,   114,    52,   137,    11,
      46,   140,    26,    26,    49,    49,    48,   146,    24,    25,
      26,    27,    28,    29,   132,   154,   134,    17,    18,    19,
      20,    46,    22,    23,    11,    46,    26,   166,    37,    14,
      46,     6,     5,   172,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    31,    32,    33,    34,    35,    36,     9,
      49,     5,    47,    47,    47,    11,    11,     0,    50,    50,
      11,    11,   103,    77,   161,    55,   153
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    13,    21,    55,    57,    58,    59,    60,    26,
      26,    26,     0,    30,    56,    57,    60,    56,    14,    14,
      53,    46,    56,    56,    17,    18,    19,    20,    22,    23,
      26,    64,    65,    66,    68,    24,    25,    26,    27,    28,
      29,    46,    79,    80,    81,    82,    83,    84,    85,    86,
      64,    26,    61,    63,    48,    58,    67,    48,    79,    38,
      39,    40,    31,    32,    33,    34,    35,    36,    42,    44,
      45,    41,    43,    51,    14,    53,    47,    52,    62,    79,
      67,    11,    79,    46,    79,    79,    79,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    82,    82,    85,    79,
      64,    14,    53,    63,    49,    49,     3,     4,     8,    15,
      16,    26,    57,    69,    71,    72,    73,    75,    76,    78,
      85,    64,    62,    64,    48,    87,    26,    79,    79,    46,
      46,    46,    57,    70,    71,    11,    70,    37,    14,    79,
       6,    77,     5,     9,    79,    79,    52,    74,    79,    70,
      70,    79,    69,    49,     7,    79,     5,    69,    69,    47,
      47,    79,    47,    11,    87,    79,    50,    69,    11,    10,
      11,    74,    50,    79,    11,    69,    79,    11
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    57,    57,    58,
      58,    58,    59,    60,    60,    61,    62,    62,    63,    64,
      64,    64,    64,    65,    65,    65,    65,    66,    67,    67,
      68,    69,    69,    69,    70,    70,    70,    71,    71,    71,
      71,    71,    71,    71,    72,    73,    73,    74,    74,    75,
      76,    77,    77,    78,    78,    79,    79,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    81,    81,    81,    81,
      82,    82,    82,    83,    83,    84,    84,    84,    84,    84,
      84,    85,    85,    86,    86,    86,    87,    87
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
#line 139 "Analyser.y"
                                        {root = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "root", "ROOT");}
#line 1301 "Analyser.tab.c"
    break;

  case 3: /* Program: RoutineDeclaration Programs  */
#line 140 "Analyser.y"
                                        {root = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "root", "ROOT");}
#line 1307 "Analyser.tab.c"
    break;

  case 4: /* Programs: T_EOF  */
#line 143 "Analyser.y"
                                         {(yyval.nodeList) = vector<Node*>();}
#line 1313 "Analyser.tab.c"
    break;

  case 5: /* Programs: SimpleDeclaration Programs  */
#line 144 "Analyser.y"
                                        {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1319 "Analyser.tab.c"
    break;

  case 6: /* Programs: RoutineDeclaration Programs  */
#line 145 "Analyser.y"
                                        {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1325 "Analyser.tab.c"
    break;

  case 7: /* SimpleDeclaration: VariableDeclaration  */
#line 148 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1331 "Analyser.tab.c"
    break;

  case 8: /* SimpleDeclaration: TypeDeclaration  */
#line 149 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1337 "Analyser.tab.c"
    break;

  case 9: /* VariableDeclaration: T_VAR T_ID T_COLON Type T_IS Expression  */
#line 155 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-4].string))), (yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "var_decl_colon_is", "colon is");}
#line 1343 "Analyser.tab.c"
    break;

  case 10: /* VariableDeclaration: T_VAR T_ID T_COLON Type  */
#line 156 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-2].string))), (yyvsp[0].nodeLink), "var_decl_colon", "colon");}
#line 1349 "Analyser.tab.c"
    break;

  case 11: /* VariableDeclaration: T_VAR T_ID T_IS Expression  */
#line 157 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-2].string))), (yyvsp[0].nodeLink), "var_decl_is", "is");}
#line 1355 "Analyser.tab.c"
    break;

  case 12: /* TypeDeclaration: T_TYPE T_ID T_IS Type  */
#line 160 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-2].string))), (yyvsp[0].nodeLink), "type_decl_is", "is");}
#line 1361 "Analyser.tab.c"
    break;

  case 13: /* RoutineDeclaration: T_ROUTINE T_ID T_LPAREN Parameters T_RPAREN T_COLON Type T_IS Body T_END  */
#line 166 "Analyser.y"
                                                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-8].string))), (yyvsp[-6].nodeLink), (yyvsp[-3].nodeLink),(yyvsp[-1].nodeLink), "routin_decl_type", "routine");}
#line 1367 "Analyser.tab.c"
    break;

  case 14: /* RoutineDeclaration: T_ROUTINE T_ID T_LPAREN Parameters T_RPAREN T_IS Body T_END  */
#line 167 "Analyser.y"
                                                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-6].string))), (yyvsp[-4].nodeLink), (yyvsp[-1].nodeLink), "routin_decl", "routine");}
#line 1373 "Analyser.tab.c"
    break;

  case 15: /* Parameters: ParameterDeclaration ParameterDeclarations  */
#line 170 "Analyser.y"
                                                                                                {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "parameters", "()");}
#line 1379 "Analyser.tab.c"
    break;

  case 16: /* ParameterDeclarations: %empty  */
#line 174 "Analyser.y"
                                                                                                {(yyval.nodeList) = vector<Node*>();}
#line 1385 "Analyser.tab.c"
    break;

  case 17: /* ParameterDeclarations: T_COMMA ParameterDeclaration ParameterDeclarations  */
#line 175 "Analyser.y"
                                                                                                {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1391 "Analyser.tab.c"
    break;

  case 18: /* ParameterDeclaration: T_ID T_COLON Type  */
#line 178 "Analyser.y"
                                            {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-2].string))), (yyvsp[0].nodeLink), "T_COLON", ":");}
#line 1397 "Analyser.tab.c"
    break;

  case 19: /* Type: PrimitiveType  */
#line 181 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1403 "Analyser.tab.c"
    break;

  case 20: /* Type: ArrayType  */
#line 182 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1409 "Analyser.tab.c"
    break;

  case 21: /* Type: RecordType  */
#line 183 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1415 "Analyser.tab.c"
    break;

  case 22: /* Type: T_ID  */
#line 184 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_ID", (yyvsp[0].string));}
#line 1421 "Analyser.tab.c"
    break;

  case 23: /* PrimitiveType: T_INTEGER  */
#line 187 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_INTEGER", "integer");}
#line 1427 "Analyser.tab.c"
    break;

  case 24: /* PrimitiveType: T_REAL  */
#line 188 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_REAL", "real");}
#line 1433 "Analyser.tab.c"
    break;

  case 25: /* PrimitiveType: T_BOOLEAN  */
#line 189 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_BOOLEAN", "boolean");}
#line 1439 "Analyser.tab.c"
    break;

  case 26: /* PrimitiveType: T_CHAR  */
#line 190 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_CHAR", "char");}
#line 1445 "Analyser.tab.c"
    break;

  case 27: /* RecordType: T_RECORD VariableDeclarations T_END  */
#line 193 "Analyser.y"
                                                 {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeList), "T_RECORD", "record");}
#line 1451 "Analyser.tab.c"
    break;

  case 28: /* VariableDeclarations: %empty  */
#line 197 "Analyser.y"
                                                                {(yyval.nodeList) = vector<Node*>();}
#line 1457 "Analyser.tab.c"
    break;

  case 29: /* VariableDeclarations: VariableDeclaration VariableDeclarations  */
#line 198 "Analyser.y"
                                                                {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1463 "Analyser.tab.c"
    break;

  case 30: /* ArrayType: T_ARRAY T_LBRACK Expression T_RBRACK Type  */
#line 201 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_ARRAY", "array");}
#line 1469 "Analyser.tab.c"
    break;

  case 31: /* Body: %empty  */
#line 206 "Analyser.y"
                                    {(yyval.nodeLink) = createNode("BODY", "BODY");}
#line 1475 "Analyser.tab.c"
    break;

  case 32: /* Body: SimpleDeclaration Bodies  */
#line 207 "Analyser.y"
                                    {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "BODY", "BODY");}
#line 1481 "Analyser.tab.c"
    break;

  case 33: /* Body: Statement Bodies  */
#line 208 "Analyser.y"
                                    {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "BODY", "BODY");}
#line 1487 "Analyser.tab.c"
    break;

  case 34: /* Bodies: %empty  */
#line 211 "Analyser.y"
                                    {(yyval.nodeList) = vector<Node*>();}
#line 1493 "Analyser.tab.c"
    break;

  case 35: /* Bodies: SimpleDeclaration Bodies  */
#line 212 "Analyser.y"
                                    {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1499 "Analyser.tab.c"
    break;

  case 36: /* Bodies: Statement Bodies  */
#line 213 "Analyser.y"
                                    {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1505 "Analyser.tab.c"
    break;

  case 37: /* Statement: Assignment  */
#line 216 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1511 "Analyser.tab.c"
    break;

  case 38: /* Statement: RoutineCall  */
#line 217 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1517 "Analyser.tab.c"
    break;

  case 39: /* Statement: WhileLoop  */
#line 218 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1523 "Analyser.tab.c"
    break;

  case 40: /* Statement: ForLoop  */
#line 219 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1529 "Analyser.tab.c"
    break;

  case 41: /* Statement: IfStatement  */
#line 220 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1535 "Analyser.tab.c"
    break;

  case 42: /* Statement: T_RETURN T_LPAREN Expression T_RPAREN  */
#line 221 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode((yyvsp[-1].nodeLink), "T_RETURN", "return");}
#line 1541 "Analyser.tab.c"
    break;

  case 43: /* Statement: T_PRINT T_LPAREN Expression T_RPAREN  */
#line 222 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode((yyvsp[-1].nodeLink), "T_PRINT", "print");}
#line 1547 "Analyser.tab.c"
    break;

  case 44: /* Assignment: ModifiablePrimary T_COLONEQU Expression  */
#line 225 "Analyser.y"
                                                     {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_COLONEQU", ":=");}
#line 1553 "Analyser.tab.c"
    break;

  case 45: /* RoutineCall: T_ID  */
#line 229 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode("T_ID", (yyvsp[0].string));}
#line 1559 "Analyser.tab.c"
    break;

  case 46: /* RoutineCall: T_ID T_LPAREN Expressions T_RPAREN  */
#line 230 "Analyser.y"
                                                    {(yyval.nodeLink) = combineNodes(new Node(Token("T_ID", (yyvsp[-3].string))), (yyvsp[-1].nodeList), "RoutineCall", "ROUTINECALL");}
#line 1565 "Analyser.tab.c"
    break;

  case 47: /* Expressions: Expression  */
#line 234 "Analyser.y"
                                                    {(yyval.nodeList) = collectNodes((yyvsp[0].nodeLink));}
#line 1571 "Analyser.tab.c"
    break;

  case 48: /* Expressions: T_COMMA Expression Expressions  */
#line 235 "Analyser.y"
                                                    {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1577 "Analyser.tab.c"
    break;

  case 49: /* WhileLoop: T_WHILE Expression T_LOOP Body T_END  */
#line 238 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode((yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), "T_WHILE", "while");}
#line 1583 "Analyser.tab.c"
    break;

  case 50: /* ForLoop: T_FOR T_ID Range T_LOOP Body T_END  */
#line 241 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-4].string))), (yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), "T_FOR", "for");}
#line 1589 "Analyser.tab.c"
    break;

  case 51: /* Range: T_IN Expression T_DOTDOT Expression  */
#line 244 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_IN", "in");}
#line 1595 "Analyser.tab.c"
    break;

  case 52: /* Range: T_IN T_REVERSE Expression T_DOTDOT Expression  */
#line 245 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_IN_REVERSE", "in_reverse");}
#line 1601 "Analyser.tab.c"
    break;

  case 53: /* IfStatement: T_IF Expression T_THEN Body T_ELSE Body T_END  */
#line 248 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode((yyvsp[-5].nodeLink), (yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), "T_IF_ELSE", "if else");}
#line 1607 "Analyser.tab.c"
    break;

  case 54: /* IfStatement: T_IF Expression T_THEN Body T_END  */
#line 249 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode((yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), "T_IF", "if");}
#line 1613 "Analyser.tab.c"
    break;

  case 55: /* Expression: Relation  */
#line 253 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1619 "Analyser.tab.c"
    break;

  case 56: /* Expression: Relation T_AND Expression  */
#line 254 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_AND", "and");}
#line 1625 "Analyser.tab.c"
    break;

  case 57: /* Expression: Relation T_OR Expression  */
#line 255 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_OR", "or");}
#line 1631 "Analyser.tab.c"
    break;

  case 58: /* Expression: Relation T_XOR Expression  */
#line 256 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_XOR", "xor");}
#line 1637 "Analyser.tab.c"
    break;

  case 59: /* Relation: Simple  */
#line 268 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1643 "Analyser.tab.c"
    break;

  case 60: /* Relation: Simple T_LESS Simple  */
#line 269 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_LESS", "<");}
#line 1649 "Analyser.tab.c"
    break;

  case 61: /* Relation: Simple T_LESSOREQU Simple  */
#line 270 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_LESSOREQU", "<=");}
#line 1655 "Analyser.tab.c"
    break;

  case 62: /* Relation: Simple T_GREAT Simple  */
#line 271 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_GREAT", ">");}
#line 1661 "Analyser.tab.c"
    break;

  case 63: /* Relation: Simple T_GREATOREQU Simple  */
#line 272 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_GREATOREQU", ">=");}
#line 1667 "Analyser.tab.c"
    break;

  case 64: /* Relation: Simple T_EQU Simple  */
#line 273 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_EQU", "=");}
#line 1673 "Analyser.tab.c"
    break;

  case 65: /* Relation: Simple T_NOTEQU Simple  */
#line 274 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_NOTEQU", "/=");}
#line 1679 "Analyser.tab.c"
    break;

  case 66: /* Simple: Factor  */
#line 278 "Analyser.y"
                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1685 "Analyser.tab.c"
    break;

  case 67: /* Simple: Factor T_MULTOP Simple  */
#line 279 "Analyser.y"
                                   {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_MULTOP", "*");}
#line 1691 "Analyser.tab.c"
    break;

  case 68: /* Simple: Factor T_DIVOP Simple  */
#line 280 "Analyser.y"
                                   {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_DIVOP", "/");}
#line 1697 "Analyser.tab.c"
    break;

  case 69: /* Simple: Factor T_MODOP Simple  */
#line 281 "Analyser.y"
                                   {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_MODOP", "%");}
#line 1703 "Analyser.tab.c"
    break;

  case 70: /* Factor: Summand  */
#line 286 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1709 "Analyser.tab.c"
    break;

  case 71: /* Factor: Summand T_ADDOP Factor  */
#line 287 "Analyser.y"
                                      {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_ADDOP", "+");}
#line 1715 "Analyser.tab.c"
    break;

  case 72: /* Factor: Summand T_SUBTROP Factor  */
#line 288 "Analyser.y"
                                      {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_SUBTROP", "-");}
#line 1721 "Analyser.tab.c"
    break;

  case 73: /* Summand: Primary  */
#line 291 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1727 "Analyser.tab.c"
    break;

  case 74: /* Summand: T_LPAREN Expression T_LPAREN  */
#line 292 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[-1].nodeLink);}
#line 1733 "Analyser.tab.c"
    break;

  case 75: /* Primary: T_ICONST  */
#line 295 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_ICONST", to_string((yyvsp[0].integer)));}
#line 1739 "Analyser.tab.c"
    break;

  case 76: /* Primary: T_CCONST  */
#line 296 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_CCONST", (yyvsp[0].string));}
#line 1745 "Analyser.tab.c"
    break;

  case 77: /* Primary: T_RCONST  */
#line 297 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_RCONST", to_string((yyvsp[0].real)));}
#line 1751 "Analyser.tab.c"
    break;

  case 78: /* Primary: T_TRUE  */
#line 298 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_TRUE", "true");}
#line 1757 "Analyser.tab.c"
    break;

  case 79: /* Primary: T_FALSE  */
#line 299 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_FALSE", "false");}
#line 1763 "Analyser.tab.c"
    break;

  case 80: /* Primary: ModifiablePrimary  */
#line 300 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1769 "Analyser.tab.c"
    break;

  case 81: /* ModifiablePrimary: ID_ARRAY  */
#line 315 "Analyser.y"
                                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1775 "Analyser.tab.c"
    break;

  case 82: /* ModifiablePrimary: ID_ARRAY T_DOT ModifiablePrimary  */
#line 316 "Analyser.y"
                                                                    {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink),"T_DOT", ".");}
#line 1781 "Analyser.tab.c"
    break;

  case 83: /* ID_ARRAY: T_ID  */
#line 319 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode("T_ID", (yyvsp[0].string));}
#line 1787 "Analyser.tab.c"
    break;

  case 84: /* ID_ARRAY: T_ID T_LBRACK Expression T_RBRACK  */
#line 320 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-3].string))), (yyvsp[-1].nodeLink), "BRACKS", "[]");}
#line 1793 "Analyser.tab.c"
    break;

  case 85: /* ID_ARRAY: T_ID T_LBRACK Expression T_RBRACK Identifiers_ARRAY  */
#line 321 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-4].string))), (yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "BRACKS", "[]");}
#line 1799 "Analyser.tab.c"
    break;

  case 86: /* Identifiers_ARRAY: T_LBRACK Expression T_RBRACK  */
#line 324 "Analyser.y"
                                                                    {(yyval.nodeLink) = createNode((yyvsp[-1].nodeLink), "BRACKS", "[]");}
#line 1805 "Analyser.tab.c"
    break;

  case 87: /* Identifiers_ARRAY: T_LBRACK Expression T_RBRACK Identifiers_ARRAY  */
#line 325 "Analyser.y"
                                                                    {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "BRACKS", "[]");}
#line 1811 "Analyser.tab.c"
    break;


#line 1815 "Analyser.tab.c"

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

#line 328 "Analyser.y"


Node* generateAST (string inputfile) {
    yyin = fopen(inputfile.c_str(), "r");
    yyparse();
    fclose(yyin);

    return root;
}
