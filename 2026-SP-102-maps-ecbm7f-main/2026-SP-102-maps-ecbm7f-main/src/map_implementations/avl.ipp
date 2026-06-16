#ifndef AVL_TREE_IPP
#define AVL_TREE_IPP

#include <stdexcept>

// Height-related methods

template <typename K, typename V> unsigned int AVL<K, V>::height() const {
  return get_height(global_root);
}

template <typename K, typename V>
unsigned int AVL<K, V>::get_height(Node *root) const {
  return (root == nullptr) ? 0 : root->height;
}

template <typename K, typename V> void AVL<K, V>::update_height(Node *root) {
  if (root != nullptr) {
    root->height =
        1 + std::max(get_height(root->left), get_height(root->right));
  }
}

// Methods to implement for the assignment

// calculates and returns the current load factor
template <typename K, typename V>
int AVL<K, V>::get_balance_factor(Node *root) const {
  if (root == nullptr) {
    return 0;
  }

  return static_cast<int>(get_height(root->left)) -
         static_cast<int>(get_height(root->right));
}

// performs a right rotation on the tree passed in
template <typename K, typename V> void AVL<K, V>::rotate_right(Node *&root) {
  Node *new_root = root->left;
  Node *temp = new_root->right;

  new_root->right = root;
  root->left = temp;

  update_height(root);
  update_height(new_root);

  root = new_root;
}

// performs a left rotation on the tree passed in
template <typename K, typename V> void AVL<K, V>::rotate_left(Node *&root) {

  Node *new_root = root->right;
  Node *temp = new_root->left;

  new_root->left = root;
  root->right = temp;

  update_height(root);
  update_height(new_root);

  root = new_root;
}

// (recursive)
// If the key already exists in the map, update the value of that record
// If the key does not exist, insert a new record,
//   making rotations if needed to maintain the height
template <typename K, typename V>
void AVL<K, V>::put_helper(Node *&root, const K &key, const V &value) {
  if (root == nullptr) {
    root = new Node(key, value);
    ++num_elems;
    return;
  }

  if (key < root->key) {
    put_helper(root->left, key, value);
  } else if (key > root->key) {
    put_helper(root->right, key, value);
  } else {
    root->value = value;
    return;
  }

  update_height(root);

  int balance = get_balance_factor(root);

  // Left left
  if (balance > 1 && key < root->left->key) {
    rotate_right(root);
  }

  // Right right
  else if (balance < -1 && key > root->right->key) {
    rotate_left(root);
  }

  // Left Right
  else if (balance > 1 && key > root->left->key) {
    rotate_left(root->left);
    rotate_right(root);
  }

  // Right Left
  else if (balance < -1 && key < root->right->key) {
    rotate_right(root->right);
    rotate_left(root);
  }
}

// (recursive)
// Remove the record with the target key,
//   making rotations if necessary to maintain the height
template <typename K, typename V>
void AVL<K, V>::remove_helper(Node *&root, const K &key) {

  if (root == nullptr) {
    throw std::invalid_argument("Key not found");
  }

  if (key < root->key) {
    remove_helper(root->left, key);
  } else if (key > root->key) {
    remove_helper(root->right, key);
  } else {

    // 0 or 1 child
    if (root->left == nullptr || root->right == nullptr) {
      Node *temp = (root->left != nullptr) ? root->left : root->right;
      delete root;
      root = temp;
    }

    // 2 children
    else {
      Node *temp = get_min(root->right);
      root->key = temp->key;
      root->value = temp->value;
      remove_helper(root->right, temp->key);
    }
  }

  if (root == nullptr)
    return;

  update_height(root);

  int balance = get_balance_factor(root);

  // Left Left
  if (balance > 1 && get_balance_factor(root->left) >= 0) {
    rotate_right(root);
  }

  // Left Right
  else if (balance > 1 && get_balance_factor(root->left) < 0) {
    rotate_left(root->left);
    rotate_right(root);
  }

  // Right Right
  else if (balance < -1 && get_balance_factor(root->right) <= 0) {
    rotate_left(root);
  }

  // Right Left
  else if (balance < -1 && get_balance_factor(root->right) > 0) {
    rotate_right(root->right);
    rotate_left(root);
  }
}

