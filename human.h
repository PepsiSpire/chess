#ifndef _HUMAN_H_
#define _HUMAN_H_
#include <string>
#include "player.h"

class Human : public Player {
    public:
        Human(int clr, Board* board);

        void Move() override;

        virtual ~Human();
};

#endif
