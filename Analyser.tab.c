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

    Node* root = new Node(Token(T_ROOT, "root"));


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
  YYSYMBOL_T_NONE = 32,                    /* T_NONE  */
  YYSYMBOL_T_ROOT = 33,                    /* T_ROOT  */
  YYSYMBOL_T_VAR_DECL_COLON_IS = 34,       /* T_VAR_DECL_COLON_IS  */
  YYSYMBOL_T_VAR_DECL_COLON = 35,          /* T_VAR_DECL_COLON  */
  YYSYMBOL_T_VAR_DECL_IS = 36,             /* T_VAR_DECL_IS  */
  YYSYMBOL_T_TYPE_DECL_IS = 37,            /* T_TYPE_DECL_IS  */
  YYSYMBOL_T_ROUTIN_DECL_TYPE = 38,        /* T_ROUTIN_DECL_TYPE  */
  YYSYMBOL_T_ROUTIN_DECL = 39,             /* T_ROUTIN_DECL  */
  YYSYMBOL_T_PARAMETERS = 40,              /* T_PARAMETERS  */
  YYSYMBOL_T_BODY = 41,                    /* T_BODY  */
  YYSYMBOL_T_ROUTINE_CALL = 42,            /* T_ROUTINE_CALL  */
  YYSYMBOL_T_BRACKS = 43,                  /* T_BRACKS  */
  YYSYMBOL_T_IN_REVERSE = 44,              /* T_IN_REVERSE  */
  YYSYMBOL_T_IF_ELSE = 45,                 /* T_IF_ELSE  */
  YYSYMBOL_T_PARENT = 46,                  /* T_PARENT  */
  YYSYMBOL_T_LESS = 47,                    /* T_LESS  */
  YYSYMBOL_T_GREAT = 48,                   /* T_GREAT  */
  YYSYMBOL_T_LESSOREQU = 49,               /* T_LESSOREQU  */
  YYSYMBOL_T_GREATOREQU = 50,              /* T_GREATOREQU  */
  YYSYMBOL_T_NOTEQU = 51,                  /* T_NOTEQU  */
  YYSYMBOL_T_EQU = 52,                     /* T_EQU  */
  YYSYMBOL_T_COLONEQU = 53,                /* T_COLONEQU  */
  YYSYMBOL_T_AND = 54,                     /* T_AND  */
  YYSYMBOL_T_OR = 55,                      /* T_OR  */
  YYSYMBOL_T_XOR = 56,                     /* T_XOR  */
  YYSYMBOL_T_ADDOP = 57,                   /* T_ADDOP  */
  YYSYMBOL_T_MULTOP = 58,                  /* T_MULTOP  */
  YYSYMBOL_T_SUBTROP = 59,                 /* T_SUBTROP  */
  YYSYMBOL_T_DIVOP = 60,                   /* T_DIVOP  */
  YYSYMBOL_T_MODOP = 61,                   /* T_MODOP  */
  YYSYMBOL_T_LPAREN = 62,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 63,                  /* T_RPAREN  */
  YYSYMBOL_T_LBRACK = 64,                  /* T_LBRACK  */
  YYSYMBOL_T_RBRACK = 65,                  /* T_RBRACK  */
  YYSYMBOL_T_DOTDOT = 66,                  /* T_DOTDOT  */
  YYSYMBOL_T_DOT = 67,                     /* T_DOT  */
  YYSYMBOL_T_COMMA = 68,                   /* T_COMMA  */
  YYSYMBOL_T_COLON = 69,                   /* T_COLON  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_Program = 71,                   /* Program  */
  YYSYMBOL_Programs = 72,                  /* Programs  */
  YYSYMBOL_SimpleDeclaration = 73,         /* SimpleDeclaration  */
  YYSYMBOL_VariableDeclaration = 74,       /* VariableDeclaration  */
  YYSYMBOL_TypeDeclaration = 75,           /* TypeDeclaration  */
  YYSYMBOL_RoutineDeclaration = 76,        /* RoutineDeclaration  */
  YYSYMBOL_Parameters = 77,                /* Parameters  */
  YYSYMBOL_ParameterDeclarations = 78,     /* ParameterDeclarations  */
  YYSYMBOL_ParameterDeclaration = 79,      /* ParameterDeclaration  */
  YYSYMBOL_Type = 80,                      /* Type  */
  YYSYMBOL_PrimitiveType = 81,             /* PrimitiveType  */
  YYSYMBOL_RecordType = 82,                /* RecordType  */
  YYSYMBOL_VariableDeclarations = 83,      /* VariableDeclarations  */
  YYSYMBOL_ArrayType = 84,                 /* ArrayType  */
  YYSYMBOL_Body = 85,                      /* Body  */
  YYSYMBOL_Bodies = 86,                    /* Bodies  */
  YYSYMBOL_Statement = 87,                 /* Statement  */
  YYSYMBOL_Assignment = 88,                /* Assignment  */
  YYSYMBOL_RoutineCall = 89,               /* RoutineCall  */
  YYSYMBOL_Expressions = 90,               /* Expressions  */
  YYSYMBOL_WhileLoop = 91,                 /* WhileLoop  */
  YYSYMBOL_ForLoop = 92,                   /* ForLoop  */
  YYSYMBOL_Range = 93,                     /* Range  */
  YYSYMBOL_IfStatement = 94,               /* IfStatement  */
  YYSYMBOL_Expression = 95,                /* Expression  */
  YYSYMBOL_Relation = 96,                  /* Relation  */
  YYSYMBOL_Simple = 97,                    /* Simple  */
  YYSYMBOL_Factor = 98,                    /* Factor  */
  YYSYMBOL_Summand = 99,                   /* Summand  */
  YYSYMBOL_Primary = 100,                  /* Primary  */
  YYSYMBOL_ModifiablePrimary = 101,        /* ModifiablePrimary  */
  YYSYMBOL_ID_ARRAY = 102,                 /* ID_ARRAY  */
  YYSYMBOL_Identifiers_ARRAY = 103         /* Identifiers_ARRAY  */
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
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  177

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   324


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   145,   145,   146,   149,   150,   151,   154,   155,   161,
     162,   163,   166,   172,   173,   176,   180,   181,   184,   187,
     188,   189,   190,   193,   194,   195,   196,   199,   203,   204,
     207,   212,   213,   214,   217,   218,   219,   222,   223,   224,
     225,   226,   227,   228,   231,   235,   236,   240,   241,   244,
     247,   250,   251,   254,   255,   259,   260,   261,   262,   274,
     275,   276,   277,   278,   279,   280,   284,   285,   286,   287,
     292,   293,   294,   297,   298,   301,   302,   303,   304,   305,
     306,   321,   322,   325,   326,   327,   330,   331
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
  "T_EOF", "T_NONE", "T_ROOT", "T_VAR_DECL_COLON_IS", "T_VAR_DECL_COLON",
  "T_VAR_DECL_IS", "T_TYPE_DECL_IS", "T_ROUTIN_DECL_TYPE", "T_ROUTIN_DECL",
  "T_PARAMETERS", "T_BODY", "T_ROUTINE_CALL", "T_BRACKS", "T_IN_REVERSE",
  "T_IF_ELSE", "T_PARENT", "T_LESS", "T_GREAT", "T_LESSOREQU",
  "T_GREATOREQU", "T_NOTEQU", "T_EQU", "T_COLONEQU", "T_AND", "T_OR",
  "T_XOR", "T_ADDOP", "T_MULTOP", "T_SUBTROP", "T_DIVOP", "T_MODOP",
  "T_LPAREN", "T_RPAREN", "T_LBRACK", "T_RBRACK", "T_DOTDOT", "T_DOT",
  "T_COMMA", "T_COLON", "$accept", "Program", "Programs",
  "SimpleDeclaration", "VariableDeclaration", "TypeDeclaration",
  "RoutineDeclaration", "Parameters", "ParameterDeclarations",
  "ParameterDeclaration", "Type", "PrimitiveType", "RecordType",
  "VariableDeclarations", "ArrayType", "Body", "Bodies", "Statement",
  "Assignment", "RoutineCall", "Expressions", "WhileLoop", "ForLoop",
  "Range", "IfStatement", "Expression", "Relation", "Simple", "Factor",
  "Summand", "Primary", "ModifiablePrimary", "ID_ARRAY",
  "Identifiers_ARRAY", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-125)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      80,    -7,     6,    10,    15,    83,  -125,  -125,    83,    -4,
     -12,   -23,  -125,  -125,  -125,    83,    83,  -125,   105,    22,
     105,    21,  -125,  -125,  -125,  -125,  -125,  -125,   -11,    46,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,    -3,  -125,  -125,
    -125,    22,  -125,    52,   106,    87,   -46,  -125,  -125,     3,
      50,    -1,     9,    13,    22,    46,    66,    22,    20,    22,
      22,    22,    22,    22,    22,    22,    22,    22,    22,    22,
      22,    22,    22,    64,    22,   105,    -9,    21,  -125,    29,
    -125,  -125,    38,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,    63,   105,    13,   105,    48,    99,    22,    22,    67,
      68,   -41,    63,   120,    63,  -125,  -125,  -125,  -125,  -125,
      96,   136,  -125,  -125,    22,  -125,   145,   154,   151,    22,
      22,    22,    63,  -125,    63,  -125,  -125,    22,    63,    97,
       0,   156,    63,    63,   100,   102,   103,   104,  -125,  -125,
    -125,   153,    48,    22,   107,    63,   157,   109,  -125,  -125,
    -125,    22,  -125,  -125,   108,    22,   158,  -125,    63,  -125,
    -125,    22,  -125,  -125,   159,  -125,  -125
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
       0,     0,    31,    31,     0,     0,     0,    47,    35,    36,
      44,     0,    86,     0,     0,    31,     0,     0,    43,    42,
      46,     0,    13,    87,     0,     0,     0,    49,    31,    54,
      48,     0,    51,    50,     0,    52,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,   101,     1,   -21,  -125,   167,  -125,    72,    94,
     -17,  -125,  -125,   121,  -125,  -124,   -78,   -32,  -125,  -125,
      16,  -125,  -125,  -125,  -125,   -19,  -125,    74,    26,  -125,
    -125,   -69,  -125,    27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,    14,   112,     6,     7,    16,    52,    78,    53,
      31,    32,    33,    56,    34,   113,   133,   114,   115,   116,
     146,   117,   118,   141,   119,   147,    43,    44,    45,    46,
      47,    48,    49,   125
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,     5,    19,    50,    98,   101,    15,   153,    55,    15,
      18,    71,   -83,    72,   151,    12,    15,    15,   156,   157,
       9,   131,    58,    57,    35,    36,   -83,    37,    38,    39,
      40,   166,   120,    10,    55,    79,   136,    11,    82,    21,
      84,    85,    86,   120,   174,   120,    35,    36,    51,    37,
      38,    39,    40,    54,   148,    99,   149,    20,   100,     2,
     102,    57,    41,   120,    74,   120,   106,   107,    75,   120,
      73,   108,    76,   120,   120,     1,     2,    81,   109,   110,
     134,    77,   134,    83,    41,   121,   120,   123,   127,   128,
     111,    37,     1,     2,   104,     1,     2,    96,    97,   120,
     134,     3,   134,   105,     3,   139,    59,    60,    61,    17,
     144,   145,   124,   132,    13,   132,    22,    23,   150,   168,
     169,   154,    24,    25,    26,    27,   126,    28,    29,   129,
     130,   135,    30,   132,   164,   132,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    68,   172,    69,    70,   137,
     138,   140,   175,    62,    63,    64,    65,    66,    67,   142,
     143,   155,   152,   158,   162,   159,   160,     8,   167,   173,
     176,   103,   161,   165,   171,   122,    80,   170,     0,   163
};

