#include "hashmap.hpp"
#include "test_utils.hpp"


int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {

    HashMap<std::string, int> your_map;

    // false negative test

    your_map.put("a", 1);
    your_map.put("b", 2);

    if (!your_map.contains("a") || !your_map.contains("b")) {
      std::cerr<<"contains is producing false negatives"<<std::endl;
      return false;
    }

    // false positive test

    if (your_map.contains("c")) {
      std::cerr<<"contains is producing false positives"<<std::endl;
      return false;
    } 


    return true;
  });
}
