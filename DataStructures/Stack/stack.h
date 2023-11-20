#ifndef STACK_H
#define STACK_H

#include <iostream>

typedef unsigned int index_t;

template <class T>
class Stack{
public:
    Stack();
    Stack(size_t _SIZE);
    Stack(const Stack &cpy);
    virtual ~Stack();
    size_t size() const;
    void push(T element);
    T pop();
    bool find(T element) const;
    bool empty() const;
    int index_of(T element) const;
    Stack<T> &operator=(const Stack &rhs);
    template <class FT>
    friend std::ostream &operator<<(std::ostream &os, const Stack<FT> &stack);

private:
    size_t MAXSIZE;
    index_t CURRENT = 0;
    T *STACK;
};

template <class T>
Stack<T>::Stack() : Stack(1000){}

template <class T>
Stack<T>::Stack(size_t _SIZE){
    MAXSIZE = _SIZE;
    STACK = new T[MAXSIZE];
}

template <class T>
Stack<T>::Stack(const Stack<T> &stack){
    MAXSIZE = stack.size();
    STACK = new T[MAXSIZE];
    #pragma omp parallel for
    for(size_t i = 0; i < MAXSIZE; i++)
        STACK[i] = stack.STACK[i];
}

template <class T>
Stack<T>::~Stack(){
    delete[] STACK;
}

template <class T>
inline bool Stack<T>::empty() const{
    return CURRENT == 0;
}

template <class T>
inline size_t Stack<T>::size() const{
    return CURRENT;
}

template <class T>
bool Stack<T>::find(T element) const{
    // return std::find(STACK, STACK + CURRENT, element) != std::end(STACK); -- Possível implementação pronta/eficiente
    if(!empty())
        for(size_t i = 0; i < CURRENT; i++)
            if(STACK[i] == element) return true;
    return false;
}

template <class T>
bool Stack<T>::find(T element) const{
    bool found = false;
    if(!empty()){
        #pragma omp parallel for
        for(size_t i = 0; i < CURRENT; i++){
            if(STACK[i] == element){
                #pragma omp critical
                {
                    found = true;
                }
            }
        }
    }
    return found;
}

template <class T>
int Stack<T>::index_of(T element) const{
    int index = -1;
    if(!empty()){
        #pragma omp parallel for
        for(size_t i = 0; i < CURRENT; i++){
            if(STACK[i] == element){
                #pragma omp critical
                {
                    index = i;
                }
            }
        }
    }
    return index;
}

template <class T>
T Stack<T>::pop(){
    if(empty()) throw std::underflow_error("Stack underflow!");
    return STACK[--CURRENT];
}

template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &rhs){
    if(this != &rhs){
        delete[] STACK;
        MAXSIZE = rhs.size();
        STACK = new T[MAXSIZE];
        for(size_t i = 0; i < MAXSIZE; i++)
            STACK[i] = rhs.STACK[i];
    }
    return *this;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const Stack<T> &stack){
    os << "[";
    for(size_t i = 0; i < stack.CURRENT - 1; i++)
        os << stack.STACK[i] << ", ";
    os << stack.STACK[stack.CURRENT - 1] << "]";
    return os;
}

#endif
