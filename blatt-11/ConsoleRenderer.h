// Copyright [year] <Copyright Owner>
#ifndef CONSOLERENDERER_H_
#define CONSOLERENDERER_H_
class ConsoleRenderer {
 public:
  ConsoleRenderer();  // init in constructor
  ~ConsoleRenderer();  // cleanup
  drawFrame() = 0;  // draw frame to window/display/fixelflut
  prepareBridge(float x1, float y1, float x2, float y2);
  prepareDoubleBridge(float x1, float y1, float x2, float y2);
  prepareIsland(float x1, float x2);
}
#endif  // CONSOLERENDERER_H_
