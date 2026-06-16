#include "array_list.hpp"

int main() {

  ArrayList<int> your_list, assigned_list;

  for (int i = 1; i <=5; ++i) {
    your_list.insert(your_list.end(), i);
  } 

  // testing operator=
  assigned_list.reserve(3);
  assigned_list = your_list;

  // testing copy constructor
  ArrayList<int> copied_list = your_list;
    
  return 0;
}
