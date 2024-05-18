#ifndef LIST
#define LIST

#include <iostream>

template <typename T>
class List
{
    protected:
        int size;
    public:
        List();
        int getSize() const;
        bool Empty() const;

        virtual T getItem(int index) const = 0;
        virtual T removeBegin() = 0;
        virtual T removeEnd() = 0;
        virtual T removeIndex(int index) = 0;
        virtual int search(T item) const = 0;
        virtual void printList() const = 0;
        virtual void clear() = 0;

};


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

template  <typename T>
class SinglyLinkedList : public  List<T>
{

    protected :
        Node<T>* head;
        Node<T>* tail;
        Node<T>* getPosition(int index, bool before = false) const;
    
    public :
        SinglyLinkedList();
        ~SinglyLinkedList();
        
        T getItem(int index) const override;
        T removeBegin() override;
        T removeEnd() override;
        T removeIndex(int index) override;
        virtual int search(T item) const = 0;
        void copyArray(T* array, int size);
        void printList() const override;
        void clear() override;

};

template  <typename T>
class SinglyLinkedListOrdered : public  SinglyLinkedList<T>
{   
    public :
        SinglyLinkedListOrdered();
        ~SinglyLinkedListOrdered();

        void insert(T item);
        virtual int search(T item) const override;

};

template  <typename T>
class SinglyLinkedListUnordered : public  SinglyLinkedList<T>
{   
    public :
        SinglyLinkedListUnordered();
        ~SinglyLinkedListUnordered();

        void setItem(T item, int index);
        void insertBegin(T item);
        void insertEnd(T item);
        virtual void insertIndex(T item, int index);
        virtual int search(T item) const override;

};


#endif