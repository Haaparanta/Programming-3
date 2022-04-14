#include "fastball.hh"
#include "constants.hh"

#include <QDebug>


FastBall::FastBall():
    MovingObject::MovingObject()
{
    speed_ = randomValue(10, 15);
    dir_x_ = randomValue(-10, 10);
    dir_y_ = randomValue(-10, 10);
    qDebug() << "Constucted FastBall with speed " << speed_ << " direction: "
             << dir_x_ << ", " << dir_y_;


}

void FastBall::move()
{
    int new_x = x_ + dir_x_ * speed_;
    int new_y = y_ + dir_y_ * speed_;

    x_ = std::max(0, std::min(new_x, VIEW_WIDTH));
    y_ = std::max(0, std::min(new_y, VIEW_HEIGHT));

    qDebug() << "New coord: " << x_ << ", " << y_;
}
