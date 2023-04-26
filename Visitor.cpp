#include "Visitor.h"
#include "TypeClass.h"
#include <iostream>
#include <string>
using namespace std;

bool compareTypes(Type* firstType, Type*  secondType){
    cout << firstType->toString() << ",,, " << secondType->toString() << endl;
    if(firstType->toString() == secondType->toString()){
        return true;
    }
    else{
        return false;
    }
}

bool Visitor::visitProgram(Node *node){
    if (DEBUG)
        cout << "Enter; Program" << endl; /*DEBUG*/

    if (node->token.token == T_ROOT){
        bool collector = false;
        for (auto iterator : node->nodes){
            // VariableDeclaration
            collector = visitSimpleDeclaration(iterator); // 0
            if (collector)
                continue;
            collector = visitRoutineDeclaration(iterator); // 1
            if (collector == false)
                break;
        }
        for (auto iter : this->state){
            cout << iter.first << " : " << iter.second << endl;
        }
        if (collector == false){
            cout << "T_ROOT Error" << endl;
            exit(1);
            return false;
        }
        if (DEBUG)
            cout << "return true; Program" << endl; /*DEBUG*/
        return true;
    }
    return false;
}
bool Visitor::visitSimpleDeclaration(Node *node){
    if (DEBUG)
        cout << "Enter; SimpleDeclaration" << endl; /*DEBUG*/

    if (visitVariableDeclaration(node) || visitTypeDeclaration(node)){
        if (DEBUG)
            cout << "return true; SimpleDeclaration" << endl; /*DEBUG*/
        return true;
    }
    else
        return false;
}

bool Visitor::visitVariableDeclaration(Node *node){
    if (DEBUG)
        cout << "Enter; VariableDeclaration" << endl; /*DEBUG*/
    if (visitT_VAR_DECL_COLON_IS(node) || visitT_VAR_DECL_COLON(node) || visitT_VAR_DECL_IS(node)){
        if (DEBUG)
            cout << "return true; VariableDeclaration" << endl; /*DEBUG*/
        return true;
    }
    else
        return false;
}
bool Visitor::visitTypeDeclaration(Node *node){
    if (DEBUG)
        cout << "Enter; TypeDeclaration" << endl; /*DEBUG*/

    if (visitT_TYPE_DECL_IS(node)){
        if (DEBUG)
            cout << "return true; TypeDeclaration" << endl; /*DEBUG*/
        return true;
    }
    else
        return false;
}

bool Visitor::visitRoutineDeclaration(Node *node){
    if (DEBUG)
        cout << "Enter; RoutineDeclaration" << endl; /*DEBUG*/

    if (visitT_ROUTIN_DECL_TYPE(node) || visitT_ROUTIN_DECL(node)){
        if (DEBUG)
            cout << "return true; RoutineDeclaration" << endl; /*DEBUG*/
        return true;
    }
    else
        return false;
}

