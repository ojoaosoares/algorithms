#ifndef STATIC_LIST
#define STATIC_LIST

#include "list.hpp"

template  <typename T>
class StaticList : public List<T>
{

    private :
        const int MAXSIZE;
        T *itens;
    
    public :
        StaticList(int MAX);
        ~StaticList();

        T getItem(int index) const override;
        void setItem(T item, int index);
        void insertBegin(T item);
        void insertEnd(T item);
        void insertIndex(T item, int index);
        T removeBegin() override;
        T removeEnd() override;
        T removeIndex(int index) override;
        int search(T item) const override;
        void printList() const override;
        void clear() override;
};


#endif