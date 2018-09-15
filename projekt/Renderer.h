// Copyright [year] <Copyright Owner>
#ifndef RENDERER_H_
#define RENDERER_H_

class Renderer {
 protected:
  void* buffer;  // frame buffer
  void* permanentBuffer;  // frame buffer for elements that are staying
 public:
  ~Renderer();  // cleanup
  virtual void drawFrame() = 0;  // draw frame to window/display/fixelflut
  virtual void prepareBridge(float x1, float y1, float x2, float y2) = 0;
  virtual void prepareDoubleBridge(float x1, float y1, float x2, float y2) = 0;
  virtual void prepareIsland(float x1, float x2) = 0;
};
#endif  // RENDERER_H_
