#ifndef BALL_H
#define BALL_H

#include "paddle.h"
#include "ofMain.h"

class Ball {

public:
    ofVec2f position;
    ofVec2f velocity;

    Ball();

    void draw();
    void move(float);
    void reset();
    bool paddleHit(Paddle *);

};

#endif // BALL_H
