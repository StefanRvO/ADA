#pragma once
#include "Rod.h"
class Tower_of_Hanoi
{
  private:
    Rod A;
    Rod B;
    Rod C;
    unsigned long step = 0;
    bool verbose;
    int discs;
    void move_discs(Rod &Move_from, Rod &Move_to, Rod &Last, const int n);
    void print_step();
  public:
    Tower_of_Hanoi(const int n, const bool _verbose);
    void solve();
};
