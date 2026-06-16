#include "array_list.hpp"
#include "linked_list.hpp"
#include "benchmark_functions.hpp"
#include "test_utils.hpp"
#include <random>
#include <vector>
#include <algorithm>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {

    std::mt19937 rng(std::random_device{}()); 
    std::uniform_int_distribution<int> dist(0, 100);

    ArrayList<int> your_al;
    LinkedList<int> your_ll;
    std::vector<int> test_list;

    for (int k = 0; k < 8; k++) {
      int r = dist(rng);
      your_al.insert(your_al.end(), r);
      your_ll.insert(your_ll.end(), r);
      test_list.insert(test_list.end(), r);
    }

    selection_sort<ArrayList<int>::Iterator,int>(your_al.begin(), your_al.end());
    selection_sort<LinkedList<int>::Iterator,int>(your_ll.begin(), your_ll.end());
    std::sort(test_list.begin(), test_list.end());
        
    auto your_al_iter = your_al.begin();  
    auto your_ll_iter = your_ll.begin();
    bool sorted = true;
    for ( int elem : test_list ) {
      if (elem != *your_al_iter) {
        std::cerr<<"ArrayList is not being sorted properly"<<std::endl;    
        sorted = false;
      }
      if (elem != *your_ll_iter) {
        std::cerr<<"LinkedList is not being sorted properly"<<std::endl;    
        sorted = false;
      }
      ++your_al_iter;
      ++your_ll_iter;
    }

    return sorted;
  });
}
