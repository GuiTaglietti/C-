/*
    Gui Taglietti - Assets (Stack interpreter)
    192370
*/

#include <bits/stdc++.h>
using namespace std;

struct logger{
    string pos;
    float val; 
};

class Control{
    public:
        int findRange(string x){
            int range = 0;
            for(char c : x){
                if(c == ' '){
                    return range + 1;
                }
                range++;
            }
            return 0;
        }

        int findLenght(string x){
            int lenght = 0;
            string vars = "123456789.";
            if(findRange(x)){
                for(char c : x){
                    if(count(vars.begin(), vars.end(), c)){
                        lenght += count(vars.begin(), vars.end(), c);
                    }
                }
                return lenght;
            }
        }

        string hexString(string x){
            return x.substr(this->findRange(x), 2);
        }
        
        string lower(string x){
            for(int i = 0; i < x.length(); i++){
                x[i] = tolower(x[i]);
            }
            return x;
        }

        float toFloat(string x){
            return stof(x.substr(this->findRange(x), this->findLenght(x)));
        }

        int hexConverter(string x){
            return stoi(hexString(x), 0, 16);
        }

};

class Memory : public Control{
    protected:
        float mem[256];

    public:
        Memory(){
            memset(this->mem, 0, sizeof(this->mem));
        }
        
        void debug(){
            cout << "Memória: ";
            for(int i = 0; i < 5; i++){
                cout << this->mem[i] << " ";
            }
            cout << endl;
        }
        
        void memoryAssign(int local, float value){
            this->mem[local] = value;
        }

        float getMemory(string hex){
            return this->mem[this->hexConverter(hex)];
        }
};

class Stack{
    private:
        float arr[16];
        int size = -1;
    
    public:
        Stack(){
            memset(this->arr, 0, sizeof(this->arr));
        }
        
        void underflowError(){
            if(this->size < 0){
                throw underflow_error("STACK UNDERFLOW");
            }
        }
        
        void overflowError(){
            if(this->size > 14){
                throw underflow_error("STACK OVERFLOW");
            }
        };
        
        void push(float e){
            this->overflowError();
            this->arr[++this->size] = e; 
        }
        
        float pop(){
            this->underflowError();
            return this->arr[size--];
        }
        
        void show(){
            cout << "Valores restantes na pilha: ";
            for(int i = 0; i < this->size + 1; i++){
                cout << this->arr[i] << " ";
            }
            cout << endl;
        }
};

class Operations : public Stack{
    public:
        void pushMemory(string x, float value){
            Memory* m = new Memory();
            m->memoryAssign(m->hexConverter(x), value);
        }
        
        void input(){
            float aux;
            cout << "Digite o valor para ser inserido na pilha: " << endl;
            cin >> aux;
            this->push(aux);
        }
        
        void print(){
            cout << "Valor do topo da pilha: " << this->pop() << endl;
        }

        void add(){
            float n1 = this->pop();
            float n2 = this->pop();
            this->push(n2 + n1);
            cout << "Soma dos valores do topo: " << n1 + n2 << endl;
        }
        
        void sub(){
            float n1 = this->pop();
            float n2 = this->pop();
            this->push(n2 - n1);
            cout << "Subtração dos valores do topo: " << n1 - n2 << endl;
        }
        
        void mul(){
            float n1 = this->pop();
            float n2 = this->pop();
            this->push(n2 * n1);
            cout << "Multiplicação dos valores do topo: " << n1 * n2 << endl;
        }
        
        void div(){
            float n1 = this->pop();
            if(n1 == 0){
                throw runtime_error("DIVIDE BY ZERO ERROR");
            }
            float n2 = this->pop();
            this->push(n2 / n1);
            cout << "Divisão dos valores do topo: " << n1 / n2 << endl;
        }
        
        void swap(){
            float first = this->pop();
            float second = this->pop();
            this->push(first);
            this->push(second);
        }
        
        void drop(){
            this->pop();
        }
        
        void dup(){
            float aux = this->pop();
            this->push(aux);
            this->push(aux);
        }
        
        void hlt(){
            exit(0);
        }
};

int main(){
    Memory* m = new Memory();
    Operations* s = new Operations();
    cout << "Parse: " << m->hexString("PUSH 8A") << endl;
    cout << "Valor da parsed string: " << m->hexConverter("PUSH 8A") << endl;
    s->push(15.5);
    s->push(20.5);
    s->show();
    s->pop();
    s->show();
    m->debug();
    m->memoryAssign(2, 10.5);
    m->debug();
    s->push(m->getMemory("PUSH 02"));
    s->show();
    s->hlt();
}
