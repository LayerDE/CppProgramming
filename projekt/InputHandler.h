// Copyright [year] <Copyright Owner>
#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include "./Bridge.h"
#include "./Island.h"
#include "./InputHitbox.h"

class InputHandler {
 private:
  Island** islands;
  Bridge** bridges;
 public:
  InputHitbox* getInput();
};
#endif  // INPUTHANDLER_H_
