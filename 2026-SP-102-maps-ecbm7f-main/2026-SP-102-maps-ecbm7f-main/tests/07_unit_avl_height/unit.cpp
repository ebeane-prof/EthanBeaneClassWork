#include "avl.hpp"
#include "test_utils.hpp"
#include <random>
#include <cmath>
#include <set>


int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {


    unsigned int N = 10000; 
    unsigned int MAX_HEIGHT = std::ceil(1.44*std::log2(N+2)-0.328);
    std::mt19937 rng(std::random_device{}()); 
    std::uniform_int_distribution<int> dist(0, 100000);
    std::set<int> random_nums;
    while (random_nums.size() < N) {
      random_nums.insert(dist(rng));
    }

    AVL<int,int> your_map;
    for (int num : random_nums) {
      your_map.put(num, 0);
    } 

    if (your_map.height() > MAX_HEIGHT) {
      std::cerr<<"Height exceeds the theoretical maximum for an AVL tree"<<std::endl;
      return false;
    }

    return true;
  });
}
