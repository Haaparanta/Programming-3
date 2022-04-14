#include "morottaja.hh"
#include <iostream>
Morottaja::Morottaja():
    morotetut(0)
{

}

std::string Morottaja::morjesta()
{
    return "Morjesta Manse!";
}

std::string Morottaja::morjesta(std::string nimi)
{
    ++morotetut;
    return "Morjesta, " + nimi + "!";
}

unsigned Morottaja::montakoMorotettu()
{
    return morotetut;
}
