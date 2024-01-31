#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
class TextDisplay;
#include "square.h"


class TextDisplay {
  std::vector<std::vector<char>> theDisplay;
 public:
  TextDisplay();
  void update(Square &s);
  void print();

  ~TextDisplay();
};

#endif
