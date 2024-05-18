#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include "list.hpp"
#include "node.hpp"

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


#endif