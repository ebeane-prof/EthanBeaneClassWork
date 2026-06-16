#include "avl.hpp"
#include "test_utils.hpp"


int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {

    AVL<std::string, int> your_map;

    // does putting new records increase size?

    your_map.put("a", 1);
    your_map.put("b", 2);

    if (your_map.size() != 2 || your_map.get("a") != 1 || your_map.get("b") != 2) {
      std::cerr<<"new records are not being inserted correctly"<<std::endl;
      return false;
    }

    // does putting existing records update?

    your_map.put("a", 3);

    if (your_map.size() != 2 || your_map.get("a") != 3) {
      std::cerr<<"existing records are not being updated correctly"<<std::endl;
      return false;
    } 

    if (!your_map.is_bst()) {
      std::cerr<<"not maintaining the search property"<<std::endl;
      return false;
    }

    return true;
  });
}
