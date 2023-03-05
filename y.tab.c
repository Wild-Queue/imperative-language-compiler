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
    extern FILE *yyin;
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

        long long int integer;
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



#line 210 "y.tab.c"

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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_FOR = 258,                   /* T_FOR  */
    T_WHILE = 259,                 /* T_WHILE  */
    T_LOOP = 260,                  /* T_LOOP  */
    T_IN = 261,                    /* T_IN  */
    T_REVERSE = 262,               /* T_REVERSE  */
    T_IF = 263,                    /* T_IF  */
    T_THEN = 264,                  /* T_THEN  */
    T_ELSE = 265,                  /* T_ELSE  */
    T_END = 266,                   /* T_END  */
    T_TYPE = 267,                  /* T_TYPE  */
    T_VAR = 268,                   /* T_VAR  */
    T_IS = 269,                    /* T_IS  */
    T_PRINT = 270,                 /* T_PRINT  */
    T_RETURN = 271,                /* T_RETURN  */
    T_INTEGER = 272,               /* T_INTEGER  */
    T_REAL = 273,                  /* T_REAL  */
    T_BOOLEAN = 274,               /* T_BOOLEAN  */
    T_ROUTINE = 275,               /* T_ROUTINE  */
    T_ARRAY = 276,                 /* T_ARRAY  */
    T_RECORD = 277,                /* T_RECORD  */
    T_TRUE = 278,                  /* T_TRUE  */
    T_FALSE = 279,                 /* T_FALSE  */
    T_ID = 280,                    /* T_ID  */
    T_ICONST = 281,                /* T_ICONST  */
    T_SCONST = 282,                /* T_SCONST  */
    T_RCONST = 283,                /* T_RCONST  */
    T_BCONST = 284,                /* T_BCONST  */
    T_CCONST = 285,                /* T_CCONST  */
    T_EOF = 286,                   /* T_EOF  */
    T_LESS = 287,                  /* T_LESS  */
    T_GREAT = 288,                 /* T_GREAT  */
    T_LESSOREQU = 289,             /* T_LESSOREQU  */
    T_GREATOREQU = 290,            /* T_GREATOREQU  */
    T_NOTEQU = 291,                /* T_NOTEQU  */
    T_EQU = 292,                   /* T_EQU  */
    T_COLONEQU = 293,              /* T_COLONEQU  */
    T_AND = 294,                   /* T_AND  */
    T_OR = 295,                    /* T_OR  */
    T_XOR = 296,                   /* T_XOR  */
    T_NOT = 297,                   /* T_NOT  */
    T_ADDOP = 298,                 /* T_ADDOP  */
    T_MULTOP = 299,                /* T_MULTOP  */
    T_SUBTROP = 300,               /* T_SUBTROP  */
    T_DIVOP = 301,                 /* T_DIVOP  */
    T_MODOP = 302,                 /* T_MODOP  */
    T_TAB = 303,                   /* T_TAB  */
    T_NL = 304,                    /* T_NL  */
    T_POINTER = 305,               /* T_POINTER  */
    T_REFERENCE = 306,             /* T_REFERENCE  */
    T_LPAREN = 307,                /* T_LPAREN  */
    T_RPAREN = 308,                /* T_RPAREN  */
    T_LBRACK = 309,                /* T_LBRACK  */
    T_RBRACK = 310,                /* T_RBRACK  */
    T_DOTDOT = 311,                /* T_DOTDOT  */
    T_DOT = 312,                   /* T_DOT  */
    T_COMMA = 313,                 /* T_COMMA  */
    T_COLON = 314                  /* T_COLON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_FOR 258
#define T_WHILE 259
#define T_LOOP 260
#define T_IN 261
#define T_REVERSE 262
#define T_IF 263
#define T_THEN 264
#define T_ELSE 265
#define T_END 266
#define T_TYPE 267
#define T_VAR 268
#define T_IS 269
#define T_PRINT 270
#define T_RETURN 271
#define T_INTEGER 272
#define T_REAL 273
#define T_BOOLEAN 274
#define T_ROUTINE 275
#define T_ARRAY 276
#define T_RECORD 277
#define T_TRUE 278
#define T_FALSE 279
#define T_ID 280
#define T_ICONST 281
#define T_SCONST 282
#define T_RCONST 283
#define T_BCONST 284
#define T_CCONST 285
#define T_EOF 286
#define T_LESS 287
#define T_GREAT 288
#define T_LESSOREQU 289
#define T_GREATOREQU 290
#define T_NOTEQU 291
#define T_EQU 292
#define T_COLONEQU 293
#define T_AND 294
#define T_OR 295
#define T_XOR 296
#define T_NOT 297
#define T_ADDOP 298
#define T_MULTOP 299
#define T_SUBTROP 300
#define T_DIVOP 301
#define T_MODOP 302
#define T_TAB 303
#define T_NL 304
#define T_POINTER 305
#define T_REFERENCE 306
#define T_LPAREN 307
#define T_RPAREN 308
#define T_LBRACK 309
#define T_RBRACK 310
#define T_DOTDOT 311
#define T_DOT 312
#define T_COMMA 313
#define T_COLON 314

/* Value type.  */