static const yytype_int16 yycheck[] =
{
      19,     0,    14,    20,    73,    14,     5,     7,    29,     8,
      14,    57,    53,    59,   138,     0,    15,    16,   142,   143,
      27,    62,    41,    64,    24,    25,    67,    27,    28,    29,
      30,   155,   101,    27,    55,    54,   114,    27,    57,    62,
      59,    60,    61,   112,   168,   114,    24,    25,    27,    27,
      28,    29,    30,    64,   132,    74,   134,    69,    75,    13,
      69,    64,    62,   132,    14,   134,     3,     4,    69,   138,
      67,     8,    63,   142,   143,    12,    13,    11,    15,    16,
     112,    68,   114,    63,    62,   102,   155,   104,   107,   108,
      27,    27,    12,    13,    65,    12,    13,    71,    72,   168,
     132,    21,   134,    65,    21,   124,    54,    55,    56,     8,
     129,   130,    64,   112,    31,   114,    15,    16,   137,    10,
      11,   140,    17,    18,    19,    20,    27,    22,    23,    62,
      62,    11,    27,   132,   153,   134,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    58,   165,    60,    61,    53,
      14,     6,   171,    47,    48,    49,    50,    51,    52,     5,
       9,     5,    65,    63,    11,    63,    63,     0,    11,    11,
      11,    77,    68,    66,    66,   103,    55,   161,    -1,   152
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    13,    21,    71,    73,    74,    75,    76,    27,
      27,    27,     0,    31,    72,    73,    76,    72,    14,    14,
      69,    62,    72,    72,    17,    18,    19,    20,    22,    23,
      27,    80,    81,    82,    84,    24,    25,    27,    28,    29,
      30,    62,    95,    96,    97,    98,    99,   100,   101,   102,
      80,    27,    77,    79,    64,    74,    83,    64,    95,    54,
      55,    56,    47,    48,    49,    50,    51,    52,    58,    60,
      61,    57,    59,    67,    14,    69,    63,    68,    78,    95,
      83,    11,    95,    63,    95,    95,    95,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    98,    98,   101,    95,
      80,    14,    69,    79,    65,    65,     3,     4,     8,    15,
      16,    27,    73,    85,    87,    88,    89,    91,    92,    94,
     101,    80,    78,    80,    64,   103,    27,    95,    95,    62,
      62,    62,    73,    86,    87,    11,    86,    53,    14,    95,
       6,    93,     5,     9,    95,    95,    90,    95,    86,    86,
      95,    85,    65,     7,    95,     5,    85,    85,    63,    63,
      63,    68,    11,   103,    95,    66,    85,    11,    10,    11,
      90,    66,    95,    11,    85,    95,    11
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    71,    72,    72,    72,    73,    73,    74,
      74,    74,    75,    76,    76,    77,    78,    78,    79,    80,
      80,    80,    80,    81,    81,    81,    81,    82,    83,    83,
      84,    85,    85,    85,    86,    86,    86,    87,    87,    87,
      87,    87,    87,    87,    88,    89,    89,    90,    90,    91,
      92,    93,    93,    94,    94,    95,    95,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    97,    97,    97,    97,
      98,    98,    98,    99,    99,   100,   100,   100,   100,   100,
     100,   101,   101,   102,   102,   102,   103,   103
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
#line 145 "Analyser.y"
                                        {root = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), T_ROOT, "ROOT");}
