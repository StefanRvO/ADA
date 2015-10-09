#include "SplayTree.hpp"
#include <iostream>

template <class Type>
SplayNode<Type>::SplayNode(SplayNode<Type> *node)
{
  parent = node;
}

template <class Type>
SplayNode<Type>::~SplayNode()
{
  if(left) delete left;
  if(right) delete right;
  if(element) delete element;
}

template <class Type>
void SplayNode<Type>::print(SplayNode<Type> * &node)
{
  if(node == nullptr || node->element == nullptr) return;
  std::cout << *(node->element) << std::endl;
  node->print(node->left);
  node->print(node->right);
}


/*****************************
** AVL Tree class funcitons **
*****************************/
template <class Type>
SplayTree<Type>::SplayTree()
{
  //create root node
  rootNode = new SplayNode<Type>(nullptr);
}


template <class Type>
SplayTree<Type>::~SplayTree()
{
  if(rootNode != nullptr) delete rootNode;
}

template <class Type>
void SplayTree<Type>::insert(SplayNode<Type> *node, Type &new_element)
{
  if(!node->element)
  {
    node->element = new Type;
    *(node->element) = new_element;
    splay(node);
  }
  else if(new_element > *(node->element))
  {
    if(!node->right)
      node->right = new SplayNode<Type>(node);
    insert(node->right, new_element);
  }
  else if(new_element < *(node->element))
  {
    if(!node->left)
      node->left = new SplayNode<Type>(node);
    insert(node->left, new_element);
  }
}

template <class Type>
void SplayTree<Type>::insert(Type new_element)
{
  insert(rootNode, new_element);
  //std::cout << *(rootNode->element) << std::endl;
}


template <class Type>
void SplayTree<Type>::splay(SplayNode<Type> *node)
{ //Splays the node to the top of the tree
  while(node->parent != nullptr)
  {
    if(node->parent->parent == nullptr) //parent is root
    {
      if(node->parent->left == node) //node is a left child
        zig(node->parent);
      else
        zag(node->parent);
    }
    else if(node->parent->left == node && node->parent->parent->left == node->parent)
      zigzig(node);
    else if(node->parent->right == node && node->parent->parent->right == node->parent)
      zagzag(node);
    else if(node->parent->left == node && node->parent->parent->right == node->parent)
      zigzag(node);
    else if(node->parent->right == node && node->parent->parent->left == node->parent)
      zagzig(node);
  }
}
template <class Type>
void SplayTree<Type>::zag(SplayNode<Type> *k2)
{
  auto k1 = k2->right;
  if(k1 != nullptr)
  {
    k2->right = k1->left;
    if(k1->left != nullptr)
      k1->left->parent = k2;
    k1->parent = k2->parent;
  }
  if(k2->parent == nullptr) rootNode = k1;
  else if(k2 == k2->parent->left) k2->parent->left = k1;
  else k2->parent->right = k1;
  if(k1 != nullptr)
    k1->left = k2;
  k2->parent = k1;
}

template <class Type>
void SplayTree<Type>::zig(SplayNode<Type> *k2)
{
  auto k1 = k2->left;
  if(k1 != nullptr)
  {
    k2->left = k1->right;
    if(k1->right != nullptr)
      k1->right->parent = k2;
    k1->parent = k2->parent;
  }
  if(k2->parent == nullptr) rootNode = k1;
  else if(k2 == k2->parent->left) k2->parent->left = k1;
  else k2->parent->right = k1;
  if(k1 != nullptr)
    k1->right = k2;
  k2->parent = k1;
}

template <class Type>
bool SplayTree<Type>::contains(SplayNode<Type> *node, Type &test_element)
{
  if(node == nullptr || node->element == nullptr) return false;
  if(test_element > *(node->element)) return contains(node->right, test_element);
  if(test_element < *(node->element))  return contains(node->left, test_element);
  splay(node);
  return true;
}

template <class Type>
void SplayTree<Type>::zigzag(SplayNode<Type> *node)
{
  zig(node->parent);
  zag(node->parent);
}

template <class Type>
void SplayTree<Type>::zagzig(SplayNode<Type> *node)
{
  zag(node->parent);
  zig(node->parent);
}

template <class Type>
void SplayTree<Type>::zagzag(SplayNode<Type> *node)
{
  zag(node->parent->parent);
  zag(node->parent);
}

template <class Type>
void SplayTree<Type>::zigzig(SplayNode<Type> *node)
{
  zig(node->parent->parent);
  zig(node->parent);
}

template <class Type>
bool SplayTree<Type>::contains(Type test_element)
{
  return contains(rootNode, test_element);
}

template <class Type>
void SplayTree<Type>::print()
{
  rootNode->print(rootNode);
}
template <class Type>
int SplayTree<Type>::get_height()
{
  return rootNode->height;
}
