#include "list.hpp"

// Base List implementation

template <typename T>
List<T>::List() : size(0) {};

template <typename T>
int List<T>::getSize() const
{
    // Output : int, the size of the array
    // Complexity : O(1)

    return size;
};

template <typename T>
bool List<T>::Empty() const
{
    // Output : a boolean value, if the array is empty (size equals 0) true, else false
    // Complexity : O(1)

    return List<T>::size == 0;
};


// Static List implementation

template <typename T>
StaticList<T>::StaticList(int MAX) : List<T>::List(), MAXSIZE(MAX) { itens = new T[MAX]; }

template <typename T>
StaticList<T>::~StaticList() { delete[] itens; }

template <typename T>
T StaticList<T>::getItem(int index) const 
{ 
    // Input : index (index of the target)
    // Output : T  (the target value)
    // Complexity : O(1)

    if(index >= List<T>::size || index < 0)
        throw "ERROR: Invalid index";

    return itens[index];
};

template <typename T>
void StaticList<T>::setItem(T item, int index)
{ 

    // Input : index (index of the target), item (the value of the target)
    // Complexity : O(1)

    if(index >= List<T>::size || index < 0)
        throw "ERROR: Invalid index";

    itens[index] = item;
};

template <typename T>
void StaticList<T>::insertBegin(T item)
{

    // Input : item (the item to be added)
    // Complexity : O(n)

    if (List<T>::size == MAXSIZE)
        throw "ERROR: Full list";

    List<T>::size++;
    for (int i = List<T>::size; i > 0; i--)
        itens[i] = itens[i-1];

    itens[0] = item;
};

template <typename T>
void StaticList<T>::insertEnd(T item)
{
    // Input : item (the item to be added)
    // Complexity : O(1)

    if (List<T>::size == MAXSIZE)
        throw "ERROR: Full list";
    
    itens[List<T>::size++] = item;
}

template <typename T>
void StaticList<T>::insertIndex(T item, int index)
{

    // Input : item (the item to be added)
    // Complexity : O(n) worst case, O(1) best case (Insertion in the end)


    if(index >= List<T>::size || index < 0)
        throw "ERROR: Invalid index";

    if (List<T>::size == MAXSIZE)
        throw "ERROR: Full list";

    List<T>::size++;

    for (int i = List<T>::size; i > index; i--)
        itens[i] = itens[i-1];

    itens[index] = item;
}


template <typename T>
T StaticList<T>::removeBegin()
{
    // Output : item (the item to be removed, the last first one)
    // Complexity : O(n)

    if(List<T>::Empty())
        throw "ERROR: Empty list";

    T aux = itens[0];

    for (int i = 0; i < List<T>::size; i++)
        itens[i] = itens[i+1];

    List<T>::size--;
    return aux;
    
}



template <typename T>
T StaticList<T>::removeEnd()
{
    // Output : item (the item to be removed, the last last one)
    // Complexity : O(1)

    if(List<T>::Empty())
        throw "ERROR: Empty list";

    T aux = itens[List<T>::size--];
    return aux;
}

template <typename T>
T StaticList<T>::removeIndex(int index)
{   
    // Output : item (the item to be removed)
    // Complexity : O(n) worst case, O(1) (the best case, remove the last element)

    if(index >= List<T>::size || index < 0)
        throw "ERROR: Invalid index";

    if(List<T>::Empty())
        throw "ERROR: Empty list";

    T aux = itens[index];

    for (int i = index; i < List<T>::size; i++)
        itens[i] = itens[i+1];

    List<T>::size--;
    return aux;
}
template <typename T>
int StaticList<T>::search(T item) const
{
    // Input : item (the item to be searched)
    // Output : int, the index of the element in case it exists in the array, otherwise -1;
    // Complexity : O(n)

    if(List<T>::Empty())
        throw "ERROR: Empty list";

    for (int i = 0; i < List<T>::size; i++ )
        if (item == itens[i])
            return i;
    
    return -1;
};


template <typename T>
void StaticList<T>::printList() const
{
    // Output : string, the array is printed in form of "a1 a2 a3 ... an";
    // Complexity : O(n)

    for (int i = 0; i < List<T>::size; i++)
        std::cout << itens[i] << ' ';

    std::cout << '\n';
}


template <typename T>
void StaticList<T>::clear()
{
    // Complexity : O(1)
    List<T>::size = 0; 
}

// Node implementation

template <typename T>
Node<T>::Node(T item) : item(item), next(nullptr) {}

template <typename T>
void Node<T>::setItem(T item) { this->item = item; }

template <typename T>
void Node<T>::setNext(Node<T>* next) { this->next = next; }

template <typename T>
T Node<T>::getItem() { return item; }

template <typename T>
Node<T>* Node<T>::getNext() { return next; }

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

    if (List<T>::size == 1)
    {
        delete SinglyLinkedList<T>::tail;
        SinglyLinkedList<T>::head = nullptr; SinglyLinkedList<T>::tail = nullptr;
    }

    else 
    {
        Node<T>* p = getPosition(List<T>::size - 1, true);
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

    if (index == List<T>::size - 1)
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

    List<T>::size = 0;
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

    else if (List<T>::size == index) insertEnd(item);

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