#include <iostream>

#include "date.hh"
#include "morottaja.hh"

int main()
{
    Date d(1, 2, 2014);
    Morottaja m;
    std::cout << m.morjesta() << std::endl;
    std::cout << d.giveDay() << "." << d.giveMonth() << "." << d.giveYear() << std::endl;
    return 0;
}
