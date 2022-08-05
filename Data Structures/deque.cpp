#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

class Deque{
    int num;

    private:
        int arr[MAX];
        int size = 0;
        int control = 0;

    public:
        Deque(){
            num = 1;
        };
        void pushFront(int element);
        void pushBack(int element);
        void show();
        int popFront();
        int popBack();
        int front();
        int back();
        int len();
        bool have(int finder);
        bool isEmpty();
};

void Deque::pushBack(int element){
    arr[size] = element;
    size++;
}

void Deque::pushFront(int element){
    for(int i = size; i > 0; i--){
        arr[i] = arr[i - 1];
    }
    arr[0] = element; 
    size++;
}

int Deque::front(){
    if(!isEmpty()){
        return arr[0];
    }
    return NULL;
}

int Deque::back(){
    if(!isEmpty()){
        return arr[size - 1];
    }
    return NULL;
}

bool Deque::isEmpty(){
    return size <= 0;
}

int Deque::popFront(){
    if(!isEmpty()){
        for(int i = 0; i < size; i++){
            arr[i] = arr[i + 1];
        }
        size--;
    }
    return NULL;
}

int Deque::popBack(){
    if(!isEmpty()){
        size--;
        return arr[size];
    }
    return NULL;
}

int Deque::len(){
    return size;
}

bool Deque::have(int finder){
    if(control == 0){
        for(int i = 0; i < size; i++){
            if(arr[i] == finder){
                return true;
            }
        }
        return false;
    }
    else{
        for(int i = 0; i < size + 1; i++){
            if(arr[i] == finder){
                return true;
            }
        }
        return false;
    }
}

void Deque::show(){
    if(control == 0){
        cout << "Sua deque: ";
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << "Sua deque: ";
        for(int i = 0; i < size + 1; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    class Deque d;
    d.pushBack(10);
    d.pushBack(15);
    cout << d.len() << endl;
    d.show();
    d.pushFront(20);
    d.show();
    d.popFront();
    d.pushFront(50);
    d.popBack();
    d.show();
    cout << "Front: " << d.front() << endl;
    cout << "Back: " << d.back() << endl;
    cout << "Existe o elemento inteiro 15 na fila?(1 = SIM // 0 = NÃO): " << d.have(15) << endl;
    cout << "A fila está vazia?(1 = SIM // 0 = NÃO): " << d.isEmpty() << endl;
    cout << "Tamanho da fila: " << d.len() << endl;
    return 0;
}
