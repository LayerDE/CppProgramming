#include "./Island.h"
#include <math.h>
bool Island::isOk() {
    char curBridges = 0;
    for(int x = 0; x < conBridgesLen; x++)
        curBridges += conBridges[x] -> getState();
    return curBridges <= maxBridges;
}

void Island::addBridge(Bridge tmp[], int len){

}
bool Island::isClicked(float x, float y){
    return pow(x-getX(),2) + pow(y-getY(),2) <= pow(ISLAND_RADIUS,2);
}
Island::Island(int hMaxBridges, float x, float y) : InputHitbox(x, y){
    maxBridges = hMaxBridges;
}
Island::Island(int hMaxBridges, float x, float y, Bridge* hConBridges[], int hConBridgesLen) : InputHitbox(x, y) {
    maxBridges = hMaxBridges;
    conBridgesLen = hConBridgesLen;
    conBridges = new Bridge*[conBridgesLen];
    for(int x = 0; x < conBridgesLen; x++)
        conBridges[x] = hConBridges[x];
}

Island::~Island() {
    
}