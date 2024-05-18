#ifndef NODE
#define NODE

template <typename T>
class Node
{
    private :
        T item;
        Node<T> *next;

    public:
        Node(T item);

    friend class SingSinglyLinkedList;
    friend class SinglyLinkedListOrdered;
    friend class SinglyLinkedListUnordered;
};


#endif