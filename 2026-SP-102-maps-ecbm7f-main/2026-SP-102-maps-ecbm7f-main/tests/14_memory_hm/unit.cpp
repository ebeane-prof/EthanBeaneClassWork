#include "hashmap.hpp"
#include <string>

int main() {

  HashMap<int, int> your_map, other_map;


  // triggering rehash

  for (int i = 0; i < 500; ++i) {
    your_map.put(i, 0);
  }  

  // triggering assign op

  other_map = your_map;

  // triggering cc  

  HashMap<int, int> copy_map = your_map;
  
  return 0;
}
