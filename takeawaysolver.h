#ifndef TAKEAWAYSOLVER_H
#define TAKEAWAYSOLVER_H

#include "solver.h"
#include "position.h"
#include "board.h"

class TakeAwaySolver : public Solver {

public:
    vector < Position* > generate_moves(Board *board);
    bool is_final(Position* pos);
    int evaluate(Position * pos);
//  bool compare(Board* b, Board* b2) const;

};

#endif
