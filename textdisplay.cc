#include <iostream>
#include "textdisplay.h"
#include <iostream>
using namespace std;

TextDisplay::TextDisplay() {

    // bool printWhite = false;
     theDisplay.push_back({' ', '_', ' ', '_', ' ', '_', ' ', '_'});
    theDisplay.push_back({ '_', ' ', '_', ' ', '_', ' ', '_', ' '});
    theDisplay.push_back({' ', '_', ' ', '_', ' ', '_', ' ', '_'});
    theDisplay.push_back({ '_', ' ', '_', ' ', '_', ' ', '_', ' '});
    theDisplay.push_back({' ', '_', ' ', '_', ' ', '_', ' ', '_'});
    theDisplay.push_back({ '_', ' ', '_', ' ', '_', ' ', '_', ' '});
    theDisplay.push_back({' ', '_', ' ', '_', ' ', '_', ' ', '_'});
    theDisplay.push_back({ '_', ' ', '_', ' ', '_', ' ', '_', ' '});
   
    
    // for (int i = 0; i < 8; ++i)
    // {   
    //   vector<char> tempVec;
    //   for(int j=0; j < 8; j++){
    //     if(printWhite){
    //       tempVec.push_back(' ');
    //       printWhite = false;
    //     }else{
    //         tempVec.push_back('_');
    //         printWhite = true;
    //     }
        
    //   }
    //    theDisplay.push_back(tempVec);
    // }

}

void TextDisplay::update(Square &s) {
  int row = s.getRow();
  int col = s.getCol();

    theDisplay[row][col] = s.getSymbol();

}

void TextDisplay::print() {
  cout << endl;
  for (int i = 7; i >= 0; --i)
      
    {   
        cout << (i + 1) << " " ;
        cout << " ";
      for(int j=0; j < 8; j++){
        cout << theDisplay[i][j];
        cout << " ";
        
      }
      cout << endl;

}
cout << "   a b c d e f g h\n" << endl;
}

TextDisplay::~TextDisplay(){
  theDisplay.clear();
}



