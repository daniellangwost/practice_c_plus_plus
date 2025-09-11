#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"

class Queue
{
private:
  LinkedList items;

public:
  Queue();
  void enqueue(int value);
  bool dequeue();
  std::optional<int> front() const;
  bool isEmpty() const;
  int size() const;
};

#endif