#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <stdexcept>
#include "NodeLinkedList.h"

// Lista enlazada simple con operaciones O(1) para addLast sobre promedio amortizado
// y O(n) para iteración y destrucción.
template <class T>
class LinkedList {
private:
    NodeLinkedList<T>* head;
    NodeLinkedList<T>* tail;
    int numElements;

public:
    LinkedList(); // O(1)
    ~LinkedList(); // O(n)
    int getNumElements() const; // O(1)
    NodeLinkedList<T>* getHead() const; // O(1)
    void addLast(const T& value); // O(1)
};

template <class T>
LinkedList<T>::LinkedList()
    : head(nullptr), tail(nullptr), numElements(0) {}

template <class T>
LinkedList<T>::~LinkedList() {
    NodeLinkedList<T>* p = head;
    while (p) {
        NodeLinkedList<T>* q = p->next;
        delete p;
        p = q;
    }
    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

template <class T>
int LinkedList<T>::getNumElements() const {
    return numElements;
}

template <class T>
NodeLinkedList<T>* LinkedList<T>::getHead() const {
    return head;
}

template <class T>
void LinkedList<T>::addLast(const T& value) {
    NodeLinkedList<T>* newNode = new NodeLinkedList<T>(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    numElements += 1;
}

#endif