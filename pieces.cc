#include "pieces.h"
#include <iostream>
using namespace std;
Rook::Rook(int r, int c, int clr, Board* b) : Piece(r, c, clr, b) {}

char Rook::getSymbol(){
    if(color == 0){
        return 'R';
    }

    return 'r';

}

void Rook::GenerateMoves(){
    
    for(int i = row + 1; i < 8 ;i ++){
        if(!(board->isOccupied(i, col)) || board->validCapture(i, col, color)){
            legalMoves.push_back(position{i, col});
            if(board->isOccupied(i, col))break;
        }else{
            break;
        }
    }

        for(int i = row - 1; i >= 0 ; i --){
        if(!(board->isOccupied(i, col)) || board->validCapture(i, col, color)){
            legalMoves.push_back(position{i, col});
            if(board->isOccupied(i, col))break;
        }else{
            break;
        }
    }

    for(int i = col + 1; i < 8 ;i ++){
        if(!(board->isOccupied(row, i)) || board->validCapture(row, i, color)){
            legalMoves.push_back(position{row, i});
            if(board->isOccupied(row, i))break;
        }else{
            break;
        }
    }

    for(int i = col - 1; i >= 0 ;i --){
        if(!(board->isOccupied(row, i)) || board->validCapture(row, i, color)){
            legalMoves.push_back(position{row, i});
            if(board->isOccupied(row, i))break;
        }else{
            break;
        }
    }

}


bool Rook::CanWin(){
    position kingpos = board->EnemyKingPosition(color);

    for(int i = row + 1; i < 8 ;i ++){
        if(!(board->isOccupied(i, col)) || board->validCapture(i, col, color)){
            if(kingpos.row == i && kingpos.col == col) return true;
            if(board->isOccupied(i, col))break;
        }else{
            break;
        }
    }

        for(int i = row - 1; i >= 0 ; i --){
        if(!(board->isOccupied(i, col)) || board->validCapture(i, col, color)){
            if(kingpos.row == i && kingpos.col == col) return true;
            if(board->isOccupied(i, col))break;
        }else{
            break;
        }
    }

    for(int i = col + 1; i < 8 ;i ++){
        if(!(board->isOccupied(row, i)) || board->validCapture(row, i, color)){
            if(kingpos.row == row && kingpos.col == i) return true;
            if(board->isOccupied(row, i))break;
        }else{
            break;
        }
    }

    for(int i = col - 1; i >= 0 ;i --){
        if(!(board->isOccupied(row, i)) || board->validCapture(row, i, color)){
            if(kingpos.row == row && kingpos.col == i) return true;
            if(board->isOccupied(row, i))break;
        }else{
            break;
        }
    }
   return false;
}

Rook::~Rook(){}

Pawn::Pawn(int r, int c, int clr, Board* b) : Piece(r, c, clr, b) {}


char Pawn::getSymbol(){
    if(color == 0){
        return 'P';
    }

    return 'p';

}

void Pawn::GenerateMoves(){
    if(color == 0){
        if(!(board->isOccupied(row + 1, col))){
            legalMoves.push_back(position{row + 1, col});
            if(!(board->isOccupied(row + 2, col) && row == 1)){
                legalMoves.push_back(position{row + 2, col});
            }
        }
            
        if((board->validCapture(row + 1, col + 1, color))){
            legalMoves.push_back(position{row + 1, col + 1});
        }

        if((board->validCapture(row + 1, col - 1, color))){
            legalMoves.push_back(position{row + 1, col - 1});
        }

            
    }
    else if(color == 1){

        if(!(board->isOccupied(row - 1, col))){
            legalMoves.push_back(position{row - 1, col});


            if(!(board->isOccupied(row - 2, col) && row == 6)){
                legalMoves.push_back(position{row - 2, col});
            }
        }
            
        if((board->validCapture(row - 1, col + 1, color))){
            legalMoves.push_back(position{row - 1, col + 1});
        }

        if((board->validCapture(row - 1, col - 1, color))){
            legalMoves.push_back(position{row - 1, col - 1});
        }
    }
}

