#ifndef TAKEAWAYPLAYER_H
#define TAKEAWAYPLAYER_H

#include "board.h"

class TakeAwayBoard : public Board {
private:
    int data;
public:
    TakeAwayBoard(const int d);
    void init();
    void print_board() const;
    int get_data() const;
    TakeAwayBoard* clone() const;
    bool less_than(const Board* b2) const;


};

#endif
