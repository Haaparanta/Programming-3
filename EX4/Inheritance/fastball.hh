#ifndef FASTBALL_HH
#define FASTBALL_HH

#include "movingobject.hh"


class FastBall : public MovingObject
{
public:
    FastBall();

    void move() final;

private:
    int speed_;
    int dir_x_;
    int dir_y_;
};

#endif // FASTBALL_HH
