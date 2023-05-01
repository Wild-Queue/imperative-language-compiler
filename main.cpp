#include <iostream>
#include <fstream>
#include <string>
#include "Analyser.tab.c"
#include "Visitor.h"
#include "CodeGeneration/CodeGenerator.h"
using namespace std;
string inputFile = "tests/test_0.txt";

 
void drawTree(Node *root, int depth, bool lastChild[])
{
    if (root == nullptr)
    {
        return;
    }
    cout << string(depth * 2, ' ');
    if (lastChild[depth])
    {
        cout << "\\- ";
        lastChild[depth] = false;
    }
    else
    {
        cout << "|-";
    }

    cout << root->token.lexeme << endl;
    int numChildren = root->nodes.size();
    for (int i = 0; i < numChildren; i++)
    {
        lastChild[depth + 1] = (i == numChildren - 1);
        drawTree(root->nodes[i], depth + 1, lastChild);
    }
}
int main(int argc, char *argv[])
{
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
    // cout << "Tokenized program:" << endl;
    Node *root_1 = generateAST(inputFile);
    cout << "\nAST:\n";
    //printAST(root_1, 0);
    bool lastChild[1000] = {false};
    drawTree(root_1, 0, lastChild);
    Visitor v = Visitor();
    v.DEBUG = true;
    v.visitProgram(root_1);

    cout << "Typecheck ends;" << endl << endl << endl;
    cout << "Code Generation starts;" << endl;
    CodeGenerator v2 = CodeGenerator();
    v2.DEBUG = false;
    v2.visitProgram(root_1);
    v2.printAll();
}