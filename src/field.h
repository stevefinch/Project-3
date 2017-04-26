#ifndef FIELD_H
#define FIELD_H

#include "ball.h"
#include "paddle.h"

class Field
{
public:
    int height;
    int width;
    float velocityMultiplier;
    int ballsRemaining;
    bool visible;

    Ball *ball;
    Paddle *userPaddle;
    Paddle *computerPaddle;

    Field();

    void draw();
    void update();
};

#endif // FIELD_H
