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