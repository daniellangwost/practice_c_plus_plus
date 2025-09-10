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

public:
  void append(int value);
  void prepend(int value);
  void clear();
  void reverse();
  bool remove(int value); // removes first occurence
  bool removeIndex(int index);
  int size() const;
  void print() const;
  std::optional<int> getHeadValue() const;
};

#endif