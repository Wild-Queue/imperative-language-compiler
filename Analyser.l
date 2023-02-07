%{
#include <stdio.h>
#include <stdlib.h>

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

/* Imaginary literals*/

Imaginary_Lit   ({Decimal_Digits}|{Int_Lit}|{Float_Lit})(i)

/*Rune literals*/

Escaped_Char    (\\)(a|b|f|n|r|t|v|(\\)|(')|(')|(\42))

Big_u_Value     (\\)(U){Hex_Digit}{Hex_Digit}{Hex_Digit}{Hex_Digit}{Hex_Digit}{Hex_Digit}{Hex_Digit}{Hex_Digit}

Littel_u_Value (\\)(u){Hex_Digit}{Hex_Digit}{Hex_Digit}{Hex_Digit}

Hex_Byte_Value  (\\)(x){Hex_Digit}{Hex_Digit}

Octal_Byte_Value (\\){Octal_Digit}{Octal_Digit}{Octal_Digit}

Byte_Value       ({Octal_Byte_Value}|{Hex_Byte_Value})

Unicode_Value   ({ASCII}|{Littel_u_Value}|{Big_u_Value}|{Escaped_Char})

Rune_Lit    (')({Unicode_Value}|{Byte_Value})(')

/*String Literal*/

Interpreted_String_Lit  (\")({Unicode_Value}|{Byte_Value})*(\")

Raw_String_Lit          (`)(({ASCIIFTPG}|(\n))*)(`)
/*"*/
String_Lit              ({Raw_String_Lit}|{Interpreted_String_Lit})

L   [A-Za-z]
D   [0-9]
Dp  [1-9]
Bi  [0-1]
OCTP [1-7]
OCT [0-7]
Hex [A-Fa-f]
W   [ \t] 
SPEC [NnFfTtVvBbRr]

%%

"else"          { printf( " T_ELSE" );}
"for"           { printf( " T_FOR" );}
"if"            { printf( " T_IF" );}
"type"          { printf( " T_TYPE" );}
"var"           { printf( " T_VAR" );}


"real"          { printf( " T_REAL" );}

"<"     { printf(" T_LESS");}
">"     { printf(" T_GREAT");}
"<="    { printf(" T_LESSOREQU");}
">="    { printf(" T_GREATOREQU");}
"/="    { printf(" T_NOTEQU");}
"=="    { printf(" T_EQU");}


"+"     { printf( " T_ADDOP" );}
"*"     { printf( " T_MULTOP" );}
"-"     { printf( " T_SUBTROP" );}
"/"     { printf( " T_DIVOP" );}
"%"     { printf( " T_MOD" );}

"\n"    {line_no++; /*printf("Line is right %d \n", line_no); return( T_NL);*/}
"\t"    ;


"("     { printf( " T_LPAREN" );}
")"     { printf( " T_RPAREN" );}
"["     { printf( " T_LBRACK" );}
"]"     { printf( " T_RBRACK" );}

".."    { printf( " T_DOTDOT" );}
"."     { printf( " T_DOT" );}
","     { printf( " T_COMMA" );}
":"     { printf( " T_COLON" );}
":="    { printf( " T_ASSIGN" );}
"="     { printf( " T_ASSIGNOP" );}


(_)?{L}({L}|{D}|_)*({L}|{D})|{L}* { /*yylval.string = strdup(yytext);*/ printf(" T_ID");} 

{Int_Lit}           {/*yylval.integer = atoi(yytext); */        printf(" T_ICONST");}
{Float_Lit}         {/*yylval.real = decRealHandler(yytext);*/  printf(" T_RCONST");}
{Imaginary_Lit}     {/*yylval.string = strdup(yytext);*/        printf(" T_IMCONST");}
{Rune_Lit}          {/*yylval.character=yytext[1];*/            printf(" T_CCONST");}
{String_Lit}        {/*yylval.string = yytext.substr(1, yytext.size() - 2);*/ printf(" T_SCONST");}

{W}         {}
.           {ECHO; printf ("unexpected character");}

%%
int yywrap (void) {return 1;}