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

/*В правилах есть какие-то [Sign | NOT] что за not*/
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

"reverse"       {printf("T_REVERSE "); return( T_REVERSE );}
"return"        {printf("T_RETURN "); return( T_RETURN );}
"print"         {printf("T_PRINT "); return( T_PRINT );}
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

"integer"           {printf("T_INTEGER "); return( T_INTEGER );}
"boolean"           {printf("T_BOOLEAN "); return( T_BOOLEAN );}
"routine"           {printf("T_ROUTINE "); return( T_ROUTINE );}
"record"            {printf("T_RECORD "); return( T_RECORD );}
"array"             {printf("T_ARRAY "); return( T_ARRAY );}
"real"              {printf("T_REAL "); return( T_REAL );}
"char"              {printf("T_CHAR "); return( T_CHAR );}

"false"             {printf("T_FALSE "); return( T_FALSE );}
"true"              {printf("T_TRUE "); return( T_TRUE );}

"and"               {printf("T_AND "); return( T_AND );}
"xor"               {printf("T_XOR "); return( T_XOR );}
"not"               {printf("T_NOT "); /*return( T_NOT );*/}
"or"                {printf("T_OR "); return( T_OR );}

">="    {printf("T_>= "); return( T_GREATOREQU );}
"<="    {printf("T_<= "); return( T_LESSOREQU );}
":="    {printf("T_:= "); return( T_COLONEQU );}
"/="    {printf("T_/= "); return( T_NOTEQU );}
">"     {printf("T_> "); return( T_GREAT );}
"<"     {printf("T_< "); return( T_LESS );}
"="     {printf("T_= "); return( T_EQU );}


"%"     {printf("T_MODOP "); return( T_MODOP );}
"-"     {printf("T_- "); return( T_SUBTROP );}
"*"     {printf("T_* "); return( T_MULTOP );}
"+"     {printf("T_+ "); return( T_ADDOP );}
"/"     {printf("T_/ "); return( T_DIVOP );}

'\n'    {printf("T_NL "); line_no++; /*return( T_NL );*/}
'\t'    {printf("T_TAB "); /*return( T_TAB ); */}


"("     {printf("T_( "); return( T_LPAREN );}
")"     {printf("T_) "); return( T_RPAREN );}
"["     {printf("T_[ "); return( T_LBRACK );}
"]"     {printf("T_] "); return( T_RBRACK );}

".."    {printf("T_.. "); return( T_DOTDOT );}
","     {printf("T_, "); return( T_COMMA );}
":"     {printf("T_: "); return( T_COLON );}
"."     {printf("T_. "); return( T_DOT );}

{Int_Lit}           {yylval.integer = atoi(yytext); printf("T_ICONST:%s ", yytext);  return(T_ICONST );}
{Float_Lit}         {yylval.real = atof(yytext); printf("T_RCONST:%s ", yytext); return( T_RCONST );}

{Char_Lit}                        {yylval.string = std::string(yytext)[1]; printf("T_CCONST:%s ", yytext);   return( T_CCONST );}
(_)?{L}({L}|{D}|_)*({L}|{D})|{L}* {yylval.string = std::string(yytext); printf("T_ID:%s ", yytext); return( T_ID);} 

<<EOF>>     {static int once = 0; return once++ ? 0 : T_EOF ;}

" "         {}
.           {ECHO; printf (" unexpected character\n");}

%%
int yywrap (void) {return 1;}