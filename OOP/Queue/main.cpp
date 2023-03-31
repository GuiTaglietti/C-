#include "queue.cpp"

int main(){
    Queue fila1(10), fila2(20);

    fila1.push(10);
    fila1.push(20);
    std::cout << fila1;
    fila1.pop();
    std::cout << fila1;

    fila2.push(30);
    fila2.push(40);
    std::cout << fila2;

    Queue fila3 = fila1 + fila2;
    std::cout << "Fila 3 (Tamanho: " << fila3.getMaxSize() << ") --> " << fila3;
    return 0;
}
