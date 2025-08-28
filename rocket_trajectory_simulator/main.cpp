#include <iostream>
#include <limits>
#include <vector>
#include <fstream>
#include "rocket.h"
#include "main.h"

int main()
{
  const double MAX_VELOCITY { 10'000 };
  const double MAX_ALTITUDE { 100'000 };

  double angle{ get_positive_number(90, "angle", "degrees") };
  double velocity{ get_positive_number(MAX_VELOCITY, "velocity", "m/s") };
  double target_altitude { get_positive_number(MAX_ALTITUDE, "altitude", "m")};

  Rocket rocket(0, 0, velocity, angle, target_altitude); // instantiate rocket
  std::vector<std::pair<double, double>> data {};
  
  constexpr double TIMESTEP {0.1};
  int iterations { 1000 };

  for (int i{0}; i < iterations; ++i)
  {
    data.push_back(rocket.log()); // log data
    rocket.update(TIMESTEP); // update rocket object
    if (rocket.get_y() < 0) // stop calculation when rocket hits ground
    {
      break;
    }

    if (i % 10 == 0)
    {
      int remaining_iterations {iterations - i};
      int remaining_corrections {remaining_iterations / 10};

      rocket.adjust_guidance(remaining_corrections);
    }
  }
  write_data(data);
}

double get_positive_number(double upper, std::string name, std::string unit)
{
  double number{};
  std::cout << "Please enter a positive " << name << " up to " << upper << " " << unit << " \n";
  while (!(std::cin >> number) || number <= 0 || number > upper)
  {
    std::cout << "Invalid input, try again!\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return number;
}

void write_data(std::vector<std::pair<double, double>>& data)
{
  std::ofstream file;
  file.open("data.csv");

  if (!file)
  {
    std::cerr << "Error opening file\n";
  }

  file << "x,y\n";

  for (auto& pos : data)
  {
    file << pos.first << "," << pos.second << "\n"; 
  }

}