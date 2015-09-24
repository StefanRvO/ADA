#pragma once

template <class Type, size_t ALLOWED_IMBALANCE>
class AVLNode
{
  public:
    Type *element;
    AVLNode<Type, ALLOWED_IMBALANCE> *left = nullptr; //less
    AVLNode<Type, ALLOWED_IMBALANCE> *right = nullptr; //more
    int height = -1;

    void insert(Type &new_element);
    bool contains(Type &test_element);
    void print();
    AVLNode(Type *_element);
    ~AVLNode();
  private:
    void rotate_left(AVLNode<Type, ALLOWED_IMBALANCE> *Node);
    void rotate_right(AVLNode<Type, ALLOWED_IMBALANCE> *Node);
    void drotate_left(AVLNode<Type, ALLOWED_IMBALANCE> *Node);
    void drotate_right(AVLNode<Type, ALLOWED_IMBALANCE> *Node);
    void balance(AVLNode<Type, ALLOWED_IMBALANCE> *Node);
    int static get_height(AVLNode<Type, ALLOWED_IMBALANCE> *node)

}

#include "AVLNode.tpp"
