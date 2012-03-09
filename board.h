#ifndef BOARD_H_
#define BOARD_H_

#include "defines.h"
#include <iostream>
using namespace std;

class Board {
public:
   
  virtual void init() = 0;
  virtual void print_board() const = 0;
  virtual Board* clone() const = 0;
  virtual bool less_than(const Board* b2) const = 0;
};

#endif
