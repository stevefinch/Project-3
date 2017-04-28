#ifndef PADDLE_H
#define PADDLE_H

class Paddle
{
public:
    int x;
    int y;
    bool paddleFrozen;

    Paddle();
    Paddle(int x, int y);

    void draw();
    void moveup(int);
    void movedown(int);
};

#endif // PADDLE_H
