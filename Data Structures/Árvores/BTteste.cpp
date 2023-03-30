#include <iostream>
#include "BT.cpp"
using namespace std;

int main() {
    ArvoreBinaria tree1, tree2;
    int n1, n2;
    cout << "Digite a quantidade de elementos da primeira árvore: ";
    cin >> n1;
    cout << "Digite os elementos da primeira árvore: ";
    for (int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        tree1.inserir(x);
    }
    cout << "Digite a quantidade de elementos da segunda árvore: ";
    cin >> n2;
    cout << "Digite os elementos da segunda árvore: ";
    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        tree2.inserir(x);
    }
    if (tree1.verificaSimilaridade(tree2)) {
        cout << "As arvores sao similares" << endl;
    } else {
        cout << "As arvores nao sao similares" << endl;
    }
    if (tree1.verificaIgualdade(tree2)) {
        cout << "As arvores sao iguais" << endl;
    } else {
        cout << "As arvores nao sao iguais" << endl;
    }
    return 0;
}