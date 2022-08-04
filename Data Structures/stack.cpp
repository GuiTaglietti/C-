#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

class Stack{
    int num;
    
    private:
        int arr[MAX];
        int size = 0;
    
    public:
        Stack(){
            num = -1;
        };
        void push(int element);
        int pop();
        bool isEmpty();
        int peek();
        int len();
        bool have(int number);
        void print();
};

void Stack::push(int element){
    arr[size] = element;
    size++;
}

int Stack::pop(){
    if(size > 0){
        size--;
        return arr[size];
    }
    return 0; 
}

bool Stack::isEmpty(){
    if(size == 0){
        return true;
    }
    return false;
}

int Stack::peek(){
    if(!isEmpty()){
        return arr[size - 1];
    }
    else{
        return NULL;
    }
}

int Stack::len(){
    return size;
}

bool Stack::have(int number){
    for(int i = 0; i < size; i++){
        if(arr[i] == number){
            return true;
        }
    }
    return false;
}

void Stack::print(){
    cout << "Sua pilha: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " "; 
    }
    cout << endl;
}

int main(){
    class Stack s;
    s.push(10);
    s.push(20);
    s.print();
    s.pop();
    s.print();
    cout << "Contém o elemento?(1 = Sim // 0 = Não): " << s.have(10) << endl;
    cout << "Está vazia?(1 = Sim // 0 = Não): " << s.isEmpty() << endl;
    cout << "Ultimo item da pilha(Caso exista): " << s.peek() << endl;
    cout << "Tamanho da pilha: " << s.len() << endl;
    return 0;
}
