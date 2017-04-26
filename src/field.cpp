#include "field.h"
#include "ofApp.h"

Field::Field() {
    visible = True;
    height = ofGetHeight()-20;
    width = ofGetWidth()-20;

    ball = new Ball();
    ballsRemaining =2;

    userPaddle = new Paddle(30,height/2-80);
    computerPaddle = new Paddle(width - 20,height/2-80);

    velocityMultiplier = 1.0;
}

void Field::draw() {
    if ( visible) {
        ofSetColor(255,255,255);
        ofFill();
        ofDrawRectangle(10,10,width,height);

        ball->draw();
        userPaddle->draw();
        computerPaddle->draw();
    }

}

void Field::update() {
    if (! computerPaddle->paddleFrozen & ball->xVelocity > 0)
        if (ball->y < computerPaddle->y+40)
            computerPaddle->moveup();
        else
            computerPaddle->movedown();

    if(ofGetKeyPressed(OF_KEY_UP))
        userPaddle->moveup();
    else if(ofGetKeyPressed(OF_KEY_DOWN))
        userPaddle->movedown();

    if (ball->x < 50) {
        if ( (ball->y > userPaddle->y) & (ball->y < userPaddle->y + 80) ) {
            ball->xVelocity = - ball->xVelocity;//hit paddle TODO add score
        }
        else {
            velocityMultiplier = 1.0;
            ball->reset();
            --ballsRemaining;

        }
    }

    velocityMultiplier *= 1.001;
    ball->move(velocityMultiplier);



}

