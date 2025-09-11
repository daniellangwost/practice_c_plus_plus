#include <iostream>
#include <optional>
#include "linkedlist.h"

void LinkedList::append(int value)
{
  Node* n = new Node;
  n->value = value;

  if (!head) // empty list
  {
    head = n;
  }
  else
  {
    Node* current = head;
    while (current->next) // iterate to last node
    {
      current = current->next;
    }
    current->next = n;
  }
}

void LinkedList::prepend(int value)
{
  Node* n = new Node;
  n->value = value;
  n->next = head;
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
}

void LinkedList::reverse()
{
  if (!head) return;

  Node* prev = nullptr;
  Node* curr = head;

  while (curr != nullptr)
  {
    Node* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
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
        head = curr->next;
        delete curr;
        return true;
      }
      prev->next = curr->next;
      delete curr;
      return true;
    }
    prev = curr;
    curr = curr->next;
  }
  return false;
}

bool LinkedList::removeIndex(int index)
{
  int curr_index = 0;
  Node* curr = head;
  Node* prev = nullptr;

  if (index < 0 || !head) {return false;}

  if (index == 0)
  {
    head = head->next;
    delete curr;
    return true;
  }

  while (curr)
  {
    if (curr_index == index)
    {
      prev->next = curr->next;
      delete curr;
      return true;
    }
    prev = curr;
    curr = curr->next;
    ++curr_index;
  }
  return false;
}

std::optional<int> LinkedList::getHeadValue() const
{
  if (head) return head->value;
  return std::nullopt;
}