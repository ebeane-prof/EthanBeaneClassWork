#include "avl.hpp"
#include "test_utils.hpp"
#include <string>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {



    AVL<std::string, int> your_map;

    your_map.put("c", 1);
    your_map.put("b", 2);
    your_map.put("f", 3);
    your_map.put("d", 4);
    your_map.put("g", 5);
    

    // exact match
    if (your_map.get_upper_bound("c")->key != "c") {
      std::cerr<<"failure when exact key is present"<<std::endl;
      return false;
    }
    
    // last seen
    if (your_map.get_upper_bound("a")->key != "b") {
      std::cerr<<"failure getting correct upper bound"<<std::endl;
      return false;
    }

    // ancestor
    if (your_map.get_upper_bound("e")->key != "f") {
      std::cerr<<"failure getting correct upper bound"<<std::endl;
      return false;
    }

    // no upper bound
    if (your_map.get_upper_bound("h") != nullptr) {
      std::cerr<<"failure when no upper bound exists"<<std::endl;
      return false;
    }

    
    return true;
  });
}
