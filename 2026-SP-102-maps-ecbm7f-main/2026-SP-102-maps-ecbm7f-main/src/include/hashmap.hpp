#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include "map.hpp"
#include <functional>
#include <list>
#include <stdexcept>

template <typename K, typename V> class HashMap : public Map<K, V> {

  const double MAX_LOAD_FACTOR = 0.7;

  std::list<std::pair<K, V>> *buckets;
  unsigned int num_elems;
  unsigned int num_buckets;

  unsigned int hash(const K &key) const;
  void rehash(unsigned int new_num_buckets);

public:
  HashMap();

  ~HashMap() override;
  HashMap<K, V> &operator=(const HashMap<K, V> &other);
  HashMap(const HashMap<K, V> &other);
  void clear();

  // Core Operations
  void put(const K &key, const V &value) override;
  V get(const K &key) const override;
  bool contains(const K &key) const override;
  void remove(const K &key) override;

  // State Queries
  double load_factor() const;
  unsigned int size() const override;
};

#include "../map_implementations/hashmap.ipp"

#endif
