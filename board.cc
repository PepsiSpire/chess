
#include <iostream>
#include "board.h"
#include "pieces.h"
using namespace std;

Board::Board(Xwindow &w) : gd(new GraphicsDisplay(w)) {
    td = new TextDisplay(); 
    int clr = 0;
    for (int i = 0; i < 8; ++i)
    {   
        vector<Square> tempVec;
        for (int j = 0; j < 8; ++j)
        {   
            Square tempSquare = Square(i, j, clr);
            tempVec.push_back(tempSquare);
            if(clr != 0){
                if(j != 7)clr = 0;
            }else{
                if(j != 7)clr = 1;
            }
            
        }
        theBoard.push_back(tempVec);
    }
}

Board::~Board(){
    if(td != nullptr){
        delete td;
    }
}
void Board::setup(){
    clear();

    // Setup white pieces
    for(int i = 0; i < 8; i++){
        theBoard[1][i].occupy(new Pawn(1, i, 0, this));
        td->update(theBoard[1][i]);
        gd->update(theBoard[1][i]);
    }

        theBoard[0][0].occupy(new Rook(0, 0, 0, this));

        
        theBoard[0][7].occupy(new Rook(0, 7, 0, this));


        theBoard[0][1].occupy(new Knight(0, 1, 0, this));


        theBoard[0][6].occupy(new Knight(0, 6, 0, this));


        theBoard[0][2].occupy(new Bishop(0, 2, 0, this));
    

        theBoard[0][5].occupy(new Bishop(0, 5, 0, this));


        theBoard[0][3].occupy(new Queen(0, 3, 0, this));


        theBoard[0][4].occupy(new King(0, 4, 0, this));

        for(int i = 0; i < 8; i++){
            td->update(theBoard[0][i]);
            gd->update(theBoard[0][i]);
        }

    // Setup black pieces
    for(int i = 0;i < 8; i++){
        theBoard[6][i].occupy(new Pawn(6, i, 1, this));
        td->update(theBoard[6][i]);
        gd->update(theBoard[6][i]);
    }

        theBoard[7][0].occupy(new Rook(7, 0, 1, this));


        theBoard[7][7].occupy(new Rook(7, 7, 1, this));


        theBoard[7][1].occupy(new Knight(7, 1, 1, this));


        theBoard[7][6].occupy(new Knight(7, 6, 1, this));


        theBoard[7][2].occupy(new Bishop(7, 2, 1, this));


        theBoard[7][5].occupy(new Bishop(7, 5, 1, this));


        theBoard[7][3].occupy(new Queen(7, 3, 1, this));


        theBoard[7][4].occupy(new King(7, 4, 1, this));

        for(int i = 0; i < 8; i++){
            td->update(theBoard[7][i]);
            gd->update(theBoard[7][i]);
        }

        
        
}

void Board::addPiece(Piece* p, int r, int c){

    if(0 <= r && r < 8 && 0 <= c && c < 8){
        theBoard[r][c].occupy(p);
        td->update(theBoard[r][c]);
        gd->update(theBoard[r][c]);
    }else{
        cout << "Position out of range." << endl;

    } 
}

void Board::clear(){
    for (int i = 0; i < 8; ++i)
    {   
        for (int j = 0; j < 8; ++j)
        {   
           if(theBoard[i][j].isOccupied()){

            theBoard[i][j].clear();
            td->update(theBoard[i][j]);
            gd->update(theBoard[i][j]);
            
        
           }
            
        }
        
    }
}

void Board::deletePiece(int r, int c){
    theBoard[r][c].clear();
    td->update(theBoard[r][c]);
    gd->update(theBoard[r][c]);
}

bool Board::isOccupied(int r, int c){
    if( r < 0 || c < 0 || r > 7 || c > 7){
        return false;
    }
    return theBoard[r][c].isOccupied();
}

bool Board::isEmpty(){

     for (int i = 0; i < 8; ++i)
    {   
        for (int j = 0; j < 8; ++j)
        {   
           if(theBoard[i][j].isOccupied()){

            return false;
            
        
           }
            
        }
        
    }
    return true;
}

