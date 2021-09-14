#include "pkg_b.h"
#include "pkg_a.h"

namespace pkg_b {

size_t Class::size(const std::string & package) const
{
  if ("pkg_b" == package) {
    return sizeof(Class);
  }
  if ("pkg_a" == package) {
    return sizeof(pkg_a::Class);
  }
  return 0;
}

const char * Class::constant(const std::string & package) const
{
  if ("pkg_b" == package) {
    return kConstant;
  }
  if ("pkg_a" == package) {
    return pkg_a::kConstant;
  }
  return "";
}

const char * Class::define(const std::string & package) const
{
  if ("pkg_b" == package) {
    return pkg_b_DEFINE;
  }
  if ("pkg_a" == package) {
    return pkg_a_DEFINE;
  }
  return "";
}
}
