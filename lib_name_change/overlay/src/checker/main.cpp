#include <iostream>
#include <string>

#include "pkg_a.h"
#include "pkg_b.h"

int main(int argc, char ** argv)
{
  std::cout << "Welcome to the overlay checker!\n";

  pkg_a::A a;
  pkg_b::B b;

  std::cout << "A says: " << a.say_something() << "\n";
  std::cout << "B says A says: " << b.what_does_A_say() << "\n";

  return 0;
};
