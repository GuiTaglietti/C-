#include "queue.h"
using namespace std;

int main(){
    Queue<int> q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout << q << endl;
    cout << "Vazio? " << q.empty() << endl;
    cout << "Possui o 30? " << q.find(30) << endl;
    cout << "Indice do 30: " << q.index_of(30) << endl;
    cout << "Quantidade de elementos: " << q.size() << endl;
    cout << "Removido o elemento: " << q.pop() << endl;
    cout << "Removido o elemento: " << q.pop() << endl;
    cout << "Quantidade de elementos: " << q.size() << endl;
    cout << q << endl;
    // q.push(15); q.push(15); q.push(15); --> Teste de queue overflow; 
    return 0;
}
