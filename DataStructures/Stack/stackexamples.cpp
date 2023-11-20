#include "stack.h"
using namespace std;

int main(){
    Stack<int> st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout << st << endl;
    cout << "Vazio? " << st.empty() << endl;
    cout << "Possui o 30? " << st.find(30) << endl;
    cout << "Indice do 30: " << st.index_of(30) << endl;
    cout << "Quantidade de elementos: " << st.size() << endl;
    cout << "Removido o elemento: " << st.pop() << endl;
    cout << "Removido o elemento: " << st.pop() << endl;
    cout << "Quantidade de elementos: " << st.size() << endl;
    cout << st << endl;
    // st.push(15); st.push(15); st.push(15); --> Teste de stack overflow; 
    return 0;
}