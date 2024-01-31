#include "human.h"
#include<iostream>

using namespace std;

Human::Human(int clr, Board* board) : Player(clr, board) {}

Human::~Human(){}

bool validateInput(string s){
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

position translateInput(string s){

    int col;
    char c = tolower(s[0]);

    col = int(c) - 97;

    return position{(int(s[1]) - 49), col};
}

void Human::Move(){
    string in1;
    string in2;
    string clr;
    if(color == 0)clr = "white";else clr = "black";
    bool getInputs = true;
    cout << "Please input a move for " << clr << ": " << endl;
    while(getInputs){
        cin >> in1;
        if(in1 == "resign"){
            board->resign(color);
            break;
        }
        cin >> in2;
        if(validateInput(in1) && validateInput(in2)){
            position pos1 = translateInput(in1);
            position pos2 = translateInput(in2);
            if(board->validateMove(pos1.row, pos1.col, pos2.row, pos2.col, color)){
                board->move(pos1.row, pos1.col, pos2.row, pos2.col);
                 if(board->pawnCanUpgrade(color)){
                    char upgrade;
                    bool upgrading = true;
                    while(upgrading && cin >> upgrade){
                        upgrade = tolower(upgrade);
                        switch(upgrade) {
                            case 'q':
                                if(color == 0)upgrade = toupper(upgrade);
                                board->insertPiece(pos2.row, pos2.col, upgrade);
                                break;
                            case 'r':
                                if(color == 0)upgrade = toupper(upgrade);
                                board->insertPiece(pos2.row, pos2.col, upgrade);
                                break;
                            case 'b':
                                if(color == 0)upgrade = toupper(upgrade);
                                board->insertPiece(pos2.row, pos2.col, upgrade);
                                break;
                            case 'n':
                                if(color == 0)upgrade = toupper(upgrade);
                                board->insertPiece(pos2.row, pos2.col, upgrade);
                                break;
                            default:
                                cout << "invalid piece for promotion." << endl;
                            }
                        
                    }
                }
                getInputs = false;
            }else{
            cout << "Invalid Move" << endl;
            }
        }else{
            cout << "Invalid Input!" << endl;
        }
    }
}


