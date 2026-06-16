#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include "list.hpp"
#include "list_iterator.hpp"
#include <stdexcept>

template <typename T> class ArrayList : public List<T> {
private:
  T *data;
  unsigned int num_elems;
  unsigned int max_elems;

public:
  class Iterator : public ListIterator<T> {
    friend class ArrayList<T>;

  public:
    // This class exists in the "ArrayList" namespace
    // example: ArrayList<int>::Iterator it = myAL.begin()
    Iterator(T *p);
    T &operator*() override;
    ListIterator<T> &operator++() override;
    ListIterator<T> &operator--() override;
    typename ArrayList<T>::Iterator operator+(const int &inc) const;
    typename ArrayList<T>::Iterator operator-(const int &dec) const;
    bool operator==(const ListIterator<T> &other) const override;

  private:
    T *ptr;
  };

  // Iterator-related methods
  Iterator begin() const;
  Iterator end() const;
  unsigned int get_index(const ListIterator<T> &iter) const;

  // Constructors & default member functions
  ArrayList();
  ~ArrayList() override;
  ArrayList(const ArrayList<T> &other);
  ArrayList<T> &operator=(const ArrayList<T> &other);

  // Array-specific methods
  void reserve(int new_max_elems);
  unsigned int capacity() { return max_elems; }

  // List operations
  unsigned int size() const override { return num_elems; }
  void insert(const ListIterator<T> &pos, const T &value) override;
  void erase(const ListIterator<T> &pos) override;
};

#include "../list_implementations/array_list.ipp"
#endif