bool Visitor::visitT_VAR_DECL_COLON_IS(Node *node){
    if (DEBUG)
        cout << "Enter; T_VAR_DECL_COLON_IS" << endl; /*DEBUG*/

    if (node->token.token == T_VAR_DECL_COLON_IS){
        if (visitT_ID_define(node->nodes[0])){

            string varNameC = this->varName;
            if (visitType(node->nodes[1]) && visitExpression(node->nodes[2])){
                if (DEBUG)
                    cout << "return true; T_VAR_DECL_COLON_IS" << endl; /*DEBUG*/

                Type* returnType_ = this->getReturnType("visitT_VAR_DECL_COLON_IS");
                Type* expectedType_ = this->getExpectedType("visitT_VAR_DECL_COLON_IS");
                if (compareTypes(returnType_, expectedType_) == false){
                    cout << "Error: real type and expected type are not the same " << "visitT_VAR_DECL_COLON_IS" << endl;
                    exit(1);
                }

                this->stateInsert(varNameC, returnType_);
                
                
                return true;
            }else{
                cout << "T_VAR_DECL_COLON_IS Error" << endl;
                exit(1);
                return false;
            }
        }
        else{
            cout << "T_VAR_DECL_COLON_IS Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitT_VAR_DECL_COLON(Node *node){
    if (DEBUG)
        cout << "Enter; T_VAR_DECL_COLON" << endl; /*DEBUG*/

    if (node->token.token == T_VAR_DECL_COLON){
        if (visitT_ID_define(node->nodes[0])){
            string varNameC = this->varName;
                if (visitType(node->nodes[1])){
                Type* expectedType_ = this->getExpectedType("visitT_VAR_DECL_COLON");

                cout << "visitT_VAR_DECL_COLON" << endl;
                this->stateInsert(varNameC, expectedType_);
                
                if (DEBUG)
                    cout << "return true; T_VAR_DECL_COLON" << endl; /*DEBUG*/
                return true;
            }
            else{
                cout << "T_VAR_DECL_COLON Error" << endl;
                exit(1);
                return false;
            }
        }
        else{
            cout << "T_VAR_DECL_COLON Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}
bool Visitor::visitT_VAR_DECL_IS(Node *node){
    if (DEBUG)
        cout << "Enter; T_VAR_DECL_IS" << endl; /*DEBUG*/

    if (node->token.token == T_VAR_DECL_IS){
        if (visitT_ID_define(node->nodes[0])){

            string varNameC = this->varName;
            if (visitExpression(node->nodes[1])){
                Type* returnType_ = this->getReturnType("visitT_VAR_DECL_IS");
                
                cout << "visitT_VAR_DECL_IS" << endl;
                this->stateInsert(varNameC, returnType_);

                if (DEBUG)
                    cout << "return true; T_VAR_DECL_IS" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_VAR_DECL_IS Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_VAR_DECL_IS Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
};

bool Visitor::visitT_TYPE_DECL_IS(Node *node){
    if (DEBUG)
        cout << "Enter; T_TYPE_DECL_IS" << endl; /*DEBUG*/

    if (node->token.token == T_TYPE_DECL_IS){
        if (visitT_ID_define(node->nodes[0])){
            string typeName = this->varName;
            if(visitType(node->nodes[1])){

                Type* returnType_ = this->getExpectedType("visitT_TYPE_DECL_IS");
                
                cout << "visitT_TYPE_DECL_IS" << endl;
                for(auto iterator : this->state){
                    cout << iterator.first << " " << iterator.second->toString() << endl;
                }
                this->stateInsert(typeName, returnType_);

                if (DEBUG)
                    cout << "return true; T_TYPE_DECL_IS" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_TYPE_DECL_IS Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_TYPE_DECL_IS Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitT_ROUTIN_DECL_TYPE(Node *node){
    if (DEBUG)
        cout << "Enter; T_ROUTIN_DECL_TYPE" << endl; /*DEBUG*/

    if (node->token.token == T_ROUTIN_DECL_TYPE){
        if (node->nodes.size() > 3){
            if (visitT_ID_define(node->nodes[0])){

                this->funcionName = this->varName;
                string routineName = this->varName;
                unordered_map<string, Type*> stateCopy = this->state;
                if (visitParameters(node->nodes[1]) && visitType(node->nodes[2])){

                    Type* expectedType_ = this->getExpectedType("visitT_ROUTIN_DECL_TYPE");
                    ListType* paramTypes = this->getListTypes("visitT_ROUTIN_DECL_TYPE");

                    TypeFun* rutineType = new TypeFun(paramTypes, new ReturnType(expectedType_));
                    
                    cout << "visitT_ROUTIN_DECL_TYPE" << endl;
                    this->stateInsert(routineName, rutineType);

                    if (visitBody(node->nodes[3])){
                        Type* returnType_ = this->getReturnType("visitT_ROUTIN_DECL_TYPE");
                        if (compareTypes(returnType_, expectedType_) == false){
                            cout << "Error: real type and expected type are not the same " << "T_ROUTIN_DECL_TYPE" << endl;
                            exit(1);
                        }
                    }
                    this->state = stateCopy;
                    this->stateInsert(routineName, rutineType);
                
                    if (DEBUG)
                        cout << "return true; T_ROUTIN_DECL_TYPE" << endl; /*DEBUG*/
                    return true;
                }
            }else{
                cout << "T_TYPE_DECL_IS Error" << endl;
                exit(1);
                return false;
            }
        }else{
            if (visitT_ID_define(node->nodes[0])){
                string routineName = this->varName;
                if (visitParameters(node->nodes[1]) && visitType(node->nodes[2])){
                    if (DEBUG)
                        cout << "return true; T_ROUTIN_DECL_TYPE" << endl; /*DEBUG*/


                    Type* returnType_ = this->getExpectedType("visitT_ROUTIN_DECL_TYPE");
                    ListType* paramTypes = this->getListTypes("visitT_ROUTIN_DECL_TYPE");
                    
                    TypeFun* rutineType = new TypeFun(paramTypes, new ReturnType(returnType_));
                    
                    cout << "visitT_ROUTIN_DECL_TYPE" << endl;
                    this->stateInsert(routineName, rutineType);

                    return true;
                }else{
                    cout << "T_TYPE_DECL_IS Error" << endl;
                    exit(1);
                    return false;
                }
            }else{
                cout << "T_TYPE_DECL_IS Error" << endl;
                exit(1);
                return false;
            }
        }
    }
    return false;
    // if (exist Body)
    //     Body
}

bool Visitor::visitT_ROUTIN_DECL(Node *node){

    if (node->token.token == T_ROUTIN_DECL){
        if (DEBUG)
            cout << "Enter; T_ROUTIN_DECL" << endl; /*DEBUG*/
        
        if (visitT_ID_define(node->nodes[0])){

            string routineName = this->varName; 
            this->funcionName = this->varName;
            if (visitParameters(node->nodes[1])){
                ListType* paramTypes = this->getListTypes("visitT_ROUTIN_DECL");
                
                unordered_map<string, Type*> stateCopy = this->state;
                if(visitBody(node->nodes[2])){
                    Type* returnType_ = this->getReturnType("visitT_ROUTIN_DECL");
                    
                    TypeFun* rutineType = new TypeFun(paramTypes, new ReturnType(returnType_));
                    
                    cout << "visitT_ROUTIN_DECL" << endl;
                    this->stateInsert(routineName, rutineType);
                    
                    if (DEBUG)
                        cout << "return true; T_ROUTIN_DECL" << endl; /*DEBUG*/
                    return true;
                }
                this->state = stateCopy;
            }
        }else{
            cout << "T_ROUTIN_DECL Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitParameters(Node *node){
    if (DEBUG)
        cout << "Enter; Parameters" << endl; /*DEBUG*/

    if (node->token.token == T_PARAMETERS){
        vector<Type*> Types;
        if (visitParameterDeclaration(node->nodes[0])){
            Type* currentType = this->getExpectedType("visitParameters");
            Types.push_back(currentType);
            if (node->nodes.size() > 1){
                
                for (auto iterator : vector<Node *>(node->nodes.begin() + 1, node->nodes.end())){
                    if (visitParameterDeclaration(iterator)){
                        Type* currentType = getExpectedType("visitParameters");
                        Types.push_back(currentType);
                        continue;
                    }else
                        return false;
                }
    
            }
            this->listTypes = new ListType(Types);//ебать блять теперь надо вот в эту пиздень перейти

            if (DEBUG)
                cout << "return true; Parameters" << endl; /*DEBUG*/
            return true;
        }else{
            cout << "Parameters Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}
bool Visitor::visitParameterDeclaration(Node *node){
    if (DEBUG)
        cout << "Enter; ParameterDeclaration" << endl; /*DEBUG*/

    if (node->token.token == T_COLON){
        if (visitT_ID_define(node->nodes[0])){
            string paramName = this->varName;
            if (visitType(node->nodes[1])){
                Type* returnType_ = this->getExpectedType("visitParameterDeclaration");
                
                cout << "visitParameterDeclaration" << endl;
                this->stateInsert(paramName, returnType_);

                if (DEBUG)
                    cout << "return true; ParameterDeclaration" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "ParameterDeclaration Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "ParameterDeclaration Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitParameterDeclarations(Node *node){
    if (DEBUG)
        cout << "Enter; ParameterDeclarations" << endl; /*DEBUG*/

    if (visitParameterDeclaration(node->nodes[0]) && visitParameters(node->nodes[1])){
        if (DEBUG)
            cout << "return true; ParameterDeclarations" << endl; /*DEBUG*/
        return true;
    }else{
        // cout << "T_ROUTIN_DECL Error" << endl;
        // exit(1);
        return false;
    }
}

bool Visitor::visitType(Node *node){
    if (DEBUG)
        cout << "Enter; Type" << endl; /*DEBUG*/

    if (visitPrimitiveType(node) 
            || visitArrayType(node) 
                || visitRecordType(node) 
                    || visitT_ID_use(node)){
        if (visitT_ID_use(node)){
            this->expectedType = this->returnType;
        }
        if (DEBUG)
            cout << "return true; Type" << endl; /*DEBUG*/
        return true;
    }else
        return false;
}

bool Visitor::visitPrimitiveType(Node *node){
    if (DEBUG)
        cout << "Enter; PrimitiveType" << endl; /*DEBUG*/

    if (node->token.token == T_INTEGER 
            || node->token.token == T_REAL 
                || node->token.token == T_BOOLEAN 
                    || node->token.token == T_CHAR){
        switch (node->token.token){
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
            break;
        }

        if (DEBUG)
            cout << "return true; PrimitiveType" << endl; /*DEBUG*/
        return true;
    }else
        return false;
}

bool Visitor::visitArrayType(Node *node){
    if (DEBUG)
        cout << "Enter; ArrayType" << endl; /*DEBUG*/

    if (node->token.token == T_ARRAY){
        if (visitExpression(node->nodes[0]) && visitType(node->nodes[1])){
            
            Type* expectedType_ = this->getExpectedType("visitArrayType");
            this->expectedType = new TypeArray(expectedType_);
            
            if (DEBUG)
                cout << "return true; ArrayType" << endl; /*DEBUG*/
            return true;
        }else{
            cout << "ArrayType Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitRecordType(Node *node){
    if (DEBUG)
        cout << "Enter; RecordType" << endl; /*DEBUG*/

    if (node->token.token == T_RECORD){
        vector<Type*> Types;
        vector<string> Names;

        unordered_map<string, Type*> stateCopy = this->state;
        for (auto iterator : node->nodes){
            if (visitVariableDeclaration(iterator)){
                string currentName = this->varName;
                Type* currentType = getReturnType("visitRecordType");
                Names.push_back(currentName);
                Types.push_back(currentType);
                continue;
            }else
                return false;   
        }
        this->state = stateCopy;
        this->expectedType = new TypeRecord(new ListType(Types), Names);//ебать блять теперь надо вот в эту пиздень перейти
        
        if (DEBUG)
            cout << "return true; RecordType" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool Visitor::visitT_ID_define(Node *node){
    if (DEBUG)
        cout << "Enter; T_ID " << node->token.lexeme << endl; /*DEBUG*/

    if (node->token.token == T_ID){
        this->varName = node->token.lexeme;
        
        if (DEBUG)
            cout << "return true; T_ID" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool Visitor::visitT_ID_use(Node *node){
    if (DEBUG)
        cout << "Enter; T_ID " << node->token.lexeme << endl; /*DEBUG*/

    if (node->token.token == T_ID){
        if (this->state.count(node->token.lexeme) == 0){
            cout << "Error: not initialized type or variable" << endl;
            exit(1);
        }

        this->returnType = this->state[node->token.lexeme];
        this->varName = node->token.lexeme;

        if (DEBUG)
            cout << "return true; T_ID" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool Visitor::visitBody(Node *node){
    if (DEBUG)
        cout << "Enter; Body" << endl; /*DEBUG*/

    if (node->token.token == T_BODY){
        for (auto iterator : node->nodes){
            if (visitSimpleDeclaration(iterator) || visitStatement(iterator))
                continue;
            else{
                cout << "visitBody Error" << endl;
                exit(1);
                return false;
            }
        }
        if (DEBUG)
            cout << "return true; Body" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool Visitor::visitStatement(Node *node){
    if (DEBUG)
        cout << "Enter; Statement" << endl; /*DEBUG*/

    if (visitAssignment(node) || visitRoutineCall(node) || visitWhileLoop(node) || visitForLoop(node) || visitIfStatement(node) || visitT_RETURN(node) || visitT_PRINT(node)){
        if (DEBUG)
            cout << "return true; Statement" << endl; /*DEBUG*/
        return true;
    }
    else
        return false;
}

bool Visitor::visitT_RETURN(Node *node){
    if (DEBUG)
        cout << "Enter; T_RETURN" << endl; /*DEBUG*/

    if (node->token.token == T_RETURN){
        if (visitExpression(node->nodes[0])){
            Type* expectedType_ = this->state[this->funcionName];
            TypeFun* expectedTypeFun_ = dynamic_cast<TypeFun*>(expectedType_);
            Type* returnType_ = this->getReturnType("visitT_RETURN");
            ReturnType* expectedTypeFunReturnType = dynamic_cast<ReturnType*>(expectedTypeFun_->type_);
            cout << expectedTypeFunReturnType->type_->toString() << " | " << returnType_->toString() << endl;

            if (compareTypes(returnType_, expectedTypeFunReturnType->type_) == false){
                cout << "Error: real type and expected type are not the same " << "visitT_RETURN" << endl;
                exit(1);
            }

            if (DEBUG)
                cout << "return true; T_RETURN" << endl; /*DEBUG*/
            return true;
        }else{
            cout << "T_RETURN Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitT_PRINT(Node *node){
    if (DEBUG)
        cout << "Enter; T_PRINT" << endl; /*DEBUG*/

    if (node->token.token == T_PRINT){
        if (visitExpression(node->nodes[0])){
            Type* returnType_ = this->getReturnType("visitT_RETURN");

            if (compareTypes(returnType_, new TypeBool()) == false &&
                    compareTypes(returnType_, new TypeInteger()) == false &&
                    compareTypes(returnType_, new TypeReal()) == false  &&
                    compareTypes(returnType_, new TypeChar()) == false){
                cout << "Error: real type and expected type are not the same " << "visitT_PRINT" << endl;
                exit(1);
            }

            if (DEBUG)
                cout << "return true; T_PRINT" << endl; /*DEBUG*/
            return true;
        }else{
            cout << "T_PRINT Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitIfStatement(Node *node){
    if (DEBUG)
        cout << "Enter; IfStatement" << endl; /*DEBUG*/

    if (visitT_IF_ELSE(node) || visitT_IF(node)){
        if (DEBUG)
            cout << "return true; IfStatement" << endl; /*DEBUG*/
        return true;
    }else
        return false;
}

bool Visitor::visitT_IF_ELSE(Node *node){
    if (DEBUG)
        cout << "Enter; T_IF_ELSE" << endl; /*DEBUG*/

    if (node->token.token == T_IF_ELSE){
        if (visitExpression(node->nodes[0])){

            Type* returnType_ = this->getReturnType("visitT_IF_ELSE");
            if ( visitBody(node->nodes[1]) && visitBody(node->nodes[2])){
                if (compareTypes(returnType_, new TypeBool()) == false){
                    cout << "Error: real type and expected type are not the same " << "visitT_IF_ELSE" << endl;
                    exit(1);
                }

                if (DEBUG)
                    cout << "return true; T_IF_ELSE" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_IF_ELSE Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_IF_ELSE Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitT_IF(Node *node){
    if (DEBUG)
        cout << "Enter; T_IF" << endl; /*DEBUG*/
                                       // Node
    
    if (node->token.token == T_IF){
        if (visitExpression(node->nodes[0])){

            Type* returnType_ = this->getReturnType("visitT_IF");
            if (compareTypes(returnType_, new TypeBool()) == false){
                cout << "Error: real type and expected type are not the same " << "visitT_IF" << endl;
                exit(1);
            }
            if (visitBody(node->nodes[1])){

                if (DEBUG)
                    cout << "return true; T_IF" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_IF Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_IF Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitForLoop(Node *node){
    if (DEBUG)
        cout << "Enter; ForLoop" << endl; /*DEBUG*/

    if (node->token.token == T_FOR){
        if (visitT_ID_define(node->nodes[0])){
            string indexName = this->varName;
            cout << "visitForLoop" << endl;
            unordered_map<string, Type*> stateCopy = this->state;
            this->stateInsert(indexName, new TypeInteger());
            if (visitRange(node->nodes[1]) && visitBody(node->nodes[2])){

                if (DEBUG)
                    cout << "return true; ForLoop" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_FOR Error" << endl;
                exit(1);
                return false;
            }
            this->state = stateCopy;
        }else{
            cout << "T_FOR Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}
bool Visitor::visitRange(Node *node){
    if (DEBUG)
        cout << "Enter; Range" << endl; /*DEBUG*/

    if (visitT_IN(node) || visitT_IN_REVERSE(node)){
        if (DEBUG)
            cout << "return true; Range" << endl; /*DEBUG*/
        return true;
    }else
        return false;
}

bool Visitor::visitT_IN(Node *node){
    if (DEBUG)
        cout << "Enter; T_IN" << endl; /*DEBUG*/

    if (node->token.token == T_IN){
        if (visitExpression(node->nodes[0])){

            Type* returnType1_ = this->getReturnType("visitT_IF_ELSE");
            if (visitExpression(node->nodes[1])){
                Type* returnType2_ = this->getReturnType("visitT_IF_ELSE");

                if (compareTypes(returnType1_, new TypeInteger()) == false){
                    cout << "Error: index in for is not integer " << "visitT_IN" << endl;
                    exit(1);
                }
                if (compareTypes(returnType2_, new TypeInteger()) == false){
                    cout << "Error: index in for is not integer" << "visitT_IN" << endl;
                    exit(1);
                }
            }else{
                cout << "T_IN Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_IN Error" << endl;
            exit(1);
            return false;
        }


        if (DEBUG)
            cout << "return true; T_IN" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool Visitor::visitT_IN_REVERSE(Node *node){
    if (DEBUG)
        cout << "Enter; T_IN_REVERSE" << endl; /*DEBUG*/

    if (node->token.token == T_IN_REVERSE){
        if (DEBUG)
            cout << "return true; T_IN_REVERSE" << endl; /*DEBUG*/

        if (visitExpression(node->nodes[0])){

            Type* returnType1_ = this->getReturnType("visitT_IF_ELSE");
            if (visitExpression(node->nodes[1])){
                Type* returnType2_ = this->getReturnType("visitT_IF_ELSE");

                if (compareTypes(returnType1_, new TypeInteger()) == false){
                    cout << "Error: index in for is not integer " << "visitT_IN_REVERSE" << endl;
                    exit(1);
                }
                if (compareTypes(returnType2_, new TypeInteger()) == false){
                    cout << "Error: index in for is not integer" << "visitT_IN_REVERSE" << endl;
                    exit(1);
                }
            }else{
                cout << "T_IN_REVERSE Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_IN_REVERSE Error" << endl;
            exit(1);
            return false;
        }
        return true;
    }
    return false;
}

bool Visitor::visitWhileLoop(Node *node){
    if (DEBUG)
        cout << "Enter; WhileLoop" << endl; /*DEBUG*/

    if (node->token.token == T_WHILE){
        if (visitExpression(node->nodes[0])){
            
            Type* returnType_ = this->getReturnType("visitT_IF_ELSE");
            if (visitBody(node->nodes[1])){
                if (compareTypes(returnType_, new TypeBool()) == false){
                    cout << "Error: condition in while loop -> visitWhileLoop" << endl;
                    exit(1);
                }

                if (DEBUG)
                    cout << "return true; WhileLoop" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_WHILE Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_WHILE Error" << endl;
            exit(1);
            return false;
        }

        if (DEBUG)
            cout << "return true; WhileLoop" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool Visitor::visitRoutineCall(Node *node){
    if (DEBUG)
        cout << "Enter; RoutineCall" << endl; /*DEBUG*/

    // Node
    if (node->token.token == T_ROUTINE_CALL){
        if (visitT_ID_use(node->nodes[0])){
            Type* routineType_ = this->returnType;
            TypeFun* routineTypeFun = nullptr;
            if (routineType_->getName() == "fun"){
                routineTypeFun = (TypeFun*) routineType_;
            }

            if (DEBUG)
                cout << "return true; RoutineCall" << endl; /*DEBUG*/
            
            int j = 0;
            cout << "Type Parameters count" << node->nodes.size() << endl;
            for (auto iterator : vector<Node *>(node->nodes.begin() + 1, node->nodes.end())){
                if (visitExpression(iterator)){
                    Type* returnParamType = this->getReturnType("visitRoutineCall");
                    cout << "Type Parameters" << routineTypeFun->listtype_->types_[j]->toString() << " " << returnParamType->toString() << endl;
                    if (compareTypes(routineTypeFun->listtype_->types_[j], returnParamType) == false){
                        cout << "Error: incorrect passing parameters visitRoutineCall" << endl;
                        exit(1);
                    }

                    ++j;
                    continue;
                }else{
                    return false;
                }
            }

            this->returnType = routineTypeFun->type_;
            return true;
        }
        return false;
    }
    if (node->token.token == T_ID){
        cout << "T_ID";
        if (DEBUG)
            cout << "return true; RoutineCall" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool Visitor::visitAssignment(Node *node){
    if (DEBUG)
        cout << "Enter; Assignment" << endl; /*DEBUG*/

    if (node->token.token == T_COLONEQU){
        if (visitModifiablePrimary(node->nodes[0])){

            Type* modifiableType_ = this->getReturnType("visitAssignment");
            if (visitExpression(node->nodes[1])){
                Type* exprType_ = this->getReturnType("visitAssignment");

                cout << modifiableType_->toString() << " " << exprType_->toString() << endl;
                if (compareTypes(modifiableType_, exprType_) == false){
                    cout << "Error: incorrect type of equation" << endl;
                    exit(1);
                }

                if (DEBUG)
                    cout << "return true; Assignment" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "Assignment Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "Assignment Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitExpression(Node *node){
    if (DEBUG)
        cout << "Enter; Expression" << endl; /*DEBUG*/

    if (visitRelation(node) || visitT_AND(node) || visitT_OR(node) || visitT_XOR(node)){
        if (DEBUG)
            cout << "return true; Expression" << endl; /*DEBUG*/
        return true;
    }else{
        // cout << "visitExpression " << endl;
        // exit(1);
        return false;
    }
}

bool Visitor::visitT_AND(Node *node){
    if (DEBUG)
        cout << "Enter; T_AND" << endl; /*DEBUG*/

    if (node->token.token == T_AND){
        if (visitRelation(node->nodes[0])){

            Type* relationType_ = this->getReturnType("visitT_AND");
            if(visitExpression(node->nodes[1])){
                Type* expressionType_ = this->getReturnType("visitT_AND");

                if (compareTypes(relationType_, new TypeBool()) == false){
                    cout << "Error: incorrect expression type " << "visitT_AND" << endl;
                    exit(1);
                }
                if (compareTypes(relationType_, expressionType_) == false){
                    cout << "Error: incorrect expression type " << "visitT_AND" << endl;
                    exit(1);
                }                

                this->returnType = new TypeBool();
                if (DEBUG)
                    cout << "return true; T_AND" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_AND Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_AND Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitT_OR(Node *node){
    if (DEBUG)
        cout << "Enter; T_OR" << endl; /*DEBUG*/

    if (node->token.token == T_OR){
        if (visitRelation(node->nodes[0])){

            Type* relationType_ = this->getReturnType("visitT_OR");
            if(visitExpression(node->nodes[1])){
                Type* expressionType_ = this->getReturnType("visitT_OR");

                if (compareTypes(relationType_, new TypeBool()) == false){
                    cout << "Error: incorrect expression type " << "visitT_OR" << endl;
                    exit(1);
                }
                if (compareTypes(relationType_, expressionType_) == false){
                    cout << "Error: incorrect expression type " << "visitT_OR" << endl;
                    exit(1);
                }                

                this->returnType = new TypeBool();
                if (DEBUG)
                    cout << "return true; T_OR" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_OR Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_OR Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitT_XOR(Node *node){
    if (DEBUG)
        cout << "Enter; T_XOR" << endl; /*DEBUG*/

    if (node->token.token == T_XOR){
        if (visitRelation(node->nodes[0])){

            Type* relationType_ = this->getReturnType("visitT_XOR");
            if(visitExpression(node->nodes[1])){
                Type* expressionType_ = this->getReturnType("visitT_XOR");

                if (compareTypes(relationType_, new TypeBool()) == false){
                    cout << "Error: incorrect expression type " << "visitT_XOR" << endl;
                    exit(1);
                }
                if (compareTypes(relationType_, expressionType_) == false){
                    cout << "Error: incorrect expression type " << "visitT_XOR" << endl;
                    exit(1);
                }

                this->returnType = new TypeBool();
                if (DEBUG)
                    cout << "return true; T_XOR" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_XOR Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_XOR Error" << endl;
            exit(1);
            return false;
        }
        if (DEBUG)
            cout << "return true; T_XOR" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool Visitor::visitRelation(Node *node){
    if (DEBUG)
        cout << "Enter; Relation" << endl; /*DEBUG*/

    if (visitSimple(node) || visitT_LESS(node) || visitT_LESSOREQU(node) || visitT_GREAT(node) || visitT_GREATOREQU(node) || visitT_EQU(node) || visitT_NOTEQU(node)){
        if (DEBUG)
            cout << "return true; Relation" << endl; /*DEBUG*/
        return true;
    }else{
        // cout << "visitRelation " << endl;
        // exit(1);
        return false;
    }
}

bool Visitor::visitT_LESS(Node *node){
    if (DEBUG)
        cout << "Enter; T_LESS" << endl; /*DEBUG*/

    if (node->token.token == T_LESS){
        if (visitSimple(node->nodes[0])){

            Type* simpleType_1 = this->getReturnType("visitT_LESS");
            if (visitSimple(node->nodes[1])){
                Type* simpleType_2 = this->getReturnType("visitT_LESS");

                if(compareTypes(simpleType_1, simpleType_2) == false){
                    cout << "Error: incorrect relation types " << "visitT_LESS" << endl;
                    exit(1);
                }

                this->returnType = new TypeBool();
                if (DEBUG)
                    cout << "return true; T_LESS" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_LESS Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_LESS Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}
bool Visitor::visitT_LESSOREQU(Node *node){
    if (DEBUG)
        cout << "Enter; T_LESSOREQU" << endl; /*DEBUG*/

    if (node->token.token == T_LESSOREQU){
        if (visitSimple(node->nodes[0])){

            Type* simpleType_1 = this->getReturnType("visitT_LESSOREQU");
            if (visitSimple(node->nodes[1])){
                Type* simpleType_2 = this->getReturnType("visitT_LESSOREQU");

                if(compareTypes(simpleType_1, simpleType_2) == false){
                    cout << "Error: incorrect relation types " << "visitT_LESSOREQU" << endl;
                    exit(1);
                }
                
                this->returnType = new TypeBool();
                if (DEBUG)
                    cout << "return true; T_LESSOREQU" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "visitT_LESSOREQU Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "visitT_LESSOREQU Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}
bool Visitor::visitT_GREAT(Node *node){
    if (DEBUG)
        cout << "Enter; T_GREAT" << endl; /*DEBUG*/

    if (node->token.token == T_GREAT){
        if (visitSimple(node->nodes[0])){

            Type* simpleType_1 = this->getReturnType("visitT_GREAT");
            if (visitSimple(node->nodes[1])){
                Type* simpleType_2 = this->getReturnType("visitT_GREAT");

                if(compareTypes(simpleType_1, simpleType_2) == false){
                    cout << "Error: incorrect relation types " << "visitT_GREAT" << endl;
                    exit(1);
                }

                this->returnType = new TypeBool();
                if (DEBUG)
                    cout << "return true; T_GREAT" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_GREAT Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_GREAT Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}
bool Visitor::visitT_GREATOREQU(Node *node){
    if (DEBUG)
        cout << "Enter; T_GREATOREQU" << endl; /*DEBUG*/

    if (node->token.token == T_GREATOREQU){
        if (visitSimple(node->nodes[0])){

            Type* simpleType_1 = this->getReturnType("visitT_GREATOREQU");
            if (visitSimple(node->nodes[1])){
                Type* simpleType_2 = this->getReturnType("visitT_GREATOREQU");

                if(compareTypes(simpleType_1, simpleType_2) == false){
                    cout << "Error: incorrect relation types " << "visitT_GREATOREQU" << endl;
                    exit(1);
                }

                this->returnType = new TypeBool();
                if (DEBUG)
                    cout << "return true; T_GREATOREQU" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_GREATOREQU Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_GREATOREQU Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitT_EQU(Node *node){
    if (DEBUG)
        cout << "Enter; T_EQU" << endl; /*DEBUG*/
    if (node->token.token == T_EQU){
        if (visitSimple(node->nodes[0])){

            Type* simpleType_1 = this->getReturnType("visitT_EQU");
            if (visitSimple(node->nodes[1])){
                Type* simpleType_2 = this->getReturnType("visitT_EQU");

                if(compareTypes(simpleType_1, simpleType_2) == false){
                    cout << "Error: incorrect relation types " << "visitT_EQU" << endl;
                    exit(1);
                }
                this->returnType = new TypeBool();
                if (DEBUG)
                    cout << "return true; T_EQU" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_EQU Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_EQU Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}
bool Visitor::visitT_NOTEQU(Node *node){
    if (DEBUG)
        cout << "Enter; T_NOTEQU" << endl; /*DEBUG*/

    if (node->token.token == T_NOTEQU){
        if (visitSimple(node->nodes[0])){

            Type* simpleType_1 = this->getReturnType("visitT_NOTEQU");
            if (visitSimple(node->nodes[1])){
                Type* simpleType_2 = this->getReturnType("visitT_NOTEQU");

                if(compareTypes(simpleType_1, simpleType_2) == false){
                    cout << "Error: incorrect relation types " << "visitT_NOTEQU" << endl;
                    exit(1);
                }
                this->returnType = new TypeBool();
                if (DEBUG)
                    cout << "return true; T_NOTEQU" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_NOTEQU Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_NOTEQU Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitSimple(Node *node){
    if (DEBUG)
        cout << "Enter; Simple" << endl; /*DEBUG*/

    if (visitFactor(node) || visitT_MULTOP(node) || visitT_DIVOP(node) || visitT_MODOP(node)){
        if (DEBUG)
            cout << "return true; Simple" << endl; /*DEBUG*/
        return true;
    }else{
        // cout << "visitSimple Error" << endl;
        // exit(1);
        return false;
    }
}

bool Visitor::visitT_MULTOP(Node *node){
    if (DEBUG)
        cout << "Enter; T_MULTOP" << endl; /*DEBUG*/

    if (node->token.token == T_MULTOP){
        if (visitFactor(node->nodes[0])){

            Type* factorType_1 = this->getReturnType("visitT_MULTOP");
            if(visitSimple(node->nodes[1])){
                Type* factorType_2 = this->getReturnType("visitT_MULTOP");

                if(compareTypes(factorType_1, factorType_2) == false){
                    cout << "Error: incorrect simple types " << "visitT_MULTOP" << endl;
                    exit(1);
                }
                
                this->returnType = factorType_2;
                if (DEBUG)
                    cout << "return true; T_MULTOP" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_MULTOP Error" << endl;
                exit(1);
                return false;
            }
        }
    }
    return false;
}
bool Visitor::visitT_DIVOP(Node *node){
    if (DEBUG)
        cout << "Enter; T_DIVOP" << endl; /*DEBUG*/

    if (node->token.token == T_DIVOP){
        if (visitFactor(node->nodes[0])){

            Type* factorType_1 = this->getReturnType("visitT_MULTOP");
            if(visitSimple(node->nodes[1])){
                Type* factorType_2 = this->getReturnType("visitT_MULTOP");

                if(compareTypes(factorType_1, factorType_2) == false){
                    cout << "Error: incorrect simple types " << "visitT_MULTOP" << endl;
                    exit(1);
                }

                this->returnType = factorType_2;
                if (DEBUG)
                    cout << "return true; T_DIVOP" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_DIVOP Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_DIVOP Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}
bool Visitor::visitT_MODOP(Node *node){
    if (DEBUG)
        cout << "Enter; T_MODOP" << endl; /*DEBUG*/

    if (node->token.token == T_MODOP){
        if (visitFactor(node->nodes[0])){

            Type* factorType_1 = this->getReturnType("visitT_MODOP");
            if(visitSimple(node->nodes[1])){
                Type* factorType_2 = this->getReturnType("visitT_MODOP");

                if(compareTypes(factorType_1, factorType_2) == false){
                    cout << "Error: incorrect simple types " << "visitT_MODOP" << endl;
                    exit(1);
                }

                this->returnType = factorType_2;
                if (DEBUG)
                    cout << "return true; T_MODOP" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_MODOP Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_MODOP Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitFactor(Node *node){
    if (DEBUG)
        cout << "Enter; Factor" << endl; /*DEBUG*/

    if (visitSummand(node) || visitT_ADDOP(node) || visitT_SUBTROP(node)){
        if (DEBUG)
            cout << "return true; Factor" << endl; /*DEBUG*/
        return true;
    }else{
        // cout << "Factor Error" << endl;
        // exit(1);
        return false;
    }
}
bool Visitor::visitT_ADDOP(Node *node){
    if (DEBUG)
        cout << "Enter; T_ADDOP" << endl; /*DEBUG*/

    if (node->token.token == T_ADDOP){
        if (visitSummand(node->nodes[0])){

            Type* summandType_ = this->getReturnType("visitT_ADDOP");
            if(visitFactor(node->nodes[1])){
                Type* factorType_ = this->getReturnType("visitT_ADDOP");
                
                if(compareTypes(factorType_, summandType_) == false){
                    cout << "Error: incorrect factor types " << "visitT_ADDOP" << endl;
                    exit(1);
                }

                this->returnType = summandType_;
                if (DEBUG)
                    cout << "return true; T_ADDOP" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_ADDOP Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_ADDOP Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitT_SUBTROP(Node *node){
    if (DEBUG)
        cout << "Enter; T_SUBTROP" << endl; /*DEBUG*/

    if (node->token.token == T_SUBTROP){
        if (visitSummand(node->nodes[0])){

            Type* summandType_ = this->getReturnType("visitT_SUBTROP");
            if(visitFactor(node->nodes[1])){
                Type* factorType_ = this->getReturnType("visitT_SUBTROP");
                
                if(compareTypes(factorType_, summandType_) == false){
                    cout << "Error: incorrect factor types " << "visitT_SUBTROP" << endl;
                    exit(1);
                }

                this->returnType = summandType_;
                if (DEBUG)
                    cout << "return true; T_SUBTROP" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_SUBTROP Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_SUBTROP Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitSummand(Node *node){
    if (DEBUG)
        cout << "Enter; Summand" << endl; /*DEBUG*/
    
    if (visitPrimary(node) || visitT_PARENT(node)){
        if (DEBUG)
            cout << "return true; Summand" << endl; /*DEBUG*/
        return true;
    }else{
        // cout << "Summand Error" << endl;
        // exit(1);
        return false;
    }
}
bool Visitor::visitT_PARENT(Node *node){
    if (DEBUG)
        cout << "Enter; T_PARENT" << endl; /*DEBUG*/

    if (node->token.token == T_PARENT){
        if (visitExpression(node->nodes[0])){
            if (DEBUG)
                cout << "return true; T_PARENT" << endl; /*DEBUG*/
            return true;
        }else{
            cout << "T_PARENT Error" << endl;
            exit(1);
            return false;
        }
    }else{
        // cout << "T_PARENT Error" << endl;
        // exit(1);
        return false;
    }
}

bool Visitor::visitPrimary(Node *node){
    if (DEBUG)
        cout << "Enter; Primary" << endl; /*DEBUG*/

    if (visitT_ICONST(node) || visitT_CCONST(node) || visitT_RCONST(node) || visitT_TRUE(node) || visitT_FALSE(node) || visitModifiablePrimary(node)){
        if (DEBUG)
            cout << "return true; Primary" << endl; /*DEBUG*/
        return true;
    }else{
        // cout << "Primary Error" << endl;
        // exit(1);
        return false;
    }
}
bool Visitor::visitT_ICONST(Node *node){
    if (DEBUG)
        cout << "Enter; T_ICONST" << endl; /*DEBUG*/

    if (node->token.token == T_ICONST){
        this->returnType = new TypeInteger();
        if (DEBUG)
            cout << "return true; T_ICONST" << endl; /*DEBUG*/
        return true;
    }
    return false;
}
bool Visitor::visitT_CCONST(Node *node){
    if (DEBUG)
        cout << "Enter; T_CCONST" << endl; /*DEBUG*/

    if (node->token.token == T_CCONST){
        this->returnType = new TypeChar();
        if (DEBUG)
            cout << "return true; T_CCONST" << endl; /*DEBUG*/
        return true;
    }
    return false;
}
bool Visitor::visitT_RCONST(Node *node){
    if (DEBUG)
        cout << "Enter; T_RCONST" << endl; /*DEBUG*/

    if (node->token.token == T_RCONST){
        this->returnType = new TypeReal();
        if (DEBUG)
            cout << "return true; T_RCONST" << endl; /*DEBUG*/
        return true;
    }
    return false;
}
bool Visitor::visitT_TRUE(Node *node){
    if (DEBUG)
        cout << "Enter; T_TRUE" << endl; /*DEBUG*/

    if (node->token.token == T_TRUE){
        this->returnType = new TypeBool();
        if (DEBUG)
            cout << "return true; T_TRUE" << endl; /*DEBUG*/
        return true;
    }
    return false;
}
bool Visitor::visitT_FALSE(Node *node){
    if (DEBUG)
        cout << "Enter; T_FALSE" << endl; /*DEBUG*/

    if (node->token.token == T_FALSE){
        this->returnType = new TypeBool();
        if (DEBUG)
            cout << "return true; T_FALSE" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

// bool Visitor::visitModifiablePrimary(Node *node){
//     if (DEBUG)
//         cout << "Enter; ModifiablePrimary" << endl; /*DEBUG*/

//     if (visitID_ARRAY(node) || visitT_DOT(node)){
//         if (DEBUG)
//             cout << "return true; ModifiablePrimary" << endl; /*DEBUG*/
//         return true;
//     }else{
//         // cout << "ModifiablePrimary Error " << endl;
//         // exit(1);
//         return false;
//     }
// }

// bool Visitor::visitT_DOT(Node *node){
//     if (DEBUG)
//         cout << "Enter; T_DOT" << endl; /*DEBUG*/

//     if (node->token.token == T_DOT){

//         if (visitID_ARRAY(node->nodes[0])){
//             Type* id_arrayType;
//             TypeRecord* id_arrayRecordType;
//             if (this->inType == nullptr){
//                 id_arrayType = this->getReturnType("visitT_DOT");
//                 if (id_arrayType->getName() == "record"){
//                     id_arrayRecordType = (TypeRecord *)id_arrayType;
//                 }

//                 this->inType = id_arrayType;
//             }
//             else{
//                 string idArrayName = this->varName;

//             }
            
//             if (visitModifiablePrimary(node->nodes[1])){
//                 string dotName = this->varName;

//                 for (int i = 0; i < id_arrayRecordType->names.size(); ++i){
//                     if (id_arrayRecordType->names[i] == dotName){
//                         this->returnType = id_arrayRecordType->listtype_->types_[i];
//                         break;
//                     }
//                 }


//                 if (DEBUG)
//                     cout << "return true; T_DOT" << endl; /*DEBUG*/
//                 return true;
//             }else{
//                 cout << "T_DOT Error" << endl;
//                 exit(1);
//                 return false;
//             }
//         }else{
//             cout << "T_DOT Error" << endl;
//             exit(1);
//             return false;
//         }
//     }
//     return false;
// }

bool Visitor::visitModifiablePrimary(Node *node){
    if (DEBUG)
        cout << "Enter; ModifiablePrimary" << endl; /*DEBUG*/

    if (visitID_ARRAY(node) || visitT_DOT(node)){
        this->inType = nullptr;
        if (DEBUG)
            cout << "return true; ModifiablePrimary" << endl; /*DEBUG*/
        return true;
    }else{
        // cout << "ModifiablePrimary Error " << endl;
        // exit(1);
        return false;
    }
}

bool Visitor::visitT_DOT(Node *node){
    if (DEBUG)
        cout << "Enter; T_DOT" << endl; /*DEBUG*/
    
    if (node->token.token == T_DOT){

        if (visitID_ARRAY(node->nodes[0])){

            if (node->nodes.size() == 1){
                return true;
            }
            if (node->nodes.size() > 1 && visitModifiablePrimary(node->nodes[1])){

                if (DEBUG)
                    cout << "return true; T_DOT" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_DOT Error1" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_DOT Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool Visitor::visitID_ARRAY(Node *node){
    if (DEBUG)
        cout << "Enter; ID_ARRAY" << endl; /*DEBUG*/

    cout << node->token.lexeme << "()()()()()()(           )()()()()()()" << endl;
    if (visitT_ID_define(node)){
        string idName = this->varName;
        if (this->inType == nullptr){
            visitT_ID_use(node);
            Type* idType = this->getReturnType("visitID_ARRAY");
            this->inType = idType;
            cout << idName << endl;
            cout << this->state[idName]->toString() << endl;
            cout << inType->toString() << "<><><><><><><><><><"<< endl;
        }
        else{
            Type* inType = this->inType; // c.a.b <- c.a type OR c.a.b <- c type
            
            TypeRecord* inRecordType;
            if (inType->getName() == "record"){
                inRecordType = (TypeRecord *)inType;
            }
            else{
                cout << inType->toString() << endl;
                cout << "Error: expected record type, but get somth else" << endl;
                exit(1);
            }
            for (int i = 0; i < inRecordType->names.size(); i++){
                if (inRecordType->names[i] == idName){
                    this->returnType = inRecordType->listtype_->types_[i];
                    this->inType = this->returnType;
                    break;
                }
            }
        }


        if (DEBUG)
            cout << "return true; ID_ARRAY" << endl; /*DEBUG*/
        return true;
    }
    // OR
    if (visitT_BRACKS(node)){

        if (DEBUG)
            cout << "return true; ID_ARRAY" << endl; /*DEBUG*/
        return true;
    }else{
        // cout << "visitSimple " << endl;
        // exit(1);
        return false;
    }
}

bool Visitor::visitT_BRACKS(Node *node){
    if (DEBUG)
        cout << "Enter; T_BRACKS" << endl; /*DEBUG*/

    if (node->token.token == T_BRACKS){

        if (node->nodes.size() == 2 && visitT_ID_define(node->nodes[0])){
            
            if (visitExpression(node->nodes[1])){
                Type * exprType = this->getReturnType("visitT_BRACKS");

                if (compareTypes(exprType, new TypeInteger) == false){
                    cout << "Error: incorrect factor types " << "visitT_SUBTROP" << endl;
                    exit(1);  
                } 
            }

            if (DEBUG)
                cout << "return true; T_BRACKS" << endl; /*DEBUG*/
            return true;
        }else if (node->nodes.size() == 3 && visitT_ID_define(node->nodes[0])){
            
            if (visitExpression(node->nodes[1])){
                Type * exprType = this->getReturnType("visitT_BRACKS");

                if (compareTypes(exprType, new TypeInteger) == false){
                    cout << "Error: incorrect factor types " << "visitT_SUBTROP" << endl;
                    exit(1);  
                } 
                if (visitT_BRACKS(node->nodes[2])){
                
                }
            }

            if (DEBUG)
                cout << "return true; T_BRACKS" << endl; /*DEBUG*/
            return true;
        }else if (node->nodes.size() == 1 && visitExpression(node->nodes[0])){
            Type * exprType = this->getReturnType("visitT_BRACKS");

            if (compareTypes(exprType, new TypeInteger) == false){
                cout << "Error: incorrect factor types " << "visitT_SUBTROP" << endl;
                exit(1);  
            } 
            if (DEBUG)
                cout << "return true; T_BRACKS" << endl; /*DEBUG*/
            return true;
        }else if (node->nodes.size() == 2 && visitExpression(node->nodes[0])){
            Type * exprType = this->getReturnType("visitT_BRACKS");

            if (compareTypes(exprType, new TypeInteger) == false){
                cout << "Error: incorrect factor types " << "visitT_SUBTROP" << endl;
                exit(1);  
            } 
            if (visitT_BRACKS(node->nodes[1])){

            }
            if (DEBUG)
                cout << "return true; T_BRACKS" << endl; /*DEBUG*/
            return true;
        }
        return false;
    }
    return false;
}