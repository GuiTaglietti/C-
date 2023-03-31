#ifndef STACK_HPP
#define STACK_HPP
#include <iostream> // Incluso para a sobrecarga de operador << (Usando a classe std::ostream)

class Stack{
private:
    int *stack;
    int size = 0;
    int max_size;
    void setMaxSize(int max_size) {this->max_size = max_size;} 
    
public:
    Stack();
    Stack(int size);
    Stack(const Stack &stack);
    int getMaxSize() const {return this->max_size;} 
    virtual ~Stack();
    void push(int value);
    int pop();
    int peek() const {return this->stack[this->size];}
    bool isEmpty() const {return this->size == 0;}
    bool isFull() const {return this->size == this->max_size;}
    int lenght() const {return this->size;}
    bool have(int value) const;
    Stack operator+(const Stack &stack);
    Stack operator=(Stack &stack);
    friend std::ostream& operator<<(std::ostream os, const Stack &stack);  
};

#endif // STACK_HPP
