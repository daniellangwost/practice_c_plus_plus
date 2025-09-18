#include <iostream>
#include "heap.h"

int main()
{
  Heap h;
  h.insert(1);
  h.insert(2);
  h.insert(2);
  h.insert(5);
  h.insert(9);
  h.insert(8);

  std::cout << h.extractMin() << std::endl;
  std::cout << h.extractMin() << std::endl;
  std::cout << h.extractMin() << std::endl;
  std::cout << h.extractMin() << std::endl;
  std::cout << h.extractMin() << std::endl;
  std::cout << h.extractMin() << std::endl;
  std::cout << h.extractMin() << std::endl;

  std::cout << "Done";
}