#ifndef FRACTION_HH
#define FRACTION_HH

class Fraction
{
public:
  Fraction(int numerator, int denominator);
  ~Fraction();

  int giveNumerator() const;
  int givedenominator() const;
  double giveAsFloating() const;

  Fraction& operator+=(Fraction f);
  Fraction& operator/=(Fraction f);
// ...

private:
  int numerator_;
  int denominator_;
};

#endif // Fraction_HH