void Board::print(){
    td->print();
    gd->output();
    
}

bool Board::validCapture(int r, int c, int clr){
    if( r < 0 || c < 0 || r > 7 || c > 7){
        return false;
    }
    return theBoard[r][c].validCapture(clr);

}

bool Board::validateMove(int r, int c, int r2, int c2, int clr){
    return theBoard[r][c].validateMove(r2, c2, clr);
}

void Board::move(int r, int c, int r2, int c2){

    if(theBoard[r][c].isOccupied()){
            //theBoard[r][c].move(r2, c2);
            Piece* movingPiece = theBoard[r][c].getPiece();
            if(movingPiece != nullptr){
                theBoard[r2][c2].occupy(movingPiece);
                
                theBoard[r][c].setNull();
            }
    
            td->update(theBoard[r2][c2]);
            
             gd->update(theBoard[r2][c2]);
             td->update(theBoard[r][c]);
            gd->update(theBoard[r][c]);

    }
   

}

void Board::GenerateMoves(int clr){

    for (int i = 0; i < 8; ++i)
    {   
        for (int j = 0; j < 8; ++j)
        {   
           if(theBoard[i][j].isOccupied()){
            Piece* temp = theBoard[i][j].getPiece();
            if(temp != nullptr){
                if(temp->getColor() == clr){
                temp->GenerateLegalMoves();    
            }
            }
            
        
           }
            
        }
        
    }

}

position Board::KingPosition(int clr){

    for (int i = 0; i < 8; ++i)
    {   
        for (int j = 0; j < 8; ++j)
        {   
           if(theBoard[i][j].isOccupied()){
            Piece* temp = theBoard[i][j].getPiece();
            if(temp != nullptr){
                if(temp->getSymbol() == 'K' && clr == 0){
                return position{i, j};
            }
            if(temp->getSymbol() == 'k' && clr == 1){
                return position{i, j};
            }
            }
            
        
           }
            
        }
        
    }
    return position{-1, -1};

}

position Board::EnemyKingPosition(int clr){

    for (int i = 0; i < 8; ++i)
    {   
        for (int j = 0; j < 8; ++j)
        {   
           if(theBoard[i][j].isOccupied()){
            Piece* temp = theBoard[i][j].getPiece();
            if(temp != nullptr){
                if(temp->getSymbol() == 'K' && clr == 1){
                return position{i, j};
            }
            if(temp->getSymbol() == 'k' && clr == 0){
                return position{i, j};
            }
            }
            
        
           }
            
        }
        
    }
    return position{-1, -1};

}
bool Board::CanWin(int clr){
     for (int i = 0; i < 8; ++i)
        {   
        for (int j = 0; j < 8; ++j)
        {   
           if(theBoard[i][j].isOccupied()){
            Piece* temp = theBoard[i][j].getPiece();

            if(temp != nullptr && temp->getColor() == clr){
            if(temp->CanWin()){
                return true;
            }

            }
            
        
           }
            
        }
        
    }
    return false;;

}
void Board::insertPiece(int r, int c, char p){
    switch(p) {
  case 'r':
    theBoard[r][c].occupy(new Rook(r, c, 1, this));
    
    break;
  case 'R':
    theBoard[r][c].occupy(new Rook(r, c, 0, this));
    break;
      case 'k':
     theBoard[r][c].occupy(new King(r, c, 1, this));
    break;
  case 'K':
    theBoard[r][c].occupy(new King(r, c, 0, this));
    break;
      case 'q':
    theBoard[r][c].occupy(new Queen(r, c, 1, this));
    break;
  case 'Q':
     theBoard[r][c].occupy(new Queen(r, c, 0, this));
    break;
      case 'b':
    theBoard[r][c].occupy(new Bishop(r, c, 1, this));
    break;
  case 'B':
    theBoard[r][c].occupy(new Bishop(r, c, 0, this));
    break;
      case 'p':
    theBoard[r][c].occupy(new Pawn(r, c, 1, this));
    break;
  case 'P':
    theBoard[r][c].occupy(new Pawn(r, c, 0, this));
    break;
      case 'n':
    theBoard[r][c].occupy(new Knight(r, c, 1, this));
    break;
  case 'N':
    theBoard[r][c].occupy(new Knight(r, c, 0, this));
    break;
  default:
    cout << "bad input" << endl;
    break;
}
            td->update(theBoard[r][c]);
            gd->update(theBoard[r][c]);
}

