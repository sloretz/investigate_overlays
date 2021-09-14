#include <iostream>
#include <string>

#include "pkg_a.h"

int main(int argc, char ** argv)
{
  std::cout << "Welcome to the overlay checker!\n";

  pkg_a::A a;

  std::cout << "A says: " << a.say_something() << "\n";

  return 0;
};

