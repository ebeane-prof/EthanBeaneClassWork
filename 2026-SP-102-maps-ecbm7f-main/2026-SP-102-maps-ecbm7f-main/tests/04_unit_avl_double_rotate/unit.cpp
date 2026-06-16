#include "avl.hpp"
#include "test_utils.hpp"


int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {

    AVL<std::string, int> your_map;

    // right-left case resulting from put

    your_map.put("a", 1);
    your_map.put("c", 2);
    your_map.put("b", 3);

    if (your_map.height() != 2 || !your_map.is_bst()) {
      std::cerr<<"put failed in right-left case"<<std::endl;
      return false;
    }
    your_map.clear();
    
    // right-left case resulting from remove

    your_map.put("b", 1);
    your_map.put("a", 2);
    your_map.put("d", 3);
    your_map.put("c", 4);
    your_map.remove("a");
    
    if (your_map.height() != 2 || !your_map.is_bst()) {
      std::cerr<<"remove failed in right-left case"<<std::endl;
      return false;
    }
    your_map.clear();
    
    // left-right case resulting from put

    your_map.put("c", 1);
    your_map.put("a", 2);
    your_map.put("b", 3);

    if (your_map.height() != 2){// || !your_map.is_bst()) {
      std::cerr<<"put failed in left-right case"<<std::endl;
      return false;
    }
    your_map.clear();
    
    // left-right case resulting from remove

    // your_map.put("b", 1);
    // your_map.put("a", 2);
    // your_map.put("d", 3);
    // your_map.put("c", 4);
    // your_map.put("e", 5);
    // your_map.remove("a");

    your_map.put("d",1);
    your_map.put("e",2);
    your_map.put("b",3);
    your_map.put("c",4);
    your_map.put("a",5);
    your_map.remove("e");
    
    if (!your_map.is_bst()) {
      std::cerr<<"remove failed in left-right case"<<std::endl;
      return false;
    }

    return true;
  });
}
