#include <iostream>
#include <fstream>
#include <string>
#include "Analyser.tab.c"
#include "Visitor.h"
#include "CodeGeneration/CodeGenerator.h"
#include "REALCodeGeneration/CodeGenerator.h"
using namespace std;
string inputFile = "tests/test_0.txt";

 
void drawTree(Node *root, int depth, bool lastChild[]){
    if (root == nullptr)
        return;
    
    cout << string(depth * 2, ' ');
    
    if (lastChild[depth]){
        cout << "\\- ";
        lastChild[depth] = false;
    }
    else
        cout << "|-";

    cout << root->token.lexeme << endl;
    int numChildren = root->nodes.size();
    for (int i = 0; i < numChildren; i++){
        lastChild[depth + 1] = (i == numChildren - 1);
        drawTree(root->nodes[i], depth + 1, lastChild);
    }
}


int main(int argc, char *argv[]){
    
    cout << "#####################################\n";
    if (argc > 1) {
        inputFile = argv[1];
    }
    cout << "\nInputfile: "<< inputFile << endl;

    // Check if input file exists
    ifstream input(inputFile);
    if (!input.good()) {
        cerr << "Error: input file \"" << inputFile << "\" does not exist or cannot be opened.\n";
        return 1;
    }
    input.close();

    // Generation AST from the given code
    Node *root_1 = generateAST(inputFile);

    // Printing generated AST
    cout << "\nAST:\n";
    bool lastChild[1000] = {false};
    drawTree(root_1, 0, lastChild);

    // Semantic analysis
    cout << endl << "Start typechecking" << endl;
    Visitor v = Visitor();
    v.DEBUG = false;
    v.visitProgram(root_1);
    cout << "Typecheck ends" << endl << endl;
    
    // Code Generation
    cout << "Code Generation starts" << endl;
    CodeGenerator v2 = CodeGenerator();
    v2.DEBUG = false;
    v2.visitProgram(root_1);
    v2.printAll();
    cout << "Code Generation ends" << endl << endl;

    v2.safeCSFile();
    cout << "Result of the running:" << endl;

    REALCodeGenerator v3 = REALCodeGenerator();
    v3.DEBUG = false;
    v3.visitProgram(root_1);
    v3.printAll();
    v3.safeCSFile();
    cout << "End:" << endl;
}