#include "node.hpp"

// Node implementation

template <typename T>
Node<T>::Node(T item) : item(item), next(nullptr) {}
