#ifndef POSITION_H_
#define POSITION_H_

#include "board.h"

class Board;

class Position {
private:
    int score;
    Board* board;

public:
    Position();
    Position(Board* brd);
    ~Position();
    void set_score(int scr);
    void set_board(Board* brd);
    int get_score() const;
    Board* get_board() const;
};



#endif // POSITION_H_

