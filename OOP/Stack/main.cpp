//#include <iostream> -- Comentado pois está incluso na classe para fins de debug  
#include "stack.cpp"
using namespace std;

int main(){
    Stack *teste1 = new Stack(10);
    Stack *teste2 = new Stack(10);
    teste1->push(10);
    teste1->push(20);
    teste2->push(30);
    teste2->push(40);
    teste1->showStack();
    teste1->pop();
    teste1->showStack();
    teste1 += teste2;
    return 0;
}
