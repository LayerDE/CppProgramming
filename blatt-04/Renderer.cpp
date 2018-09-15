// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <ncurses.h>
#include "./Renderer.h"
#include "./Config.h"
#include "./GameFunctions.h"
void (*cellPrintPointer)(bool, int, int);

void initializeRenderer() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
}

void setColor(bool inverse) {
  cellPrintPointer = inverse ? _cellPrint2 : _cellPrint1;
  for (int x = 0; x < MAX_GRID_SIZE; x++)
    for (int y = 0; y < MAX_GRID_SIZE; y++)
      cellPrintPointer(currentCellPointer[x][y], x, y);
  refresh();
}

void cleanRenderer() {
  endwin();
}
// First steps towards game of life.

void showState() {  // print game
  int z = 0;
  for (int x = 0; x < MAX_GRID_SIZE; x++)
    for (int y = 0; y < MAX_GRID_SIZE; y++)
      if (currentCellPointer[x][y] != oldCellPointer[x][y]) {
        z++;
        cellPrintPointer(currentCellPointer[x][y], x, y);
      }
  mvprintw(1, 0, "Round: %i RendererDebug: %i     ", round, z);
  refresh();
}

void _cellPrint1(bool cell, int x, int y) {
  if (cell) {
    attron(A_REVERSE);
    mvprintw(y + Y_FREE_SPACE, x*2 + X_FREE_SPACE, "  ");  // print white
    attroff(A_REVERSE);
  } else {
    mvprintw(y + Y_FREE_SPACE, x*2 + X_FREE_SPACE, "  ");  // print black
  }
}
void _cellPrint2(bool cell, int x, int y) {
  if (cell) {
    mvprintw(y + Y_FREE_SPACE, x*2 + X_FREE_SPACE, "  ");  // print black
  } else {
    attron(A_REVERSE);
    mvprintw(y + Y_FREE_SPACE, x*2 + X_FREE_SPACE, "  ");  // print white
    attroff(A_REVERSE);
  }
}