bool Board::isLegal(int r1, int c1, int r2, int c2, int clr){
    int opcolor;
    if(clr == 0) opcolor = 1;
    if(clr == 1) opcolor = 0;

    char piece = 'L';

    if(theBoard[r2][c2].isOccupied()){
        Piece* tempPiece = theBoard[r2][c2].getPiece();
        if(tempPiece != nullptr){
            piece = tempPiece->getSymbol();
        }
        
    }

    move(r1, c1, r2, c2);
    
    if(CanWin(opcolor)){
        move(r2, c2, r1, c1);
        if(piece != 'L'){
            insertPiece(r2, c2, piece);
        }
        return false;
    }
    
    move(r2, c2, r1, c1);
    if(piece != 'L'){
            insertPiece(r2, c2, piece);
        }
    return true;

}
bool Board::createsCheck(int r1, int c1, int r2, int c2, int clr){
    
    char piece = 'L';

    if(theBoard[r2][c2].isOccupied()){
        Piece* tempPiece = theBoard[r2][c2].getPiece();
        if(tempPiece != nullptr){
            piece = tempPiece->getSymbol();
        }
        
    }

    move(r1, c1, r2, c2);
    
    if(CanWin(clr)){
        move(r2, c2, r1, c1);
        if(piece != 'L'){
            insertPiece(r2, c2, piece);
        }
        return true;
    }
    
    move(r2, c2, r1, c1);
    if(piece != 'L'){
            insertPiece(r2, c2, piece);
        }
    return false;

}
bool Board::hasMoves(int clr){
         for (int i = 0; i < 8; ++i)
        {   
        for (int j = 0; j < 8; ++j)
        {   
           if(theBoard[i][j].isOccupied()){
            Piece* temp = theBoard[i][j].getPiece();
            if(temp != nullptr && temp->getColor() == clr){

                if(temp->hasMoves()){
                return true;
            }
            }
            
        
           }
            
        }
        
    }
    return false;

}

bool Board::hasMoves(int r, int c){
       
        if(theBoard[r][c].isOccupied()){
            Piece* temp = theBoard[r][c].getPiece();
            if(temp != nullptr){

                if(temp->hasMoves()){
                return true;
            }
            }
            
        
           }
    return false;

}

void Board::resign(int clr){
    resignedclr = clr;

}

int Board::resigned(){
    return resignedclr;

}
int Board::kingcount(int clr){
    int count = 0;
    for (int i = 0; i < 8; ++i)
    {   
        for (int j = 0; j < 8; ++j)
        {   
           if(theBoard[i][j].isOccupied()){
            Piece* temp = theBoard[i][j].getPiece();
            if(temp != nullptr){
                if(temp->getSymbol() == 'K' && clr == 0){
                count++;
            }
            if(temp->getSymbol() == 'k' && clr == 1){
                count++;
            }
            }
           }
            
        }
        
    }

    return count;
       }
         bool Board::pawnCanUpgrade(int clr){
              
            for (int i = 0; i < 8; ++i)
            {   
              if(theBoard[0][i].isOccupied()){
                    Piece* temp = theBoard[0][i].getPiece();
                    if(temp != nullptr){
                        if(temp->getSymbol() == 'p' && clr == 1){
                        return true;
                    }
                    }
                }
            }

            for (int i = 0; i < 8; ++i)
            {   
              if(theBoard[7][i].isOccupied()){
                    Piece* temp = theBoard[7][i].getPiece();
                    if(temp != nullptr){
                        if(temp->getSymbol() == 'P' && clr == 0){
                        return true;
                    }
                    }
                }
            }
        return false;
         }
        vector<position> Board::OccupiedSquares(int clr){
            vector<position> niceVec;
            for (int i = 0; i < 8; ++i)
    {   
        for (int j = 0; j < 8; ++j)
        {   
           if(theBoard[i][j].isOccupied()){
            Piece* temp = theBoard[i][j].getPiece();
            if(temp != nullptr && temp->getColor() == clr){
                niceVec.push_back(position{i, j});
            }
            }
           }
            
        }

        return niceVec;
        
    }

        
        vector<position> Board::validMoves(int row, int col){
            vector<position> coolvec;
            if(theBoard[row][col].isOccupied()){
            Piece* temp = theBoard[row][col].getPiece();
            if(temp != nullptr){
                return temp->getMoves();
            }
            }
            return coolvec;
        }

