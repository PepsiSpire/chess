#ifndef _PIECE_H_
#define _PIECE_H_
#include <string>
#include <vector>
class Piece;
struct position;
#include "board.h"

struct position{
    int row;
    int col;
};



class Piece {
    protected:
    int row;
    int col;
    int color;
    Board* board;
    std::vector<position> legalMoves;
    public:
        Piece(int r, int c, int clr, Board* b);
        void move(int r, int c);
        bool ValidateMove(int r, int c);
        virtual void GenerateMoves() = 0;
        void GenerateLegalMoves();
        int GetRow();
        int GetCol();
        virtual bool CanWin() = 0;
        virtual char getSymbol() = 0;
        std::string getColorString();
        int getColor();
        bool hasMoves();
        std::vector<position> getMoves();
        virtual ~Piece();
};

#endif
