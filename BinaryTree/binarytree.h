/**
 * @author Guilherme Martinelli Taglietti
 * @brief Binary tree implementation
*/
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <exception>

namespace datastructures{

template <class T>
class BinaryTree{
private: struct Node;
public:
    BinaryTree();
    BinaryTree(const BinaryTree &cpy);
    virtual ~BinaryTree();
    Node* insert(Node* &root, T val);
    Node* find(T val) const noexcept;
    void remove(T val) noexcept;
    [[nodiscard]] constexpr bool empty() const;
    void preorder() const noexcept;
    void inorder() const noexcept;
    void posorder() const noexcept;
    BinaryTree& operator=(const BinaryTree &rhs);

private:
    struct Node{
        T val;
        Node* left;
        Node* right;
        Node(T _val) : val(_val), left(nullptr), right(nullptr){}
    };

    Node* root;
};

template <class T>
BinaryTree<T>::BinaryTree() : root(nullptr){}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree &cpy){
    // Terminar...
}

template <class T>
BinaryTree<T>::~BinaryTree(){
    // Terminar...
}

template <class T>
typename BinaryTree<T>::Node* BinaryTree<T>::insert(Node* &root, T val){
    if(!root){
        root = new Node(val);
        return root;
    }
    else if(root->val < val) return insert(root->right, val);
    else if(root->val > val) return insert(root->left, val);
    else throw std::logic_error("BTree already have this value!")
}

template <class T>
typename BinaryTree<T>::Node* BinaryTree<T>::find(T val) const noexcept{
    // Terminar...
}

template <class T>
void BinaryTree<T>::remove(T val) noexcept{
    // Terminar...
}

template <class T>
inline constexpr bool BinaryTree<T>::empty() const{
    return root == nullptr;
}

template <class T>
void BinaryTree<T>::preorder() const noexcept{
    // Terminar...
}

template <class T>
void BinaryTree<T>::inorder() const noexcept{
    // Terminar...
}

template <class T>
void BinaryTree<T>::posorder() const noexcept{
    // Terminar...
}

template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree &rhs){
    if(this != &rhs){
        // Terminar...
    }
    return *this;
}

}

#endif
