#ifndef STACK_HPP
#define STACK_HPP

class Stack{
private:
    int *stack;
    int size = -1;
    int max_size;
    void setMaxSize(int max_size);
    int getMaxSize(); 
    
public:
    Stack();
    Stack(int size);
    virtual ~Stack();
    void push(int value);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    int lenght();
    bool have(int value);
    void showStack();
    Stack* operator+(Stack *stack);    
};

#endif // STACK_HPP
