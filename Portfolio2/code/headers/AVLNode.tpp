#include "AVLNode.hpp"
#include <iostream>

template <class Type, size_t ALLOWED_IMBALANCE>
AVLNode<Type, ALLOWED_IMBALANCE>::AVLNode()
{
}

AVLNode<Type, ALLOWED_IMBALANCE>::~AVLNode()
{
  if(left) delete left;
  if(right) delete right;
  if(element) delete element;
  std::cout << "Fuck dig din ost." << std::endl;
}

AVLNode<Type, ALLOWED_IMBALANCE>::insert(Type &new_element)
{
  if(!element)
  {
    element = new Type;
    *element = new_element;
    height = 0;
  }
  else if(new_element > element)
  {
    if(!right)
      right = new AVLNode<Type, ALLOWED_IMBALANCE>();
    right->insert(new_element);
  }
  else if(new_element < element)
  {
    if(!left)
      left = new AVLNode<Type, ALLOWED_IMBALANCE>();
    left->insert(new_element);
  }
  balance();
}

int static AVLNode<Type, ALLOWED_IMBALANCE>::get_height(AVLNode<Type, ALLOWED_IMBALANCE> *node)
{
  return node == nullptr ? -1 : node->height;
}

AVLNode<Type, ALLOWED_IMBALANCE>::balance()
{ //balances the tree
  if(height(left) - height(right) > ALLOWED_IMBALANCE)
  {
    if(height(left->left) >= height(left->right))
      rotate_left();
    else
      drotate_left();
  }
  else if(height(right) - height(left) > ALLOWED_IMBALANCE)
  {
    if(height(right->right) >= height(right->left))
      rotate_right();
    else
      drotate_right();
  }
  height = max(height(left), height(right)) + 1;
}

void AVLNode<Type, ALLOWED_IMBALANCE>::rotate_left(AVLNode<Type, ALLOWED_IMBALANCE> *Node)
{
  auto tmp = left;
  left = left->left
  tmp->left = left->right;
  left->right = tmp;
  tmp->height = max(height(tmp->left), height(tmp->right)) + 1;
  left->height = max(height(left->left), height(left->right)) + 1;
}

void AVLNode<Type, ALLOWED_IMBALANCE>::rotate_right(AVLNode<Type, ALLOWED_IMBALANCE> *Node);
{
  auto tmp = right;
  right = right->right
  tmp -> right = right->left;
  right->left = tmp;
  tmp->height = max(height(tmp->left), height(tmp->right)) + 1;
  right->height = max(height(right->left), height(right->right)) + 1;
}

void AVLNode<Type, ALLOWED_IMBALANCE>::drotate_left(AVLNode<Type, ALLOWED_IMBALANCE> *Node)
{
  left->rotate_right();
  rotate_left();
}

void AVLNode<Type, ALLOWED_IMBALANCE>::drotate_right(AVLNode<Type, ALLOWED_IMBALANCE> *Node)
{
  right->rotate_left();
  rotate_right();
}
