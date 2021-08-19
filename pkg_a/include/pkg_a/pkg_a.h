#ifndef PKG_A__PKG_A_H_
#define PKG_A__PKG_A_H_

#include <cstddef>

#define PKG_A_WORKSPACE "underlay"

class PkgA
{
public:
  size_t size_at_build_time() const;

  const char * workspace_at_build_time() const;

private:
  char stuff[16];
};

#endif  // PKG_A__PKG_A_H_
