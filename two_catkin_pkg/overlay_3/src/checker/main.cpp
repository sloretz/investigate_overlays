#include <iostream>
#include <string>

#include "pkg_a.h"
#include "pkg_b.h"


template <typename T>
void check_equal(const char * note, T left, T right)
{
  std::cout << "\t" << (left == right ? "OK   " : "ERROR") << " --- ";
  std::cout << note << ": " << left << " == " << right << "\n";
}

int main(int argc, char ** argv)
{
  std::cout << "Welcome to the overlay checker!\n";

  pkg_a::Class a;
  pkg_b::Class b;

  std::cout << "? run time size == build time size ?\n";
  check_equal("A", sizeof(a), a.size("pkg_a"));
  check_equal("B", sizeof(b), b.size("pkg_b"));
  check_equal("A according to B", sizeof(a), b.size("pkg_a"));

  std::cout << "? run time constant == build time constant ?\n";
  check_equal<std::string>("A", pkg_a::kConstant, a.constant("pkg_a"));
  check_equal<std::string>("B", pkg_b::kConstant, b.constant("pkg_b"));
  check_equal<std::string>("A according to B", pkg_a::kConstant, b.constant("pkg_a"));

  std::cout << "? run time define == build time define?\n";
  check_equal<std::string>("A", pkg_a_DEFINE, a.define("pkg_a"));
  check_equal<std::string>("B", pkg_b_DEFINE, b.define("pkg_b"));
  check_equal<std::string>("A according to B", pkg_a_DEFINE, b.define("pkg_a"));
  return 0;
};
