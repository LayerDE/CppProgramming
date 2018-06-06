// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <ncurses.h>
#include "./Ball.h"

// ___________________________________________________________________________
int x;
int y;
int rx;
int ry;

// ___________________________________________________________________________
void initialize() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);

  x = COLS / 2;
  y = LINES / 2;
  rx = 10;
  ry = 5;
}


// ___________________________________________________________________________
void drawBall() {
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
