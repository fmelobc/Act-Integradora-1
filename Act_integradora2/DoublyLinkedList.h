
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include "DLLNode.h"
#include "Registro.h"

using std::cout;
using std::endl;

/* Representa una lista doblemente ligada para almacenar elementos de tipo T
 * Lo que hace son metodos para :
 * - Insertar elementos al final de la lista.
 * - Imprimir la lista (en orden directo e inverso).
 * - Acceder a un nodo en una posición específica.
 * - Ordenar la lista en orden descendente mediante el algoritmo Merge Sort.
 * - Realizar una búsqueda binaria adaptada para la lista ordenada descendente.
*/

template <class T>
class DoublyLinkedList
{
private:
    DLLNode<T> *head; // Puntero al primer nodo de la lista
    DLLNode<T> *tail; // Puntero al ultimo nodo de la lista
    int numElements;  // Numero total de elementos en la lista

    // Funcion recursiva mergeSort para ordenar la lista
    DLLNode<T> *mergeSort(DLLNode<T> *headNode);
    // Funcion que divide la lista en dos mitades , utilizando la técnica de dos punteros
    DLLNode<T> *split(DLLNode<T> *headNode);
    // Fusiona dos sublistas ordenadas descendentemente
    DLLNode<T> *merge(DLLNode<T> *first, DLLNode<T> *second);

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void printList();
    void printReverseList();
    void push_back(const T &value);
    void sort();

    // Retorna el nodo en la posicion "index". Complejidad 0(n)
    DLLNode<T> *getNodeAt(int index) const;

    // Busqueda binaria adaptada para la lista doblemente ligada ordenada descendentemente
    //  Retorna el indice del nodo encontrado o -1 si no se encuentra
    int binarySearch(const T &target) const;

    // Retorna el puntero al primer nodo de la lista
    DLLNode<T> *getHead() const;
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), numElements(0)
{
    cout << "---- Creando una lista doblemente ligada vacia : " << this << endl;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    cout << "Liberando memoria de la lista doblemente ligada " << this << endl;
    DLLNode<T> *p = head;
    while (p != nullptr)
    {
        DLLNode<T> *q = p->next;
        delete p;
        p = q;
    }
    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

template <class T>
void DoublyLinkedList<T>::printList()
{
    if (head == nullptr)
    {
        cout << "La lista no tiene nada " << endl;
    }
    else
    {
        cout << "El contenido de la lista es : " << endl;
        DLLNode<T> *p = head;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

template <class T>
void DoublyLinkedList<T>::printReverseList()
{
    if (head == nullptr)
    {
        cout << "La lista no tiene nada " << endl;
    }
    else
    {
        cout << " El contenido de la lista es : " << endl;
        DLLNode<T> *p = tail;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->prev;
        }
        cout << std::endl;
    }
}

template <class T>
void DoublyLinkedList<T>::push_back(const T &value)
{
    DLLNode<T> *newNode = new DLLNode<T>(value);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    numElements++;
}

template <class T>
DLLNode<T> *DoublyLinkedList<T>::getHead() const
{
    return head;
}

// Retorna el nodo en la posicion que es index . Tiene una complejidad de O(n)
template <class T>
DLLNode<T> *DoublyLinkedList<T>::getNodeAt(int index) const
{
    if (index < 0 || index >= numElements)
    {
        throw std::out_of_range("Indice fuera de rango");
    }
    DLLNode<T> *p = head;
    int count = 0;

    while (p != nullptr && count < index)
    {
        p = p->next;
        count++;
    }
    return p;
}

// Implementación de mergeSort para listas doblemente enlazadas

template <class T>
DLLNode<T> *DoublyLinkedList<T>::split(DLLNode<T> *headNode)
{
    DLLNode<T> *slow = headNode;
    DLLNode<T> *fast = headNode;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    DLLNode<T> *second = slow->next;
    slow->next = nullptr;
    if (second)
    {
        second->prev = nullptr;
    }
    return second;
}

template <class T>
DLLNode<T> *DoublyLinkedList<T>::merge(DLLNode<T> *first, DLLNode<T> *second)
{
    if (!first)
    {
        return second;
    }
    if (!second)
    {
        return first;
    }
    // El registro con mayor tiempo (más reciente debe de estar primero)
    if (first->data.aSegundos() >= second->data.aSegundos())
    {
        first->next = merge(first->next, second);
        if (first->next)
        {
            first->next->prev = first;
        }
        first->prev = nullptr;
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        if (second->next)
        {
            second->next->prev = second;
        }
        second->prev = nullptr;
        return second;
    }
}

template <class T>
DLLNode<T> *DoublyLinkedList<T>::mergeSort(DLLNode<T> *headNode)
{
    if (!headNode || !headNode->next)
    {
        return headNode;
    }
    DLLNode<T> *second = split(headNode);
    headNode = mergeSort(headNode);
    second = mergeSort(second);
    return merge(headNode, second);
}

// Ordena la lista en orden descendente usando mergeSort
template <class T>
void DoublyLinkedList<T>::sort()
{
    head = mergeSort(head);
    tail = head;
    if (tail)
    {
        while (tail->next)
        {
            tail = tail->next;
        }
    }
}

// Busqueda binaria en la lista doblemente enlazada ordenada descendentemente
//  Se usara getNodeAt por la falta de acceso aleatorio eficiente .
// Complejidad O(n log n)

template <class T>
int DoublyLinkedList<T>::binarySearch(const T &target) const
{
    // Crear vector auxliar de nodos para acceso aleatorio
    std::vector<DLLNode<T> *> arr;
    arr.reserve(numElements);
    DLLNode<T> *current = head;
    while (current != nullptr)
    {
        arr.push_back(current);
        current = current->next;
    }
    int low = 0;
    int high = numElements - 1;
    int bestIndex = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid]->data == target)
        {
            return mid;
        }
        else if (target > arr[mid]->data)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return bestIndex;
}

#endif
