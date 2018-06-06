// Copyright 2018, LayerDE, MIT


#include <stdlib.h>
#include <ncurses.h>
#include "./Renderer.h"
#include "./Config.h"
#include "./GameFunctions.h"


int main(int argc, char** argv) {
  bool isRunning = false;
  bool runStep = false;
  bool color = false;
  initializeRenderer();
  initializeGame();
  setColor(color);
  while (true) {
    switch (processUserInput(getch())) {
      case EVENT_EXIT:
        cleanRenderer();
        exit(0);
      case EVENT_RUN:
        isRunning = !isRunning;
        break;
      case EVENT_STEPS:
        runStep = true;
        break;
      case EVENT_COLOR:
        setColor(color = !color);
        break;
    }
    if (isRunning || runStep) {
      runStep = false;
      updateState();
    }
    showState();
  }
}