extern YYSTYPE yylval;


int yyparse (void);



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
  YYSYMBOL_T_ROUTINE = 20,                 /* T_ROUTINE  */
  YYSYMBOL_T_ARRAY = 21,                   /* T_ARRAY  */
  YYSYMBOL_T_RECORD = 22,                  /* T_RECORD  */
  YYSYMBOL_T_TRUE = 23,                    /* T_TRUE  */
  YYSYMBOL_T_FALSE = 24,                   /* T_FALSE  */
  YYSYMBOL_T_ID = 25,                      /* T_ID  */
  YYSYMBOL_T_ICONST = 26,                  /* T_ICONST  */
  YYSYMBOL_T_SCONST = 27,                  /* T_SCONST  */
  YYSYMBOL_T_RCONST = 28,                  /* T_RCONST  */
  YYSYMBOL_T_BCONST = 29,                  /* T_BCONST  */
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
  YYSYMBOL_T_NOT = 42,                     /* T_NOT  */
  YYSYMBOL_T_ADDOP = 43,                   /* T_ADDOP  */
  YYSYMBOL_T_MULTOP = 44,                  /* T_MULTOP  */
  YYSYMBOL_T_SUBTROP = 45,                 /* T_SUBTROP  */
  YYSYMBOL_T_DIVOP = 46,                   /* T_DIVOP  */
  YYSYMBOL_T_MODOP = 47,                   /* T_MODOP  */
  YYSYMBOL_T_TAB = 48,                     /* T_TAB  */
  YYSYMBOL_T_NL = 49,                      /* T_NL  */
  YYSYMBOL_T_POINTER = 50,                 /* T_POINTER  */
  YYSYMBOL_T_REFERENCE = 51,               /* T_REFERENCE  */
  YYSYMBOL_T_LPAREN = 52,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 53,                  /* T_RPAREN  */
  YYSYMBOL_T_LBRACK = 54,                  /* T_LBRACK  */
  YYSYMBOL_T_RBRACK = 55,                  /* T_RBRACK  */
  YYSYMBOL_T_DOTDOT = 56,                  /* T_DOTDOT  */
  YYSYMBOL_T_DOT = 57,                     /* T_DOT  */
  YYSYMBOL_T_COMMA = 58,                   /* T_COMMA  */
  YYSYMBOL_T_COLON = 59,                   /* T_COLON  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_Program = 61,                   /* Program  */
  YYSYMBOL_Programs = 62,                  /* Programs  */
  YYSYMBOL_SimpleDeclaration = 63,         /* SimpleDeclaration  */
  YYSYMBOL_VariableDeclaration = 64,       /* VariableDeclaration  */
  YYSYMBOL_TypeDeclaration = 65,           /* TypeDeclaration  */
  YYSYMBOL_RoutineDeclaration = 66,        /* RoutineDeclaration  */
  YYSYMBOL_Parameters = 67,                /* Parameters  */
  YYSYMBOL_ParameterDeclarations = 68,     /* ParameterDeclarations  */
  YYSYMBOL_ParameterDeclaration = 69,      /* ParameterDeclaration  */
  YYSYMBOL_Type = 70,                      /* Type  */
  YYSYMBOL_PrimitiveType = 71,             /* PrimitiveType  */
  YYSYMBOL_RecordType = 72,                /* RecordType  */
  YYSYMBOL_VariableDeclarations = 73,      /* VariableDeclarations  */
  YYSYMBOL_ArrayType = 74,                 /* ArrayType  */
  YYSYMBOL_Body = 75,                      /* Body  */
  YYSYMBOL_Bodies = 76,                    /* Bodies  */
  YYSYMBOL_Statement = 77,                 /* Statement  */
  YYSYMBOL_Assignment = 78,                /* Assignment  */
  YYSYMBOL_RoutineCall = 79,               /* RoutineCall  */
  YYSYMBOL_Expressions = 80,               /* Expressions  */
  YYSYMBOL_WhileLoop = 81,                 /* WhileLoop  */
  YYSYMBOL_ForLoop = 82,                   /* ForLoop  */
  YYSYMBOL_Range = 83,                     /* Range  */
  YYSYMBOL_IfStatement = 84,               /* IfStatement  */
  YYSYMBOL_Expression = 85,                /* Expression  */
  YYSYMBOL_Relation = 86,                  /* Relation  */
  YYSYMBOL_Simple = 87,                    /* Simple  */
  YYSYMBOL_Factor = 88,                    /* Factor  */
  YYSYMBOL_Summand = 89,                   /* Summand  */
  YYSYMBOL_Primary = 90,                   /* Primary  */
  YYSYMBOL_ModifiablePrimary = 91,         /* ModifiablePrimary  */
  YYSYMBOL_Identifiers = 92                /* Identifiers  */
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
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


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
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   245,   245,   246,   249,   250,   251,   254,   255,   261,
     262,   263,   266,   272,   273,   276,   280,   281,   284,   287,
     288,   289,   290,   293,   294,   295,   298,   302,   303,   306,
     311,   312,   313,   316,   317,   318,   321,   322,   323,   324,
     325,   326,   327,   330,   334,   335,   339,   340,   343,   346,
     349,   350,   353,   354,   358,   359,   360,   361,   373,   374,
     375,   376,   377,   378,   379,   383,   384,   385,   386,   391,
     392,   393,   396,   397,   400,   401,   402,   403,   404,   408,
     409,   413,   414,   415,   416
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
  "T_BOOLEAN", "T_ROUTINE", "T_ARRAY", "T_RECORD", "T_TRUE", "T_FALSE",
  "T_ID", "T_ICONST", "T_SCONST", "T_RCONST", "T_BCONST", "T_CCONST",
  "T_EOF", "T_LESS", "T_GREAT", "T_LESSOREQU", "T_GREATOREQU", "T_NOTEQU",
  "T_EQU", "T_COLONEQU", "T_AND", "T_OR", "T_XOR", "T_NOT", "T_ADDOP",
  "T_MULTOP", "T_SUBTROP", "T_DIVOP", "T_MODOP", "T_TAB", "T_NL",
  "T_POINTER", "T_REFERENCE", "T_LPAREN", "T_RPAREN", "T_LBRACK",
  "T_RBRACK", "T_DOTDOT", "T_DOT", "T_COMMA", "T_COLON", "$accept",
  "Program", "Programs", "SimpleDeclaration", "VariableDeclaration",
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

