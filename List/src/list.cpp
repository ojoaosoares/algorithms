#include "list.hpp"

// Base List implementation

template <typename T>
List<T>::List() : size(0) {}

template <typename T>
int List<T>::getSize() const
{
    // Output : int, the size of the array
    // Complexity : O(1)

    return size;
}

template <typename T>
bool List<T>::Empty() const
{
    // Output : a boolean value, if the array is empty (size equals 0) true, else false
    // Complexity : O(1)

    return getSize() == 0;
}

// Singly Linked List implemention

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : List<T>() { SinglyLinkedList<T>::head = nullptr; SinglyLinkedList<T>::tail = nullptr; }

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() { clear(); }


template <typename T>
Node<T>* SinglyLinkedList<T>::getPosition(int index, bool before) const
{
    // Input : (int) index, the index of the wanted element, (bool) before, if you want the item with the previous index
    // Complexity : Worst case O(n), Best case O(1)

    if (index < 0 || index >= List<T>::size) 
        throw "ERROR: Invalid index";

    Node<T>* p = SinglyLinkedList<T>::head;

    for (int i = 0; i < index - 1; i++) p = p->getNext();
    
    if (!before && index) p = p->getNext(); // And i because 0 has no antecessor

    return p;

}

template <typename T>
T SinglyLinkedList<T>::getItem(int index) const
{
    // Input : (int) index, the index of the wanted element
    // Complexity : Worst case O(n), Best case O(1)

    return getPosition(index)->getItem();

}

template <typename T>
T SinglyLinkedList<T>::removeBegin()
{
    // Output : T, the item that was removed
    // Complexity : O(1) 

    if(List<T>::Empty())
        throw "ERROR: Empty list";

    Node<T>* p = SinglyLinkedList<T>::head;
    SinglyLinkedList<T>::head = SinglyLinkedList<T>::head->getNext();

    if (SinglyLinkedList<T>::head == nullptr)
        SinglyLinkedList<T>::tail = nullptr;

    T aux = p->getItem();

    delete p;

    List<T>::size--;

    return aux;
}

template <typename T>
T SinglyLinkedList<T>::removeEnd()
{
    // Output : T, the item that was removed
    // Complexity : O(n)

    if(List<T>::Empty())
        throw "ERROR: Empty list";
    
    T aux = SinglyLinkedList<T>::tail->getItem();

    if (getSize() == 1)
    {
        delete SinglyLinkedList<T>::tail;
        SinglyLinkedList<T>::head = nullptr; SinglyLinkedList<T>::tail = nullptr;
    }

    else 
    {
        Node<T>* p = getPosition(getSize() - 1, true);
        p->setNext(nullptr);

        delete SinglyLinkedList<T>::tail;

        SinglyLinkedList<T>::tail = p;
    }
    
    List<T>::size--;

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
    Node<T>* q = p->getNext();

    p->setNext(q->getNext());

    T aux = q->getItem();

    delete q;

    List<T>::size--;
    
    return aux;

}

template <typename T>
void SinglyLinkedList<T>::copyArray(T* array, int size)
{
    if (size < List<T>::getSize())
        throw "ERROR: size insuficient";

    Node<T>* p = head;

    for (int i = 0; i < List<T>::getSize(); i++)
    {
        array[i] = p->getItem();
        p->setNext(p->getNext());
    }

}

template <typename T>
void SinglyLinkedList<T>::printList() const
{
    // Output : string, the array is printed in form of "a1 a2 a3 ... an";
    // Complexity : O(n)

    if(List<T>::Empty())
        throw "ERROR: Empty list";

    Node<T>* p = SinglyLinkedList<T>::head;

    while (p != nullptr)
    {
        std::cout << p->getItem() << ' ';
        p = p->getNext();
    }
    
    std::cout << '\n';    
}


template <typename T>
void SinglyLinkedList<T>::clear()
{
    // Complexity : O(n)

    Node<T>* p = SinglyLinkedList<T>::head;

    while (p != nullptr)
    {
        SinglyLinkedList<T>::head = SinglyLinkedList<T>::head->getNext();
        delete p;
        p = SinglyLinkedList<T>::head;
    }

    SinglyLinkedList<T>::tail = nullptr;

    getSize() = 0;
}


// Singly Linked List Ordered  implementation

template  <typename T>
SinglyLinkedListOrdered<T>::SinglyLinkedListOrdered() : SinglyLinkedList<T>::SinglyLinkedList() {}

template  <typename T>
SinglyLinkedListOrdered<T>::~SinglyLinkedListOrdered() {}

