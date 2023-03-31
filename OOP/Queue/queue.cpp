#include "queue.hpp"

Queue::Queue(int max_size){
    this->queue = new int[max_size];
    this->setMaxSize(max_size);
}

Queue::Queue(const Queue &queue){ // Construtor de cópia
    this->queue = queue.queue;
    this->size = queue.size;
    this->max_size = queue.max_size;
}

Queue::~Queue(){
    delete this->queue;
}

void Queue::push(int value){
    if(!this->isFull()) this->queue[this->size++] = value;    
}

int Queue::pop(){
    if(!this->isEmpty()){
        int temp = this->queue[0];
        for(int i = 0; i < this->size - 1; i++) this->queue[i] = this->queue[i + 1];
        this->size--;
        return temp;
    }
    return -1;
}

bool Queue::have(int value) const{
    for(int i = 0; i < this->size; i++){
        if(this->queue[i] == value) return true;
    }
    return false;
}

Queue Queue::operator+(const Queue &queue){
    Queue new_queue(this->max_size + queue.max_size);
    for(int i = 0; i < this->size; i++) new_queue.push(this->queue[i]);
    for(int i = 0; i < queue.size; i++) new_queue.push(queue.queue[i]);
    return new_queue;
}

Queue Queue::operator=(const Queue &queue){
    delete this->queue;
    Queue new_queue(queue);
    return new_queue;
}

std::ostream& operator<<(std::ostream &os, const Queue &queue){
    os << "Fila: ";
    for(int i = 0; i < queue.size; i++) os << queue.queue[i] << " ";
    os << std::endl;
    return os;   
}
