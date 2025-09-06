#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

struct Node
{
  int key{};
  int value{};
  Node* next{nullptr};
};

class LinkedList
{
  Node* head{nullptr};

public:
  void append(int key, int value);
  void prepend(int key, int value);
  void clear();
  void reverse();
  bool remove(int key); // removes first occurence
  int size() const;
  void print() const;
  Node* find(int key) const;
};

#endif