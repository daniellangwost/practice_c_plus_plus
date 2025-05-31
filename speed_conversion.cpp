#include <iostream>

int main()
{
  std::cout << "Please enter your speed in km/h\n";

  double speed{};
  std::cin >> speed;
  speed /= 3.6; // conversion factor for km/h -> m/s is used

  std::cout << "Speed: " << speed << " m/s\n";
  return 0;
}