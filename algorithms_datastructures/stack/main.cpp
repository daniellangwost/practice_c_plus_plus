#include <iostream>
#include "stack.h"

int main()
{
  Stack stack;

  stack.push(4);
  stack.push(7);
  stack.push(100);
  stack.push(33);

  std::cout << stack.size() << "\n";

  auto top = stack.top();
  if (top) std::cout << *stack.top() << "\n";

  stack.pop();
  stack.pop();

  top = stack.top();
  if (top) std::cout << *stack.top() << "\n";

  std::cout << stack.size() << "\n";
  std::cout << stack.isEmpty() << "\n";

  stack.pop();
  stack.pop();

  std::cout << stack.isEmpty() << "\n";
}