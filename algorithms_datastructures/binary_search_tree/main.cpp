#include <iostream>
#include "binary_search_tree.h"

int main()
{
  BinarySearchTree t;

  t.insert(10);
  t.insert(40);
  t.insert(30);
  t.insert(25);

  std::cout << t.remove(30);
  std::cout << t.remove(10);
  std::cout << t.remove(25);
  std::cout << t.remove(40);

  std::cout << "Done";
  
}