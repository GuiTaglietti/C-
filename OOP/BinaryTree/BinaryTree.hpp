#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

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

public:
    BinaryTree();
    void insert(int value);
    void preOrder(Node *node);
    void inOrder(Node *node);
    void posOrder(Node *node);
    int getHeight();
    Node* getRoot();
};

#endif // BINARYTREE_HPP
