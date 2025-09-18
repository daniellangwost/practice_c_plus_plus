#ifndef HEAP_H
#define HEAP_H
#include <vector>

class Heap
{
private:
  std::vector<int> m_elements{};
  void heapifyDown(size_t index);

public:
  void insert(int value);
  int extractMin();
  int getMin() const;
  bool isEmpty() const;
  int size() const;
};

#endif