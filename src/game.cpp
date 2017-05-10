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

    velocityMultiplier = 2.0;
    logo.load("/home/steve/logo.png");
    screen = START;


}

void Game::update() {
    if (screen == GAME) {

        // Update Paddle positions
        if (! computerPaddle->paddleFrozen && ball->velocity.x > 0)
            if (ball->position.y < computerPaddle->position.y+40)
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
        if (ball->position.y < 30.0 || ball->position.y > ofGetHeight() - 30)
            ball->velocity.y = - ball->velocity.y;

        // Check Ball collision with user paddle
        if (ball->position.x < 50) {
            if (ball->paddleHit(userPaddle)) {
                ball->velocity.set(-ball->velocity.x, ball->velocity.y - (userPaddle->position.y - ball->position.y + 40)/40 );

                ++score;
            }
            else {
                ball->reset();
                --ballsRemaining;
                velocityMultiplier = 2.0;
                score = 0;
            }
        }

        // Check Ball collision with computer paddle
        if (ball->position.x > ofGetWidth() -50) {
            if (ball->paddleHit(computerPaddle)) {
                ball->velocity.set(-ball->velocity.x, ball->velocity.y - (computerPaddle->position.y - ball->position.y + 40)/40 );
            }
            else {
                score += 100;
                ball->reset();
                velocityMultiplier = 2.0;
            }
        }

         // Check Bullet collision with computer paddle
        if (bullet->visible && bullet->x > 1000) {
            bullet->visible = false;
            --bulletsRemaining;
            if ( (bullet->y > userPaddle->position.y) && (bullet->y < userPaddle->position.y + 80) ) { // hit
                computerPaddle->paddleFrozen = true;
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

            logo.draw(100,100);
            ofDrawBitmapString("High Score: " + to_string(highScore), ofGetWidth()/2, 50);

        }
        else if (screen == GAME) {
            ofSetColor(255,255,255);
            ofFill();
            ofDrawRectangle(10,10,width,height);

            ball->draw();
            userPaddle->draw();
            computerPaddle->draw();
            bullet->draw();

            ofDrawBitmapString("Score: " + to_string(score), ofGetWidth()/2, 50);
        }
        else if (screen == END) {
            ofSetColor(0,0,255);
            ofFill();
            ofDrawRectangle(10,10,width,height);

            if (score > highScore) {
                ofBuffer buff;
                buff.set(to_string(score));
                ofBufferToFile("/home/steve/score.txt", buff);

            }
        }

}

