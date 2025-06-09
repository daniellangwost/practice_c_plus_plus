#include <iostream>

int readNumber()
{
  std::cout << "Please provide a number: ";
  int n{};
  std::cin >> n;
  return n;
}

void writeAnswer(int n)
{
  std::cout << n << "\n";
}