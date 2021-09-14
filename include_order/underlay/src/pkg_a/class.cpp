#include "pkg_a.h"

namespace pkg_a {
size_t Class::size(const std::string & package) const
{
  if ("pkg_a" == package) {
    return sizeof(Class);
  }
  return 0;
}

const char * Class::constant(const std::string & package) const
{
  if ("pkg_a" == package) {
    return kConstant;
  }
  return "";
}

const char * Class::define(const std::string & package) const
{
  if ("pkg_a" == package) {
    return pkg_a_DEFINE;
  }
  return "";
}
}
