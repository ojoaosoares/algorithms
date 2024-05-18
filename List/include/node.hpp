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
        void setItem(T item);
        void setNext(Node<T>* next);
        T getItem();
        Node<T>* getNext();

    friend class SingSinglyLinkedList;
};


#endif