#include "../headers/AVLNode.hpp"
#include <iostream>
int main()
{
  AVLTree<int, 1> Tree;
  for(int i = 0; i < 20; i++)
    Tree.insert(i);
  Tree.print();

}
