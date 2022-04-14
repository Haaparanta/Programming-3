// /// $Id$


#ifndef DATE_HH
#define DATE_HH

class BadDate
{
  // Empty mickey implementation for an exception class to ensure compilation
};

 /*!
 * \version $Id$
 * \file date.hh
 * \brief Definition of a simple date class
 * \author ©2014 Matti Rintala (matti.rintala@tut.fi)
 **/

 /*!
  * \brief Simple date class
  **/
class Date
{
public:

    /*!
    * \brief Constructor initializes the date to a given value
    * \param d Day
    * \param m Month
    * \param y Year
    * \pre 1 <= d <= kpit(m, y) && 1 <= d <= 12 && y >= 1754
    **/
   Date(unsigned int d, unsigned int m, unsigned int y);

    /*!
    * \brief Destructor
    * \pre -
    **/
   ~Date();

    /*!
    * \brief SetDay sets the date
    * \param day New day
    * \pre 1 <= day <= 31
    * \post The day of the date has been set to the parameter value given (month and year do not change)
    * \exception BadDate  Day number too large for month
    */
   void setDay(unsigned int day);

   /*!
   * \brief setMonth sets the month
   * \param month New month
   * \pre 1 <= month <= 12
   * \post The month of the date has been set to the parameter value given (month and year do not change)
   * \exception BadDate  Day number too large for month
   */
  void setMonth(unsigned int month);

   /*!
   * \brief setYear sets the year
   * \param year New year
   * \pre year >= 1754
   * \post The year of the date has been set to the parameter value given (month and year do not change)
   * \exception BadDate  Day number too large for month
   */
  void setYear(unsigned int year);

  /*!
  * \brief giveDay returns the day
  * \return Day of the date
  * \pre -
  */
 unsigned int giveDay() const;

  /*!
  * \brief giveMonth returns the month
  * \return Month of the date
  * \pre -
  */
 unsigned int giveMonth() const;

  /*!
  * \brief giveYear returns the year
  * \return Year of the date
  * \pre -
  */
 unsigned int giveYear() const;

 /*!
 * \brief step moves the date forward/backward
 * \param n how many days to move (negative = backward)
 * \pre -
 * \post Date moved n days forward/backward
 */
void step(int n);

 /*!
 * \brief howMuchAhead tells how many days a given date is ahead of the other
 * \param d Date to compare to
 * \return The difference of the dates in days (positive = d later, negative = d earlier)
 * \pre -
 */
int howMuchAhead(Date const& d) const;

/*!
 * \brief monthLength tells the length of the date
 * \return the length of the month in the date
 */
unsigned int monthLength() const;

private:
  unsigned int day_;    //!< day of the date
  unsigned int month_; //!< month of the date
  unsigned int year_;    //!< year of the date

  /*!
   * \class Date
   * \internal
   * \invariant 1 <= day_ <= month lenght and 1 <= month_ <= 12 and year_ >= 1754
   **/

  /*!
   * \brief tests the class invariant
   */
  void invariant() const;
};


#endif
