// Copyright [year] <Copyright Owner>
#ifndef INPUTHITBOX_H_
#define INPUTHITBOX_H_
#include <utility>


class InputHitbox{
 private:
  int X, Y;
 protected:
  InputHitbox(float hX, float hY);
  virtual bool isClicked(float x, float y) = 0;
 public:
  float getX();
  float getY();
  std::pair<float, float> getPos();
};

#endif  // INPUTHITBOX_H_
