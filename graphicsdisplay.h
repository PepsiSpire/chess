#ifndef _GRAPHICSDISPLAY_H_
#define _GRAPHICSDISPLAY_H_
#include <iostream>
#include <vector>
#include "window.h"
class GraphicsDisplay;
#include "square.h"
#include "piece.h"

class GraphicsDisplay {

  std::vector<std::vector<char>> theDisplay;
  std::vector<position> toUpdate;
    
  Xwindow window;
  const int recSize;

 public:
  GraphicsDisplay(Xwindow &window);

  void update(Square &c);
  void output();


  ~GraphicsDisplay();

};

#endif


