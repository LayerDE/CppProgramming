// Copyright [year] <Copyright Owner>
#ifndef RENDERERCONSOLE_H_
#define RENDERERCONSOLE_H_
#include "./Renderer.h"

class RendererConsole : Renderer{
 protected:
  void* buffer;  // frame buffer
  void* permanentBuffer;  // frame buffer for elements that are staying
 public:
  RendererConsole();  // init in constructor
  ~RendererConsole();  // cleanup
  void drawFrame();  // draw frame to window/display/fixelflut
  void prepareBridge(float x1, float y1, float x2, float y2);
  void prepareDoubleBridge(float x1, float y1, float x2, float y2);
  void prepareIsland(float x1, float x2);
};
#endif  // RENDERERCONSOLE_H_