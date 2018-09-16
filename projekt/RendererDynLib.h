#include "./Renderer.h"
#include <dlfcn.h>
#include <string>

class RendererDynLib : Renderer {
 private:
  void* handle;
  void (*drawFramePtr)(void* bufferPerm, void* bufferTmp);
  void (*prepareBridgePtr)(void* bufferTmp,float x1, float y1, float x2, float y2);
  void (*prepareDoubleBridgePtr)(void* bufferTmp, float x1, float y1, float x2, float y2);
  void (*prepareIslandPtr)(void* bufferTmp, float x1, float x2);
 public:
  RendererDynLib(std::string path){
      handle = dlopen(path.c_str(), RTLD_LAZY);
      drawFramePtr = (void (*)(void* bufferPerm, void* bufferTmp))dlsym(handle, "drawFrame");
      prepareBridgePtr = (void (*)(void* bufferTmp,float x1, float y1, float x2, float y2))dlsym(handle, "prepareBridge");
      prepareDoubleBridgePtr = (void (*)(void* bufferTmp, float x1, float y1, float x2, float y2))dlsym(handle, "prepareDoubleBridge");
      prepareIslandPtr = (void (*)(void* bufferTmp, float x1, float x2))dlsym(handle, "prepareIsland");
  }
  ~RendererDynLib(){
      dlclose(handle);
      delete buffer;
      delete permanentBuffer;
  }
  void drawFrame(){
      drawFramePtr(permanentBuffer, buffer);
  } // draw frame to window/display/fixelflut
  void prepareBridge(float x1, float y1, float x2, float y2){prepareBridgePtr(buffer, x1, y1, x2, y2);}
  void prepareDoubleBridge(float x1, float y1, float x2, float y2){prepareDoubleBridgePtr(buffer, x1, y1, x2, y2);}
  void prepareIsland(float x1, float x2) {prepareIslandPtr(buffer, x1, x2);}
};
