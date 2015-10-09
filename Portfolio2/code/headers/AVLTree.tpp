#include "AVLTree.hpp"
#include <iostream>

template <class Type, int ALLOWED_IMBALANCE>
AVLNode<Type, ALLOWED_IMBALANCE>::AVLNode()
{
}

template <class Type, int ALLOWED_IMBALANCE>
AVLNode<Type, ALLOWED_IMBALANCE>::~AVLNode()
{
  if(left) delete left;
  if(right) delete right;
  if(element) delete element;
}

template <class Type, int ALLOWED_IMBALANCE>
void AVLNode<Type, ALLOWED_IMBALANCE>::insert(AVLNode<Type, ALLOWED_IMBALANCE> * &node, Type &new_element)
{
  if(!node->element)
  {
    node->element = new Type;
    *(node->element) = new_element;
    node->height = 0;
  }
  else if(new_element > *(node->element))
  {
    if(!node->right)
      node->right = new AVLNode<Type, ALLOWED_IMBALANCE>();
    node->right->insert(node->right, new_element);
  }
  else if(new_element < *(node->element))
  {
    if(!node->left)
      node->left = new AVLNode<Type, ALLOWED_IMBALANCE>();
    node->left->insert(node->left, new_element);
  }
  balance(node);
}

template <class Type, int ALLOWED_IMBALANCE>
bool AVLNode<Type, ALLOWED_IMBALANCE>::contains(AVLNode<Type, ALLOWED_IMBALANCE> * &node, Type &test_element)
{
  if(node == nullptr || node->element == nullptr) return false;
  if(test_element > *(node->element)) return node->contains(node->right, test_element);
  if(test_element < *(node->element))  return node->contains(node->left, test_element);
  return true;
}

template <class Type, int ALLOWED_IMBALANCE>
void AVLNode<Type, ALLOWED_IMBALANCE>::print(AVLNode<Type, ALLOWED_IMBALANCE> * &node)
{
  if(node == nullptr || node->element == nullptr) return;
  std::cout << *(node->element) << std::endl;
  node->print(node->left);
  node->print(node->right);
}

template <class Type, int ALLOWED_IMBALANCE>
int AVLNode<Type, ALLOWED_IMBALANCE>::get_height(AVLNode<Type, ALLOWED_IMBALANCE> * &node)
{
  return node == nullptr ? -1 : node->height;
}

template <class Type, int ALLOWED_IMBALANCE>
void AVLNode<Type, ALLOWED_IMBALANCE>::balance(AVLNode<Type, ALLOWED_IMBALANCE> * &node)
{ //balances the tree
  if(get_height(node->left) - get_height(node->right) > ALLOWED_IMBALANCE)
  {
    if(get_height(node->left->left) >= get_height(node->left->right))
      rotate_left(node);
    else
      drotate_left(node);
  }
  else if(get_height(node->right) - get_height(node->left) > ALLOWED_IMBALANCE)
  {
    if(get_height(node->right->right) >= get_height(node->right->left))
      rotate_right(node);
    else
      drotate_right(node);
  }
  node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
}

template <class Type, int ALLOWED_IMBALANCE>
void AVLNode<Type, ALLOWED_IMBALANCE>::rotate_left(AVLNode<Type, ALLOWED_IMBALANCE> * &k2)
{
  auto k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;
  k2->height = std::max(get_height(k2->left), get_height(k2->right)) + 1;
  k1->height = std::max(get_height(k1->right), get_height(k1->right)) + 1;
  k2 = k1;
}

template <class Type, int ALLOWED_IMBALANCE>
void AVLNode<Type, ALLOWED_IMBALANCE>::rotate_right(AVLNode<Type, ALLOWED_IMBALANCE> * &k2)
{
  auto k1 = k2->right;
  k2->right = k1->left;
  k1->left = k2;
  k2->height = std::max(get_height(k2->left), get_height(k2->right)) + 1;
  k1->height = std::max(get_height(k1->left), get_height(k1->right)) + 1;
  k2 = k1;

}
template <class Type, int ALLOWED_IMBALANCE>
void AVLNode<Type, ALLOWED_IMBALANCE>::drotate_left(AVLNode<Type, ALLOWED_IMBALANCE> * &node)
{
  node->rotate_right(node->left);
  node->rotate_left(node);
}

template <class Type, int ALLOWED_IMBALANCE>
void AVLNode<Type, ALLOWED_IMBALANCE>::drotate_right(AVLNode<Type, ALLOWED_IMBALANCE> * &node)
{
  node->rotate_left(node->right);
  node->rotate_right(node);
}

/*****************************
** AVL Tree class funcitons **
*****************************/
template <class Type, int ALLOWED_IMBALANCE>
AVLTree<Type, ALLOWED_IMBALANCE>::AVLTree()
{
  //create root node
  rootNode = new AVLNode<Type, ALLOWED_IMBALANCE>;
}


template <class Type, int ALLOWED_IMBALANCE>
AVLTree<Type, ALLOWED_IMBALANCE>::~AVLTree()
{
  if(rootNode != nullptr) delete rootNode;
}

template <class Type, int ALLOWED_IMBALANCE>
void AVLTree<Type, ALLOWED_IMBALANCE>::insert(Type new_element)
{
  rootNode->insert(rootNode, new_element);
}

template <class Type, int ALLOWED_IMBALANCE>
bool AVLTree<Type, ALLOWED_IMBALANCE>::contains(Type test_element)
{
  return rootNode->contains(rootNode, test_element);
}

template <class Type, int ALLOWED_IMBALANCE>
void AVLTree<Type, ALLOWED_IMBALANCE>::print()
{
  rootNode->print(rootNode);
}
template <class Type, int ALLOWED_IMBALANCE>
int AVLTree<Type, ALLOWED_IMBALANCE>::get_height()
{
  return rootNode->height;
}
