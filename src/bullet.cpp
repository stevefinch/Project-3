#include "bullet.h"

Bullet::Bullet() {
    visible = False;

}

void Bullet::draw() {
    if (visible) {
        ofSetColor(color);
        ofFill();
        ofDrawRectangle(x,y,20,5);
    }

}

void Bullet::move() {
    x = x + xVelocity;
    y = y + yVelocity;

}

void Bullet::shoot() {
    //TODO make bullet start from paddle
    x = 60;
    y = 300;
    xVelocity = 5;
    yVelocity = 0;
    color = ofColor(128,128,128);
    visible = true;

}

