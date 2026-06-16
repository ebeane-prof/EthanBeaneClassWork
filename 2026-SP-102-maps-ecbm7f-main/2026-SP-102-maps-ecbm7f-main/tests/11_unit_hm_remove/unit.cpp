#include "hashmap.hpp"
#include "test_utils.hpp"


int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {



    HashMap<std::string, int> your_map;

    your_map.put("a", 1);
    your_map.put("b", 2);
    your_map.put("c", 3);
    
    your_map.remove("b");

    if (your_map.contains("b")) {
      std::cerr<<"records not being removed properly"<<std::endl;
      return false;
    }

    return true;
  });
}
