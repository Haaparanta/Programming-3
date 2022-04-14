#include "movingobject.hh"
#include "constants.hh"

#include <cstdlib>
#include <QDebug>

MovingObject::MovingObject():
    x_(randomValue(0, VIEW_WIDTH)),
    y_(randomValue(0, VIEW_HEIGHT))
{
    qDebug() << "MovingObject at " << x_ << ", " << y_;
}


MovingObject::~MovingObject()
{
}


int MovingObject::getX() const
{
    return x_;
}

int MovingObject::getY() const
{
    return y_;
}

int MovingObject::randomValue(int min, int max)
{
    return rand() % (max - min) + min;
}


