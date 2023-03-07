/* BLOCK A: Statements block*/
%{
    #include <iostream>
    #include <string.h>
    #include <vector>
    #include <typeinfo>
    extern FILE *yyin;
    extern int yylineno;
    int yylex();
    using namespace std;
    void yyerror(std::string s) {
        cout << "Syntax Error on Line " << s << endl;
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


%}


//keywords
%token <string> T_FOR T_WHILE T_LOOP T_IN T_REVERSE T_IF T_THEN T_ELSE T_END T_TYPE T_VAR T_IS T_PRINT T_RETURN
%token <string> T_INTEGER T_REAL T_BOOLEAN T_CHAR T_ROUTINE T_ARRAY T_RECORD T_TRUE T_FALSE

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
%token <string> T_CCONST


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
%type<nodeLink> Identifiers;

%%

// Zero or more
// Program : { SimpleDeclaration | RoutineDeclaration }
Program : SimpleDeclaration Programs    {root = combineNodes($1, $2, "root", "ROOT");}
        | RoutineDeclaration Programs   {root = combineNodes($1, $2, "root", "ROOT");}
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
VariableDeclaration : T_VAR T_ID T_COLON Type T_IS Expression   {$$ = createNode(new Node(Token("T_ID", $2)), $4, $6, "var_decl_colon_is", "colon is");}
                  | T_VAR T_ID T_COLON Type                     {$$ = createNode(new Node(Token("T_ID", $2)), $4, "var_decl_colon", "colon");}
                  | T_VAR T_ID T_IS Expression                  {$$ = createNode(new Node(Token("T_ID", $2)), $4, "var_decl_is", "is");}
                  ;

TypeDeclaration : T_TYPE T_ID T_IS Type                         {$$ = createNode(new Node(Token("T_ID", $2)), $4, "type_decl_is", "is");}
                ;

//RoutineDeclaration
// : routine Identifier ( Parameters ) [ : Type ] is Body end
RoutineDeclaration 
              : T_ROUTINE T_ID T_LPAREN Parameters T_RPAREN T_COLON Type T_IS Body T_END        {$$ = createNode(new Node(Token("T_ID", $2)), $4, $7,$9, "routin_decl_type", "routine");}   
              | T_ROUTINE T_ID T_LPAREN Parameters T_RPAREN T_IS Body T_END                     {$$ = createNode(new Node(Token("T_ID", $2)), $4, $7, "routin_decl", "routine");}
              ;

Parameters : ParameterDeclaration ParameterDeclarations                                         {$$ = combineNodes($1, $2, "parameters", "PARAMETERS");}
                ;

// Zero or more
ParameterDeclarations : /*empty*/                                                               {$$ = vector<Node*>();}
                    | T_COMMA ParameterDeclaration ParameterDeclarations                        {$$ = collectNodes($2, $3);}
                    ;

ParameterDeclaration : T_ID T_COLON Type    {$$ = createNode(new Node(Token("T_ID", $1)), $3, "T_COLON", ":");}
                        ;

Type : PrimitiveType                        {$$ = $1;}
      | ArrayType                           {$$ = $1;}
      | RecordType                          {$$ = $1;}
      | T_ID                                {$$ = createNode("T_ID", $1);}
      ;

PrimitiveType: T_INTEGER                    {$$ = createNode("T_INTEGER", "integer");}
              | T_REAL                      {$$ = createNode("T_REAL", "real");}
              | T_BOOLEAN                   {$$ = createNode("T_BOOLEAN", "boolean");}
              | T_CHAR                      {$$ = createNode("T_CHAR", "char");}
              ;

RecordType : T_RECORD VariableDeclarations T_END {$$ = combineNodes($2, "T_RECORD", "record");}
            ;

// Zero or more
VariableDeclarations : /*empty*/                                {$$ = vector<Node*>();}
                    | VariableDeclaration VariableDeclarations  {$$ = collectNodes($1, $2);}
                    ;

ArrayType : T_ARRAY T_LBRACK Expression T_RBRACK Type   {$$ = createNode($3, $5, "T_ARRAY", "array");}
            ;

// Zero or more
// Body : { SimpleDeclaration | Statement }
Body : /*empty*/                    {$$ = createNode("BODY", "BODY");}
      | SimpleDeclaration Bodies    {$$ = combineNodes($1, $2, "BODY", "BODY");}
      | Statement Bodies            {$$ = combineNodes($1, $2, "BODY", "BODY");}
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
          | T_RETURN T_LPAREN Expression T_RPAREN   {$$ = createNode($3, "T_RETURN", "return");}
          | T_PRINT T_LPAREN Expression T_RPAREN    {$$ = createNode($3, "T_PRINT", "print");}
          ;

Assignment : ModifiablePrimary T_COLONEQU Expression {$$ = createNode($1, $3, "T_COLONEQU", ":=");}
                ;

// RoutineCall : Identifier [ '('' Expression { , Expression } ')' ]
RoutineCall : T_ID                                  {$$ = createNode("T_ID", $1);}
            | T_ID T_LPAREN Expressions T_RPAREN    {$$ = combineNodes(new Node(Token("T_ID", $1)), $3, "RoutineCall", "ROUTINECALL");}
            ;

// Zero or more
Expressions : Expression                            {$$ = collectNodes($1);}
            | T_COMMA Expression Expressions        {$$ = collectNodes($2, $3);}
            ;

WhileLoop : T_WHILE Expression T_LOOP Body T_END    {$$ = createNode($2, $4, "T_WHILE", "while");}
                ;

ForLoop : T_FOR T_ID Range T_LOOP Body T_END        {$$ = createNode(new Node(Token("T_ID", $2)), $3, $5, "T_FOR", "for");}
        ;

Range : T_IN Expression T_DOTDOT Expression             {$$ = createNode($2, $4, "T_IN", "in");}
      | T_IN T_REVERSE Expression T_DOTDOT Expression   {$$ = createNode($3, $5, "T_IN_REVERSE", "in_reverse");}
      ;

IfStatement : T_IF Expression T_THEN Body T_ELSE Body  T_END    {$$ = createNode($2, $4, $6, "T_IF_ELSE", "if else");}
            | T_IF Expression T_THEN Body T_END                 {$$ = createNode($2, $4, "T_IF", "if");}
            ;

// Возможно, прикреплять детей к родительскому ноду
Expression : Relation                       {$$ = $1;}
            | Relation T_AND Expression     {$$ = createNode($1, $3, "T_AND", "and");}
            | Relation T_OR  Expression     {$$ = createNode($1, $3, "T_OR", "or");}
            | Relation T_XOR Expression     {$$ = createNode($1, $3, "T_XOR", "xor");}
            ;

// Relation Relations         {$$ = createNode($1, $2, "Expression", "Expression");}
// Zero or more
//Relations : /*empty*/                   {}
//          | Relations T_AND Relation    {}
//          | Relations T_OR  Relation    {}
//          | Relations T_XOR Relation    {}
//          ;


Relation : Simple                           {$$ = $1;}
          | Simple T_LESS Simple            {$$ = createNode($1, $3, "T_LESS", "<");}
          | Simple T_LESSOREQU Simple       {$$ = createNode($1, $3, "T_LESSOREQU", "<=");}
          | Simple T_GREAT Simple           {$$ = createNode($1, $3, "T_GREAT", ">");}
          | Simple T_GREATOREQU Simple      {$$ = createNode($1, $3, "T_GREATOREQU", ">=");}
          | Simple T_EQU Simple             {$$ = createNode($1, $3, "T_EQU", "=");}
          | Simple T_NOTEQU Simple          {$$ = createNode($1, $3, "T_NOTEQU", "/=");}
          ;

// Simple : Factor { ( * | / | % ) Factor }
Simple : Factor                     {$$ = $1;}
        | Factor T_MULTOP Simple   {$$ = createNode($1, $3, "T_MULTOP", "*");}
        | Factor T_DIVOP Simple    {$$ = createNode($1, $3, "T_DIVOP", "/");}
        | Factor T_MODOP Simple    {$$ = createNode($1, $3, "T_MODOP", "%");}
        ;


//Factor : Summand { ( + | - ) Summand }
Factor : Summand                        {$$ = $1;}
        | Summand T_ADDOP Factor      {$$ = createNode($1, $3, "T_ADDOP", "+");}
        | Summand T_SUBTROP Factor    {$$ = createNode($1, $3, "T_SUBTROP", "-");}
        ;

Summand : Primary                       {$$ = $1;}
        | T_LPAREN Expression T_LPAREN  {$$ = $2;}
        ;

Primary : T_ICONST                      {$$ = createNode("T_ICONST", to_string($1));}
        | T_CCONST                      {$$ = createNode("T_CCONST", $1);}
        | T_RCONST                      {$$ = createNode("T_RCONST", to_string($1));}
        | T_TRUE                        {$$ = createNode("T_TRUE", "true");}
        | T_FALSE                       {$$ = createNode("T_FALSE", "false");}
        | ModifiablePrimary             {$$ = $1;}
        ;

//ModifiablePrimary : Identifier { . Identifier | [ Expression ] }
ModifiablePrimary : T_ID            {$$ = createNode("T_ID", $1);}
                | T_ID Identifiers  {$$ = createNode(new Node(Token("T_ID", $1)), $2,"ModifiablePrim", "MODIFIABLEPRIM");}
                ;

// Zero of more
Identifiers : T_DOT T_ID                                {$$ = createNode(new Node(Token("T_ID", $2)),"T_DOT", ".");}
            | T_DOT T_ID Identifiers                    {$$ = createNode(new Node(Token("T_ID", $2)), $3,"T_DOT", ".");}
            | T_LBRACK Expression T_RBRACK              {$$ = createNode($2,"BRACKS", "[]");}
            | T_LBRACK Expression T_RBRACK Identifiers  {$$ = createNode($2, $4,"BRACKS", "[]");}
            ;

//ModifiablePrimary : T_ID                                              {$$ = createNode("T_ID", $1);}
//                | T_ID T_DOT ModifiablePrimary                          {$$ = createNode(new Node(Token("T_ID", $1)), $2,"ModifiablePrim", "MODIFIABLEPRIM");}
//                | T_ID T_LBRACK Expression T_RBRACK Identifiers_ARRAY {$$ = createNode(new Node(Token("T_ID", $1)), $2,"ModifiablePrim", "MODIFIABLEPRIM");}
//                ;
//
//Identifiers_ARRAY : T_DOT ModifiablePrimary
//                  | T_LBRACK Expression T_RBRACK Identifiers_ARRAY
//

%%

Node* generateAST (string inputfile) {
    yyin = fopen(inputfile.c_str(), "r");
    yyparse();
    fclose(yyin);

    return root;
}