#define YYPACT_NINF (-95)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-80)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -4,     9,    41,    50,    15,    79,   -95,   -95,    79,    -8,
     -13,    34,   -95,   -95,   -95,    79,    79,   -95,   143,    44,
     143,    55,   -95,   -95,   -95,   -95,   -95,    39,    81,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,    -7,   -95,   -95,    44,
     -95,    65,   137,    35,    28,   -95,   -95,    83,    42,    54,
      53,    44,    81,   101,    44,    89,   -95,    67,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,   143,   -10,    55,   -95,    62,   -95,   -95,
      66,    -7,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   125,
     143,    53,   143,    -7,   -95,    95,    44,    44,    70,    71,
      46,   125,   114,   125,   -95,   -95,   -95,   -95,   -95,    88,
     113,   -95,   -95,   -95,   124,   130,   127,    44,    44,    37,
     125,   -95,   125,   -95,   -95,    44,   125,     5,   134,   125,
     125,    91,    92,    44,    93,   -95,   -95,   -95,   -95,   132,
      44,   107,   125,   136,    48,   -95,   -95,    37,   -95,   -95,
     110,    44,   138,   -95,   125,   -95,   -95,    44,   -95,   -95,
     156,   -95,   -95
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     1,     4,     2,     0,     0,     3,     0,     0,
       0,     0,     5,     6,    23,    24,    25,     0,    27,    22,
      12,    19,    21,    20,    76,    77,    79,    74,    75,     0,
      11,    54,    58,    65,    69,    72,    78,    10,     0,     0,
      16,     0,    27,     0,     0,     0,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,    28,    26,
       0,    81,    73,    55,    56,    57,    59,    61,    60,    62,
      64,    63,    66,    67,    68,    70,    71,     9,    18,    30,
       0,    16,     0,    83,    82,     0,     0,     0,     0,     0,
      44,    33,     0,    33,    36,    37,    38,    39,    40,     0,
       0,    17,    29,    84,     0,     0,     0,     0,     0,     0,
      33,    31,    33,    14,    32,     0,    30,     0,     0,    30,
      30,     0,     0,     0,     0,    46,    34,    35,    43,     0,
       0,     0,    30,     0,     0,    42,    41,     0,    45,    13,
       0,     0,     0,    48,    30,    53,    47,     0,    50,    49,
       0,    51,    52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,     6,     2,   -15,   -95,   175,   -95,    75,   102,
     -17,   -95,   -95,   126,   -95,   -62,   -94,   -87,   -95,   -95,
      22,   -95,   -95,   -95,   -95,   -19,   -95,    90,   -16,   -95,
     -95,   -88,   -76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,    14,   111,     6,     7,    16,    49,    76,    50,
      30,    31,    32,    53,    33,   112,   131,   113,   114,   115,
     144,   116,   117,   138,   118,   145,    41,    42,    43,    44,
      45,    46,    56
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    19,     5,    47,    99,   104,    18,    15,     1,     2,
      15,   119,   150,    52,    17,    12,     3,    15,    15,   134,
      57,    22,    23,   119,   132,   119,   132,   123,    34,    35,
      36,    37,    77,    38,     9,    80,   146,    52,   147,    83,
      84,    85,   119,   132,   119,   132,    20,    54,   119,   100,
      55,   119,   119,    97,    95,    96,    98,    39,   164,   165,
      34,    35,    36,    37,   119,    38,    10,    34,    35,    36,
      37,    70,    38,    71,   149,    11,   119,   153,   154,    67,
      48,    68,    69,   120,   -79,   122,    21,   125,   126,    39,
     162,     1,     2,    51,     2,   143,    39,    72,   129,     3,
      54,    73,   170,    55,    58,    59,    60,    74,   141,   142,
      13,    75,    79,   130,    81,   130,   148,   102,   151,    82,
     124,   103,   127,   128,   157,   133,   135,   136,   105,   106,
     137,   160,   130,   107,   130,   139,   140,     1,     2,   152,
     108,   109,   168,   159,   155,   156,   158,   163,   171,   169,
     110,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      24,    25,    26,   161,    27,    28,   167,   172,    29,    61,
      62,    63,    64,    65,    66,     8,   121,   101,    78,   166
};