// Return a pointer to the node with the largest key that is <= the target key
// If no such node exists, return nullptr
template <typename K, typename V>
typename AVL<K, V>::Node *AVL<K, V>::get_lower_bound(const K &key) const {

  Node *current = global_root;
  Node *result = nullptr;

  while (current != nullptr) {

    if (current->key == key) {
      return current;
    }

    if (current->key < key) {
      result = current;
      current = current->right;
    } else {
      current = current->left;
    }
  }

  return result;
}

// Return a pointer to the node with the smallest key that is >= the target key
// If no such node exists, return nullptr
template <typename K, typename V>
typename AVL<K, V>::Node *AVL<K, V>::get_upper_bound(const K &key) const {
  Node *current = global_root;
  Node *result = nullptr;

  while (current != nullptr) {

    if (current->key == key) {
      return current;
    }

    if (current->key > key) {
      result = current;
      current = current->left;
    } else {
      current = current->right;
    }
  }

  return result;
}

/// Provided Methods ///
template <typename K, typename V>
void AVL<K, V>::put(const K &key, const V &value) {
  put_helper(global_root, key, value);
}

template <typename K, typename V> V AVL<K, V>::get(const K &key) const {
  Node *result = search(global_root, key);
  if (result == nullptr) {
    throw std::invalid_argument("Key not found in Map");
  }
  return result->value;
}

template <typename K, typename V>
typename AVL<K, V>::Node *AVL<K, V>::search(Node *root, const K &key) const {
  if (root == nullptr || key == root->key) {
    return root;
  }
  if (key < root->key) {
    return search(root->left, key);
  }
  return search(root->right, key);
}

template <typename K, typename V>
typename AVL<K, V>::Node *AVL<K, V>::get_min(Node *root) const {
  Node *current = root;
  while (current->left != nullptr) {
    current = current->left;
  }
  return current;
}

template <typename K, typename V> bool AVL<K, V>::contains(const K &key) const {
  return search(global_root, key) != nullptr;
}

template <typename K, typename V> unsigned int AVL<K, V>::size() const {
  return num_elems;
}

template <typename K, typename V>
AVL<K, V>::AVL() : global_root(nullptr), num_elems(0) {}

template <typename K, typename V> void AVL<K, V>::clear() {
  clear_helper(global_root);
  num_elems = 0;
}

template <typename K, typename V> void AVL<K, V>::clear_helper(Node *&root) {
  if (root != nullptr) {
    clear_helper(root->left);
    clear_helper(root->right);
    delete root;
    root = nullptr;
  }
}

template <typename K, typename V> bool AVL<K, V>::is_bst() const {
  return is_bst_helper(global_root);
}

template <typename K, typename V>
bool AVL<K, V>::is_bst_helper(Node *root) const {
  if (root == nullptr) {
    return true;
  }
  if (root->left) {
    if (root->left->key >= root->key) {
      return false;
    }
  }
  if (root->right) {
    if (root->right->key <= root->key) {
      return false;
    }
  }
  return is_bst_helper(root->left) && is_bst_helper(root->right);
}

template <typename K, typename V>
typename AVL<K, V>::Node *AVL<K, V>::clone(Node *root) {
  if (root == nullptr) {
    return nullptr;
  }

  return new Node *(root->key, root->value, root->height, clone(root->left),
                    clone(root->right));
}

template <typename K, typename V> AVL<K, V>::~AVL() {
  clear_helper(global_root);
}

template <typename K, typename V> void AVL<K, V>::remove(const K &key) {
  remove_helper(global_root, key);
  --num_elems;
}
#endif // AVL_TREE_IPP
