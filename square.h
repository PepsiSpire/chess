#ifndef _SQUARE_H_
#define _SQUARE_H_
class Square;
#include "player.h"
#include "piece.h"

class Square {
    Piece* piece = nullptr;
    int row, col, color;
    
    public:
          Square(int row, int col, int clr);
          Square(int row, int col, int clr, Piece* piece);
         ~Square();
         bool isOccupied();
         int getRow();
         int getCol();
         char getSymbol();
         void setNull();
         bool validCapture(int clr);
         void move(int r, int c);
         bool validateMove(int r, int c, int clr);
         void occupy(Piece* piece);
         Piece* getPiece();
         void clear();
        
};

#endif
