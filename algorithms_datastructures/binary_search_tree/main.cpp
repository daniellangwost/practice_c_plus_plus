#include <iostream>
#include "binary_search_tree.h"

int main()
{
  BinarySearchTree t;
  t.insert(4);

  t.insert(6);
  t.insert(2);

  t.insert(3);
  t.insert(5);
  t.insert(7);
  t.insert(1);

  std::cout << t.search(1) << "\n";
  std::cout << t.search(2) << "\n";
  std::cout << t.search(3) << "\n";
  std::cout << t.search(4) << "\n";
  std::cout << t.search(5) << "\n";
  std::cout << t.search(6) << "\n";
  std::cout << t.search(7) << "\n";
  std::cout << t.search(8) << "\n";
  std::cout << t.search(-1) << "\n";
  std::cout << t.search(100) << "\n";
  std::cout << "Done";
}