#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <vector>
#include <optional>
#include "linkedlist.h"

class HashMap
{
private:
  int m_length{};
  std::vector<LinkedList> m_buckets;

public:
  HashMap(int length);
  void insert(int key, int value);
  int hash(int key);
  std::optional<int> get(int key);
  bool remove(int key); // remove first pair with key occurence
  void clear();
};

#endif