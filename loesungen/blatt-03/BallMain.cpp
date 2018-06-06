// Copyright 2018, University of Freiburg
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <ncurses.h>
#include <unistd.h>
#include "./Ball.h"

// Main function.
int main(int argc, char** argv) {
  initTerminal();
  refresh();
  drawBall(true);
  refresh();

  int key;
  while (true) {
    key = getch();
    drawBall(false);
    float v = moveBall(key);
    if (v < 0) break;
    drawBall(true);
    refresh();
    usleep(30 * 1000 / v);
  }

  endwin();
}
