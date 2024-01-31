#include "computers.h"
#include<iostream>

using namespace std;
Computer1::Computer1(int clr, Board* board) : Player(clr, board) {}

Computer1::~Computer1(){}
Computer2::Computer2(int clr, Board* board) : Player(clr, board) {}

Computer2::~Computer2(){}
Computer3::Computer3(int clr, Board* board) : Player(clr, board) {}

Computer3::~Computer3(){}
Computer4::Computer4(int clr, Board* board) : Player(clr, board) {}

Computer4::~Computer4(){}
void Computer1::Move(){
        bool moving = true;
        vector<position> occupied = board->OccupiedSquares(color);
        while(moving){
        int index = rand() % int(occupied.size());
        int row = occupied[index].row;
        int col = occupied[index].col;
        cout << row << " " << col << endl;
        if(board->isOccupied(row, col)){
            if(board->hasMoves(row, col)){
                vector<position> moves = board->validMoves(row, col);
                
                int index2 = rand() % int(moves.size());
            
                if(board->validateMove(row, col, moves[index2].row, moves[index2].col, color)){
                    board->move(row, col, moves[index2].row, moves[index2].col);
                    if(board->pawnCanUpgrade(color)){
                        char upgrade;
                        if(color == 0) upgrade = 'Q';
                        else upgrade = 'q';
                        board->insertPiece(moves[index2].row, moves[index2].col, upgrade);
                               
                            }
                        moving = false;
                    }
                    
                }
                
            }
                
            }
        }
        




void Computer2::Move(){
    vector<fullmove> checks = board->WinningMoves(color);
    if(!checks.empty()){
        int index = rand() % int(checks.size());
         if(board->validateMove(checks[index].r1, checks[index].c1, checks[index].r2, checks[index].c2, color)){
                    board->move(checks[index].r1, checks[index].c1, checks[index].r2, checks[index].c2);
                    if(board->pawnCanUpgrade(color)){
                        char upgrade;
                        if(color == 0) upgrade = 'Q';
                        else upgrade = 'q';
                        board->insertPiece(checks[index].r2, checks[index].c2, upgrade);
                               
                            }
                return;
            }
    }
    vector<fullmove> kills = board->CaptureMoves(color);
    if(!kills.empty()){
        int index = rand() % int(kills.size());
         if(board->validateMove(kills[index].r1, kills[index].c1, kills[index].r2, kills[index].c2, color)){
                    board->move(kills[index].r1, kills[index].c1, kills[index].r2, kills[index].c2);
                    if(board->pawnCanUpgrade(color)){
                        char upgrade = 'q';
                        if(color == 0) upgrade = 'Q';
                
                        board->insertPiece(kills[index].r2, kills[index].c2, upgrade);
                               
                            }
                return;
            }
    }

     bool moving = true;
        vector<position> occupied = board->OccupiedSquares(color);
        while(moving){
        int index = rand() % int(occupied.size());
        int row = occupied[index].row;
        int col = occupied[index].col;
        if(board->isOccupied(row, col)){
            if(board->hasMoves(row, col)){
                vector<position> moves = board->validMoves(row, col);
                
                int index2 = rand() % int(moves.size());
            
                if(board->validateMove(row, col, moves[index2].row, moves[index2].col, color)){
                    board->move(row, col, moves[index2].row, moves[index2].col);
                    if(board->pawnCanUpgrade(color)){
                        char upgrade = 'q';
                        if(color == 0) upgrade = 'Q';
                        
                        board->insertPiece(moves[index2].row, moves[index2].col, upgrade);
                               
                            }
                moving = false;
            }
                
            }
        }
        }


}


void Computer3::Move(){
    
    vector<fullmove> checks = board->WinningMoves(color);
    if(!checks.empty()){
        int index = rand() % int(checks.size());
         if(board->validateMove(checks[index].r1, checks[index].c1, checks[index].r2, checks[index].c2, color)){
                    board->move(checks[index].r1, checks[index].c1, checks[index].r2, checks[index].c2);
                    if(board->pawnCanUpgrade(color)){
                        char upgrade;
                        if(color == 0) upgrade = 'Q';
                        else upgrade = 'q';
                        board->insertPiece(checks[index].r2, checks[index].c2, upgrade);
                               
                            }
                return;
            }
    }
    vector<fullmove> dodges = board->threatDodges(color);
    if(!dodges.empty()){
        int index = rand() % int(dodges.size());
         if(board->validateMove(dodges[index].r1, dodges[index].c1, dodges[index].r2, dodges[index].c2, color)){
                    board->move(dodges[index].r1, dodges[index].c1, dodges[index].r2, dodges[index].c2);
                    if(board->pawnCanUpgrade(color)){
                        char upgrade;
                        if(color == 0) upgrade = 'Q';
                        else upgrade = 'q';
                        board->insertPiece(dodges[index].r2, dodges[index].c2, upgrade);
                               
                            }
                return;
            }
    }

    vector<fullmove> kills = board->CaptureMoves(color);
    if(!kills.empty()){
        int index = rand() % int(kills.size());
         if(board->validateMove(kills[index].r1, kills[index].c1, kills[index].r2, kills[index].c2, color)){
                    board->move(kills[index].r1, kills[index].c1, kills[index].r2, kills[index].c2);
                    if(board->pawnCanUpgrade(color)){
                        char upgrade;
                        if(color == 0) upgrade = 'Q';
                        else upgrade = 'q';
                        board->insertPiece(kills[index].r2, kills[index].c2, upgrade);
                               
                            }
                return;
            }
    }

     bool moving = true;
        vector<position> occupied = board->OccupiedSquares(color);
        while(moving){
        int index = rand() % int(occupied.size());
        int row = occupied[index].row;
        int col = occupied[index].col;
        if(board->isOccupied(row, col)){
            if(board->hasMoves(row, col)){
                vector<position> moves = board->validMoves(row, col);
                
                int index2 = rand() % int(moves.size());
            
                if(board->validateMove(row, col, moves[index2].row, moves[index2].col, color)){
                    board->move(row, col, moves[index2].row, moves[index2].col);
                    if(board->pawnCanUpgrade(color)){
                        char upgrade;
                        if(color == 0) upgrade = 'Q';
                        else upgrade = 'q';
                        board->insertPiece(moves[index2].row, moves[index2].col, upgrade);
                               
                            }
                moving = false;
            }
                
            }
        }
        }
}



