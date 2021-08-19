#include <iostream>
#include <string>

#include "pkg_a/pkg_a.h"
#include "pkg_b/pkg_b.h"


template <typename T>
void check_equal(const char * note, T left, T right)
{
  std::cout << "\t" << (left == right ? "OK   " : "ERROR") << " --- ";
  std::cout << note << ": " << left << " == " << right << "\n";
}

int main(int argc, char ** argv)
{
  std::cout << "Welcome to the overlay checker!\n";

  PkgA a;
  PkgB b;

  std::cout << "? run time size == build time size ?\n";
  check_equal("A", sizeof(a), a.size_at_build_time());
  check_equal("B", sizeof(b), b.size_at_build_time());
  check_equal("A according to B", sizeof(a), b.pkg_a_size_at_build_time());

  std::cout << "? run time header == build time header ?\n";
  check_equal<std::string>("A", PKG_A_WORKSPACE, a.workspace_at_build_time());
  check_equal<std::string>("B", PKG_B_WORKSPACE, b.workspace_at_build_time());
  check_equal<std::string>("A according to B", PKG_A_WORKSPACE, b.pkg_a_workspace_at_build_time());

  return 0;
};
