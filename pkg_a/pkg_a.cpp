#include "pkg_a/pkg_a.h"

size_t PkgA::size_at_build_time() const
{
  return sizeof(PkgA);
};

const char * PkgA::workspace_at_build_time() const
{
  return PKG_A_WORKSPACE;
};
