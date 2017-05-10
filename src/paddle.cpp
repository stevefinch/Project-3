#include "paddle.h"
#include "ofApp.h"
#include "ofMain.h"

Paddle::Paddle() {

}

Paddle::Paddle(int x, int y) {
    position.x = x;
    position.y = y;
    paddleFrozen = false;
}

void Paddle::moveup(int height) {
    position.y = max(height, (int)position.y-2);

}

void Paddle::movedown(int height) {
    position.y = min(height, (int)position.y+2);

}

void Paddle::draw() {
    ofSetColor(255,0,0);
    ofFill();
    ofDrawRectangle(position.x,position.y,10,80);

}
