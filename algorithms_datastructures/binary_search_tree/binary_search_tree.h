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
public:
  BinarySearchTree();
  void insert(int value);
  bool search(int value) const;
  bool remove(int value);
  void ordered_print() const;
  void pre_order_print() const;
  void post_order_print() const;
};