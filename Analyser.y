/* BLOCK A: Statements block*/
%{
    #include <iostream>
    #include <string>
    #include <vector>
    #include <typeinfo>

    #include "NodeDecl.h"
    extern FILE *yyin;
    extern int yylineno;
    int yylex();
    using namespace std;
    void yyerror(std::string s) {
        cout << "Syntax Error in the line " << line_no << endl;
        //cerr << s << ", line " << yylineno << endl;
        exit(0);
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

    Node* root = new Node(Token(T_ROOT, "root"));

%}


//keywords
%token <string> T_FOR T_WHILE T_LOOP T_IN T_REVERSE T_IF T_THEN T_ELSE T_END T_TYPE T_VAR T_IS T_PRINT T_RETURN
%token <string> T_INTEGER T_REAL T_BOOLEAN T_CHAR T_ROUTINE T_ARRAY T_RECORD T_TRUE T_FALSE
%token <string> T_LEXERROR

//identifier
%token<string> T_ID

//integer consts
%token <integer> T_ICONST

//string consts
//%token <string> T_SCONST

//real consts
%token <real> T_RCONST

//logical
//%token <boolean> T_BCONST

//chars
%token <string> T_CCONST


// End of file
%token <string> T_EOF

//
%token <string> T_NONE T_ROOT T_VAR_DECL_COLON_IS T_VAR_DECL_COLON T_VAR_DECL_IS
                        T_TYPE_DECL_IS T_ROUTIN_DECL_TYPE T_ROUTIN_DECL T_PARAMETERS T_BODY 
                                T_ROUTINE_CALL T_BRACKS T_IN_REVERSE T_IF_ELSE


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
//T_NOT // not

T_ADDOP // +
T_MULTOP // *
T_SUBTROP // -
T_DIVOP // /
T_MODOP // %

//T_TAB
//T_NL // NEW LINE


T_LPAREN // (
T_RPAREN // )
T_LBRACK // [
T_RBRACK // ]

T_DOTDOT // ..
T_DOT //.
T_COMMA // ,
T_COLON // :

%start Program;

%type<nodeLink> Program;
%type<nodeList> Programs;
%type<nodeLink> SimpleDeclaration;
%type<nodeLink> VariableDeclaration;
%type<nodeLink> TypeDeclaration;
%type<nodeLink> RoutineDeclaration;
%type<nodeLink> Parameters;
%type<nodeList> ParameterDeclarations;
%type<nodeLink> ParameterDeclaration;
%type<nodeLink> Type;
%type<nodeLink> PrimitiveType;
%type<nodeLink> RecordType;
%type<nodeList> VariableDeclarations;
%type<nodeLink> ArrayType;
%type<nodeLink> Body;
%type<nodeList> Bodies;
%type<nodeLink> Statement;
%type<nodeLink> Assignment;
%type<nodeLink> RoutineCall;
%type<nodeList> Expressions;
%type<nodeLink> WhileLoop;
%type<nodeLink> ForLoop;
%type<nodeLink> Range;
%type<nodeLink> IfStatement;
%type<nodeLink> Expression;
%type<nodeLink> Relation;
%type<nodeLink> Simple;
%type<nodeLink> Factor;
%type<nodeLink> Summand;
%type<nodeLink> Primary;
%type<nodeLink> ModifiablePrimary;
//%type<nodeLink> Identifiers;
%type<nodeLink> Identifiers_ARRAY
%type<nodeLink> ID_ARRAY;

%%

// Zero or more
// Program : { SimpleDeclaration | RoutineDeclaration }
Program : SimpleDeclaration Programs    {root = combineNodes($1, $2, T_ROOT, "ROOT");}
        | RoutineDeclaration Programs   {root = combineNodes($1, $2, T_ROOT, "ROOT");}
        ;

Programs : T_EOF                         {$$ = vector<Node*>();}
        | SimpleDeclaration Programs    {$$ = collectNodes($1, $2);}
        | RoutineDeclaration Programs   {$$ = collectNodes($1, $2);}
        ;

SimpleDeclaration : VariableDeclaration {$$ = $1;}
                  | TypeDeclaration     {$$ = $1;}
                  ;

//VariableDeclaration
// : var Identifier : Type [ is Expression ]
// | var Identifier is Expression
VariableDeclaration : T_VAR T_ID T_COLON Type T_IS Expression   {$$ = createNode(new Node(Token(T_ID, $2)), $4, $6, T_VAR_DECL_COLON_IS, "colon is");}
                  | T_VAR T_ID T_COLON Type                     {$$ = createNode(new Node(Token(T_ID, $2)), $4, T_VAR_DECL_COLON, "colon");}
                  | T_VAR T_ID T_IS Expression                  {$$ = createNode(new Node(Token(T_ID, $2)), $4, T_VAR_DECL_IS, "is");}
                  ;

TypeDeclaration : T_TYPE T_ID T_IS Type                         {$$ = createNode(new Node(Token(T_ID, $2)), $4, T_TYPE_DECL_IS, "is");}
                ;

//RoutineDeclaration
// : routine Identifier ( Parameters ) [ : Type ] is Body end
RoutineDeclaration 
              : T_ROUTINE T_ID T_LPAREN Parameters T_RPAREN T_COLON Type T_IS Body T_END        {$$ = createNode(new Node(Token(T_ID, $2)), $4, $7,$9, T_ROUTIN_DECL_TYPE, "routine");}   
              | T_ROUTINE T_ID T_LPAREN Parameters T_RPAREN T_IS Body T_END                     {$$ = createNode(new Node(Token(T_ID, $2)), $4, $7, T_ROUTIN_DECL, "routine");}
              ;

Parameters : ParameterDeclaration ParameterDeclarations                                         {$$ = combineNodes($1, $2, T_PARAMETERS, "()");}
                ;

// Zero or more
ParameterDeclarations : /*empty*/                                                               {$$ = vector<Node*>();}
                    | T_COMMA ParameterDeclaration ParameterDeclarations                        {$$ = collectNodes($2, $3);}
                    ;

ParameterDeclaration : T_ID T_COLON Type    {$$ = createNode(new Node(Token(T_ID, $1)), $3, T_COLON, ":");}
                        ;

Type : PrimitiveType                        {$$ = $1;}
      | ArrayType                           {$$ = $1;}
      | RecordType                          {$$ = $1;}
      | T_ID                                {$$ = createNode(T_ID, $1);}
      ;

PrimitiveType: T_INTEGER                    {$$ = createNode(T_INTEGER, "integer");}
              | T_REAL                      {$$ = createNode(T_REAL, "real");}
              | T_BOOLEAN                   {$$ = createNode(T_BOOLEAN, "boolean");}
              | T_CHAR                      {$$ = createNode(T_CHAR, "char");}
              ;

RecordType : T_RECORD VariableDeclarations T_END {$$ = combineNodes($2, T_RECORD, "record");}
            ;

// Zero or more
VariableDeclarations : /*empty*/                                {$$ = vector<Node*>();}
                    | VariableDeclaration VariableDeclarations  {$$ = collectNodes($1, $2);}
                    ;

ArrayType : T_ARRAY T_LBRACK Expression T_RBRACK Type   {$$ = createNode($3, $5, T_ARRAY, "array");}
            ;

// Zero or more
// Body : { SimpleDeclaration | Statement }
Body : /*empty*/                    {$$ = createNode(T_BODY, "BODY");}
      | SimpleDeclaration Bodies    {$$ = combineNodes($1, $2, T_BODY, "BODY");}
      | Statement Bodies            {$$ = combineNodes($1, $2, T_BODY, "BODY");}
      ;

Bodies : /*empty*/                  {$$ = vector<Node*>();}
      | SimpleDeclaration Bodies    {$$ = collectNodes($1, $2);}
      | Statement Bodies            {$$ = collectNodes($1, $2);}
      ;

Statement : Assignment                              {$$ = $1;}
          | RoutineCall                             {$$ = $1;}
          | WhileLoop                               {$$ = $1;}
          | ForLoop                                 {$$ = $1;}
          | IfStatement                             {$$ = $1;}
          | T_RETURN T_LPAREN Expression T_RPAREN   {$$ = createNode($3, T_RETURN, "return");}
          | T_PRINT T_LPAREN Expression T_RPAREN    {$$ = createNode($3, T_PRINT, "print");}
          ;

Assignment : ModifiablePrimary T_COLONEQU Expression {$$ = createNode($1, $3, T_COLONEQU, ":=");}
                ;

// RoutineCall : Identifier [ '('' Expression { , Expression } ')' ]
RoutineCall : T_ID                                  {$$ = createNode(T_ID, $1);}
            | T_ID T_LPAREN Expressions T_RPAREN    {$$ = combineNodes(new Node(Token(T_ID, $1)), $3, T_ROUTINE_CALL, "ROUTINECALL");}
            ;

// Zero or more
Expressions : Expression                            {$$ = collectNodes($1);}
            | Expression T_COMMA Expressions        {$$ = collectNodes($1, $3);}
            ;

WhileLoop : T_WHILE Expression T_LOOP Body T_END    {$$ = createNode($2, $4, T_WHILE, "while");}
                ;

ForLoop : T_FOR T_ID Range T_LOOP Body T_END        {$$ = createNode(new Node(Token(T_ID, $2)), $3, $5, T_FOR, "for");}
        ;

Range : T_IN Expression T_DOTDOT Expression             {$$ = createNode($2, $4, T_IN, "in");}
      | T_IN T_REVERSE Expression T_DOTDOT Expression   {$$ = createNode($3, $5, T_IN_REVERSE, "in_reverse");}
      ;

IfStatement : T_IF Expression T_THEN Body T_ELSE Body  T_END    {$$ = createNode($2, $4, $6, T_IF_ELSE, "if else");}
            | T_IF Expression T_THEN Body T_END                 {$$ = createNode($2, $4, T_IF, "if");}
            ;

// Возможно, прикреплять детей к родительскому ноду
Expression : Relation                       {$$ = $1;}
            | Relation T_AND Expression     {$$ = createNode($1, $3, T_AND, "and");}
            | Relation T_OR  Expression     {$$ = createNode($1, $3, T_OR, "or");}
            | Relation T_XOR Expression     {$$ = createNode($1, $3, T_XOR, "xor");}
            ;

// Relation Relations         {$$ = createNode($1, $2, "Expression", "Expression");}
// Zero or more
//Relations : /*empty*/                   {}
//          | Relations T_AND Relation    {}
//          | Relations T_OR  Relation    {}
//          | Relations T_XOR Relation    {}
//          ;


Relation : Simple                           {$$ = $1;}
          | Simple T_LESS Simple            {$$ = createNode($1, $3, T_LESS, "<");}
          | Simple T_LESSOREQU Simple       {$$ = createNode($1, $3, T_LESSOREQU, "<=");}
          | Simple T_GREAT Simple           {$$ = createNode($1, $3, T_GREAT, ">");}
          | Simple T_GREATOREQU Simple      {$$ = createNode($1, $3, T_GREATOREQU, ">=");}
          | Simple T_EQU Simple             {$$ = createNode($1, $3, T_EQU, "=");}
          | Simple T_NOTEQU Simple          {$$ = createNode($1, $3, T_NOTEQU, "/=");}
          ;

// Simple : Factor { ( * | / | % ) Factor }
Simple : Factor                     {$$ = $1;}
        | Factor T_MULTOP Simple   {$$ = createNode($1, $3, T_MULTOP, "*");}
        | Factor T_DIVOP Simple    {$$ = createNode($1, $3, T_DIVOP, "/");}
        | Factor T_MODOP Simple    {$$ = createNode($1, $3, T_MODOP, "%");}
        ;


//Factor : Summand { ( + | - ) Summand }
Factor : Summand                        {$$ = $1;}
        | Summand T_ADDOP Factor      {$$ = createNode($1, $3, T_ADDOP, "+");}
        | Summand T_SUBTROP Factor    {$$ = createNode($1, $3, T_SUBTROP, "-");}
        ;

Summand : Primary                       {$$ = $1;}
        | T_LPAREN Expression T_LPAREN  {$$ = $2;}
        ;

Primary : T_ICONST                      {$$ = createNode(T_ICONST, to_string($1));}
        | T_CCONST                      {$$ = createNode(T_CCONST, $1);}
        | T_RCONST                      {$$ = createNode(T_RCONST, to_string($1));}
        | T_TRUE                        {$$ = createNode(T_TRUE, "true");}
        | T_FALSE                       {$$ = createNode(T_FALSE, "false");}
        | ModifiablePrimary             {$$ = $1;}
        ;

//ModifiablePrimary : Identifier { . Identifier | [ Expression ] }
//ModifiablePrimary : T_ID            {$$ = createNode("T_ID", $1);}
//                | T_ID Identifiers  {$$ = createNode(new Node(Token("T_ID", $1)), $2,"ModifiablePrim", "MODIFIABLEPRIM");}
//                ;

// Zero of more
//Identifiers : T_DOT T_ID                                {$$ = createNode(new Node(Token("T_ID", $2)),"T_DOT", ".");}
//            | T_DOT T_ID Identifiers                    {$$ = createNode(new Node(Token("T_ID", $2)), $3,"T_DOT", ".");}
//            | T_LBRACK Expression T_RBRACK              {$$ = createNode($2,"BRACKS", "[]");}
//            | T_LBRACK Expression T_RBRACK Identifiers  {$$ = createNode($2, $4,"BRACKS", "[]");}
//            ;

ModifiablePrimary : ID_ARRAY                                        {$$ = $1;}
                | ID_ARRAY T_DOT ModifiablePrimary                  {$$ = createNode($1, $3,T_DOT, ".");}
                ;

ID_ARRAY  : T_ID                                                {$$ = createNode(T_ID, $1);}
          | T_ID T_LBRACK Expression T_RBRACK                   {$$ = createNode(new Node(Token(T_ID, $1)), $3, T_BRACKS, "[]");}
          | T_ID T_LBRACK Expression T_RBRACK Identifiers_ARRAY {$$ = createNode(new Node(Token(T_ID, $1)), $3, $5, T_BRACKS, "[]");}
          ;

Identifiers_ARRAY : T_LBRACK Expression T_RBRACK                    {$$ = createNode($2, T_BRACKS, "[]");}
                  | T_LBRACK Expression T_RBRACK Identifiers_ARRAY  {$$ = createNode($2, $4, T_BRACKS, "[]");}
                  ;

%%

Node* generateAST (string inputfile) {
    yyin = fopen(inputfile.c_str(), "r");
    yyparse();
    fclose(yyin);

    return root;
}