static const yytype_uint8 yycheck[] =
{
      19,    14,     0,    20,    14,    81,    14,     5,    12,    13,
       8,    99,     7,    28,     8,     0,    20,    15,    16,   113,
      39,    15,    16,   111,   111,   113,   113,   103,    23,    24,
      25,    26,    51,    28,    25,    54,   130,    52,   132,    58,
      59,    60,   130,   130,   132,   132,    59,    54,   136,    59,
      57,   139,   140,    72,    70,    71,    73,    52,    10,    11,
      23,    24,    25,    26,   152,    28,    25,    23,    24,    25,
      26,    43,    28,    45,   136,    25,   164,   139,   140,    44,
      25,    46,    47,   100,    38,   102,    52,   106,   107,    52,
     152,    12,    13,    54,    13,    58,    52,    14,    52,    20,
      54,    59,   164,    57,    39,    40,    41,    53,   127,   128,
      31,    58,    11,   111,    25,   113,   135,    55,   137,    52,
      25,    55,    52,    52,   143,    11,    38,    14,     3,     4,
       6,   150,   130,     8,   132,     5,     9,    12,    13,     5,
      15,    16,   161,    11,    53,    53,    53,    11,   167,    11,
      25,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      17,    18,    19,    56,    21,    22,    56,    11,    25,    32,
      33,    34,    35,    36,    37,     0,   101,    75,    52,   157
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    13,    20,    61,    63,    64,    65,    66,    25,
      25,    25,     0,    31,    62,    63,    66,    62,    14,    14,
      59,    52,    62,    62,    17,    18,    19,    21,    22,    25,
      70,    71,    72,    74,    23,    24,    25,    26,    28,    52,
      85,    86,    87,    88,    89,    90,    91,    70,    25,    67,
      69,    54,    64,    73,    54,    57,    92,    85,    39,    40,
      41,    32,    33,    34,    35,    36,    37,    44,    46,    47,
      43,    45,    14,    59,    53,    58,    68,    85,    73,    11,
      85,    25,    52,    85,    85,    85,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    88,    88,    85,    70,    14,
      59,    69,    55,    55,    92,     3,     4,     8,    15,    16,
      25,    63,    75,    77,    78,    79,    81,    82,    84,    91,
      70,    68,    70,    92,    25,    85,    85,    52,    52,    52,
      63,    76,    77,    11,    76,    38,    14,     6,    83,     5,
       9,    85,    85,    58,    80,    85,    76,    76,    85,    75,
       7,    85,     5,    75,    75,    53,    53,    85,    53,    11,
      85,    56,    75,    11,    10,    11,    80,    56,    85,    11,
      75,    85,    11
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    62,    63,    63,    64,
      64,    64,    65,    66,    66,    67,    68,    68,    69,    70,
      70,    70,    70,    71,    71,    71,    72,    73,    73,    74,
      75,    75,    75,    76,    76,    76,    77,    77,    77,    77,
      77,    77,    77,    78,    79,    79,    80,    80,    81,    82,
      83,    83,    84,    84,    85,    85,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    87,    87,    87,    87,    88,
      88,    88,    89,    89,    90,    90,    90,    90,    90,    91,
      91,    92,    92,    92,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     2,     1,     1,     6,
       4,     4,     4,    10,     8,     2,     0,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     0,     2,     5,
       0,     2,     2,     0,     2,     2,     1,     1,     1,     1,
       1,     4,     4,     3,     1,     4,     1,     3,     5,     6,
       4,     5,     7,     5,     1,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     3,     4
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
#line 245 "Analyser.y"
                                        {root = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "root", "ROOT");}
