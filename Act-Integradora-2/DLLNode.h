#ifndef _DLLNODE_H_
#define _DLLNODE_H_

template<class T>
class DLLNode
{
    private:
    T data;
    DLLNode<T>* next;
    DLLNode<T>* prev;

    public: 
    // Constructor por defecto : Inicializa "data" con su valor por defecto y "next" y "prev" a nullptr
    DLLNode();
    // Constructor que recibe el valor: "Inicializa "data" con el valor recibido  y "next" y "prev"
    DLLNode(T value);
    //Retorna el valor almacenado en "data"
    T getData() const{ return data;}
    //Retorna el puntero al siguiente nodo
    DLLNode<T>* getNext() const{return next;}
    //Retorna el puntero al noto anterior
    DLLNode<T>* getPrev()const{return prev;}
    //Declaracion de amistas: Permite a la clase DoublyLinkedList acceder a los miembros privados
    template<typename U> friend class DoublyLinkedList;
};

//Implementacion del constructor por defecto
template<class T>
DLLNode<T>::DLLNode():data{},next{nullptr}, prev{nullptr}{}

//Implementación del constructor que recibe un valor
template<class T>
DLLNode<T>::DLLNode(T value):data{value}, next{nullptr}, prev{nullptr}{}

#endif