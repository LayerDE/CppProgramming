// Copyright 2018, Victor Maier

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_

#define MAX_GRID_SIZE 1000

class GameOfLife{
 private:
  // The grid, alternated use as old and new grid.
  bool grid1[MAX_GRID_SIZE][MAX_GRID_SIZE] = {0};
  bool grid2[MAX_GRID_SIZE][MAX_GRID_SIZE] = {0};
  // Scaling and bounds for drawing.
  int drawMinX;
  int drawMaxX;
  int drawMinY;
  int drawMaxY;
  // Last click, used to generate glider and cannon.
  int xSize;
  int ySize;
  // Global state
  bool running;
  int steps;


 public:
  GameOfLife();
  ~GameOfLife();
  // The grid poniter, alternated use as old and new grid.
  bool (*oldGrid)[MAX_GRID_SIZE][MAX_GRID_SIZE];
  bool (*newGrid)[MAX_GRID_SIZE][MAX_GRID_SIZE];
  int lastClickedX;
  int lastClickedY;
  int livingCells;
  void initializeGame();
  int processUserInput(int key);
  void updateState();
  int aliveNeighbours(int x, int y);
  void play();
  void showState();
};

#endif  // GAMEOFLIFE_H_
