/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_ANALYSER_TAB_HH_INCLUDED
# define YY_YY_ANALYSER_TAB_HH_INCLUDED
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
    T_INTEGER = 271,               /* T_INTEGER  */
    T_REAL = 272,                  /* T_REAL  */
    T_BOOLEAN = 273,               /* T_BOOLEAN  */
    T_ROUTINE = 274,               /* T_ROUTINE  */
    T_ARRAY = 275,                 /* T_ARRAY  */
    T_RECORD = 276,                /* T_RECORD  */
    T_TRUE = 277,                  /* T_TRUE  */
    T_FALSE = 278,                 /* T_FALSE  */
    T_ID = 279,                    /* T_ID  */
    T_ICONST = 280,                /* T_ICONST  */
    T_SCONST = 281,                /* T_SCONST  */
    T_RCONST = 282,                /* T_RCONST  */
    T_BCONST = 283,                /* T_BCONST  */
    T_CCONST = 284,                /* T_CCONST  */
    T_EOF = 285,                   /* T_EOF  */
    T_LESS = 286,                  /* T_LESS  */
    T_GREAT = 287,                 /* T_GREAT  */
    T_LESSOREQU = 288,             /* T_LESSOREQU  */
    T_GREATOREQU = 289,            /* T_GREATOREQU  */
    T_NOTEQU = 290,                /* T_NOTEQU  */
    T_EQU = 291,                   /* T_EQU  */
    T_COLONEQU = 292,              /* T_COLONEQU  */
    T_AND = 293,                   /* T_AND  */
    T_OR = 294,                    /* T_OR  */
    T_XOR = 295,                   /* T_XOR  */
    T_NOT = 296,                   /* T_NOT  */
    T_ADDOP = 297,                 /* T_ADDOP  */
    T_MULTOP = 298,                /* T_MULTOP  */
    T_SUBTROP = 299,               /* T_SUBTROP  */
    T_DIVOP = 300,                 /* T_DIVOP  */
    T_MODOP = 301,                 /* T_MODOP  */
    T_TAB = 302,                   /* T_TAB  */
    T_NL = 303,                    /* T_NL  */
    T_POINTER = 304,               /* T_POINTER  */
    T_REFERENCE = 305,             /* T_REFERENCE  */
    T_LPAREN = 306,                /* T_LPAREN  */
    T_RPAREN = 307,                /* T_RPAREN  */
    T_LBRACK = 308,                /* T_LBRACK  */
    T_RBRACK = 309,                /* T_RBRACK  */
    T_DOTDOT = 310,                /* T_DOTDOT  */
    T_DOT = 311,                   /* T_DOT  */
    T_COMMA = 312,                 /* T_COMMA  */
    T_COLON = 313                  /* T_COLON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 47 "Analyser.yy"

  unsigned int integer;
  double real;
  char *string;
  char character;
  int boolean;

#line 130 "Analyser.tab.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ANALYSER_TAB_HH_INCLUDED  */
