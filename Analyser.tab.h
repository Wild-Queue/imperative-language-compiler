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

#ifndef YY_YY_ANALYSER_TAB_H_INCLUDED
# define YY_YY_ANALYSER_TAB_H_INCLUDED
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
    T_CHAR = 275,                  /* T_CHAR  */
    T_ROUTINE = 276,               /* T_ROUTINE  */
    T_ARRAY = 277,                 /* T_ARRAY  */
    T_RECORD = 278,                /* T_RECORD  */
    T_TRUE = 279,                  /* T_TRUE  */
    T_FALSE = 280,                 /* T_FALSE  */
    T_LEXERROR = 281,              /* T_LEXERROR  */
    T_ID = 282,                    /* T_ID  */
    T_ICONST = 283,                /* T_ICONST  */
    T_RCONST = 284,                /* T_RCONST  */
    T_CCONST = 285,                /* T_CCONST  */
    T_EOF = 286,                   /* T_EOF  */
    T_NONE = 287,                  /* T_NONE  */
    T_ROOT = 288,                  /* T_ROOT  */
    T_VAR_DECL_COLON_IS = 289,     /* T_VAR_DECL_COLON_IS  */
    T_VAR_DECL_COLON = 290,        /* T_VAR_DECL_COLON  */
    T_VAR_DECL_IS = 291,           /* T_VAR_DECL_IS  */
    T_TYPE_DECL_IS = 292,          /* T_TYPE_DECL_IS  */
    T_ROUTIN_DECL_TYPE = 293,      /* T_ROUTIN_DECL_TYPE  */
    T_ROUTIN_DECL = 294,           /* T_ROUTIN_DECL  */
    T_PARAMETERS = 295,            /* T_PARAMETERS  */
    T_BODY = 296,                  /* T_BODY  */
    T_ROUTINE_CALL = 297,          /* T_ROUTINE_CALL  */
    T_BRACKS = 298,                /* T_BRACKS  */
    T_IN_REVERSE = 299,            /* T_IN_REVERSE  */
    T_IF_ELSE = 300,               /* T_IF_ELSE  */
    T_PARENT = 301,                /* T_PARENT  */
    T_LESS = 302,                  /* T_LESS  */
    T_GREAT = 303,                 /* T_GREAT  */
    T_LESSOREQU = 304,             /* T_LESSOREQU  */
    T_GREATOREQU = 305,            /* T_GREATOREQU  */
    T_NOTEQU = 306,                /* T_NOTEQU  */
    T_EQU = 307,                   /* T_EQU  */
    T_COLONEQU = 308,              /* T_COLONEQU  */
    T_AND = 309,                   /* T_AND  */
    T_OR = 310,                    /* T_OR  */
    T_XOR = 311,                   /* T_XOR  */
    T_ADDOP = 312,                 /* T_ADDOP  */
    T_MULTOP = 313,                /* T_MULTOP  */
    T_SUBTROP = 314,               /* T_SUBTROP  */
    T_DIVOP = 315,                 /* T_DIVOP  */
    T_MODOP = 316,                 /* T_MODOP  */
    T_LPAREN = 317,                /* T_LPAREN  */
    T_RPAREN = 318,                /* T_RPAREN  */
    T_LBRACK = 319,                /* T_LBRACK  */
    T_RBRACK = 320,                /* T_RBRACK  */
    T_DOTDOT = 321,                /* T_DOTDOT  */
    T_DOT = 322,                   /* T_DOT  */
    T_COMMA = 323,                 /* T_COMMA  */
    T_COLON = 324                  /* T_COLON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ANALYSER_TAB_H_INCLUDED  */
