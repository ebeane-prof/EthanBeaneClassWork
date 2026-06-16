#include "array_list.hpp"
#include "test_utils.hpp"

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {

    // make a dynamic array to attach iterator to

    int* test_array = new int[8];
    for (int i = 0; i < 8; ++i) {
      test_array[i] = i;
    }

    ArrayList<int>::Iterator test_iter = ArrayList<int>::Iterator(test_array);
    ArrayList<int>::Iterator orig_test_iter = ArrayList<int>::Iterator(test_array);

    // testing basic dereference
    if (*test_iter != 0)
    {
      std::cerr<<"dereference operator failed";
      return false;
    }

    // testing pre-increment
    ++test_iter;
    ++test_iter;
    ++test_iter;
    // does it point to the right value, and did it actually move the iterator?
    if (*test_iter != 3 || test_iter == orig_test_iter)
    {
      std::cerr<<"pre-increment operator failed";
      return false;
    }    

    // testing pre-decrement
    --test_iter;
    if (*test_iter != 2)
    {
      std::cerr<<"pre-decrement operator failed";
      return false;
    }

    // testing + operator
    if (*(test_iter+5) != 7)        
    {
      std::cerr<<"+ operator failed";
      return false;
    }

    // testing - operator
    if (*(test_iter-2) != 0)        
    {
      std::cerr<<"- operator failed";
      return false;
    }

    return true;
  });
}

