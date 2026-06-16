#include "avl.hpp"
#include "test_utils.hpp"


int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {

    AVL<std::string, int> your_map;

    // right-right case resulting from put

    your_map.put("a", 1);
    your_map.put("b", 2);
    your_map.put("c", 3);

    if (your_map.height() != 2 || !your_map.is_bst()) {
      std::cerr<<"put is not rotating correctly"<<std::endl;
      return false;
    }
    your_map.clear();
    
    // right-right case resulting from remove

    your_map.put("b", 1);
    your_map.put("a", 2);
    your_map.put("c", 3);
    your_map.put("d", 4);
    your_map.remove("a");
    
    if (your_map.height() != 2 || !your_map.is_bst()) {
      std::cerr<<"remove is not rotating correctly"<<std::endl;
      return false;
    }

    return true;
  });
}