#line 1321 "Analyser.tab.c"
    break;

  case 3: /* Program: RoutineDeclaration Programs  */
#line 146 "Analyser.y"
                                        {root = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), T_ROOT, "ROOT");}
#line 1327 "Analyser.tab.c"
    break;

  case 4: /* Programs: T_EOF  */
#line 149 "Analyser.y"
                                         {(yyval.nodeList) = vector<Node*>();}
#line 1333 "Analyser.tab.c"
    break;

  case 5: /* Programs: SimpleDeclaration Programs  */
#line 150 "Analyser.y"
                                        {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1339 "Analyser.tab.c"
    break;

  case 6: /* Programs: RoutineDeclaration Programs  */
#line 151 "Analyser.y"
                                        {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1345 "Analyser.tab.c"
    break;

  case 7: /* SimpleDeclaration: VariableDeclaration  */
#line 154 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1351 "Analyser.tab.c"
    break;

  case 8: /* SimpleDeclaration: TypeDeclaration  */
#line 155 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1357 "Analyser.tab.c"
    break;

  case 9: /* VariableDeclaration: T_VAR T_ID T_COLON Type T_IS Expression  */
#line 161 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token(T_ID, (yyvsp[-4].string))), (yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_VAR_DECL_COLON_IS, "colon is");}
#line 1363 "Analyser.tab.c"
    break;

  case 10: /* VariableDeclaration: T_VAR T_ID T_COLON Type  */
#line 162 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token(T_ID, (yyvsp[-2].string))), (yyvsp[0].nodeLink), T_VAR_DECL_COLON, "colon");}
#line 1369 "Analyser.tab.c"
    break;

  case 11: /* VariableDeclaration: T_VAR T_ID T_IS Expression  */
#line 163 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token(T_ID, (yyvsp[-2].string))), (yyvsp[0].nodeLink), T_VAR_DECL_IS, "is");}
#line 1375 "Analyser.tab.c"
    break;

  case 12: /* TypeDeclaration: T_TYPE T_ID T_IS Type  */
#line 166 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token(T_ID, (yyvsp[-2].string))), (yyvsp[0].nodeLink), T_TYPE_DECL_IS, "is");}
#line 1381 "Analyser.tab.c"
    break;

  case 13: /* RoutineDeclaration: T_ROUTINE T_ID T_LPAREN Parameters T_RPAREN T_COLON Type T_IS Body T_END  */
#line 172 "Analyser.y"
                                                                                                {(yyval.nodeLink) = createNode(new Node(Token(T_ID, (yyvsp[-8].string))), (yyvsp[-6].nodeLink), (yyvsp[-3].nodeLink),(yyvsp[-1].nodeLink), T_ROUTIN_DECL_TYPE, "routine");}
#line 1387 "Analyser.tab.c"
    break;

  case 14: /* RoutineDeclaration: T_ROUTINE T_ID T_LPAREN Parameters T_RPAREN T_IS Body T_END  */
#line 173 "Analyser.y"
                                                                                                {(yyval.nodeLink) = createNode(new Node(Token(T_ID, (yyvsp[-6].string))), (yyvsp[-4].nodeLink), (yyvsp[-1].nodeLink), T_ROUTIN_DECL, "routine");}
#line 1393 "Analyser.tab.c"
    break;

  case 15: /* Parameters: ParameterDeclaration ParameterDeclarations  */
#line 176 "Analyser.y"
                                                                                                {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), T_PARAMETERS, "()");}
