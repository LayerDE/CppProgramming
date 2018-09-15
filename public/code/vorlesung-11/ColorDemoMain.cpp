// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>

#include <ncurses.h>

int main(int argc, char** argv) {
  initscr();
  start_color();

  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_YELLOW);

  attron(COLOR_PAIR(1));
  printw("Hello in colour...\n");

  attron(COLOR_PAIR(2));
  printw("Hello again colour...\n");

  getch();

  endwin();
}

/*

Single bridge: -
Double bridge: =

X
X---------
X

X---------
X
X---------
