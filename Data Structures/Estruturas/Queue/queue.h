#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

typedef unsigned int index_t;

template <class T>
class Queue{
public:
    Queue();
    Queue(size_t _SIZE);
    Queue(const Queue &cpy);
    void push(T val);
    T pop();
    size_t size() const;
    int index_of(T val) const;
    bool find(T val) const;
    bool empty() const;
    Queue<T> &operator=(const Queue &rhs);
    template <class QT>
    friend std::ostream &operator<<(std::ostream &os, const Queue<QT> &queue);

private:
    size_t MAXSIZE;
    index_t CURRENT;
    T *QUEUE;
};

template <class T>
Queue<T>::Queue() : Queue(1000){}

template <class T>
Queue<T>::Queue(size_t _SIZE){
    MAXSIZE = _SIZE;
    QUEUE = new T[MAXSIZE];
}

template <class T>
Queue<T>::Queue(const Queue<T> &queue){
    MAXSIZE = queue.size();
    QUEUE = new T[MAXSIZE];
    #pragma omp parallel for
    for(size_t i = 0; i < MAXSIZE; i++)
        QUEUE[i] = queue.QUEUE[i];
}

template <class T>
inline bool Queue<T>::empty() const{
    return CURRENT == 0;
}

template <class T>
inline size_t Queue<T>::size() const{
    return CURRENT;
}

template <class T>
int Queue<T>::index_of(T val) const {
    int result = -1;
    #pragma omp parallel for
    for(size_t i = 0; i < CURRENT; i++){
        if(QUEUE[i] == val){
            #pragma omp critical
            {
                result = i; 
            }
        }
    }
    return result; 
}

template <class T>
bool Queue<T>::find(T val) const{
    bool found = false; 
    #pragma omp parallel for
    for(size_t i = 0; i < CURRENT; i++){
        if(QUEUE[i] == val){
            #pragma omp critical
            {
                found = true;
            }
        }
    }
    return found; 
}

template <class T>
void Queue<T>::push(T val){
    if(size() == MAXSIZE) throw std::overflow_error("QUEUE OVERFLOW!");
    QUEUE[CURRENT++] = val;
}

template <class T>
T Queue<T>::pop(){
    if(!size()) throw std::underflow_error("QUEUE UNDERFLOW!");
    if(size() == 1) return QUEUE[--CURRENT];
    T temp = QUEUE[0];
    for(size_t i = 1; i < CURRENT; i++)
        QUEUE[i - 1] = QUEUE[i];
    CURRENT--;
    return temp;
}

template <class T>
Queue<T> &Queue<T>::operator=(const Queue<T> &rhs){
    if(this != &rhs){
        delete[] QUEUE;
        MAXSIZE = rhs.size();
        QUEUE = new T[MAXSIZE];
        for(size_t i = 0; i < MAXSIZE; i++)
            QUEUE[i] = rhs.QUEUE[i];
    }
    return *this;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const Queue<T> &queue){
    os << "[";
    for(size_t i = 0; i < queue.CURRENT - 1; i++)
        os << queue.QUEUE[i] << ", ";
    os << queue.QUEUE[queue.CURRENT - 1] << "]";
    return os;
}

#endif
