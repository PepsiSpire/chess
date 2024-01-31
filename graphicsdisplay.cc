#include <iostream>
#include <sstream>
#include "graphicsdisplay.h"


using namespace std;

GraphicsDisplay::GraphicsDisplay(Xwindow &window) : window(window), recSize(48) {
  
        theDisplay.push_back({' ', '_', ' ', '_', ' ', '_', ' ', '_'});
    theDisplay.push_back({ '_', ' ', '_', ' ', '_', ' ', '_', ' '});
    theDisplay.push_back({' ', '_', ' ', '_', ' ', '_', ' ', '_'});
    theDisplay.push_back({ '_', ' ', '_', ' ', '_', ' ', '_', ' '});
    theDisplay.push_back({' ', '_', ' ', '_', ' ', '_', ' ', '_'});
    theDisplay.push_back({ '_', ' ', '_', ' ', '_', ' ', '_', ' '});
    theDisplay.push_back({' ', '_', ' ', '_', ' ', '_', ' ', '_'});
    theDisplay.push_back({ '_', ' ', '_', ' ', '_', ' ', '_', ' '});
    
    bool drawWhite = true;
    for (int i = 1; i < 9; ++i)
    {   
      if(i % 2 == 0)drawWhite = false;
      else drawWhite = true;
      for(int j=0; j < 8; j++){
        if(drawWhite){
          window.fillRectangle(i * recSize, j * recSize, recSize, recSize, Xwindow::White);
          drawWhite = false;
        }
        else{
          window.fillRectangle(i * recSize, j * recSize, recSize, recSize, Xwindow::Black);
          drawWhite = true;
        }
        


      }
    }
}
void GraphicsDisplay::output() {

    for (int i = 0; i <8; i++)
      
    {   

      for(int j=0; j < 8; j++){
        for(position p : toUpdate){

        if(p.row == i && p.col == j){
       if(theDisplay[i][j] != ' ' && theDisplay[i][j] != '_'){
          if(((i + 1) % 2 == 0 && (j + 1) % 2 == 0) || ((i + 1) % 2 != 0 && (j + 1) % 2 != 0)){
          window.drawPiece(j + 1, i, theDisplay[i][j], 0);
        
        }
        else{
          window.drawPiece(j + 1, i, theDisplay[i][j], 1);
          
        }
        }else{
          if(theDisplay[i][j] == ' '){
          window.fillRectangle((j + 1) * recSize, i * recSize, recSize, recSize, Xwindow::Black);

        }
        else{
          window.fillRectangle((j + 1) * recSize, i * recSize, recSize, recSize, Xwindow::White);
        }
        }
        
        break;
        }
        }
        
      }
}
toUpdate.clear();
  
}
void GraphicsDisplay::update(Square &s) {
  int row = s.getRow();
  int col = s.getCol();

  theDisplay[7 - row][col] = s.getSymbol();
  toUpdate.push_back(position{7-row, col});

  
}

GraphicsDisplay::~GraphicsDisplay() {
  
  theDisplay.clear();

}


