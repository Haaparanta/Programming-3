#include "name.hh"
#include <string>
#include <stdexcept>

using namespace std;


Name::Name() : name_(0)
{
    // Empty at the beginning
    name_ = new string;
}

Name::~Name()
{
  delete name_;
}

int Name::forename_length() const
{
  for (unsigned int i = 0; i < name_->length(); ++i )
    {
      if (name_->at(i) == ' ')
        { // Forename ended
          return i;
        }
    }
  // Only a forename
  return name_->length();
}

void Name::change_name(string const& new_name)
{
  delete name_;
  // Make a copy
  name_ = new string(new_name);
}

void Name::remove_familyname()
{
  unsigned int cut = forename_length();
  if (cut == name_->length())
    { // No familyname, cannot remove!
      throw runtime_error("No familyname");
    }
  // Truncating to a forename only
  name_->resize(cut, ' ');
}

void Name::change_familyname(string const& new_name)
{
  remove_familyname();
  name_->push_back(' '); // Add empty space
  name_->append(new_name); // and familyname
}

