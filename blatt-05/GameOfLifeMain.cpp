// Copyright 2018, Victor Maier

#include "./GameOfLife.h"

int main(int argc, char** argv) {
  GameOfLife *g = new GameOfLife();
  g->play();
  delete g;
}
