#include "hashmap.hpp"
#include "test_utils.hpp"
#include <random>
#include <set>


int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {



    unsigned int N = 10000; 
    std::mt19937 rng(std::random_device{}()); 
    std::uniform_int_distribution<int> dist(0, 100000);
    std::set<int> random_nums;
    while (random_nums.size() < N) {
      random_nums.insert(dist(rng));
    }

    HashMap<int,int> your_map;
    for (int num : random_nums) {
      your_map.put(num, 0);
    } 

    if (your_map.load_factor() > 0.7) {
      std::cerr<<"Load factor is not being maintained"<<std::endl;
      return false;
    }

    return true;
  });
}
