#ifndef BULLET_H
#define BULLET_H

#include "ofMain.h"

class Bullet
{
public:
    float x;
    float y;
    float xVelocity;
    float yVelocity;
    ofColor color;
    bool visible;

    Bullet();

    void draw();
    void move();
    void shoot();

};

#endif // BULLET_H