#line 1561 "y.tab.c"
    break;

  case 3: /* Program: RoutineDeclaration Programs  */
#line 246 "Analyser.y"
                                        {root = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "root", "ROOT");}
#line 1567 "y.tab.c"
    break;

  case 4: /* Programs: T_EOF  */
#line 249 "Analyser.y"
                                         {(yyval.nodeList) = vector<Node*>();}
#line 1573 "y.tab.c"
    break;

  case 5: /* Programs: SimpleDeclaration Programs  */
#line 250 "Analyser.y"
                                        {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1579 "y.tab.c"
    break;

  case 6: /* Programs: RoutineDeclaration Programs  */
#line 251 "Analyser.y"
                                        {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1585 "y.tab.c"
    break;

  case 7: /* SimpleDeclaration: VariableDeclaration  */
#line 254 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1591 "y.tab.c"
    break;

  case 8: /* SimpleDeclaration: TypeDeclaration  */
#line 255 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1597 "y.tab.c"
    break;

  case 9: /* VariableDeclaration: T_VAR T_ID T_COLON Type T_IS Expression  */
#line 261 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-4].string))), (yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "var_decl_colon_is", "colon is");}
#line 1603 "y.tab.c"
    break;

  case 10: /* VariableDeclaration: T_VAR T_ID T_COLON Type  */
#line 262 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-2].string))), (yyvsp[0].nodeLink), "var_decl_colon", "colon");}
#line 1609 "y.tab.c"
    break;

  case 11: /* VariableDeclaration: T_VAR T_ID T_IS Expression  */
#line 263 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-2].string))), (yyvsp[0].nodeLink), "var_decl_is", "is");}
#line 1615 "y.tab.c"
    break;

  case 12: /* TypeDeclaration: T_TYPE T_ID T_IS Type  */
#line 266 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-2].string))), (yyvsp[0].nodeLink), "type_decl_is", "is");}
#line 1621 "y.tab.c"
    break;

  case 13: /* RoutineDeclaration: T_ROUTINE T_ID T_LPAREN Parameters T_RPAREN T_COLON Type T_IS Body T_END  */
#line 272 "Analyser.y"
                                                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-8].string))), (yyvsp[-6].nodeLink), (yyvsp[-3].nodeLink),(yyvsp[-1].nodeLink), "routin_decl_type", "routine");}
#line 1627 "y.tab.c"
    break;

  case 14: /* RoutineDeclaration: T_ROUTINE T_ID T_LPAREN Parameters T_RPAREN T_IS Body T_END  */
#line 273 "Analyser.y"
                                                                                                {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-6].string))), (yyvsp[-4].nodeLink), (yyvsp[-1].nodeLink), "routin_decl", "routine");}
#line 1633 "y.tab.c"
    break;

  case 15: /* Parameters: ParameterDeclaration ParameterDeclarations  */
