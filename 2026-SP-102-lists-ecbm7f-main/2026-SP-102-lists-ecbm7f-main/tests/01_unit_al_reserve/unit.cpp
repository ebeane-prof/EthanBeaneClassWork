#include "array_list.hpp"
#include "test_utils.hpp"
#include <random>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    std::mt19937 rng(1337); 
    std::uniform_int_distribution<int> dist(10,100);

    ArrayList<int> your_list;
    ArrayList<int>::Iterator orig_iter = your_list.begin();
    unsigned int new_cap = dist(rng);
    your_list.reserve(new_cap);

    if (your_list.capacity() != new_cap)
    {
      std::cerr<<"member variable max_elems is not updating properly";
      return false;
    }

    if (orig_iter == your_list.begin()) {
      std::cerr<<"the storage array after reserve() is the same as the storage array before";
      return false;
    }
    
    return true;
  });
}

