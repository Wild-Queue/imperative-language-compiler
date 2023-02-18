%{
#include <stdio.h>
#include <stdlib.h>

#include "Analyser.tab.h"
//void yyerror (char *s);
//int yylex();

//used in error function
int line_no = 1;
int errors = 0;
%}

ASCII1 [ -[]

ASCII2 []-~]

ASCII3 [ -_]

ASCII4 [a-~]

ASCIIFTPG ({ASCII3}|{ASCII4})

ASCII ({ASCII1}|{ASCII2})

Binary_Digit    [0-1]

Octal_Digit     [0-7]

Decimal_Digit   [0-9]

Hex_Digit       [0-9A-Fa-f]

/* Integer literals*/

Binary_Digits    ({Binary_Digit}(_?{Binary_Digit})*)

Octal_Digits     ({Octal_Digit}(_?{Octal_Digit})*)

Decimal_Digits   ({Decimal_Digit}(_?{Decimal_Digit})*)

Hex_Digits       ({Hex_Digit}((_)?{Hex_Digit})*)

Binary_Lit       (0[bB](_)?{Binary_Digits})

Octal_Lit      ((0)(o|O)?(_)?{Octal_Digits})

Decimal_Lit      ((0)|(([1-9])((_)?{Decimal_Digits})?))

Hex_Lit      ((0)(x|X)(_)?{Hex_Digits})

Int_Lit       ({Binary_Lit}|{Octal_Lit}|{Decimal_Lit}|{Hex_Lit})

/* floating piont literals*/

Decimal_Exponent    (e|E)[-+]?{Decimal_Digits}

Hex_Mantisa     ((_)?{Hex_Digits}("."){Hex_Digits}?)|((_)?{Hex_Digits})|(("."){Hex_Digits}) 

Hex_Exponent    (p|P)[-+]?{Decimal_Digits}

Hex_Float_Lit   (0)(x|X){Hex_Mantisa}{Hex_Exponent}

Decimal_Float_Lit   ({Decimal_Digits}("."){Decimal_Digits}?{Decimal_Exponent}?)|({Decimal_Digits}{Decimal_Exponent})|(("."){Decimal_Digits}{Decimal_Exponent}?)

Float_Lit       ({Decimal_Float_Lit}|{Hex_Float_Lit})

/*Rune literals*/

Escaped_Char    (\\)(a|b|f|n|r|t|v|(\\)|(')|(')|(\42))

Big_u_Value     (\\)(U){Hex_Digit}{Hex_Digit}{Hex_Digit}{Hex_Digit}{Hex_Digit}{Hex_Digit}{Hex_Digit}{Hex_Digit}

Littel_u_Value (\\)(u){Hex_Digit}{Hex_Digit}{Hex_Digit}{Hex_Digit}

Hex_Byte_Value  (\\)(x){Hex_Digit}{Hex_Digit}

Octal_Byte_Value (\\){Octal_Digit}{Octal_Digit}{Octal_Digit}

Byte_Value       ({Octal_Byte_Value}|{Hex_Byte_Value})

Unicode_Value   ({ASCII}|{Littel_u_Value}|{Big_u_Value}|{Escaped_Char})

/*String Literal*/

Interpreted_String_Lit  (\")({Unicode_Value}|{Byte_Value})*(\")

Raw_String_Lit          (`)(({ASCIIFTPG}|(\n))*)(`)

String_Lit              ({Raw_String_Lit}|{Interpreted_String_Lit})

L   [A-Za-z]
D   [0-9]

%%

"ENDOFFILE"     {/*printf("T_EOF "); return( T_EOF );*/}

"reverse"       {printf("T_REVERSE "); return( T_REVERSE );}
"while"         {printf("T_WHILE "); return( T_WHILE );}
"loop"          {printf("T_LOOP "); return( T_LOOP );}
"then"          {printf("T_THEN "); return( T_THEN );}
"else"          {printf("T_ELSE "); return( T_ELSE );}
"type"          {printf("T_TYPE "); return( T_TYPE );}
"for"           {printf("T_FOR "); return( T_FOR );}
"end"           {printf("T_END "); return( T_END );}
"var"           {printf("T_VAR "); return( T_VAR );}
"in"            {printf("T_IN "); return( T_IN );}
"if"            {printf("T_IF "); return( T_IF );}
"is"            {printf("T_IS "); return( T_IS );}

"real"              {printf("T_REAL "); return( T_REAL );}
"integer"           {printf("T_INTEGER "); return( T_INTEGER );}
"boolean"           {printf("T_BOOLEAN "); return( T_BOOLEAN );}
"routine"           {printf("T_ROUTINE "); return( T_ROUTINE );}
"array"             {printf("T_ARRAY "); return( T_ARRAY );}
"record"            {printf("T_RECORD "); return( T_RECORD );}

"true"              {printf("T_TRUE "); return( T_TRUE );}
"false"             {printf("T_FALSE "); return( T_FALSE );}

"and"               {printf("T_AND "); return( T_AND );}
"xor"               {printf("T_XOR "); return( T_XOR );}
"or"                {printf("T_OR "); return( T_OR );}
"not"               {printf("T_NOT "); return( T_NOT );}

"<="    {printf("T_LESSOREQU "); return( T_LESSOREQU );}
">="    {printf("T_GREATOREQU "); return( T_GREATOREQU );}
"<"     {printf("T_LESS "); return( T_LESS );}
">"     {printf("T_GREAT "); return( T_GREAT );}
"/="    {printf("T_NOTEQU "); return( T_NOTEQU );}
":="    {printf("T_COLONEQU "); return( T_COLONEQU );}
"="     {printf("T_EQU "); return( T_EQU );}


"+"     {printf("T_ADDOP "); return( T_ADDOP );}
"*"     {printf("T_MULTOP "); return( T_MULTOP );}
"-"     {printf("T_SUBTROP "); return( T_SUBTROP );}
"/"     {printf("T_DIVOP "); return( T_DIVOP );}
"%"     {printf("T_MODOP "); return( T_MODOP );}

'\n'    {printf("T_NL "); line_no++; return( T_NL ); /*printf("Line is right %d \n", line_no); return( T_NL);*/}
'\t'    {printf("T_TAB "); return( T_TAB ); }


"("     {printf("T_LPAREN "); return( T_LPAREN );}
")"     {printf("T_RPAREN "); return( T_RPAREN );}
"["     {printf("T_LBRACK "); return( T_LBRACK );}
"]"     {printf("T_RBRACK "); return( T_RBRACK );}

".."    {printf("T_DOTDOT "); return( T_DOTDOT );}
"."     {printf("T_DOT "); return( T_DOT );}
","     {printf("T_COMMA "); return( T_COMMA );}
":"     {printf("T_COLON "); return( T_COLON );}


(_)?{L}({L}|{D}|_)*({L}|{D})|{L}* { /*yylval.string = strdup(yytext);*/printf("T_ID:%s ", yytext);    return( T_ID );} 

{Int_Lit}           {/*yylval.integer = atoi(yytext); */printf("T_ICONST:%s ", yytext);  return(T_ICONST );}
{Float_Lit}         {/*yylval.real = decRealHandler(yytext);*/printf("T_RCONST:%s ", yytext); return( T_RCONST );}
{String_Lit}        {/*yylval.string = yytext.substr(1, yytext.size() - 2);*/printf("T_SCONST:%s ", yytext);   return( T_SCONST );}

<<EOF>>     {/*printf("T_EOF ");*/ static int once = 0; return once++ ? 0 : T_EOF ;}

" "         {}
.           {ECHO; printf (" unexpected character ");}

%%
int yywrap (void) {return 1;}