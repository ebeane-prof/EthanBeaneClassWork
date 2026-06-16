#include "array_list.hpp"
#include "test_utils.hpp"
#include <random>
#include <vector>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {

    std::mt19937 rng(std::random_device{}()); 
    std::uniform_int_distribution<int> dist(0, 100);

    ArrayList<int> your_list, assigned_list;
    
    for (int k = 0; k < 5; k++) {
      int r = dist(rng);
      your_list.insert(your_list.end(), r);
    }

    // testing operator=

    assigned_list = your_list;

    if (your_list.size() != assigned_list.size() || your_list.capacity() != assigned_list.capacity()) {
      std::cerr<<"operator= does not update member variables properly";
      return false;
    }
  
    if (your_list.begin() == assigned_list.begin()) {
      std::cerr<<"operator= produces a shallow copy";
      return false;
    }

    ArrayList<int>::Iterator your_iter = your_list.begin();  
    for (auto it = assigned_list.begin(); it != assigned_list.end(); ++it) {
      if (*it != *your_iter) {
        std::cerr<<"operator= is not copying values properly";
        return false;
      }
      ++your_iter;
    }

    // testing copy constructor

    ArrayList<int> copied_list = your_list;

    if (your_list.size() != copied_list.size() || your_list.capacity() != copied_list.capacity()) {
      std::cerr<<"copy constructor does not update member variables properly";
      return false;
    }
  
    if (your_list.begin() == copied_list.begin()) {
      std::cerr<<"copy constructor produces a shallow copy";
      return false;
    }

    your_iter = your_list.begin();  
    for (auto it = copied_list.begin(); it != copied_list.end(); ++it) {
      if (*it != *your_iter) {
        std::cerr<<"copy constructor is not copying values properly";
        return false;
      }
      ++your_iter;
    }

    return true;
  });
}
