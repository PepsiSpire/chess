#ifndef _COMPUTERS_H_
#define _COMPUTERS_H_
#include <string>
#include "player.h"

class Computer1 : public Player {
    public:
        Computer1(int clr, Board* board);

        void Move() override;

        virtual ~Computer1();
};

class Computer2 : public Player {
    public:
        Computer2(int clr, Board* board);

        void Move() override;

        virtual ~Computer2();
};

class Computer3 : public Player {
    public:
        Computer3(int clr, Board* board);

        void Move() override;

        virtual ~Computer3();
};

class Computer4 : public Player {
    public:
        Computer4(int clr, Board* board);

        void Move() override;

        virtual ~Computer4();
};

#endif
