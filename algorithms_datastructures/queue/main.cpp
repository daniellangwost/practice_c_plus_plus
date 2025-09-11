#include <iostream>
#include "queue.h"

int main()
{
  Queue q;
  q.enqueue(10);
  q.enqueue(20);
  
  auto front = q.front();
  if (front) {std::cout << *front << "\n";}

  std::cout << q.size() << "\n";
  q.dequeue();

  front = q.front();
  if (front) {std::cout << *front << "\n";}

  std::cout << q.size() << "\n";
  q.dequeue();

  front = q.front();
  if (front) {std::cout << *front << "\n";}

  std::cout << q.size() << "\n";
  std::cout << q.isEmpty() << "\n";
}