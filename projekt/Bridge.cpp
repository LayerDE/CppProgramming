#include <math.h>
#include "./Bridge.h"
#include "./InputHitbox.h"
#include "./Island.h"
Bridge::Bridge(Island *a, Island *b) : 
    InputHitbox((a->getX() + b->getX()) / 2 , (a->getY() + b->getY() / 2)) {
        len = sqrt(pow(a->getX() - b->getX(),2) + pow(a->getY() - b->getY(),2));
        vertical = abs(a->getX() - b->getX()) < abs(getY() - b->getY());
        isActive = isDouble = false;
}

bool Bridge::isClicked(float x, float y){
    if (!isActive)
        return false;
    //do something
    if(vertical){
        if(getX()-len/2.0<=x && getX()+len/2.0>=x && getY()-BRIDGE_WIDTH/2.0<=y && getY()+BRIDGE_WIDTH/2.0>=y)
            return true;
        else
            return false;
    }
    else{
        if(getY()-len/2.0<=y && getY()+len/2.0>=y && getX()-BRIDGE_WIDTH/2.0<=x && getX()+BRIDGE_WIDTH/2.0>=x)
            return true;
        else
            return false;
    }
}

int Bridge::getState() {
    return isActive * (1 + isDouble);
}

void Bridge::computeInput() {
    switch((isDouble << 1) | isActive){
        case 0:
            isActive = true;
        break;
        case 1:
            isDouble = true;
        break;
        default:
            isActive = false;
            isDouble = false;
        break;
    }
}
