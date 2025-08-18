#include <vector>
#include <stdio.h>
#include <iostream>

int main()
{
  std::vector squares{1, 4, 9, 16, 25};
  std::vector<double> temperatures (365);

  std::vector<int> nums (3);
  std::cout << "Enter three integers 3";

  std::cin >> nums[0] >> nums[1] >> nums[2];

  std::cout << "The sum is: " << nums[0] + nums[1] + nums[2] << "\n";
  std::cout << "The product is: " << nums[0] * nums[1] * nums[2] << "\n";


}