#include <iostream>
#include "Node.hpp"
#include <string>
#include <boost/filesystem.hpp>


using namespace boost::filesystem;

Node *insertfolder(std::string dir)
{
  path p(dir);
  Node *this_node = new Node(0);
  int sum = 0; //number of files in directory and all subdirectories
  if(is_regular_file(p))
  {
    sum++;
  }
  else if(is_directory(p))
  {
    sum++;
    for(auto &x : directory_iterator(p))
    {
      Node *node = insertfolder(x.path().string());
      sum += node->getValue();
      this_node->add_subnode(*node);
    }
  }
  this_node->setValue(sum);
  return this_node;
}

int main(int argc, char** argv)
{
  Node *node = insertfolder(std::string(argv[1]));
  std::cout << node->getValue() << std::endl;
}
