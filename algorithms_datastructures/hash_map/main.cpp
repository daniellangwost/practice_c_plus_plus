#include <iostream>
#include "hash_map.h"

int main()
{
  HashMap map {10};
  map.insert(5,100);
  map.insert(15,200);
  map.insert(7,20);
  map.insert(-5, 300);

  // trying to find certain key
  // auto value = map.get(10);
  // if (value) std::cout << "Found! Key: 5, Value: " << *value << "\n";
  // else std::cout << "Could not find key\n";

  std::cout << map.remove(3);
  std::cout << map.remove(5) << std::endl;

  map.clear();

  std::cout << "Done";
}