#line 276 "Analyser.y"
                                                                                                {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "parameters", "PARAMETERS");}
#line 1639 "y.tab.c"
    break;

  case 16: /* ParameterDeclarations: %empty  */
#line 280 "Analyser.y"
                                                                                                {(yyval.nodeList) = vector<Node*>();}
#line 1645 "y.tab.c"
    break;

  case 17: /* ParameterDeclarations: T_COMMA ParameterDeclaration ParameterDeclarations  */
#line 281 "Analyser.y"
                                                                                                {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1651 "y.tab.c"
    break;

  case 18: /* ParameterDeclaration: T_ID T_COLON Type  */
#line 284 "Analyser.y"
                                            {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-2].string))), (yyvsp[0].nodeLink), "T_COLON", ":");}
#line 1657 "y.tab.c"
    break;

  case 19: /* Type: PrimitiveType  */
#line 287 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1663 "y.tab.c"
    break;

  case 20: /* Type: ArrayType  */
#line 288 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1669 "y.tab.c"
    break;

  case 21: /* Type: RecordType  */
#line 289 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1675 "y.tab.c"
    break;

  case 22: /* Type: T_ID  */
#line 290 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_ID", (yyvsp[0].string));}
#line 1681 "y.tab.c"
    break;

  case 23: /* PrimitiveType: T_INTEGER  */
#line 293 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_INTEGER", "integer");}
#line 1687 "y.tab.c"
    break;

  case 24: /* PrimitiveType: T_REAL  */
#line 294 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_REAL", "real");}
#line 1693 "y.tab.c"
    break;

  case 25: /* PrimitiveType: T_BOOLEAN  */
#line 295 "Analyser.y"
                                            {(yyval.nodeLink) = createNode("T_BOOLEAN", "boolean");}
#line 1699 "y.tab.c"
    break;

  case 26: /* RecordType: T_RECORD VariableDeclarations T_END  */
#line 298 "Analyser.y"
                                                 {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeList), "T_RECORD", "record");}
#line 1705 "y.tab.c"
    break;

  case 27: /* VariableDeclarations: %empty  */
#line 302 "Analyser.y"
                                                                {(yyval.nodeList) = vector<Node*>();}
#line 1711 "y.tab.c"
    break;

  case 28: /* VariableDeclarations: VariableDeclaration VariableDeclarations  */
#line 303 "Analyser.y"
                                                                {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1717 "y.tab.c"
    break;

  case 29: /* ArrayType: T_ARRAY T_LBRACK Expression T_RBRACK Type  */
#line 306 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_ARRAY", "array");}
#line 1723 "y.tab.c"
    break;

  case 30: /* Body: %empty  */
#line 311 "Analyser.y"
                                    {(yyval.nodeLink) = createNode("BODY", "BODY");}
#line 1729 "y.tab.c"
    break;

  case 31: /* Body: SimpleDeclaration Bodies  */
#line 312 "Analyser.y"
                                    {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "BODY", "BODY");}
#line 1735 "y.tab.c"
    break;

  case 32: /* Body: Statement Bodies  */
#line 313 "Analyser.y"
                                    {(yyval.nodeLink) = combineNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList), "BODY", "BODY");}
#line 1741 "y.tab.c"
    break;

  case 33: /* Bodies: %empty  */
#line 316 "Analyser.y"
                                    {(yyval.nodeList) = vector<Node*>();}
#line 1747 "y.tab.c"
    break;

  case 34: /* Bodies: SimpleDeclaration Bodies  */
