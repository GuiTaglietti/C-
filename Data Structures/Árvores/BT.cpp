#include "BT.hpp"

// Constrói o método construtor do nó

No::No(int data){
    this->data = data;
    left = right = nullptr;
}

// Constrói os métodos da árvore binária

ArvoreBinaria::ArvoreBinaria(){
    this->root = nullptr;
}

void ArvoreBinaria::inserir(int data) {
    No* newNode = new No(data);
    if(root == nullptr){
        root = newNode;
        return;
    }
    No* current = root;
    No* parent = nullptr;
    while (current != nullptr){
        parent = current;
        if(data < current->data) current = current->left;
        else current = current->right;
    }
    if (data < parent->data)parent->left = newNode;
    else parent->right = newNode;
}

bool ArvoreBinaria::verificaSimilaridade(No* root1, No* root2){
    if(root1 == nullptr && root2 == nullptr) return true;
    if (root1 == nullptr || root2 == nullptr) return false;
    return verificaSimilaridade(root1->left, root2->left) && verificaSimilaridade(root1->right, root2->right);
}

bool ArvoreBinaria::verificaIgualdade(No* root1, No* root2){
    if (root1 == nullptr && root2 == nullptr) return true;
    if (root1 == nullptr || root2 == nullptr) return false;
    return (root1->data == root2->data) && verificaIgualdade(root1->left, root2->left) && verificaIgualdade(root1->right, root2->right);
}

bool ArvoreBinaria::verificaSimilaridade(ArvoreBinaria& other){
    return verificaSimilaridade(root, other.root);
}

bool ArvoreBinaria::verificaIgualdade(ArvoreBinaria& other){
    return verificaIgualdade(root, other.root);
}