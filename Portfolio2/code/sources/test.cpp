#include "../headers/AVLNode.hpp"
#include <iostream>
int main()
{
  AVLNode<int, 1> Tree;
  for(int i = 0; i < 10000; i++)
    Tree.insert(i);
  std::cout << Tree.height << std::endl;
}
