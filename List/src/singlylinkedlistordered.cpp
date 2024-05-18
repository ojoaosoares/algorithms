#include "singlylinkedlistordered.hpp"

// Singly Linked List Ordered  implementation

template  <typename T>
SinglyLinkedListOrdered<T>::SinglyLinkedListOrdered() : SinglyLinkedList() {}

template  <typename T>
SinglyLinkedListOrdered<T>::~SinglyLinkedListOrdered() {}

template  <typename T>
void SinglyLinkedListOrdered<T>::insert(T item)
{
    Node<T>* newNode = new Node<T>(item);

    if (Empty())
    {
        newNode->next = nullptr;
        head = newNode; tail = newNode; 
    }

    else
    {

        Node<T>* previous = nullptr;
        Node<T>* current = head;

        while (current != nullptr)
        {
            if (current->item >= item) break;

            previous = current;
            current = current->next;
        }

        
        newNode->next = current;

        if (previous == nullptr)
            head = newNode;

        else
            previous->next = newNode;
        

        if (current == nullptr)
            tail = newNode;
    }

    size++;
}

template  <typename T>
int SinglyLinkedListOrdered<T>::search(T item) const
{
    if(Empty())
        throw "ERROR: Empty list";

    Node<T>* p = head;

    int i = 0;

    while (p != nullptr)
    {
        if (p->item > item) break;
        else if (p->item == item) return i;
        
        p = p->next;

        i++;
    }

    return -1;

}