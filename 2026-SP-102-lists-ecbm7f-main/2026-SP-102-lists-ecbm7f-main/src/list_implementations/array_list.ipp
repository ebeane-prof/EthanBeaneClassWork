/*
Iterator Implmentation
    Implement the following functions according to the interface defined in
`include/list_iterator.hpp` Reference the class definition for
ArrayList::Iterator in `include/array_list.hpp` Complete this section before
proceeding to List Implementation
*/

// de-reference.
// Returns: the data element (T) referenced by the iterator
template <typename T> T &ArrayList<T>::Iterator::operator*() {
	return *ptr;
}

// testing git2
// pre-increment. Advance the iterator forward by one
// Returns: the calling object, after advancement
template <typename T> ListIterator<T> &ArrayList<T>::Iterator::operator++() {
	ptr++;
	return *this;
}

// pre-decrement. Advance the iterator backward by one
// Returns: the calling object, after advancement
template <typename T> ListIterator<T> &ArrayList<T>::Iterator::operator--() {
	ptr--;
	return *this;
}

// END Iterator Implementation

/*
List Implementation
    Implement the following functions according to the interface defined in
`include/list.hpp` Reference the class definition for ArrayList in
`include/array_list.hpp` Complete the functions in order, testing each
individually before proceeding
*/

// allocate a new storage array of length 'new_max_elems`, copying data over
template <typename T> void ArrayList<T>::reserve(int new_max_elems) {
	if (new_max_elems <= (int)max_elems) return;
	T* new_data = new T[new_max_elems];
	
	for (unsigned int i = 0; i < num_elems; i++) {
		new_data[i] = data[i];
	}

	delete[] data;
	data = new_data;
	max_elems = new_max_elems;


}

// insert a new element at the position referenced by the iterator (pos)
template <typename T>
void ArrayList<T>::insert(const ListIterator<T> &pos, const T &value) {
	unsigned int index = get_index(pos);
	if (num_elems == max_elems) {
		reserve(max_elems * 2);
	}
	for (unsigned int i = num_elems; i > index; i--) {
		data[i] = data[i - 1];
	}
	data[index] = value;
	num_elems++;

}

// remove the element at the position referenced by the iterator (pos)
template <typename T> void ArrayList<T>::erase(const ListIterator<T> &pos) {
	unsigned int index = get_index(pos);
	for (unsigned int i = index; i < num_elems - 1; i++) {
		data[i] = data[i + 1];
	}
	num_elems--;
}

// destructor. De-allocate all dynamic memory tied to the calling object
template <typename T> ArrayList<T>::~ArrayList() {
	delete[] data;


}

// assignment operator. Make the calling object into a copy of the argument
// (other) Returns: the calling object, after assignment
template <typename T>
ArrayList<T> &ArrayList<T>::operator=(const ArrayList<T> &other) {
	if (this == &other) return *this;

	delete[] data;

	num_elems = other.num_elems;
	max_elems = other.max_elems;
	
	data = new T[max_elems];
	for (unsigned int i = 0; i < num_elems; i++) {
		data[i] = other.data[i];
	}

	return *this;

}

// copy constructor. Initialize the calling object as a copy of the argument
// (other)
template <typename T> ArrayList<T>::ArrayList(const ArrayList<T> &other) {
	num_elems = other.num_elems;
	max_elems = other.max_elems;
	
	data = new T[max_elems];
	for (unsigned int i = 0; i < num_elems; i++) {
		data[i] = other.data[i];
	}

}

// END List Implmentation

/*
Provided Functions
    The following functions are not tested and you do not need to change them.
    You may reference them while working on your assignment and use them freely.
    Altering the functions in this section may cause your tests to fail!
*/

template <typename T> ArrayList<T>::Iterator::Iterator(T *p) : ptr(p) {}

template <typename T>
typename ArrayList<T>::Iterator
ArrayList<T>::Iterator::operator+(const int &inc) const {
  Iterator copy = *this;
  copy.ptr += inc;
  return copy;
}

template <typename T>
typename ArrayList<T>::Iterator
ArrayList<T>::Iterator::operator-(const int &dec) const {

  return *this + (-dec);
}

template <typename T>
bool ArrayList<T>::Iterator::operator==(const ListIterator<T> &other) const {
  // Since 'other' could be ArrayList or LinkedList iterator, we need to check
  // the dynamic type
  const Iterator *otherPtr = dynamic_cast<const Iterator *>(&other);

  // If the cast fails (returns nullptr), they aren't the same type,
  // so they definitely aren't equal.
  if (!otherPtr)
    return false;

  // If they are the same type, compare the actual memory addresses
  return this->ptr == otherPtr->ptr;
}

template <typename T> ArrayList<T>::ArrayList() : num_elems(0), max_elems(8) {
  data = new T[max_elems];
}

template <typename T>
typename ArrayList<T>::Iterator ArrayList<T>::begin() const {
  return ArrayList<T>::Iterator(data);
}

template <typename T>
typename ArrayList<T>::Iterator ArrayList<T>::end() const {
  return ArrayList<T>::Iterator(data + num_elems);
}

template <typename T>
unsigned int ArrayList<T>::get_index(const ListIterator<T> &iter) const {
  // 1. Cast to dynamic type to access the private ptr
  const auto &actual_iter = dynamic_cast<const Iterator &>(iter);

  // 2. Pointer subtraction: (Target Address - Base Address) = Index
  if (actual_iter.ptr != nullptr) {
    return actual_iter.ptr - data;
  } else {
    throw std::invalid_argument(
        "method get_index only supports ArrayList<T>::Iterator");
  }
}
// END Provided Functions
