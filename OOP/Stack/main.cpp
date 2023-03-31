#include "stack.cpp"

int main(){
    Stack teste1(10);
    teste1.push(10);
    teste1.push(20);
    //std::cout << teste1;
    teste1.debug();
    teste1.pop();

    Stack teste2(20);
    teste2.push(30);
    teste2.push(40);

    Stack teste3 = teste1 + teste2;
    teste3.debug();
    std::cout << "Tamanho da nova pilha: " << teste3.getMaxSize() << std::endl;
    return 0;
}
