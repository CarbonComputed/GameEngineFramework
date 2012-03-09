#include "takeawaysolver.h"
#include "takeawayboard.h"
using namespace std;

vector < Position* > TakeAwaySolver::generate_moves(Board *brd) {
    TakeAwayBoard *board = static_cast<TakeAwayBoard*>(brd);
    vector < Position* > moves;
    if(board->get_data() >= 3) {
        TakeAwayBoard *b = new TakeAwayBoard(board->get_data() - 3);
        Position* p = new Position(b);
        moves.push_back(p);
    }
    if(board->get_data() >= 2) {
        TakeAwayBoard *b = new TakeAwayBoard(board->get_data() - 2);
        Position* p = new Position(b);
        moves.push_back(p);
    }
    TakeAwayBoard *b = new TakeAwayBoard(board->get_data() - 1);
    Position* p = new Position(b);
    moves.push_back(p);
    return moves;
}

bool TakeAwaySolver::is_final(Position* pos) {
    TakeAwayBoard* board = static_cast<TakeAwayBoard*>(pos->get_board());
    if(board->get_data() == 0) {
        return true;
    }
    return false;
}

int TakeAwaySolver::evaluate(Position * pos) {
    return 1;
}
/*
bool operator()(Board* b1, Board* b2) const{
  TakeAwayBoard* board = static_cast<TakeAwayBoard*>(b);
  TakeAwayBoard* board2 = static_cast<TakeAwayBoard*>(b2);
  return board->get_data() < board2->get_data();
}
*/
