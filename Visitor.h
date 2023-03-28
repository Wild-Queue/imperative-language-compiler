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
    T_LESS = 301,                  /* T_LESS  */
    T_GREAT = 302,                 /* T_GREAT  */
    T_LESSOREQU = 303,             /* T_LESSOREQU  */
    T_GREATOREQU = 304,            /* T_GREATOREQU  */
    T_NOTEQU = 305,                /* T_NOTEQU  */
    T_EQU = 306,                   /* T_EQU  */
    T_COLONEQU = 307,              /* T_COLONEQU  */
    T_AND = 308,                   /* T_AND  */
    T_OR = 309,                    /* T_OR  */
    T_XOR = 310,                   /* T_XOR  */
    T_ADDOP = 311,                 /* T_ADDOP  */
    T_MULTOP = 312,                /* T_MULTOP  */
    T_SUBTROP = 313,               /* T_SUBTROP  */
    T_DIVOP = 314,                 /* T_DIVOP  */
    T_MODOP = 315,                 /* T_MODOP  */
    T_LPAREN = 316,                /* T_LPAREN  */
    T_RPAREN = 317,                /* T_RPAREN  */
    T_LBRACK = 318,                /* T_LBRACK  */
    T_RBRACK = 319,                /* T_RBRACK  */
    T_DOTDOT = 320,                /* T_DOTDOT  */
    T_DOT = 321,                   /* T_DOT  */
    T_COMMA = 322,                 /* T_COMMA  */
    T_COLON = 323                  /* T_COLON  */
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
    NT_Statement = 28,
    NT_Relation = 29,
    NT_Simple = 30,
    NT_Boolean = 31,
    NT_Char = 32,
    NT_IdentifiersArray = 33
};

#endif
#ifndef VISITOR_PATTERN
#define VISITOR_PATTERN
#include "NodeDecl.h"
#include <string>
#include <unordered_map>

using namespace std;
class Visitor {
    class declaredVariable{
        std::string name;
        yytokentype type;
        double value;
    };
    
    //Не ебу но будет новый declaredVariable
    unordered_map<string, declaredVariable> state;
    
    void visitProgram(Node* Program);
    void visitVarDecl(Node* VarDecl);
    void visitTypeDecl(Node* TypeDecl);
    void visitRoutineDecl(Node* RoutineDecl);
    void visitParametersDecl(Node* ParametersDecl);
    void visitParameterDecl(Node* ParameterDecl);
    void visitIdentificator(Node* Identificator);
    void visitConstInt(Node* ConstInt);
    void visitConstReal(Node* ConstReal);
    void visitConstTrue(Node* ConstTrue);
    void visitConstFalse(Node* ConstFalse);
    void visitConstChar(Node* ConstChar);
    void visitRecord(Node* Record);
    void visitArrayType(Node* ArrayType);
    void visitStatement(Node* Statement);
    void visitReturn(Node* Return);
    void visitAssignment(Node* Assignment);
    void visitExpression(Node* Expression);
    void visitForLoop(Node* ForLoop);
    void visitFactor(Node* Factor);
    void visitInteger(Node* Integer);
    void visitReal(Node* Real);
    void visitIdArray(Node* IdArray);
    void visitBody(Node* Body);
    void visitPrint(Node* Print);
    void visitRoutineCall(Node* RoutineCall);
    void visitWhileLoop(Node* WhileLoop);
    void visitRange(Node* Range);
    void visitStatement(Node* Statement);
    void visitRelation(Node* Relation);
    void visitSimple(Node* Simple);
    void visitBoolean(Node* Boolean);
    void visitChar(Node* Char);
    void visitIdentifiersArray(Node* IdentifiersArray);
    void visitColonEqu(Node *ColonEqu);
    void visitInReverse(Node *InReverse);
    void visitDot(Node *Dot);
    void visitBrackets(Node *Brackets);
    void visitSubtrOp(Node *SubtrOp);
    void visitAddOp(Node *AddOp);
    void visitModOp(Node *ModOp);
    void visitDivOp(Node *DivOp);
    void visitMultOp(Node *MultOp);
    void visitNotEqu(Node *NotEqu);
    void visitEqu(Node *Equ);
    void visitGreatOrEqu(Node *GreatOrEqu);
    void visitGreat(Node *Great);
    void visitLessOrEqu(Node *LessOrEqu);
    void visitLess(Node *Less);
    void visitXor(Node *Xor);
    void visitOr(Node *Or);
    void visitAnd(Node *And);
    void visitIfElse(Node *IfElse);
    void visitIf(Node *If);
    void visitIn(Node *In);
};


#endif