std::vector<fullmove> Board::WinningMoves(int clr){

    vector<fullmove> niceVec;
    for (int i = 0; i < 8; ++i)
    {   
        for (int j = 0; j < 8; ++j)
        {   
           if(theBoard[i][j].isOccupied()){
            Piece* temp = theBoard[i][j].getPiece();
            if(temp != nullptr && temp->getColor() == clr){
                position curpos = position{i, j};
                vector<position> tempvec = validMoves(i, j);
                for(position z : tempvec){
                    
                    if(createsCheck(curpos.row, curpos.col, z.row, z.col, clr)){
                        niceVec.push_back(fullmove{curpos.row, curpos.col, z.row, z.col});
                    }
                }
                
                
            }
            }
           }
            
        }
    return niceVec;

}
         std::vector<fullmove> Board::CaptureMoves(int clr){
            vector<fullmove> nicevec;
            int opcolor;
            if(clr == 0) opcolor = 1;
            else opcolor = 0;

            vector<position> enemyPositions = OccupiedSquares(opcolor);
            for (int i = 0; i < 8; ++i)
    {   
        for (int j = 0; j < 8; ++j)
        {   
           if(theBoard[i][j].isOccupied()){
            Piece* temp = theBoard[i][j].getPiece();
            if(temp != nullptr && temp->getColor() == clr){
                vector<position> moves = temp->getMoves();
                for(position z : moves){
                    for(position x : enemyPositions){
                        if(z.row == x.row && z.col == x.col){
                            nicevec.push_back(fullmove{i, j, z.row, z.col});
                        }
                    }
                }
            }
            }
           }
            
        }

        return nicevec;
         }
         bool Board::isThreatened(int r, int c){
            Piece* temp = nullptr;
            if(theBoard[r][c].isOccupied()){
                temp = theBoard[r][c].getPiece();
            }
            if(temp != nullptr){
                int clr = temp->getColor();
                int opcolor;
            if(clr == 0) opcolor = 1;
            else opcolor = 0;

            vector<fullmove> enemyKills = CaptureMoves(opcolor);

            for(fullmove mv : enemyKills){
                if(mv.r2 == r && mv.c2 == c){
                    return true;
                }
            }
            }
            return false;
         }



         std::vector<fullmove> Board::threatDodges(int clr){
            vector<fullmove> nicevec;
    for (int i = 0; i < 8; ++i)
    {   
        for (int j = 0; j < 8; ++j)
        {   
           if(theBoard[i][j].isOccupied()){
            Piece* temp = theBoard[i][j].getPiece();
            if(temp != nullptr && temp->getColor() == clr && isThreatened(i, j)){
                vector<position> moves = temp->getMoves();
                for(position pos : moves){
                    
                    nicevec.push_back(fullmove{i, j, pos.row, pos.col});
                }
            }
            }
           }
            
        }
        return nicevec;
         }
    bool Board::issafe(int r1, int c1, int r2, int c2, int clr){


            char piece = 'L';

            if(theBoard[r2][c2].isOccupied()){
                Piece* tempPiece = theBoard[r2][c2].getPiece();
                if(tempPiece != nullptr){
                    piece = tempPiece->getSymbol();
                }
                
            }

            move(r1, c1, r2, c2);
    
    if(isThreatened(r2, c2)){
        move(r2, c2, r1, c1);
        if(piece != 'L'){
            insertPiece(r2, c2, piece);
        }
        return false;
    }
    
    move(r2, c2, r1, c1);
    if(piece != 'L'){
            insertPiece(r2, c2, piece);
        }
    return true;
    }
