#include "CodeGenerator.h"
#include "../TypeClass.h"
#include <iostream>
#include <string>
using namespace std;


string convertType(string type){
    if (type.find("int") != std::string::npos){
        return "int32";
    }
    if (type.find("double") != std::string::npos){

    }
    if (type.find("char") != std::string::npos){

    }
    if (type.find("bool") != std::string::npos){

    }
    return "float32";
}

string convertValueToType(string value){
    if(value == "true" || value == "false"){
        return "bool";
    }

    if(value.find(".") != std::string::npos){
        if(value.size() == 1){
            return "char";
        }else{
            bool checker = false;
            for(int i = 0;i < value.size();i++){
                if(!(int('0') <= int(value[i]) && int(value[i]) <= int('9'))){
                    checker = true;   
                }
            }
            if(checker){
                cout << "Error: type of constant can not be identified" << endl;
                exit(1);
            }else{
                if(int('0') <= int(value[0]) && int(value[0]) <= int('9') && int('0') <= int(value[value.size()-1]) && int(value[value.size()-1]) <= int('9')){
                    return "float32";
                }else{
                    cout << "Error: type of constant can not be identified" << endl;
                    exit(1);
                }
            }
        }
    }else{
        if(value.size() == 1){
            if((int('0') <= int(value[0]) && int(value[0]) <= int('9'))){
                return "int32";
            }else{
                return "char";
            }
        }else{
            bool checker = false;
            for(int i = 0;i < value.size();i++){
                if(!(int('0') <= int(value[i]) && int(value[i]) <= int('9'))){
                    checker = true;   
                }
            }
            if(checker){
                cout << "Error: type of constant can not be identified" << endl;
                exit(1);
            }else{
                if('0' != value[0]){
                    return "int32";
                }else{
                    cout << "Error: type of constant can not be identified" << endl;
                    exit(1);
                }
            }
        }
    }   
    cout << "Error: type of constant can not be identified" << endl;
    exit(1);
}

string convertTypeToStackLoad(string type){
    if (type == "int32"){
        return ".i4 ";
    }
    if (type == "float32"){
        return ".r4 ";
    }
    if (type == "bool"){
        return ".i4 ";
    }
    if (type == "char"){
        return ".i2 ";
    }
    return ".r4 ";
}

