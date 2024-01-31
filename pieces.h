#ifndef _PIECES_H_
#define _PIECES_H_
#include <string>
#include "piece.h"

class Rook : public Piece {
    public:
        Rook(int r, int c, int clr, Board* b);

        void GenerateMoves() override;
        char getSymbol() override;
        bool CanWin() override;
        virtual ~Rook();
};

class Pawn : public Piece {
    bool moved = false;
    public:
        Pawn(int r, int c, int clr, Board* b);

        void GenerateMoves() override;
        char getSymbol() override;
        bool CanWin() override;
        virtual ~Pawn();
};

class King : public Piece {
    public:
        King(int r, int c, int clr, Board* b);

        void GenerateMoves() override;
        char getSymbol() override;
        bool CanWin() override;
        virtual ~King();
};

class Queen : public Piece {
    public:
        Queen(int r, int c, int clr, Board* b);

        void GenerateMoves() override;
        char getSymbol() override;
        bool CanWin() override;
        virtual ~Queen();
};

class Bishop : public Piece {
    public:
        Bishop(int r, int c, int clr, Board* b);

        void GenerateMoves() override;
        char getSymbol() override;
        bool CanWin() override;
        virtual ~Bishop();
};

class Knight : public Piece {
    public:
        Knight(int r, int c, int clr, Board* b);
        
        void GenerateMoves() override;
        char getSymbol() override;
        bool CanWin() override;
        virtual ~Knight ();
};


#endif
