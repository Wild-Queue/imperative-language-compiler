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
    #include <string.h>
    #include <vector>
    #include <typeinfo>
    extern int yylineno;
    int yylex();
    using namespace std;
    void yyerror(std::string s) {
        cout << "Syntax Error on Line" << s << endl;
        cerr << s << ", line " << yylineno << endl;
        exit(1);
    }

    struct Token{
        std::string token;
        std::string lexeme;

        Token(std::string token, std::string lexeme) : token(token), lexeme(lexeme){};
    };

    struct Node {
        Token token = Token("NONE", "");
        vector<Node*>nodes;

        Node(Token token) : token(token){};
    };

    typedef struct {
        Node* nodeLink;
        vector<Node*> nodeList;

        unsigned int integer;
        double real;
        std::string string;
        char character;
        int boolean;
    } YYSTYPE;
    #define YYSTYPE YYSTYPE

    
    Node* combineNodes(vector<Node*> nodes, std::string token, std::string lexeme){
        Node* newNode = new Node(Token(token, lexeme));

        for (int i = 0; i < nodes.size(); ++i){
            newNode->nodes.push_back(nodes[i]);
        }
        return newNode;
    };

    Node* combineNodes(Node *fst, vector<Node*> nodes, std::string token, std::string lexeme){
        Node* newNode = new Node(Token(token, lexeme));

        newNode->nodes.push_back(fst);
        for (int i = 0; i < nodes.size(); ++i){
            newNode->nodes.push_back(nodes[i]);
        }
        return newNode;
    };

    vector<Node*> collectNodes(Node *fst){
        vector<Node*> newNode;

        newNode.push_back(fst);

        return newNode;
    };

    vector<Node*> collectNodes(vector<Node*> nodes){
        vector<Node*> newNode;

        for (int i = 0; i < nodes.size(); ++i){
            newNode.push_back(nodes[i]);
        }

        return newNode;
    };

    vector<Node*> collectNodes(Node *fst, vector<Node*> nodes){
        vector<Node*> newNode;

        newNode.push_back(fst);
        for (int i = 0; i < nodes.size(); ++i){
            newNode.push_back(nodes[i]);
        }

        return newNode;
    };

    Node* createNode(std::string token, std::string lexeme){
        Node* newNode = new Node(Token(token, lexeme));

        return newNode;
    };

    Node* createNode(Node *fst, std::string token, std::string lexeme){
        Node* newNode = new Node(Token(token, lexeme));

        newNode->nodes.push_back(fst);

        return newNode;
    };

    Node* createNode(Node *fst, Node *snd, string token, string lexeme){
            Node* newNode = new Node(Token(token, lexeme));

            newNode->nodes.push_back(fst);
            newNode->nodes.push_back(snd);

            return newNode;
    };

    Node* createNode(Node *fst, Node *snd, Node *trd, string token, string lexeme){
            Node* newNode = new Node(Token(token, lexeme));

            newNode->nodes.push_back(fst);
            newNode->nodes.push_back(snd);
            newNode->nodes.push_back(trd);

            return newNode;
    };

    Node* createNode(Node *fst, Node *snd, Node *trd, Node *frth, string token, string lexeme){
            Node* newNode = new Node(Token(token, lexeme));

            newNode->nodes.push_back(fst);
            newNode->nodes.push_back(snd);
            newNode->nodes.push_back(trd);
            newNode->nodes.push_back(frth);

            return newNode;
    };

    Node* root = new Node(Token("root", "root"));

