#include "avl.hpp"
#include "test_utils.hpp"


int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {

    AVL<std::string, int> your_map;

    // does putting new records increase size?

    your_map.put("e", 1);
    your_map.put("g", 2);
    your_map.put("c", 3);
    your_map.put("b", 4);
    your_map.put("d", 5);
    your_map.put("f", 6);
    your_map.put("h", 7);


    // degree-0 case
    your_map.remove("d");
    if (your_map.size() != 6 || your_map.contains("d") || !your_map.is_bst()) {
      std::cerr<<"failure in 0-child case"<<std::endl;
      return false;
    }
    
    // degree-1 case
    your_map.remove("c");
    if (your_map.size() != 5 || your_map.contains("c") || !your_map.is_bst()) {
      std::cerr<<"failure in 1-child case"<<std::endl;
      return false;
    }

    // degree-2 case
    your_map.remove("g");
    if (your_map.size() != 4 || your_map.contains("g") || !your_map.is_bst()) {
      std::cerr<<"failure in 2-child case"<<std::endl;
      return false;
    }
    
    return true;
  });
}
