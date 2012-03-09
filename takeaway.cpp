#include <iostream>         // system header include for I/O
#include <stdlib.h>

#include "player.h"
#include "takeawayboard.h"
#include "takeawaysolver.h"
#include "board.h"

using namespace std;

int main(int argc, char* argv[]) {
    int val;
    bool human = false;
    if(argc == 3) {
        string str(argv[1]);

        if(str.compare("play")==0) {
            human=true;
        }
        val=atoi(argv[2]);

    }
    else if(argc==2) {
        val=atoi(argv[1]);

    }
    else {
        cerr<<"Usage: takeaway [play] num_pennies"<<endl;
        return 0;
    }

    if(val<0) {
        cerr<<"Number of coins must be positive"<<endl;
        return 0;
    }
    Board* board = new TakeAwayBoard(val);
    TakeAwaySolver solver;
    Player left(human);
    Player right(false);
    left.move(&board,solver);
//    board->print_board();
//    left.move(&board,solver);
    delete board;
/*    TakePosition pos(val);
    do {
        cout<<"LEFT"<<endl;
        left.move(pos);
        if(left.is_final(pos)) {
            cout<<"Lose"<<endl;
            return 0;
        }
        cout<<"RIGHT"<<endl;
        right.move(pos);
        if(right.is_final(pos)) {
            cout<<"Win"<<endl;
            return 0;
        }
    } while(!left.is_final(pos));
*/    


    return 0;
}






