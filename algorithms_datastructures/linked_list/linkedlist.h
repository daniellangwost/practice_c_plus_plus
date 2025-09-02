#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node
{
  int value{};
  Node* next{nullptr};
};

class LinkedList
{
  Node* head{nullptr};

public:
  void append(int value);
  void prepend(int value);
  void print();
};

#endif