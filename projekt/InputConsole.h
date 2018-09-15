// Copyright [year] <Copyright Owner>
#ifndef INPUTCONSOLE_H_
#define INPUTCONSOLE_H_

#include <utility>
#include "./InputHandler.h"

class InputConsole : InputHandler {
    std::pair<float,float> getInput();
};
#endif  // INPUTCONSOLE_H_
