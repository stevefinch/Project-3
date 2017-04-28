#include "ball.h"
#include "ofApp.h"

Ball::Ball() {
    this->reset();

}

void Ball::draw() {
    ofSetColor(64,128,64);
    ofFill();
    ofDrawCircle(x,y,15);

}

void Ball::move(float multiplier) {
    x = x + xVelocity * multiplier;
    y = y + yVelocity * multiplier;

}

void Ball::reset() {
    x = (0.5 + ofRandom(-0.25, 0.25))* ofGetHeight();
    y = (0.5 + ofRandom(-0.25, 0.25))* ofGetWidth();
    xVelocity = -1.0+ofRandom(-0.5, 0.5);
    yVelocity = ofRandom(-0.5, 0.5);

}
