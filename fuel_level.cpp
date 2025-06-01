#include <iostream>

int main()
{
  std::cout << "Please enter your fuel level\n";

  double level{};
  std::cin >> level;

  if (level > 50) std::cout << "Ready to launch\n";
  else std::cout << "Low fuel\n";

  for (int i{ 1 }; i <= 3; ++i)
  {
    std::cout << "Checking system: " << i << "\n";
  }
  return 0;
}