#line 1399 "Analyser.tab.c"
    break;

  case 16: /* ParameterDeclarations: %empty  */
#line 180 "Analyser.y"
                                                                                                {(yyval.nodeList) = vector<Node*>();}
#line 1405 "Analyser.tab.c"
    break;

  case 17: /* ParameterDeclarations: T_COMMA ParameterDeclaration ParameterDeclarations  */
#line 181 "Analyser.y"
                                                                                                {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1411 "Analyser.tab.c"
    break;

  case 18: /* ParameterDeclaration: T_ID T_COLON Type  */
#line 184 "Analyser.y"
                                            {(yyval.nodeLink) = createNode(new Node(Token(T_ID, (yyvsp[-2].string))), (yyvsp[0].nodeLink), T_COLON, ":");}
#line 1417 "Analyser.tab.c"
    break;

  case 19: /* Type: PrimitiveType  */
#line 187 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1423 "Analyser.tab.c"
    break;

  case 20: /* Type: ArrayType  */
#line 188 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1429 "Analyser.tab.c"
    break;

  case 21: /* Type: RecordType  */
#line 189 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1435 "Analyser.tab.c"
    break;

  case 22: /* Type: T_ID  */
#line 190 "Analyser.y"
                                            {(yyval.nodeLink) = createNode(T_ID, (yyvsp[0].string));}
#line 1441 "Analyser.tab.c"
    break;

  case 23: /* PrimitiveType: T_INTEGER  */
#line 193 "Analyser.y"
                                            {(yyval.nodeLink) = createNode(T_INTEGER, "integer");}
#line 1447 "Analyser.tab.c"
    break;

  case 24: /* PrimitiveType: T_REAL  */
#line 194 "Analyser.y"
                                            {(yyval.nodeLink) = createNode(T_REAL, "real");}
#line 1453 "Analyser.tab.c"
    break;

  case 25: /* PrimitiveType: T_BOOLEAN  */
#line 195 "Analyser.y"
                                            {(yyval.nodeLink) = createNode(T_BOOLEAN, "boolean");}
#line 1459 "Analyser.tab.c"
    break;

  case 26: /* PrimitiveType: T_CHAR  */
#line 196 "Analyser.y"
                                            {(yyval.nodeLink) = createNode(T_CHAR, "char");}
#line 1465 "Analyser.tab.c"
    break;

  case 27: /* RecordType: T_RECORD VariableDeclarations T_END  */
#line 199 "Analyser.y"
                                                 {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeList), T_RECORD, "record");}
