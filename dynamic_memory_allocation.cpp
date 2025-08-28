#include <iostream>

int main()
{
  size_t count {};
  std::cout << "How many values do you want to enter? ";
  std::cin >> count;

  double* values { new double[count]{} };

  std::cout << "Enter your values, seperated by spaces ";

  for (size_t i = 0; i < count; ++i)
  {
    std::cin >> values[i];
  }

  double *ptr = values;

  for (size_t i = 0; i < count; ++i)
  {
    std::cout << *(ptr + i);
  }

  delete[] values;
  return 0;
}