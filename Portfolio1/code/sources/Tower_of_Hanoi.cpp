#define _unused(x) ((void)x) //Prevent compiler warnings about unused variables

#include "../headers/Tower_of_Hanoi.h"
#include <iostream>
#include <cassert>
Tower_of_Hanoi::Tower_of_Hanoi(const int n, const bool _verbose)
:A(n), B(0), C(0)
{
  verbose = _verbose;
  discs = n;
}

void Tower_of_Hanoi::move_discs(Rod &Move_from, Rod &Move_to, Rod &Last, const int n)
{
  if(n == 1)
  { //If only moving one disc, just move it
    bool sucess = Move_to.pushDisc(Move_from.popDisc());
    assert(sucess == true);
    _unused(sucess);
    if(verbose) this->print_step();
    return;
  }
  /*else, we move n - 1 discs to the last rod,
  **meaning that there will be 1 disc left on the start rod.
  **We move this disc to the wanted Rod, and move all remaining discs
  **on top of this one.
  */
  move_discs(Move_from, Last, Move_to, n - 1);
  move_discs(Move_from, Move_to, Last, 1);
  move_discs(Last, Move_to, Move_from, n - 1);
}

void Tower_of_Hanoi::print_step()
{
  std::cout << "STEP " << ++step << ":" << std::endl;
  std::cout << "A: " << A.getDiscString() << std::endl;
  std::cout << "B: " << B.getDiscString() << std::endl;
  std::cout << "C: " << C.getDiscString() << std::endl;
  std::cout << std::endl;
}

void Tower_of_Hanoi::solve()
{
  this->move_discs(A, B, C, discs);
}
