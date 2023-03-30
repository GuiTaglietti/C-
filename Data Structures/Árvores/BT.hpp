#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

class No{
public:
    int data;
    No* left;
    No* right;
    No(int data);
};

class ArvoreBinaria{
private:
    No* root;
    bool verificaSimilaridade(No* root1, No* root2); // Método privado usando polimorfismo
    bool verificaIgualdade(No* root1, No* root2); // Mesmo esquema do método acima

public:
    ArvoreBinaria();
    void inserir(int data);
    bool verificaSimilaridade(ArvoreBinaria& other); // Método público que chama o privado para verificações
    bool verificaIgualdade(ArvoreBinaria& other); // Mesmo esquema e bla bla bla...
};

#endif // BT_HPP
