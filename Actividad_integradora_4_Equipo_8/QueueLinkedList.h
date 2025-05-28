#ifndef _QUEUELINKEDLIST_H_
#define _QUEUELINKEDLIST_H_

#include <stdexcept>
#include "QueueNode.h"

// Cola FIFO con lista enlazada: enqueue O(1), dequeue O(1)
template <class T>
class QueueLinkedList {
private:
    QueueNode<T>* front;
    QueueNode<T>* rear;

public:
    QueueLinkedList(); // O(1)
    ~QueueLinkedList(); // O(n)
    bool isEmpty() const; // O(1)
    void enqueue(const T& value); // O(1)
    T dequeue(); // O(1)
};

template <class T>
QueueLinkedList<T>::QueueLinkedList()
    : front(nullptr), rear(nullptr) {}

template <class T>
QueueLinkedList<T>::~QueueLinkedList() {
    while (front != nullptr) {
        QueueNode<T>* p = front;
        front = front->next;
        delete p;
    }
    rear = nullptr;
}

template <class T>
bool QueueLinkedList<T>::isEmpty() const {
    return front == nullptr;
}

template <class T>
void QueueLinkedList<T>::enqueue(const T& value) {
    QueueNode<T>* node = new QueueNode<T>(value);
    if (rear == nullptr) {
        front = node;
        rear = node;
    } else {
        rear->next = node;
        rear = node;
    }
}

template <class T>
T QueueLinkedList<T>::dequeue() {
    if (front == nullptr) {
        throw std::out_of_range("Queue is empty");
    }
    QueueNode<T>* p = front;
    T val = p->data;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete p;
    return val;
}
#endif