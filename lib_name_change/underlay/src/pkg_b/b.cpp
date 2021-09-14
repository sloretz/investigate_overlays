#include "pkg_b.h"
#include "pkg_a.h"

namespace pkg_b {
std::string B::what_does_A_say() const
{
  return pkg_a::A().say_something();
}
}
