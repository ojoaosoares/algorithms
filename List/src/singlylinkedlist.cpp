#include "singlylinkedlist.hpp"

// Singly Linked List implemention

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : List<T>() { head = nullptr; tail = nullptr; }

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() { clear(); }

template <typename T>
Node<T>* SinglyLinkedList<T>::getPosition(int index, bool before) const
{
    // Input : (int) index, the index of the wanted element, (bool) before, if you want the item with the previous index
    // Complexity : Worst case O(n), Best case O(1)

    if (index < 0 || index >= getSize()) 
        throw "ERROR: Invalid index";

    Node<T>* p = head;

    for (int i = 0; i < index - 1; i++) p = p->next;
    
    if (!before && index) p = p->next; // And i because 0 has no antecessor

    return p;

}

template <typename T>
T SinglyLinkedList<T>::getItem(int index) const
{
    // Input : (int) index, the index of the wanted element
    // Complexity : Worst case O(n), Best case O(1)

    return getPosition(index)->item;

}

template <typename T>
T SinglyLinkedList<T>::removeBegin()
{
    // Output : T, the item that was removed
    // Complexity : O(1) 

    if(Empty())
        throw "ERROR: Empty list";

    Node<T>* p = head;
    head = head->next;

    if (head == nullptr)
        tail = nullptr;

    T aux = p->item;

    delete p;

    size--;

    return aux;
}

template <typename T>
T SinglyLinkedList<T>::removeEnd()
{
    // Output : T, the item that was removed
    // Complexity : O(n)

    if(Empty())
        throw "ERROR: Empty list";
    
    T aux = tail->item;

    if (getSize() == 1)
    {
        delete tail;
        head = nullptr; tail = nullptr;
    }

    else 
    {
        Node<T>* p = getPosition(getSize() - 1, true);
        p->next = nullptr;

        delete tail;

        tail = p;
    }
    
    size--;

    return aux;    
}

template <typename T>
T SinglyLinkedList<T>::removeIndex(int index)
{
    // Output : T, the item that was removed
    // Complexity : Worst case O(n), best case O(1)

    if (index == 0) 
        return removeBegin();

    if (index == getSize() - 1)
        return removeEnd();

    if(List<T>::Empty())
        throw "ERROR: Empty list";
    
    Node<T>* p = getPosition(index, true);
    Node<T>* q = p->next;

    p->setNext(q->next);

    T aux = q->item;

    delete q;

    size--;
    
    return aux;

}

template <typename T>
void SinglyLinkedList<T>::copyArray(T* array, int size)
{
    if (size < getSize())
        throw "ERROR: size insuficient";

    Node<T>* p = head;

    for (int i = 0; i < getSize(); i++)
    {
        array[i] = p->item;
        p->next = p->next;
    }

}

template <typename T>
void SinglyLinkedList<T>::printList() const
{
    // Output : string, the array is printed in form of "a1 a2 a3 ... an";
    // Complexity : O(n)

    if(Empty())
        throw "ERROR: Empty list";

    Node<T>* p = head;

    while (p != nullptr)
    {
        std::cout << p->item << ' ';
        p = p->next;
    }
    
    std::cout << '\n';    
}


template <typename T>
void SinglyLinkedList<T>::clear()
{
    // Complexity : O(n)

    Node<T>* p = head;

    while (p != nullptr)
    {
        head = head->next;
        delete p;
        p = head;
    }

    tail = nullptr;

    size = 0;
}