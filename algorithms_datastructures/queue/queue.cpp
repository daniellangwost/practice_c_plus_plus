#include <optional>
#include "queue.h"


Queue::Queue()
  : items()
{
}

void Queue::enqueue(int value)
{
  items.append(value);
}

bool Queue::dequeue()
{
  return items.removeHead();
}

std::optional<int> Queue::front() const
{
  return items.getHeadValue();
}

bool Queue::isEmpty() const
{
  if (!items.getHeadValue()) {return true;}
  return false;
}

int Queue::size() const
{
  return items.size();
}