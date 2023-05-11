%{
    #include <iostream>
    #include <string>
    #include <vector>
    #include <typeinfo>
    #include "NodeDecl.h"

    typedef struct {
        Node* nodeLink;
        std::vector<Node*> nodeList;

        long long int integer;
        double real;
        std::string string;
        char character;
        int boolean;
    } YYSTYPE;
    
    #define YYSTYPE YYSTYPE
    #include "Analyser.tab.h"
    void yyerror(char *s);
    int line_no = 1;
    int errors = 0;

%}

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

Int_Lit       (-|"not ")?({Binary_Lit}|{Octal_Lit}|{Decimal_Lit}|{Hex_Lit})

/* Floating piont literals*/

Decimal_Exponent    (e|E)[-+]?{Decimal_Digits}

Hex_Mantisa     ((_)?{Hex_Digits}("."){Hex_Digits}?)|((_)?{Hex_Digits})|(("."){Hex_Digits}) 

Hex_Exponent    (p|P)[-+]?{Decimal_Digits}

Hex_Float_Lit   (0)(x|X){Hex_Mantisa}{Hex_Exponent}

Decimal_Float_Lit   ({Decimal_Digits}("."){Decimal_Digits}?{Decimal_Exponent}?)|({Decimal_Digits}{Decimal_Exponent})|(("."){Decimal_Digits}{Decimal_Exponent}?)

Float_Lit       (-)?(({Decimal_Float_Lit}|{Hex_Float_Lit}))

/*Char Literal*/

Char_Lit                (\")([A-Za-z0-9])(\")

L   [A-Za-z]
D   [0-9]

%%

"reverse"       {return( T_REVERSE );}
"return"        {return( T_RETURN );}
"print"         {return( T_PRINT );}
"while"         {return( T_WHILE );}
"loop"          {return( T_LOOP );}
"then"          {return( T_THEN );}
"else"          {return( T_ELSE );}
"type"          {return( T_TYPE );}
"for"           {return( T_FOR );}
"end"           {return( T_END );}
"var"           {return( T_VAR );}
"in"            {return( T_IN );}
"if"            {return( T_IF );}
"is"            {return( T_IS );}

"integer"           {return( T_INTEGER );}
"boolean"           {return( T_BOOLEAN );}
"routine"           {return( T_ROUTINE );}
"record"            {return( T_RECORD );}
"array"             {return( T_ARRAY );}
"real"              {return( T_REAL );}
"char"              {return( T_CHAR );}

"false"             {return( T_FALSE );}
"true"              {return( T_TRUE );}

"and"               {return( T_AND );}
"xor"               {return( T_XOR );}
"not"               {/*return( T_NOT );*/}
"or"                {return( T_OR );}

">="    {return( T_GREATOREQU );}
"<="    {return( T_LESSOREQU );}
":="    {return( T_COLONEQU );}
"/="    {return( T_NOTEQU );}
">"     {return( T_GREAT );}
"<"     {return( T_LESS );}
"="     {return( T_EQU );}


"%"     {return( T_MODOP );}
"-"     {return( T_SUBTROP );}
"*"     {return( T_MULTOP );}
"+"     {return( T_ADDOP );}
"/"     {return( T_DIVOP );}

\n      {line_no++;}
'\t'    {}


"("     {return( T_LPAREN );}
")"     {return( T_RPAREN );}
"["     {return( T_LBRACK );}
"]"     {return( T_RBRACK );}

".."    {return( T_DOTDOT );}
","     {return( T_COMMA );}
":"     {return( T_COLON );}
"."     {return( T_DOT );}

{Int_Lit}           {yylval.integer = atoi(yytext);return(T_ICONST );}
{Float_Lit}         {yylval.real = atof(yytext); return( T_RCONST );}

{Char_Lit}                        {yylval.string = std::string(yytext)[1]; return( T_CCONST );}
(_)?{L}({L}|{D}|_)*({L}|{D})|{L}* {yylval.string = std::string(yytext); return( T_ID);} 

<<EOF>>     {static int once = 0; return once++ ? 0 : T_EOF ;}

" "         {}
.           {printf("\nUnexpected character: '%s'\nIn the line::%i\n",yytext, line_no); exit(0);}

%%
int yywrap (void) {return 1;}