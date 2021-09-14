#include "pkg_a.h"

namespace pkg_a {
std::string A::say_something() const
{
  return "I'm the overlay version of say_something()";
}
}
