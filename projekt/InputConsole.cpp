#include <ncurses.h>
#include "./InputConsole.h"
#include <utility>

InputConsole::InputConsole(){
    mousemask(ALL_MOUSE_EVENTS, NULL);
}

std::pair<float,float> InputConsole::getInput(){
  MEVENT event;
  switch (getch()) {
    case 27:
      // Exit
      return {-1.0f,-1.0f};
    case ' ':
      // Toggle run
      return {-1.0f,1.0f};
    case 's':
      // Execute step
      return {-1.0f,2.0f};
    case KEY_MOUSE:
      if (getmouse(&event) == OK) {
        if (event.bstate & BUTTON1_CLICKED) {
          return {(float)event.x,(float)event.y};
        }
      }
      break;
  }
}