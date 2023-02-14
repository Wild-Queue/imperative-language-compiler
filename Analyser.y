/* BLOCK A: Statements block*/
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int yyerror (char *s);
int yylex();
%}

%union {
  unsigned int integer;
  double real;
  char *string;
  char character;
  int boolean;
}

//keywords
%token <string> T_FOR T_WHILE T_LOOP T_IN T_REVERSE T_IF T_THEN T_ELSE T_END T_TYPE T_VAR T_IS 
%token <string> T_INTEGER T_REAL T_BOOLEAN T_ROUTINE T_ARRAY T_RECORD T_TRUE T_FALSE

//identifier
%token<string> T_ID

//integer consts
%token <integer> T_ICONST

//string consts
%token <string> T_SCONST

//real consts
%token <real> T_RCONST

//logical
%token <boolean> T_BCONST

//chars
%token <character> T_CCONST


// End of file
%token <string> T_EOF


//operators
%token <string> 
T_LESS // <
T_GREAT // >
T_LESSOREQU // <=
T_GREATOREQU // >= 
T_NOTEQU // !=
T_EQU // =
T_COLONEQU // :=

T_AND // and
T_OR // or
T_XOR // xor
T_NOT // not

T_ADDOP // +
T_MULTOP // *
T_SUBTROP // -
T_DIVOP // /
T_MOD // %

T_TAB
T_NL // NEW LINE

T_POINTER //*
T_REFERENCE //&

T_LPAREN // (
T_RPAREN // )
T_LBRACK // [
T_RBRACK // ]

T_DOTDOT // ..
T_DOT //.
T_COMMA // ,
T_COLON // :

%start Program;

%%

Program : T_VAR T_EOF;

%%

int yyerror(char *s){
  printf("Syntax Error on Line %s\n", s);
  return 0;
}

int main (void) {
  yyparse();
  return 0;
}
