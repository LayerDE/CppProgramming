#include "Renderer.h"

Renderer::~Renderer() {
    delete buffer;
    delete permanentBuffer;
}