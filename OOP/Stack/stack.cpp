#include "stack.hpp"
#include <iostream> // Usado apenas para debug (Mostrar a pilha no método showStack())

void Stack::setMaxSize(int max_size){
    this->max_size = max_size;
}

int Stack::getMaxSize(){
    return this->max_size;
}

Stack::Stack(){
    this->stack = new int[100];
    this->setMaxSize(100);
}

Stack::Stack(int size = 100){
    this->stack = new int[size];
    this->setMaxSize(size);
}

Stack::Stack(const Stack &stack){
    this->size = stack.size;
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

/*
Stack& Stack::operator+=(Stack &stack){
    int i, j;
    this->size = this->size + stack.size;
    for(i = 0; i < this->size; i++)
        this->stack[i] = this->stack[i];
    for(j = size; j < stack.size; j++, i++)
        this->stack[i] = stack.stack[i];
    return *this;
}
*/

void Stack::operator+(Stack *stack){
    int new_size = this->getMaxSize() + stack->getMaxSize();
    Stack *buffer = new Stack(new_size);
    for(int i = 0; i < this->size + 2; i++) buffer->push(this->stack[i]);
    for(int i = 0; i < stack->size + 1; i++) buffer->push(stack->stack[i]);
    this->stack = new int[new_size];
    this->setMaxSize(new_size);
    for(int i = 0; i < buffer->lenght(); i++) this->push(buffer->stack[i]);
    delete buffer;
}
