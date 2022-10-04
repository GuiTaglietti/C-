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
        void add();
        void sub();
        void mul();
        void div();
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
    arr[++size] = (arr[size] + arr[size - 1]);
}

void Ops::sub(){
    arr[++size] = (arr[size] - arr[size - 1]);
}

void Ops::mul(){
    arr[++size] = (arr[size] * arr[size - 1]);
}

void Ops::div(){
    arr[++size] = (arr[size] / arr[size - 1]);
}

// Globais

string ins[10] = {
    "input", "print", "add",
    "sub", "mul", "div", "swap",
    "drop", "dup", "stop"
};

char alg[11] = {
    '0', '1', '2',
    '3', '4', '5',
    '6', '7', '8',
    '9', '.'
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
    int ans = 0, ct = 0;
    for(char e : alg){
        if(e == x[ct]){
            ans++;
        }
        ct++;
    }
    if(ans == x.length()){
        return true;
    }
    return false;
}

int main(){
    Ops* s = new Ops(); // Inicializador
    string z = "12.83";
    cout << isNumber(z) << endl;
    return 0;
}
