#include <stdio.h>
#include <iostream>

int main()
{
  int speeds[5] {};

  for (int i = 0; i < 5; ++i)
  {
    std::cout << "Please provide Speed " << i+1 << "\n";
    std::cin >> speeds[i];
  }

  int *ptr = speeds;
  for (int i = 0; i < 5; i++)
  {
    std::cout << "Speed " << i+1 << ": " << *ptr << " m/s \n";
    ptr = ptr + 1;
  }

  return 0;
}