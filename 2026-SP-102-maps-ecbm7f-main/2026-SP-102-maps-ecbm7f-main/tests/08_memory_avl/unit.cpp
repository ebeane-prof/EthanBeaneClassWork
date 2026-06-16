#include "avl.hpp"
#include <string>

int main() {

  AVL<std::string, int> your_map;

  your_map.put("a", 1);
  your_map.put("b", 1);
  your_map.put("c", 1);
  your_map.put("d", 1);
  your_map.put("e", 1);
  your_map.put("f", 1);
  your_map.put("g", 1);
  your_map.put("h", 1);
  your_map.put("i", 1);

  your_map.remove("a");
  your_map.remove("b");
  your_map.remove("c");
  your_map.remove("d");
  your_map.remove("e");
  your_map.remove("f");
  your_map.remove("g");
  your_map.remove("h");
  your_map.remove("i");

  
  return 0;
}
