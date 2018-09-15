// Copyright [year] <Copyright Owner>
#ifndef ENGINE_H_
#define ENGINE_H_
#include <utility>
#include <vector>

class Engine {
 private:
  Renderer* rendererArray[];
  InputHandler* input[]
  Island* islands[]
  int islandLen;
  Bridge* possibleBridges[]
  int possibleBridgesLen;
  int rendererLen;
  int inputLen;
 public:
  explicit Engine(std::vector<std::pair<float, float>> islands);
  void addRenderer(Renderer tmp);
  bool checkFin();
}
#endif  // ENGINE_H_
