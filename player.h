#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>

#include "defines.h"
#include "board.h"
#include "solver.h"

using namespace std;

class Player {
private:
	bool _is_human;
public:
    Player(bool is_human);
    ~Player();
    bool is_human() const;
    void move(Board ** board, Solver & solver);
};

#endif // PLAYER_H_

