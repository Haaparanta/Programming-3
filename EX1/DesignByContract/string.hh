#ifndef STRING_HH
#define STRING_HH

#include <vector>

class String
{
public:
  String();
  ~String();

  int length() const;

  void clear();

  String substr(int location, int amount) const;

private:
  std::vector<char> chars_; // Would in reality be implemented e.g. with char* chars_;
  int length_;               // Pidetään kirjaa merkkien määrästä tehokkuussyistä
};

#endif // STRING_HH
