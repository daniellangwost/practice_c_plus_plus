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
  std::cout << "Hi";
}