#include "../headers/SplayTree.hpp"
#include "../headers/AVLTree.hpp"
#include <sys/time.h>
#include <iostream>

long gettimediff(timeval *tv_start, timeval *tv_end)
{
  long seconds = tv_end->tv_sec - tv_start->tv_sec;
  long useconds = tv_end->tv_usec - tv_start->tv_usec;
  return seconds * 1000000 + useconds;
}

int main()
{
  srand(time(NULL));
  timeval tv_start;
  timeval tv_end;
  //Test AVL tree increasing
  std::cout << "AVL Increasing" << std::endl;
  for(int i = 1; i < 100000000; i *= 2)
  {
    AVLTree<int, 1> Tree;
    gettimeofday(&tv_start, NULL);
    for(int j = 0; j < i; j++)
      Tree.insert(j);
    gettimeofday(&tv_end, NULL);
    std::cout << i << "\t" << gettimediff(&tv_start, &tv_end) <<  std::endl;
  }
  //Test AVL tree decreasing
  std::cout << std::endl;
  std::cout << "AVL decreasing" << std::endl;
  for(int i = 1; i < 100000000; i *= 2)
  {
    AVLTree<int, 1> Tree;
    gettimeofday(&tv_start, NULL);
    for(int j = i; j > 0; j--)
      Tree.insert(j);
    gettimeofday(&tv_end, NULL);
    std::cout << i << "\t" << gettimediff(&tv_start, &tv_end) <<  std::endl;
  }
  //test AVL tree random
  std::cout << std::endl;
  std::cout << "AVL random" << std::endl;
  for(int i = 1; i < 100000000; i *= 2)
  {
    AVLTree<int, 1> Tree;
    //generate random numbers
    int *randnums = new int[i];
    for(int j = 0; j < i; j++)
      randnums[j] = rand() % i;

    gettimeofday(&tv_start, NULL);
    for(int j = 0; j < i; j++)
      Tree.insert(randnums[j]);
    gettimeofday(&tv_end, NULL);
    delete[] randnums;
    std::cout << i << "\t" << gettimediff(&tv_start, &tv_end) <<  std::endl;
  }
  std::cout << std::endl << std::endl;
  //**************splay*************//
  //Test Splay tree increasing
  std::cout << "Splay Increasing" << std::endl;
  for(int i = 1; i < 100000000; i *= 2)
  {
    SplayTree<int> Tree;
    gettimeofday(&tv_start, NULL);
    for(int j = 0; j < i; j++)
      Tree.insert(j);
    gettimeofday(&tv_end, NULL);
    std::cout << i << "\t" << gettimediff(&tv_start, &tv_end) <<  std::endl;
  }
  //Test Splay tree decreasing
  std::cout << std::endl;
  std::cout << "Splay decreasing" << std::endl;
  for(int i = 1; i < 100000000; i *= 2)
  {
    SplayTree<int> Tree;
    gettimeofday(&tv_start, NULL);
    for(int j = i; j > 0; j--)
      Tree.insert(j);
    gettimeofday(&tv_end, NULL);
    std::cout << i << "\t" << gettimediff(&tv_start, &tv_end) <<  std::endl;
  }
  //test Splay tree random
  std::cout << std::endl;
  std::cout << "Splay random" << std::endl;
  for(int i = 1; i < 100000000; i *= 2)
  {
    SplayTree<int> Tree;
    //generate random numbers
    int *randnums = new int[i];
    for(int j = 0; j < i; j++)
      randnums[j] = rand() % i;

    gettimeofday(&tv_start, NULL);
    for(int j = 0; j < i; j++)
      Tree.insert(randnums[j]);
    gettimeofday(&tv_end, NULL);
    delete[] randnums;
    std::cout << i << "\t" << gettimediff(&tv_start, &tv_end) <<  std::endl;
  }


  std::cout << std::endl << std::endl;
  SplayTree<int> STree;
  AVLTree<int, 1> ATree;
  for(int i = 0; i < 10; i++)
  {
    int tmp = rand() % 100;
    STree.insert(tmp);
    ATree.insert(tmp);
    std::cout << tmp << " ";
  }
  std::cout << std::endl << std::endl;
  std::cout << "AVLTree testprint" << std::endl;
  ATree.print();
  std::cout << std::endl << std::endl;
  std::cout << "SplayTree testprint" << std::endl;
  STree.print();
}
