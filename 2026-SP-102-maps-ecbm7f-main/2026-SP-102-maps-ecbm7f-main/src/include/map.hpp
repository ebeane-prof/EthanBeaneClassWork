#ifndef MAP_HPP
#define MAP_HPP

#include <functional>

template <typename K, typename V> class Map {
public:
  virtual ~Map() = default;

  // Core Operations
  virtual void put(const K &key, const V &value) = 0;
  virtual V get(const K &key) const = 0;
  virtual bool contains(const K &key) const = 0;
  virtual void remove(const K &key) = 0;

  // State Queries
  virtual unsigned int size() const = 0;
};

#endif
