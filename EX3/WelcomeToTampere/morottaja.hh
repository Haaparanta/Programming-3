#ifndef MOROTTAJA_HH
#define MOROTTAJA_HH

#include <string>
/**
 * @brief Morottaja Is a Tampere-flavored Hello World -class
 */
class Morottaja
{
public:
    /**
     * @brief Morottaja default constructor
     *
     */
    Morottaja();
    /**
     * @brief morjesta returns a Tampere -flavoured version of "Hello World!".
     * @return "Morjesta Manse!"
     */
    std::string morjesta();
    /**
     * @brief morjesta Does a morotus to a target.
     * @param name The target of morotus
     * @post Increments the amount of morotus' by one
     * @return "Morjesta, <nimi>!"
     */
    std::string morjesta(std::string nimi);
    /**
     * @brief montakoMorotettu tells the amount of morotus given
     * @return the amount of given morotus
     */
    unsigned montakoMorotettu();

private:

    unsigned morotetut;
};

#endif // MOROTTAJA_HH
