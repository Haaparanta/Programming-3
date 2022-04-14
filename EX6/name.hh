#include <string>
#include <stdexcept>

using namespace std;

class Name
{
public:
  Name();
  ~Name();
  int forename_length() const;
  void change_name(string const& new_name);
  void remove_familyname();
  void change_familyname(string const& new_name);

private:
  string* name_;
};
