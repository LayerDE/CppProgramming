// Copyright [year] <Copyright Owner>
// NO CLEANUP
// NO TODO
#ifndef BRIDGE_H_
#define BRIDGE_H_
#include "./InputHitbox.h"
#include "./Island.h"
#define BRIDGE_WIDTH 1.0

class Bridge : InputHitbox {  // contains the X and Y
 private:
  int len;  // lenght of the bridge
  bool vertical;  // is vertical for renderer
  bool isActive;  // is shown
  bool isDouble;  // is two lines
  Island* conIslands[2];  // the two islands
 public:
  Bridge(Island* a, Island* b);  // constructor
  bool isClicked(float x, float y);  // override
  int getState();  // return 0, 1 or 2
  void computeInput();  // go to next state
};
#endif  // BRIDGE_H_
