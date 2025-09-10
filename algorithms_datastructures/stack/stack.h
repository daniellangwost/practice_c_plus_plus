#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"

class Stack
{
private:
  LinkedList items;

public:
  void push(int value);
  bool pop();
  std::optional<int> top() const;
  bool isEmpty() const;
  int size() const;
  Stack();
};

#endif