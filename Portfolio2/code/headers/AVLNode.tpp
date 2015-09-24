#include "AVLNode.hpp"
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
  std::cout << "Fuck dig din ost." << std::endl;
}

template <class Type, int ALLOWED_IMBALANCE>
void AVLNode<Type, ALLOWED_IMBALANCE>::insert(Type &new_element)
{
  if(!element)
  {
    element = new Type;
    *element = new_element;
    height = 0;
  }
  else if(new_element > *element)
  {
    if(!right)
      right = new AVLNode<Type, ALLOWED_IMBALANCE>();
    right->insert(new_element);
  }
  else if(new_element < *element)
  {
    if(!left)
      left = new AVLNode<Type, ALLOWED_IMBALANCE>();
    left->insert(new_element);
  }
  balance();
}

template <class Type, int ALLOWED_IMBALANCE>
int AVLNode<Type, ALLOWED_IMBALANCE>::get_height(AVLNode<Type, ALLOWED_IMBALANCE> *node)
{
  return node == nullptr ? -1 : node->height;
}

template <class Type, int ALLOWED_IMBALANCE>
void AVLNode<Type, ALLOWED_IMBALANCE>::balance()
{ //balances the tree
  if(get_height(left) - get_height(right) > ALLOWED_IMBALANCE)
  {
    if(get_height(left->left) >= get_height(left->right))
      rotate_left();
    else
      drotate_left();
  }
  else if(get_height(right) - get_height(left) > ALLOWED_IMBALANCE)
  {
    if(get_height(right->right) >= get_height(right->left))
      rotate_right();
    else
      drotate_right();
  }
  height = std::max(get_height(left), get_height(right)) + 1;
}

template <class Type, int ALLOWED_IMBALANCE>
void AVLNode<Type, ALLOWED_IMBALANCE>::rotate_left()
{
  auto tmp = left;
  left = left->left;
  tmp->left = left->right;
  left->right = tmp;
  tmp->height = std::max(get_height(tmp->left), get_height(tmp->right)) + 1;
  left->height = std::max(get_height(left->left), get_height(left->right)) + 1;
}

template <class Type, int ALLOWED_IMBALANCE>
void AVLNode<Type, ALLOWED_IMBALANCE>::rotate_right()
{
  auto tmp = right;
  right = right->right;
  tmp -> right = right->left;
  right->left = tmp;
  tmp->height = std::max(get_height(tmp->left), get_height(tmp->right)) + 1;
  right->height = std::max(get_height(right->left), get_height(right->right)) + 1;
}

template <class Type, int ALLOWED_IMBALANCE>
void AVLNode<Type, ALLOWED_IMBALANCE>::drotate_left()
{
  left->rotate_right();
  rotate_left();
}

template <class Type, int ALLOWED_IMBALANCE>
void AVLNode<Type, ALLOWED_IMBALANCE>::drotate_right()
{
  right->rotate_left();
  rotate_right();
}
