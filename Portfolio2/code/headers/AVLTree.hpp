#pragma once
#include <cstdlib>

template <class Type, int ALLOWED_IMBALANCE>
class AVLNode
{
  public:
    Type *element = nullptr;
    AVLNode<Type, ALLOWED_IMBALANCE> *left = nullptr; //less
    AVLNode<Type, ALLOWED_IMBALANCE> *right = nullptr; //more
    int height = -1;


    AVLNode();
    ~AVLNode();
    void static rotate_left(AVLNode<Type, ALLOWED_IMBALANCE> * &node);
    void static rotate_right(AVLNode<Type, ALLOWED_IMBALANCE> * &node);
    void static drotate_left(AVLNode<Type, ALLOWED_IMBALANCE> * &node);
    void static drotate_right(AVLNode<Type, ALLOWED_IMBALANCE> * &node);
    void static balance(AVLNode<Type, ALLOWED_IMBALANCE> * &node);
    int static get_height(AVLNode<Type, ALLOWED_IMBALANCE> * &node);
    void static insert(AVLNode<Type, ALLOWED_IMBALANCE> * &node, Type &new_element);
    bool static contains(AVLNode<Type, ALLOWED_IMBALANCE> * &node, Type &test_element);
    void static print(AVLNode<Type, ALLOWED_IMBALANCE> * &node);
};

template <class Type, int ALLOWED_IMBALANCE>
class AVLTree
{
  public:
    AVLNode<Type, ALLOWED_IMBALANCE> *rootNode = nullptr;
  public:
    void insert(Type new_element);
    bool contains(Type test_element);
    void print();
    int get_height();
    AVLTree();
    ~AVLTree();

};

#include "AVLTree.tpp"
