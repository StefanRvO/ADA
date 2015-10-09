#pragma once
#include <cstdlib>

template <class Type>
class SplayNode
{
  public:
    Type *element = nullptr;
    SplayNode<Type> *left = nullptr; //less
    SplayNode<Type> *right = nullptr; //more
    SplayNode<Type> *parent = nullptr; //parent

    SplayNode(SplayNode<Type> *node);
    ~SplayNode();
    void static print(SplayNode<Type> * &node);
};

template <class Type>
class SplayTree
{
  public:
    SplayNode<Type> *rootNode = nullptr;
  public:
    void zigzag(SplayNode<Type> *node);
    void zagzig(SplayNode<Type> *node);
    void zigzig(SplayNode<Type> *node);
    void zagzag(SplayNode<Type> *node);
    void zig(SplayNode<Type> *node);
    void zag(SplayNode<Type> *node);
    void splay(SplayNode<Type> *node);
    bool contains(SplayNode<Type> *node, Type &test_element);
    void insert(Type new_element);
    void insert(SplayNode<Type> *node, Type &new_element);
    bool contains(Type test_element);
    void print();
    int get_height();
    SplayTree();
    ~SplayTree();

};

#include "SplayTree.tpp"
