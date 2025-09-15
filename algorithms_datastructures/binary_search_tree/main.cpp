#include <iostream>
#include "binary_search_tree.h"

int main()
{
  BinarySearchTree t;

  t.insert(5);
  t.insert(12);
  t.insert(13);

  t.level_order_print();

  std::cout << "Done";

}