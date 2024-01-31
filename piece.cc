#include "piece.h"
#include <iostream>
using namespace std;

Piece::Piece(int r, int c, int clr, Board* b) : row(r), col(c), color(clr), board(b) {}

string Piece::getColorString(){
    if(color == 0){
        return "White";
    }else if(color == 1){
        return "Black";
    }else{
        return "Undefined";
    }
}
void Piece::move(int r, int c){
    row = r;
    col = c;
}

bool Piece::ValidateMove(int r, int c){
    for(position i : legalMoves){
        if(i.row == r && i.col == c){
            return true;
        }
    }
   return false;

}

int Piece::getColor(){
    return color;
}


void Piece::GenerateLegalMoves(){
    legalMoves.clear();
    GenerateMoves();

    for(int i = 0; i < int(legalMoves.size()) ; i++){

        if(!(board->isLegal(row, col, legalMoves.at(i).row, legalMoves.at(i).col, color))){
            
            legalMoves.erase(legalMoves.begin()+i);
            i--;
        }
       
    }
    
}

bool Piece::hasMoves(){
    if(legalMoves.empty()){
        return false;
    }

    
    return true;
}

void Piece::GenerateMoves(){}

bool Piece::CanWin(){
    return false;
}
char Piece::getSymbol(){
    return 'x';
}
  int Piece::GetRow(){
    return row;
  }
        int Piece::GetCol(){
            return col;
        }

       vector<position> Piece::getMoves(){
        return legalMoves;
       }

Piece::~Piece(){}
