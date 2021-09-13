#ifndef pkg_a__pkg_a_H_
#define pkg_a__pkg_a_H_

#include <cstddef>
#include <string>

namespace pkg_a {

const char * const kConstant = "overlay_3_pkg_a_constant";

#define pkg_a_DEFINE "overlay_3_pkg_a_define"

class Class
{
public:
  size_t size(const std::string & package) const;
  const char * constant(const std::string & package) const;
  const char * define(const std::string & package) const;

private:
  char stuff[64];
};
}

#endif  // pkg_a__pkg_a_H_
