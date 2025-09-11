#include <iostream>
#include "binary_search_tree.h"

BinarySearchTree::BinarySearchTree()
: root{nullptr}
{
}

BinarySearchTree::~BinarySearchTree()
{
  clear();
}

void BinarySearchTree::insert(int value, Node* start)
{
  Node* curr = start;
  if (curr->value == value) return;

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

bool BinarySearchTree::search(int value, Node* start) const
{
  if (value == start->value) {return true;}
  if (value < start->value)
  {
    if (!start->left) return false;
    return search(value, start->left);
  } else if (value > start->value)
  {
    if (!start->right) return false;
    return search(value, start->right);
  }
  return false;
}

bool BinarySearchTree::search(int value) const
{
  if (!root) return false;
  return search(value, root);
}

bool BinarySearchTree::remove(int value)
{
  Node* curr = root;
  Node* parent = nullptr;
  bool isLeftChild;
  while (curr)
  {
    if (curr->value == value) {break;}
    
    if (value < curr->value)
    {
      if (!curr->left) return false; // value does not exist
      parent = curr;
      isLeftChild = true;
      curr = curr->left;
    } 
    else if (value > curr->value)
    {
      if (!curr->right) return false; // value does not exist
      parent = curr;
      isLeftChild = false;
      curr = curr->right;
    }
  }

  if (!curr) return false;

  if (!curr->left && !curr->right) // no child node
  {
    if (curr == root)
    {
      root = nullptr;
    }
    else
    {
      if (isLeftChild) parent->left = nullptr;
      else parent->right = nullptr;
    }
    delete curr;
  } 
  else if ((!curr->left && curr->right) || (curr->left && !curr->right)) // one child node
  {
    Node* child = curr->left ? curr->left : curr->right;

    if (curr == root) 
    {
      root = child;
    }
    else
    {
      if (isLeftChild) parent->left = child;
      else parent->right = child;
    }
    delete curr;
  }
  else // two child nodes
  {
    Node* successor = curr->right;
    Node* successor_parent = curr;
    while (successor->left)
    {
      successor_parent = successor;
      successor = successor->left;
    }

    curr->value = successor->value;

    if (!successor->left && !successor->right)
    {
      if (successor_parent == curr) curr->right = nullptr;
      else successor_parent->left = nullptr;
    }
    else
    {
      if (successor_parent == curr)
      {
        successor_parent->right = successor->right;
      }
      else
      {
        successor_parent->left = successor->right;
      }
    }
    delete successor;
  }

  return true;
}

void BinarySearchTree::ordered_print(Node* start) const
{
  if (start->left) ordered_print(start->left);
  std::cout << start->value << " ";
  if (start->right) ordered_print(start->right);
}

void BinarySearchTree::ordered_print() const
{
  if (root) ordered_print(root);
  std::cout << "\n";
}

void BinarySearchTree::pre_order_print(Node* start) const
{
  std::cout << start->value << " ";
  if (start->left) pre_order_print(start->left);
  if (start->right) pre_order_print(start->right);
}

void BinarySearchTree::pre_order_print() const
{
  if (root) pre_order_print(root);
  std::cout << "\n";
}

void BinarySearchTree::post_order_print(Node* start) const
{
  if (start->left) post_order_print(start->left);
  if (start->right) post_order_print(start->right);
  std::cout << start->value << " ";
}

void BinarySearchTree::post_order_print() const
{
  if (root) post_order_print(root);
  std::cout << "\n";
}

void BinarySearchTree::clear(Node* root)
{
  if (!root) return;

  if (root->left) clear(root->left);
  if (root->right) clear(root->right);
  delete root;
}

void BinarySearchTree::clear()
{
  clear(root);
  root = nullptr;
}