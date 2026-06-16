#include "array_list.hpp"
#include "linked_list.hpp"
#include "benchmark_functions.hpp"
#include "test_utils.hpp"
#include <random>


int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {

    std::mt19937 rng(1337); 
    std::uniform_int_distribution<int> dist(0, 100);

    ArrayList<int> your_al;
    LinkedList<int> your_ll;
    

    for (int k = 0; k < 5; k++) {
      int r = dist(rng);
      your_al.insert(your_al.begin(), r);
      your_ll.insert(your_ll.begin(), r);
    }

    your_al.insert(your_al.end(), 999);
    your_ll.insert(your_ll.end(), 999);
    
    
    // does it find the target?
    if (linear_search(your_al.begin(), your_al.end(), 999) != true) {
      std::cerr<<"ArrayList failed to find the target";
      return false;
    }
    
    if (linear_search(your_ll.begin(), your_ll.end(), 999) != true) {
      std::cerr<<"LinkedList failed to find the target";
      return false;
    }
    
    // does it correctly report a failure?
    if (linear_search(your_al.begin(), your_al.end(), -1) != false) {
      std::cerr<<"ArrayList found a non-existent target";
      return false;
    }

    if (linear_search(your_ll.begin(), your_ll.end(), -1) != false) {
      std::cerr<<"LinkedList found a non-existent target";
      return false;
    }
    

    return true;
  });
}
