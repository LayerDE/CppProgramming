// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <ncurses.h>
#include "./GameFunctions.h"
#include "./Renderer.h"
#include "./Config.h"

bool _cells[2][MAX_GRID_SIZE][MAX_GRID_SIZE] = { 0 };
bool (*currentCellPointer)[200];
bool (*oldCellPointer)[200];
int round = 0;
void initializeGame() {
  currentCellPointer = _cells[0];
  oldCellPointer = _cells[1];
}
void initializeNcurseGame() {
  keypad(stdscr, true);
  mousemask(ALL_MOUSE_EVENTS, NULL);
}
void updateState() {
  for (int x = 0; x < MAX_GRID_SIZE; x++)
    for (int y = 0; y < MAX_GRID_SIZE; y++) {
      int tempNeighbors = aliveNeighbors(x, y);
      if (2 > tempNeighbors || tempNeighbors > 3)
        oldCellPointer[x][y] = false;
      else if (tempNeighbors == 3)
        oldCellPointer[x][y] = true;
    }
  bool (*temp)[200] = currentCellPointer;  // swap ptr
  currentCellPointer = oldCellPointer;
  oldCellPointer = temp;
  round++;
}

int aliveNeighbors(int x, int y) {
  int retVal = 0;
  for (int j = -1; j <= 1; j++) {
    for (int k = -1; k <= 1; k++) {
      if (!(j == 0 && k == 0)) {
        if (x+j >= 0 && y+k >= 0 && x+j < MAX_GRID_SIZE
            && y+k < MAX_GRID_SIZE) {
          if (currentCellPointer[x+j][y+k] == true) {
            retVal++;
          }
        }
      }
    }
  }
  return retVal;
}

int processUserInput(int key) {
  MEVENT event;
  switch (key) {
    case 27:
      return EVENT_EXIT;
    case ' ':
      return EVENT_RUN;
    case 's':
      return EVENT_STEPS;
    case 'c':
      return EVENT_COLOR;
    case KEY_MOUSE:
      if (getmouse(&event) == OK && (event.bstate & BUTTON1_CLICKED)) {
        int x = (event.x - X_FREE_SPACE)/2;
        int y = event.y -Y_FREE_SPACE;
        if (x >= 0 && x < MAX_GRID_SIZE && y >= 0 && y < MAX_GRID_SIZE) {
          currentCellPointer[x][y] = !currentCellPointer[x][y];
          cellPrintPointer(currentCellPointer[x][y], x, y);
          mvprintw(0, 0, "Mouse clicked at %d, %d\n", x, y);
        }
      }
    default:
      return EVENT_NONE;
  }
}
