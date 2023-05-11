
#include <iostream>
#include <fstream>
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

#ifndef NTOKKEN
# define NTOKKEN
enum NONTERMINAL{
    NT_Program = 0,
    NT_VarDecl = 1,
    NT_TypeDecl = 2, 
    NT_RoutineDecl = 3,  
    NT_ParametersDecl = 4, 
    NT_ParameterDecl = 5, 
    NT_Identificator = 6, 
    NT_ConstInt = 7, 
    NT_ConstReal = 8, 
    NT_ConstTrue = 9, 
    NT_ConstFalse = 10,
    NT_ConstChar = 11,
    NT_Record = 12,
    NT_ArrayType = 13,
    NT_Statement = 14,
    NT_Return = 15,
    NT_Assignment = 16,
    NT_Expression = 17,
    NT_ForLoop = 18,
    NT_Factor = 19,
    NT_Integer = 20,
    NT_Real = 21,
    NT_IdArray = 22,
    NT_Body = 23,
    NT_Print = 24,
    NT_RoutineCall = 25, 
    NT_WhileLoop = 26,
    NT_Range = 27,
    NT_Relation = 28,
    NT_Simple = 29,
    NT_Boolean = 30,
    NT_Char = 31,
    NT_IdentifiersArray = 32
};

#endif
#ifndef REALCODEGENERATOR_PATTERN
#define REALCODEGENERATOR_PATTERN

#include "../NodeDecl.h"
#include <string>
#include <unordered_map>
#include "../TypeClass.h"


using namespace std;
class REALCodeGenerator {
    std::string returnString = "";
    int structNum = 0;
  public:
//   

// .method static public void main() il managed
// {
//     .entrypoint
//     .maxstack 8

    string header = ".assembly GoodProgram {}\n";
    string main_body = ".method static public void main() il managed {\n.entrypoint\n.maxstack 8\n\n";
    unordered_map<string, string> var_to_num;
    unordered_map<string, string> state;
    string main_end = "ret\n}";
    int new_var_num = 0;
    // string struct_decls = "";
    // string program_decls = "";

    // void addHeader(std::string header){
    //   this->header += header;
    // };
    // void addStructDecls(std::string struct_decls){
    //   this->struct_decls += struct_decls;
    // };
    // void addProgramDecls(std::string program_decls){
    //   this->program_decls += program_decls;
    // };
    void setReturnString(std::string returnString){
      this->returnString = returnString;
      // cout << returnString << endl;
    };
    std::string getReturnString(){
      string copy = this->returnString;
      this->returnString = "";
      return copy;
    };

    void printAll(){
      cout << this->header << endl;
      cout << this->main_body << endl;
      cout << this->main_end << endl;
      // cout << this->program_decls << endl;
      // cout << this->struct_decls << endl;
    };

    void safeCSFile(){
      ofstream myfile;
      myfile.open ("Result/Program.il");
      
      myfile << this->header << endl;
      myfile << this->main_body << endl;
      myfile << this->main_end << endl;
      // myfile << this->program_decls << endl;
      // myfile << this->struct_decls << endl;

      myfile.close();
    }

    bool DEBUG = 0;
    bool visitProgram(Node* node);
    bool visitSimpleDeclaration(Node* node);
    bool visitVariableDeclaration(Node* node);
    bool visitTypeDeclaration(Node* node);
    bool visitT_PARENT(Node *node);
    bool visitRoutineDeclaration(Node* node);
    bool visitT_VAR_DECL_COLON_IS(Node* node);
    bool visitT_VAR_DECL_COLON(Node* node);
    bool visitT_VAR_DECL_IS(Node* node);
    bool visitT_TYPE_DECL_IS(Node* node);
    bool visitT_ROUTIN_DECL_TYPE(Node* node);
    bool visitT_ROUTIN_DECL(Node* node);
    bool visitParameters(Node* node);
    bool visitParameterDeclaration(Node* node);
    bool visitParameterDeclarations(Node* node);
    bool visitType(Node* node);
    bool visitPrimitiveType(Node* node);
    bool visitArrayType(Node* node);
    bool visitRecordType(Node* node);
    bool visitVariableDeclarations(Node* node);
    bool visitBody(Node* node);
    bool visitStatement(Node* node);
    bool visitT_RETURN(Node* node);
    bool visitT_PRINT(Node* node);
    bool visitIfStatement(Node* node);
    bool visitT_IF_ELSE(Node* node);
    bool visitT_IF(Node* node);
    bool visitForLoop(Node* node);
    bool visitRange(Node* node);
    bool visitT_IN(Node* node);
    bool visitT_IN_REVERSE(Node* node);
    bool visitWhileLoop(Node* node);
    bool visitRoutineCall(Node* node);
    bool visitAssignment(Node* node);
    bool visitExpressions(Node* node);
    bool visitExpression(Node* node);
    bool visitT_AND(Node* node);
    bool visitT_OR(Node* node);
    bool visitT_XOR(Node* node);
    bool visitRelation(Node* node);
    bool visitT_LESS(Node* node);
    bool visitT_LESSOREQU(Node* node);
    bool visitT_GREAT(Node* node);
    bool visitT_GREATOREQU(Node* node);
    bool visitT_EQU(Node* node);
    bool visitT_NOTEQU(Node* node);
    bool visitSimple(Node* node);
    bool visitT_MULTOP(Node* node);
    bool visitT_DIVOP(Node* node);
    bool visitT_MODOP(Node* node);
    bool visitFactor(Node* node);
    bool visitT_ADDOP(Node* node);
    bool visitT_SUBTROP(Node* node);
    bool visitSummand(Node* node);
    bool visitPrimary(Node* node);
    bool visitT_ICONST(Node* node);
    bool visitT_CCONST(Node* node);
    bool visitT_RCONST(Node* node);
    bool visitT_TRUE(Node* node);
    bool visitT_FALSE(Node* node);
    bool visitModifiablePrimary(Node* node);
    bool visitT_DOT(Node* node);
    bool visitID_ARRAY(Node* node);
    bool visitT_BRACKS(Node* node);
    bool visitT_ID_use(Node *node);
    bool visitT_ID_define(Node *node);
};


#endif