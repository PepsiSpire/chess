#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
class Player;
#include "board.h"

class Player {
    protected:
    int color;
    Board* board;
    public:
        Player(int clr, Board* board);
        int getColor();
        virtual void Move();
        void GenerateMoves();
        virtual ~Player();
};

#endif
