#include <iostream>

int doubleNumber(int n)
{
  return 2 * n;
}

double convert_speed(double speed)
{
  return speed * (1/3.6);
}

double calculateThrust(double fuel, double efficiency)
{
  return fuel * efficiency;
}

int main()
{
  // std::cout << "Please enter a number: ";
  // int num{};
  // std::cin >> num;
  // std::cout << doubleNumber(num) << '\n';

  // std::cout << "Please enter speed in km/h: ";
  // double speed{};
  // std::cin >> speed;

  // std::cout << "That's " << convert_speed(speed) << " m/s\n";

  std::cout << "Please input fuel and efficiency seperated by a space: ";
  double fuel{};
  double efficiency{};
  std::cin >> fuel >> efficiency;

  std::cout << "Thrust: " << calculateThrust(fuel, efficiency) << " N\n";

}