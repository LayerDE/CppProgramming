// Copyright [year] <Copyright Owner>
#ifndef ISLAND_H_
#define ISLAND_H_
#include <utility>
#include "./InputHitbox.h"
#define ISLAND_RADIUS 2.0

class Island : public InputHitbox {
 private:
  int maxBridges;
  void **conBridges;
  int conBridgesLen;
 public:
  bool isOk();
  void addBridge(void** tmp, int len);
  bool isClicked(float x, float y);
  Island(int hMaxBridges, float x, float y);
  Island(int hMaxBridges, float x, float y, void **hConBridges, int hConBridgesLen);
  ~Island();
  std::pair<float, float> getCoordinates();
};
#endif  // ISLAND_H_
