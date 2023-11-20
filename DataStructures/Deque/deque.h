#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <stdexcept>

template <class T>
class Deque{
public:
    Deque();
    Deque(std::size_t _SIZE);
    Deque(const Deque &cpy);
    virtual ~Deque();
    std::size_t size() const noexcept;
    std::size_t max_size() const noexcept;
    int index_of(T val) const noexcept;
    constexpr bool empty() const noexcept;
    void push_front(T val);
    void push_back(T val);
    void pop_front();
    void pop_back();
    T front() const;
    T back() const;
    Deque<T> &operator=(const Deque &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Deque<T> &dq){
        if(!dq.empty()){
            os << "[";
            for(std::size_t i = 0; i < dq.CURRENT - 1; i++)
                os << dq.DEQUE[i] << " - ";
            os << dq.back() << "]";
        } 
        else os << "[]";
        return os;
    }

private:
    T* DEQUE;
    std::size_t SIZE;
    std::size_t CURRENT;
    static const std::size_t MAX_SIZE = 1000;
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;
};

template <class T>
Deque<T>::Deque() : Deque(MAX_SIZE){}

template <class T>
Deque<T>::Deque(std::size_t _SIZE){
    if(_SIZE > MAX_SIZE) throw std::bad_array_new_length(); 
    SIZE = _SIZE;
    CURRENT = 0;
    DEQUE = new T[SIZE]();
}

template <class T>
Deque<T>::Deque(const Deque<T> &cpy) : SIZE(cpy.CURRENT), CURRENT(cpy.CURRENT){
    DEQUE = new T[SIZE];
    for(std::size_t i = 0; i < CURRENT; i++)
        DEQUE[i] = cpy.DEQUE[i];
}


template <class T>
Deque<T>::~Deque(){
    delete[] DEQUE;
}

template <class T>
inline std::size_t Deque<T>::size() const noexcept{
    return CURRENT;
}

template <class T>
inline std::size_t Deque<T>::max_size() const noexcept{
    return MAX_SIZE;
}

template <class T>
int Deque<T>::index_of(T val) const noexcept{
    for(std::size_t i = 0; i < CURRENT; i++)
        if(DEQUE[i] == val) return i;
    return -1;    
}

template <class T>
constexpr bool Deque<T>::empty() const noexcept{
    return CURRENT == 0;
}

template <class T>
void Deque<T>::push_front(T val){
    if(size() >= SIZE) throw std::overflow_error("DEQUE OVERFLOW!");
    for(std::size_t i = size(); i > 0; i--)
        DEQUE[i] = DEQUE[i - 1];
    DEQUE[0] = val;
    CURRENT++;
}

template <class T>
void Deque<T>::push_back(T val){
    if(size() >= SIZE) throw std::overflow_error("DEQUE OVERFLOW!");
    DEQUE[CURRENT++] = val;
}

template <class T>
void Deque<T>::pop_front(){
    if(empty()) throw std::underflow_error("DEQUE UNDERFLOW!");
    for(std::size_t i = 1; i < CURRENT; i++)
        DEQUE[i - 1] = DEQUE[i];
    CURRENT--;
}

template <class T>
void Deque<T>::pop_back(){
    if(empty()) throw std::underflow_error("DEQUE UNDERFLOW!");
    CURRENT--;
}

template <class T>
T Deque<T>::front() const{
    if(empty()) throw std::underflow_error("DEQUE UNDERFLOW!");
    return DEQUE[0];
}

template <class T>
T Deque<T>::back() const{
    if(empty()) throw std::underflow_error("DEQUE UNDERFLOW!");
    return DEQUE[CURRENT - 1];
}

template <class T>
Deque<T> &Deque<T>::operator=(const Deque<T> &rhs){
    if(this != &rhs){
        delete[] DEQUE;
        SIZE = rhs.SIZE;
        CURRENT = rhs.CURRENT;
        MAX_SIZE = rhs.MAX_SIZE;
        DEQUE = new T[SIZE];
        for(std::size_t i = 0; i < CURRENT; ++i)
            DEQUE[i] = rhs.DEQUE[i];
    }
    return *this;
}

template <class T>
T& Deque<T>::operator[](std::size_t index){
    if(index >= CURRENT) throw std::out_of_range("Index out of range");
    return DEQUE[index];
}

template <class T>
const T& Deque<T>::operator[](std::size_t index) const{
    if(index >= CURRENT) throw std::out_of_range("Index out of range");
    return DEQUE[index];
}

#endif
