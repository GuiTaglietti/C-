#ifndef STACK_HPP
#define STACK_HPP

class Stack{
private:
    int *stack;
    int size = -1;
    int max_size;
    void setMaxSize(int max_size);
    
public:
    Stack();
    Stack(int size);
    Stack(const Stack &stack);
    int getMaxSize(); 
    virtual ~Stack();
    void push(int value);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    int lenght();
    bool have(int value);
    void showStack();
    void operator+(Stack *stack);
    //Stack& operator+=(Stack &stack1);    
};

#endif // STACK_HPP
