#ifndef BALL_H
#define BALL_H


class Ball
{
public:
    int x;
    int y;
    int xVelocity;
    int yVelocity;

    Ball();    
    Ball(int x, int y, int xVelocity, int yVelocity);
};

#endif // BALL_H