#line 1471 "Analyser.tab.c"
    break;

  case 28: /* VariableDeclarations: %empty  */
#line 203 "Analyser.y"
                                                                {(yyval.nodeList) = vector<Node*>();}
#line 1477 "Analyser.tab.c"
    break;

  case 29: /* VariableDeclarations: VariableDeclaration VariableDeclarations  */
#line 204 "Analyser.y"
                                                                {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1483 "Analyser.tab.c"
    break;

  case 30: /* ArrayType: T_ARRAY T_LBRACK Expression T_RBRACK Type  */
#line 207 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_ARRAY, "array");}
#line 1489 "Analyser.tab.c"
    break;

  case 31: /* Body: %empty  */
#line 212 "Analyser.y"
                                    {(yyval.nodeLink) = createNode(T_BODY, "BODY");}
#line 1495 "Analyser.tab.c"
    break;

  case 32: /* Body: SimpleDeclaration Bodies  */
#line 213 "Analyser.y"
                                    {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), T_BODY, "BODY");}
#line 1501 "Analyser.tab.c"
    break;

  case 33: /* Body: Statement Bodies  */
#line 214 "Analyser.y"
                                    {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), T_BODY, "BODY");}
#line 1507 "Analyser.tab.c"
    break;

  case 34: /* Bodies: %empty  */
