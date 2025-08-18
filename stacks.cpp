#include <iostream>
#include <vector>

int main()
{
	std::vector<double> speeds;
  speeds.reserve(3);
  speeds.push_back(500.5);
  speeds.push_back(600.0);
  speeds.push_back(700.5);

  for (size_t i{0}; i < speeds.size(); ++i)
  {
    std::cout << "Speed " << i+1 << ": " << speeds[i] << "\n";
  }

  return 0;
}