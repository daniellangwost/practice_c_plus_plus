#include <iostream>
#include "linkedlist.h"

void LinkedList::append(int key, int value)
{
  Node* n = new Node;
  n->key = key;
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

void LinkedList::prepend(int key, int value)
{
  Node* n = new Node;
  n->key = key;
  n->value = value;
  n->next = head;
  head = n;
}

void LinkedList::print() const
{
  Node* current = head;
  while (current)
  {
    std::cout << current->key << ": ";
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

bool LinkedList::remove(int key) // removes first occurence of key
{
  Node* prev = nullptr;
  Node* curr = head;
  while (curr)
  {
    if (curr->key == key)
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

Node* LinkedList::find(int key) const
{
  Node* curr = head;
  while (curr)
  {
    if (curr->key == key) return curr;
    curr = curr->next;
  }
  return nullptr;
}