#line 217 "Analyser.y"
                                    {(yyval.nodeList) = vector<Node*>();}
#line 1513 "Analyser.tab.c"
    break;

  case 35: /* Bodies: SimpleDeclaration Bodies  */
#line 218 "Analyser.y"
                                    {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1519 "Analyser.tab.c"
    break;

  case 36: /* Bodies: Statement Bodies  */
#line 219 "Analyser.y"
                                    {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1525 "Analyser.tab.c"
    break;

  case 37: /* Statement: Assignment  */
#line 222 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1531 "Analyser.tab.c"
    break;

  case 38: /* Statement: RoutineCall  */
#line 223 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1537 "Analyser.tab.c"
    break;

  case 39: /* Statement: WhileLoop  */
#line 224 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1543 "Analyser.tab.c"
    break;

  case 40: /* Statement: ForLoop  */
#line 225 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1549 "Analyser.tab.c"
    break;

  case 41: /* Statement: IfStatement  */
#line 226 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1555 "Analyser.tab.c"
    break;

  case 42: /* Statement: T_RETURN T_LPAREN Expression T_RPAREN  */
#line 227 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode((yyvsp[-1].nodeLink), T_RETURN, "return");}
#line 1561 "Analyser.tab.c"
    break;

  case 43: /* Statement: T_PRINT T_LPAREN Expression T_RPAREN  */
#line 228 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode((yyvsp[-1].nodeLink), T_PRINT, "print");}
#line 1567 "Analyser.tab.c"
    break;

  case 44: /* Assignment: ModifiablePrimary T_COLONEQU Expression  */
#line 231 "Analyser.y"
                                                     {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_COLONEQU, ":=");}
#line 1573 "Analyser.tab.c"
    break;

  case 45: /* RoutineCall: T_ID  */
#line 235 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode(T_ID, (yyvsp[0].string));}
#line 1579 "Analyser.tab.c"
    break;

  case 46: /* RoutineCall: T_ID T_LPAREN Expressions T_RPAREN  */
#line 236 "Analyser.y"
                                                    {(yyval.nodeLink) = combineNodes(new Node(Token(T_ID, (yyvsp[-3].string))), (yyvsp[-1].nodeList), T_ROUTINE_CALL, "ROUTINECALL");}
#line 1585 "Analyser.tab.c"
    break;

  case 47: /* Expressions: Expression  */
#line 240 "Analyser.y"
                                                    {(yyval.nodeList) = collectNodes((yyvsp[0].nodeLink));}
#line 1591 "Analyser.tab.c"
    break;

  case 48: /* Expressions: Expression T_COMMA Expressions  */
#line 241 "Analyser.y"
                                                    {(yyval.nodeList) = collectNodes((yyvsp[-2].nodeLink), (yyvsp[0].nodeList));}
#line 1597 "Analyser.tab.c"
    break;

  case 49: /* WhileLoop: T_WHILE Expression T_LOOP Body T_END  */
#line 244 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode((yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), T_WHILE, "while");}
#line 1603 "Analyser.tab.c"
    break;

  case 50: /* ForLoop: T_FOR T_ID Range T_LOOP Body T_END  */
#line 247 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode(new Node(Token(T_ID, (yyvsp[-4].string))), (yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), T_FOR, "for");}
#line 1609 "Analyser.tab.c"
    break;

  case 51: /* Range: T_IN Expression T_DOTDOT Expression  */
#line 250 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_IN, "in");}
#line 1615 "Analyser.tab.c"
    break;

  case 52: /* Range: T_IN T_REVERSE Expression T_DOTDOT Expression  */
#line 251 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_IN_REVERSE, "in_reverse");}
#line 1621 "Analyser.tab.c"
    break;

  case 53: /* IfStatement: T_IF Expression T_THEN Body T_ELSE Body T_END  */
#line 254 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode((yyvsp[-5].nodeLink), (yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), T_IF_ELSE, "if else");}
#line 1627 "Analyser.tab.c"
    break;

  case 54: /* IfStatement: T_IF Expression T_THEN Body T_END  */
#line 255 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode((yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), T_IF, "if");}
#line 1633 "Analyser.tab.c"
    break;

  case 55: /* Expression: Relation  */
#line 259 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1639 "Analyser.tab.c"
    break;

  case 56: /* Expression: Relation T_AND Expression  */
#line 260 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_AND, "and");}
#line 1645 "Analyser.tab.c"
    break;

  case 57: /* Expression: Relation T_OR Expression  */
#line 261 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_OR, "or");}
#line 1651 "Analyser.tab.c"
    break;

  case 58: /* Expression: Relation T_XOR Expression  */
#line 262 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_XOR, "xor");}
#line 1657 "Analyser.tab.c"
    break;

  case 59: /* Relation: Simple  */
#line 274 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1663 "Analyser.tab.c"
    break;

  case 60: /* Relation: Simple T_LESS Simple  */
#line 275 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_LESS, "<");}
#line 1669 "Analyser.tab.c"
    break;

  case 61: /* Relation: Simple T_LESSOREQU Simple  */
#line 276 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_LESSOREQU, "<=");}
#line 1675 "Analyser.tab.c"
    break;

  case 62: /* Relation: Simple T_GREAT Simple  */
#line 277 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_GREAT, ">");}
#line 1681 "Analyser.tab.c"
    break;

  case 63: /* Relation: Simple T_GREATOREQU Simple  */
#line 278 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_GREATOREQU, ">=");}
#line 1687 "Analyser.tab.c"
    break;

  case 64: /* Relation: Simple T_EQU Simple  */
#line 279 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_EQU, "=");}
#line 1693 "Analyser.tab.c"
    break;

  case 65: /* Relation: Simple T_NOTEQU Simple  */
#line 280 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_NOTEQU, "/=");}
#line 1699 "Analyser.tab.c"
    break;

  case 66: /* Simple: Factor  */
#line 284 "Analyser.y"
                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1705 "Analyser.tab.c"
    break;

  case 67: /* Simple: Factor T_MULTOP Simple  */
#line 285 "Analyser.y"
                                   {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_MULTOP, "*");}
