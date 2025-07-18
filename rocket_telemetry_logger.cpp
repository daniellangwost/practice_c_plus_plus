#include <stdio.h>
#include <iostream>

int main()
{
  int speeds[5] {};

  for (int i = 0; i < 5; i++)
  {
    std::cout << "Please provide Speed " << i+1 << ": \n";
    std::cin >> speeds[i];
  }

  int *ptr = speeds;
  int sum = 0;

  for (int i = 0; i < 5; i++)
  {
    sum += *ptr;
    if (*ptr > 1000)
    {
    std::cout << "Received DANGEROUS speed: " << *ptr << " m/s at t=" << i+1 << "\n";
    }
    else
    {
    std::cout << "Received speed: " << *ptr << " m/s at t=" << i+1 << "\n";
    }
    ++ptr;
  }

  std::cout << "Average speed was: " << sum/5 << " m/s";

}