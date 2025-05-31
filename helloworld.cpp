#include <iostream>

int main()
{
  // std::cout << "hello, rocket!" << std::endl;
  // std::cout << "this is on a second line" << std::endl;

  // NOTE: Prefer \n to std::endl because the latter flushes the buffer

  int x { 5 };
  std::cout << "x is equal to: " << x << '\n';
  std::cout << "Yep." << "\n";
  std::cout << "And that's all, folks!\n";

  return 0;
}