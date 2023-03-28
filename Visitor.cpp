#include "Visitor.h"
#include <iostream>
using namespace std;

bool Visitor::visitProgram(Node *Program)
{
    if (Program->token.token == T_ROOT)
    {
        bool collector = false;
        for (auto iterator : Program->nodes)
        {
            // VariableDeclaration
            collector = visitSimpleDeclaration(iterator); // 0
            if (collector)
                continue;
            collector = visitRoutineDeclaration(iterator); // 1
            if (collector == false)
                break;

           /* if (visitSimpleDeclaration(iterator)
            || visitRoutineDeclaration(iterator))
                continue;
            else
                break;*/
        }
        if (collector == false){
            cout << "Program Error" << endl;
            exit(1);
        }
        return true;
    }
    return false;
}
bool Visitor::visitSimpleDeclaration(Node *SimpleDeclaration)
{
    //visitVariableDeclaration(); // 0
    //visitTypeDeclaration(); // 0
    for (auto iterator : SimpleDeclaration->nodes)
    {
        if (visitVariableDeclaration(iterator)
            || visitTypeDeclaration(iterator))
            continue;
        else
            return false;
    }
    return true;
}

bool Visitor::visitVariableDeclaration(Node *VariableDeclaration)
{
    //T_VAR_DECL_COLON_IS ==
    //          visitT_VAR_DECL_COLON_IS
    //T_VAR_DECL_COLON ==
    //          visitT_VAR_DECL_COLON
        
    //T_VAR_DECL_IS ==
    //      visitT_VAR_DECL_IS
    for (auto iterator : VariableDeclaration->nodes)
    {
        if (visitT_VAR_DECL_COLON_IS(iterator)
            || visitT_VAR_DECL_COLON(iterator)
            || visitT_VAR_DECL_IS(iterator))
            continue;
        else
            return false;
    }
    return true;
        
}
bool Visitor::visitTypeDeclaration(Node *TypeDeclaration)
{
    //T_TYPE_DECL_IS
    //visitT_TYPE_DECL_IS
    for (auto iterator : TypeDeclaration->nodes)
    {
        if (visitT_TYPE_DECL_IS(iterator))
            continue;
        else
            return false;
    }
    return true;
}

bool Visitor::visitRoutineDeclaration(Node *RoutineDeclaration)
{
    //T_ROUTIN_DECL_TYPE
    // ||
    //visitT_ROUTIN_DECL_TYPE
    // T_ROUTIN_DECL ==
    for (auto iterator : RoutineDeclaration->nodes)
    {
        if (visitT_ROUTIN_DECL_TYPE(iterator)
            || visitT_ROUTIN_DECL(iterator))
            continue;
        else
            return false;
    }
    return true; 
}

bool Visitor::visitT_VAR_DECL_COLON_IS(Node *SMT)
{
    // T_ID
    //visitT_ID 
    // &&
    // Type
    //Type 
    // &&
    // Expression
    //Expression
    if (SMT->token.token == T_VAR_DECL_COLON_IS)
    {
        for (auto iterator : SMT->nodes)
        {
            if (visitT_ID(iterator)
                && visitType(iterator)
                && visitExpression(iterator))
                continue;
            else{
                cout << "T_VAR_DECL_COLON_IS Error" << endl;
                exit(1);
            }
        }
        return true;
    }
    return false;
}

bool Visitor::visitT_VAR_DECL_COLON(Node *SMT)
{
    //T_ID
    // &&
    //Type
    for (auto iterator : SMT->nodes)
    {
        if (visitT_ID(iterator)
            && visitType(iterator))
            continue;
        else{
            cout << "T_VAR_DECL_COLON Error" << endl;
            exit(1);}
    }
    return true;
}
bool Visitor::visitT_VAR_DECL_IS(Node *SMT)
{
    //T_ID
    // &&
    //Expression
    for (auto iterator : SMT->nodes)
    {
        if (visitT_ID(iterator)
            && visitExpression(iterator))
            continue;
        else
            return false;
    }
}

bool Visitor::visitT_TYPE_DECL_IS()
{
    T_ID
    // && 
    Type
}

bool Visitor::visitT_ROUTIN_DECL_TYPE()
{
    T_ID
    // &&
    Parameters
    // &&
    Type
    // &&
    if (exist Body)
        Body
}

bool Visitor::visitT_ROUTIN_DECL()
{
    T_ID
    // &&
    Parameters
    // && 
    if (exist Body)
        Body
}

