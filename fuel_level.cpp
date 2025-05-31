#include <iostream>

int main()
{
  std::cout << "Please enter your fuel level\n";

  double level{};
  std::cin >> level;

  std::cout << "Fuel: " << level << " units\n";
  return 0;
}