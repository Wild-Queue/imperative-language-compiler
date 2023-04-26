#include "CodeGenerator.h"
#include "TypeClass.h"
#include <iostream>
#include <string>
using namespace std;


bool CodeGenerator::visitProgram(Node *node){
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
bool CodeGenerator::visitSimpleDeclaration(Node *node){
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

bool CodeGenerator::visitVariableDeclaration(Node *node){
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
bool CodeGenerator::visitTypeDeclaration(Node *node){
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

bool CodeGenerator::visitRoutineDeclaration(Node *node){
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

bool CodeGenerator::visitT_VAR_DECL_COLON_IS(Node *node){
    if (DEBUG)
        cout << "Enter; T_VAR_DECL_COLON_IS" << endl; /*DEBUG*/

    if (node->token.token == T_VAR_DECL_COLON_IS){
        if (visitT_ID_define(node->nodes[0])){

            if (visitType(node->nodes[1]) && visitExpression(node->nodes[2])){
                if (DEBUG)
                    cout << "return true; T_VAR_DECL_COLON_IS" << endl; /*DEBUG*/

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

bool CodeGenerator::visitT_VAR_DECL_COLON(Node *node){
    if (DEBUG)
        cout << "Enter; T_VAR_DECL_COLON" << endl; /*DEBUG*/

    if (node->token.token == T_VAR_DECL_COLON){
        if (visitT_ID_define(node->nodes[0])){
                if (visitType(node->nodes[1])){
                
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
bool CodeGenerator::visitT_VAR_DECL_IS(Node *node){
    if (DEBUG)
        cout << "Enter; T_VAR_DECL_IS" << endl; /*DEBUG*/

    if (node->token.token == T_VAR_DECL_IS){
        if (visitT_ID_define(node->nodes[0])){

            if (visitExpression(node->nodes[1])){

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

bool CodeGenerator::visitT_TYPE_DECL_IS(Node *node){
    if (DEBUG)
        cout << "Enter; T_TYPE_DECL_IS" << endl; /*DEBUG*/

    if (node->token.token == T_TYPE_DECL_IS){
        if (visitT_ID_define(node->nodes[0])){
            if(visitType(node->nodes[1])){

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

bool CodeGenerator::visitT_ROUTIN_DECL_TYPE(Node *node){
    if (DEBUG)
        cout << "Enter; T_ROUTIN_DECL_TYPE" << endl; /*DEBUG*/

    if (node->token.token == T_ROUTIN_DECL_TYPE){
        if (node->nodes.size() > 3){
            if (visitT_ID_define(node->nodes[0])){
                if (visitParameters(node->nodes[1]) && visitType(node->nodes[2])){
                    if (visitBody(node->nodes[3])){
                    }
                
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
                if (visitParameters(node->nodes[1]) && visitType(node->nodes[2])){
                    if (DEBUG)
                        cout << "return true; T_ROUTIN_DECL_TYPE" << endl; /*DEBUG*/
                    
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

bool CodeGenerator::visitT_ROUTIN_DECL(Node *node){

    if (node->token.token == T_ROUTIN_DECL){
        if (DEBUG)
            cout << "Enter; T_ROUTIN_DECL" << endl; /*DEBUG*/
        
        if (visitT_ID_define(node->nodes[0])){
            if (visitParameters(node->nodes[1])){
                if(visitBody(node->nodes[2])){
                    
                    
                    if (DEBUG)
                        cout << "return true; T_ROUTIN_DECL" << endl; /*DEBUG*/
                    return true;
                }
            }
        }else{
            cout << "T_ROUTIN_DECL Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}

bool CodeGenerator::visitParameters(Node *node){
    if (DEBUG)
        cout << "Enter; Parameters" << endl; /*DEBUG*/

    if (node->token.token == T_PARAMETERS){
        if (visitParameterDeclaration(node->nodes[0])){
            if (node->nodes.size() > 1){
                
                for (auto iterator : vector<Node *>(node->nodes.begin() + 1, node->nodes.end())){
                    if (visitParameterDeclaration(iterator)){
                        
                        continue;
                    }else
                        return false;
                }
            }

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
bool CodeGenerator::visitParameterDeclaration(Node *node){
    if (DEBUG)
        cout << "Enter; ParameterDeclaration" << endl; /*DEBUG*/

    if (node->token.token == T_COLON){
        if (visitT_ID_define(node->nodes[0])){
            if (visitType(node->nodes[1])){

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

bool CodeGenerator::visitParameterDeclarations(Node *node){
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

bool CodeGenerator::visitType(Node *node){
    if (DEBUG)
        cout << "Enter; Type" << endl; /*DEBUG*/

    if (visitPrimitiveType(node) 
            || visitArrayType(node) 
                || visitRecordType(node) 
                    || visitT_ID_use(node)){
        if (visitT_ID_use(node)){
        }
        if (DEBUG)
            cout << "return true; Type" << endl; /*DEBUG*/
        return true;
    }else
        return false;
}

bool CodeGenerator::visitPrimitiveType(Node *node){
    if (DEBUG)
        cout << "Enter; PrimitiveType" << endl; /*DEBUG*/

    if (node->token.token == T_INTEGER 
            || node->token.token == T_REAL 
                || node->token.token == T_BOOLEAN 
                    || node->token.token == T_CHAR){
        switch (node->token.token){
        case T_INTEGER:
            
            break;
        case T_REAL:
            
            break;
        case T_BOOLEAN:
            
            break;
        case T_CHAR:
            
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

bool CodeGenerator::visitArrayType(Node *node){
    if (DEBUG)
        cout << "Enter; ArrayType" << endl; /*DEBUG*/

    if (node->token.token == T_ARRAY){
        if (visitExpression(node->nodes[0]) && visitType(node->nodes[1])){
            
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

bool CodeGenerator::visitRecordType(Node *node){
    if (DEBUG)
        cout << "Enter; RecordType" << endl; /*DEBUG*/

    if (node->token.token == T_RECORD){
        for (auto iterator : node->nodes){
            if (visitVariableDeclaration(iterator)){
                continue;
            }else
                return false;   
        }

        if (DEBUG)
            cout << "return true; RecordType" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool CodeGenerator::visitT_ID_define(Node *node){
    if (DEBUG)
        cout << "Enter; T_ID " << node->token.lexeme << endl; /*DEBUG*/

    if (node->token.token == T_ID){
        
        if (DEBUG)
            cout << "return true; T_ID" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool CodeGenerator::visitT_ID_use(Node *node){
    if (DEBUG)
        cout << "Enter; T_ID " << node->token.lexeme << endl; /*DEBUG*/

    if (node->token.token == T_ID){

        if (DEBUG)
            cout << "return true; T_ID" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool CodeGenerator::visitBody(Node *node){
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

bool CodeGenerator::visitStatement(Node *node){
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

bool CodeGenerator::visitT_RETURN(Node *node){
    if (DEBUG)
        cout << "Enter; T_RETURN" << endl; /*DEBUG*/

    if (node->token.token == T_RETURN){
        if (visitExpression(node->nodes[0])){

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

bool CodeGenerator::visitT_PRINT(Node *node){
    if (DEBUG)
        cout << "Enter; T_PRINT" << endl; /*DEBUG*/

    if (node->token.token == T_PRINT){
        if (visitExpression(node->nodes[0])){

            

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

bool CodeGenerator::visitIfStatement(Node *node){
    if (DEBUG)
        cout << "Enter; IfStatement" << endl; /*DEBUG*/

    if (visitT_IF_ELSE(node) || visitT_IF(node)){
        if (DEBUG)
            cout << "return true; IfStatement" << endl; /*DEBUG*/
        return true;
    }else
        return false;
}

bool CodeGenerator::visitT_IF_ELSE(Node *node){
    if (DEBUG)
        cout << "Enter; T_IF_ELSE" << endl; /*DEBUG*/

    if (node->token.token == T_IF_ELSE){
        if (visitExpression(node->nodes[0])){
            if ( visitBody(node->nodes[1]) && visitBody(node->nodes[2])){
                

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

bool CodeGenerator::visitT_IF(Node *node){
    if (DEBUG)
        cout << "Enter; T_IF" << endl; /*DEBUG*/
                                       // Node
    
    if (node->token.token == T_IF){
        if (visitExpression(node->nodes[0])){
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

bool CodeGenerator::visitForLoop(Node *node){
    if (DEBUG)
        cout << "Enter; ForLoop" << endl; /*DEBUG*/

    if (node->token.token == T_FOR){
        if (visitT_ID_define(node->nodes[0])){
            
            if (visitRange(node->nodes[1]) && visitBody(node->nodes[2])){

                if (DEBUG)
                    cout << "return true; ForLoop" << endl; /*DEBUG*/
                return true;
            }else{
                cout << "T_FOR Error" << endl;
                exit(1);
                return false;
            }
        }else{
            cout << "T_FOR Error" << endl;
            exit(1);
            return false;
        }
    }
    return false;
}
bool CodeGenerator::visitRange(Node *node){
    if (DEBUG)
        cout << "Enter; Range" << endl; /*DEBUG*/

    if (visitT_IN(node) || visitT_IN_REVERSE(node)){
        if (DEBUG)
            cout << "return true; Range" << endl; /*DEBUG*/
        return true;
    }else
        return false;
}

bool CodeGenerator::visitT_IN(Node *node){
    if (DEBUG)
        cout << "Enter; T_IN" << endl; /*DEBUG*/

    if (node->token.token == T_IN){
        if (visitExpression(node->nodes[0])){
            if (visitExpression(node->nodes[1])){

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

bool CodeGenerator::visitT_IN_REVERSE(Node *node){
    if (DEBUG)
        cout << "Enter; T_IN_REVERSE" << endl; /*DEBUG*/

    if (node->token.token == T_IN_REVERSE){
        if (DEBUG)
            cout << "return true; T_IN_REVERSE" << endl; /*DEBUG*/

        if (visitExpression(node->nodes[0])){

            if (visitExpression(node->nodes[1])){
                
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

bool CodeGenerator::visitWhileLoop(Node *node){
    if (DEBUG)
        cout << "Enter; WhileLoop" << endl; /*DEBUG*/

    if (node->token.token == T_WHILE){
        if (visitExpression(node->nodes[0])){
            
            if (visitBody(node->nodes[1])){
                

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

bool CodeGenerator::visitRoutineCall(Node *node){
    if (DEBUG)
        cout << "Enter; RoutineCall" << endl; /*DEBUG*/

    // Node
    if (node->token.token == T_ROUTINE_CALL){
        if (visitT_ID_use(node->nodes[0])){
            
            for (auto iterator : vector<Node *>(node->nodes.begin() + 1, node->nodes.end())){
                if (visitExpression(iterator)){
                    
                    continue;
                }else{
                    return false;
                }
            }


            if (DEBUG)
                cout << "return true; RoutineCall" << endl; /*DEBUG*/
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

bool CodeGenerator::visitAssignment(Node *node){
    if (DEBUG)
        cout << "Enter; Assignment" << endl; /*DEBUG*/

    if (node->token.token == T_COLONEQU){
        if (visitModifiablePrimary(node->nodes[0])){

            if (visitExpression(node->nodes[1])){

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

bool CodeGenerator::visitExpression(Node *node){
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

bool CodeGenerator::visitT_AND(Node *node){
    if (DEBUG)
        cout << "Enter; T_AND" << endl; /*DEBUG*/

    if (node->token.token == T_AND){
        if (visitRelation(node->nodes[0])){
            if(visitExpression(node->nodes[1])){


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

bool CodeGenerator::visitT_OR(Node *node){
    if (DEBUG)
        cout << "Enter; T_OR" << endl; /*DEBUG*/

    if (node->token.token == T_OR){
        if (visitRelation(node->nodes[0])){
            if(visitExpression(node->nodes[1])){


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

bool CodeGenerator::visitT_XOR(Node *node){
    if (DEBUG)
        cout << "Enter; T_XOR" << endl; /*DEBUG*/

    if (node->token.token == T_XOR){
        if (visitRelation(node->nodes[0])){
            if(visitExpression(node->nodes[1])){


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

bool CodeGenerator::visitRelation(Node *node){
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

bool CodeGenerator::visitT_LESS(Node *node){
    if (DEBUG)
        cout << "Enter; T_LESS" << endl; /*DEBUG*/

    if (node->token.token == T_LESS){
        if (visitSimple(node->nodes[0])){
            if (visitSimple(node->nodes[1])){


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
bool CodeGenerator::visitT_LESSOREQU(Node *node){
    if (DEBUG)
        cout << "Enter; T_LESSOREQU" << endl; /*DEBUG*/

    if (node->token.token == T_LESSOREQU){
        if (visitSimple(node->nodes[0])){
            if (visitSimple(node->nodes[1])){


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
bool CodeGenerator::visitT_GREAT(Node *node){
    if (DEBUG)
        cout << "Enter; T_GREAT" << endl; /*DEBUG*/

    if (node->token.token == T_GREAT){
        if (visitSimple(node->nodes[0])){
            if (visitSimple(node->nodes[1])){


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
bool CodeGenerator::visitT_GREATOREQU(Node *node){
    if (DEBUG)
        cout << "Enter; T_GREATOREQU" << endl; /*DEBUG*/

    if (node->token.token == T_GREATOREQU){
        if (visitSimple(node->nodes[0])){
            if (visitSimple(node->nodes[1])){


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

bool CodeGenerator::visitT_EQU(Node *node){
    if (DEBUG)
        cout << "Enter; T_EQU" << endl; /*DEBUG*/
    if (node->token.token == T_EQU){
        if (visitSimple(node->nodes[0])){
            if (visitSimple(node->nodes[1])){


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
bool CodeGenerator::visitT_NOTEQU(Node *node){
    if (DEBUG)
        cout << "Enter; T_NOTEQU" << endl; /*DEBUG*/

    if (node->token.token == T_NOTEQU){
        if (visitSimple(node->nodes[0])){
            if (visitSimple(node->nodes[1])){


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

bool CodeGenerator::visitSimple(Node *node){
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

bool CodeGenerator::visitT_MULTOP(Node *node){
    if (DEBUG)
        cout << "Enter; T_MULTOP" << endl; /*DEBUG*/

    if (node->token.token == T_MULTOP){
        if (visitFactor(node->nodes[0])){
            if(visitSimple(node->nodes[1])){


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
bool CodeGenerator::visitT_DIVOP(Node *node){
    if (DEBUG)
        cout << "Enter; T_DIVOP" << endl; /*DEBUG*/

    if (node->token.token == T_DIVOP){
        if (visitFactor(node->nodes[0])){
            if(visitSimple(node->nodes[1])){


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
bool CodeGenerator::visitT_MODOP(Node *node){
    if (DEBUG)
        cout << "Enter; T_MODOP" << endl; /*DEBUG*/

    if (node->token.token == T_MODOP){
        if (visitFactor(node->nodes[0])){
            if(visitSimple(node->nodes[1])){



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

bool CodeGenerator::visitFactor(Node *node){
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
bool CodeGenerator::visitT_ADDOP(Node *node){
    if (DEBUG)
        cout << "Enter; T_ADDOP" << endl; /*DEBUG*/

    if (node->token.token == T_ADDOP){
        if (visitSummand(node->nodes[0])){
            if(visitFactor(node->nodes[1])){


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

bool CodeGenerator::visitT_SUBTROP(Node *node){
    if (DEBUG)
        cout << "Enter; T_SUBTROP" << endl; /*DEBUG*/

    if (node->token.token == T_SUBTROP){
        if (visitSummand(node->nodes[0])){
            if(visitFactor(node->nodes[1])){


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

bool CodeGenerator::visitSummand(Node *node){
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
bool CodeGenerator::visitT_PARENT(Node *node){
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

bool CodeGenerator::visitPrimary(Node *node){
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
bool CodeGenerator::visitT_ICONST(Node *node){
    if (DEBUG)
        cout << "Enter; T_ICONST" << endl; /*DEBUG*/

    if (node->token.token == T_ICONST){

        if (DEBUG)
            cout << "return true; T_ICONST" << endl; /*DEBUG*/
        return true;
    }
    return false;
}
bool CodeGenerator::visitT_CCONST(Node *node){
    if (DEBUG)
        cout << "Enter; T_CCONST" << endl; /*DEBUG*/

    if (node->token.token == T_CCONST){

        if (DEBUG)
            cout << "return true; T_CCONST" << endl; /*DEBUG*/
        return true;
    }
    return false;
}
bool CodeGenerator::visitT_RCONST(Node *node){
    if (DEBUG)
        cout << "Enter; T_RCONST" << endl; /*DEBUG*/

    if (node->token.token == T_RCONST){

        if (DEBUG)
            cout << "return true; T_RCONST" << endl; /*DEBUG*/
        return true;
    }
    return false;
}
bool CodeGenerator::visitT_TRUE(Node *node){
    if (DEBUG)
        cout << "Enter; T_TRUE" << endl; /*DEBUG*/

    if (node->token.token == T_TRUE){

        if (DEBUG)
            cout << "return true; T_TRUE" << endl; /*DEBUG*/
        return true;
    }
    return false;
}
bool CodeGenerator::visitT_FALSE(Node *node){
    if (DEBUG)
        cout << "Enter; T_FALSE" << endl; /*DEBUG*/

    if (node->token.token == T_FALSE){

        if (DEBUG)
            cout << "return true; T_FALSE" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

// bool CodeGenerator::visitModifiablePrimary(Node *node){
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

// bool CodeGenerator::visitT_DOT(Node *node){
//     if (DEBUG)
//         cout << "Enter; T_DOT" << endl; /*DEBUG*/

//     if (node->token.token == T_DOT){

//         if (visitID_ARRAY(node->nodes[0])){
//             if (visitModifiablePrimary(node->nodes[1])){


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


bool CodeGenerator::visitModifiablePrimary(Node *node){
    if (DEBUG)
        cout << "Enter; ModifiablePrimary" << endl; /*DEBUG*/

    if (visitID_ARRAY(node) || visitT_DOT(node)){


        if (DEBUG)
            cout << "return true; ModifiablePrimary" << endl; /*DEBUG*/
        return true;
    }else{
        // cout << "ModifiablePrimary Error " << endl;
        // exit(1);
        return false;
    }
}

bool CodeGenerator::visitT_DOT(Node *node){
    if (DEBUG)
        cout << "Enter; T_DOT" << endl; /*DEBUG*/
    
    if (node->token.token == T_DOT){

        if (visitID_ARRAY(node->nodes[0])){

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

bool CodeGenerator::visitID_ARRAY(Node *node){
    if (DEBUG)
        cout << "Enter; ID_ARRAY" << endl; /*DEBUG*/

    if (visitT_ID_define(node)){


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

bool CodeGenerator::visitT_BRACKS(Node *node){
    if (DEBUG)
        cout << "Enter; T_BRACKS" << endl; /*DEBUG*/

    if (node->token.token == T_BRACKS){

        if (node->nodes.size() == 2 && visitT_ID_define(node->nodes[0])){
            
            if (visitExpression(node->nodes[1])){

            }

            if (DEBUG)
                cout << "return true; T_BRACKS" << endl; /*DEBUG*/
            return true;
        }else if (node->nodes.size() == 3 && visitT_ID_define(node->nodes[0])){
            
            if (visitExpression(node->nodes[1])){
                if (visitT_BRACKS(node->nodes[2])){
                
                }
            }

            if (DEBUG)
                cout << "return true; T_BRACKS" << endl; /*DEBUG*/
            return true;
        }else if (node->nodes.size() == 1 && visitExpression(node->nodes[0])){


            if (DEBUG)
                cout << "return true; T_BRACKS" << endl; /*DEBUG*/
            return true;
        }else if (node->nodes.size() == 2 && visitExpression(node->nodes[0])){


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