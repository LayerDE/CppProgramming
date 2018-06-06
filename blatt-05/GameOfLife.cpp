// Copyright 2018, Victor Maier

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>
#include "./GameOfLife.h"

// Glider.
static const int glider[5][2] = { {1, 0}, {2, 1}, {0, 2}, {1, 2}, {2, 2} };

// Glider factory.
static const int factory[36][2] = {
  {24, 0},
  {22, 1}, {24, 1},
  {12, 2}, {13, 2}, {20, 2}, {21, 2}, {34, 2}, {35, 2},
  {11, 3}, {15, 3}, {20, 3}, {21, 3}, {34, 3}, {35, 3},
  {0, 4}, {1, 4}, {10, 4}, {16, 4}, {20, 4}, {21, 4},
  {0, 5}, {1, 5}, {10, 5}, {14, 5}, {16, 5}, {17, 5}, {22, 5}, {24, 5},
  {10, 6}, {16, 6}, {24, 6},
  {11, 7}, {15, 7},
  {12, 8}, {13, 8}
};

// ____________________________________________________________________________
void GameOfLife::initializeGame() {
  // Init terminal
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);
  // Catch mouse events
  mousemask(ALL_MOUSE_EVENTS, NULL);

  // Determine drawing bounds. Show only around the center of the grid with
  // respect to the scaling of one cell.
  drawMinX = (MAX_GRID_SIZE / 2) - ((COLS / xSize) / 2);
  drawMaxX = drawMinX + (COLS / xSize);
  drawMinY = (MAX_GRID_SIZE / 2) - ((LINES / ySize) / 2);
  drawMaxY = drawMinY + (LINES / ySize);
}

// ____________________________________________________________________________
int GameOfLife::processUserInput(int key) {
  MEVENT event;
  switch (key) {
    case 27:
      // Exit
      return -1;
    case ' ':
      // Toggle run
      return 1;
    case 's':
      // Execute step
      return 2;
    case 'c':
      // Clear all
      for (int x = 0; x < MAX_GRID_SIZE; ++x) {
        for (int y = 0; y < MAX_GRID_SIZE; ++y) {
          (*newGrid)[x][y] = false;
        }
      }
      break;
    case 'r':
      // Fill randomly
      for (int x = 0; x < MAX_GRID_SIZE; ++x) {
        for (int y = 0; y < MAX_GRID_SIZE; ++y) {
          (*newGrid)[x][y] = drand48() > 0.8;
        }
      }
      break;
    case 'g':
      // Generate glider
      if (lastClickedX != -1 && lastClickedY != -1) {
        (*newGrid)[lastClickedX][lastClickedY] = false;
        for (int i = 0; i < 5; ++i) {
          (*newGrid)[lastClickedX + glider[i][0]]
            [lastClickedY + glider[i][1]] = true;
        }
      }
      break;
    case 'G':
      // Generate glider
      if (lastClickedX != -1 && lastClickedY != -1) {
        (*newGrid)[lastClickedX][lastClickedY] = false;
        for (int i = 0; i < 36; ++i) {
          (*newGrid)[lastClickedX + factory[i][0]]
            [lastClickedY + factory[i][1]] = true;
        }
      }
      break;
    case KEY_MOUSE:
      if (getmouse(&event) == OK) {
        if (event.bstate & BUTTON1_CLICKED) {
          // Store position of click and invert cell.
          lastClickedX = drawMinX + event.x / xSize;
          lastClickedY = drawMinY + event.y / ySize;
          (*newGrid)[lastClickedX][lastClickedY] =
            !(*newGrid)[lastClickedX][lastClickedY];
        }
      }
      break;
  }
  return 0;
}

// ____________________________________________________________________________
void GameOfLife::updateState() {
  livingCells = 0;
  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      int neighbours = aliveNeighbours(x, y);
      (*newGrid)[x][y] = false;
      if ((*oldGrid)[x][y]) {
        // Stay alive if 2 or 3 neighbours are alive, die otherwise.
        (*newGrid)[x][y] = neighbours > 1 && neighbours < 4;
      } else if (neighbours == 3) {
        // Birth of a cell if exactly 3 neighbours are alive.
        (*newGrid)[x][y] = true;
      }
      // Count cells which are alive.
      livingCells += (*newGrid)[x][y];
    }
  }
}

// ____________________________________________________________________________
int GameOfLife::aliveNeighbours(int x, int y) {
  int result = 0;
  // Check the 3x3 around the given cell.
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      // Ignore the given cell itself
      if (dx == 0 && dy == 0) { continue; }
      // Don't check outside the grid, treat them as dead.
      if (x + dx >= 0 && x + dx < MAX_GRID_SIZE &&
          y + dy >= 0 && y + dy < MAX_GRID_SIZE) {
        result += (*oldGrid)[x + dx][y + dy];
      }
    }
  }
  return result;
}

// ____________________________________________________________________________
void GameOfLife::play() {
  // Initialize terminal and grid.
  initializeGame();

  while (true) {
    int key = getch();
    int newRun = processUserInput(key);
    if (newRun == -1) {
      // Exit
      break;
    }
    if (newRun == 1) {
      // Toggle running
      running = !running;
    }
    if (running || newRun == 2) {
      // Calculate next state if running or single step is wanted.
      bool (*tempGrid)[MAX_GRID_SIZE][MAX_GRID_SIZE] = newGrid;
      newGrid = oldGrid;
      oldGrid = tempGrid;
      updateState();
      steps++;
    }
    // Draw and wait.
    showState();
    usleep(10 * 1000);
  }
}

// ____________________________________________________________________________
void GameOfLife::showState() {
  // Only draw visible cells.
  for (int x = 0; x < drawMaxX - drawMinX; ++x) {
    for (int y = 0; y < drawMaxY - drawMinY; ++y) {
      attroff(A_REVERSE);
      if ((*newGrid)[drawMinX + x][drawMinY + y]) {
        attron(A_REVERSE);
      }
      // Scale each visible cell.
      for (int dx = 0; dx < xSize; ++dx) {
        for (int dy = 0; dy < ySize; ++dy) {
          mvprintw(y * ySize + dy, x * xSize + dx, " ");
        }
      }
    }
  }
  attroff(A_REVERSE);
  mvprintw(0, 0, "Step: %9d Cells alive: %4d Running: %d", steps, livingCells,
           running);
}
GameOfLife::GameOfLife() {
  oldGrid = &grid1;
  newGrid = &grid2;
  memset(&grid1, 0, sizeof(grid1));
  memset(&grid2, 0, sizeof(grid2));
  lastClickedX = -1;
  lastClickedY = -1;
  xSize = 3;
  ySize = 2;
  running = false;
  steps = 0;
  livingCells = 0;
}
GameOfLife::~GameOfLife() {
  // Clean up window.
  endwin();
}
