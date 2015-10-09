#include "../headers/SplayTree.hpp"
#include <iostream>
int main()
{
  SplayTree<int> Tree;
  for(int i = 0; i < 20; i++)
    Tree.insert(i);
  Tree.contains(10);

}
