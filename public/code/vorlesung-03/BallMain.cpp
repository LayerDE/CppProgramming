// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <ncurses.h>
#include <unistd.h>
#include "./Ball.h"

// Show a ball on the screen and let it be moved with the arrow keys.
int main(int argc, char** argv) {
  initialize();

  // Move according to arrow keys.
  while (true) {
    drawBall();
    refresh();

    // Move according to pressed key.
    int key = getch();
    switch (key) {
      case KEY_LEFT:
        x -= 1;
        break;
      case KEY_RIGHT:
        x += 1;
        break;
    }

    // Do nothing for 1000ms.
    usleep(1000);
  }

  // Clean up.
  endwin();
}
