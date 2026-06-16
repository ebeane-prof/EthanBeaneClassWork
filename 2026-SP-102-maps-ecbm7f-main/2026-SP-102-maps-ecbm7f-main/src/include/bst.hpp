#ifndef BST_HPP
#define BST_HPP

#include "map.hpp"
#include <algorithm>

template <typename K, typename V> class BST : public Map<K, V> {
private:
  struct Node {
    K key;
    V value;
    Node *left;
    Node *right;

    Node(const K &k, const V &v)
        : key(k), value(v), left(nullptr), right(nullptr) {}
    Node(const K &k, const V &v, const Node *&l, const Node *&r)
        : key(k), value(v), left(l), right(r) {}
  };

  Node *global_root;
  unsigned int num_elems;

  // --- Core BST Helpers ---
  void
  in_order_traversal(Node *root,
                     std::function<void(const K &, const V &)> action) const;
  Node *get_min(Node *root) const;

  // unsigned int get_height(const Node*& root) const;

  // --- Recursive Operational Helpers ---
  Node *search(Node *root, const K &key) const;
  void put_helper(Node *&root, const K &key, const V &value);
  Node *clone(const Node *root);
  void remove_helper(Node *&root, const K &key);

public:
  BST();
  ~BST() override;
  BST<K, V> &operator=(const BST<K, V> &other);
  BST(const BST<K, V> &other);

  // --- Map Interface ---
  void put(const K &key, const V &value) override;
  V get(const K &key) const override;
  bool contains(const K &key) const override;
  void remove(const K &key) override;
  void clear(Node *root);
  unsigned int size() const override;
  void
  for_each(std::function<void(const K &, const V &)> action) const override;

  // --- SortedMap Interface ---
  // Node* get_lower_bound(const K& key) override;
  // Node* get_upper_bound(const K& key) override;
  // std::vector<V> get_range(const K& lower, const K& upper) const = 0;
};

#include "../map_implementations/bst.ipp"

#endif // BST_HPP
