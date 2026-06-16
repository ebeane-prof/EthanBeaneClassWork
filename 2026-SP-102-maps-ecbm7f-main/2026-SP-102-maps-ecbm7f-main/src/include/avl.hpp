#ifndef AVL_HPP
#define AVL_HPP

#include "map.hpp"
#include <algorithm>
#include <type_traits>

template <typename K, typename V> class AVL : public Map<K, V> {
public:
  struct Node {
    K key;
    V value;
    unsigned int height; // The only addition to a standard BST Node
    Node *left;
    Node *right;

    Node(const K &k, const V &v)
        : key(k), value(v), height(1), left(nullptr), right(nullptr) {}
    Node(const K &k, const V &v, const int &h, const Node *&l, const Node *&r)
        : key(k), value(v), height(h), left(l), right(r) {}
  };

private:
  Node *global_root;
  unsigned int num_elems;

  // --- Core BST Helpers ---
  Node *search(Node *root, const K &key) const;
  Node *get_min(Node *root) const;

  // --- AVL Specific Helpers ---
  unsigned int get_height(Node *root) const;
  int get_balance_factor(Node *root) const;
  void update_height(Node *root);
  void rotate_right(Node *&root);
  void rotate_left(Node *&root);

  // --- Recursive Operational Helpers ---
  void put_helper(Node *&root, const K &key, const V &value);
  void remove_helper(Node *&root, const K &key);
  Node *clone(Node *root);
  bool is_bst_helper(Node *root) const;
  void clear_helper(Node *&root);

public:
  AVL();
  ~AVL() override;
  AVL<K, V> &operator=(const AVL<K, V> &other);
  AVL(const AVL<K, V> &other);

  bool is_bst() const;
  // --- Map Interface ---
  void put(const K &key, const V &value) override;
  V get(const K &key) const override;
  bool contains(const K &key) const override;
  void remove(const K &key) override;
  void clear();
  unsigned int size() const override;
  unsigned int height() const;

  // --- SortedMap Interface ---
  Node *get_lower_bound(const K &key) const;
  Node *get_upper_bound(const K &key) const;
};

#include "../map_implementations/avl.ipp"

#endif // AVL_HPP
