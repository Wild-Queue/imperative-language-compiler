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
%token <string> T_FOR T_WHILE T_LOOP T_IN T_REVERSE T_IF T_THEN T_ELSE T_END T_TYPE T_VAR T_IS T_PRINT
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
T_NOTEQU // /=
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
T_MODOP // %

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

// Zero or more
// Program : { SimpleDeclaration | RoutineDeclaration }
Program : T_EOF
        | SimpleDeclaration Program
        | RoutineDeclaration Program 
        ;

SimpleDeclaration : VariableDeclaration 
                  | TypeDeclaration
                  ;

//VariableDeclaration
// : var Identifier : Type [ is Expression ]
// | var Identifier is Expression
VariableDeclaration : T_VAR T_ID T_COLON Type T_IS Expression   
                  | T_VAR T_ID T_COLON Type     
                  | T_VAR T_ID T_IS Expression  
                  ;

TypeDeclaration : T_TYPE T_ID T_IS Type        
                ;

//RoutineDeclaration
// : routine Identifier ( Parameters ) [ : Type ] is Body end
RoutineDeclaration 
              : T_ROUTINE T_ID T_LPAREN Parameters T_RPAREN T_COLON Type T_IS Body T_END        
              | T_ROUTINE T_ID T_LPAREN Parameters T_RPAREN T_IS Body T_END     
              ;

Parameters : ParameterDeclaration ParameterDeclarations 
                ;

// Zero or more
ParameterDeclarations : /*empty*/
                    | T_COMMA ParameterDeclaration ParameterDeclarations
                    ;

ParameterDeclaration : T_ID T_COLON Type      
                        ;

Type : PrimitiveType 
      | ArrayType 
      | RecordType 
      | T_ID    
      ;

PrimitiveType: T_INTEGER 
              | T_REAL
              | T_BOOLEAN 
              ;

RecordType : T_RECORD VariableDeclarations T_END ;

// Zero or more
VariableDeclarations : /*empty*/
                    | VariableDeclaration VariableDeclarations 
                    ;

ArrayType : T_ARRAY T_LBRACK Expression T_RBRACK Type ;

// Zero or more
// Body : { SimpleDeclaration | Statement }
Body : /*empty*/
      | SimpleDeclaration Body  
      | Statement Body 
      ;

Statement : Assignment 
          | RoutineCall
          | WhileLoop 
          | ForLoop 
          | IfStatement
          | T_PRINT T_LPAREN Expression T_RPAREN
          ;

Assignment : ModifiablePrimary T_COLONEQU Expression 
                ;

// RoutineCall : Identifier [ '('' Expression { , Expression } ')' ]
RoutineCall : T_ID                                              
            | T_ID T_LPAREN Expression Expressions T_RPAREN     
            ;

// Zero or more
Expressions : /*empty*/
            | T_COMMA Expression Expressions 
            ;

WhileLoop : T_WHILE Expression T_LOOP Body T_END 
                ;

ForLoop : T_FOR T_ID Range T_LOOP Body T_END    
        ;

Range : T_IN Expression T_DOTDOT Expression
      | T_IN T_REVERSE Expression T_DOTDOT Expression
      ;

IfStatement : T_IF Expression T_THEN Body T_ELSE Body  T_END 
            | T_IF Expression T_THEN Body T_END
            ;

Expression : Relation Relations
            ;

// Zero or more
Relations : /*empty*/
          | Relations T_AND Relation
          | Relations T_OR  Relation
          | Relations T_XOR Relation
          ;

Relation : Simple
          | Simple T_LESS Simple
          | Simple T_LESSOREQU Simple
          | Simple T_GREAT Simple 
          | Simple T_GREATOREQU Simple
          | Simple T_EQU Simple
          | Simple T_NOTEQU Simple
          ;

// Simple : Factor { ( * | / | % ) Factor }
Simple : Factor Factors 
        ;

Factors : /*empty*/
        | Factors T_MULTOP Factor
        | Factors T_DIVOP Factor
        | Factors T_MODOP Factor
        ;

//Factor : Summand { ( + | - ) Summand }
Factor : Summand Summands


Summands : /*empty*/
          | Summands T_ADDOP Summand
          | Summands T_SUBTROP Summand
          ;

Summand : Primary 
        | T_LPAREN Expression T_LPAREN
        ;

Primary : T_ICONST
        | T_RCONST
        | T_TRUE | T_FALSE
        | ModifiablePrimary
        ;

//ModifiablePrimary : Identifier { . Identifier | [ Expression ] }
ModifiablePrimary : T_ID Identifiers 
                ;

// Zero of more
Identifiers : /*empty*/
            | T_DOT T_ID  Identifiers
            | T_LBRACK Expression T_RBRACK Identifiers
            ;

%%

int yyerror(char *s){
  printf("Syntax Error on Line %s\n", s);
  return 0;
}

int main (void) {
  yyparse();
  return 0;
}