#line 207 "Analyser.tab.c"

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
  YYSYMBOL_T_INTEGER = 16,                 /* T_INTEGER  */
  YYSYMBOL_T_REAL = 17,                    /* T_REAL  */
  YYSYMBOL_T_BOOLEAN = 18,                 /* T_BOOLEAN  */
  YYSYMBOL_T_ROUTINE = 19,                 /* T_ROUTINE  */
  YYSYMBOL_T_ARRAY = 20,                   /* T_ARRAY  */
  YYSYMBOL_T_RECORD = 21,                  /* T_RECORD  */
  YYSYMBOL_T_TRUE = 22,                    /* T_TRUE  */
  YYSYMBOL_T_FALSE = 23,                   /* T_FALSE  */
  YYSYMBOL_T_ID = 24,                      /* T_ID  */
  YYSYMBOL_T_ICONST = 25,                  /* T_ICONST  */
  YYSYMBOL_T_SCONST = 26,                  /* T_SCONST  */
  YYSYMBOL_T_RCONST = 27,                  /* T_RCONST  */
  YYSYMBOL_T_BCONST = 28,                  /* T_BCONST  */
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
  YYSYMBOL_T_NOT = 41,                     /* T_NOT  */
  YYSYMBOL_T_ADDOP = 42,                   /* T_ADDOP  */
  YYSYMBOL_T_MULTOP = 43,                  /* T_MULTOP  */
  YYSYMBOL_T_SUBTROP = 44,                 /* T_SUBTROP  */
  YYSYMBOL_T_DIVOP = 45,                   /* T_DIVOP  */
  YYSYMBOL_T_MODOP = 46,                   /* T_MODOP  */
  YYSYMBOL_T_TAB = 47,                     /* T_TAB  */
  YYSYMBOL_T_NL = 48,                      /* T_NL  */
  YYSYMBOL_T_POINTER = 49,                 /* T_POINTER  */
  YYSYMBOL_T_REFERENCE = 50,               /* T_REFERENCE  */
  YYSYMBOL_T_LPAREN = 51,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 52,                  /* T_RPAREN  */
  YYSYMBOL_T_LBRACK = 53,                  /* T_LBRACK  */
  YYSYMBOL_T_RBRACK = 54,                  /* T_RBRACK  */
  YYSYMBOL_T_DOTDOT = 55,                  /* T_DOTDOT  */
  YYSYMBOL_T_DOT = 56,                     /* T_DOT  */
  YYSYMBOL_T_COMMA = 57,                   /* T_COMMA  */
  YYSYMBOL_T_COLON = 58,                   /* T_COLON  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_Program = 60,                   /* Program  */
  YYSYMBOL_Programs = 61,                  /* Programs  */
  YYSYMBOL_SimpleDeclaration = 62,         /* SimpleDeclaration  */
  YYSYMBOL_VariableDeclaration = 63,       /* VariableDeclaration  */
  YYSYMBOL_TypeDeclaration = 64,           /* TypeDeclaration  */
  YYSYMBOL_RoutineDeclaration = 65,        /* RoutineDeclaration  */
  YYSYMBOL_Parameters = 66,                /* Parameters  */
  YYSYMBOL_ParameterDeclarations = 67,     /* ParameterDeclarations  */
  YYSYMBOL_ParameterDeclaration = 68,      /* ParameterDeclaration  */
  YYSYMBOL_Type = 69,                      /* Type  */
  YYSYMBOL_PrimitiveType = 70,             /* PrimitiveType  */
  YYSYMBOL_RecordType = 71,                /* RecordType  */
  YYSYMBOL_VariableDeclarations = 72,      /* VariableDeclarations  */
  YYSYMBOL_ArrayType = 73,                 /* ArrayType  */
  YYSYMBOL_Body = 74,                      /* Body  */
  YYSYMBOL_Bodies = 75,                    /* Bodies  */
  YYSYMBOL_Statement = 76,                 /* Statement  */
  YYSYMBOL_Assignment = 77,                /* Assignment  */
  YYSYMBOL_RoutineCall = 78,               /* RoutineCall  */
  YYSYMBOL_Expressions = 79,               /* Expressions  */
  YYSYMBOL_WhileLoop = 80,                 /* WhileLoop  */
  YYSYMBOL_ForLoop = 81,                   /* ForLoop  */
  YYSYMBOL_Range = 82,                     /* Range  */
  YYSYMBOL_IfStatement = 83,               /* IfStatement  */
  YYSYMBOL_Expression = 84,                /* Expression  */
  YYSYMBOL_Relation = 85,                  /* Relation  */
  YYSYMBOL_Simple = 86,                    /* Simple  */
  YYSYMBOL_Factor = 87,                    /* Factor  */
  YYSYMBOL_Summand = 88,                   /* Summand  */
  YYSYMBOL_Primary = 89,                   /* Primary  */
  YYSYMBOL_ModifiablePrimary = 90,         /* ModifiablePrimary  */
  YYSYMBOL_Identifiers = 91                /* Identifiers  */
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
#define YYLAST   175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


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
      55,    56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   242,   242,   243,   246,   247,   248,   251,   252,   258,
     259,   260,   263,   269,   270,   273,   277,   278,   281,   284,
     285,   286,   287,   290,   291,   292,   295,   299,   300,   303,
     308,   309,   310,   313,   314,   315,   318,   319,   320,   321,
     322,   323,   326,   330,   331,   335,   336,   339,   342,   345,
     346,   349,   350,   354,   355,   356,   357,   369,   370,   371,
     372,   373,   374,   375,   379,   380,   381,   382,   387,   388,
     389,   392,   393,   396,   397,   398,   399,   400,   404,   405,
     409,   410,   411,   412
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
  "T_TYPE", "T_VAR", "T_IS", "T_PRINT", "T_INTEGER", "T_REAL", "T_BOOLEAN",
  "T_ROUTINE", "T_ARRAY", "T_RECORD", "T_TRUE", "T_FALSE", "T_ID",
  "T_ICONST", "T_SCONST", "T_RCONST", "T_BCONST", "T_CCONST", "T_EOF",
  "T_LESS", "T_GREAT", "T_LESSOREQU", "T_GREATOREQU", "T_NOTEQU", "T_EQU",
  "T_COLONEQU", "T_AND", "T_OR", "T_XOR", "T_NOT", "T_ADDOP", "T_MULTOP",
  "T_SUBTROP", "T_DIVOP", "T_MODOP", "T_TAB", "T_NL", "T_POINTER",
  "T_REFERENCE", "T_LPAREN", "T_RPAREN", "T_LBRACK", "T_RBRACK",
  "T_DOTDOT", "T_DOT", "T_COMMA", "T_COLON", "$accept", "Program",
  "Programs", "SimpleDeclaration", "VariableDeclaration",
  "TypeDeclaration", "RoutineDeclaration", "Parameters",
  "ParameterDeclarations", "ParameterDeclaration", "Type", "PrimitiveType",
  "RecordType", "VariableDeclarations", "ArrayType", "Body", "Bodies",
  "Statement", "Assignment", "RoutineCall", "Expressions", "WhileLoop",
  "ForLoop", "Range", "IfStatement", "Expression", "Relation", "Simple",
  "Factor", "Summand", "Primary", "ModifiablePrimary", "Identifiers", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-131)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-79)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      67,    -1,     4,     7,    46,    90,  -131,  -131,    90,    36,
     -11,     9,  -131,  -131,  -131,    90,    90,  -131,   106,    48,
     106,    44,  -131,  -131,  -131,  -131,  -131,    24,    70,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,   -41,  -131,  -131,    48,
    -131,   102,   101,    49,    56,  -131,  -131,    96,    54,    52,
      58,    48,    70,   107,    48,    95,  -131,    74,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,   106,    -4,    44,  -131,    85,  -131,  -131,
      89,   -41,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,    93,
     106,    58,   106,   -41,  -131,   130,    48,    48,   104,    25,
      93,   145,    93,  -131,  -131,  -131,  -131,  -131,   120,   144,
    -131,  -131,  -131,   153,   155,   152,    48,    34,    93,  -131,
      93,  -131,  -131,    48,    93,    42,   157,    93,    93,   111,
      48,   112,  -131,  -131,  -131,  -131,   154,    48,   113,    93,
     156,    27,  -131,    34,  -131,  -131,   114,    48,   159,  -131,
      93,  -131,  -131,    48,  -131,  -131,   160,  -131,  -131
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     1,     4,     2,     0,     0,     3,     0,     0,
       0,     0,     5,     6,    23,    24,    25,     0,    27,    22,
      12,    19,    21,    20,    75,    76,    78,    73,    74,     0,
      11,    53,    57,    64,    68,    71,    77,    10,     0,     0,
      16,     0,    27,     0,     0,     0,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,    28,    26,
       0,    80,    72,    54,    55,    56,    58,    60,    59,    61,
      63,    62,    65,    66,    67,    69,    70,     9,    18,    30,
       0,    16,     0,    82,    81,     0,     0,     0,     0,    43,
      33,     0,    33,    36,    37,    38,    39,    40,     0,     0,
      17,    29,    83,     0,     0,     0,     0,     0,    33,    31,
      33,    14,    32,     0,    30,     0,     0,    30,    30,     0,
       0,     0,    45,    34,    35,    42,     0,     0,     0,    30,
       0,     0,    41,     0,    44,    13,     0,     0,     0,    47,
      30,    52,    46,     0,    49,    48,     0,    50,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,     6,     1,   -23,  -131,   166,  -131,    71,    98,
     -18,  -131,  -131,   122,  -131,  -130,   -94,   -85,  -131,  -131,
      22,  -131,  -131,  -131,  -131,   -19,  -131,    84,    19,  -131,
    -131,   -86,   -70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,    14,   110,     6,     7,    16,    49,    76,    50,
      30,    31,    32,    53,    33,   111,   129,   112,   113,   114,
     141,   115,   116,   136,   117,   142,    41,    42,    43,    44,
      45,    46,    56
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,     5,    47,    19,   146,    52,    15,   150,   151,    15,
      99,   104,    54,   118,    17,    55,    15,    15,   132,   158,
      57,    22,    23,     9,   118,   130,   118,   130,    10,    52,
     166,    11,    77,   122,   143,    80,   144,   160,   161,    83,
      84,    85,   118,   130,   118,   130,    12,    20,   118,   147,
      18,   118,   118,    97,   100,    98,    34,    35,    36,    37,
      21,    38,   -78,   118,    34,    35,    36,    37,    48,    38,
      34,    35,    36,    37,   118,    38,   127,    51,    54,     1,
       2,    55,   119,     2,   121,    39,     3,   124,   125,    95,
      96,   140,    67,    39,    68,    69,   105,   106,    70,    39,
      71,   107,     1,     2,    74,     1,     2,   139,   108,     3,
      72,   128,    73,   128,   145,    75,   148,   109,    79,    81,
      13,   153,    24,    25,    26,    82,    27,    28,   156,   128,
      29,   128,    61,    62,    63,    64,    65,    66,   164,   102,
      58,    59,    60,   103,   167,    86,    87,    88,    89,    90,
      91,    92,    93,    94,   123,   126,   131,   133,   134,   135,
     137,   138,   149,   152,   154,   155,     8,   159,   157,   163,
     165,   168,   120,   101,    78,   162
};

