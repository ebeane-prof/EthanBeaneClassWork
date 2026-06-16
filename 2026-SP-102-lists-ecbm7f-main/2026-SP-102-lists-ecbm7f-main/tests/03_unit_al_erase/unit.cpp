#include "array_list.hpp"
#include "test_utils.hpp"
#include <random>
#include <vector>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {

    std::mt19937 rng(std::random_device{}()); 
    std::uniform_int_distribution<int> dist(0, 100);

    ArrayList<int> your_list;
    std::vector<int> test_list;

    for (int k = 0; k < 5; k++) {
      int r = dist(rng);
      your_list.insert(your_list.end(), r);
      test_list.insert(test_list.end(), r);
    }

    //testing erase
    your_list.erase(your_list.begin());
    test_list.erase(test_list.begin());
    

    if (your_list.size() != 4) {
      std::cerr<<"list size is not reducing properly";
      return false;
    }

    your_list.erase(--your_list.end());
    test_list.erase(--test_list.end());

    auto your_iter = your_list.begin();  
    for ( int elem : test_list ) {
      if (elem != *your_iter) {
        std::cerr<<"values are not being erased properly";
        return false;
      }
      ++your_iter;
    }

    return true;
  });
}
