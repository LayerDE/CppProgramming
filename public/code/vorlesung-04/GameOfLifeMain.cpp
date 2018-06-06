// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <ncurses.h>

// First steps towards game of life.
int main(int argc, char** argv) {
  // Initialize ncurses.
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);
  mousemask(ALL_MOUSE_EVENTS, NULL);

  // Cells (0 = false, 1 = true).
  bool cells[200][200] = { 0 };

  // Check for mouse clicks in an infinite loop.
  while (true) {
    MEVENT event;
    int key = getch();
    if (key == KEY_MOUSE) {
      if (getmouse(&event) == OK && (event.bstate & BUTTON1_CLICKED)) {
        int x = event.x;
        int y = event.y;
        mvprintw(0, 0, "Mouse clicked at %d, %d\n", x, y);
        cells[x][y] = !cells[x][y];
        if (cells[x][y] == true) { attron(A_REVERSE); }
        mvprintw(y, x, " ");
        attroff(A_REVERSE);
        refresh();
      }
    }
  }

  // Clean up.
  endwin();
}