static const yytype_uint8 yycheck[] =
{
      19,     0,    20,    14,   134,    28,     5,   137,   138,     8,
      14,    81,    53,    99,     8,    56,    15,    16,   112,   149,
      39,    15,    16,    24,   110,   110,   112,   112,    24,    52,
     160,    24,    51,   103,   128,    54,   130,    10,    11,    58,
      59,    60,   128,   128,   130,   130,     0,    58,   134,     7,
      14,   137,   138,    72,    58,    73,    22,    23,    24,    25,
      51,    27,    37,   149,    22,    23,    24,    25,    24,    27,
      22,    23,    24,    25,   160,    27,    51,    53,    53,    12,
      13,    56,   100,    13,   102,    51,    19,   106,   107,    70,
      71,    57,    43,    51,    45,    46,     3,     4,    42,    51,
      44,     8,    12,    13,    52,    12,    13,   126,    15,    19,
      14,   110,    58,   112,   133,    57,   135,    24,    11,    24,
      30,   140,    16,    17,    18,    51,    20,    21,   147,   128,
      24,   130,    31,    32,    33,    34,    35,    36,   157,    54,
      38,    39,    40,    54,   163,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    24,    51,    11,    37,    14,     6,
       5,     9,     5,    52,    52,    11,     0,    11,    55,    55,
      11,    11,   101,    75,    52,   153
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    13,    19,    60,    62,    63,    64,    65,    24,
      24,    24,     0,    30,    61,    62,    65,    61,    14,    14,
      58,    51,    61,    61,    16,    17,    18,    20,    21,    24,
      69,    70,    71,    73,    22,    23,    24,    25,    27,    51,
      84,    85,    86,    87,    88,    89,    90,    69,    24,    66,
      68,    53,    63,    72,    53,    56,    91,    84,    38,    39,
      40,    31,    32,    33,    34,    35,    36,    43,    45,    46,
      42,    44,    14,    58,    52,    57,    67,    84,    72,    11,
      84,    24,    51,    84,    84,    84,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    87,    87,    84,    69,    14,
      58,    68,    54,    54,    91,     3,     4,     8,    15,    24,
      62,    74,    76,    77,    78,    80,    81,    83,    90,    69,
      67,    69,    91,    24,    84,    84,    51,    51,    62,    75,
      76,    11,    75,    37,    14,     6,    82,     5,     9,    84,
      57,    79,    84,    75,    75,    84,    74,     7,    84,     5,
      74,    74,    52,    84,    52,    11,    84,    55,    74,    11,
      10,    11,    79,    55,    84,    11,    74,    84,    11
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    61,    62,    62,    63,
      63,    63,    64,    65,    65,    66,    67,    67,    68,    69,
      69,    69,    69,    70,    70,    70,    71,    72,    72,    73,
      74,    74,    74,    75,    75,    75,    76,    76,    76,    76,
      76,    76,    77,    78,    78,    79,    79,    80,    81,    82,
      82,    83,    83,    84,    84,    84,    84,    85,    85,    85,
      85,    85,    85,    85,    86,    86,    86,    86,    87,    87,
      87,    88,    88,    89,    89,    89,    89,    89,    90,    90,
      91,    91,    91,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     2,     1,     1,     6,
       4,     4,     4,    10,     8,     2,     0,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     0,     2,     5,
       0,     2,     2,     0,     2,     2,     1,     1,     1,     1,
       1,     4,     3,     1,     4,     1,     3,     5,     6,     4,
       5,     7,     5,     1,     3,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     3,     4
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
#line 242 "Analyser.y"
                                        {root = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "root", "root");}
