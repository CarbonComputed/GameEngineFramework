#include "takeawayboard.h"
#include "solver.h"
#include <iostream>
using namespace std;

Solver::Solver() {
  best = NULL;
}

Solver::~Solver(){
  map< Board*, int>::iterator it;
  for(it = memo_table.begin();it !=  memo_table.end();it++){
    delete it->first;
  }
}

Position* Solver::find_best_move(Board* board) {
  Position* pos = new Position(board);
  int score = negamax(pos,99999,-99999, 1, -1 );
  pos->set_board(best);
  pos->set_score(score);
  return pos;
}

int Solver::negamax(Position* pos,int alpha,int beta, int color, int depth ) {
  map < Board* , int >::iterator it;
  it = memo_table.find(pos->get_board());
  if(it != memo_table.end()){
    return it->second;
  }
	else if(depth==0 || is_final(pos)){
	  return evaluate(pos);
	}
	else{
		vector < Position* > moves = generate_moves(pos->get_board());
		vector < Position* >::iterator move;
    int min = 99999;
		for(move = moves.begin(); move < moves.end(); move++){
			int val = negamax(*move,alpha, beta, -color, depth - 1 );
      it = memo_table.find((*move)->get_board());
      if(it == memo_table.end()){
        memo_table[(*move)->get_board()->clone()] = val;
      }
      if(val <= min){
         min = val;
         delete best;
         best = NULL;
         best = (*move)->get_board()->clone();
        
      }
      
      delete *move;
      
	  }
		min = -min;
    return min;
	}
	
}
	


