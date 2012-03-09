#include <iostream>

#include "takeawayboard.h"

TakeAwayBoard::TakeAwayBoard(const int d): data(d){

}
  
void TakeAwayBoard::init(){
}

void TakeAwayBoard::print_board() const{
  std::cout<<data<<endl;
}
  
int TakeAwayBoard::get_data() const{
  return data;
}

TakeAwayBoard* TakeAwayBoard::clone() const{
  return new TakeAwayBoard(data);  
}

bool TakeAwayBoard::less_than(const Board* b2) const{
  const TakeAwayBoard* board = static_cast<const TakeAwayBoard*>(b2);
  return (this->get_data() < board->get_data());
}

 


