#include <iostream>
#include <chrono>
#include <thread>

int main()
{
  int count{};

  do
  {
    std::cout << "Please enter countdown length in seconds\n";
    std::cin >> count;
  }
  while (count <= 0);

  while (count > 0)
  {
    std::cout << count << " seconds to launch\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    --count;
  }
  std::cout << "Liftoff!\n";

}