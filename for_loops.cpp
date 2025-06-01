#include <iostream>

int sumTo(int value)
{
  int sum{ 0 };
  for (int i{ 1 }; i <= value; ++i)
  {
    sum += i;
  }
  return sum;
}

void fizzbuzz(int num)
{
  for (int i{ 1 }; i <= num; ++i)
  {
    if (i % 3 == 0 && i % 5 == 0)
      std::cout << "fizzbuzz\n";

    else if (i % 3 == 0)
      std::cout << "fizz\n"; 

    else if (i % 5 == 0)
      std::cout << "buzz\n";

    else std::cout << i << '\n';
  }
}

void fizzbuzzpop(int num)
{
  for (int i{ 0 }; i <= num; ++i)
  {
    bool printed = false;
    if (i % 3 == 0)
    {
      std::cout << "fizz";
      printed = true;
    }

    if (i % 5 == 0)
    {
      std::cout << "buzz";
      printed = true;
    }

    if (i % 7 == 0)
    {
      std::cout << "pop";
      printed = true;
    }

    if (!printed)
      std::cout << i;
    std::cout << '\n';
  }
}

int main()
{
  // for (int i{ 0 }; i <= 20; ++i)
  // {
  //   std::cout << i << ' ';
  // }
  // std::cout << '\n';

  // std::cout << sumTo(5) << '\n';

  // fizzbuzz(15);

  fizzbuzzpop(150);

  return 0;
}