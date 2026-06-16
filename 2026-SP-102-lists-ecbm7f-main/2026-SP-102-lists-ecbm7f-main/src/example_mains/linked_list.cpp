#include "linked_list.hpp"
#include <iostream>

int main() {

  LinkedList<std::string> names;

  // Edge Case: Insert into empty
  names.insert(names.begin(), "Middle");

  // Edge Case: Insert at head
  names.insert(names.begin(), "Start");

  // Edge Case: Insert at tail
  names.insert(names.end(), "End");

  // Verification of Iterator traversal
  std::cout << "Current List: ";
  for (auto it = names.begin(); it != names.end(); ++it) {
    std::cout << *it << " -> ";
  }

  return 0;
}
