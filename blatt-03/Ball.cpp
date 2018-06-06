// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <ncurses.h>
#include <math.h>
#include <stdlib.h>
#include "./Ball.h"

// ___________________________________________________________________________
int x;
int y;
int rx;
int ry;
float fX, fY, fSpeedX, fSpeedY, fAccelY;
// ___________________________________________________________________________
void initTerminal() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);

  fX = x = COLS / 2;
  fY = y = LINES / 2;
  rx = 10;
  ry = 5;
  fSpeedX = fSpeedY = fAccelY = 0;
}


// ___________________________________________________________________________
void drawBall() {
  clear();
  attron(A_REVERSE);
  for (int dx = -rx; dx <= +rx; dx++) {
    for (int dy = -ry; dy <= +ry; dy++) {
       if (dx * dx * ry * ry + dy * dy * rx * rx < rx * rx * ry * ry) {
         mvprintw(y + dy, x + dx, " ");
       }
    }
  }
  attroff(A_REVERSE);
}

void drawBall(bool reverseColor) {
  if (reverseColor)
    attron(A_REVERSE);
  for (int dx = -rx; dx <= +rx; dx++) {
    for (int dy = -ry; dy <= +ry; dy++) {
       if (dx * dx * ry * ry + dy * dy * rx * rx < rx * rx * ry * ry) {
         mvprintw(y + dy, x + dx, " ");
       }
    }
  }
  if (reverseColor)
    attroff(A_REVERSE);
}
float moveBall(int key) {
    switch (key) {
      case KEY_LEFT:
        fSpeedX -= 0.02;
        break;
      case KEY_RIGHT:
        fSpeedX += 0.02;
        break;
      case KEY_UP:
        fAccelY -= 0.01;
        break;
      case KEY_DOWN:
        fAccelY += 0.01;
        break;
      case 27:
        endwin();  // cleanup screen
        exit(0);
        return -1;  // never used
    }
    return sqrt(pow(fSpeedX, 2) + pow(fSpeedY += fAccelY, 2));
}