#line 1404 "Analyser.tab.c"
    break;

  case 3: /* Program: RoutineDeclaration Programs  */
#line 243 "Analyser.y"
                                        {root = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "root", "root");}
#line 1410 "Analyser.tab.c"
    break;

  case 4: /* Programs: T_EOF  */
#line 246 "Analyser.y"
                                         {(yyval.nodeList) = vector<Node*>();}
#line 1416 "Analyser.tab.c"
    break;

  case 5: /* Programs: SimpleDeclaration Programs  */
#line 247 "Analyser.y"
                                        {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1422 "Analyser.tab.c"
    break;

  case 6: /* Programs: RoutineDeclaration Programs  */
#line 248 "Analyser.y"
                                        {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1428 "Analyser.tab.c"
    break;

  case 7: /* SimpleDeclaration: VariableDeclaration  */
#line 251 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1434 "Analyser.tab.c"
    break;

  case 8: /* SimpleDeclaration: TypeDeclaration  */
#line 252 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1440 "Analyser.tab.c"
    break;

  case 9: /* VariableDeclaration: T_VAR T_ID T_COLON Type T_IS Expression  */
#line 258 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-4].string))), (yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "var_decl_colon_is", "colon_is");}
#line 1446 "Analyser.tab.c"
    break;

  case 10: /* VariableDeclaration: T_VAR T_ID T_COLON Type  */
#line 259 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-2].string))), (yyvsp[0].nodeLink), "var_decl_colon", "colon");}
#line 1452 "Analyser.tab.c"
    break;

  case 11: /* VariableDeclaration: T_VAR T_ID T_IS Expression  */
#line 260 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-2].string))), (yyvsp[0].nodeLink), "var_decl_is", "is");}
#line 1458 "Analyser.tab.c"
    break;

  case 12: /* TypeDeclaration: T_TYPE T_ID T_IS Type  */
#line 263 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-2].string))), (yyvsp[0].nodeLink), "type_decl_is", "is");}
#line 1464 "Analyser.tab.c"
    break;

  case 13: /* RoutineDeclaration: T_ROUTINE T_ID T_LPAREN Parameters T_RPAREN T_COLON Type T_IS Body T_END  */
#line 269 "Analyser.y"
                                                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-8].string))), (yyvsp[-6].nodeLink), (yyvsp[-3].nodeLink),(yyvsp[-1].nodeLink), "routin_decl_type", "routin_decl_type");}