bool Visitor::visitParameters()
{
    //непонятно как обработать empty
    visitParameterDeclaration()
    // &&
    if (exist ParameterDeclarations)
        visitParameterDeclarations()
    for (){
        
    }
}
bool Visitor::visitParameterDeclaration()
{
    T_ID
    // &&
    Type
}

   
bool Visitor::visitParameterDeclarations()
{
    //непонятно как обработать empty
    ParameterDeclaration
    // &&
    if (exist ParameterDeclarations)
        ParameterDeclarations
}

bool Visitor::visitType()
{
    PrimitiveType
    // ||
    ArrayType
    // ||
    RecordType
    // ||
    T_ID
    
}

bool Visitor::visitPrimitiveType()
{
   T_INTEGER
    // ||
    T_REAL
    // ||
    T_BOOLEAN
    // ||
    T_CHAR
}

bool Visitor::visitArrayType()
{
    //И
    Expression
    // &&
    Type
}
bool Visitor::visitRecordType()
{
    /*Обработать empty*/ 
    if (exist VariableDeclarations)
        VariableDeclarations   
}

bool Visitor::visitT_ID()
{
       
}

bool Visitor::visitVariableDeclarations()
{
    /*Обработать empty*/ 
    VariableDeclaration
    // &&
    if (exist VariableDeclarations)
        VariableDeclarations   
}

bool Visitor::visitBody()
{
    
    for (){
        SimpleDeclaration
        //||
        Statement
    }
}

bool Visitor::visitStatement(Node *Statement)
{
    //Not node
    Assignment
    //||
    RoutineCall
    //||
    WhileLoop
    //||
    ForLoop
    //||
    IfStatement
    //||
    T_RETURN
    //||
    T_PRINT
    //||

    for (auto iterator : Statement->nodes)
    {
        if (visitAssignment(iterator)
            || visitRoutineCall(iterator)
            || visitWhileLoop(iterator)
            || visitForLoop(iterator)
            || visitIfStatement(iterator)
            || visitT_RETURN(iterator)
            || visitT_PRINT(iterator))
            continue;
        else
            return false;
    }
    return true;
}

bool Visitor::visitT_RETURN(Node *SMT)
{    // Node
    Expression 

    if(SMT->token.token == T_RETURN){
        for (auto iterator : SMT->nodes)
        {
            if (visitExpression(iterator))
                continue;
            else
            {
                cout << "T_RETURN Error" << endl;
                exit(1);    
            }
        }
        return true;
    }
    return false;
}

bool Visitor::visitT_PRINT(Node *SMT)
{    // Node
    Expression 

    if(SMT->token.token == T_PRINT){
        for (auto iterator : SMT->nodes)
        {
            if (visitExpression(iterator))
                continue;
            else
            {
                cout << "T_PRINT Error" << endl;
                exit(1);    
            }
        }
        return true;
    }
    return false;
}

bool Visitor::visitIfStatement(Node *IfStatement)
{    //Not node
    T_IF_ELSE 
    //||
    T_IF
    for (auto iterator : IfStatement->nodes)
    {
        if (visitT_IF_ELSE(iterator)
            || visitT_IF(iterator))
            continue;
        else
            return false;
    }
    return true;
}

bool Visitor::visitT_IF_ELSE(Node *SMT)
{    //Node
    //&&
    Expression Body Body
    
    if(SMT->token.token == T_IF_ELSE){
        if (visitExpression(SMT->nodes[0])
            && visitBody(SMT->nodes[1])
            && visitBody(SMT->nodes[2]))
            return true;
        else
        {
            cout << "T_IF_ELSE Error" << endl;
            exit(1);    
        }
    } 
    return false;
}

bool Visitor::visitT_IF(Node *SMT)
{    //Node
    //&&
    Expression Body 
    if(SMT->token.token == T_IF){
        if (visitExpression(SMT->nodes[0])
            && visitBody(SMT->nodes[1]))
            return true;
        else
        {
            cout << "T_IF Error" << endl;
            exit(1);    
        }
    }
    return false;
}

bool Visitor::visitForLoop(Node *ForLoop)
{
    //Node
    //&&
    T_ID Range Body  
    if(SMT->token.token == T_FOR){
        if (visitT_ID(ForLoop->nodes[0])
            && visitRange(ForLoop->nodes[1])
            && visitBody(ForLoop->nodes[2]))
            return true;
        else
        {
            cout << "T_FOR Error" << endl;
            exit(1);    
        }
    }
    return false;
}
bool Visitor::visitRange(Node *Range)
{
    //No node
    //||
    T_IN
    T_IN_REVERSE
    for (auto iterator : Range->nodes)
    {
        if (visitT_IN(iterator)
            || visitT_IN_REVERSE(iterator))
            continue;
        else
            return false;
    }
    
}

