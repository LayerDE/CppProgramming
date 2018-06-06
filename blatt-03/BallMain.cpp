// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <ncurses.h>
#include <unistd.h>
#include "./Ball.h"

// Show a ball on the screen and let it be moved with the arrow keys.
int main(int argc, char** argv) {
  initTerminal();

  // Move according to arrow keys.
  while (true) {
    drawBall();
    refresh();

    // Move according to pressed key.
    moveBall(getch());

    x = fX += fSpeedX;
    y = fY += fSpeedY;
    if (fX + rx > COLS)  // reflector function
      fSpeedX = -fSpeedX*0.9;
    else if (fX - rx < 0)
      fSpeedX = -fSpeedX*0.9;
    if (fY + ry > LINES) {
      fSpeedY = -fSpeedY*0.9;
      fAccelY = -fAccelY;
    } else if (fY - ry < 0) {
      fSpeedY = -fSpeedY*0.9;
      fAccelY = -fAccelY;
    }
    // Do nothing for 1000ms.
    usleep(1000*10);
  }

  // Clean up.
  endwin();
}
