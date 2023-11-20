#include "deque.h"
using namespace std;

int main(){
    Deque<int> dq(10);
    cout << "Deque: " << dq << endl;
    cout << "Vazia? " << dq.empty() << endl;
    // cout << "Primeiro elemento: " << dq.front() << endl; --> Testar exceptions
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    cout << "Deque: " << dq << endl;
    cout << "Vazia? " << dq.empty() << endl;
    cout << "Possui o 3? " << ((dq.index_of(3) != -1) ? "Sim!" : "Não") << " - Índice do 3: " << dq.index_of(3) << endl;
    cout << "Possui o 5? " << ((dq.index_of(5) != -1) ? "Sim!" : "Não") << " - Índice do 5: " << dq.index_of(5) << endl;
    cout << "Primeiro elemento: " << dq.front() << endl;
    cout << "Segundo elemento: " << dq.back() << endl;
    cout << "Tamanho: " << dq.size() << endl;
    cout << "Tamanho máximo (limite): " << dq.max_size() << endl;
    dq.push_front(4);
    dq.push_front(5);
    cout << "Deque: " << dq << endl;
    cout << "Vazia? " << dq.empty() << endl;
    cout << "Possui o 3? " << ((dq.index_of(3) != -1) ? "Sim!" : "Não") << " - Índice do 3: " << dq.index_of(3) << endl;
    cout << "Possui o 5? " << ((dq.index_of(5) != -1) ? "Sim!" : "Não") << " - Índice do 5: " << dq.index_of(5) << endl;
    cout << "Primeiro elemento: " << dq.front() << endl;
    cout << "Segundo elemento: " << dq.back() << endl;
    cout << "Tamanho: " << dq.size() << endl;
    cout << "Tamanho máximo (limite): " << dq.max_size() << endl;
    dq.pop_back();
    dq.pop_front();
    cout << "Deque: " << dq << endl;
    cout << "Vazia? " << dq.empty() << endl;
    cout << "Possui o 3? " << ((dq.index_of(3) != -1) ? "Sim!" : "Não") << " - Índice do 3: " << dq.index_of(3) << endl;
    cout << "Possui o 5? " << ((dq.index_of(3) != -1) ? "Sim!" : "Não") << " - Índice do 5: " << dq.index_of(3) << endl;
    cout << "Primeiro elemento: " << dq.front() << endl;
    cout << "Segundo elemento: " << dq.back() << endl;
    cout << "Tamanho: " << dq.size() << endl;
    cout << "Tamanho máximo (limite): " << dq.max_size() << endl;
    return 0;
}