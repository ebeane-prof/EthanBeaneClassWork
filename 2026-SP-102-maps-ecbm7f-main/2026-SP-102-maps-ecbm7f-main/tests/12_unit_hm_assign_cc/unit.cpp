#include "hashmap.hpp"
#include "test_utils.hpp"


int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {



    HashMap<std::string, int> your_map, other_map;

    your_map.put("a", 1);
    your_map.put("b", 2);

    // assignment op test

    other_map = your_map;

    if (other_map.get("b") != 2) {
      std::cerr<<"assign op is not copying data correctly"<<std::endl;
      return false;
    }

    your_map.put("c", 3);

    if (other_map.contains("c")) {
      std::cerr<<"assign op is not creating a deep copy"<<std::endl;
      return false;
    }
    
    // cc test
    HashMap<std::string, int> copy_map = your_map;

    if (copy_map.get("b") != 2) {
      std::cerr<<"copy constructor is not copying data correctly"<<std::endl;
      return false;
    }

    your_map.put("d", 4);

    if (copy_map.contains("d")) {
      std::cerr<<"copy constructor is not creating a deep copy"<<std::endl;
      return false;
    }

    return true;
  });
}
