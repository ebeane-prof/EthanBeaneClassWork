#include "linked_list.hpp"
#include "test_utils.hpp"

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {

    using node = LinkedList<int>::Node;

    // make a chain of nodes to attach iterator to

    node* test_sentinel = new node;

    node* current_node = test_sentinel;
    for (int i = 0; i < 5; ++i) {
      current_node->next = new node(i, nullptr, current_node);
      current_node = current_node->next;
    }
    current_node->next = test_sentinel;
    test_sentinel->prev = current_node;
    

    LinkedList<int>::Iterator test_iter = LinkedList<int>::Iterator(test_sentinel->next);
    LinkedList<int>::Iterator orig_test_iter = LinkedList<int>::Iterator(test_sentinel->next);

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

    return true;
  });
}

