/*
    Gui Taglietti - Stack Interpreter
    192370
*/

// Headers

#include <bits/stdc++.h>
using namespace std;

// Classes
 
class Stack{
    protected:
        int size = -1;
        double arr[16];

    public:
        Stack(){};
        bool isFull();
        bool isEmpty();
        void input();
        void print();
        void swap();
        void drop();
        void dup();
        void stop();
        void debug();
};

class Ops : public Stack{
    public:
        Ops(){};
        void add();
        void sub();
        void mul();
        void div();
};

// Construtores

void Stack::debug(){
    cout << "Pilha: ";
    for(int i = 0; i < size; i++){
        cout << arr[i];
    }
    cout << endl;
    cout << "Size: " << size << endl;
}

bool Stack::isFull(){
    return size >= 15;
}

bool Stack::isEmpty(){
    return size < 0;
}

void Stack::input(){
    cout << "Digite um número: " << endl;
    cin >> arr[++size];
}

void Stack::print(){
    cout << arr[size] << endl;
}

void Stack::swap(){
    double aux = arr[size];
    arr[size] = arr[size - 1];
    arr[size - 1] = aux;
}

void Stack::drop(){
    size--;
}

void Stack::dup(){
    arr[++size] = arr[size - 1];
}

void Stack::stop(){
    exit(0);
}

void Ops::add(){
    arr[0] = (arr[size] + arr[size - 1]);
    size = 0;
}

void Ops::sub(){
    arr[0] = (arr[size] - arr[size - 1]);
    size = 0;
}

void Ops::mul(){
    arr[0] = (arr[size] * arr[size - 1]);
    size = 0;
}

void Ops::div(){
    arr[0] = (arr[size] / arr[size - 1]);
    size = 0;
}

// Globais

string ins[10] = {
    "input", "print", "add",
    "sub", "mul", "div", "swap",
    "drop", "dup", "stop"
};

string lower(string x){
    for(int i = 0; i < x.length(); i++){
        x[i] = tolower(x[i]);
    }
    return x;
}

bool isOk(string x){
    for(string e : ins){
        if(lower(e) == lower(x)){
            return true;
        }
    }
    return false;
}

bool isNumber(string x){
   string alg = "0123456789.";
   for(char e : x){
        if(count(alg.begin(), alg.end(), e) == 0){
            return false;
        }
    }
    return true;
}

int main(){
    Ops* s = new Ops(); // Inicializador
    s->input();
    s->input();
    s->debug();
    s->add();
    s->debug();
    return 0;
}
