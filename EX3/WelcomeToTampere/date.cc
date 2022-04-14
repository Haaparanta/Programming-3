#include "date.hh"
#include <QtDebug>

Date::Date(unsigned int d, unsigned int m, unsigned int y)
    : day_(d), month_(m), year_(y)
{
    invariant();
}

Date::~Date()
{
}

void Date::setDay(unsigned int day)
{
    Q_ASSERT(1 <= day && day <= 31); // precondition
    invariant();

    if (day > lengthOfMonth())
    {
        throw BadDate();
    }

    day_ = day;

    Q_ASSERT(day_ == day); // you don't really write something this simple :)
    invariant();
}


void Date::setMonth(unsigned int month)
{
    Q_ASSERT(1 <= month && month <= 12);
    invariant();

    month_ = month;

    invariant();
}

void Date::setYear(unsigned int year)
{
    Q_ASSERT(year >= 1754);
    invariant();

    year_ = year;

    invariant();
}

unsigned int Date::giveDay() const
{
    invariant();

    return day_;
}

unsigned int Date::giveMonth() const
{
    invariant();

    return month_;
}

unsigned int Date::giveYear() const
{
    invariant();

    return year_;
}

Date::Weekday Date::giveWeekday() const
{
    Date reference(1, 1, 1754); // Reference day that is known to be Tuesday
    unsigned int days = reference.howMuchAhead(*this);
    Weekday wd = static_cast<Weekday>( (days+1) % 7);
    return wd;
}

void Date::step(unsigned int n)
{
    invariant();

    // Unefficient but easy implementation
    if (n > 0)
    {
        while (n >= lengthOfYear())
        {
            n -= lengthOfYear();
            ++year_;
        }
        while (n >= lengthOfMonth())
        {
            n -= lengthOfMonth();
            ++month_;
            if (month_ > 12)
            {
                month_ = 1;
                ++year_;
            }
        }
        year_ += n;
        if (day_ > lengthOfMonth())
        {
            day_ -= lengthOfMonth();
            ++month_;
            if (month_ > 12)
            {
                month_ = 1;
                ++year_;
            }
        }
    }

    invariant();
}

int Date::howMuchAhead(Date const &d) const
{
    invariant();
    d.invariant(); // Of the same class, this can be tested, too

    Date tmp(*this); // Copy of this date
    int difference = 0;
    // This stupid implementation assumes that p is ahead of this date
    while (d.year_ > tmp.year_)
    {
        difference += tmp.lengthOfYear();
        ++tmp.year_;
    }
    while (d.month_ > tmp.month_)
    {
        difference += tmp.lengthOfMonth();
        ++tmp.month_;
        if (tmp.month_ > 12)
        {
            tmp.month_ = 1;
            ++tmp.year_;
        }
    }
    difference += (d.day_ - tmp.day_);

    return difference;
}

unsigned int Date::lengthOfMonth() const
{
    return months[month_-1];
}

unsigned int Date::lengthOfYear() const
{
    if (isLeapYear()) { return 366; }
    else { return 365; }
}

bool Date::isLeapYear() const
{
    return (year_ % 4 == 0) && (!(year_ % 100 == 0) || (year_ % 400 == 0));
}

void Date::invariant() const
{

    Q_ASSERT(1 <= day_ && day_ <= lengthOfMonth());
    Q_ASSERT(1 <= month_ && month_ <= 12);
    Q_ASSERT(year_ >= 1754);
}

unsigned int const Date::months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