#line 317 "Analyser.y"
                                    {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1753 "y.tab.c"
    break;

  case 35: /* Bodies: Statement Bodies  */
#line 318 "Analyser.y"
                                    {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1759 "y.tab.c"
    break;

  case 36: /* Statement: Assignment  */
#line 321 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1765 "y.tab.c"
    break;

  case 37: /* Statement: RoutineCall  */
#line 322 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1771 "y.tab.c"
    break;

  case 38: /* Statement: WhileLoop  */
#line 323 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1777 "y.tab.c"
    break;

  case 39: /* Statement: ForLoop  */
#line 324 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1783 "y.tab.c"
    break;

  case 40: /* Statement: IfStatement  */
#line 325 "Analyser.y"
                                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1789 "y.tab.c"
    break;

  case 41: /* Statement: T_RETURN T_LPAREN Expression T_RPAREN  */
#line 326 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode((yyvsp[-1].nodeLink), "T_RETURN", "return");}
#line 1795 "y.tab.c"
    break;

  case 42: /* Statement: T_PRINT T_LPAREN Expression T_RPAREN  */
#line 327 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode((yyvsp[-1].nodeLink), "T_PRINT", "print");}
#line 1801 "y.tab.c"
    break;

  case 43: /* Assignment: ModifiablePrimary T_COLONEQU Expression  */
#line 330 "Analyser.y"
                                                     {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_COLONEQU", ":=");}
#line 1807 "y.tab.c"
    break;

  case 44: /* RoutineCall: T_ID  */
#line 334 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode("T_ID", (yyvsp[0].string));}
#line 1813 "y.tab.c"
    break;

  case 45: /* RoutineCall: T_ID T_LPAREN Expressions T_RPAREN  */
#line 335 "Analyser.y"
                                                    {(yyval.nodeLink) = combineNodes(new Node(Token("T_ID", (yyvsp[-3].string))), (yyvsp[-1].nodeList), "RoutineCall", "ROUTINECALL");}
#line 1819 "y.tab.c"
    break;

  case 46: /* Expressions: Expression  */
#line 339 "Analyser.y"
                                                    {(yyval.nodeList) = collectNodes((yyvsp[0].nodeLink));}
#line 1825 "y.tab.c"
    break;

  case 47: /* Expressions: T_COMMA Expression Expressions  */
#line 340 "Analyser.y"
                                                    {(yyval.nodeList) = collectNodes((yyvsp[-1].nodeLink), (yyvsp[0].nodeList));}
#line 1831 "y.tab.c"
    break;

  case 48: /* WhileLoop: T_WHILE Expression T_LOOP Body T_END  */
#line 343 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode((yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), "T_WHILE", "while");}
#line 1837 "y.tab.c"
    break;

  case 49: /* ForLoop: T_FOR T_ID Range T_LOOP Body T_END  */
#line 346 "Analyser.y"
                                                    {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-4].string))), (yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), "T_FOR", "for");}
#line 1843 "y.tab.c"
    break;

  case 50: /* Range: T_IN Expression T_DOTDOT Expression  */
#line 349 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_IN", "in");}
#line 1849 "y.tab.c"
    break;

  case 51: /* Range: T_IN T_REVERSE Expression T_DOTDOT Expression  */
#line 350 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_IN_REVERSE", "in_reverse");}
#line 1855 "y.tab.c"
    break;

  case 52: /* IfStatement: T_IF Expression T_THEN Body T_ELSE Body T_END  */
#line 353 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode((yyvsp[-5].nodeLink), (yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), "T_IF_ELSE", "if else");}
#line 1861 "y.tab.c"
    break;

  case 53: /* IfStatement: T_IF Expression T_THEN Body T_END  */
#line 354 "Analyser.y"
                                                                {(yyval.nodeLink) = createNode((yyvsp[-3].nodeLink), (yyvsp[-1].nodeLink), "T_IF", "if");}
#line 1867 "y.tab.c"
    break;

  case 54: /* Expression: Relation  */
#line 358 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1873 "y.tab.c"
    break;

  case 55: /* Expression: Relation T_AND Expression  */
#line 359 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_AND", "and");}
#line 1879 "y.tab.c"
    break;

  case 56: /* Expression: Relation T_OR Expression  */
#line 360 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_OR", "or");}
#line 1885 "y.tab.c"
    break;

  case 57: /* Expression: Relation T_XOR Expression  */
#line 361 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_XOR", "xor");}
#line 1891 "y.tab.c"
    break;

  case 58: /* Relation: Simple  */
