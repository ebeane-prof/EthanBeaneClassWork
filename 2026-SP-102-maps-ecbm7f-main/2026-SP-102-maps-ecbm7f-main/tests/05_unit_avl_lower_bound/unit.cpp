#include "avl.hpp"
#include "test_utils.hpp"
#include <string>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {

    AVL<std::string, int> your_map;

    // does putting new records increase size?

    your_map.put("f", 1);
    your_map.put("g", 2);
    your_map.put("c", 3);
    your_map.put("e", 4);
    your_map.put("b", 5);
    

    // exact match
    if (your_map.get_lower_bound("f")->key != "f") {
      std::cerr<<"failure when exact key is present"<<std::endl;
      return false;
    }
    
    // last seen
    if (your_map.get_lower_bound("h")->key != "g") {
      std::cerr<<"failure getting correct lower bound"<<std::endl;
      return false;
    }

    // ancestor
    if (your_map.get_lower_bound("d")->key != "c") {
      std::cerr<<"failure getting correct lower bound"<<std::endl;
      return false;
    }

    // no lower bound
    if (your_map.get_lower_bound("a") != nullptr) {
      std::cerr<<"failure when no lower bound exists"<<std::endl;
      return false;
    }

    
    return true;
  });
}