#line 1711 "Analyser.tab.c"
    break;

  case 68: /* Simple: Factor T_DIVOP Simple  */
#line 286 "Analyser.y"
                                   {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_DIVOP, "/");}
#line 1717 "Analyser.tab.c"
    break;

  case 69: /* Simple: Factor T_MODOP Simple  */
#line 287 "Analyser.y"
                                   {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_MODOP, "%");}
#line 1723 "Analyser.tab.c"
    break;

  case 70: /* Factor: Summand  */
#line 292 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1729 "Analyser.tab.c"
    break;

  case 71: /* Factor: Summand T_ADDOP Factor  */
#line 293 "Analyser.y"
                                      {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_ADDOP, "+");}
#line 1735 "Analyser.tab.c"
    break;

  case 72: /* Factor: Summand T_SUBTROP Factor  */
#line 294 "Analyser.y"
                                      {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_SUBTROP, "-");}
#line 1741 "Analyser.tab.c"
    break;

  case 73: /* Summand: Primary  */
#line 297 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1747 "Analyser.tab.c"
    break;

  case 74: /* Summand: T_LPAREN Expression T_RPAREN  */
#line 298 "Analyser.y"
                                        {(yyval.nodeLink) = createNode((yyvsp[-1].nodeLink), T_PARENT, "()");}
