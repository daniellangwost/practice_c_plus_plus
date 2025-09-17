#include <iostream>
#include <cmath>
#include "heap.h"

void Heap::insert(int value)
{
  m_elements.push_back(value);

  if (m_elements.size() == 1) return;

  size_t index = static_cast<size_t>(m_elements.size()) - 1;
  size_t parent_index = (index - 1 ) / 2; // NOTE: intentional floor division

  while (value < m_elements[parent_index])
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

  size_t index = 0;
  size_t child_index = m_elements[1] < m_elements[2] ? 1 : 2;

  while (m_elements[index] > m_elements[child_index])
  {
    std::swap(m_elements[index], m_elements[child_index]);

    // TODO

  }
  return min;
}

int Heap::getMin()
{
  if (m_elements.size() == 0) throw std::runtime_error("Min-Heap is empty!");
  return m_elements[0];
}

bool Heap::isEmpty()
{
  return m_elements.size() == 0;
}

int Heap::size()
{
  return m_elements.size();
}

