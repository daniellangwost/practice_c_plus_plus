#include <iostream>
#include "binary_search_tree.h"

int main()
{
  BinarySearchTree t;

  t.insert(8);
  t.insert(3);
  t.insert(10);
  t.insert(1);
  t.insert(6);
  t.insert(14);
  t.insert(4);
  t.insert(7);
  t.insert(13);


  t.ordered_print();
  t.pre_order_print();
  t.post_order_print();

  std::cout << "Done";

}