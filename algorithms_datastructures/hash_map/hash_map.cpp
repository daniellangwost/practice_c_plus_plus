#include <iostream>
#include <cmath>
#include <optional>
#include "hash_map.h"

HashMap::HashMap(int length)
  : m_length {}
  , m_buckets()
{
  if (length <= 0)
  {
    throw std::invalid_argument("Length must be positive");
  }
  m_length = length;
  m_buckets.resize(static_cast<std::vector<LinkedList>::size_type>(length));
}

int HashMap::hash(int key)
{
  return abs(key % m_length) % m_length;
}

void HashMap::insert(int key, int value)
{
  int bucket = hash(key);
  m_buckets[static_cast<std::vector<LinkedList>::size_type>(bucket)].append(key, value);
}

std::optional<int> HashMap::get(int key)
{
  int bucket_num = hash(key);
  LinkedList& bucket = m_buckets[static_cast<std::vector<LinkedList>::size_type>(bucket_num)];
  Node* node = bucket.find(key);
  if (node) return node->value;
  return std::nullopt;
}

bool HashMap::remove(int key)
{
  int bucket_num = hash(key);
  LinkedList& bucket = m_buckets[static_cast<std::vector<LinkedList>::size_type>(bucket_num)];
  return bucket.remove(key);
}

void HashMap::clear()
{
  for (LinkedList& bucket : m_buckets)
  {
    bucket.clear();
  }
}
