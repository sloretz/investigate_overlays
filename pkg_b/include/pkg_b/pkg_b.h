#ifndef PKG_B__PKG_B_H_
#define PKG_B__PKG_B_H_

#include <cstddef>

#define PKG_B_WORKSPACE "underlay"

class PkgB
{
public:
  size_t size_at_build_time() const;
  const char * workspace_at_build_time() const;

  size_t pkg_a_size_at_build_time() const;
  const char * pkg_a_workspace_at_build_time() const;

private:
  char stuff[16];
};

#endif  // PKG_B__PKG_B_H_
