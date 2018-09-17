#include "./Island.h"
#include "./Bridge.h"
#include <math.h>
bool Island::isOk() {
    char curBridges = 0;
    for(int x = 0; x < conBridgesLen; x++)
        curBridges += ((Bridge**)conBridges)[x] -> getState();
    return curBridges <= maxBridges;
}

void Island::addBridge(void **tmp, int len){
    void** tmp2 = new void*[conBridgesLen+len];
    for(int x=0;x<conBridgesLen;x++)
        tmp2[x] = conBridges[x];
    for(int x=0;x<len;x++)
        tmp2[x] = tmp[x];
    delete conBridges;
    conBridges = tmp2;
}

void Island::addBridge(void *tmp){
    void** tmp2 = new void*[conBridgesLen+1];
    for(int x=0;x<conBridgesLen;x++)
        tmp2[x] = conBridges[x];
    tmp2[conBridgesLen++] = tmp;
    delete conBridges;
    conBridges = tmp2;
}

bool Island::isClicked(float x, float y){
    return pow(x-getX(),2) + pow(y-getY(),2) <= pow(ISLAND_RADIUS,2);
}
Island::Island(int hMaxBridges, float x, float y) : InputHitbox(x, y){
    maxBridges = hMaxBridges;
}
Island::Island(int hMaxBridges, float x, float y, void** hConBridges, int hConBridgesLen) : InputHitbox(x, y) {
    maxBridges = hMaxBridges;
    conBridgesLen = hConBridgesLen;
    conBridges = new void*[conBridgesLen];
    for(int x = 0; x < conBridgesLen; x++)
        conBridges[x] = hConBridges[x];
}

Island::~Island() {
    delete conBridges;
}