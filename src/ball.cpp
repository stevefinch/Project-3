#include "ball.h"
#include "ofApp.h"

Ball::Ball() {
    this->reset();

}

void Ball::draw() {
    ofSetColor(64,128,64);
    ofFill();
    ofDrawCircle(position.x,position.y,15);

}

void Ball::move(float multiplier) {
    position = position + velocity * multiplier;

}

void Ball::reset() {

    position.set( (0.5 + ofRandom(-0.25, 0.25) )* ofGetWidth(),
                  (0.5 + ofRandom(-0.25, 0.25) )* ofGetHeight() );

    velocity.set(-1.0+ofRandom(-0.5, 0.5), ofRandom(-0.5, 0.5));

}

bool Ball::paddleHit(Paddle *paddle) {

    return (position.y > paddle->position.y) && (position.y < paddle->position.y + 80);

}
