#include "NodeDecl.h"
#include <vector>
#include <string>
using namespace std;

Node* combineNodes(vector<Node*> nodes, yytokentype token, string lexeme){
    Node* newNode = new Node(Token(token, lexeme));

    for (int i = 0; i < nodes.size(); ++i){
        newNode->nodes.push_back(nodes[i]);
    }
    return newNode;
};

Node* combineNodes(Node *fst, vector<Node*> nodes, yytokentype token, string lexeme){
    Node* newNode = new Node(Token(token, lexeme));

    newNode->nodes.push_back(fst);
    for (int i = 0; i < nodes.size(); ++i){
        newNode->nodes.push_back(nodes[i]);
    }
    return newNode;
};

vector<Node*> collectNodes(Node *fst){
    vector<Node*> newNode;

    newNode.push_back(fst);

    return newNode;
};

vector<Node*> collectNodes(vector<Node*> nodes){
    vector<Node*> newNode;

    for (int i = 0; i < nodes.size(); ++i){
        newNode.push_back(nodes[i]);
    }

    return newNode;
};

vector<Node*> collectNodes(Node *fst, vector<Node*> nodes){
    vector<Node*> newNode;

    newNode.push_back(fst);
    for (int i = 0; i < nodes.size(); ++i){
        newNode.push_back(nodes[i]);
    }

    return newNode;
};

Node* createNode(yytokentype token, string lexeme){
    Node* newNode = new Node(Token(token, lexeme));

    return newNode;
};

Node* createNode(Node *fst, yytokentype token, string lexeme){
    Node* newNode = new Node(Token(token, lexeme));

    newNode->nodes.push_back(fst);

    return newNode;
};

Node* createNode(Node *fst, Node *snd, yytokentype token, string lexeme){
        Node* newNode = new Node(Token(token, lexeme));

        newNode->nodes.push_back(fst);
        newNode->nodes.push_back(snd);

        return newNode;
};

Node* createNode(Node *fst, Node *snd, Node *trd, yytokentype token, string lexeme){
        Node* newNode = new Node(Token(token, lexeme));

        newNode->nodes.push_back(fst);
        newNode->nodes.push_back(snd);
        newNode->nodes.push_back(trd);

        return newNode;
};

Node* createNode(Node *fst, Node *snd, Node *trd, Node *frth, yytokentype token, string lexeme){
        Node* newNode = new Node(Token(token, lexeme));

        newNode->nodes.push_back(fst);
        newNode->nodes.push_back(snd);
        newNode->nodes.push_back(trd);
        newNode->nodes.push_back(frth);

        return newNode;
};