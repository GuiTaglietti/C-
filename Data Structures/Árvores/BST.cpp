#include "BST.hpp"
#include <iostream> // Usado para o cout na árvore
#include <algorithm> //Usado para a função de max()

/*
    Define o valor mínimo que possa ser retornado pela árvore
*/
#define INT_MIN -1e9 

/*
    Constrói os métodos da classe No
*/

No::No(int valor){
    this->valor = valor;
    this->esquerda = NULL;
    this->direita = NULL;
}

/*
    Constrói os métodos da classe ÁrvoreBinaria
*/

ArvoreBinaria::ArvoreBinaria(){}

int ArvoreBinaria::numNos(No *no){
    if(no == NULL) return 0;
    return 1 + numNos(no->esquerda) + numNos(no->direita);
}

int ArvoreBinaria::numNosFolha(No *no){
    if(no == NULL) return 0;
    if(no->esquerda == NULL && no->direita == NULL) return 1;
    return numNosFolha(no->esquerda) + numNosFolha(no->direita);
        
}

int ArvoreBinaria::numNosNaoFolha(No *no){
    if(no == NULL) return 0;
    if(no->esquerda == NULL && no->direita == NULL) return 0;
    return 1 + numNosNaoFolha(no->esquerda) + numNosNaoFolha(no->direita);
}

int ArvoreBinaria::altura(No *no){
    if(no == NULL) return -1;
    int alturaEsquerda = altura(no->esquerda);
    int alturaDireita = altura(no->direita);
    return 1 + std::max(alturaEsquerda, alturaDireita);
}

int ArvoreBinaria::maiorValor(No *no){
    if(no == NULL) return INT_MIN;
    return std::max(no->valor, std::max(maiorValor(no->esquerda), maiorValor(no->direita)));
}

bool ArvoreBinaria::estritamenteBinaria(No *no){
    if(no == NULL) return true;
    if (no->esquerda == NULL && no->direita == NULL) return true;
    if (no->esquerda != NULL && no->direita != NULL) return estritamenteBinaria(no->esquerda) && estritamenteBinaria(no->direita);
    return false;
}

No* ArvoreBinaria::espelho(No *no) {
    if(no == NULL) return NULL;
    No *temp = no->esquerda;
    no->esquerda = espelho(no->direita);
    no->direita = espelho(temp);
    return no;
}

void ArvoreBinaria::mostrarOrdenado(No* no){
    if(no){
        mostrarOrdenado(no->esquerda);
        std::cout << no->valor << " ";
        mostrarOrdenado(no->direita);
    }
}

void ArvoreBinaria::inserir(int valor) {
    No *novo = new No(valor);
    if(raiz == NULL) raiz = novo;
    else {
        No *atual = raiz;
        No *anterior;
        while(atual != NULL){
            anterior = atual;
            if(valor < atual->valor) atual = atual->esquerda;
            else atual = atual->direita;
        }
        if (valor < anterior->valor) anterior->esquerda = novo;
        else anterior->direita = novo;
    }
}
    
int ArvoreBinaria::getNumNos() {
    return numNos(raiz);
}

int ArvoreBinaria::getNumNosFolha() {
    return numNosFolha(raiz);
}

int ArvoreBinaria::getNumNosNaoFolha() {
    return numNosNaoFolha(raiz);
}

int ArvoreBinaria::getAltura() {
    return altura(raiz);
}

int ArvoreBinaria::getMaiorValor() {
    return maiorValor(raiz);
}

bool ArvoreBinaria::isEstritamenteBinaria() {
    return estritamenteBinaria(raiz);
}

void ArvoreBinaria::espelho() {
    raiz = espelho(raiz);
}

void ArvoreBinaria::mostrarArvore(){
    this->mostrarOrdenado(this->raiz);
}