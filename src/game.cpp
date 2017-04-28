#include "game.h"
#include "ofApp.h"

//TODO make hard coded numbers into consts
Game::Game() {
    height = ofGetHeight()-20;
    width = ofGetWidth()-20;

    score = 0;

    ball = new Ball();
    ballsRemaining = 2;

    bullet = new Bullet();
    //TODO after testing make starting bullets = 0
    bulletsRemaining = 5;

    userPaddle = new Paddle(30,height/2-80);
    computerPaddle = new Paddle(width - 20,height/2-80);

    velocityMultiplier = 1.0;
    screen = START;

}

void Game::update() {
    if (screen == GAME) {

        // Update Paddle positions
        if (! computerPaddle->paddleFrozen && ball->xVelocity > 0)
            if (ball->y < computerPaddle->y+40)
                computerPaddle->moveup(10);
            else
                computerPaddle->movedown(height-70);

        if(ofGetKeyPressed(OF_KEY_UP))
            userPaddle->moveup(10);
        else if(ofGetKeyPressed(OF_KEY_DOWN))
            userPaddle->movedown(height-70);
        else if(ofGetKeyPressed(OF_KEY_RIGHT))
            if (bulletsRemaining > 0 && !bullet->visible)
                bullet->shoot();

        // Check Ball collision with top or bottom
        if (ball->y < 30.0 | ball->y > ofGetHeight() - 30)
            ball->yVelocity = - ball->yVelocity;

        // Check Ball collision with user paddle
        if (ball->x < 50) {
            if ( (ball->y > userPaddle->y) && (ball->y < userPaddle->y + 80) ) { // hit
                ball->xVelocity = - ball->xVelocity;
                ball->yVelocity -= (userPaddle->y - ball->y + 40)/40; //offcenter paddle hit
                ++score;
            }
            else { // miss
                velocityMultiplier = 1.0;
                ball->reset();
                --ballsRemaining;

            }
        }

        // Check Ball collision with computer paddle
// TODO
//        if (ball->x < 50) {
//            if ( (ball->y > userPaddle->y) && (ball->y < userPaddle->y + 80) ) { // hit
//                ball->xVelocity = - ball->xVelocity;
//                ball->yVelocity -= (userPaddle->y - ball->y + 40)/40; //offcenter paddle hit
//                ++score;
//            }
//            else { // miss
//                velocityMultiplier = 1.0;
//                ball->reset();
//                --ballsRemaining;

//            }
//        }

        //TODO remove next lines after testing
            if (ball->x > ofGetWidth()-50 ) {
                ball->xVelocity = - ball->xVelocity;
            }
        //TODO end remove

         // Check Bullet collision with computer paddle
        if (bullet->visible && bullet->x > 1000) {
            bullet->visible = False;
            --bulletsRemaining;
            if ( (bullet->y > userPaddle->y) && (bullet->y < userPaddle->y + 80) ) { // hit
                computerPaddle->paddleFrozen = True;
            }
            else { // miss


            }
        }
        velocityMultiplier *= 1.0005;

        ball->move(velocityMultiplier);

        if (bullet->visible)
            bullet->move();
    }

}


void Game::draw() {
        if (screen == START) {
            ofSetColor(255,255,255);
            ofFill();
            ofDrawRectangle(10,10,width,height);

            ofSetColor(128,128,128);
            ofFill();
            ofDrawRectangle(width/2,height/2,100,100);
        }
        else if (screen == GAME) {
            ofSetColor(255,255,255);
            ofFill();
            ofDrawRectangle(10,10,width,height);

            ball->draw();
            userPaddle->draw();
            computerPaddle->draw();
            bullet->draw();
        }
        else if (screen = END) {
            ofSetColor(0,0,255);
            ofFill();
            ofDrawRectangle(10,10,width,height);
        }

}

