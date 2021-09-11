#ifndef pkg_b__pkg_b_H_
#define pkg_b__pkg_b_H_

#include <cstddef>
#include <string>

namespace pkg_b {

const char * const kConstant = "overlay_pkg_b";

#define pkg_b_DEFINE "overlay_pkg_b"

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

#endif  // pkg_b__pkg_b_H_
