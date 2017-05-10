#ifndef PADDLE_H
#define PADDLE_H

#include "ofMain.h"

class Paddle
{
public:
    ofVec2f position;
    bool paddleFrozen;

    Paddle();
    Paddle(int x, int y);

    void draw();
    void moveup(int);
    void movedown(int);
};

#endif // PADDLE_H
