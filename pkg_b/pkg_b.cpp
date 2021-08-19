#include "pkg_a/pkg_a.h"
#include "pkg_b/pkg_b.h"

size_t PkgB::size_at_build_time() const
{
  return sizeof(PkgB);
};

const char * PkgB::workspace_at_build_time() const
{
  return PKG_B_WORKSPACE;
};


size_t PkgB::pkg_a_size_at_build_time() const
{
  return sizeof(PkgA);
}

const char * PkgB::pkg_a_workspace_at_build_time() const
{
  return PKG_B_WORKSPACE;
}
