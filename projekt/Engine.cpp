#include "./Engine.h"

void Engine::addRenderer(Renderer *tmp){
    Renderer** tmp2 = new Renderer*[rendererLen+1];
    for(int x = 0; x < rendererLen;x++)
        tmp2[x] = rendererArray[x];
    tmp2[rendererLen++] = tmp;
    delete rendererArray;
    rendererArray = tmp2;
}

bool Engine::checkFin(){
    for(int x = 0; x < islandLen; x++)
        if(!islands[x] -> isOk())
            return false;
    return true;
}

Engine::~Engine(){
    delete[] rendererArray;
    delete[] input;
    delete[] islands;
    delete[] possibleBridges;
}