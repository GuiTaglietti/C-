#include "stack.hpp"
#include <iostream> // Usado apenas para debug (Mostrar a pilha no método showStack())

void Stack::setMaxSize(int max_size){
    this->max_size = max_size;
}

int Stack::getMaxSize(){
    return this->max_size;
}

Stack::Stack(int size = 100){
    this->stack = new int[size];
    this->setMaxSize(size);
}

Stack::~Stack(){
    delete this->stack;
}

bool Stack::isEmpty(){
    return this->size == -1;
}

bool Stack::isFull(){
    return this->size + 1 == this->getMaxSize();
}

bool Stack::have(int value){
    for(int i = 0; i < this->size + 1; i++){
        if(this->stack[i] == value) return true;
    }
    return false;
}

void Stack::push(int value){
    if(!this->isFull()) this->stack[++this->size] = value;
}

int Stack::pop(){
    if(!this->isEmpty()) return this->stack[this->size--];
    return -1;
}

int Stack::lenght(){
    return this->size + 1;
}

int Stack::peek(){
    return this->stack[this->size];
}

void Stack::showStack(){
    std::cout << "Pilha: ";
    for(int i = 0; i < this->size + 1; i++){
        std::cout << this->stack[i] << " "; 
    }
    std::cout << std::endl;
}

Stack* Stack::operator+(Stack *stack){
    Stack *newStack = new Stack((this->size + 1) + (stack->size + 1));
    for(int i = 0; i < this->size + 1; i++) newStack->push(this->pop());
    for(int i = 0; i < stack->size + 1; i++) newStack->push(stack->pop());
    return newStack;
}
