   #include "square.h"
   #include <iostream>

using namespace std;
         Square::Square(int row, int col, int clr) : row(row), col(col), color(clr) {}
          Square::Square(int row, int col, int clr, Piece* piece) : piece(piece), row(row), col(col), color(clr) {}
         Square::~Square(){
            clear();
         }
         bool Square::isOccupied(){
            if(piece != nullptr){
                return true;
            }

            return false;
         }
         void Square::occupy(Piece* piece2){

            if(isOccupied()){
               if(piece != piece2)clear();
               
            }
            //if(piece2 != nullptr)piece2->move(row, col);
            piece = piece2;
            if(piece != nullptr)piece->move(row, col);
         }


         void Square::clear(){
            if(piece != nullptr){
               delete piece;
               piece = nullptr;
            }
         }
         void Square::setNull(){
               piece = nullptr;
            
         }
         int Square::getRow(){

            return row;
         }
         int Square::getCol(){

            return col;
         }

         char Square::getSymbol(){
            if(isOccupied()){
               return piece->getSymbol();
            }

            if(color == 0){
               return ' ';
            }

            return '_';
         }

         bool Square::validCapture(int clr){

            if(piece == nullptr){
               return false;
            }

            if((piece->getColor() == 1 && clr == 0) || (piece->getColor() == 0 && clr == 1)){
               return true;
            }
            return false;
         }

         bool Square::validateMove(int r, int c, int clr){

            if(piece == nullptr){
               return false;
            }

            if(piece->getColor() != clr){
               return false;
            }

            return piece->ValidateMove(r, c);

         }

         void Square::move(int r, int c){

            if(piece != nullptr){
               piece->move(r, c);
            }
            

         }

         Piece* Square::getPiece(){
            
            return piece;
         }


