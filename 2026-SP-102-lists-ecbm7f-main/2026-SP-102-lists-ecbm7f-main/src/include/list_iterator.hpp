#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

template <typename T> class ListIterator {
public:
  virtual ~ListIterator() =
      default; // use default (empty) destructor, but make it virtual

  // Abstract operations
  virtual T &operator*() = 0;
  virtual ListIterator &operator++() = 0; // Prefix ++
  virtual ListIterator &operator--() = 0;
  virtual bool operator==(const ListIterator &other) const = 0;
  bool operator!=(const ListIterator &other) const { return !(*this == other); }
};

#endif