bool Pawn::CanWin(){
    position kingpos = board->EnemyKingPosition(color);

    if(color == 0){
        if((board->validCapture(row + 1, col + 1, color))){
            if(kingpos.row == row + 1 && kingpos.col == col + 1) return true;
        }

        if((board->validCapture(row + 1, col - 1, color))){
            if(kingpos.row == row + 1 && kingpos.col == col - 1) return true;
        }

            
    }else if(color == 1){
        if((board->validCapture(row - 1, col + 1, color))){
            if(kingpos.row == row - 1 && kingpos.col == col + 1) return true;
        }

        if((board->validCapture(row - 1, col - 1, color))){
            if(kingpos.row == row - 1 && kingpos.col == col - 1) return true;
        }
    }

    return false;
}

Pawn::~Pawn(){}

Bishop::Bishop(int r, int c, int clr, Board* b) : Piece(r, c, clr, b) {}


char Bishop::getSymbol(){
    if(color == 0){
        return 'B';
    }

    return 'b';

}

void Bishop::GenerateMoves(){

    for(position i = {row + 1, col + 1}; i.col < 8 && i.row < 8; i.row++ , i.col++){
        if(!(board->isOccupied(i.row, i.col)) || board->validCapture(i.row, i.col, color)){
            legalMoves.push_back(position{i.row, i.col});
            if(board->isOccupied(i.row, i.col))break;
        }else{
            break;
        }
    }

    for(position i = {row - 1, col + 1}; i.col < 8 && i.row >= 0; i.row-- , i.col++){
        if(!(board->isOccupied(i.row, i.col)) || board->validCapture(i.row, i.col, color)){
            legalMoves.push_back(position{i.row, i.col});
            if(board->isOccupied(i.row, i.col))break;
        }else{
            break;
        }
    }

        for(position i = {row + 1, col - 1}; i.col >= 0 && i.row < 8; i.row++ , i.col--){
        if(!(board->isOccupied(i.row, i.col)) || board->validCapture(i.row, i.col, color)){
            legalMoves.push_back(position{i.row, i.col});
            if(board->isOccupied(i.row, i.col))break;
        }else{
            break;
        }
    }

        for(position i = {row - 1, col - 1}; i.col >= 0 && i.row >= 0; i.row-- , i.col--){
        if(!(board->isOccupied(i.row, i.col)) || board->validCapture(i.row, i.col, color)){
            legalMoves.push_back(position{i.row, i.col});
            if(board->isOccupied(i.row, i.col))break;
        }else{
            break;
        }
    }
}

bool Bishop::CanWin(){
     position kingpos = board->EnemyKingPosition(color);

    for(position i = {row + 1, col + 1}; i.col < 8 && i.row < 8; i.row++ , i.col++){
        if(!(board->isOccupied(i.row, i.col)) || board->validCapture(i.row, i.col, color)){
            if(kingpos.row == i.row && kingpos.col == i.col) return true;
            if(board->isOccupied(i.row, i.col))break;
        }else{
            break;
        }
    }

    for(position i = {row - 1, col + 1}; i.col < 8 && i.row >= 0; i.row-- , i.col++){
        if(!(board->isOccupied(i.row, i.col)) || board->validCapture(i.row, i.col, color)){
            if(kingpos.row == i.row && kingpos.col == i.col) return true;
            if(board->isOccupied(i.row, i.col))break;
        }else{
            break;
        }
    }

        for(position i = {row + 1, col - 1}; i.col >= 0 && i.row < 8; i.row++ , i.col--){
        if(!(board->isOccupied(i.row, i.col)) || board->validCapture(i.row, i.col, color)){
            if(kingpos.row == i.row && kingpos.col == i.col) return true;
            if(board->isOccupied(i.row, i.col))break;
        }else{
            break;
        }
    }

        for(position i = {row - 1, col - 1}; i.col >= 0 && i.row >= 0; i.row-- , i.col--){
        if(!(board->isOccupied(i.row, i.col)) || board->validCapture(i.row, i.col, color)){
            if(kingpos.row == i.row && kingpos.col == i.col) return true;
            if(board->isOccupied(i.row, i.col))break;
        }else{
            break;
        }
    }
    return false;
}

Bishop::~Bishop(){}

King::King(int r, int c, int clr, Board* b) : Piece(r, c, clr, b) {}


char King::getSymbol(){
    if(color == 0){
        return 'K';
    }

    return 'k';

}

