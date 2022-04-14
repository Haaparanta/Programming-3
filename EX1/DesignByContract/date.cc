#include "date.hh"
#include <QtDebug>

void Date::setDay(unsigned int day)
{
    Q_ASSERT(1 <= day && day <= 31); // precondition
    invariant();

    if (day > monthLength())
    {
        throw BadDate();
    }

    day_ = day;

    Q_ASSERT(day_ == day); // you don't really write something this simple :)
    invariant();
}

unsigned int Date::monthLength() const
{
    return -1; // return something silly as not implemented
}

void Date::invariant() const
{
    Q_ASSERT(1 <= day_ && day_ <= monthLength() && 1 <= month_ && month_ <= 12 && year_ >= 1754);
}
