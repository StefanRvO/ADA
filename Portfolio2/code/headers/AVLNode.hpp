#pragma once
#include <cstdlib>
template <class Type, int ALLOWED_IMBALANCE>
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
    AVLNode();
    ~AVLNode();
  private:
    void rotate_left();
    void rotate_right();
    void drotate_left();
    void drotate_right();
    void balance();
    int static get_height(AVLNode<Type, ALLOWED_IMBALANCE> *node);
};

#include "AVLNode.tpp"
