#include "ball.h"
#include "ofApp.h"

Ball::Ball() {
    this->reset();

}

void Ball::draw() {
    ofSetColor(64,128,64);
    ofFill();
//    ofDrawCircle(x,y,15);
    ofDrawCircle(position.x,position.y,15);

}

void Ball::move(float multiplier) {
//    x = x + xVelocity * multiplier;
//    y = y + yVelocity * multiplier;
    position = position + velocity;

}

void Ball::reset() {
    ofVec2f rand;
//    x = (0.5 + ofRandom(-0.25, 0.25))* ofGetHeight();
//    y = (0.5 + ofRandom(-0.25, 0.25))* ofGetWidth();
//    xVelocity = -1.0+ofRandom(-0.5, 0.5);
//    yVelocity = ofRandom(-0.5, 0.5);

    position.set( (0.5 + ofRandom(-0.25, 0.25) )* ofGetWidth(),
                  (0.5 + ofRandom(-0.25, 0.25) )* ofGetHeight() );

    velocity.set(-1.0+ofRandom(-0.5, 0.5), ofRandom(-0.5, 0.5));

}

bool Ball::paddleHit(Paddle *paddle) {
    bool hit = False;

    if (position.x < paddle->x) {
        if ( (position.y > paddle->y) && (position.y < paddle->y + 80) ) { // hit
//            xVelocity = -xVelocity;
//            yVelocity -= (paddle->y - y + 40)/40; //offcenter paddle hit
            velocity.set(-velocity.x, (paddle->y - position.y + 40)/40 );
            hit = True;
        }
    }

    return hit;

}
