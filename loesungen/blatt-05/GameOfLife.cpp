// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "./GameOfLife.h"
#include "./GameOfLifePrefab.h"

// ____________________________________________________________________________
GameOfLife::GameOfLife() {
  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      _grid1[x][y] = false;
      _grid2[x][y] = false;
    }
  }
  _oldGrid = &_grid1;
  _newGrid = &_grid2;

  // Scaling
  _xSize = 3;
  _ySize = 2;

  // Last click, used to generate glider and cannon.
  _lastClickedX = -1;
  _lastClickedY = -1;

  // State
  _running = false;
  _steps = 0;
  _livingCells = 0;
}

// ____________________________________________________________________________
GameOfLife::~GameOfLife() {
  endwin();
}

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
  _drawMinX = (MAX_GRID_SIZE / 2) - ((COLS / _xSize) / 2);
  _drawMaxX = _drawMinX + (COLS / _xSize);
  _drawMinY = (MAX_GRID_SIZE / 2) - ((LINES / _ySize) / 2);
  _drawMaxY = _drawMinY + (LINES / _ySize);
}

// ____________________________________________________________________________
void GameOfLife::insertPrefab(int x, int y, GameOfLifePrefab prefab) {
  (*_newGrid)[x][y] = false;
  for (int i = 0; i < prefab.getNumberOfCells(); ++i) {
    (*_newGrid)[x + prefab.getRelativeX(i)][y + prefab.getRelativeY(i)] = true;
  }
}

// ____________________________________________________________________________
int GameOfLife::processUserInput(int key) {
  GameOfLifePrefab prefab;
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
          (*_newGrid)[x][y] = false;
        }
      }
      break;
    case 'r':
      // Fill randomly
      for (int x = 0; x < MAX_GRID_SIZE; ++x) {
        for (int y = 0; y < MAX_GRID_SIZE; ++y) {
          (*_newGrid)[x][y] = drand48() > 0.8;
        }
      }
      break;
    case 'g':
      // Generate glider
      if (_lastClickedX != -1 && _lastClickedY != -1) {
        prefab.select(0);
        insertPrefab(_lastClickedX, _lastClickedY, prefab);
      }
      break;
    case 'G':
      // Generate a glider factory
      if (_lastClickedX != -1 && _lastClickedY != -1) {
        prefab.select(1);
        insertPrefab(_lastClickedX, _lastClickedY, prefab);
      }
      break;
    case KEY_MOUSE:
      if (getmouse(&event) == OK) {
        if (event.bstate & BUTTON1_CLICKED) {
          // Store position of click and invert cell.
          _lastClickedX = _drawMinX + event.x / _xSize;
          _lastClickedY = _drawMinY + event.y / _ySize;
          (*_newGrid)[_lastClickedX][_lastClickedY] =
            !(*_newGrid)[_lastClickedX][_lastClickedY];
        }
      }
      break;
  }
  return 0;
}

// ____________________________________________________________________________
void GameOfLife::updateState() {
  _livingCells = 0;
  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      int neighbours = aliveNeighbours(x, y);
      (*_newGrid)[x][y] = false;
      if ((*_oldGrid)[x][y]) {
        // Stay alive if 2 or 3 neighbours are alive, die otherwise.
        (*_newGrid)[x][y] = neighbours > 1 && neighbours < 4;
      } else if (neighbours == 3) {
        // Birth of a cell if exactly 3 neighbours are alive.
        (*_newGrid)[x][y] = true;
      }
      // Count cells which are alive.
      _livingCells += (*_newGrid)[x][y];
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
        result += (*_oldGrid)[x + dx][y + dy];
      }
    }
  }
  return result;
}

// ____________________________________________________________________________
void GameOfLife::play() {
  while (true) {
    int key = getch();
    int newRun = processUserInput(key);
    if (newRun == -1) {
      // Exit
      break;
    }
    if (newRun == 1) {
      // Toggle running
      _running = !_running;
    }
    if (_running || newRun == 2) {
      // Calculate next state if running or single step is wanted.
      bool (*tempGrid)[MAX_GRID_SIZE][MAX_GRID_SIZE] = _newGrid;
      _newGrid = _oldGrid;
      _oldGrid = tempGrid;
      updateState();
      _steps++;
    }
    // Draw and wait.
    showState();
    usleep(10 * 1000);
  }
}

// ____________________________________________________________________________
void GameOfLife::showState() {
  // Only draw visible cells.
  for (int x = 0; x < _drawMaxX - _drawMinX; ++x) {
    for (int y = 0; y < _drawMaxY - _drawMinY; ++y) {
      attroff(A_REVERSE);
      if ((*_newGrid)[_drawMinX + x][_drawMinY + y]) {
        attron(A_REVERSE);
      }
      // Scale each visible cell.
      for (int dx = 0; dx < _xSize; ++dx) {
        for (int dy = 0; dy < _ySize; ++dy) {
          mvprintw(y * _ySize + dy, x * _xSize + dx, " ");
        }
      }
    }
  }
  attroff(A_REVERSE);
  mvprintw(0, 0, "Step: %9d Cells alive: %4d Running: %d", _steps,
           _livingCells, _running);
}
