#ifndef LIST_HPP
#define LIST_HPP

#include "list_iterator.hpp"

template <typename T> class List {
public:
  virtual ~List() =
      default; // use default (empty) destructor, but make it virtual

  // Pure virtual interface
  virtual unsigned int size() const = 0;
  virtual void insert(const ListIterator<T> &pos, const T &value) = 0;
  virtual void erase(const ListIterator<T> &pos) = 0;
};

#endif
