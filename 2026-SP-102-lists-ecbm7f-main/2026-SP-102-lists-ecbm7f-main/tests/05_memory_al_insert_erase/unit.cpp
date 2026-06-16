#include "array_list.hpp"

int main() {

  ArrayList<int> your_list;

  // testing insert 
  your_list.insert(your_list.begin(), 3);  
  your_list.insert(your_list.begin(), 2);  
  your_list.insert(your_list.begin(), 1);  

  // resize test
  for (int i = 4; i < 10; ++i) {
    your_list.insert(your_list.end(), i);
  }

  // testing erase
  your_list.erase(your_list.end());
  your_list.erase(your_list.begin());
  your_list.erase(your_list.begin()+3);
  
  return 0;
}
