#include <string>
#include <iostream>
#include <cstdlib>
#include "../headers/Tower_of_Hanoi.h"
int main(const int argc, const char **argv)
{
  if(argc < 2)
  {
    std::cout << "Not enough arguments" << std::endl;
    std::cout << "Run with <number of discs> [<--verbose>]" << std::endl;
    exit(0);
  }
  bool verbose = false;
  for(int i = 2; i < argc; i++)
  {
    if(std::string(argv[i]) == "--verbose") verbose = true;
  }
  int disc_number = atoi(argv[1]);
  Tower_of_Hanoi T(disc_number, verbose);
  T.solve();

  return 0;
}
