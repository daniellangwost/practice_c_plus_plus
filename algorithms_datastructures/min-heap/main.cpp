#include <iostream>
#include "heap.h"

int main()
{
  Heap h;
  h.insert(2);
  h.insert(3);
  h.insert(10);
  h.insert(4);
  h.insert(5);
  h.insert(1);

  std::cout << h.extractMin() << std::endl;

  std::cout << "Done";
}