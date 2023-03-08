#include <vector>
#include <string>
using namespace std;

#ifndef Token_H
#define Token_H

struct Token{
    string token;
    string lexeme;

    Token(string token, string lexeme) : token(token), lexeme(lexeme){};
};

#endif

#ifndef Node_H
#define Node_H

struct Node {
    Token token = Token("NONE", "");
    vector<Node*>nodes;

    Node(Token token) : token(token){};
};

#endif

extern Node* combineNodes(vector<Node*> nodes, string token, string lexeme);

extern Node* combineNodes(Node *fst, vector<Node*> nodes, string token, string lexeme);

extern vector<Node*> collectNodes(Node *fst);

extern vector<Node*> collectNodes(vector<Node*> nodes);

extern vector<Node*> collectNodes(Node *fst, vector<Node*> nodes);

extern Node* createNode(string token, string lexeme);

extern Node* createNode(Node *fst, string token, string lexeme);

extern Node* createNode(Node *fst, Node *snd, string token, string lexeme);

extern Node* createNode(Node *fst, Node *snd, Node *trd, string token, string lexeme);

extern Node* createNode(Node *fst, Node *snd, Node *trd, Node *frth, string token, string lexeme);