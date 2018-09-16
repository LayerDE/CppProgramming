// Copyright [year] <Copyright Owner>
#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include "./Bridge.h"
#include "./Island.h"
#include "./InputHitbox.h"

class InputHandler {
 public:
  virtual InputHitbox* getInput() = 0;
};
#endif  // INPUTHANDLER_H_