#line 1470 "Analyser.tab.c"
    break;

  case 14: /* RoutineDeclaration: T_ROUTINE T_ID T_LPAREN Parameters T_RPAREN T_IS Body T_END  */
#line 270 "Analyser.y"
                                                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-6].string))), (yyvsp[-4].nodeLink), (yyvsp[-1].nodeLink), "routin_decl", "routin_decl");}
#line 1476 "Analyser.tab.c"
    break;

  case 15: /* Parameters: ParameterDeclaration ParameterDeclarations  */
#line 273 "Analyser.y"
                                                                                                {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "param", "param");}
#line 1482 "Analyser.tab.c"
    break;

  case 16: /* ParameterDeclarations: %empty  */
#line 277 "Analyser.y"
                                                                                                {(yyval.nodeList) = vector<Node*>();}
#line 1488 "Analyser.tab.c"
    break;

  case 17: /* ParameterDeclarations: T_COMMA ParameterDeclaration ParameterDeclarations  */
#line 278 "Analyser.y"
                                                                                                {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1494 "Analyser.tab.c"
    break;

  case 18: /* ParameterDeclaration: T_ID T_COLON Type  */
#line 281 "Analyser.y"
                                            {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-2].string))), (yyvsp[0].nodeLink), "T_COLON", ":");}
