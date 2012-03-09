#include "position.h"


Position::Position() : score(0) {

}

Position::Position(Board* brd) : score(0), board(brd) {
}

Position::~Position() {
	delete board;
}

void Position::set_score(int scr){
	score = scr;
}

void Position::set_board(Board* brd){
	board = brd;
}

int Position::get_score() const {
    return score;
}

Board* Position::get_board() const{
	return board;
}
