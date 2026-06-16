#include "map.hpp"
// #include "sorted_map.hpp"
#include "avl.hpp"
#include "bst.hpp"
#include "hashmap.hpp"
#include <string>

int main() {

  // testing different dynamic types
  Map<std::string, int> *g_bst = new BST<std::string, int>;
  Map<std::string, int> *g_avl = new AVL<std::string, int>;
  Map<std::string, int> *g_hash = new HashMap<std::string, int>;

  // SortedMap<std::string, int>* gs_bst = new BST<std::string, int>;
  // SortedMap<std::string, int>* gs_avl = new AVL<std::string, int>;

  return 0;
}