#line 1500 "Analyser.tab.c"
    break;

  case 19: /* Type: PrimitiveType  */
#line 284 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1506 "Analyser.tab.c"
    break;

  case 20: /* Type: ArrayType  */
#line 285 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1512 "Analyser.tab.c"
    break;

  case 21: /* Type: RecordType  */
#line 286 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1518 "Analyser.tab.c"
    break;

  case 22: /* Type: T_ID  */
#line 287 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_ID", (yyvsp[0].string));}
#line 1524 "Analyser.tab.c"
    break;

  case 23: /* PrimitiveType: T_INTEGER  */
#line 290 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_INTEGER", "integer");}
#line 1530 "Analyser.tab.c"
    break;

  case 24: /* PrimitiveType: T_REAL  */
#line 291 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_REAL", "real");}
#line 1536 "Analyser.tab.c"
    break;

  case 25: /* PrimitiveType: T_BOOLEAN  */
#line 292 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_BOOLEAN", "boolean");}
#line 1542 "Analyser.tab.c"
    break;

  case 26: /* RecordType: T_RECORD VariableDeclarations T_END  */
#line 295 "Analyser.y"
                                                 {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeList), "T_RECORD", "record");}
#line 1548 "Analyser.tab.c"
    break;

  case 27: /* VariableDeclarations: %empty  */
#line 299 "Analyser.y"
                                                                {(yyval.nodeList) = vector<Node*>();}
#line 1554 "Analyser.tab.c"
    break;

  case 28: /* VariableDeclarations: VariableDeclaration VariableDeclarations  */
#line 300 "Analyser.y"
                                                                {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1560 "Analyser.tab.c"
    break;

  case 29: /* ArrayType: T_ARRAY T_LBRACK Expression T_RBRACK Type  */
#line 303 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_ARRAY", "array");}
#line 1566 "Analyser.tab.c"
    break;

  case 30: /* Body: %empty  */
#line 308 "Analyser.y"
                                    {(yyval.nodeLink) = createNode("BODY", "body");}
#line 1572 "Analyser.tab.c"
    break;

  case 31: /* Body: SimpleDeclaration Bodies  */
#line 309 "Analyser.y"
                                    {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "BODY", "body");}
#line 1578 "Analyser.tab.c"
    break;

  case 32: /* Body: Statement Bodies  */
#line 310 "Analyser.y"
                                    {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "BODY", "body");}
#line 1584 "Analyser.tab.c"
    break;

  case 33: /* Bodies: %empty  */
#line 313 "Analyser.y"
                                    {(yyval.nodeList) = vector<Node*>();}
#line 1590 "Analyser.tab.c"
    break;

  case 34: /* Bodies: SimpleDeclaration Bodies  */
