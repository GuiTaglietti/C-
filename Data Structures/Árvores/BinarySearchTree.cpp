#include <bits/stdc++.h>
using namespace std;

/*

    Gui Taglietti
    Binary Search Tree implementation
    
    Important! 
    
    I didn't separate the files into .h/.hpp and .cpp for faster implementation to save time. 
    I created this just to test the implementation...
    
    By the way, here are a simple BST

*/

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
private:
    Node* root;

    Node* insertHelper(Node* node, int data) {
        if(!node) return new Node(data);
        if(data < node->data) node->left = insertHelper(node->left, data);
        else node->right = insertHelper(node->right, data);
        return node;
    }

    bool searchHelper(Node* node, int data) {
        if(!node) return false;
        if(data == node->data) return true;
        if(data < node->data) return searchHelper(node->left, data);
        return searchHelper(node->right, data);
    }

    void inOrderHelper(Node* node) {
        if(node){
            inOrderHelper(node->left);
            cout << node->data << " ";
            inOrderHelper(node->right);
        }
    }

public:
    BST(){
        this->root = NULL;
    }
    
    void insert(int data){
        this->root = insertHelper(this->root, data);
    }
    
    bool search(int data){
        return searchHelper(this->root, data);
    }
    
    void inOrder(){
        inOrderHelper(this->root);
    }
};

int main() {
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(9);
    cout << "Árvore binária de busca ordenada: ";
    bst.inOrder();
    cout << endl;
    cout << "Número 7 está na BST? " << (bst.search(7) ? "Sim" : "Não") << endl;
    cout << "Número 2 está na BST? " << (bst.search(2) ? "Sim" : "Não") << endl;
    return 0;
}
