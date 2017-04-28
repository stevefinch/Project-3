#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "paddle.h"
#include "bullet.h"

class Game
{
public:
    enum {START, GAME, END} screen;
    int height;
    int width;
    float velocityMultiplier;
    int ballsRemaining;
    int bulletsRemaining;
    int score;

    Ball *ball;
    Paddle *userPaddle;
    Paddle *computerPaddle;
    Bullet *bullet;

    Game();

    void draw();
    void update();
};

#endif // GAME_H
