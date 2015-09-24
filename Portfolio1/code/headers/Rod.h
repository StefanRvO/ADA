#pragma once
#include <vector>
#include <string>

class Rod
{
  private:
    std::vector <int> discs;
  public:
    Rod(const int number_of_discs);
    int popDisc();
    bool pushDisc(const int disc_size);
    unsigned long getNumberOfDiscs() const;
    std::string getDiscString() const;
};
