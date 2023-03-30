#include "BST.cpp"

int main(int argc, char *argv[]) {
    ArvoreBinaria bst;
    for(int i = 1; i < argc; i++) {
        int valor = atoi(argv[i]);
        bst.inserir(valor);
    }
    std::cout << "Número de nós da árvore: " << bst.getNumNos() << std::endl;
    std::cout << "Número de nós folha da árvore: " << bst.getNumNosFolha() << std::endl;
    std::cout << "Número de nós não-folha da árvore: " << bst.getNumNosNaoFolha() << std::endl;
    std::cout << "Altura da árvore: " << bst.getAltura() << std::endl;
    std::cout << "Maior valor da árvore: " << bst.getMaiorValor() << std::endl;
    if (bst.isEstritamenteBinaria()) {
        std::cout << "A árvore é estritamente binária." << std::endl;
    } else {
        std::cout << "A árvore não é estritamente binária." << std::endl;
    }
    std::cout << "Árvore original: ";
    bst.mostrarArvore();
    std::cout << std::endl;
    bst.espelho();
    std::cout << "Árvore espelho: " << std::endl;
    bst.mostrarArvore();
    return 0;
}