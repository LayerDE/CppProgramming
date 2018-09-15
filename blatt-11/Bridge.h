// Copyright [year] <Copyright Owner>

#ifndef BRIDGE_H_
#define BRIDGE_H_
class Bridge : InputHitbox {
 private:
  float len;
  bool vertical;
  bool isActive;
  bool isDouble;
  Island conIslands[2];
 public:
  Bridge();
  bool isClicked(float x, float y);  // override
  int getState();
  void computeInput();
}
#endif  // BRIDGE_H_
