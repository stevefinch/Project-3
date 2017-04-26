#include "ball.h"
#include "ofApp.h"

Ball::Ball() {
    x = ofGetHeight()/2 + ofRandom(-100,100);
    y = ofGetWidth()/2 + ofRandom(-100,100);
    xVelocity = -1+ofRandom(-.5,.5);
    yVelocity = .5+ ofRandom(-1,1);
    spin = 0;
}

void Ball::draw() {
    ofSetColor(64,128,64);
    ofFill();
    ofDrawCircle(x,y,15);

}

void Ball::move(float multiplier) {
    float a = ofGetHeight();
    if (y < 30.0 | y > a - 30) {
        yVelocity = - yVelocity;
    }

//TODO remove next lines after testing
    if (x > ofGetWidth()-50 ) {
        xVelocity = - xVelocity;
    }

    x = x + xVelocity * multiplier;
    y = y + yVelocity * multiplier;
}

void Ball::reset() {
    x = ofGetHeight()/2 + ofRandom(-100,100);
    y = ofGetWidth()/2 + ofRandom(-100,100);
    xVelocity = -0.5+ofRandom(-1,1);
    yVelocity = ofRandom(-1,1);
    spin = 0;
}
