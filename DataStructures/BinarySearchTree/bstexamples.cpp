#include "binarytree.h"

int main(){
    datastructures::BinaryTree<int> bst;
    
    std::cout << "Altura: " << bst.height() << std::endl;
    std::cout << "Número de nodos: " << bst.get_num_nodes() << std::endl;
    std::cout << "Preorder: "; bst.preorder(); std::cout << std::endl;
    std::cout << "Inorder: "; bst.inorder(); std::cout << std::endl;
    std::cout << "Postorder: "; bst.postorder(); std::cout << std::endl << std::endl;

    bst.insert(10);
    bst.insert(8);
    bst.insert(12);
    bst.insert(7);
    bst.insert(11);

    std::cout << "Altura: " << bst.height() << std::endl;
    std::cout << "Número de nodos: " << bst.get_num_nodes() << std::endl;
    std::cout << "Preorder: "; bst.preorder(); std::cout << std::endl;
    std::cout << "Inorder: "; bst.inorder(); std::cout << std::endl;
    std::cout << "Postorder: "; bst.postorder(); std::cout << std::endl << std::endl;

    bst.remove(8);

    std::cout << "Altura: " << bst.height() << std::endl;
    std::cout << "Número de nodos: " << bst.get_num_nodes() << std::endl;
    std::cout << "Preorder: "; bst.preorder(); std::cout << std::endl;
    std::cout << "Inorder: "; bst.inorder(); std::cout << std::endl;
    std::cout << "Postorder: "; bst.postorder(); std::cout << std::endl << std::endl;

    return 0;
}
