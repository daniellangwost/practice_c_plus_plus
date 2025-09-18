#include <iostream>
#include <cmath>
#include "heap.h"

void Heap::insert(int value)
{
  m_elements.push_back(value);

  if (m_elements.size() == 1) return;

  size_t index = static_cast<size_t>(m_elements.size()) - 1;
  size_t parent_index = (index - 1 ) / 2; // NOTE: intentional floor division

  while (index > 0 && m_elements[index] < m_elements[parent_index])
  {
    std::swap(m_elements[index], m_elements[parent_index]);
    index = parent_index;
    parent_index = (index - 1 ) / 2;
  }
}

int Heap::extractMin()
{
  if (m_elements.size() == 0) throw std::runtime_error("Min-Heap is empty!");

  int min = m_elements[0];
  m_elements[0] = m_elements[static_cast<size_t>(m_elements.size()) - 1];
  m_elements.pop_back();
  
  if (!isEmpty()) heapifyDown(0);
  return min;
}

int Heap::getMin() const
{
  if (m_elements.size() == 0) throw std::runtime_error("Min-Heap is empty!");
  return m_elements[0];
}

bool Heap::isEmpty() const
{
  return m_elements.size() == 0;
}

int Heap::size() const
{
  return static_cast<int>(m_elements.size());
}

void Heap::heapifyDown(size_t index)
{
  size_t length = static_cast<size_t>(size());
  size_t left = index * 2 + 1;
  size_t right = index * 2 + 2;
  size_t smallest{};

  while (true)
  {
    if (left >= length) return;
    
    if (right >= length) smallest = left;
    else smallest = m_elements[left] <= m_elements[right] ? left : right;


    if (m_elements[smallest] < m_elements[index])
    {
      std::swap(m_elements[index], m_elements[smallest]);
      index = smallest;
      left = index * 2 + 1;
      right = index * 2 + 2;
    }
    else break;
  }
}