bool Visitor::visitT_IN()
{
    //Node
    //&&
    Expression
    Expression 
}

bool Visitor::visitT_IN_REVERSE()
{
    //Node
    //&&
    Expression
    Expression
}

bool Visitor::visitWhileLoop()
{
    //Node
    //&&
    Expression
    Body 
}

bool Visitor::visitRoutineCall(){
    //Node
    
    T_ID 
    //||
    //(
    T_ID 
    //&&
    Expressions 
    //)
}

bool Visitor::visitAssignment(){
    //Node
    //&&
    ModifiablePrimary 
    Expression
}

bool Visitor::visitExpressions(){
    //No node
    Expression
    //||
    //(
    Expression 
    //&&
    Expressions  
    //)
}

bool Visitor::visitExpression(){
    //No node
    //||
    visitRelation
    visitT_AND
    visitT_OR
    visitT_XOR
}

bool Visitor::visitT_AND(){
    //Node
    // &&
    Relation
    Expression
}

bool Visitor::visitT_OR(){
    //Node
    // &&
    Relation
    Expression
}

bool Visitor::visitT_XOR(){
    //Node
    // &&
    Relation
    Expression
}

bool Visitor::visitRelation(){
    //No node
    // || 
    Simple
    T_LESS
    T_LESSOREQU
    T_GREAT
    T_GREATOREQU
    T_EQU
    T_NOTEQU
} 

bool Visitor::visitT_LESS(){
    //Node
    // &&
    Simple 
    Simple
}
bool Visitor::visitT_LESSOREQU(){
    //Node
    // &&
    Simple 
    Simple
}
bool Visitor::visitT_GREAT(){
    //Node
    // &&
    Simple 
    Simple
}
bool Visitor::visitT_GREATOREQU(){
    //Node
    // &&
    Simple 
    Simple
}
bool Visitor::visitT_LESS(){
    //Node
    // &&
    Simple 
    Simple
}
bool Visitor::visitT_EQU(){
    //Node
    // &&
    Simple 
    Simple
}
bool Visitor::visitT_NOTEQU(){
    //Node
    // &&
    Simple 
    Simple
}

bool Visitor::visitSimple(){
    //No node
    // || 
    Factor
    T_MULTOP
    T_DIVOP
    T_MODOP
} 

bool Visitor::visitT_MULTOP(){
    //Node
    // && 
    Factor 
    Simple
} 
bool Visitor::visitT_DIVOP(){
    //Node
    // && 
    Factor 
    Simple
} 
bool Visitor::visitT_MODOP(){
    //Node
    // && 
    Factor 
    Simple
} 

bool Visitor::visitFactor(){
    //No node
    // || 
    Summand
    T_ADDOP
    T_SUBTROP
} 
bool Visitor::visitT_ADDOP(){
    //Node
    // && 
    Summand 
    Factor
} 

bool Visitor::visitT_SUBTROP(){
    //Node
    // && 
    Summand 
    Factor
} 

bool Visitor::visitSummand(){
    //No node
    // || 
    Primary
    Expression
} 

bool Visitor::visitPrimary(){
    //No node
    // || 
    T_ICONST
    T_CCONST
    T_RCONST
    T_TRUE
    T_FALSE
    ModifiablePrimary
} 
bool Visitor::visitT_ICONST(){
    //Node
} 
bool Visitor::visitT_CCONST(){
    //Node
} 
bool Visitor::visitT_RCONST(){
    //Node
} 
bool Visitor::visitT_TRUE(){
    //Node
} 
bool Visitor::visitT_FALSE(){
    //Node
} 

bool Visitor::visitModifiablePrimary(){
    //No node
    // || 
    ID_ARRAY
    T_DOT
} 

bool Visitor::visitT_DOT(){
    //Node
    // &&
    ID_ARRAY 
    ModifiablePrimary
} 

bool Visitor::visitID_ARRAY(){
    //No node
    // || 
    T_ID
    T_BRACKS
} 

bool Visitor::visitT_BRACKS(){
    //Node
    // && 
    T_ID
    for (){
        Expression
    }
} 

//Identifiers_ARRAY не реализован