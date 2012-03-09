#ifndef CRUNCHER_H
#define CRUNCHER_H

#include <map>
#include <vector>

#include "board.h"
#include "position.h"
#include "defines.h"


using namespace std;

struct compareBoards {
    bool operator()(const Board* b1,const Board* b2) const {
        return b1->less_than(b2);
    }
};


class Solver {
private:
    Board* best;
    map< Board* , int , compareBoards> memo_table;
public:
    Solver();
    ~Solver();
    int negamax(Position* pos ,int alpha,int beta, int color, int depth);
    virtual vector < Position* > generate_moves(Board *board) = 0;
    Position* find_best_move(Board *board) ;
    virtual bool is_final(Position* pos) = 0;
    virtual int evaluate(Position *pos) = 0;

};


#endif