#line 1753 "Analyser.tab.c"
    break;

  case 75: /* Primary: T_ICONST  */
#line 301 "Analyser.y"
                                        {(yyval.nodeLink) = createNode(T_ICONST, to_string((yyvsp[0].integer)));}
#line 1759 "Analyser.tab.c"
    break;

  case 76: /* Primary: T_CCONST  */
#line 302 "Analyser.y"
                                        {(yyval.nodeLink) = createNode(T_CCONST, (yyvsp[0].string));}
#line 1765 "Analyser.tab.c"
    break;

  case 77: /* Primary: T_RCONST  */
#line 303 "Analyser.y"
                                        {(yyval.nodeLink) = createNode(T_RCONST, to_string((yyvsp[0].real)));}
#line 1771 "Analyser.tab.c"
    break;

  case 78: /* Primary: T_TRUE  */
#line 304 "Analyser.y"
                                        {(yyval.nodeLink) = createNode(T_TRUE, "true");}
#line 1777 "Analyser.tab.c"
    break;

  case 79: /* Primary: T_FALSE  */
#line 305 "Analyser.y"
                                        {(yyval.nodeLink) = createNode(T_FALSE, "false");}
#line 1783 "Analyser.tab.c"
    break;

  case 80: /* Primary: ModifiablePrimary  */
#line 306 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1789 "Analyser.tab.c"
    break;

  case 81: /* ModifiablePrimary: ID_ARRAY  */
#line 321 "Analyser.y"
                                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1795 "Analyser.tab.c"
    break;

  case 82: /* ModifiablePrimary: ID_ARRAY T_DOT ModifiablePrimary  */
#line 322 "Analyser.y"
                                                                    {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink),T_DOT, ".");}
#line 1801 "Analyser.tab.c"
    break;

  case 83: /* ID_ARRAY: T_ID  */
#line 325 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(T_ID, (yyvsp[0].string));}
#line 1807 "Analyser.tab.c"
    break;

  case 84: /* ID_ARRAY: T_ID T_LBRACK Expression T_RBRACK  */
#line 326 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token(T_ID, (yyvsp[-3].string))), (yyvsp[-1].nodeLink), T_BRACKS, "[]");}
#line 1813 "Analyser.tab.c"
    break;

  case 85: /* ID_ARRAY: T_ID T_LBRACK Expression T_RBRACK Identifiers_ARRAY  */
#line 327 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token(T_ID, (yyvsp[-4].string))), (yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_BRACKS, "[]");}
#line 1819 "Analyser.tab.c"
    break;

  case 86: /* Identifiers_ARRAY: T_LBRACK Expression T_RBRACK  */
#line 330 "Analyser.y"
                                                                    {(yyval.nodeLink) = createNode((yyvsp[-1].nodeLink), T_BRACKS, "[]");}
#line 1825 "Analyser.tab.c"
    break;

  case 87: /* Identifiers_ARRAY: T_LBRACK Expression T_RBRACK Identifiers_ARRAY  */
#line 331 "Analyser.y"
                                                                    {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), T_BRACKS, "[]");}
#line 1831 "Analyser.tab.c"
    break;


#line 1835 "Analyser.tab.c"

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

#line 334 "Analyser.y"


Node* generateAST (string inputfile) {
    yyin = fopen(inputfile.c_str(), "r");
    yyparse();
    fclose(yyin);

    return root;
}
