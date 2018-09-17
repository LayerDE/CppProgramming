#include "Renderer.h"

Renderer::~Renderer() {
    delete buffer;
    delete permanentBuffer;
}
InputHandler* Renderer::getInput() {
  return nullptr;
}