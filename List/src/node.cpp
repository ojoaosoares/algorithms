#include "node.hpp"

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