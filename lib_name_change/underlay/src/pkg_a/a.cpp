#include "pkg_a.h"

namespace pkg_a {
std::string A::say_something() const
{
  return "I'm the underlay version of say_something()";
}
}
