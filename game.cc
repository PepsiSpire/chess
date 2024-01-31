#include "game.h"
#include "human.h"
#include "computers.h"
#include <iostream>
using namespace std;



        Game::Game(Xwindow &w): board(new Board(w)){}

         Game::~Game(){
            if(white != nullptr){
                delete white;
            }

            if(black != nullptr){
                delete black;
            }
            if(board != nullptr){
                delete board;
            }
         }

         void Game::newGame(int whiteType, int blackType){
            if(board->isEmpty()){
                nextColor = 0;
                board->setup();
            }
            board->resign(-1);

            board->GenerateMoves(0);
            board->GenerateMoves(1);
            started = true;
            if(white != nullptr) delete white;
            if(black != nullptr) delete black;
            white = nullptr;
            black = nullptr;
            switch(whiteType){
                case 0:
                    white = new Human(0, board);
                    break;
                case 1:
                    white = new Computer1(0, board);
                    break;
                case 2:
                    white = new Computer2(0, board);
                    break;
                case 3:
                    white = new Computer3(0, board);
                    break;
                case 4:
                    white = new Computer4(0, board);
                    break;
                default:
                started = false;
                break;
            }

            switch(blackType){
                case 0:
                    black = new Human(1, board);
                    break;
                case 1:
                    black = new Computer1(1, board);
                    break;
                case 2:
                    black = new Computer2(1, board);
                    break;
                case 3:
                    black = new Computer3(1, board);
                    break;
                case 4:
                    black = new Computer4(1, board);
                    break;
                default:
                started = false;
                break;
            }

            board->print();

            
         }
         void Game::nextTurn(){
            if(!started){
                cout << "No game is initialized." << endl;
                return;
            }

            if(nextColor == 0){
                if(!board->hasMoves(0)){
                    if(!board->CanWin(0)){
                        cout << "stalemate." << endl;
                        started = false;
                        return;
                    }else{
                        cout << "White is in checkmate. Black wins." << endl;
                        board->clear();
                        started = false;
                        blackWins ++;
                        return;
                    }
                }
                cout << "Whites Turn." << endl;
                string movecmd;
                while(cin >> movecmd){
                    if(movecmd == "move"){
                        break;
                    }else if(movecmd == "resign"){
                        cout << "White surrenders. Black wins." << endl;
                        board->clear();
                        started = false;
                        blackWins ++;
                        return;
                    }
                }
                white->Move();
                if(board->resigned() == 0){
                    cout << "White surrenders. Black wins." << endl;
                        board->clear();
                        started = false;
                        blackWins ++;
                        return;
                }
               
                board->print();
                
                black->GenerateMoves();
                if(board->CanWin(0)){
                    if(board->hasMoves(1)){
                        cout << "Black is in check." << endl;
                    }else{
                        cout << "Black is in checkmate. White wins." << endl;
                        board->clear();
                        started = false;
                        whiteWins ++;
                        return;
                    }
                    
                }
                nextColor = 1;
            }else if(nextColor == 1){
                if(!board->hasMoves(1)){
                    if(!board->CanWin(0)){
                        cout << "stalemate." << endl;
                        started = false;
                        return;
                    }else{
                        cout << "Black is in checkmate. White wins." << endl;
                        board->clear();
                        started = false;
                        whiteWins ++;
                        return;
                    }
                }
                cout << "Blacks Turn." << endl;
                string movecmd;
                while(cin >> movecmd){
                    if(movecmd == "move"){
                        break;
                    }else if(movecmd == "resign"){
                        cout << "Black surrenders. White wins." << endl;
                        board->clear();
                        started = false;
                        whiteWins ++;
                        return;
                    }
                }
                black->Move();
                if(board->resigned() == 1){
                    cout << "Black surrenders. White wins." << endl;
                        board->clear();
                        started = false;
                        whiteWins ++;
                        return;
                }
                board->print();
                white->GenerateMoves();
                if(board->CanWin(1)){
                    if(board->hasMoves(0)){
                        cout << "White is in check." << endl;
                    }else{
                        cout << "White is in checkmate. Black wins." << endl;
                        board->clear();
                        started = false;
                        blackWins ++;
                        return;
                    }
                    
                }
                nextColor = 0;
            }


         }

         bool Game::running(){
            return started;
         }
        void Game::insertPiece(position p, char c){
            board->insertPiece(p.row, p.col, c);
        }

                 void Game::deletePiece(position p){
                    board->deletePiece(p.row, p.col);
                 }
         void Game::printBoard(){
            board->print();
         }
         void Game::setNext(int clr){
            nextColor = clr;
         }

         bool Game::validateBoard(){
            if(board->kingcount(0) != 1 || board->kingcount(1) != 1){
                return false;
            }

            if(board->pawnCanUpgrade(0) || board->pawnCanUpgrade(1)){
                return false;
            }

            if(board->CanWin(0) || board->CanWin(1)){
                return false;
            }

            return true;
         }

        int Game::score(int clr){
            if(clr == 0){
                return whiteWins;
            }else{
                return blackWins;
            }
        }
