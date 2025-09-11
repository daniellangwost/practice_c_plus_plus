#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <optional>

struct Node
{
  int value{};
  Node* next{nullptr};
};

class LinkedList
{
  Node* head{nullptr};
  Node* tail{nullptr};

public:
  void append(int value);
  void prepend(int value);
  void clear();
  bool remove(int value); // removes first occurence
  bool removeHead();
  int size() const;
  void print() const;
  std::optional<int> getHeadValue() const;
};

#endif