#line 314 "Analyser.y"
                                    {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1596 "Analyser.tab.c"
    break;

  case 35: /* Bodies: Statement Bodies  */
#line 315 "Analyser.y"
                                    {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1602 "Analyser.tab.c"
    break;

  case 36: /* Statement: Assignment  */
#line 318 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1608 "Analyser.tab.c"
    break;

  case 37: /* Statement: RoutineCall  */
#line 319 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1614 "Analyser.tab.c"
    break;

  case 38: /* Statement: WhileLoop  */
#line 320 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1620 "Analyser.tab.c"
    break;

  case 39: /* Statement: ForLoop  */
#line 321 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1626 "Analyser.tab.c"
    break;

  case 40: /* Statement: IfStatement  */
#line 322 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1632 "Analyser.tab.c"
    break;

  case 41: /* Statement: T_PRINT T_LPAREN Expression T_RPAREN  */
#line 323 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode((yyvsp[-1].nodeLink), "T_PRINT", "print");}
#line 1638 "Analyser.tab.c"
    break;

  case 42: /* Assignment: ModifiablePrimary T_COLONEQU Expression  */
#line 326 "Analyser.y"
                                                     {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_COLONEQU", ":=");}
#line 1644 "Analyser.tab.c"
    break;

  case 43: /* RoutineCall: T_ID  */
#line 330 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode("T_ID", (yyvsp[0].string));}
#line 1650 "Analyser.tab.c"
    break;

  case 44: /* RoutineCall: T_ID T_LPAREN Expressions T_RPAREN  */
#line 331 "Analyser.y"
                                                    {(yyval.nodeLink) = combineNodes(new Node(Token("T_ID", (yyvsp[-3].string))), (yyvsp[-1].nodeList), "RoutineCall", "RoutineCall");}
#line 1656 "Analyser.tab.c"
    break;

  case 45: /* Expressions: Expression  */
#line 335 "Analyser.y"
                                                    {(yyval.nodeList) = collectNodes((yyvsp[0].nodeLink));}
#line 1662 "Analyser.tab.c"
    break;

  case 46: /* Expressions: T_COMMA Expression Expressions  */
#line 336 "Analyser.y"
                                                    {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1668 "Analyser.tab.c"
    break;

  case 47: /* WhileLoop: T_WHILE Expression T_LOOP Body T_END  */
#line 339 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode((yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), "T_WHILE", "while");}
#line 1674 "Analyser.tab.c"
    break;

  case 48: /* ForLoop: T_FOR T_ID Range T_LOOP Body T_END  */
#line 342 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-4].string))), (yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), "T_FOR", "for");}
#line 1680 "Analyser.tab.c"
    break;

  case 49: /* Range: T_IN Expression T_DOTDOT Expression  */
#line 345 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_IN", "in");}
#line 1686 "Analyser.tab.c"
    break;

  case 50: /* Range: T_IN T_REVERSE Expression T_DOTDOT Expression  */
#line 346 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_IN_REVERSE", "in_reverse");}
#line 1692 "Analyser.tab.c"
    break;

  case 51: /* IfStatement: T_IF Expression T_THEN Body T_ELSE Body T_END  */
#line 349 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode((yyvsp[-5].nodeLink), (yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), "T_IF_ELSE", "if_else");}
#line 1698 "Analyser.tab.c"
    break;

  case 52: /* IfStatement: T_IF Expression T_THEN Body T_END  */
#line 350 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode((yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), "T_IF", "if");}
#line 1704 "Analyser.tab.c"
    break;

  case 53: /* Expression: Relation  */
#line 354 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1710 "Analyser.tab.c"
    break;

  case 54: /* Expression: Relation T_AND Expression  */
#line 355 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_AND", "and");}
#line 1716 "Analyser.tab.c"
    break;

  case 55: /* Expression: Relation T_OR Expression  */
#line 356 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_OR", "or");}
#line 1722 "Analyser.tab.c"
    break;

  case 56: /* Expression: Relation T_XOR Expression  */
#line 357 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_XOR", "xor");}
#line 1728 "Analyser.tab.c"
    break;

  case 57: /* Relation: Simple  */
#line 369 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1734 "Analyser.tab.c"
    break;

  case 58: /* Relation: Simple T_LESS Simple  */
#line 370 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_LESS", "<");}
#line 1740 "Analyser.tab.c"
    break;

  case 59: /* Relation: Simple T_LESSOREQU Simple  */
#line 371 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_LESSOREQU", "<=");}
#line 1746 "Analyser.tab.c"
    break;

  case 60: /* Relation: Simple T_GREAT Simple  */
#line 372 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_GREAT", ">");}
#line 1752 "Analyser.tab.c"
    break;

  case 61: /* Relation: Simple T_GREATOREQU Simple  */
#line 373 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_GREATOREQU", ">=");}
#line 1758 "Analyser.tab.c"
    break;

  case 62: /* Relation: Simple T_EQU Simple  */
#line 374 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_EQU", "=");}
#line 1764 "Analyser.tab.c"
    break;

  case 63: /* Relation: Simple T_NOTEQU Simple  */
#line 375 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_NOTEQU", "/=");}
#line 1770 "Analyser.tab.c"
    break;

  case 64: /* Simple: Factor  */
#line 379 "Analyser.y"
                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1776 "Analyser.tab.c"
    break;

  case 65: /* Simple: Factor T_MULTOP Simple  */
#line 380 "Analyser.y"
                                   {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_MULTOP", "*");}
#line 1782 "Analyser.tab.c"
    break;

  case 66: /* Simple: Factor T_DIVOP Simple  */
#line 381 "Analyser.y"
                                   {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_DIVOP", "/");}
#line 1788 "Analyser.tab.c"
    break;

  case 67: /* Simple: Factor T_MODOP Simple  */
#line 382 "Analyser.y"
                                   {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_MODOP", "%");}
#line 1794 "Analyser.tab.c"
    break;

  case 68: /* Factor: Summand  */
#line 387 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1800 "Analyser.tab.c"
    break;

  case 69: /* Factor: Summand T_ADDOP Factor  */
#line 388 "Analyser.y"
                                      {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_ADDOP", "+");}
#line 1806 "Analyser.tab.c"
    break;

  case 70: /* Factor: Summand T_SUBTROP Factor  */
#line 389 "Analyser.y"
                                      {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_SUBTROP", "-");}
#line 1812 "Analyser.tab.c"
    break;

  case 71: /* Summand: Primary  */
#line 392 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1818 "Analyser.tab.c"
    break;

  case 72: /* Summand: T_LPAREN Expression T_LPAREN  */
#line 393 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[-1].nodeLink);}
#line 1824 "Analyser.tab.c"
    break;

  case 73: /* Primary: T_ICONST  */
#line 396 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_ICONST", to_string((yyvsp[0].integer)));}
#line 1830 "Analyser.tab.c"
    break;

  case 74: /* Primary: T_RCONST  */
#line 397 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_RCONST", to_string((yyvsp[0].real)));}
#line 1836 "Analyser.tab.c"
    break;

  case 75: /* Primary: T_TRUE  */
#line 398 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_TRUE", "true");}
#line 1842 "Analyser.tab.c"
    break;

  case 76: /* Primary: T_FALSE  */
#line 399 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_FALSE", "false");}
#line 1848 "Analyser.tab.c"
    break;

  case 77: /* Primary: ModifiablePrimary  */
#line 400 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1854 "Analyser.tab.c"
    break;

  case 78: /* ModifiablePrimary: T_ID  */
#line 404 "Analyser.y"
                                    {(yyval.nodeLink) = createNode("T_ID", (yyvsp[0].string));}
#line 1860 "Analyser.tab.c"
    break;

  case 79: /* ModifiablePrimary: T_ID Identifiers  */
#line 405 "Analyser.y"
                                    {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-1].string))), (yyvsp[0].nodeLink),"ModifiablePrim", "ModifiablePrim");}
#line 1866 "Analyser.tab.c"
    break;

  case 80: /* Identifiers: T_DOT T_ID  */
#line 409 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[0].string))),"T_DOT", ".");}
#line 1872 "Analyser.tab.c"
    break;

  case 81: /* Identifiers: T_DOT T_ID Identifiers  */
#line 410 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-1].string))), (yyvsp[0].nodeLink),"T_DOT", ".");}
#line 1878 "Analyser.tab.c"
    break;

  case 82: /* Identifiers: T_LBRACK Expression T_RBRACK  */
#line 411 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-1].nodeLink),"BRACKS", "[]");}
#line 1884 "Analyser.tab.c"
    break;

  case 83: /* Identifiers: T_LBRACK Expression T_RBRACK Identifiers  */
#line 412 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink),"BRACKS", "[]");}
#line 1890 "Analyser.tab.c"
    break;


#line 1894 "Analyser.tab.c"

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

#line 420 "Analyser.y"


void printAST(Node *curNode, int depth = 0)
{
    for (int i = 0; i < depth; ++i)
        cout << "---";

    if (curNode->nodes.empty())
        cout << "| ";
    else
        cout << "> ";

    cout << curNode->token.token << " : " << curNode->token.lexeme << endl;

    for (Node *nextNode : curNode->nodes)
    {
        printAST(nextNode, depth + 1);
    }
}

int main (void) {
    auto newNode = yyparse();
    
    cout << "\n\n";
    printAST(root, 0);
    return 0;
}
