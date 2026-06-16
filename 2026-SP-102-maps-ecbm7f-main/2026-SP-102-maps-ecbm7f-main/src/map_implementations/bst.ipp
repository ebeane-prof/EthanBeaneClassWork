#ifndef BST_IPP
#define BST_IPP

#include <stdexcept>

// --- Constructor & Destructor ---

template <typename K, typename V>
BST<K, V>::BST() : global_root(nullptr), num_elems(0) {}

template <typename K, typename V> BST<K, V>::~BST() { clear(global_root); }

template <typename K, typename V>
BST<K, V> &BST<K, V>::operator=(const BST<K, V> &other) {
  clear(global_root);
  global_root = clone(other.global_root);
  num_elems = other.num_elems;
  return *this;
}

template <typename K, typename V> BST<K, V>::BST(const BST<K, V> &other) {

  global_root = nullptr;
  *this = other;
}

template <typename K, typename V> void BST<K, V>::clear(Node *root) {
  if (root != nullptr) {
    clear(root->left);
    clear(root->right);
    delete root;
  }
}

template <typename K, typename V>
typename BST<K, V>::Node *BST<K, V>::clone(const Node *root) {

  if (root == nullptr) {
    return nullptr;
  }

  return new Node(root->key, root->value, clone(root->left),
                  clone(root->right));
}

// --- Map Interface ---

template <typename K, typename V> V BST<K, V>::get(const K &key) const {
  Node *result = search(global_root, key);
  if (result == nullptr) {
    throw std::out_of_range("Key not found in Map");
  }
  return result->value;
}

template <typename K, typename V> bool BST<K, V>::contains(const K &key) const {
  return search(global_root, key) != nullptr;
}

template <typename K, typename V> unsigned int BST<K, V>::size() const {
  return num_elems;
}

template <typename K, typename V>
void BST<K, V>::for_each(
    std::function<void(const K &, const V &)> action) const {
  in_order_traversal(global_root, action);
}

// --- Internal Traversal & Search ---

template <typename K, typename V>
void BST<K, V>::in_order_traversal(
    Node *root, std::function<void(const K &, const V &)> action) const {
  if (root == nullptr)
    return;
  in_order_traversal(root->left, action);
  action(root->key, root->value);
  in_order_traversal(root->right, action);
}

template <typename K, typename V>
typename BST<K, V>::Node *BST<K, V>::search(Node *root, const K &key) const {
  if (root == nullptr || key == root->key) {
    return root;
  }
  if (key < root->key) {
    return search(root->left, key);
  }
  return search(root->right, key);
}

template <typename K, typename V>
typename BST<K, V>::Node *BST<K, V>::get_min(Node *root) const {
  Node *current = root;
  while (current->left != nullptr) {
    current = current->left;
  }
  return current;
}

// --- AVL Height & Balance Helpers ---

// template <typename K, typename V>
// unsigned int BST<K, V>::get_height(const Node*& root) const {
//     if (root == nullptr){
//         return 0;
//     }

//     return 1 + std::max(get_height(root->left), get_height(root->right));
// }

template <typename K, typename V>
void BST<K, V>::put(const K &key, const V &value) {
  put_helper(global_root, key, value);
}

template <typename K, typename V>
void BST<K, V>::put_helper(Node *&root, const K &key, const V &value) {

  if (root == nullptr) {
    ++num_elems;
    root = new Node(key, value);
  }

  if (key < root->key) {
    put_helper(root->left, key, value);
  } else if (key > root->key) {
    put_helper(root->right, key, value);
  } else {
    root->value = value; // Update existing key
  }
}

// --- Deletion Logic ---

template <typename K, typename V> void BST<K, V>::remove(const K &key) {

  remove_helper(global_root, key);
}

template <typename K, typename V>
void BST<K, V>::remove_helper(Node *&root, const K &key) {
  if (root == nullptr)
    return;

  if (key < root->key) {
    remove_helper(root->left, key);
  } else if (key > root->key) {
    remove_helper(root->right, key);
  } else {
    --num_elems;
    // Node with only one child or no child
    if (root->left == nullptr && root->right == nullptr) {
      delete root;
    } else if (root->left == nullptr) {
      Node *temp = root;
      root = root->right;
      delete temp;
    } else if (root->right == nullptr) {
      Node *temp = root;
      root = root->left;
      delete temp;
    } else {
      // Node with two children: Get inorder successor
      Node *temp = get_min(root->right);
      root->key = temp->key;
      root->value = temp->value;
      remove_helper(root->right, temp->key); // Recursive delete
    }
  }
}

// template <typename K, typename V>
// typename BST<K,V>::Node* BST<K,V>::get_lower_bound(const K& key) const {

//     if (size() == 0) {
//         return nullptr;
//     }

//     Node* lower_bound = nullptr;
//     Node* current = global_root;

//     while (current != nullptr) {
//         if (current->key == key) {
//             return current;
//         }
//         else if (current->key > key) {
//             // search left tree
//             current = current->left;
//         }
//         else if (current->key < key) {
//             // search right tree?
//             lower_bound = current;
//             current = current->right;
//         }
//     }
// }

// template <typename K, typename V>
// typename BST<K,V>::Node* BST<K,V>::get_upper_bound(const K& key) const {

//     if (size() == 0) {
//         return nullptr;
//     }

//     Node* upper_bound = nullptr;
//     Node* current = global_root;

//     while (current != nullptr) {
//         if (current->key == key) {
//             return current;
//         }
//         else if (current->key > key) {
//             // search left tree
//             upper_bound = current;
//             current = current->left;
//         }
//         else if (current->key < key) {
//             // search right tree?
//             current = current->right;
//         }

//     }

// }

// template <typename K, typename V>
// std::vector<V> get_range(Node* root, const K& lower, const K& upper) const {

// replace with for_range?
// }

#endif // BST_IPP
