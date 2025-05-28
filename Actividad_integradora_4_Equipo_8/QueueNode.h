#ifndef _QUEUENODE_H_
#define _QUEUENODE_H_

// Nodo para cola enlazada
// Operaciones O(1)
template <class T>
class QueueNode {
private:
    T data;
    QueueNode<T>* next;

public:
    QueueNode();
    QueueNode(const T& value);
    template<typename U> friend class QueueLinkedList;
};

template <class T>
QueueNode<T>::QueueNode()
    : data{}, next(nullptr) {}

template <class T>
QueueNode<T>::QueueNode(const T& value)
    : data(value), next(nullptr) {}

#endif