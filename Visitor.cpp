#include "Visitor.h"
#include "TypeClass.h"
#include <iostream>
#include <string>
using namespace std;

bool compareTypes(Type *firstType, Type *secondType)
{
    if (firstType->toString() == secondType->toString())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Visitor::visitProgram(Node *node)
{
    if (node->token.token == T_ROOT)
    {
        if (DEBUG)
            cout << "Enter; Program" << endl;

        bool collector = false;
        for (auto iterator : node->nodes)
        {
            collector = visitSimpleDeclaration(iterator);
            if (collector)
                continue;
            collector = visitRoutineDeclaration(iterator);

            if (collector == false)
                break;
        }
        if (collector == false)
        {
            cout << "T_ROOT Error" << endl;
            exit(1);
            return false;
        }
        if (DEBUG)
            cout << "return true; Program" << endl;
        return true;
    }
    return false;
}
bool Visitor::visitSimpleDeclaration(Node *node)
{
    if (DEBUG)
        cout << "Enter; SimpleDeclaration" << endl;

    if (visitVariableDeclaration(node) || visitTypeDeclaration(node))
    {
        if (DEBUG)
            cout << "return true; SimpleDeclaration" << endl;
        return true;
    }
    else
        return false;
}

bool Visitor::visitVariableDeclaration(Node *node)
{
    if (DEBUG)
        cout << "Enter; VariableDeclaration" << endl;
    if (visitT_VAR_DECL_COLON_IS(node) || visitT_VAR_DECL_COLON(node) || visitT_VAR_DECL_IS(node))
    {
        if (DEBUG)
            cout << "return true; VariableDeclaration" << endl;
        return true;
    }
    else
        return false;
}
bool Visitor::visitTypeDeclaration(Node *node)
{
    if (DEBUG)
        cout << "Enter; TypeDeclaration" << endl;

    if (visitT_TYPE_DECL_IS(node))
    {
        if (DEBUG)
            cout << "return true; TypeDeclaration" << endl;
        return true;
    }
    else
        return false;
}

bool Visitor::visitRoutineDeclaration(Node *node)
{
    if (DEBUG)
        cout << "Enter; RoutineDeclaration" << endl;

    if (visitT_ROUTIN_DECL_TYPE(node) || visitT_ROUTIN_DECL(node))
    {
        if (DEBUG)
            cout << "return true; RoutineDeclaration" << endl;
        return true;
    }
    else
        return false;
}

bool Visitor::visitT_VAR_DECL_COLON_IS(Node *node)
{
    if (node->token.token == T_VAR_DECL_COLON_IS)
    {
        if (DEBUG)
            cout << "Enter; T_VAR_DECL_COLON_IS" << endl;

        if (visitT_ID_define(node->nodes[0]) == false)
        {
            cout << "T_VAR_DECL_COLON_IS Error" << endl;
            exit(1);
        }
        string varNameC = this->varName;

        if (visitType(node->nodes[1]) == false)
        {
            cout << "T_VAR_DECL_COLON_IS Error" << endl;
            exit(1);
        }
        if (visitExpression(node->nodes[2]) == false)
        {
            cout << "T_VAR_DECL_COLON_IS Error" << endl;
            exit(1);
        }

        Type *returnType_ = this->getReturnType("visitT_VAR_DECL_COLON_IS");
        Type *expectedType_ = this->getExpectedType("visitT_VAR_DECL_COLON_IS");
        if (compareTypes(returnType_, expectedType_) == false)
        {
            cout << "Error: real type and expected type are not the same "
                 << "visitT_VAR_DECL_COLON_IS" << endl;
            exit(1);
        }

        this->stateInsert(varNameC, returnType_);

        if (DEBUG)
            cout << "return true; T_VAR_DECL_COLON_IS" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitT_VAR_DECL_COLON(Node *node)
{
    if (node->token.token == T_VAR_DECL_COLON)
    {
        if (DEBUG)
            cout << "Enter; T_VAR_DECL_COLON" << endl;

        if (visitT_ID_define(node->nodes[0]) == false)
        {
            cout << "T_VAR_DECL_COLON Error" << endl;
            exit(1);
        }
        string varNameC = this->varName;

        if (visitType(node->nodes[1]) == false)
        {
            cout << "T_VAR_DECL_COLON Error" << endl;
            exit(1);
        }
        Type *expectedType_ = this->getExpectedType("visitT_VAR_DECL_COLON");

        this->stateInsert(varNameC, expectedType_);

        this->returnType = expectedType_;
        if (DEBUG)
            cout << "return true; T_VAR_DECL_COLON" << endl;
        return true;
    }
    return false;
}
bool Visitor::visitT_VAR_DECL_IS(Node *node)
{
    if (node->token.token == T_VAR_DECL_IS)
    {
        if (DEBUG)
            cout << "Enter; T_VAR_DECL_IS" << endl;

        if (visitT_ID_define(node->nodes[0]) == false)
        {
            cout << "T_VAR_DECL_IS Error" << endl;
            exit(1);
        }
        string varNameC = this->varName;

        if (visitExpression(node->nodes[1]) == false)
        {
            cout << "T_VAR_DECL_IS Error" << endl;
            exit(1);
        }
        Type *returnType_ = this->getReturnType("visitT_VAR_DECL_IS");

        this->stateInsert(varNameC, returnType_);

        if (DEBUG)
            cout << "return true; T_VAR_DECL_IS" << endl;
        return true;
    }
    return false;
};

bool Visitor::visitT_TYPE_DECL_IS(Node *node)
{
    if (node->token.token == T_TYPE_DECL_IS)
    {
        if (DEBUG)
            cout << "Enter; T_TYPE_DECL_IS" << endl;

        if (visitT_ID_define(node->nodes[0]) == false)
        {
            cout << "Routine name error" << endl;
            exit(1);
        }
        string typeName = this->varName;
        this->typeNames.insert(typeName);

        if (visitType(node->nodes[1]) == false)
        {
            cout << "T_TYPE_DECL_IS Error" << endl;
            exit(1);
        }
        Type *returnType_ = this->getExpectedType("visitT_TYPE_DECL_IS");

        this->stateInsert(typeName, returnType_);

        if (DEBUG)
            cout << "return true; T_TYPE_DECL_IS" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitT_ROUTIN_DECL_TYPE(Node *node)
{
    if (node->token.token == T_ROUTIN_DECL_TYPE){
        if (DEBUG)
            cout << "Enter; T_ROUTIN_DECL_TYPE" << endl;

        if (node->nodes.size() > 3){
            if (visitT_ID_define(node->nodes[0]) == false)
            {
                cout << "T_TYPE_DECL_IS Error" << endl;
                exit(1);
            }
            this->funcionName = this->varName;
            string routineName = this->varName;
            if (this->typeNames.count(routineName) != 0)
            {
                cout << "Expected routine name, but got type name" << std::endl;
                exit(1);
            }

            unordered_map<string, Type *> stateCopy = this->state;
            if (visitParameters(node->nodes[1]) == false)
            {
                cout << "T_TYPE_DECL_IS Error" << endl;
                exit(1);
            }

            if (visitType(node->nodes[2]) == false)
            {
                cout << "T_TYPE_DECL_IS Error" << endl;
                exit(1);
            }

            Type *expectedType_ = this->getExpectedType("visitT_ROUTIN_DECL_TYPE");
            ListType *paramTypes = this->getListTypes("visitT_ROUTIN_DECL_TYPE");

            TypeFun *rutineType = new TypeFun(paramTypes, new ReturnType(expectedType_));

            this->stateInsert(routineName, rutineType);

            if (visitBody(node->nodes[3]) == false)
            {
                cout << "T_TYPE_DECL_IS Error" << endl;
                exit(1);
            }
            Type *returnType_ = this->getReturnType("visitT_ROUTIN_DECL_TYPE");
            if (compareTypes(returnType_, expectedType_) == false)
            {
                cout << "Error: real type and expected type are not the same "
                     << "T_ROUTIN_DECL_TYPE" << endl;
                exit(1);
            }

            this->state = stateCopy;
            this->stateInsert(routineName, rutineType);

            if (DEBUG)
                cout << "return true; T_ROUTIN_DECL_TYPE" << endl;
            return true;
        }
        else
        {
            if (visitT_ID_define(node->nodes[0]) == false)
            {
                cout << "T_TYPE_DECL_IS Error" << endl;
                exit(1);
            }
            string routineName = this->varName;
            if (this->typeNames.count(routineName) != 0)
            {
                cout << "Expected routine name, but got type name" << std::endl;
                exit(1);
            }

            if (visitParameters(node->nodes[1]) == false)
            {
                cout << "T_TYPE_DECL_IS Error" << endl;
                exit(1);
            }

            if (visitType(node->nodes[2]) == false)
            {
                cout << "T_TYPE_DECL_IS Error" << endl;
                exit(1);
            }

            Type *returnType_ = this->getExpectedType("visitT_ROUTIN_DECL_TYPE");
            ListType *paramTypes = this->getListTypes("visitT_ROUTIN_DECL_TYPE");

            TypeFun *rutineType = new TypeFun(paramTypes, new ReturnType(returnType_));

            this->stateInsert(routineName, rutineType);

            if (DEBUG)
                cout << "return true; T_ROUTIN_DECL_TYPE" << endl;
            return true;
        }
    }
    return false;
}

bool Visitor::visitT_ROUTIN_DECL(Node *node){

    if (node->token.token == T_ROUTIN_DECL){
        if (DEBUG)
            cout << "Enter; T_ROUTIN_DECL" << endl;

        if (visitT_ID_define(node->nodes[0]) == false){
            cout << "Routine name error" << endl;
            exit(1);
        }
        string routineName = this->varName;
        if (this->typeNames.count(routineName) != 0)
        {
            cout << "Expected routine name, but got type name" << std::endl;
            exit(1);
        }
        this->funcionName = this->varName;

        if (visitParameters(node->nodes[1]) == false)
        {
            cout << "T_ROUTIN_DECL Error" << endl;
            exit(1);
        }
        ListType *paramTypes = this->getListTypes("visitT_ROUTIN_DECL");

        unordered_map<string, Type *> stateCopy = this->state;
        if (visitBody(node->nodes[2]) == false)
        {
            cout << "T_ROUTIN_DECL Error" << endl;
            exit(1);
        }
        Type *returnType_ = this->getReturnType("visitT_ROUTIN_DECL");
        TypeFun *rutineType = new TypeFun(paramTypes, new ReturnType(returnType_));

        this->stateInsert(routineName, rutineType);

        this->state = stateCopy;
        if (DEBUG)
            cout << "return true; T_ROUTIN_DECL" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitParameters(Node *node)
{
    if (node->token.token == T_PARAMETERS)
    {
        if (DEBUG)
            cout << "Enter; Parameters" << endl;

        vector<Type *> Types;
        for (auto iterator : node->nodes)
        {
            if (visitParameterDeclaration(iterator) == false)
            {
                cout << "Parameters Error" << endl;
                exit(1);
            }

            Type *currentType = getExpectedType("visitParameters");
            Types.push_back(currentType);
        }
        this->listTypes = new ListType(Types);

        if (DEBUG)
            cout << "return true; Parameters" << endl;
        return true;
    }
    return false;
}
bool Visitor::visitParameterDeclaration(Node *node)
{
    if (node->token.token == T_COLON)
    {
        if (DEBUG)
            cout << "Enter; ParameterDeclaration" << endl;

        if (visitT_ID_define(node->nodes[0]) == false)
        {
            cout << "ParameterDeclaration Error" << endl;
            exit(1);
        }
        string paramName = this->varName;
        if (this->typeNames.count(paramName) != 0)
        {
            cout << "Expected parameter name, but got type name" << std::endl;
            exit(1);
        }

        if (visitType(node->nodes[1]) == false)
        {
            cout << "ParameterDeclaration Error" << endl;
            exit(1);
        }
        Type *returnType_ = this->getExpectedType("visitParameterDeclaration");

        this->stateInsert(paramName, returnType_);

        if (DEBUG)
            cout << "return true; ParameterDeclaration" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitType(Node *node)
{
    if (DEBUG)
        cout << "Enter; Type" << endl;

    if (visitPrimitiveType(node) || visitArrayType(node) || visitRecordType(node) || visitT_ID_use(node))
    {

        if (visitT_ID_use(node))
        {
            this->expectedType = this->returnType;
            if (this->typeNames.count(this->varName) == 0)
            {
                cout << "Expected type name, but got variable name" << std::endl;
                exit(1);
            }
        }
        if (DEBUG)
            cout << "return true; Type" << endl;
        return true;
    }
    else
        return false;
}

bool Visitor::visitPrimitiveType(Node *node)
{
    if (node->token.token == T_INTEGER || node->token.token == T_REAL || node->token.token == T_BOOLEAN || node->token.token == T_CHAR)
    {
        if (DEBUG)
            cout << "Enter; PrimitiveType" << endl;

        switch (node->token.token)
        {
        case T_INTEGER:
            this->expectedType = new TypeInteger();
            break;
        case T_REAL:
            this->expectedType = new TypeReal();
            break;
        case T_BOOLEAN:
            this->expectedType = new TypeBool();
            break;
        case T_CHAR:
            this->expectedType = new TypeChar();
            break;
        default:
            cout << "Default type" << endl;
            exit(1);
        }

        if (DEBUG)
            cout << "return true; PrimitiveType" << endl;
        return true;
    }
    else
        return false;
}

bool Visitor::visitArrayType(Node *node)
{
    if (node->token.token == T_ARRAY)
    {
        if (DEBUG)
            cout << "Enter; ArrayType" << endl;

        if (visitExpression(node->nodes[0]) == false)
        {
            cout << "ArrayType Error" << endl;
            exit(1);
        }
        if (visitType(node->nodes[1]) == false)
        {
            cout << "ArrayType Error" << endl;
            exit(1);
        }

        Type *expectedType_ = this->getExpectedType("visitArrayType");
        this->expectedType = new TypeArray(expectedType_);

        if (DEBUG)
            cout << "return true; ArrayType" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitRecordType(Node *node)
{
    if (node->token.token == T_RECORD)
    {
        if (DEBUG)
            cout << "Enter; RecordType" << endl;

        vector<Type *> Types;
        vector<string> Names;

        unordered_map<string, Type *> stateCopy = this->state;
        for (auto iterator : node->nodes)
        {
            if (iterator->token.token == 291 || iterator->token.token == 289)
            {
                cout << "Error: such declaration is not allowded in the record decl" << endl;
                exit(1);
            }
            if (visitVariableDeclaration(iterator) == false)
            {
                cout << "Error: incorrect variable declaration in the record type" << endl;
                exit(1);
            }

            string currentName = this->varName;
            Type *currentType = getReturnType("visitRecordType");
            Names.push_back(currentName);
            Types.push_back(currentType);
        }
        this->state = stateCopy;
        this->expectedType = new TypeRecord(new ListType(Types), Names);

        if (DEBUG)
            cout << "return true; RecordType" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitT_ID_define(Node *node)
{
    if (node->token.token == T_ID)
    {
        if (DEBUG)
            cout << "Enter; T_ID " << node->token.lexeme << endl;

        this->varName = node->token.lexeme;

        if (DEBUG)
            cout << "return true; T_ID" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitT_ID_use(Node *node)
{
    if (node->token.token == T_ID)
    {
        if (DEBUG)
            cout << "Enter; T_ID " << node->token.lexeme << endl;

        if (this->state.count(node->token.lexeme) == 0)
        {
            cout << "Error: not initialized type or variable" << endl;
            exit(1);
        }

        this->returnType = this->state[node->token.lexeme];
        this->varName = node->token.lexeme;

        if (DEBUG)
            cout << "return true; T_ID" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitBody(Node *node)
{
    if (node->token.token == T_BODY)
    {
        if (DEBUG)
            cout << "Enter; Body" << endl;

        for (auto iterator : node->nodes)
        {
            if (visitSimpleDeclaration(iterator) || visitStatement(iterator))
                continue;
            else
            {
                cout << "visitBody Error" << endl;
                exit(1);
                return false;
            }
        }
        if (DEBUG)
            cout << "return true; Body" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitStatement(Node *node)
{
    if (DEBUG)
        cout << "Enter; Statement" << endl;

    if (visitAssignment(node) || visitRoutineCall(node) || visitWhileLoop(node) || visitForLoop(node) || visitIfStatement(node) || visitT_RETURN(node) || visitT_PRINT(node))
    {
        if (DEBUG)
            cout << "return true; Statement" << endl;
        return true;
    }
    else
        return false;
}

bool Visitor::visitT_RETURN(Node *node)
{
    if (node->token.token == T_RETURN)
    {
        if (DEBUG)
            cout << "Enter; T_RETURN" << endl;

        if (visitExpression(node->nodes[0]) == false)
        {
            cout << "T_RETURN Error" << endl;
            exit(1);
        }
        Type *expectedType_ = this->state[this->funcionName];
        TypeFun *expectedTypeFun_ = dynamic_cast<TypeFun *>(expectedType_);
        Type *returnType_ = this->getReturnType("visitT_RETURN");
        ReturnType *expectedTypeFunReturnType = dynamic_cast<ReturnType *>(expectedTypeFun_->type_);

        if (compareTypes(returnType_, expectedTypeFunReturnType->type_) == false)
        {
            cout << "Error: real type and expected type are not the same "
                 << "visitT_RETURN" << endl;
            exit(1);
        }

        if (DEBUG)
            cout << "return true; T_RETURN" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitT_PRINT(Node *node)
{
    if (node->token.token == T_PRINT)
    {
        if (DEBUG)
            cout << "Enter; T_PRINT" << endl;

        if (visitExpression(node->nodes[0]) == false)
        {
            cout << "T_PRINT Error" << endl;
            exit(1);
        }
        Type *returnType_ = this->getReturnType("visitT_RETURN");

        if (compareTypes(returnType_, new TypeBool()) == false &&
            compareTypes(returnType_, new TypeInteger()) == false &&
            compareTypes(returnType_, new TypeReal()) == false &&
            compareTypes(returnType_, new TypeChar()) == false)
        {
            cout << "Error: real type and expected type are not the same "
                 << "visitT_PRINT" << endl;
            exit(1);
        }

        if (DEBUG)
            cout << "return true; T_PRINT" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitIfStatement(Node *node)
{
    if (DEBUG)
        cout << "Enter; IfStatement" << endl;

    if (visitT_IF_ELSE(node) || visitT_IF(node))
    {
        if (DEBUG)
            cout << "return true; IfStatement" << endl;
        return true;
    }
    else
        return false;
}

bool Visitor::visitT_IF_ELSE(Node *node)
{
    if (node->token.token == T_IF_ELSE)
    {
        if (DEBUG)
            cout << "Enter; T_IF_ELSE" << endl;

        if (visitExpression(node->nodes[0]) == false)
        {
            cout << "T_IF_ELSE Error" << endl;
            exit(1);
        }

        Type *returnType_ = this->getReturnType("visitT_IF_ELSE");
        if (visitBody(node->nodes[1]) == false)
        {
            cout << "T_IF_ELSE Error" << endl;
            exit(1);
        }
        if (visitBody(node->nodes[2]) == false)
        {
            cout << "T_IF_ELSE Error" << endl;
            exit(1);
        }
        if (compareTypes(returnType_, new TypeBool()) == false)
        {
            cout << "Error: real type and expected type are not the same "
                 << "visitT_IF_ELSE" << endl;
            exit(1);
        }

        if (DEBUG)
            cout << "return true; T_IF_ELSE" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitT_IF(Node *node)
{
    // Node

    if (node->token.token == T_IF)
    {
        if (DEBUG)
            cout << "Enter; T_IF" << endl;

        if (visitExpression(node->nodes[0]) == false)
        {
            cout << "T_IF Error" << endl;
            exit(1);
        }

        Type *returnType_ = this->getReturnType("visitT_IF");
        if (compareTypes(returnType_, new TypeBool()) == false)
        {
            cout << "Error: real type and expected type are not the same "
                 << "visitT_IF" << endl;
            exit(1);
        }
        if (visitBody(node->nodes[1]) == false)
        {
            cout << "T_IF Error" << endl;
            exit(1);
        }

        if (DEBUG)
            cout << "return true; T_IF" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitForLoop(Node *node)
{
    if (node->token.token == T_FOR)
    {
        if (DEBUG)
            cout << "Enter; ForLoop" << endl;

        if (visitT_ID_define(node->nodes[0]) == false)
        {
            cout << "T_FOR Error" << endl;
            exit(1);
        }
        string indexName = this->varName;
        if (this->typeNames.count(indexName) != 0)
        {
            cout << "Expected variable name, but got type name" << std::endl;
            exit(1);
        }

        unordered_map<string, Type *> stateCopy = this->state;
        this->stateInsert(indexName, new TypeInteger());
        if (visitRange(node->nodes[1]) == false)
        {
            cout << "T_FOR Error" << endl;
            exit(1);
        }
        if (visitBody(node->nodes[2]) == false)
        {
            cout << "T_FOR Error" << endl;
            exit(1);
        }

        if (DEBUG)
            cout << "return true; ForLoop" << endl;
        return true;
        this->state = stateCopy;
    }
    return false;
}
bool Visitor::visitRange(Node *node)
{
    if (DEBUG)
        cout << "Enter; Range" << endl;

    if (visitT_IN(node) || visitT_IN_REVERSE(node))
    {
        if (DEBUG)
            cout << "return true; Range" << endl;
        return true;
    }
    else
        return false;
}

bool Visitor::visitT_IN(Node *node)
{
    if (node->token.token == T_IN)
    {
        if (DEBUG)
            cout << "Enter; T_IN" << endl;

        if (visitExpression(node->nodes[0]) == false)
        {
            cout << "T_IN Error" << endl;
            exit(1);
        }

        Type *returnType1_ = this->getReturnType("visitT_IF_ELSE");
        if (visitExpression(node->nodes[1]) == false)
        {
            cout << "T_IN Error" << endl;
            exit(1);
        }
        Type *returnType2_ = this->getReturnType("visitT_IF_ELSE");

        if (compareTypes(returnType1_, new TypeInteger()) == false)
        {
            cout << "Error: index in for is not integer "
                 << "visitT_IN" << endl;
            exit(1);
        }
        if (compareTypes(returnType2_, new TypeInteger()) == false)
        {
            cout << "Error: index in for is not integer"
                 << "visitT_IN" << endl;
            exit(1);
        }

        if (DEBUG)
            cout << "return true; T_IN" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitT_IN_REVERSE(Node *node)
{
    if (node->token.token == T_IN_REVERSE)
    {
        if (DEBUG)
            cout << "Enter; T_IN_REVERSE" << endl;

        if (visitExpression(node->nodes[0]) == false)
        {
            cout << "T_IN_REVERSE Error" << endl;
            exit(1);
        }

        Type *returnType1_ = this->getReturnType("visitT_IF_ELSE");
        if (visitExpression(node->nodes[1]) == false)
        {
            cout << "T_IN_REVERSE Error" << endl;
            exit(1);
        }
        Type *returnType2_ = this->getReturnType("visitT_IF_ELSE");

        if (compareTypes(returnType1_, new TypeInteger()) == false)
        {
            cout << "Error: index in for is not integer "
                 << "visitT_IN_REVERSE" << endl;
            exit(1);
        }
        if (compareTypes(returnType2_, new TypeInteger()) == false)
        {
            cout << "Error: index in for is not integer"
                 << "visitT_IN_REVERSE" << endl;
            exit(1);
        }

        if (DEBUG)
            cout << "return true; T_IN_REVERSE" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitWhileLoop(Node *node)
{
    if (node->token.token == T_WHILE)
    {
        if (DEBUG)
            cout << "Enter; WhileLoop" << endl;

        if (visitExpression(node->nodes[0]) == false)
        {
            cout << "T_WHILE Error" << endl;
            exit(1);
        }
        Type *returnType_ = this->getReturnType("visitT_IF_ELSE");

        if (visitBody(node->nodes[1]) == false)
        {
            cout << "T_WHILE Error" << endl;
            exit(1);
        }

        if (compareTypes(returnType_, new TypeBool()) == false)
        {
            cout << "Error: condition in while loop -> visitWhileLoop" << endl;
            exit(1);
        }

        if (DEBUG)
            cout << "return true; WhileLoop" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitRoutineCall(Node *node)
{
    // Node
    if (node->token.token == T_ROUTINE_CALL)
    {
        if (DEBUG)
            cout << "Enter; RoutineCall" << endl;

        if (visitT_ID_use(node->nodes[0]) == false)
        {
            cout << "Error in routine call function" << endl;
            exit(1);
        }
        if (this->typeNames.count(this->varName) != 0)
        {
            cout << "Expected routine name, but got type name" << std::endl;
            exit(1);
        }

        Type *routineType_ = this->returnType;
        TypeFun *routineTypeFun = nullptr;
        if (routineType_->getName() == "fun")
        {
            routineTypeFun = (TypeFun *)routineType_;
        }
        else
        {
            cout << "Error: visitT_ID_use" << endl;
            exit(1);
        }

        int j = 0;
        for (auto iterator : vector<Node *>(node->nodes.begin() + 1, node->nodes.end()))
        {
            if (visitExpression(iterator) == false)
            {
                cout << "Erorr in the routine call parameters" << endl;
                exit(1);
            }
            Type *returnParamType = this->getReturnType("visitRoutineCall");

            if (compareTypes(routineTypeFun->listtype_->types_[j], returnParamType) == false)
            {
                cout << "Error: incorrect passing parameters visitRoutineCall" << endl;
                exit(1);
            }

            ++j;
        }
        if (j < node->nodes.size() - 1)
        {
            cout << "Error: not enough parameters" << endl;
            exit(1);
        }

        this->returnType = routineTypeFun->type_;

        if (DEBUG)
            cout << "return true; RoutineCall" << endl;
        return true;
    }
    if (node->token.token == T_ID)
    {
        if (DEBUG)
            cout << "Enter; RoutineCall" << endl;

        if (DEBUG)
            cout << "return true; RoutineCall" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitAssignment(Node *node)
{
    if (node->token.token == T_COLONEQU)
    {
        if (DEBUG)
            cout << "Enter; Assignment" << endl;

        if (visitModifiablePrimary(node->nodes[0]) == false)
        {
            cout << "Assignment Error" << endl;
            exit(1);
        }

        Type *modifiableType_ = this->getReturnType("visitAssignment");
        if (visitExpression(node->nodes[1]) == false)
        {
            cout << "Assignment Error" << endl;
            exit(1);
        }
        Type *exprType_ = this->getReturnType("visitAssignment");

        if (compareTypes(modifiableType_, exprType_) == false)
        {
            cout << "Error: incorrect type of equation" << endl;
            exit(1);
        }

        if (DEBUG)
            cout << "return true; Assignment" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitExpression(Node *node)
{
    if (DEBUG)
        cout << "Enter; Expression" << endl;

    if (visitRelation(node) || visitT_AND(node) || visitT_OR(node) || visitT_XOR(node))
    {
        if (DEBUG)
            cout << "return true; Expression" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool Visitor::visitT_AND(Node *node)
{
    if (node->token.token == T_AND)
    {
        if (DEBUG)
            cout << "Enter; T_AND" << endl;

        if (visitRelation(node->nodes[0]) == false)
        {
            cout << "T_AND Error" << endl;
            exit(1);
        }
        Type *relationType_ = this->getReturnType("visitT_AND");

        if (visitExpression(node->nodes[1]) == false)
        {
            cout << "T_AND Error" << endl;
            exit(1);
        }
        Type *expressionType_ = this->getReturnType("visitT_AND");

        if (compareTypes(relationType_, new TypeBool()) == false)
        {
            cout << "Error: incorrect expression type "
                 << "visitT_AND" << endl;
            exit(1);
        }
        if (compareTypes(relationType_, expressionType_) == false)
        {
            cout << "Error: incorrect expression type "
                 << "visitT_AND" << endl;
            exit(1);
        }

        this->returnType = new TypeBool();
        if (DEBUG)
            cout << "return true; T_AND" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitT_OR(Node *node)
{
    if (node->token.token == T_OR)
    {
        if (DEBUG)
            cout << "Enter; T_OR" << endl;

        if (visitRelation(node->nodes[0]) == false)
        {
            cout << "T_OR Error" << endl;
            exit(1);
        }
        Type *relationType_ = this->getReturnType("visitT_OR");

        if (visitExpression(node->nodes[1]) == false)
        {
            cout << "T_OR Error" << endl;
            exit(1);
        }
        Type *expressionType_ = this->getReturnType("visitT_OR");

        if (compareTypes(relationType_, new TypeBool()) == false)
        {
            cout << "Error: incorrect expression type "
                 << "visitT_OR" << endl;
            exit(1);
        }
        if (compareTypes(relationType_, expressionType_) == false)
        {
            cout << "Error: incorrect expression type "
                 << "visitT_OR" << endl;
            exit(1);
        }

        this->returnType = new TypeBool();
        if (DEBUG)
            cout << "return true; T_OR" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitT_XOR(Node *node)
{
    if (node->token.token == T_XOR)
    {
        if (DEBUG)
            cout << "Enter; T_XOR" << endl;

        if (visitRelation(node->nodes[0]) == false)
        {
            cout << "T_XOR Error" << endl;
            exit(1);
        }
        Type *relationType_ = this->getReturnType("visitT_XOR");

        if (visitExpression(node->nodes[1]) == false)
        {
            cout << "T_XOR Error" << endl;
            exit(1);
        }
        Type *expressionType_ = this->getReturnType("visitT_XOR");

        if (compareTypes(relationType_, new TypeBool()) == false)
        {
            cout << "Error: incorrect expression type "
                 << "visitT_XOR" << endl;
            exit(1);
        }
        if (compareTypes(relationType_, expressionType_) == false)
        {
            cout << "Error: incorrect expression type "
                 << "visitT_XOR" << endl;
            exit(1);
        }

        this->returnType = new TypeBool();
        if (DEBUG)
            cout << "return true; T_XOR" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitRelation(Node *node)
{
    if (DEBUG)
        cout << "Enter; Relation" << endl;

    if (visitSimple(node) || visitT_LESS(node) || visitT_LESSOREQU(node) || visitT_GREAT(node) || visitT_GREATOREQU(node) || visitT_EQU(node) || visitT_NOTEQU(node))
    {
        if (DEBUG)
            cout << "return true; Relation" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool Visitor::visitT_LESS(Node *node)
{
    if (node->token.token == T_LESS)
    {
        if (DEBUG)
            cout << "Enter; T_LESS" << endl;

        if (visitSimple(node->nodes[0]) == false)
        {
            cout << "T_LESS Error" << endl;
            exit(1);
        }
        Type *simpleType_1 = this->getReturnType("visitT_LESS");

        if (visitSimple(node->nodes[1]) == false)
        {
            cout << "T_LESS Error" << endl;
            exit(1);
        }
        Type *simpleType_2 = this->getReturnType("visitT_LESS");

        if (compareTypes(simpleType_1, simpleType_2) == false)
        {
            cout << "Error: incorrect relation types "
                 << "visitT_LESS" << endl;
            exit(1);
        }

        this->returnType = new TypeBool();
        if (DEBUG)
            cout << "return true; T_LESS" << endl;
        return true;
    }
    return false;
}
bool Visitor::visitT_LESSOREQU(Node *node)
{
    if (node->token.token == T_LESSOREQU)
    {
        if (DEBUG)
            cout << "Enter; T_LESSOREQU" << endl;

        if (visitSimple(node->nodes[0]) == false)
        {
            cout << "visitT_LESSOREQU Error" << endl;
            exit(1);
        }
        Type *simpleType_1 = this->getReturnType("visitT_LESSOREQU");

        if (visitSimple(node->nodes[1]) == false)
        {
            cout << "visitT_LESSOREQU Error" << endl;
            exit(1);
        }
        Type *simpleType_2 = this->getReturnType("visitT_LESSOREQU");

        if (compareTypes(simpleType_1, simpleType_2) == false)
        {
            cout << "Error: incorrect relation types "
                 << "visitT_LESSOREQU" << endl;
            exit(1);
        }

        this->returnType = new TypeBool();
        if (DEBUG)
            cout << "return true; T_LESSOREQU" << endl;
        return true;
    }
    return false;
}
bool Visitor::visitT_GREAT(Node *node)
{
    if (node->token.token == T_GREAT)
    {
        if (DEBUG)
            cout << "Enter; T_GREAT" << endl;

        if (visitSimple(node->nodes[0]) == false)
        {
            cout << "T_GREAT Error" << endl;
            exit(1);
        }
        Type *simpleType_1 = this->getReturnType("visitT_GREAT");

        if (visitSimple(node->nodes[1]) == false)
        {
            cout << "T_GREAT Error" << endl;
            exit(1);
        }
        Type *simpleType_2 = this->getReturnType("visitT_GREAT");

        if (compareTypes(simpleType_1, simpleType_2) == false)
        {
            cout << "Error: incorrect relation types "
                 << "visitT_GREAT" << endl;
            exit(1);
        }

        this->returnType = new TypeBool();
        if (DEBUG)
            cout << "return true; T_GREAT" << endl;
        return true;
    }
    return false;
}
bool Visitor::visitT_GREATOREQU(Node *node)
{
    if (node->token.token == T_GREATOREQU)
    {
        if (DEBUG)
            cout << "Enter; T_GREATOREQU" << endl;

        if (visitSimple(node->nodes[0]) == false)
        {
            cout << "T_GREATOREQU Error" << endl;
            exit(1);
        }
        Type *simpleType_1 = this->getReturnType("visitT_GREATOREQU");

        if (visitSimple(node->nodes[1]) == false)
        {
            cout << "T_GREATOREQU Error" << endl;
            exit(1);
        }
        Type *simpleType_2 = this->getReturnType("visitT_GREATOREQU");

        if (compareTypes(simpleType_1, simpleType_2) == false)
        {
            cout << "Error: incorrect relation types "
                 << "visitT_GREATOREQU" << endl;
            exit(1);
        }

        this->returnType = new TypeBool();
        if (DEBUG)
            cout << "return true; T_GREATOREQU" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitT_EQU(Node *node)
{
    if (node->token.token == T_EQU)
    {
        if (DEBUG)
            cout << "Enter; T_EQU" << endl;

        if (visitSimple(node->nodes[0]) == false)
        {
            cout << "T_EQU Error" << endl;
            exit(1);
        }
        Type *simpleType_1 = this->getReturnType("visitT_EQU");

        if (visitSimple(node->nodes[1]) == false)
        {
            cout << "T_EQU Error" << endl;
            exit(1);
        }
        Type *simpleType_2 = this->getReturnType("visitT_EQU");

        if (compareTypes(simpleType_1, simpleType_2) == false)
        {
            cout << "Error: incorrect relation types "
                 << "visitT_EQU" << endl;
            exit(1);
        }

        this->returnType = new TypeBool();
        if (DEBUG)
            cout << "return true; T_EQU" << endl;
        return true;
    }
    return false;
}
bool Visitor::visitT_NOTEQU(Node *node)
{
    if (node->token.token == T_NOTEQU)
    {
        if (DEBUG)
            cout << "Enter; T_NOTEQU" << endl;

        if (visitSimple(node->nodes[0]) == false)
        {
            cout << "T_NOTEQU Error" << endl;
            exit(1);
        }
        Type *simpleType_1 = this->getReturnType("visitT_NOTEQU");

        if (visitSimple(node->nodes[1]) == false)
        {
            cout << "T_NOTEQU Error" << endl;
            exit(1);
        }
        Type *simpleType_2 = this->getReturnType("visitT_NOTEQU");

        if (compareTypes(simpleType_1, simpleType_2) == false)
        {
            cout << "Error: incorrect relation types "
                 << "visitT_NOTEQU" << endl;
            exit(1);
        }

        this->returnType = new TypeBool();
        if (DEBUG)
            cout << "return true; T_NOTEQU" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitSimple(Node *node)
{
    if (DEBUG)
        cout << "Enter; Simple" << endl;

    if (visitFactor(node) || visitT_MULTOP(node) || visitT_DIVOP(node) || visitT_MODOP(node))
    {
        if (DEBUG)
            cout << "return true; Simple" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool Visitor::visitT_MULTOP(Node *node)
{
    if (node->token.token == T_MULTOP)
    {
        if (DEBUG)
            cout << "Enter; T_MULTOP" << endl;

        if (visitFactor(node->nodes[0]) == false)
        {
            cout << "T_MULTOP Error" << endl;
            exit(1);
        }
        Type *factorType_1 = this->getReturnType("visitT_MULTOP");

        if (visitSimple(node->nodes[1]) == false)
        {
            cout << "T_MULTOP Error" << endl;
            exit(1);
        }
        Type *factorType_2 = this->getReturnType("visitT_MULTOP");

        if (compareTypes(factorType_1, factorType_2) == false)
        {
            cout << "Error: incorrect simple types "
                 << "visitT_MULTOP" << endl;
            exit(1);
        }

        this->returnType = factorType_2;
        if (DEBUG)
            cout << "return true; T_MULTOP" << endl;
        return true;
    }
    return false;
}
bool Visitor::visitT_DIVOP(Node *node)
{
    if (node->token.token == T_DIVOP)
    {
        if (DEBUG)
            cout << "Enter; T_DIVOP" << endl;

        if (visitFactor(node->nodes[0]) == false)
        {
            cout << "T_DIVOP Error" << endl;
            exit(1);
        }
        Type *factorType_1 = this->getReturnType("visitT_MULTOP");

        if (visitSimple(node->nodes[1]) == false)
        {
            cout << "T_DIVOP Error" << endl;
            exit(1);
        }
        Type *factorType_2 = this->getReturnType("visitT_MULTOP");

        if (compareTypes(factorType_1, factorType_2) == false)
        {
            cout << "Error: incorrect simple types "
                 << "visitT_MULTOP" << endl;
            exit(1);
        }

        this->returnType = factorType_2;
        if (DEBUG)
            cout << "return true; T_DIVOP" << endl;
        return true;
    }
    return false;
}
bool Visitor::visitT_MODOP(Node *node)
{
    if (node->token.token == T_MODOP)
    {
        if (DEBUG)
            cout << "Enter; T_MODOP" << endl;

        if (visitFactor(node->nodes[0]) == false)
        {
            cout << "T_MODOP Error" << endl;
            exit(1);
        }
        Type *factorType_1 = this->getReturnType("visitT_MODOP");

        if (visitSimple(node->nodes[1]) == false)
        {
            cout << "T_MODOP Error" << endl;
            exit(1);
        }
        Type *factorType_2 = this->getReturnType("visitT_MODOP");

        if (compareTypes(factorType_1, factorType_2) == false)
        {
            cout << "Error: incorrect simple types "
                 << "visitT_MODOP" << endl;
            exit(1);
        }

        this->returnType = factorType_2;
        if (DEBUG)
            cout << "return true; T_MODOP" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitFactor(Node *node)
{
    if (DEBUG)
        cout << "Enter; Factor" << endl;

    if (visitSummand(node) || visitT_ADDOP(node) || visitT_SUBTROP(node))
    {
        if (DEBUG)
            cout << "return true; Factor" << endl;
        return true;
    }
    else
    {
        // cout << "Factor Error" << endl;
        // exit(1);
        return false;
    }
}
bool Visitor::visitT_ADDOP(Node *node)
{
    if (node->token.token == T_ADDOP)
    {
        if (DEBUG)
            cout << "Enter; T_ADDOP" << endl;

        if (visitSummand(node->nodes[0]) == false)
        {
            cout << "T_ADDOP Error" << endl;
            exit(1);
        }
        Type *summandType_ = this->getReturnType("visitT_ADDOP");

        if (visitFactor(node->nodes[1]) == false)
        {
            cout << "T_ADDOP Error" << endl;
            exit(1);
        }
        Type *factorType_ = this->getReturnType("visitT_ADDOP");

        if (compareTypes(factorType_, summandType_) == false)
        {
            cout << "Error: incorrect factor types "
                 << "visitT_ADDOP" << endl;
            exit(1);
        }

        this->returnType = summandType_;
        if (DEBUG)
            cout << "return true; T_ADDOP" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitT_SUBTROP(Node *node)
{
    if (node->token.token == T_SUBTROP)
    {
        if (DEBUG)
            cout << "Enter; T_SUBTROP" << endl;

        if (visitSummand(node->nodes[0]) == false)
        {
            cout << "T_SUBTROP Error" << endl;
            exit(1);
        }
        Type *summandType_ = this->getReturnType("visitT_SUBTROP");

        if (visitFactor(node->nodes[1]) == false)
        {
            cout << "T_SUBTROP Error" << endl;
            exit(1);
        }
        Type *factorType_ = this->getReturnType("visitT_SUBTROP");

        if (compareTypes(factorType_, summandType_) == false)
        {
            cout << "Error: incorrect factor types "
                 << "visitT_SUBTROP" << endl;
            exit(1);
        }

        this->returnType = summandType_;
        if (DEBUG)
            cout << "return true; T_SUBTROP" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitSummand(Node *node)
{
    if (DEBUG)
        cout << "Enter; Summand" << endl;

    if (visitPrimary(node) || visitT_PARENT(node))
    {
        if (DEBUG)
            cout << "return true; Summand" << endl;
        return true;
    }
    else
    {
        return false;
    }
}
bool Visitor::visitT_PARENT(Node *node)
{
    if (node->token.token == T_PARENT)
    {
        if (DEBUG)
            cout << "Enter; T_PARENT" << endl;

        if (visitExpression(node->nodes[0]) == false)
        {
            cout << "T_PARENT Error" << endl;
            exit(1);
        }

        if (DEBUG)
            cout << "return true; T_PARENT" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool Visitor::visitPrimary(Node *node)
{
    if (DEBUG)
        cout << "Enter; Primary" << endl;

    if (visitT_ICONST(node) || visitT_CCONST(node) || visitT_RCONST(node) || visitT_TRUE(node) || visitT_FALSE(node) || visitModifiablePrimary(node))
    {
        if (DEBUG)
            cout << "return true; Primary" << endl;
        return true;
    }
    else
    {
        return false;
    }
}
bool Visitor::visitT_ICONST(Node *node)
{
    if (node->token.token == T_ICONST)
    {
        if (DEBUG)
            cout << "Enter; T_ICONST" << endl;

        this->returnType = new TypeInteger();
        if (DEBUG)
            cout << "return true; T_ICONST" << endl;
        return true;
    }
    return false;
}
bool Visitor::visitT_CCONST(Node *node)
{
    if (node->token.token == T_CCONST)
    {
        if (DEBUG)
            cout << "Enter; T_CCONST" << endl;

        this->returnType = new TypeChar();
        if (DEBUG)
            cout << "return true; T_CCONST" << endl;
        return true;
    }
    return false;
}
bool Visitor::visitT_RCONST(Node *node)
{
    if (node->token.token == T_RCONST)
    {
        if (DEBUG)
            cout << "Enter; T_RCONST" << endl;

        this->returnType = new TypeReal();
        if (DEBUG)
            cout << "return true; T_RCONST" << endl;
        return true;
    }
    return false;
}
bool Visitor::visitT_TRUE(Node *node)
{
    if (node->token.token == T_TRUE)
    {
        if (DEBUG)
            cout << "Enter; T_TRUE" << endl;

        this->returnType = new TypeBool();
        if (DEBUG)
            cout << "return true; T_TRUE" << endl;
        return true;
    }
    return false;
}
bool Visitor::visitT_FALSE(Node *node)
{
    if (node->token.token == T_FALSE)
    {
        if (DEBUG)
            cout << "Enter; T_FALSE" << endl;

        this->returnType = new TypeBool();
        if (DEBUG)
            cout << "return true; T_FALSE" << endl;
        return true;
    }
    return false;
}

bool Visitor::visitModifiablePrimary(Node *node)
{
    if (DEBUG)
        cout << "Enter; ModifiablePrimary" << endl;

    // Actualy parsing dots
    // a[0].b[1].c => [a[0] , b[1] , c]

    vector<Node *> dot_nodes;
    Node *deviding = node;

    while (deviding->token.token == T_DOT)
    {
        if (deviding->nodes.size() > 1)
        {
            dot_nodes.push_back(deviding->nodes[0]);
            deviding = deviding->nodes[1];
        }
        else
        {
            cout << "Error: not enough parameters" << endl;
            exit(1);
        }
    }
    dot_nodes.push_back(deviding);

    Type *returnType;
    if (dot_nodes[0]->token.token == T_BRACKS)
    {
        if (this->typeNames.count(dot_nodes[0]->nodes[0]->token.lexeme) != 0)
        {
            cout << "Expected array name, but got type name" << std::endl;
            exit(1);
        }
        returnType = this->state[dot_nodes[0]->nodes[0]->token.lexeme]; // a[0][1] -> a
        int nestedNum = 0;

        Node *arrayThrough = dot_nodes[0];
        while (arrayThrough->token.token == T_BRACKS)
        {
            TypeArray *returnTypeArray = (TypeArray *)returnType;
            if (returnType->getName() != "array")
            {
                cout << "Error: expected array, but got: " << returnType->getName() << endl;
                exit(1);
            }

            if (arrayThrough->nodes.size() > 0)
            {
                returnType = returnTypeArray->type_;

                if (arrayThrough->nodes.size() > 2)
                {
                    arrayThrough = arrayThrough->nodes[2];
                }
                else if (arrayThrough->nodes.size() > 1)
                {
                    arrayThrough = arrayThrough->nodes[1];
                }
                else
                {
                    arrayThrough = arrayThrough->nodes[0];
                }
            }
            else
            {
                cout << "Error: not enough parameters" << endl;
                exit(1);
            }
        }
    }
    else if (dot_nodes[0]->token.token == T_ID)
    {
        if (this->state.count(dot_nodes[0]->token.lexeme) == 0)
        {
            cout << "Error: unknown identifier:" << dot_nodes[0]->token.lexeme << endl;
            exit(1);
        }
        if (this->typeNames.count(dot_nodes[0]->token.lexeme) != 0)
        {
            cout << "Expected variable name, but got type name" << std::endl;
            exit(1);
        }
        returnType = this->state[dot_nodes[0]->token.lexeme];
    }
    else
    {
        return false;
    }

    for (int i = 1; i < dot_nodes.size(); i++)
    {
        if (returnType->getName() != "record")
        {
            cout << "Error: expected record, but got: " << returnType->getName() << endl;
            exit(1);
        }
        TypeRecord *returnTypeRecord = (TypeRecord *)returnType;

        string fieldName;
        if (dot_nodes[i]->token.token == T_BRACKS)
        {
            fieldName = dot_nodes[i]->nodes[0]->token.lexeme;
            if (this->typeNames.count(dot_nodes[i]->nodes[0]->token.lexeme) != 0)
            {
                cout << "Expected array name, but got type name" << std::endl;
                exit(1);
            }
        }
        else if (dot_nodes[i]->token.token == T_ID)
        {
            fieldName = dot_nodes[i]->token.lexeme;
            if (this->typeNames.count(dot_nodes[i]->token.lexeme) != 0)
            {
                cout << "Expected variable name, but got type name" << std::endl;
                exit(1);
            }
        }
        else
        {
            cout << "Error: expected ID but got" << dot_nodes[i]->token.lexeme << endl;
            exit(1);
        }

        bool found = false;
        for (int j = 0; j < returnTypeRecord->names.size(); j++)
        {
            if (fieldName == returnTypeRecord->names[j])
            {
                returnType = returnTypeRecord->listtype_->types_[j]; // a[0][1] -> a
                found = true;
            }
        }
        if (found == false)
        {
            cout << "Error: not found field" << dot_nodes[i]->token.lexeme << endl;
            exit(1);
        }

        if (dot_nodes[i]->token.token == T_BRACKS)
        {
            int nestedNum = 0;

            Node *arrayThrough = dot_nodes[i];
            while (arrayThrough->token.token == T_BRACKS)
            {
                TypeArray *returnTypeArray = (TypeArray *)returnType;
                if (returnType->getName() != "array")
                {
                    cout << "Error: expected array, but got: " << returnType->getName() << endl;
                    exit(1);
                }

                if (arrayThrough->nodes.size() > 0)
                {
                    returnType = returnTypeArray->type_;

                    if (arrayThrough->nodes.size() > 2)
                    {
                        arrayThrough = arrayThrough->nodes[2];
                    }
                    else if (arrayThrough->nodes.size() > 1)
                    {
                        arrayThrough = arrayThrough->nodes[1];
                    }
                    else
                    {
                        arrayThrough = arrayThrough->nodes[0];
                    }
                }
                else
                {
                    cout << "Error: not enough parameters" << endl;
                    exit(1);
                }
            }
        }
    }

    this->returnType = returnType;
    if (DEBUG)
        cout << "return true; ModifiablePrimary" << endl;
    return true;
}