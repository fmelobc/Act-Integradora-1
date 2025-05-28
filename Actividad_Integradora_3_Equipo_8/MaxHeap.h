#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>
#include <stdexcept>
#include <utility>

// Clase MaxHeap
//  Implementa una cola de prioridad máxima
template <class T>
class MaxHeap
{
public:
    MaxHeap() = default; // Su complejidad es de : O(1)

    void push(const T &value); // Inserta valor - Su complejidad es de : O(log n)
    void pop(); // Elimina el máximo - Su complejidad es de o(log n)
    const T &top() const; // Consulta el máximo - Su complejidad es de O(1)
    bool isEmpty() const; // Checa vacío - Su complejidad es de O(1)
    int size() const; // Retorna el tamañ - Su complejidad es de O(1) 
    const std::vector<T> &getData() const; // Acceso directo al vector - Su complejidad es de O(1)

private:
    std::vector<T> data;

    //Sus  complejidades es de O(1)
    inline int parent(int i) const { return (i - 1) / 2; }
    inline int left(int i) const { return 2 * i + 1; }
    inline int right(int i) const { return 2 * i + 2; }

    void heapifyUp(int idx);
    void heapifyDown(int idx);
};

template <class T>
void MaxHeap<T>::push(const T &value)
{
    data.push_back(value);
    heapifyUp(static_cast<int>(data.size()) - 1);
}

template <class T>
void MaxHeap<T>::pop()
{
    if (data.empty())
    {
        throw std::underflow_error("MaxHeap::pop(): heap vacío");
    }
    data[0] = data.back();
    data.pop_back();
    if (!data.empty())
    {
        heapifyDown(0);
    }
}

template <class T>
const T &MaxHeap<T>::top() const
{
    if (data.empty())
    {
        throw std::underflow_error("MaxHeap::top(): heap vacío");
    }
    return data[0];
}

template <class T>
bool MaxHeap<T>::isEmpty() const
{
    return data.empty();
}

template <class T>
int MaxHeap<T>::size() const
{
    return static_cast<int>(data.size());
}

template <class T>
const std::vector<T> &MaxHeap<T>::getData() const
{
    return data;
}

template <class T>
void MaxHeap<T>::heapifyUp(int idx)
{
    while (idx > 0 && data[parent(idx)] < data[idx])
    {
        std::swap(data[parent(idx)], data[idx]);
        idx = parent(idx);
    }
}

template <class T>
void MaxHeap<T>::heapifyDown(int idx)
{
    int n = static_cast<int>(data.size());
    while (true)
    {
        int l = left(idx), r = right(idx), largest = idx;
        if (l < n && data[l] > data[largest])
        {
            largest = l;
        }
        if (r < n && data[r] > data[largest])
        {
            largest = r;
        }
        if (largest == idx)
        {
            break;
        }
        std::swap(data[idx], data[largest]);
        idx = largest;
    }
}

#endif // MAXHEAP_H