void King::GenerateMoves(){
    if((!(board->isOccupied(row, col + 1)) || board->validCapture(row, col + 1, color)) && col + 1 < 8){
            legalMoves.push_back(position{row, col + 1});
    }

    if((!(board->isOccupied(row + 1, col + 1)) || board->validCapture(row + 1, col + 1, color)) && col + 1 < 8 && row + 1 < 8){
            legalMoves.push_back(position{row + 1, col + 1});
    }

    if((!(board->isOccupied(row - 1, col - 1)) || board->validCapture(row - 1, col - 1, color)) && col - 1 >= 0 && row - 1 >= 0){
            legalMoves.push_back(position{row - 1, col - 1});
    }

    if((!(board->isOccupied(row + 1, col - 1)) || board->validCapture(row + 1, col - 1, color)) && col - 1 >= 0 && row + 1 < 8){
            legalMoves.push_back(position{row + 1, col - 1});
    }

    if((!(board->isOccupied(row - 1, col + 1)) || board->validCapture(row - 1, col + 1, color)) && col + 1 < 8 && row - 1 >= 0){
            legalMoves.push_back(position{row - 1, col + 1});
    }

    if((!(board->isOccupied(row + 1, col)) || board->validCapture(row + 1, col, color)) && row + 1 < 8){
            legalMoves.push_back(position{row + 1, col});
    }

    if((!(board->isOccupied(row - 1, col)) || board->validCapture(row - 1, col, color)) && row - 1 >= 0){
            legalMoves.push_back(position{row - 1, col});
    }

    if((!(board->isOccupied(row, col - 1)) || board->validCapture(row, col - 1, color)) && col - 1 >= 0){
            legalMoves.push_back(position{row, col - 1});
    }
    
}

bool King::CanWin(){
    position kingpos = board->EnemyKingPosition(color);
    if((!(board->isOccupied(row, col + 1)) || board->validCapture(row, col + 1, color)) && col + 1 < 8){
            if(kingpos.row == row && kingpos.col == col + 1) return true;
    }

    if((!(board->isOccupied(row + 1, col + 1)) || board->validCapture(row + 1, col + 1, color)) && col + 1 < 8 && row + 1 < 8){
            if(kingpos.row == row + 1 && kingpos.col == col + 1) return true;
    }

    if((!(board->isOccupied(row - 1, col - 1)) || board->validCapture(row - 1, col - 1, color)) && col - 1 >= 0 && row - 1 >= 0){
            if(kingpos.row == row - 1 && kingpos.col == col - 1) return true;
    }

    if((!(board->isOccupied(row + 1, col - 1)) || board->validCapture(row + 1, col - 1, color)) && col - 1 >= 0 && row + 1 < 8){
            if(kingpos.row == row + 1 && kingpos.col == col - 1) return true;
    }

    if((!(board->isOccupied(row - 1, col + 1)) || board->validCapture(row - 1, col + 1, color)) && col + 1 < 8 && row - 1 >= 0){
           if(kingpos.row == row - 1&& kingpos.col == col + 1) return true;
    }

    if((!(board->isOccupied(row + 1, col)) || board->validCapture(row + 1, col, color)) && row + 1 < 8){
            if(kingpos.row == row + 1 && kingpos.col == col) return true;
    }

    if((!(board->isOccupied(row - 1, col)) || board->validCapture(row - 1, col, color)) && row - 1 >= 0){
            if(kingpos.row == row - 1 && kingpos.col == col) return true;
    }

    if((!(board->isOccupied(row, col - 1)) || board->validCapture(row, col - 1, color)) && col - 1 >= 0){
            if(kingpos.row == row && kingpos.col == col - 1) return true;
    }

    return false;
    
}

King::~King(){}


Queen::Queen(int r, int c, int clr, Board* b) : Piece(r, c, clr, b) {}

char Queen::getSymbol(){
    if(color == 0){
        return 'Q';
    }

    return 'q';

}

