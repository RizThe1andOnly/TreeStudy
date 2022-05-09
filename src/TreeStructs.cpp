#include <iostream>
#include "TreeStructs.h"

template class Node<int>;
template class BinaryNode<int>;

template <typename T> Node<T>::Node() {}

template <typename T> BinaryNode<T>::BinaryNode() {}

template <typename T> void BinaryNode<T>::setRight() {
    std::cout << "hello world" << std::endl;
}

void doSomething(){
    std::cout << "hello world, linking for this was successful" << std::endl;
}