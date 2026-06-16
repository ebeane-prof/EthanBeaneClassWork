#include "list_iterator.hpp"

/*
    Here is where you'll write algorithms used to benchmark your lists.
    You are only allowed to use the methods defined in
   `include/list_iterator.hpp` These functions should work the same regardless
   of which list it is applied to. See `src/example_mains/generic_list.cpp` for
   an example of generic iterator logic.
*/

template <typename Iterator, typename T>
bool linear_search(Iterator start, Iterator end, const T &target) {
  while (start != end) {
    if (*start == target) {
      return true;
    }
    ++start;
  }
  return false;
}

template <typename Iterator, typename T>
void selection_sort(Iterator start, Iterator end) {
  for (Iterator i = start; i != end; ++i) {
    Iterator min_it = i;
    Iterator j = i;
    ++j;

    // Find the minimum in the remaining unsorted part
    for (; j != end; ++j) {
      if (*j < *min_it) {
        min_it = j;
      }
    }

    // Swap the found minimum with the current position
    if (min_it != i) {
      T temp = *min_it;
      *min_it = *i;
      *i = temp;
    }
  }
}