void Queen::GenerateMoves(){

    for(position i = {row + 1, col + 1}; i.col < 8 && i.row < 8; i.row++ , i.col++){
        if(!(board->isOccupied(i.row, i.col)) || board->validCapture(i.row, i.col, color)){
            legalMoves.push_back(position{i.row, i.col});
            if(board->isOccupied(i.row, i.col))break;
        }else{
            break;
        }
    }

    for(position i = {row - 1, col + 1}; i.col < 8 && i.row >= 0; i.row-- , i.col++){
        if(!(board->isOccupied(i.row, i.col)) || board->validCapture(i.row, i.col, color)){

            legalMoves.push_back(position{i.row, i.col});
            if(board->isOccupied(i.row, i.col))break;
        }else{
            
            break;
        }
    }

        for(position i = {row + 1, col - 1}; i.col >= 0 && i.row < 8; i.row++ , i.col--){
        if(!(board->isOccupied(i.row, i.col)) || board->validCapture(i.row, i.col, color)){
            legalMoves.push_back(position{i.row, i.col});
            if(board->isOccupied(i.row, i.col))break;
        }else{
            break;
        }
    }

        for(position i = {row - 1, col - 1}; i.col >= 0 && i.row >= 0; i.row-- , i.col--){
        if(!(board->isOccupied(i.row, i.col)) || board->validCapture(i.row, i.col, color)){
            legalMoves.push_back(position{i.row, i.col});
            if(board->isOccupied(i.row, i.col))break;
        }else{
            break;
        }
    }

    for(int i = row + 1; i < 8 ;i ++){
        if(!(board->isOccupied(i, col)) || board->validCapture(i, col, color)){
            legalMoves.push_back(position{i, col});
            if(board->isOccupied(i, col))break;
        }else{
            break;
        }
    }

        for(int i = row - 1; i >= 0 ; i --){
        if(!(board->isOccupied(i, col)) || board->validCapture(i, col, color)){
            legalMoves.push_back(position{i, col});
            if(board->isOccupied(i, col))break;
        }else{
            break;
        }
    }

    for(int i = col + 1; i < 8 ;i ++){
        if(!(board->isOccupied(row, i)) || board->validCapture(row, i, color)){
            legalMoves.push_back(position{row, i});
            if(board->isOccupied(row, i))break;
        }else{
            break;
        }
    }

    for(int i = col - 1; i >= 0 ;i --){
        if(!(board->isOccupied(row, i)) || board->validCapture(row, i, color)){
            legalMoves.push_back(position{row, i});
            if(board->isOccupied(row, i))break;
        }else{
            break;
        }
    }
}

bool Queen::CanWin(){
        position kingpos = board->EnemyKingPosition(color);

    for(position i = {row + 1, col + 1}; i.col < 8 && i.row < 8; i.row++ , i.col++){
        if(!(board->isOccupied(i.row, i.col)) || board->validCapture(i.row, i.col, color)){
            if(kingpos.row == i.row && kingpos.col == i.col) return true;
            if(board->isOccupied(i.row, i.col))break;
        }else{
            break;
        }
    }

    for(position i = {row - 1, col + 1}; i.col < 8 && i.row >= 0; i.row-- , i.col++){
        if(!(board->isOccupied(i.row, i.col)) || board->validCapture(i.row, i.col, color)){
            if(kingpos.row == i.row && kingpos.col == i.col) return true;
            if(board->isOccupied(i.row, i.col))break;
            
        }else{
            break;
        }
    }

        for(position i = {row + 1, col - 1}; i.col >= 0 && i.row < 8; i.row++ , i.col--){
        if(!(board->isOccupied(i.row, i.col)) || board->validCapture(i.row, i.col, color)){
            if(kingpos.row == i.row && kingpos.col == i.col) return true;
            if(board->isOccupied(i.row, i.col))break;
        }else{
            break;
        }
    }

        for(position i = {row - 1, col - 1}; i.col >= 0 && i.row >= 0; i.row-- , i.col--){
        if(!(board->isOccupied(i.row, i.col)) || board->validCapture(i.row, i.col, color)){
            if(kingpos.row == i.row && kingpos.col == i.col) return true;
            if(board->isOccupied(i.row, i.col))break;
        }else{
            break;
        }
    }

    for(int i = row + 1; i < 8 ;i ++){
        if(!(board->isOccupied(i, col)) || board->validCapture(i, col, color)){
            if(kingpos.row == i && kingpos.col == col) return true;
            if(board->isOccupied(i, col))break;
        }else{
            break;
        }
    }

        for(int i = row - 1; i >= 0 ; i --){
        if(!(board->isOccupied(i, col)) || board->validCapture(i, col, color)){
            if(kingpos.row == i && kingpos.col == col) return true;
            if(board->isOccupied(i, col))break;
        }else{
            break;
        }
    }

    for(int i = col + 1; i < 8 ;i ++){
        if(!(board->isOccupied(row, i)) || board->validCapture(row, i, color)){
            if(kingpos.row == row && kingpos.col == i) return true;
            if(board->isOccupied(row, i))break;
        }else{
            break;
        }
    }

    for(int i = col - 1; i >= 0 ;i --){
        if(!(board->isOccupied(row, i)) || board->validCapture(row, i, color)){
            if(kingpos.row == row && kingpos.col == i) return true;
            if(board->isOccupied(row, i))break;
        }else{
            break;
        }
    }

    return false;
}

