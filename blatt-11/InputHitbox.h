// Copyright [year] <Copyright Owner>
#ifndef INPUTHITBOX_H_
#define INPUTHITBOX_H_
class InputHitbox {
 protected:
  float x, y;
 public:
  virtual InputHitbox(float hX, float hY);
  virtual bool isClicked(float x, float y) = 0;
}
#endif  // INPUTHITBOX_H_
