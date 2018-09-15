// Copyright [year] <Copyright Owner>
// rendererArray input islands possible bridges
#ifndef ENGINE_H_
#define ENGINE_H_
#include <utility>
#include <vector>
#include "./Renderer.h"
#include "./InputHandler.h"
#include "./Island.h"
#include "./Bridge.h"




class Engine {
 private:
  Renderer** rendererArray;
  InputHandler** input;
  Island** islands;
  int islandLen;
  Bridge** possibleBridges;
  int possibleBridgesLen;
  int rendererLen;
  int inputLen;
  void createPosBridges();
 public:
  explicit Engine(std::vector<std::pair<std::pair<float, float>, int>> islands);
  ~Engine();
  void addRenderer(Renderer *tmp);
  void addInput(InputHandler *tmp);

  bool checkFin();
};
#endif  // ENGINE_H_
