#include <iostream>
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

void LinkedList::print()
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
