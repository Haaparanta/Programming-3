#ifndef BADDATE_HH
#define BADDATE_HH
#include <exception>

/**
 * @file
 * @brief Defines exception class for errors occuring in data format.
 */

/**
 * @brief Exception class for bad date setting.
 */
class BadDate : public std::exception
{
public:
    /**
     * @brief Constructor
     */
    BadDate();
};

#endif // BADDATE_HH
