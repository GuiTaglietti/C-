#include <bits/stdc++.h>
using namespace std;

/*
    Gui Taglietti - 192370
    Hash table class implementation
*/

class TabelaHash {
private:
    // Estrutura para usar o sistema chave-valor
    struct Nodo {
        int chave;
        int valor;
        Nodo* prox;
        Nodo(int chv, int vlr) : chave(chv), valor(vlr), prox(nullptr){} // Construtor da struct
    };

    // Atributos e STL
    vector<Nodo*> vet;

    // Método para achar a hash com base na função de divisão
    int hash(int chave) {
        return chave % vet.size();
    }

public:
    // Construtor para mostrar o método usado (segundo a atividade pede...)
    TabelaHash(){
        cout << "Objeto de tabela hash criado com sucesso!" << endl;
        cout << "Método usado: método da divisão" << endl;
    }

    // Método de inserção
    void inserir(int chave, int valor) {
        int pos = hash(chave);
        Nodo* nodo = vet[pos];
        while (nodo != nullptr) {
            if (nodo->chave == chave) {
                nodo->valor = valor;
                return;
            }
            nodo = nodo->prox;
        }
        Nodo* novo_nodo = new Nodo(chave, valor);
        novo_nodo->prox = vet[pos];
        vet[pos] = novo_nodo;
    }

    // Método de busca
    int buscar(int chave) {
        int pos = hash(chave);
        Nodo* nodo = vet[pos];
        while (nodo != nullptr) {
            if (nodo->chave == chave) {
                return nodo->valor;
            }
            nodo = nodo->prox;
        }
        return -1;
    }

    // Método de remoção
    void remover(int chave) {
        int pos = hash(chave);
        Nodo* nodo = vet[pos];
        Nodo* prev = nullptr;
        while (nodo != nullptr) {
            if (nodo->chave == chave) {
                if (prev == nullptr) {
                    vet[pos] = nodo->prox;
                } else {
                    prev->prox = nodo->prox;
                }
                delete nodo;
                return;
            }
            prev = nodo;
            nodo = nodo->prox;
        }
    }
};

/*
int main(){
    TabelaHash ht;
    ht.inserir(1, 10);
    ht.inserir(2, 20);
    ht.inserir(11, 30);
    cout << ht.buscar(1) << endl; 
    cout << ht.buscar(2) << endl; 
    cout << ht.buscar(11) << endl; 
    ht.remover(2);
    cout << ht.buscar(2) << endl; 
    return 0;
}
*/
