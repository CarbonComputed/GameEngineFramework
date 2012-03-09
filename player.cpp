#include <iostream>

#include "player.h"

using namespace std;

Player::Player(bool is_human) :_is_human(is_human) {
}

Player::~Player() {

}

bool Player::is_human() const {
    return _is_human;
}

void Player::move(Board ** board, Solver &solver) {
    Position* best = solver.find_best_move(*board);
    cout<<"Score: "<<best->get_score()<<endl;
    cout<<"Board: ";
    delete *board;
    *board = NULL;
    *board = best->get_board()->clone();
    (*board)->print_board();
    delete best;
}



