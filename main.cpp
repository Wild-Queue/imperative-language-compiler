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

    // cout << curNode->token.token << " : " << curNode->token.lexeme << endl;
    cout << curNode->token.lexeme << endl;

    for (Node *nextNode : curNode->nodes)
    {
        printAST(nextNode, depth + 1);
    }
}

void drawTree(Node *root, int depth, bool lastChild[])
{
    if (root == nullptr)
    {
        return;
    }
    cout << string(depth * 2, ' ');
    if (lastChild[depth])
    {
        cout << "\\-";
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
    cout << "\n\n"
         << inputFile << "\n\n";
    cout << "Tokenized program:" << endl;
    Node *root_1 = generateAST(inputFile);
    cout << "\n\nAST:\n";
    //printAST(root_1, 0);
    bool lastChild[1000] = {false};
    drawTree(root_1, 0, lastChild);
}