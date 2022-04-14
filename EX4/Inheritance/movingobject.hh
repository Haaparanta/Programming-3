#ifndef MOVINGOBJECT_HH
#define MOVINGOBJECT_HH


class MovingObject
{
public:
    MovingObject();
    ~MovingObject();

    virtual void move() = 0;

    int getX() const;
    int getY() const;

protected:
    int randomValue(int min, int max);

    int x_;
    int y_;

};

#endif // MOVINGOBJECT_HH
