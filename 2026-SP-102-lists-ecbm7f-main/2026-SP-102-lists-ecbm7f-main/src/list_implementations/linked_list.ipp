/*
Iterator Implmentation
    Implement the following functions according to the interface defined in
`include/list_iterator.hpp` Reference the class definition for
LinkedList::Iterator in `include/linked_list.hpp` Complete this section before
proceeding to List Implementation
*/

// de-reference.
// Returns: the data element (T) referenced by the iterator
template <typename T> T &LinkedList<T>::Iterator::operator*() {
	return ptr->data;
}

// pre-increment. Advance the iterator forward by one
// Returns: the calling object, after advancement
template <typename T> ListIterator<T> &LinkedList<T>::Iterator::operator++() {
	ptr = ptr->next;
	return *this;

}

// pre-decrement. Advance the iterator backward by one
// Returns: the calling object, after advancement
template <typename T> ListIterator<T> &LinkedList<T>::Iterator::operator--() {
	ptr = ptr->prev;
	return *this;
}

// END Iterator Implementation

/*
List Implementation
    Implement the following functions according to the interface defined in
`include/list.hpp` Reference the class definition for LinkedList in
`include/linked_list.hpp` Complete the functions in order, testing each
individually before proceeding
*/

// insert a new element at the position referenced by the iterator (pos)
template <typename T>
void LinkedList<T>::insert(const ListIterator<T> &pos, const T &value) {
	Node* curr = get_pointer(pos);

	Node* new_node = new Node(value);

	new_node->next = curr;
	new_node->prev = curr->prev;

	curr->prev->next = new_node;
	curr->prev = new_node;

	num_elems++;
}

// remove the element at the position referenced by the iterator (pos)
template <typename T> void LinkedList<T>::erase(const ListIterator<T> &pos) {
	Node* curr = get_pointer(pos);

	if (curr == sentinel) return; // never remove sentinel

	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;

	delete curr;
	num_elems--;

}

// destructor. De-allocate all dynamic memory tied to the calling object
template <typename T> LinkedList<T>::~LinkedList() {
	Node* curr = sentinel->next;

	while (curr != sentinel) {
		Node* temp = curr;
		curr = curr->next;
		delete temp;
	}

	delete sentinel;
}

// assignment operator. Make the calling object into a copy of the argument
// (other) Returns: the calling object, after assignment
template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other) {
	if (this == &other) return *this;

// clear what list i have curr
	Node* curr = sentinel->next;
	while (curr != sentinel) {
		Node* temp = curr;
		curr = curr->next;
		delete temp;
	}

	sentinel->next = sentinel;
	sentinel->prev = sentinel;
	num_elems = 0;

  // copying element
	Node* other_curr = other.sentinel->next;
	while (other_curr != other.sentinel) {
		insert(end(), other_curr->data);
		other_curr = other_curr->next;
	}

	return *this;
}

// copy constructor. Initialize the calling object as a copy of the argument
// (other)
template <typename T> LinkedList<T>::LinkedList(const LinkedList<T> &other) {
	sentinel = new Node();
	sentinel->next = sentinel;
	sentinel->prev = sentinel;
	num_elems = 0;
	Node* curr = other.sentinel->next;
	while (curr != other.sentinel) {
		insert(end(), curr->data);
		curr = curr->next;
	}
}

// END List Implementation

/*
Provided Functions
    The following functions are not tested and you do not need to change them.
    You may reference them while working on your assignment and use them freely.
    Altering the functions in this section may cause your tests to fail!
*/
template <typename T> LinkedList<T>::Iterator::Iterator(Node *n) : ptr(n) {}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() const {
  return LinkedList<T>::Iterator(sentinel->next);
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end() const {
  return LinkedList<T>::Iterator(sentinel);
}

template <typename T>
typename LinkedList<T>::Node *
LinkedList<T>::get_pointer(const ListIterator<T> &iter) const {
  // 1. Cast to dynamic type to access the private ptr
  const auto &actual_iter = dynamic_cast<const Iterator &>(iter);

  if (actual_iter.ptr != nullptr) {
    return actual_iter.ptr;
  } else {
    throw std::invalid_argument(
        "method get_pointer only supports LinkedList<T>::Iterator");
  }
}

template <typename T>
bool LinkedList<T>::Iterator::operator==(const ListIterator<T> &other) const {
  // Since 'other' could be ArrayList or LinkedList iterator, we need to check
  // the dynamic type
  const Iterator *otherPtr = dynamic_cast<const Iterator *>(&other);

  // If the cast fails (returns nullptr), they aren't the same type,
  // so they definitely aren't equal.
  if (!otherPtr)
    return false;

  // If they are the same type, compare if they are pointing to the exact same
  // Node in memory
  return this->ptr == otherPtr->ptr;
}

template <typename T> LinkedList<T>::LinkedList() : num_elems(0) {
  sentinel = new Node;
}

// END Provided Functions
