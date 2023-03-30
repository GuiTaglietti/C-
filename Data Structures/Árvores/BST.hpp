#ifndef BST_HPP
#define BST_HPP

class No{
public:
    int valor;
    No *esquerda;
    No *direita;
    No(int valor);
};

class ArvoreBinaria{
private:
    No *raiz;
    int numNos(No *no);
    int numNosFolha(No *no);
    int numNosNaoFolha(No *no);
    int altura(No *no);
    int maiorValor(No *no);
    bool estritamenteBinaria(No *no);
    No* espelho(No *no);
    void mostrarOrdenado(No* no);

public:
    ArvoreBinaria();
    void inserir(int valor);
    int getNumNos();
    int getNumNosFolha();
    int getNumNosNaoFolha();
    int getAltura();
    int getMaiorValor();
    bool isEstritamenteBinaria();
    void espelho();
    void mostrarArvore();
};

#endif // BST_HPP