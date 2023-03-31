#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

class Queue{
private:
    int *queue;
    int size = 0;
    int max_size;
    void setMaxSize(int max_size) {this->max_size = max_size;}

public:
    Queue():Queue(100){};
    Queue(int max_size);
    Queue(const Queue &queue);
    virtual ~Queue();
    void push(int value);
    int pop();
    int front() const {return this->queue[0];}
    int getMaxSize() const {return this->max_size;}
    int lenght() const {return this->size;}
    bool isFull() const {return this->size == this->max_size;}
    bool isEmpty() const {return this->size == 0;}
    bool have(int value) const;
    Queue operator+(const Queue &queue);
    Queue operator=(const Queue &queue);
    friend std::ostream& operator<<(std::ostream &os, const Queue &queue);
};

#endif // QUEUE_HPP
