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
        void input();
        void print();
        void swap();
        void drop();
        void dup();
        void stop();
};

class Ops:Stack{
    public:
        void add();
        void sub();
        void mul();
        void div();
};

// Construtores

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
    arr[++size] = (arr[size - 1] + arr[size - 2]);
}

void Ops::sub(){
    arr[++size] = (arr[size - 1] - arr[size - 2]);
}

void Ops::mul(){
    arr[++size] = (arr[size - 1] * arr[size - 2]);
}

void Ops::div(){
    arr[++size] = (arr[size - 1] / arr[size - 2]);
}

// Main

string ins[10] = {
    "input", "print", "add",
    "sub", "mul", "div", "swap",
    "drop", "dup", "stop"
};

void isOk(string x){
    return count(0, 10, x);
}

int main(){
    class Ops s;
    while(true){

    }
}
