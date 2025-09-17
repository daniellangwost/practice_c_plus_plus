#ifndef HEAP_H
#define HEAP_H
#include <vector>

class Heap
{
private:
  std::vector<int> m_elements{};

public:
  void insert(int value);
  int extractMin();
  int getMin();
  bool isEmpty();
  int size();
};

#endif