#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "list.hpp"
#include "list_iterator.hpp"
#include <stdexcept>

template <typename T> class LinkedList : public List<T> {
public:
  struct Node {
    T data;
    Node *next;
    Node *prev;
    Node(const T &d, Node *n, Node *p) : data(d), next(n), prev(p) {}
    Node(const T &d) : data(d), next(nullptr), prev(nullptr) {}
    Node() : next(this), prev(this) {}
  };

private:
  Node *sentinel; // "empty" node where 'next' points to the head and 'prev'
                  // points to the tail
  unsigned int num_elems;

public:
  class Iterator : public ListIterator<T> {
    friend class LinkedList<T>;

  public:
    // This class exists in the "LinkedList" namespace
    // example: LinkedList<int>::Iterator it = myLL.begin()
    Iterator(Node *p);
    T &operator*() override;
    ListIterator<T> &operator++() override;
    ListIterator<T> &operator--() override;
    bool operator==(const ListIterator<T> &other) const override;
    // bool operator!=(const ListIterator<T>& other) const override;
  private:
    Node *ptr;
  };

  // Iterator-related methods
  Iterator begin() const;
  Iterator end() const;
  typename LinkedList<T>::Node *get_pointer(const ListIterator<T> &iter) const;

  // Constructors & default member functions
  LinkedList();
  LinkedList(const LinkedList<T> &other);
  ~LinkedList() override;
  LinkedList<T> &operator=(const LinkedList<T> &other);

  // List operations
  unsigned int size() const override { return num_elems; }
  void insert(const ListIterator<T> &pos, const T &value) override;
  void erase(const ListIterator<T> &pos) override;
};

#include "../list_implementations/linked_list.ipp"
#endif
