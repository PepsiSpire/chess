#include <iostream>
#include "game.h"
#include "window.h"
#include "graphicsdisplay.h"


using namespace std;

bool validateInput2(string s){
    if(s.length() != 2) {
        return false;
    }
    char c = tolower(s[0]);
    int num = int(s[1]) - 48;
    if(c >= 'a' && c <= 'h' ){
        if(num >= 1 && num <= 8){
            return true;
        }
    }
    
    return false;

}

position translateInput2(string s){

    int col;
    char c = tolower(s[0]);

    col = int(c) - 97;

    return position{(int(s[1]) - 49), col};
}

int main(){
    Xwindow window;
    Game game = Game(window);

    string command;

    while(cin >> command){
        if(command == "game"){
            string player1;
            string player2;
            int cmd1 = 0;
            int cmd2 = 0;

            
            
            while(cin >> player1){
            if(player1 == "human"){
                cmd1 = 0;
                break;
            }else if(player1 == "computer1"){
                cmd1 = 1;
                break;
            }else if(player1 == "computer2"){
                cmd1 = 2;
                break;
            }else if(player1 == "computer3"){
                cmd1 = 3;
                break;
            }else if(player1 == "computer4"){
                cmd1 = 4;
                break;
            }else{
                cout << "Invalid PLayer Type" << endl;
            }
            }
            
        while(cin >> player2){

            if(player2 == "human"){
                cmd2 = 0;
                break;
            } else if(player2 == "computer1"){
                cmd2 = 1;
                break;
            }else if(player2 == "computer2"){
                cmd2 = 2;
                break;
            }else if(player2 == "computer3"){
                cmd2 = 3;
                break;
            }else if(player2 == "computer4"){
                cmd2 = 4;
                break;
            }else{
                cout << "Invalid PLayer Type" << endl;
            }
        }

            game.newGame(cmd1, cmd2);

            while(game.running()){
                game.nextTurn();
            }
        }
        else if(command == "setup"){
            string cmd;
            while(cin >> cmd){
                if(cmd == "+"){
                    char piece;
                    string pos;
                    cin >> piece;
                    cin >> pos;
                    if(validateInput2(pos)){
                        position pos1 = translateInput2(pos);
                        game.insertPiece(pos1, piece);
                        game.printBoard();
                    }else{
            cout << "Invalid Input!" << endl;
        }

                }else if(cmd == "-"){
                    string pos;
                    cin >> pos;
                    if(validateInput2(pos)){
                        position pos1 = translateInput2(pos);
                        game.deletePiece(pos1);
                        game.printBoard();
                    }else{
            cout << "Invalid Input!" << endl;
        }
                }else if(cmd == "="){
                    string turn;
                    cin >> turn;
                    if(turn == "white"){
                        game.setNext(0);
                        cout << "White has next move." << endl;
                    }else if(turn == "black"){
                        game.setNext(1);
                        cout << "Black has next move." << endl;
                    }else{
                        cout << "Invalid turn!!! Input 'black' or 'white'!" << endl;
                    }
                
                }else if(cmd == "done"){
                    if(game.validateBoard()){
                        cout << "setup mode exited." << endl;
                        break;
                    }else{
                        cout << "Board state invalid: cannot exit setup mode!" << endl;
                    }
                }
}
        }
        }
        cout << "Final Score:" << endl;
        cout << "White: " << game.score(0) << endl;
        cout << "Black: " << game.score(1) << endl;
        //delete game;
    }



