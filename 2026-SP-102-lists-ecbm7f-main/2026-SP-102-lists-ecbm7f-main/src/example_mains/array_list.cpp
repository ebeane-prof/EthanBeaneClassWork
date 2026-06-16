#include "array_list.hpp"
#include <iostream>

int main() {
  std::cout << "--- ArrayList Example: Capacity & Resizing ---\n";

  // Instantiation (Checks if T works and constructor is valid)
  ArrayList<int> list;

  // Stressing the 'grow' logic (Combination of many inserts)
  try {
    for (int i = 0; i < 25; ++i) {
      list.insert(list.begin() + i, i * 10);
      std::cout << "Inserted " << i * 10 << " | Current Size: " << list.size()
                << "\n";
    }
  } catch (const std::exception &e) {
    std::cerr << "Error during insertion: " << e.what() << "\n";
  }

  // Testing "Shifting" (Insert at index 0 multiple times)
  // This tests the logic of moving existing elements to the right.
  list.insert(list.begin(), 999);

  return 0;
}
