// Copyright 2018, University of Freiburg
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <ncurses.h>
#include <math.h>
#include "./Ball.h"


// ____________________________________________________________________________
// Position
float x;
float y;
// Radius
float rx;
float ry;
// Velocity
float vx;
float vy;
// Acceleration
float ax;
float ay;
// Maximum size, used for tests.
int maxX;
int maxY;

// ____________________________________________________________________________
void initTerminal() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);

  // COLS and LINES are global variables from ncurses (dimensions of screen).
  x = 1;
  y = 1;
  rx = 10;
  ry = 5;
  vx = 2;
  vy = 0;
  ax = 0;
  ay = 0.1;
  maxX = COLS;
  maxY = LINES;
}

// ____________________________________________________________________________
void drawBall(bool show) {
  if (show == true) attron(A_REVERSE);
  for (int dx = -rx; dx <= +rx; dx++) {
    for (int dy = -ry; dy <= +ry; dy++) {
      if (dx * dx * ry * ry + dy * dy * rx * rx < rx * rx * ry * ry) {
        mvprintw(y + dy, x + dx, " ");
      }
    }
  }
  attroff(A_REVERSE);
}

// ____________________________________________________________________________
float moveBall(int key) {
  switch (key) {
    case 27:  // ESC
      return -1;
    case KEY_DOWN:
      ay += 0.01;
      break;
    case KEY_UP:
      ay -= 0.01;
      break;
    case KEY_LEFT:
      vx -= 0.01;
      break;
    case KEY_RIGHT:
      vx += 0.01;
      break;
  }

  float v = sqrt(vx * vx + vy * vy);
  x += vx / v;
  y += vy / v;
  vx += ax;
  vy += ay;
  // Change direction on collision with any side and slow down.
  if (y < 1 || y > maxY) {
    vy *= -0.9;
    vx *= 0.9;
    y = y < 1 ? 1 : maxY;
  }
  if (x < 1 || x > maxX) {
    vx *= -0.9;
    vy *= 0.9;
    x = x < 1 ? 1 : maxX;
  }
  return v;
}
