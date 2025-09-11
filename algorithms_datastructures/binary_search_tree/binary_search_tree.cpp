#include <iostream>
#include "binary_search_tree.h"

BinarySearchTree::BinarySearchTree()
: root{nullptr}
{
}

void BinarySearchTree::insert(int value, Node* start)
{
  Node* curr = start;
  if (curr->value == value) {return;}

  if (value < curr->value)
  {
    if (curr->left) // node has left leaf
    {
      insert(value, curr->left);
      return;
    }
    // append value to the left of node
    Node* n = new Node;
    n->value = value;
    curr->left = n;
    return;
  }
  else if (value > curr->value)
  {
    if (curr->right) // node has right leaf
    {
      insert(value, curr->right);
      return;
    }
    // append value to the right of node
    Node* n = new Node;
    n->value = value;
    curr->right = n;
    return;
  }
}

void BinarySearchTree::insert(int value)
{
  if (!root)
  {
    Node* n = new Node;
    n->value = value;
    root = n;
    return;
  }
  insert(value, root);
}

bool BinarySearchTree::search(int value, Node* start)
{
  if (value == start->value) {return true;}
  if (value < start->value)
  {
    if (!start->left) {return false;}
    return search(value, start->left);
  } else if (value > start->value)
  {
    if (!start->right) {return false;}
    return search(value, start->right);
  }
  return false;
}

bool BinarySearchTree::search(int value)
{
  if (!root) {return false;}
  return search(value, root);
}