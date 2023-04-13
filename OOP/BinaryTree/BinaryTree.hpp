#ifndef BINARY_TREE
#define BINARY_TREE

class Node{
private:
    Node *left, *right;
    int value;

public:
    Node(int value);
    void setLeftNode(Node *node);
    void setRightNode(Node *node);
    Node* getLeftNode();
    Node* getRightNode();
    int getNodeValue();
};

class BinaryTree{
private:
    Node *root;
    void findInsertion(Node *node, int value);
    void clear(Node *node);

public:
    BinaryTree();
    virtual ~BinaryTree();
    void insert(int value);
    void preOrder(Node *node); // Préfixa
    void inOrder(Node *node); // Infixa
    void posOrder(Node *node); // Pósfixa
    void BFS(Node *node); // Por nível
    Node* getRoot();
};

#endif // BinaryTree.hpp
