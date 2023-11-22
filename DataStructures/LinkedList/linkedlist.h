/**
 * @author Guilherme Martinelli Taglietti
 * @brief Linked list implementation using own iterators and types
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <iterator>

namespace datastructures{

template <class T>
class LinkedList{
public:
    LinkedList();
    LinkedList(const LinkedList &cpy);
    virtual ~LinkedList();
    void insert(T val);
    void erase(T val);
    typename LinkedList<T>::iterator find(T val) const;
    std::size_t size() const noexcept;

private:
    typedef struct Node{
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr){}
    } Node;

    Node* head;
    std::size_t _size;

    class iterator : public std::iterator<std::input_iterator_tag, T>{
    public:
        iterator(Node* node = nullptr) : current(node) {}
        inline bool operator==(const iterator &rhs) const{
            return current == rhs.current;
        }

        inline bool operator!=(const iterator &rhs) const{
            return !(*this == rhs);
        }

        iterator& operator++(){
            current = current->next;
            return *this;
        }
        
        iterator operator++(int){
            iterator temp = *this;
            ++*this;
            return temp;
        }
        
        inline T operator*() const{
            return current->data;
        }

    private:
        Node* current;
    };

public:
    iterator begin() const;
    iterator end() const;

};

template <class T>
LinkedList<T>::LinkedList() : head(nullptr), _size(0){}

template <class T>
LinkedList<T>::LinkedList(const LinkedList &cpy) : head(nullptr), _size(cpy.size()){
    for(const T &val : cpy)
        insert(val);
}

template <class T>
LinkedList<T>::~LinkedList(){
    while(head){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void LinkedList<T>::insert(T val){
    if(!head) head = new Node(val);
    else{
        Node* current = head;
        while(current->next) 
            current = current->next;
        current->next = new Node(val);
    }
    _size++;
}

template <class T>
void LinkedList<T>::erase(T val){
    if(!head) return;
    if(head->data == val){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    while(current->next && current->next->data != val)
        current = current->next;
    if(!current->next) return;
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    _size--;
}

template <class T>
typename LinkedList<T>::iterator LinkedList<T>::find(T val) const{
    iterator it = begin();
    while(it != end()){
        if(*it == val) return it;
        it++;
    }
    return end();
}

template <class T>
inline std::size_t LinkedList<T>::size() const noexcept{
    return _size;
}

template <class T>
inline typename LinkedList<T>::iterator LinkedList<T>::begin() const{
    return iterator(head);
}

template <class T>
inline typename LinkedList<T>::iterator LinkedList<T>::end() const{
    return iterator();
}

};

#endif
