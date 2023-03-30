#include "BinaryTree.cpp"

int main(){
    BinaryTree btree;
    btree.insert(8);
    btree.insert(11);
    btree.insert(7);
    btree.insert(3);
    btree.insert(14);
    btree.insert(21);
    btree.insert(6);
    std::cout << "Percorrendo a árvore de maneira infixa:" << std::endl;
    btree.inOrder(btree.getRoot());
    std::cout << std::endl;
    std::cout << "Percorrendo a árvore de maneira prefixa:" << std::endl;
    btree.preOrder(btree.getRoot());
    std::cout << std::endl;
    std::cout << "Percorrendo a árvore de maneira pósfixa:" << std::endl;
    btree.posOrder(btree.getRoot());
    std::cout << std::endl;
    return 0;
}