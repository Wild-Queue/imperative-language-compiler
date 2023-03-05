#include <iostream>
#include <string>
#include "Analyser.tab.c"
using namespace std;
string inputFile = "input_1.txt";

void printAST(Node *curNode, int depth = 0)
{
    for (int i = 0; i < depth; ++i)
        cout << "---";

    if (curNode->nodes.empty())
        cout << "| ";
    else
        cout << "> ";

    //cout << curNode->token.token << " : " << curNode->token.lexeme << endl;
    cout << curNode->token.lexeme << endl;

    for (Node *nextNode : curNode->nodes)
    {
        printAST(nextNode, depth + 1);
    }
}

int main(){
    cout << "\n\n" << inputFile << "\n\n";
    cout << "Tokenized program:" << endl;
    Node* root_1 = generateAST(inputFile);
    cout << "\n\nAST:\n";
    printAST(root_1, 0);
}