void Computer4::Move(){
        vector<fullmove> kills = board->CaptureMoves(color);
    if(!kills.empty()){
        int index = rand() % int(kills.size());
         if(board->validateMove(kills[index].r1, kills[index].c1, kills[index].r2, kills[index].c2, color) && board->issafe(kills[index].r1, kills[index].c1, kills[index].r2, kills[index].c2, color)){
                    board->move(kills[index].r1, kills[index].c1, kills[index].r2, kills[index].c2);
                    if(board->pawnCanUpgrade(color)){
                        char upgrade;
                        if(color == 0) upgrade = 'Q';
                        else upgrade = 'q';
                        board->insertPiece(kills[index].r2, kills[index].c2, upgrade);
                               
                            }
                return;
            }
    }

        vector<fullmove> checks = board->WinningMoves(color);
    if(!checks.empty()){
        int index = rand() % int(checks.size());
         if(board->validateMove(checks[index].r1, checks[index].c1, checks[index].r2, checks[index].c2, color) && board->issafe(checks[index].r1, checks[index].c1, checks[index].r2, checks[index].c2, color)){
                    board->move(checks[index].r1, checks[index].c1, checks[index].r2, checks[index].c2);
                    if(board->pawnCanUpgrade(color)){
                        char upgrade;
                        if(color == 0) upgrade = 'Q';
                        else upgrade = 'q';
                        board->insertPiece(checks[index].r2, checks[index].c2, upgrade);
                               
                            }
                return;
            }
    }
    vector<fullmove> dodges = board->threatDodges(color);
    if(!dodges.empty()){
        int index = rand() % int(dodges.size());
         if(board->validateMove(dodges[index].r1, dodges[index].c1, dodges[index].r2, dodges[index].c2, color) && board->issafe(dodges[index].r1, dodges[index].c1, dodges[index].r2, dodges[index].c2, color)){
                    board->move(dodges[index].r1, dodges[index].c1, dodges[index].r2, dodges[index].c2);
                    if(board->pawnCanUpgrade(color)){
                        char upgrade;
                        if(color == 0) upgrade = 'Q';
                        else upgrade = 'q';
                        board->insertPiece(dodges[index].r2, dodges[index].c2, upgrade);
                               
                            }
                return;
            }
    }



     bool moving = true;
        vector<position> occupied = board->OccupiedSquares(color);
        while(moving){
        int index = rand() % int(occupied.size());
        int row = occupied[index].row;
        int col = occupied[index].col;
        if(board->isOccupied(row, col)){
            if(board->hasMoves(row, col)){
                vector<position> moves = board->validMoves(row, col);
                
                int index2 = rand() % int(moves.size());
            
                if(board->validateMove(row, col, moves[index2].row, moves[index2].col, color) && board->issafe(row, col, moves[index2].row, moves[index2].col, color)){
                    board->move(row, col, moves[index2].row, moves[index2].col);
                    if(board->pawnCanUpgrade(color)){
                        char upgrade;
                        if(color == 0) upgrade = 'Q';
                        else upgrade = 'q';
                        board->insertPiece(moves[index2].row, moves[index2].col, upgrade);
                               
                            }
                moving = false;
                return;
            }
                
            }
        }
        }

            bool moving2 = true;
        vector<position> occupied2 = board->OccupiedSquares(color);
        while(moving2){
        int index = rand() % int(occupied2.size());
        int row = occupied2[index].row;
        int col = occupied2[index].col;
        if(board->isOccupied(row, col)){
            if(board->hasMoves(row, col)){
                vector<position> moves = board->validMoves(row, col);
                
                int index2 = rand() % int(moves.size());
            
                if(board->validateMove(row, col, moves[index2].row, moves[index2].col, color)){
                    board->move(row, col, moves[index2].row, moves[index2].col);
                    if(board->pawnCanUpgrade(color)){
                        char upgrade;
                        if(color == 0) upgrade = 'Q';
                        else upgrade = 'q';
                        board->insertPiece(moves[index2].row, moves[index2].col, upgrade);
                               
                            }
                moving2 = false;
            }
                
            }
        }
        }
}

