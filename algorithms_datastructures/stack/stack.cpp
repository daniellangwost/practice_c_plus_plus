#include "stack.h"

Stack::Stack()
  : items()
{
}

void Stack::push(int value)
{
  items.prepend(value);
}

bool Stack::pop()
{
  return items.removeIndex(0);
}

std::optional<int> Stack::top() const
{
  auto value = items.getHeadValue();
  if (value) return *value;
  return std::nullopt;
}

bool Stack::isEmpty() const
{
  if (top()) return false;
  return true;
}

int Stack::size() const
{
  return items.size();
}