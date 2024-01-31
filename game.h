#ifndef _GAME_H_
#define _GAME_H_
#include <string>
#include <vector>
#include "board.h"
#include "player.h"

class Game {
    Board* board;
    Player* white = nullptr;
    Player* black = nullptr;
    bool started = false;
    int whiteWins = 0;
    int blackWins = 0;
    int nextColor = 0;
    public:
          Game(Xwindow &w);
         ~Game();
         void newGame(int w, int b);
         void nextTurn();
         bool running();
         void insertPiece(position p, char c);
         void deletePiece(position p);
         void printBoard();
         bool validateBoard();
         void setNext(int clr);
         int score(int clr);
        
};

#endif
