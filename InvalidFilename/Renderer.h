// Copyright [year] <Copyright Owner>
#ifndef RENDERER_H_
#define RENDERER_H_

class Renderer {
 protected:
  void* buffer;  // frame buffer
  void* permanentBuffer;  // frame buffer for elements that are staying
 public:
  virtual Renderer() = 0;  // init in constructor
  virtual ~Renderer() {  // cleanup
    delete buffer;
    delete permanentBuffer;
  }
  virtual drawFrame() = 0;  // draw frame to window/display/fixelflut
  virtual prepareBridge(float x1, float y1, float x2, float y2) = 0;
  virtual prepareDoubleBridge(float x1, float y1, float x2, float y2) = 0;
  virtual prepareIsland(float x1, float x2) = 0;
}
#endif  // RENDERER_H_
