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
