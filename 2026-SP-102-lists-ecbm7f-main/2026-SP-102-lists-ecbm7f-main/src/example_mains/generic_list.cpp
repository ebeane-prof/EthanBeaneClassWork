#include "array_list.hpp"
#include "linked_list.hpp"
#include <iostream>
#include <string>

// Purely Iterator-Based (No List needed)
// This counts occurrences. It only needs to know where to start and stop.
template <typename T>
int generic_count(ListIterator<T> &start, ListIterator<T> &end,
                  const T &target) {
  int count = 0;
  while (start != end) {
    if (*start == target) {
      count++;
    }
    ++start;
  }
  return count;
}

int main() {
  ArrayList<std::string> a_list;
  LinkedList<std::string> l_list;

  // Populate data
  auto a_insert_pos = a_list.begin();
  a_list.insert(a_insert_pos, "Apple");
  a_list.insert(a_insert_pos, "Banana");
  a_list.insert(a_insert_pos, "Apple");

  auto l_insert_pos = l_list.begin();
  l_list.insert(l_insert_pos, "Apple");
  l_list.insert(l_insert_pos, "Banana");
  l_list.insert(l_insert_pos, "Apple");

  // --- Testing Generic Count ---
  auto a_start = a_list.begin();
  auto a_end = a_list.end();
  std::cout << "ArrayList 'Apple' count: "
            << generic_count(a_start, a_end, std::string("Apple")) << "\n";

  auto l_start = l_list.begin();
  auto l_end = l_list.end();
  std::cout << "LinkedList 'Apple' count: "
            << generic_count(l_start, l_end, std::string("Apple")) << "\n";

  return 0;
}
