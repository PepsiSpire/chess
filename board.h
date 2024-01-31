#ifndef _BOARD_H_
#define _BOARD_H_
#include <string>
#include <vector>
class Board;
#include "square.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"
#include "piece.h"

struct fullmove{
    int r1;
    int c1;
    int r2;
    int c2;
};

class Board {
    std::vector<std::vector<Square>> theBoard;
    TextDisplay *td;
    GraphicsDisplay *gd;
    int resignedclr = -1;
    public:
          Board(Xwindow &w);
         ~Board();
         void setup();
         void addPiece(Piece* p, int r, int c);
         bool isOccupied(int r, int c);
         bool validCapture(int r, int c, int clr);
         bool validateMove(int r, int c, int r2, int c2, int clr);
         void move(int r, int c, int r2, int c2);
         bool hasMoves(int clr);
         bool hasMoves(int r, int c);
         void clear();
         void insertPiece(int r, int c, char p);
         void deletePiece(int r, int c);
         bool isEmpty();
         void print();
         bool isLegal(int r1, int c1, int r2, int c2, int clr);
         bool CanWin(int clr);
         void GenerateMoves(int clr);
         void resign(int clr);
         int resigned();
         int kingcount(int clr);
         bool pawnCanUpgrade(int clr);
         std::vector<position> OccupiedSquares(int clr);
         std::vector<position> validMoves(int row, int col);
         std::vector<fullmove> WinningMoves(int clr);
         std::vector<fullmove> CaptureMoves(int clr);
         bool createsCheck(int r1, int c1, int r2, int c2, int clr);
         bool isThreatened(int r, int c);
         std::vector<fullmove> threatDodges(int clr);
         position KingPosition(int clr);
         position EnemyKingPosition(int clr);
         bool issafe(int row, int col, int row2, int col2, int clr);
        
};

#endif