bool REALCodeGenerator::visitProgram(Node *node){
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
            
            string declaraion = this->getReturnString();
            this->main_body += declaraion;
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
bool REALCodeGenerator::visitSimpleDeclaration(Node *node){
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

bool REALCodeGenerator::visitVariableDeclaration(Node *node){
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
bool REALCodeGenerator::visitTypeDeclaration(Node *node){
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

bool REALCodeGenerator::visitRoutineDeclaration(Node *node){
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

bool REALCodeGenerator::visitT_VAR_DECL_COLON_IS(Node *node){
    if (DEBUG)
        cout << "Enter; T_VAR_DECL_COLON_IS" << endl; /*DEBUG*/

    if (node->token.token == T_VAR_DECL_COLON_IS){
        if (visitT_ID_define(node->nodes[0]) == false){
            cout << "T_VAR_DECL_COLON_IS Error 1" << endl;
            exit(1);
            return false;
        }
        string id_def = this->getReturnString();

        if (visitType(node->nodes[1]) == false){
            cout << "T_VAR_DECL_COLON_IS Error 2" << endl;
            exit(1);
            return false;
        }
        string type = this->getReturnString();
        
        if (visitExpression(node->nodes[2]) == false){
            cout << "T_VAR_DECL_COLON_IS Error 3" << endl;
            exit(1);
            return false;
        }
        string expr = this->getReturnString();

        //var x : integer is 5
        /*Convert to C# code*/
        // 
        
        
        this->var_to_num[id_def] = to_string(this->new_var_num);
        this->new_var_num++;
        
        string il_type = convertType(type);
        //.locals init ([0] int32 x)
        // ldc.i4 7 
        // stloc.0 
        string init_locals = ".locals init ([" + this->var_to_num[id_def] + "] " + il_type + " " + id_def + ")"+"\n";
        string load_to_var = "ldc" + convertTypeToStackLoad(il_type) + expr + "\n"; 
        load_to_var += "stloc." + this->var_to_num[id_def] + "\n"; 
        this->setReturnString(init_locals + load_to_var + "\n");
        this->state[id_def] = il_type;
        

        /*Example of C# code*/
        // int a = 1;
        // string b = "hello";
        // bool c = true;
        // float d = 1.0;
        // char e = 'a';
        // int[] f = {1,2,3};
        // string[] g = {"a","b","c"};
        

        if (DEBUG)
            cout << "return true; T_VAR_DECL_COLON_IS" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitT_VAR_DECL_COLON(Node *node){
    if (DEBUG)
        cout << "Enter; T_VAR_DECL_COLON" << endl; /*DEBUG*/

    if (node->token.token == T_VAR_DECL_COLON){
        if (visitT_ID_define(node->nodes[0]) == false){
            cout << "T_VAR_DECL_COLON Error" << endl;
            exit(1);
            return false;
        }
        string id_def = this->getReturnString();
        
        if (visitType(node->nodes[1]) == false){
            cout << "T_VAR_DECL_COLON Error" << endl;
            exit(1);
            return false;
        }
        string type = this->getReturnString();
        
        this->var_to_num[id_def] = to_string(this->new_var_num);
        this->new_var_num++;
        
        string il_type = convertType(type);
        //.locals init ([0] int32 x)
        string init_locals = ".locals init ([" + this->var_to_num[id_def] + "] " + il_type + " " + id_def + ")"+"\n";
        this->state[id_def] = il_type;
        this->setReturnString(init_locals + "\n");

        if (DEBUG)
            cout << "return true; T_VAR_DECL_COLON" << endl; /*DEBUG*/
        return true;
    }
    return false;
}
bool REALCodeGenerator::visitT_VAR_DECL_IS(Node *node){
    if (DEBUG)
        cout << "Enter; T_VAR_DECL_IS" << endl; /*DEBUG*/

    if (node->token.token == T_VAR_DECL_IS){
        if (visitT_ID_define(node->nodes[0]) == false)
        {
            cout << "T_VAR_DECL_IS Error" << endl;
            exit(1);
            return false;
        }
        string id_def = this->getReturnString();
        
        
        if (visitExpression(node->nodes[1]) == false){
            cout << "T_VAR_DECL_IS Error" << endl;
            exit(1);
            return false;
        }
        string expr = this->getReturnString();

/////////
        this->var_to_num[id_def] = to_string(this->new_var_num);
        this->new_var_num++;
        
        string il_type = convertValueToType(expr);
        //.locals init ([0] int32 x)
        // ldc.i4 7 
        // stloc.0 
        string init_locals = ".locals init ([" + this->var_to_num[id_def] + "] " + il_type + " " + id_def + ")"+"\n";
        string load_to_var = "ldc" + convertTypeToStackLoad(il_type) + expr + "\n"; 
        load_to_var += "stloc." + this->var_to_num[id_def] + "\n"; 
        this->state[id_def] = il_type;
        this->setReturnString(init_locals + load_to_var + "\n");
/////////
        if (DEBUG)
            cout << "return true; T_VAR_DECL_IS" << endl; /*DEBUG*/
        return true;
    }

    return false;
};

bool REALCodeGenerator::visitT_TYPE_DECL_IS(Node *node){
    if (DEBUG)
        cout << "Enter; T_TYPE_DECL_IS" << endl; /*DEBUG*/

    if (node->token.token == T_TYPE_DECL_IS){
        if (visitT_ID_define(node->nodes[0]) == false){
            cout << "T_TYPE_DECL_IS Error" << endl;
            exit(1);
            return false;
        }
        string id_def = this->getReturnString();

        if(visitType(node->nodes[1]) == false){
            cout << "T_TYPE_DECL_IS Error" << endl;
            exit(1);
            return false;
        }
        string type = this->getReturnString();

        /*C# type declaration example*/
        // using MyAlias = List<Tuple<int, string, int>>

        // this->addHeader("using " + id_def + " = " + type + ";\n");

        if (DEBUG)
            cout << "return true; T_TYPE_DECL_IS" << endl; /*DEBUG*/
        return true;

    }
    return false;
}

bool REALCodeGenerator::visitT_ROUTIN_DECL_TYPE(Node *node){
    if (DEBUG)
        cout << "Enter; T_ROUTIN_DECL_TYPE" << endl; /*DEBUG*/

    if (node->token.token == T_ROUTIN_DECL_TYPE){
        if (node->nodes.size() > 3){
            if (visitT_ID_define(node->nodes[0]) == false){
                cout << "T_TYPE_DECL_IS Error" << endl;
                exit(1);
                return false;
            }
            string id_def = this->getReturnString();

            if (visitParameters(node->nodes[1]) == false){
                cout << "T_TYPE_DECL_IS Error" << endl;
                exit(1);
                return false;
            } 
            string params = this->getReturnString();

            if (visitType(node->nodes[2]) == false){
                cout << "T_TYPE_DECL_IS Error" << endl;
                exit(1);
                return false;
            }
            string ret_type = this->getReturnString();

            if (visitBody(node->nodes[3]) == false){
                cout << "T_TYPE_DECL_IS Error" << endl;
                exit(1);
                return false;
            }
            string body = this->getReturnString();

            this->setReturnString(ret_type + " " + id_def + "(" + params + "){" + body + "}");
            /*void main(int a, int b){ Console.WriteLine(a + b);}*/
            
            if (DEBUG)
                cout << "return true; T_ROUTIN_DECL_TYPE" << endl; /*DEBUG*/
            return true;
        }else{
            if (visitT_ID_define(node->nodes[0]) == false){
                cout << "T_TYPE_DECL_IS Error" << endl;
                exit(1);
                return false;
            }
            string id_def = this->getReturnString();
            
            if (visitParameters(node->nodes[1]) == false){
                cout << "T_TYPE_DECL_IS Error" << endl;
                exit(1);
                return false;
            }
            string params = this->getReturnString();
            
            if(visitType(node->nodes[2]) == false){
                cout << "T_TYPE_DECL_IS Error" << endl;
                exit(1);
                return false;
            }
            string ret_type = this->getReturnString();

            this->setReturnString(ret_type + " " + id_def + "(" + params + "){};\n");
            /*void main(int a, int b){}*/

            if (DEBUG)
                cout << "return true; T_ROUTIN_DECL_TYPE" << endl; /*DEBUG*/
            return true;
        }
    }
    return false;
    // if (exist Body)
    //     Body
}

bool REALCodeGenerator::visitT_ROUTIN_DECL(Node *node){

    if (node->token.token == T_ROUTIN_DECL){
        if (DEBUG)
            cout << "Enter; T_ROUTIN_DECL" << endl; /*DEBUG*/
        
        if (visitT_ID_define(node->nodes[0]) == false){
            cout << "T_ROUTIN_DECL Error" << endl;
            exit(1);
            return false;
        }
        string id_def = this->getReturnString();
        
        if (visitParameters(node->nodes[1]) == false){
            cout << "T_ROUTIN_DECL Error" << endl;
            exit(1);
            return false;
        }
        string params = this->getReturnString();
        
        if (id_def == "main" && params != "int system"){
            cout << "Error: incorrect input parameters in the main function" << endl;
            exit(1);
        }

        if(visitBody(node->nodes[2]) == false){
            cout << "T_ROUTIN_DECL Error" << endl;
            exit(1);
            return false;
        }
        string body = this->getReturnString();
        
        // this->setReturnString("void " + id_def + "(" + params + "){" + body + "}"); // dynamic - for any type
        this->setReturnString(body);
        if (DEBUG)
            cout << "return true; T_ROUTIN_DECL" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitParameters(Node *node){
    if (DEBUG)
        cout << "Enter; Parameters" << endl; /*DEBUG*/

    if (node->token.token == T_PARAMETERS){
        if (visitParameterDeclaration(node->nodes[0]) == false){
            cout << "Parameters Error" << endl;
            exit(1);
            return false;
        }
        string param = this->getReturnString();
        vector <string> params;

        if (node->nodes.size() > 1){
            for (auto iterator : vector<Node *>(node->nodes.begin() + 1, node->nodes.end())){
                if (visitParameterDeclaration(iterator) == false){
                    cout << "Parameters Error" << endl;
                    exit(1);
                    return false;
                }
                string param = this->getReturnString();
                params.push_back(param);
            }
        }

        for (int i = 0; i < params.size(); ++i){
            param += ("," + params[i]);
        }
        
        this->setReturnString(param);

        if (DEBUG)
            cout << "return true; Parameters" << endl; /*DEBUG*/
        return true;
        
    }
    return false;
}
bool REALCodeGenerator::visitParameterDeclaration(Node *node){
    if (DEBUG)
        cout << "Enter; ParameterDeclaration" << endl; /*DEBUG*/

    if (node->token.token == T_COLON){
        if (visitT_ID_define(node->nodes[0]) == false){
            cout << "ParameterDeclaration Error" << endl;
            exit(1);
            return false;
        }
        string id_def = this->getReturnString();

        if (visitType(node->nodes[1]) == false){
            cout << "ParameterDeclaration Error" << endl;
            exit(1);
            return false;
        }
        string type = this->getReturnString();

        this->setReturnString(type + " " + id_def);
        
        if (DEBUG)
            cout << "return true; ParameterDeclaration" << endl; /*DEBUG*/
        return true;
    }
    return false;
}


bool REALCodeGenerator::visitType(Node *node){
    if (DEBUG)
        cout << "Enter; Type" << endl; /*DEBUG*/

    if (visitPrimitiveType(node) 
            || visitArrayType(node) 
                || visitRecordType(node) 
                    || visitT_ID_use(node)){
        if (DEBUG)
            cout << "return true; Type" << endl; /*DEBUG*/
        return true;
    }else
        return false;
}

bool REALCodeGenerator::visitPrimitiveType(Node *node){
    if (DEBUG)
        cout << "Enter; PrimitiveType" << endl; /*DEBUG*/

    if (node->token.token == T_INTEGER 
            || node->token.token == T_REAL 
                || node->token.token == T_BOOLEAN 
                    || node->token.token == T_CHAR){
        switch (node->token.token){
            case T_INTEGER:
                this->setReturnString("int");
                break;
            case T_REAL:
                this->setReturnString("double");
                break;
            case T_BOOLEAN:
                this->setReturnString("bool");
                break;
            case T_CHAR:
                this->setReturnString("char");
                break;
            default:
                cout << "[Something wrong?] Default type" << endl;
                exit(1);
                break;
        }

        if (DEBUG)
            cout << "return true; PrimitiveType" << endl; /*DEBUG*/
        return true;
    }else
        return false;
}

bool REALCodeGenerator::visitArrayType(Node *node){
    if (DEBUG)
        cout << "Enter; ArrayType" << endl; /*DEBUG*/

    if (node->token.token == T_ARRAY){
        if (visitExpression(node->nodes[0]) == false){
            cout << "ArrayType Error" << endl;
            exit(1);
            return false;
        }
        string expr = this->getReturnString();

        if(visitType(node->nodes[1]) == false){
            cout << "ArrayType Error" << endl;
            exit(1);
            return false;
        }
        string type = this->getReturnString();


        // Быть готовым что нужно будет где-то вставить int[] вместо int[5]
        this->setReturnString(type + "[" + expr + "+1]");
        if (DEBUG)
            cout << "return true; ArrayType" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitRecordType(Node *node){
    if (DEBUG)
        cout << "Enter; RecordType" << endl; /*DEBUG*/

    if (node->token.token == T_RECORD){
        vector<string> fields;
        for (auto iterator : node->nodes){
            if (visitVariableDeclaration(iterator) == false){
                cout << "RecordType" << endl;
                exit(1);
                return false;
            }
            string field = this->getReturnString();
            fields.push_back(field);
        }
        string str_fields = "";
        for (int i = 0; i < fields.size(); i++){
            str_fields += ("public " + fields[i]);
        }
        string recurd_name = "__unnamed_struct_number_" + to_string(this->structNum) + "__";
        this->structNum++;

        // this->addStructDecls("struct " + recurd_name + "{" + str_fields + "};\n");
        this->setReturnString(recurd_name);

        if (DEBUG)
            cout << "return true; RecordType" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitT_ID_define(Node *node){
    if (DEBUG)
        cout << "Enter; T_ID " << node->token.lexeme << endl; /*DEBUG*/

    if (node->token.token == T_ID){
        this->setReturnString(node->token.lexeme);
        
        if (DEBUG)
            cout << "return true; T_ID" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitT_ID_use(Node *node){
    if (DEBUG)
        cout << "Enter; T_ID " << node->token.lexeme << endl; /*DEBUG*/

    if (node->token.token == T_ID){
        this->setReturnString(node->token.lexeme);

        if (DEBUG)
            cout << "return true; T_ID" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitBody(Node *node){
    if (DEBUG)
        cout << "Enter; Body" << endl; /*DEBUG*/

    if (node->token.token == T_BODY){
        vector<string> statements;
        for (auto iterator : node->nodes){
            if (visitSimpleDeclaration(iterator) || visitStatement(iterator)){
                string statement = this->getReturnString();
                statements.push_back(statement);
                continue;
            }
            else{
                cout << "visitBody Error" << endl;
                exit(1);
                return false;
            }
        }
        
        string str_statements = "";
        for (int i = 0; i < statements.size(); i++){
            str_statements += statements[i];
        }
        this->setReturnString(str_statements);

        if (DEBUG)
            cout << "return true; Body" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitStatement(Node *node){
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

bool REALCodeGenerator::visitT_RETURN(Node *node){
    if (DEBUG)
        cout << "Enter; T_RETURN" << endl; /*DEBUG*/

    if (node->token.token == T_RETURN){
        if (visitExpression(node->nodes[0]) == false){
            cout << "T_RETURN Error" << endl;
            exit(1);
            return false;
        }
        
        string expr = this->getReturnString();

        this->setReturnString("return " + expr + ";\n");
        
        if (DEBUG)
            cout << "return true; T_RETURN" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitT_PRINT(Node *node){
    if (DEBUG)
        cout << "Enter; T_PRINT" << endl; /*DEBUG*/

    if (node->token.token == T_PRINT){
        if (visitExpression(node->nodes[0]) == false){
            cout << "T_PRINT Error" << endl;
            exit(1);
            return false;
        }

        string expr = this->getReturnString();
        string first_num = this->var_to_num[expr];
        //ldloc.2
        //call void [mscorlib]System.Console::WriteLine(int32)
        this->setReturnString("ldloc."+first_num+"\ncall void [mscorlib]System.Console::WriteLine("+this->state[expr]+")\n");
        
        if (DEBUG)
            cout << "return true; T_PRINT" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitIfStatement(Node *node){
    if (DEBUG)
        cout << "Enter; IfStatement" << endl; /*DEBUG*/

    if (visitT_IF_ELSE(node) || visitT_IF(node)){
        if (DEBUG)
            cout << "return true; IfStatement" << endl; /*DEBUG*/
        return true;
    }else
        return false;
}

bool REALCodeGenerator::visitT_IF_ELSE(Node *node){
    if (DEBUG)
        cout << "Enter; T_IF_ELSE" << endl; /*DEBUG*/

    if (node->token.token == T_IF_ELSE){
        if (visitExpression(node->nodes[0]) == false){
            cout << "T_IF_ELSE Error" << endl;
            exit(1);
            return false;
        }
        string expr = this->getReturnString();
        
        if (visitBody(node->nodes[1]) == false){
            cout << "T_IF_ELSE Error" << endl;
            exit(1);
            return false;
        }
        string body_if = this->getReturnString();

        if (visitBody(node->nodes[2]) == false){
            cout << "T_IF_ELSE Error" << endl;
            exit(1);
            return false;
        }
        string body_else = this->getReturnString();

        this->setReturnString("if (" + expr + "){ " + body_if + "} else { " + body_else + "};\n");
        if (DEBUG)
            cout << "return true; T_IF_ELSE" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitT_IF(Node *node){
    if (DEBUG)
        cout << "Enter; T_IF" << endl; /*DEBUG*/
                                       // Node
    
    if (node->token.token == T_IF){
        if (visitExpression(node->nodes[0]) == false){
            cout << "T_IF Error" << endl;
            exit(1);
            return false;
        }
        string expr = this->getReturnString();
        
        if (visitBody(node->nodes[1]) == false){
            cout << "T_IF Error" << endl;
            exit(1);
            return false;
        }
        string body = this->getReturnString();

        this->setReturnString("if (" + expr + "){ " + body + "};\n");

        if (DEBUG)
            cout << "return true; T_IF" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitForLoop(Node *node){
    if (DEBUG)
        cout << "Enter; ForLoop" << endl; /*DEBUG*/

    if (node->token.token == T_FOR){
        if (visitT_ID_define(node->nodes[0]) == false){
            cout << "T_FOR Error" << endl;
            exit(1);
            return false;
        }
        string id_def = this->getReturnString();
            
        if (visitRange(node->nodes[1]) == false){
            cout << "T_FOR Error" << endl;
            exit(1);
            return false;
        }
        string range = this->getReturnString();

        if (visitBody(node->nodes[2]) == false){
            cout << "T_FOR Error" << endl;
            exit(1);
            return false;
        }
        string body = this->getReturnString();

        string first = "";
        string last = "";
        string modifier = "";
        int i = 0;
        for (; i < range.size(); i++){
            if (range[i] == '|'){
                i++;
                break;
            }
            first += range[i];
        }
        for (; i < range.size(); i++){
            if (range[i] == '|'){
                i++;
                break;
            }
            last += range[i];
        }
        for (; i < range.size(); i++)
            modifier += range[i];

        string for_condition = "(int " + id_def + "=" + first + "; " + id_def + " < " + last + "; " + id_def + modifier + ")";

        this->setReturnString("for " + for_condition + "{" + body + "};\n");

        if (DEBUG)
            cout << "return true; ForLoop" << endl; /*DEBUG*/
        return true;
    }
    return false;
}
bool REALCodeGenerator::visitRange(Node *node){
    if (DEBUG)
        cout << "Enter; Range" << endl; /*DEBUG*/

    if (visitT_IN(node) || visitT_IN_REVERSE(node)){
        if (DEBUG)
            cout << "return true; Range" << endl; /*DEBUG*/
        return true;
    }else
        return false;
}

bool REALCodeGenerator::visitT_IN(Node *node){
    if (DEBUG)
        cout << "Enter; T_IN" << endl; /*DEBUG*/

    if (node->token.token == T_IN){
        if (visitExpression(node->nodes[0]) == false){
            cout << "T_IN Error" << endl;
            exit(1);
            return false;
        }
        string expr_1 = this->getReturnString();

        if (visitExpression(node->nodes[1]) == false){
            cout << "T_IN Error" << endl;
            exit(1);
            return false;
        }
        string expr_2 = this->getReturnString();

        this->setReturnString(expr_1 + "|" + expr_2 + "|" + "++");

        if (DEBUG)
            cout << "return true; T_IN" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitT_IN_REVERSE(Node *node){
    if (DEBUG)
        cout << "Enter; T_IN_REVERSE" << endl; /*DEBUG*/

    if (node->token.token == T_IN_REVERSE){
        if (DEBUG)
            cout << "return true; T_IN_REVERSE" << endl; /*DEBUG*/

        if (visitExpression(node->nodes[0])){
            cout << "T_IN_REVERSE Error" << endl;
            exit(1);
            return false;
        }
        string expr_1 = this->getReturnString();

        if (visitExpression(node->nodes[1])){
            cout << "T_IN_REVERSE Error" << endl;
            exit(1);
            return false;
        }
        string expr_2 = this->getReturnString();

        this->setReturnString(expr_1 + "|" + expr_2 + "|" + "--");

        if (DEBUG)
            cout << "return true; T_IN_REVERSE" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitWhileLoop(Node *node){
    if (DEBUG)
        cout << "Enter; WhileLoop" << endl; /*DEBUG*/

    if (node->token.token == T_WHILE){
        if (visitExpression(node->nodes[0]) == false){
            cout << "T_WHILE Error" << endl;
            exit(1);
            return false;
        }
        string expr = this->getReturnString();
        
        if (visitBody(node->nodes[1]) == false){
            cout << "T_WHILE Error" << endl;
            exit(1);
            return false;
        }
        string body = this->getReturnString();

        this->setReturnString("while (" + expr + "){ " + body + "};\n");
        if (DEBUG)
            cout << "return true; WhileLoop" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitRoutineCall(Node *node){
    if (DEBUG)
        cout << "Enter; RoutineCall" << endl; /*DEBUG*/

    // Node
    if (node->token.token == T_ROUTINE_CALL){
        if (visitT_ID_use(node->nodes[0]) == false){
            cout << "T_ROUTINE_CALL 1" <<endl;
            exit(1);
            return false;
        }
        string id_use = this->getReturnString();
        
        vector<string> expressions;
        for (auto iterator : vector<Node *>(node->nodes.begin() + 1, node->nodes.end())){
            if (visitExpression(iterator) == false){
                cout << "T_ROUTINE_CALL" <<endl;
                exit(1);
                return false;
            }
            string expr = this->getReturnString();
            expressions.push_back(expr);
        }
        string args = "";
        if (expressions.size() > 0){
            args += expressions[0];

            for (int i = 1; i < expressions.size(); i++)
                args += (", " + expressions[i]);
        }
        
        this->setReturnString(id_use + "(" + args + ");\n");
        
        if (DEBUG)
            cout << "return true; RoutineCall" << endl; /*DEBUG*/
        return true;
    }

    if (node->token.token == T_ID){
        this->setReturnString(node->token.lexeme);

        if (DEBUG)
            cout << "return true; RoutineCall" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitAssignment(Node *node){
    if (DEBUG)
        cout << "Enter; Assignment" << endl; /*DEBUG*/

    if (node->token.token == T_COLONEQU){
        if (visitModifiablePrimary(node->nodes[0]) == false){
            cout << "Assignment Error" << endl;
            exit(1);
            return false;
        }
        string modifiable_primary = this->getReturnString();

        if (visitExpression(node->nodes[1]) == false){
            cout << "Assignment Error" << endl;
            exit(1);
            return false;
        }
        string expression = this->getReturnString();
        
        // stloc.2 
        string num = this->var_to_num[modifiable_primary];
        this->setReturnString(expression + "stloc." + num + "\n\n");

        if (DEBUG)
            cout << "return true; Assignment" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitExpression(Node *node){
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

bool REALCodeGenerator::visitT_AND(Node *node){
    if (DEBUG)
        cout << "Enter; T_AND" << endl; /*DEBUG*/

    if (node->token.token == T_AND){
        if (visitRelation(node->nodes[0]) == false){
            cout << "T_AND Error" << endl;
            exit(1);
            return false;
        }
        string expr_1 = this->getReturnString();

        if(visitExpression(node->nodes[1]) == false){
            cout << "T_AND Error" << endl;
            exit(1);
            return false;
        }
        string expr_2 = this->getReturnString();

        this->setReturnString(expr_1 + " & " + expr_2);

        if (DEBUG)
            cout << "return true; T_AND" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitT_OR(Node *node){
    if (DEBUG)
        cout << "Enter; T_OR" << endl; /*DEBUG*/

    if (node->token.token == T_OR){
        if (visitRelation(node->nodes[0]) == false){
            cout << "T_OR Error" << endl;
            exit(1);
            return false;
        }
        string expr_1 = this->getReturnString();

        if(visitExpression(node->nodes[1]) == false){
            cout << "T_OR Error" << endl;
            exit(1);
            return false;
        }
        string expr_2 = this->getReturnString();
        
        this->setReturnString(expr_1 + " | " + expr_2);
        if (DEBUG)
            cout << "return true; T_OR" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitT_XOR(Node *node){
    if (DEBUG)
        cout << "Enter; T_XOR" << endl; /*DEBUG*/

    if (node->token.token == T_XOR){
        if (visitRelation(node->nodes[0]) == false){
            cout << "T_XOR Error" << endl;
            exit(1);
            return false;
        }
        string expr_1 = this->getReturnString();

        if(visitExpression(node->nodes[1]) == false){
            cout << "T_XOR Error" << endl;
            exit(1);
            return false;
        }
        string expr_2 = this->getReturnString();
        
        this->setReturnString(expr_1 + " ^ " + expr_2);
        if (DEBUG)
            cout << "return true; T_XOR" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitRelation(Node *node){
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

bool REALCodeGenerator::visitT_LESS(Node *node){
    if (DEBUG)
        cout << "Enter; T_LESS" << endl; /*DEBUG*/

    if (node->token.token == T_LESS){
        if (visitSimple(node->nodes[0]) == false){
            cout << "T_LESS Error" << endl;
            exit(1);
            return false;
        }
        string simple_1 = this->getReturnString();
        
        if (visitSimple(node->nodes[1])){
            cout << "T_LESS Error" << endl;
            exit(1);
            return false;
        }
        string simple_2 = this->getReturnString();

        this->setReturnString(simple_1 + "<" + simple_2);

        if (DEBUG)
            cout << "return true; T_LESS" << endl; /*DEBUG*/
        return true;
            
    }
    return false;
}
bool REALCodeGenerator::visitT_LESSOREQU(Node *node){
    if (DEBUG)
        cout << "Enter; T_LESSOREQU" << endl; /*DEBUG*/

    if (node->token.token == T_LESSOREQU){
        if (visitSimple(node->nodes[0]) == false){
            cout << "T_LESSOREQU Error" << endl;
            exit(1);
            return false;
        }
        string simple_1 = this->getReturnString();
        
        if (visitSimple(node->nodes[1])){
            cout << "T_LESSOREQU Error" << endl;
            exit(1);
            return false;
        }
        string simple_2 = this->getReturnString();

        this->setReturnString(simple_1 + "<=" + simple_2);

        if (DEBUG)
            cout << "return true; T_LESSOREQU" << endl; /*DEBUG*/
        return true;
    }
    return false;
}
bool REALCodeGenerator::visitT_GREAT(Node *node){
    if (DEBUG)
        cout << "Enter; T_GREAT" << endl; /*DEBUG*/

    if (node->token.token == T_GREAT){
        if (visitSimple(node->nodes[0]) == false){
            cout << "T_GREAT Error" << endl;
            exit(1);
            return false;
        }
        string simple_1 = this->getReturnString();
        
        if (visitSimple(node->nodes[1])){
            cout << "T_GREAT Error" << endl;
            exit(1);
            return false;
        }
        string simple_2 = this->getReturnString();

        this->setReturnString(simple_1 + ">" + simple_2);

        if (DEBUG)
            cout << "return true; T_GREAT" << endl; /*DEBUG*/
        return true;
    }
    return false;
}
bool REALCodeGenerator::visitT_GREATOREQU(Node *node){
    if (DEBUG)
        cout << "Enter; T_GREATOREQU" << endl; /*DEBUG*/

    if (node->token.token == T_GREATOREQU){
        
        if (visitSimple(node->nodes[0]) == false){
            cout << "T_GREATOREQU Error" << endl;
            exit(1);
            return false;
        }
        string simple_1 = this->getReturnString();
        
        if (visitSimple(node->nodes[1])){
            cout << "T_GREATOREQU Error" << endl;
            exit(1);
            return false;
        }
        string simple_2 = this->getReturnString();

        this->setReturnString(simple_1 + ">=" + simple_2);

        if (DEBUG)
            cout << "return true; T_GREATOREQU" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitT_EQU(Node *node){
    if (DEBUG)
        cout << "Enter; T_EQU" << endl; /*DEBUG*/
    if (node->token.token == T_EQU){
        
        if (visitSimple(node->nodes[0]) == false){
            cout << "T_EQU Error" << endl;
            exit(1);
            return false;
        }
        string simple_1 = this->getReturnString();
        
        if (visitSimple(node->nodes[1]) == false){
            cout << "T_EQU Error" << endl;
            exit(1);
            return false;
        }
        string simple_2 = this->getReturnString();

        this->setReturnString(simple_1 + "==" + simple_2);
        

        if (DEBUG)
            cout << "return true; T_EQU" << endl; /*DEBUG*/
        return true;
    }
    return false;
}
bool REALCodeGenerator::visitT_NOTEQU(Node *node){
    if (DEBUG)
        cout << "Enter; T_NOTEQU" << endl; /*DEBUG*/

    if (node->token.token == T_NOTEQU){
        if (visitSimple(node->nodes[0]) == false){
            cout << "T_NOTEQU Error" << endl;
            exit(1);
            return false;
        }
        string simple_1 = this->getReturnString();
        
        if (visitSimple(node->nodes[1]) == false){
            cout << "T_NOTEQU Error" << endl;
            exit(1);
            return false;
        }
        string simple_2 = this->getReturnString();

        this->setReturnString(simple_1 + "!=" + simple_2);

        if (DEBUG)
            cout << "return true; T_NOTEQU" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitSimple(Node *node){
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

bool REALCodeGenerator::visitT_MULTOP(Node *node){
    if (DEBUG)
        cout << "Enter; T_MULTOP" << endl; /*DEBUG*/

    if (node->token.token == T_MULTOP){
        if (visitFactor(node->nodes[0]) == false){
            cout << "T_MULTOP Error" << endl;
            exit(1);
            return false;
        }
        string factor = this->getReturnString();
        
        if(visitSimple(node->nodes[1]) == false){
            cout << "T_MULTOP Error" << endl;
            exit(1);
            return false;
        }
        string simple = this->getReturnString();
        // ldloc.0 
        // ldloc.1 
        // mul
        string first_num = this->var_to_num[factor];
        string second_num = this->var_to_num[simple];
        this->setReturnString("ldloc." + first_num + "\nldloc." + second_num + "\nmul\n");

        if (DEBUG)
            cout << "return true; T_MULTOP" << endl; /*DEBUG*/
        return true;
    }
    return false;
}
bool REALCodeGenerator::visitT_DIVOP(Node *node){
    if (DEBUG)
        cout << "Enter; T_DIVOP" << endl; /*DEBUG*/

    if (node->token.token == T_DIVOP){
        if (visitFactor(node->nodes[0]) == false){
            cout << "T_DIVOP Error" << endl;
            exit(1);
            return false;
        }
        string factor = this->getReturnString();
        
        if(visitSimple(node->nodes[1]) == false){
            cout << "T_DIVOP Error" << endl;
            exit(1);
            return false;
        }
        string simple = this->getReturnString();

        // ldloc.0 
        // ldloc.1 
        // div
        string first_num = this->var_to_num[factor];
        string second_num = this->var_to_num[simple];
        this->setReturnString("ldloc." + first_num + "\nldloc." + second_num + "\ndiv\n");

        if (DEBUG)
            cout << "return true; T_DIVOP" << endl; /*DEBUG*/
        return true;
    }
    return false;
}
bool REALCodeGenerator::visitT_MODOP(Node *node){
    if (DEBUG)
        cout << "Enter; T_MODOP" << endl; /*DEBUG*/

    if (node->token.token == T_MODOP){
        if (visitFactor(node->nodes[0]) == false){
            cout << "T_MODOP Error" << endl;
            exit(1);
            return false;
        }
        string factor = this->getReturnString();

        if(visitSimple(node->nodes[1]) == false){
            cout << "T_MODOP Error" << endl;
            exit(1);
            return false;
        }
        string simple = this->getReturnString();

        this->setReturnString(factor + " % " + simple);

        if (DEBUG)
            cout << "return true; T_MODOP" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitFactor(Node *node){
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
bool REALCodeGenerator::visitT_ADDOP(Node *node){
    if (DEBUG)
        cout << "Enter; T_ADDOP" << endl; /*DEBUG*/

    if (node->token.token == T_ADDOP){
        if (visitSummand(node->nodes[0]) == false){
            cout << "T_ADDOP Error" << endl;
            exit(1);
            return false;
        }
        string summand = this->getReturnString();

        if(visitFactor(node->nodes[1]) == false){
            cout << "T_ADDOP Error" << endl;
            exit(1);
            return false;
        }
        string factor = this->getReturnString();
        // ldloc.0 
        // ldloc.1 
        // add
        string first_num = this->var_to_num[summand];
        string second_num = this->var_to_num[factor];
        this->setReturnString("ldloc." + first_num + "\nldloc." + second_num + "\nadd\n");

        if (DEBUG)
            cout << "return true; T_ADDOP" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitT_SUBTROP(Node *node){
    if (DEBUG)
        cout << "Enter; T_SUBTROP" << endl; /*DEBUG*/

    if (node->token.token == T_SUBTROP){
        if (visitSummand(node->nodes[0]) == false){
            cout << "T_SUBTROP Error" << endl;
            exit(1);
            return false;
        }
        string summand = this->getReturnString();

        if(visitFactor(node->nodes[1]) == false){
            cout << "T_SUBTROP Error" << endl;
            exit(1);
            return false;
        }
        string factor = this->getReturnString();

        // ldloc.0 
        // ldloc.1 
        // sub
        string first_num = this->var_to_num[summand];
        string second_num = this->var_to_num[factor];
        this->setReturnString("ldloc." + first_num + "\nldloc." + second_num + "\nsub\n");
        
        if (DEBUG)
            cout << "return true; T_SUBTROP" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitSummand(Node *node){
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
bool REALCodeGenerator::visitT_PARENT(Node *node){
    if (DEBUG)
        cout << "Enter; T_PARENT" << endl; /*DEBUG*/

    if (node->token.token == T_PARENT){
        if (visitExpression(node->nodes[0]) == false){
            cout << "T_PARENT Error" << endl;
            exit(1);
            return false;
        }
        string expression = this->getReturnString();
        this->setReturnString("(" + expression + ")");
        
        if (DEBUG)
            cout << "return true; T_PARENT" << endl; /*DEBUG*/
        return true;
        
    }else{
        // cout << "T_PARENT Error" << endl;
        // exit(1);
        return false;
    }
}

bool REALCodeGenerator::visitPrimary(Node *node){
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
bool REALCodeGenerator::visitT_ICONST(Node *node){
    if (DEBUG)
        cout << "Enter; T_ICONST" << endl; /*DEBUG*/

    if (node->token.token == T_ICONST){

        if (DEBUG)
            cout << "return true; T_ICONST" << endl; /*DEBUG*/
        this->setReturnString(node->token.lexeme);
        return true;
    }
    return false;
}
bool REALCodeGenerator::visitT_CCONST(Node *node){
    if (DEBUG)
        cout << "Enter; T_CCONST" << endl; /*DEBUG*/

    if (node->token.token == T_CCONST){

        if (DEBUG)
            cout << "return true; T_CCONST" << endl; /*DEBUG*/

        this->setReturnString("'" + node->token.lexeme + "'");
        return true;
    }
    return false;
}
bool REALCodeGenerator::visitT_RCONST(Node *node){
    if (DEBUG)
        cout << "Enter; T_RCONST" << endl; /*DEBUG*/

    if (node->token.token == T_RCONST){

        if (DEBUG)
            cout << "return true; T_RCONST" << endl; /*DEBUG*/
        this->setReturnString(node->token.lexeme);
        return true;
    }
    return false;
}
bool REALCodeGenerator::visitT_TRUE(Node *node){
    if (DEBUG)
        cout << "Enter; T_TRUE" << endl; /*DEBUG*/

    if (node->token.token == T_TRUE){

        if (DEBUG)
            cout << "return true; T_TRUE" << endl; /*DEBUG*/
        
        this->setReturnString("true");
        return true;
    }
    return false;
}
bool REALCodeGenerator::visitT_FALSE(Node *node){
    if (DEBUG)
        cout << "Enter; T_FALSE" << endl; /*DEBUG*/

    if (node->token.token == T_FALSE){

        if (DEBUG)
            cout << "return true; T_FALSE" << endl; /*DEBUG*/
            
        this->setReturnString("false");
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitModifiablePrimary(Node *node){
    if (DEBUG)
        cout << "Enter; ModifiablePrimary" << endl; /*DEBUG*/

    if (visitID_ARRAY(node) || visitT_DOT(node)){

        if (DEBUG)
            cout << "return true; ModifiablePrimary" << endl; /*DEBUG*/
        return true;
    }
    else
        return false;
}

bool REALCodeGenerator::visitT_DOT(Node *node){
    if (DEBUG)
        cout << "Enter; T_DOT" << endl; /*DEBUG*/
    
    if (node->token.token == T_DOT){

        if (visitID_ARRAY(node->nodes[0]) == false){
            cout << "T_DOT Error" << endl;
            exit(1);
            return false;
        }
        string id_array = this->getReturnString();

        if (node->nodes.size() > 1 && visitModifiablePrimary(node->nodes[1])){
            string modifiable = this->getReturnString();
            
            id_array = id_array + "." + modifiable;
        }
        else{
            cout << "T_DOT Error" << endl;
            exit(1);
            return false;
        }

        this->setReturnString(id_array);

        if (DEBUG)
            cout << "return true; T_DOT" << endl; /*DEBUG*/
        return true;
    }
    return false;
}

bool REALCodeGenerator::visitID_ARRAY(Node *node){
    if (DEBUG)
        cout << "Enter; ID_ARRAY" << endl; /*DEBUG*/

    if (visitT_ID_define(node)){


        if (DEBUG)
            cout << "return true; ID_ARRAY" << endl; /*DEBUG*/
        return true;
    }
    if (visitT_BRACKS(node)){

        if (DEBUG)
            cout << "return true; ID_ARRAY" << endl; /*DEBUG*/
        return true;
    }
    else
        return false;

}

bool REALCodeGenerator::visitT_BRACKS(Node *node){
    if (DEBUG)
        cout << "Enter; T_BRACKS" << endl; /*DEBUG*/

    if (node->token.token == T_BRACKS){

        if (node->nodes.size() == 2 && visitT_ID_define(node->nodes[0])){
            string id_def = this->getReturnString();
            
            if (visitExpression(node->nodes[1]) == false){
                cout << "T_BRACKS Error" << endl;
                exit(1);
                return false;
            }
            string expr = this->getReturnString();

            this->setReturnString(id_def + "[" + expr + "]");

            if (DEBUG)
                cout << "return true; T_BRACKS" << endl; /*DEBUG*/
            return true;

        }
        else if (node->nodes.size() == 3 && visitT_ID_define(node->nodes[0])){
            string id_def = this->getReturnString();
            
            if (visitExpression(node->nodes[1]) == false){
                cout << "T_BRACKS Error" << endl;
                exit(1);
                return false;
            }
            string expr = this->getReturnString();
            
            if (visitT_BRACKS(node->nodes[2]) == false){
                cout << "T_BRACKS Error" << endl;
                exit(1);
                return false;
            }
            string bracks = this->getReturnString();

            this->setReturnString(id_def + "[" + expr + "]" + bracks);

            if (DEBUG)
                cout << "return true; T_BRACKS" << endl; /*DEBUG*/
            return true;
        }else if (node->nodes.size() == 1 && visitExpression(node->nodes[0])){
            string expr = this->getReturnString();

            this->setReturnString("[" + expr + "]");

            if (DEBUG)
                cout << "return true; T_BRACKS" << endl; /*DEBUG*/
            return true;
        }else if (node->nodes.size() == 2 && visitExpression(node->nodes[0])){
            string expr = this->getReturnString();

            if (visitT_BRACKS(node->nodes[1]) == false){
                cout << "T_BRACKS Error" << endl;
                exit(1);
                return false;
            }
            string bracks = this->getReturnString();

            this->setReturnString("[" + expr + "]" + bracks);

            if (DEBUG)
                cout << "return true; T_BRACKS" << endl; /*DEBUG*/
            return true;
        }
        return false;
    }
    return false;
}