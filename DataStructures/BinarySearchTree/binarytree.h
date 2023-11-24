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
    void insert(T val);
    Node* find(T val) const noexcept;
    void remove(T val);
    [[nodiscard]] constexpr bool empty() const noexcept;
    [[nodiscard]] int height() const noexcept;
    [[nodiscard]] std::size_t get_num_nodes() const noexcept;
    void preorder() const noexcept;
    void inorder() const noexcept;
    void postorder() const noexcept;
    BinaryTree& operator=(const BinaryTree &rhs);

private:
    typedef struct Node{
        T val;
        Node* left;
        Node* right;
        Node(T _val) : val(_val), left(nullptr), right(nullptr){}
    } Node;

    Node* root;
    std::size_t num_nodes;
    [[nodiscard]] Node* treecpy(Node* node) noexcept;
    void yield_tree_mem(Node* node) noexcept;
    Node* insert(Node* &root, T val);
    [[nodiscard]] Node* find(Node* node, T val) const noexcept;
    [[nodiscard]] Node* remove(Node* node, T val);
    [[nodiscard]] int height(Node* node) const noexcept;
    void preorder(Node* node) const noexcept;
    void inorder(Node* node) const noexcept;
    void postorder(Node* node) const noexcept;
};

template <class T>
BinaryTree<T>::BinaryTree() : root(nullptr), num_nodes(0){}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree &cpy) : num_nodes(0){
    root = treecpy(cpy.root);
}

template <class T>
BinaryTree<T>::~BinaryTree(){
    yield_tree_mem(root);
    root = nullptr;
    num_nodes = 0;
}

template <class T>
[[nodiscard]] typename BinaryTree<T>::Node* BinaryTree<T>::treecpy(Node* node) noexcept{
    if(!node) return nullptr;
    Node* temp = new Node(node->val);
    temp->left = treecpy(node->left);
    temp->right = treecpy(node->right);
    return temp;
}

template <class T>
void BinaryTree<T>::yield_tree_mem(Node* node) noexcept{
    if(!node) return;
    yield_tree_mem(node->left);
    yield_tree_mem(node->right);
    delete node;
}

template <class T>
typename BinaryTree<T>::Node* BinaryTree<T>::insert(Node* &node, T val){
    if(!node){
        node = new Node(val);
        num_nodes++;
        return node;
    }
    else if(node->val > val) return insert(node->left, val);
    else if(node->val < val) return insert(node->right, val);
    else throw std::logic_error("BSTree already have this value!");
}

template <class T>
inline void BinaryTree<T>::insert(T val){
    insert(root, val);
}

template <class T>
[[nodiscard]] typename BinaryTree<T>::Node* BinaryTree<T>::find(Node* node, T val) const noexcept{
    if(!node) return nullptr;
    if(node->val == val) return node;
    else if(val < node->val) return find(node->left, val);
    else return find(node->right, val);
}

template <class T>
inline typename BinaryTree<T>::Node* BinaryTree<T>::find(T val) const noexcept{
    return find(root, val);
}

template <class T>
[[nodiscard]] typename BinaryTree<T>::Node* BinaryTree<T>::remove(Node* node, T val){
    if(!node) return nullptr;
    auto min = [](Node* n){
        while(n->left) 
            n = n->left;
        return n;
    }; 
    if(val < node->val) node->left = remove(node->left, val);
    else if(val > node->val) node->right = remove(node->right, val);
    else{
        if(!node->left){
            Node* temp = node->right;
            delete node;
            return temp;
        } 
        else if(!node->right){
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = min(node->right);
        node->val = temp->val;
        node->right = remove(node->right, temp->val);
    }
    num_nodes--;
    return node;
}

template <class T>
inline void BinaryTree<T>::remove(T val){
    root = remove(root, val);
}

template <class T>
[[nodiscard]] inline constexpr bool BinaryTree<T>::empty() const noexcept{
    return root == nullptr;
}

template <class T>
[[nodiscard]] int BinaryTree<T>::height(Node* node) const noexcept{
    if(!node) return -1;
    auto max = [](int a, int b){
        if(a > b) return a;
        return b;
    };
    int lh = height(node->left);
    int rh = height(node->right);
    return max(lh, rh) + 1;
}

template <class T>
[[nodiscard]] inline int BinaryTree<T>::height() const noexcept{
    return height(root);
}

template <class T>
[[nodiscard]] inline std::size_t BinaryTree<T>::get_num_nodes() const noexcept{
    return num_nodes;
}

template <class T>
void BinaryTree<T>::preorder(Node* node) const noexcept{
    if(!node) return;
    std::cout << node->val << " ";
    preorder(node->left);
    preorder(node->right);
}

template <class T>
inline void BinaryTree<T>::preorder() const noexcept{
    preorder(root);
}

template <class T>
void BinaryTree<T>::inorder(Node* node) const noexcept{
    if(!node) return;
    inorder(node->left);
    std::cout << node->val << " ";
    inorder(node->right);
}

template <class T>
inline void BinaryTree<T>::inorder() const noexcept{
    inorder(root);
}

template <class T>
void BinaryTree<T>::postorder(Node* node) const noexcept{
    if(!node) return;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->val << " ";
}

template <class T>
inline void BinaryTree<T>::postorder() const noexcept{
    postorder(root);
}

template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree &rhs){
    if(this != &rhs){
        yield_tree_mem(root);
        root = treecpy(rhs.root);
        num_nodes = rhs.num_nodes;
    }
    return *this;
}

}

#endif