#line 373 "Analyser.y"
                                            {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1897 "y.tab.c"
    break;

  case 59: /* Relation: Simple T_LESS Simple  */
#line 374 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_LESS", "<");}
#line 1903 "y.tab.c"
    break;

  case 60: /* Relation: Simple T_LESSOREQU Simple  */
#line 375 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_LESSOREQU", "<=");}
#line 1909 "y.tab.c"
    break;

  case 61: /* Relation: Simple T_GREAT Simple  */
#line 376 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_GREAT", ">");}
#line 1915 "y.tab.c"
    break;

  case 62: /* Relation: Simple T_GREATOREQU Simple  */
#line 377 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_GREATOREQU", ">=");}
#line 1921 "y.tab.c"
    break;

  case 63: /* Relation: Simple T_EQU Simple  */
#line 378 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_EQU", "=");}
#line 1927 "y.tab.c"
    break;

  case 64: /* Relation: Simple T_NOTEQU Simple  */
#line 379 "Analyser.y"
                                            {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_NOTEQU", "/=");}
#line 1933 "y.tab.c"
    break;

  case 65: /* Simple: Factor  */
#line 383 "Analyser.y"
                                    {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1939 "y.tab.c"
    break;

  case 66: /* Simple: Factor T_MULTOP Simple  */
#line 384 "Analyser.y"
                                   {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_MULTOP", "*");}
#line 1945 "y.tab.c"
    break;

  case 67: /* Simple: Factor T_DIVOP Simple  */
#line 385 "Analyser.y"
                                   {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_DIVOP", "/");}
#line 1951 "y.tab.c"
    break;

  case 68: /* Simple: Factor T_MODOP Simple  */
#line 386 "Analyser.y"
                                   {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_MODOP", "%");}
#line 1957 "y.tab.c"
    break;

  case 69: /* Factor: Summand  */
#line 391 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1963 "y.tab.c"
    break;

  case 70: /* Factor: Summand T_ADDOP Factor  */
#line 392 "Analyser.y"
                                      {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_ADDOP", "+");}
#line 1969 "y.tab.c"
    break;

  case 71: /* Factor: Summand T_SUBTROP Factor  */
#line 393 "Analyser.y"
                                      {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink), "T_SUBTROP", "-");}
#line 1975 "y.tab.c"
    break;

  case 72: /* Summand: Primary  */
#line 396 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 1981 "y.tab.c"
    break;

  case 73: /* Summand: T_LPAREN Expression T_LPAREN  */
#line 397 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[-1].nodeLink);}
#line 1987 "y.tab.c"
    break;

  case 74: /* Primary: T_ICONST  */
#line 400 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_ICONST", to_string((yyvsp[0].integer)));}
#line 1993 "y.tab.c"
    break;

  case 75: /* Primary: T_RCONST  */
#line 401 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_RCONST", to_string((yyvsp[0].real)));}
#line 1999 "y.tab.c"
    break;

  case 76: /* Primary: T_TRUE  */
#line 402 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_TRUE", "true");}
#line 2005 "y.tab.c"
    break;

  case 77: /* Primary: T_FALSE  */
#line 403 "Analyser.y"
                                        {(yyval.nodeLink) = createNode("T_FALSE", "false");}
#line 2011 "y.tab.c"
    break;

  case 78: /* Primary: ModifiablePrimary  */
#line 404 "Analyser.y"
                                        {(yyval.nodeLink) = (yyvsp[0].nodeLink);}
#line 2017 "y.tab.c"
    break;

  case 79: /* ModifiablePrimary: T_ID  */
#line 408 "Analyser.y"
                                    {(yyval.nodeLink) = createNode("T_ID", (yyvsp[0].string));}
#line 2023 "y.tab.c"
    break;

  case 80: /* ModifiablePrimary: T_ID Identifiers  */
#line 409 "Analyser.y"
                                    {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-1].string))), (yyvsp[0].nodeLink),"ModifiablePrim", "MODIFIABLEPRIM");}
#line 2029 "y.tab.c"
    break;

  case 81: /* Identifiers: T_DOT T_ID  */
#line 413 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[0].string))),"T_DOT", ".");}
#line 2035 "y.tab.c"
    break;

  case 82: /* Identifiers: T_DOT T_ID Identifiers  */
#line 414 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode(new Node(Token("T_ID", (yyvsp[-1].string))), (yyvsp[0].nodeLink),"T_DOT", ".");}
#line 2041 "y.tab.c"
    break;

  case 83: /* Identifiers: T_LBRACK Expression T_RBRACK  */
#line 415 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-1].nodeLink),"BRACKS", "[]");}
#line 2047 "y.tab.c"
    break;

  case 84: /* Identifiers: T_LBRACK Expression T_RBRACK Identifiers  */
#line 416 "Analyser.y"
                                                        {(yyval.nodeLink) = createNode((yyvsp[-2].nodeLink), (yyvsp[0].nodeLink),"BRACKS", "[]");}
#line 2053 "y.tab.c"
    break;


#line 2057 "y.tab.c"

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

#line 419 "Analyser.y"


Node* generateAST (string inputfile) {
    yyin = fopen(inputfile.c_str(), "r");
    yyparse();
    fclose(yyin);

    return root;
}
