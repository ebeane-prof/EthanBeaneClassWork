#include "linked_list.hpp"

int main() {

  LinkedList<int> your_list;

  // testing insert 
  your_list.insert(your_list.begin(), 3);  
  your_list.insert(your_list.begin(), 2);  
  your_list.insert(your_list.begin(), 1);  
  your_list.insert(your_list.end(), 4);  
  your_list.insert(your_list.end(), 5);  


  // testing erase
  your_list.erase(your_list.end());
  your_list.erase(your_list.begin());
  your_list.erase(++your_list.begin());
  
  return 0;
}
