#include "staticlist.hpp"

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

    return getSize() == 0;
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

    if(index >= getSize() || index < 0)
        throw "ERROR: Invalid index";

    return itens[index];
};

template <typename T>
void StaticList<T>::setItem(T item, int index)
{ 

    // Input : index (index of the target), item (the value of the target)
    // Complexity : O(1)

    if(index >= getSize() || index < 0)
        throw "ERROR: Invalid index";

    itens[index] = item;
};

template <typename T>
void StaticList<T>::insertBegin(T item)
{

    // Input : item (the item to be added)
    // Complexity : O(n)

    if (getSize() == MAXSIZE)
        throw "ERROR: Full list";

    size++;
    for (int i = getSize(); i > 0; i--)
        itens[i] = itens[i-1];

    itens[0] = item;
};

template <typename T>
void StaticList<T>::insertEnd(T item)
{
    // Input : item (the item to be added)
    // Complexity : O(1)

    if (getSize() == MAXSIZE)
        throw "ERROR: Full list";
    
    itens[getSize()] = item;
}

template <typename T>
void StaticList<T>::insertIndex(T item, int index)
{

    // Input : item (the item to be added)
    // Complexity : O(n) worst case, O(1) best case (Insertion in the end)


    if(index >= getSize() || index < 0)
        throw "ERROR: Invalid index";

    if (getSize() == MAXSIZE)
        throw "ERROR: Full list";

    size++;

    for (int i = getSize(); i > index; i--)
        itens[i] = itens[i-1];

    itens[index] = item;
}


template <typename T>
T StaticList<T>::removeBegin()
{
    // Output : item (the item to be removed, the last first one)
    // Complexity : O(n)

    if(Empty())
        throw "ERROR: Empty list";

    T aux = itens[0];

    for (int i = 0; i < getSize(); i++)
        itens[i] = itens[i+1];

    size--;
    return aux;
    
}



template <typename T>
T StaticList<T>::removeEnd()
{
    // Output : item (the item to be removed, the last last one)
    // Complexity : O(1)

    if(Empty())
        throw "ERROR: Empty list";

    T aux = itens[size--];
    return aux;
}

template <typename T>
T StaticList<T>::removeIndex(int index)
{   
    // Output : item (the item to be removed)
    // Complexity : O(n) worst case, O(1) (the best case, remove the last element)

    if(index >= getSize() || index < 0)
        throw "ERROR: Invalid index";

    if(Empty())
        throw "ERROR: Empty list";

    T aux = itens[index];

    for (int i = index; i < getSize(); i++)
        itens[i] = itens[i+1];

    size--;
    return aux;
}
template <typename T>
int StaticList<T>::search(T item) const
{
    // Input : item (the item to be searched)
    // Output : int, the index of the element in case it exists in the array, otherwise -1;
    // Complexity : O(n)

    if(Empty())
        throw "ERROR: Empty list";

    for (int i = 0; i < getSize(); i++ )
        if (item == itens[i])
            return i;
    
    return -1;
};


template <typename T>
void StaticList<T>::printList() const
{
    // Output : string, the array is printed in form of "a1 a2 a3 ... an";
    // Complexity : O(n)

    for (int i = 0; i < getSize(); i++)
        std::cout << itens[i] << ' ';

    std::cout << '\n';
}


template <typename T>
void StaticList<T>::clear()
{
    // Complexity : O(1)
    size = 0; 
}