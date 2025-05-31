#include <iostream>

int main()
{
  // std::cout << "Enter a number: ";
  // int x{};
  // std::cin >> x;
  // std::cout << "You entered " << x << "\n";

  // std::cout << "Enter two numbers seperated by a space: ";
  // int x{};
  // int y{};
  // std::cin >> x >> y;
  // std::cout << "You entered " << x << " and " << y << "\n";

  // NOTE: std:cin is buffered, int extraction stops at spaces. Inputting two ints when prompted for only 
  //       one will prepare the program for two extractions

  std::cout << "Please enter three values: " << "\n";

  int a{};
  int b{};
  int c{};

  std::cin >> a >> b >> c;

  std::cout << "You entered " << a << ", " << b << ", and " << c << ".\n";

  return 0;
}