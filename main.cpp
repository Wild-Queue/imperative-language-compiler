#include <iostream>
#include <string>
#include "Analyser.tab.c"
#include "Visitor.h"
using namespace std;
string inputFile = "input_2.txt";


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
int main()
{
    cout << "######################################\n";
    cout << "\nInputfile: "<< inputFile << endl;
    // cout << "Tokenized program:" << endl;
    Node *root_1 = generateAST(inputFile);
    cout << "\nAST:\n";
    //printAST(root_1, 0);
    bool lastChild[1000] = {false};
    drawTree(root_1, 0, lastChild);
    Visitor v = Visitor();
    v.DEBUG = true;
    v.visitProgram(root_1);
}