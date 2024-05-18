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