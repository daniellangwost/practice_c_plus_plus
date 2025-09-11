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
  ~LinkedList();
  void append(int value);
  void prepend(int value);
  void clear();
  void reverse();
  bool remove(int value); // removes first occurence
  int size() const;
  void print() const;
};

#endif