#include <iostream>
#include <optional>
#include "linkedlist.h"

LinkedList::~LinkedList()
{
  clear();
}

void LinkedList::append(int value)
{
  Node* n = new Node;
  n->value = value;


  if (!head) // empty list
  {
    head = n;
    tail = n;
  }
  else
  {
    tail->next = n;
    tail = tail->next;
  }
}

void LinkedList::prepend(int value)
{
  Node* n = new Node;
  n->value = value;
  n->next = head;
  if (!head) {tail = n;}
  head = n;
}

void LinkedList::print() const
{
  Node* current = head;
  while (current)
  {
    std::cout << current->value;
    current = current->next;
    if (current) {std::cout << " -> ";}
  }
  std::cout << "\n";
}

void LinkedList::clear()
{
  Node* current = head;
  while (current)
  {
    Node* temp = current;
    current = current->next;
    delete temp;
  }
  head = nullptr;
  tail = nullptr;
}

int LinkedList::size() const
{
  int count { 0 };
  Node* curr = head;
  while (curr)
  {
    curr = curr->next;
    ++count;
  }
  return count;
}

bool LinkedList::remove(int value) // removes first occurence of value
{
  Node* prev = nullptr;
  Node* curr = head;
  while (curr)
  {
    if (curr->value == value)
    {
      if (!prev) // value is at head
      {
        if (tail == head) {tail = nullptr;}
        head = curr->next;
        delete curr;
        return true;
      }
      prev->next = curr->next;

      if (curr == tail) {tail = prev;}

      delete curr;
      return true;
    }
    prev = curr;
    curr = curr->next;
  }
  return false;
}

bool LinkedList::removeHead()
{
  if (!head) {return false;}
  if (head == tail)
  {
    delete head;
    head = nullptr;
    tail = nullptr;
    return true;
  }
  
  Node* next = head->next;
  delete head;
  head = next;
  return true;
}

std::optional<int> LinkedList::getHeadValue() const
{
  if (head) return head->value;
  return std::nullopt;
}
