#include "linked_list.hpp"

int main() {

  LinkedList<int> your_list, assigned_list;

  for (int i = 1; i <=5; ++i) {
    your_list.insert(your_list.end(), i);
  } 

  // testing operator=
  assigned_list.insert(assigned_list.begin(), 1);  
  assigned_list.insert(assigned_list.begin(), 2);  
  
  assigned_list = your_list;

  // testing copy constructor
  LinkedList<int> copied_list = your_list;
    
  return 0;
}
