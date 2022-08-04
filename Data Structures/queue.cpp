#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

class Queue{
    int n;
    
    private:
        int arr[MAX];
        int size = 0;
        int start = 0;
        int control = 0;
    
    public:
        Queue(){
            n = 1;
        };
        void push(int element);
        int pop();
        int front();
        int len();
        bool isEmpty();
        bool have(int finder);
        void show();
};

void Queue::push(int element){
    arr[size] = element;
    size++;
}

int Queue::pop(){
    if(size > 0){
        size--;
        start++;
        control++;
        return arr[0];
    }
    return NULL;
}

int Queue::front(){
    if(size > 0){
        return arr[size];
    }
    return NULL;
}

int Queue::len(){
    return size;
}

bool Queue::isEmpty(){
    return size <= 0;
}

bool Queue::have(int finder){
    if(control == 0){
        for(int i = start; i < size; i++){
            if(arr[i] == finder){
                return true;
            }
        }
        return false;
    }
    else{
        for(int i = start; i < size + 1; i++){
            if(arr[i] == finder){
                return true;
            }
        }
        return false;
    }
}

void Queue::show(){
    if(control == 0){
        cout << "Sua fila: ";
        for(int i = start; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << "Sua fila: ";
        for(int i = start; i < size + 1; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    class Queue q;
    q.push(10);
    q.push(15);
    q.push(20);
    q.show();
    q.pop();
    q.show();
    cout << "Existe o elemento inteiro 15 na fila?(1 = SIM // 0 = NÃO): " << q.have(15) << endl;
    cout << "A fila está vazia?(1 = SIM // 0 = NÃO): " << q.isEmpty() << endl;
    cout << "Tamanho da fila: " << q.len() << endl;
    cout << "Último elemento da fila: " << q.front() << endl;
    return 0;
}
