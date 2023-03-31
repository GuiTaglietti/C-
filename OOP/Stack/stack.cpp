#include "stack.hpp"

Stack::Stack():Stack(100){}

Stack::Stack(int size){
    this->stack = new int[size];
    this->setMaxSize(size);
}

Stack::Stack(const Stack &stack){ // Construtor de cópia
    this->stack = stack.stack;
    this->size = stack.size;
    this->max_size = stack.max_size;
}

Stack::~Stack(){
    delete this->stack;
}

bool Stack::have(int value) const{
    for(int i = 0; i < this->size; i++){
        if(this->stack[i] == value) return true;
    }
    return false;
}

void Stack::push(int value){
    if(!this->isFull()) this->stack[this->size++] = value;
}

int Stack::pop(){
    if(!this->isEmpty()) return this->stack[this->size--];
    return -1;
}

Stack Stack::operator+(const Stack &stack){
    int new_size = this->getMaxSize() + stack.getMaxSize();
    Stack new_stack(new_size);
    for(int i = 0; i < this->size; i++) new_stack.push(this->stack[i]);
    for(int i = 0; i < stack.size; i++) new_stack.push(stack.stack[i]);
    return new_stack;
}

Stack Stack::operator=(Stack &stack){
    delete this->stack;
    Stack new_stack(stack); // Chama o construtor de cópia
    return new_stack;
}


std::ostream& operator<<(std::ostream &os, const Stack &stack){
    os << "Pilha: ";
    for(int i = 0; i < stack.size; i++){
        os << stack.stack[i] << " "; 
    }
    os << std::endl;
    return os;
}
