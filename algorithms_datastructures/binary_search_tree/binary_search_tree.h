#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <vector>

struct Node
{
  int value{};
  Node* left {nullptr};
  Node* right {nullptr};
};

class BinarySearchTree
{
private:
  Node* root;
  void insert(int value, Node* start);
  bool search(int value, Node* start) const;
  void ordered_print(Node* start) const;
  void pre_order_print(Node* start) const;
  void post_order_print(Node* start) const;

  // recursive approach without using a queue
  // void level_order_print(Node* start, size_t depth, std::vector<std::vector<int>>& values) const;

  
  void clear(Node* root);
public:
  BinarySearchTree();
  ~BinarySearchTree();
  void insert(int value);
  bool search(int value) const;
  bool remove(int value);
  void ordered_print() const;
  void pre_order_print() const;
  void post_order_print() const;
  void level_order_print() const;
  void clear();

  BinarySearchTree(const BinarySearchTree&) = delete;
  BinarySearchTree& operator=(const BinarySearchTree&) = delete;
};

#endif