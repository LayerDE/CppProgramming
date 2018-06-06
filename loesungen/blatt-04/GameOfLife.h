// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_

// The grid, alternated use as old and new grid.
const int MAX_GRID_SIZE = 1000;
extern bool (*oldGrid)[MAX_GRID_SIZE][MAX_GRID_SIZE];
extern bool (*newGrid)[MAX_GRID_SIZE][MAX_GRID_SIZE];

// Last coordinate clicked inside grid.
extern int lastClickedX;
extern int lastClickedY;
// State information
extern int livingCells;

// Initialize the terminal
void initializeGame();

// Handle key and mouse presses. Change the new grid.
int processUserInput(int key);

// Calculate the next state and write it into new grid.
void updateState();

// Count the number of alive cells around given coordinates in the old grid.
int aliveNeighbours(int x, int y);

// The game of life itseld.
void game();

// Draw the new grid using ncurses.
void showState();

#endif  // GAMEOFLIFE_H_
