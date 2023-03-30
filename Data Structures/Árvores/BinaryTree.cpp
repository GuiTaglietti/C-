#include "BinaryTree.hpp"
#include <iostream> // Usar o NULL

// Constrói os métodos da classe Node

Node::Node(int value){
    this->value = value;
    this->left = NULL;
    this->right = NULL;
}

void Node::setLeftNode(Node *node){
    this->left = node;
}

void Node::setRightNode(Node *node){
    this->right = node;
}

Node* Node::getLeftNode(){
    return this->left;
}

Node* Node::getRightNode(){
    return this->right;
}

int Node::getNodeValue(){
    return this->value;
}

// Constrói os métodos da classe BinaryTree

BinaryTree::BinaryTree(){
    this->root = NULL;
}

void BinaryTree::insert(int value){
    if(this->root == NULL) this->root = new Node(value);
    else this->findInsertion(this->root, value);
}

void BinaryTree::findInsertion(Node *node, int value){
    if(value < node->getNodeValue()){
        if(node->getLeftNode() == NULL){
            Node* newNode = new Node(value);
            node->setLeftNode(newNode);
            return;
        }
        this->findInsertion(node->getLeftNode(), value);
    }
    else if(value > node->getNodeValue()){
        if(node->getRightNode() == NULL){
            Node* newNode = new Node(value);
            node->setRightNode(newNode);
            return;
        }
        this->findInsertion(node->getRightNode(), value);
    }
}

Node* BinaryTree::getRoot(){
    return this->root;
}

void BinaryTree::inOrder(Node *node){
    if(node){
        inOrder(node->getLeftNode());
        std::cout << node->getNodeValue() << " ";
        inOrder(node->getRightNode());
    }
}

void BinaryTree::preOrder(Node *node){
    if(node){
        std::cout << node->getNodeValue() << " ";
        preOrder(node->getLeftNode());
        preOrder(node->getRightNode());
    }
}

void BinaryTree::posOrder(Node *node){
    if(node){
        posOrder(node->getLeftNode());
        posOrder(node->getRightNode());
        std::cout << node->getNodeValue() << " ";
    }
}