Queen::~Queen(){}

Knight::Knight(int r, int c, int clr, Board* b) : Piece(r, c, clr, b) {}

char Knight::getSymbol(){
    if(color == 0){
        return 'N';
    }

    return 'n';

}

void Knight::GenerateMoves(){

    if((!(board->isOccupied(row + 1, col + 2)) || board->validCapture(row + 1, col + 2, color)) && col + 2 < 8 && row + 1 > 8){
            legalMoves.push_back(position{row + 1, col + 2});
    }

    if((!(board->isOccupied(row + 2, col + 1)) || board->validCapture(row + 2, col + 1, color)) && col + 1 < 8 && row + 2 < 8){
            legalMoves.push_back(position{row + 2, col + 1});
    }

    if((!(board->isOccupied(row - 1, col - 2)) || board->validCapture(row - 1, col - 2, color)) && col - 2 >= 0 && row - 1 >= 0){
            legalMoves.push_back(position{row - 1, col - 2});
    }

    if((!(board->isOccupied(row - 2, col - 1)) || board->validCapture(row - 2, col - 1, color)) && col - 1 >= 0 && row - 2 >= 0){
            legalMoves.push_back(position{row - 2, col - 1});
    }

    if((!(board->isOccupied(row - 1, col + 2)) || board->validCapture(row - 1, col + 2, color)) && col + 2 < 8 && row - 1 >= 0){
            legalMoves.push_back(position{row - 1, col + 2});
    }

    if((!(board->isOccupied(row - 2, col + 1)) || board->validCapture(row - 2, col + 1, color)) && col + 1 < 8 && row - 2 >= 0){
            legalMoves.push_back(position{row - 2, col + 1});
    }

     if((!(board->isOccupied(row + 1, col - 2)) || board->validCapture(row + 1, col - 2, color)) && col - 2 >= 0 && row + 1 < 8){
            legalMoves.push_back(position{row + 1, col - 2});
    }


     if((!(board->isOccupied(row + 2, col - 1)) || board->validCapture(row + 2, col - 1, color)) && col - 1 >= 0 && row + 2 < 8){
            legalMoves.push_back(position{row + 2, col - 1});
    }
    
}

bool Knight::CanWin(){

    position kingpos = board->EnemyKingPosition(color);


    if((!(board->isOccupied(row + 1, col + 2)) || board->validCapture(row + 1, col + 2, color)) && col + 2 < 8 && row + 1 > 8){
            if(kingpos.row == row + 1 && kingpos.col == col + 2) return true;
    }

    if((!(board->isOccupied(row + 2, col + 1)) || board->validCapture(row + 2, col + 1, color)) && col + 1 < 8 && row + 2 < 8){
            if(kingpos.row == row + 2 && kingpos.col == col + 1) return true;
    }

    if((!(board->isOccupied(row - 1, col - 2)) || board->validCapture(row - 1, col - 2, color)) && col - 2 >= 0 && row - 1 >= 0){
            if(kingpos.row == row - 1 && kingpos.col == col - 2) return true;
    }

    if((!(board->isOccupied(row - 2, col - 1)) || board->validCapture(row - 2, col - 1, color)) && col - 1 >= 0 && row - 2 >= 0){
            if(kingpos.row == row - 2 && kingpos.col == col - 1) return true;
    }

    if((!(board->isOccupied(row - 1, col + 2)) || board->validCapture(row - 1, col + 2, color)) && col + 2 < 8 && row - 1 >= 0){
            if(kingpos.row == row - 1 && kingpos.col == col + 2) return true;
    }

    if((!(board->isOccupied(row - 2, col + 1)) || board->validCapture(row - 2, col + 1, color)) && col + 1 < 8 && row - 2 >= 0){
            if(kingpos.row == row - 2 && kingpos.col == col + 1) return true;
    }

     if((!(board->isOccupied(row + 1, col - 2)) || board->validCapture(row + 1, col - 2, color)) && col - 2 >= 0 && row + 1 < 8){
            if(kingpos.row == row + 1 && kingpos.col == col - 2) return true;
    }


     if((!(board->isOccupied(row + 2, col - 1)) || board->validCapture(row + 2, col - 1, color)) && col - 1 >= 0 && row + 2 < 8){
            if(kingpos.row == row + 2 && kingpos.col == col - 1) return true;
    }

    return false;
    
}

Knight::~Knight(){}


