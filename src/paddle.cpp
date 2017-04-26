#include "paddle.h"
#include "ofApp.h"

Paddle::Paddle() {

}

Paddle::Paddle(int x, int y) {
    this->x = x;
    this->y = y;
    paddleFrozen = False;
}

void Paddle::moveup() {
    y -= 2;
}

void Paddle::movedown() {
    y += 2;
}

void Paddle::draw() {
    ofSetColor(255,0,0);
    ofFill();
    ofDrawRectangle(x,y,10,80);


}
