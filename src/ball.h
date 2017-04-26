#ifndef BALL_H
#define BALL_H


class Ball {
public:
    float x;
    float y;
    float xVelocity;
    float yVelocity;
    float spin;

    Ball();

    void draw();
    void move(float);
    void reset();
};

#endif // BALL_H