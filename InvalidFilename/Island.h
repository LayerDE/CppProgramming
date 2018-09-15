// Copyright [year] <Copyright Owner>
#ifndef ISLAND_H_
#define ISLAND_H_
#include <utility>

class Island : InputHitbox {
 private:
  int maxBridges;
 public:
  bool isOk();
  void addBridge(Bridge tmp[], int len);
  bool isClicked(float x, float y);
  Island(int hMaxBridges, float x, float y);
  Island(int hMaxBridges, bridge conBridges[], int conBridgesLen);
  ~Island();
  std::pair<float, float> getCoordinates();
};
#endif  // ISLAND_H_
