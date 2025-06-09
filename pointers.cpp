#include <iostream>

int get_fuel();
void print_fuel(int* ptr);


int main()
{
  int fuel = get_fuel();
  int* ptr{&fuel};

  print_fuel(ptr);

  *ptr = 1200;

  print_fuel(ptr);

  ptr = nullptr;

  print_fuel(ptr);
  return 0;
}

int get_fuel()
{
  std::cout << "Please provide fuel level: ";
  int fuel{};
  std::cin >> fuel;
  return fuel;
}

void print_fuel(int* ptr)
{
  if (ptr)
  {
    std::cout << "Fuel: " << *ptr << " units\n";
  }
  else
  {
    std::cout << "No fuel data\n";
  }
}