template  <typename T>
void SinglyLinkedListOrdered<T>::insert(T item)
{
    Node<T>* newNode = new Node<T>(item);

    if (!List<T>::size)
    {
        newNode->setNext(nullptr);
        SinglyLinkedList<T>::head = newNode; SinglyLinkedList<T>::tail = newNode; 
    }

    else
    {

        Node<T>* previous = nullptr;
        Node<T>* current = SinglyLinkedList<T>::head;

        while (current != nullptr)
        {
            if (current->getItem() >= item) break;

            previous = current;
            current = current->getNext();
        }

        
        newNode->setNext(current);

        if (previous == nullptr)
            SinglyLinkedList<T>::head = newNode;

        else
            previous->setNext(newNode);
        

        if (current == nullptr)
            SinglyLinkedList<T>::tail = newNode;
    }

    List<T>::size++;
}

template  <typename T>
int SinglyLinkedListOrdered<T>::search(T item) const
{
    if(List<T>::Empty())
        throw "ERROR: Empty list";

    Node<T>* p = SinglyLinkedList<T>::head;

    int i = 0;

    while (p != nullptr)
    {
        if (p->getItem() > item) break;
        else if (p->getItem() == item) return i;
        
        p = p->getNext();

        i++;
    }

    return -1;

}


// Singly Linked List Unordered Implementation


template <typename T>
SinglyLinkedListUnordered<T>::SinglyLinkedListUnordered() : SinglyLinkedList<T>::SinglyLinkedList() {}

template  <typename T>
SinglyLinkedListUnordered<T>::~SinglyLinkedListUnordered() {}

template <typename T>
void SinglyLinkedListUnordered<T>::setItem(T item, int index)
{
    // Input : (T) item, the item to be setted, (int) index, the index of the wanted element
    // Complexity : Worst case O(n), Best case O(1)

    SinglyLinkedList<T>::getPosition(index)->setItem(item);
}

template <typename T>
void SinglyLinkedListUnordered<T>::insertBegin(T item)
{
    // Input : (T) item, the item to be inserted
    // Complexity : O(1)

    Node<T>* newNode = new Node<T>(item);

    newNode->setNext(SinglyLinkedList<T>::head);

    SinglyLinkedList<T>::head = newNode;

    if (!(List<T>::size)) SinglyLinkedList<T>::tail = newNode;

    List<T>::size++;

}

template <typename T>
void SinglyLinkedListUnordered<T>::insertEnd(T item)
{
    
    // Input : (T) item, the item to be inserted
    // Complexity : O(1)

    Node<T>* newNode = new Node<T>(item);

    newNode->setNext(nullptr);

    if (!List<T>::size)
    {
        SinglyLinkedList<T>::head = newNode; SinglyLinkedList<T>::tail = newNode;
    }
    
    else
    {
        SinglyLinkedList<T>::tail->setNext(newNode);
        SinglyLinkedList<T>::tail = newNode;
    }

    List<T>::size++;
}

template <typename T>
void SinglyLinkedListUnordered<T>::insertIndex(T item, int index)
{
    // Input : (T) item, the item to be inserted
    // Complexity : Worst case O(n), best case O(1) 

    if (!index) insertBegin(item);

    else if (getSize() == index) insertEnd(item);

    else 
    {
        Node<T>* p = SinglyLinkedList<T>::getPosition(index, true);
        Node<T>* newNode = new Node<T>(item);
        newNode->setNext(p->getNext());
        p->setNext(newNode);

        List<T>::size++;
    }
    
}

template <typename T>
int SinglyLinkedListUnordered<T>::search(T item) const
{
    // Output : int, the item to be searched
    // Complexity : O(n)

    if(List<T>::Empty())
        throw "ERROR: Empty list";

    Node<T>* p = SinglyLinkedList<T>::head;

    int i = 0;

    while (p != nullptr)
    {
        if (p->getItem() == item) return i;

        p = p->getNext();

        i++;
    }

    return -1;

}


template class List<long long>;
template class List<int>;
template class List<double>;

template class StaticList<long long>;
template class StaticList<int>;
template class StaticList<double>;

template class SinglyLinkedList<long long>;
template class SinglyLinkedList<int>;
template class SinglyLinkedList<double>;

template class SinglyLinkedListUnordered<long long>;
template class SinglyLinkedListUnordered<int>;
template class SinglyLinkedListUnordered<double>;

template class SinglyLinkedListOrdered<long long>;
template class SinglyLinkedListOrdered<int>;
template class SinglyLinkedListOrdered<double>;