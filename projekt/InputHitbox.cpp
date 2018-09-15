#include "./InputHitbox.h"

InputHitbox::InputHitbox(float hX, float hY){
    X = hX;
    Y = hY;
}

float InputHitbox::getX(){
    return X;
}

float InputHitbox::getY(){
    return Y;
}
