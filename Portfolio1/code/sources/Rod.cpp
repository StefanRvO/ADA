#include "../headers/Rod.h"
#include <cassert>
Rod::Rod(const int number_of_discs)
{ //creates the rod with the given number of discs on it
  for(int i = number_of_discs; i > 0; i--)
  {
    this->pushDisc(i);
  }
}

bool Rod::pushDisc(const int disc_size)
{
  if(discs.size())
  {
    if(discs.back() <= disc_size)
    {
      return false;
    }
    else
    {
      discs.push_back(disc_size);
      return true;
    }
  }
  else
  {
    discs.push_back(disc_size);
    return true;
  }
}
int Rod::popDisc()
{
  auto tmp = discs.back();
  discs.pop_back();
  return tmp;
}

std::string Rod::getDiscString() const
{
  std::string str;
  for(auto &i : discs)
  {
    str += std::to_string(i);
    str += ' ';
  }
  return str;
}
