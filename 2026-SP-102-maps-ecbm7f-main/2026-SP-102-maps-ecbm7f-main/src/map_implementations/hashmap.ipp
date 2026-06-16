#ifndef HASHMAP_IPP
#define HASHMAP_IPP

// Methods to implement for the assignment

// Calculate and return the current load factor
template <typename K, typename V> double HashMap<K, V>::load_factor() const {
  return static_cast<double>(num_elems) / static_cast<double>(num_buckets);
}

// Resize and rehash the storage array
template <typename K, typename V>
void HashMap<K, V>::rehash(unsigned int new_num_buckets) {
  std::list<std::pair<K, V>> *old_buckets = buckets;
  unsigned int old_num_buckets = num_buckets;

  num_buckets = new_num_buckets;
  buckets = new std::list<std::pair<K, V>>[num_buckets];

  for (unsigned int i = 0; i < old_num_buckets; ++i) {
    for (auto record : old_buckets[i]) {
      unsigned int index = std::hash<K>{}(record.first) % num_buckets;

      buckets[index].push_back(record);
    }
  }

  delete[] old_buckets;
}

// If the key already exists in the map, update the value of that record
// If the key does not exist, insert a new record,
//   doubling the size of the storage array if the load factor exceeds 0.7
template <typename K, typename V>
void HashMap<K, V>::put(const K &key, const V &value) {
  unsigned int index = hash(key);

  for (auto &record : buckets[index]) {
    if (record.first == key) {
      record.second = value;
      return;
    }
  }

  buckets[index].push_back(std::make_pair(key, value));
  ++num_elems;

  if (load_factor() > MAX_LOAD_FACTOR) {
    rehash(num_buckets * 2);
  }
}

// Return true if a record with the target key exists, and false otherwise
template <typename K, typename V>
bool HashMap<K, V>::contains(const K &key) const {
  unsigned int index = hash(key);

  for (auto record : buckets[index]) {
    if (record.first == key) {
      return true;
    }
  }

  return false;
}

// Remove the record with the target key
template <typename K, typename V> void HashMap<K, V>::remove(const K &key) {
  unsigned int index = hash(key);

  for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it) {
    if (it->first == key) {
      buckets[index].erase(it);
      --num_elems;
      return;
    }
  }

  throw std::invalid_argument("key not found");
}

// Assignment operator
template <typename K, typename V>
HashMap<K, V> &HashMap<K, V>::operator=(const HashMap<K, V> &other) {
  if (this != &other) {
    delete[] buckets;

    num_elems = other.num_elems;
    num_buckets = other.num_buckets;

    buckets = new std::list<std::pair<K, V>>[num_buckets];

    for (unsigned int i = 0; i < num_buckets; ++i) {
      buckets[i] = other.buckets[i];
    }
  }

  return *this;
}

// Copy Constructor
template <typename K, typename V>
HashMap<K, V>::HashMap(const HashMap<K, V> &other) {
  num_elems = other.num_elems;
  num_buckets = other.num_buckets;

  buckets = new std::list<std::pair<K, V>>[num_buckets];

  for (unsigned int i = 0; i < num_buckets; ++i) {
    buckets[i] = other.buckets[i];
  }
}

// Provided Methods

template <typename K, typename V>
unsigned int HashMap<K, V>::hash(const K &key) const {
  return std::hash<K>{}(key) % num_buckets;
}

template <typename K, typename V> HashMap<K, V>::HashMap() {
  num_elems = 0;
  num_buckets = 256;

  buckets = new std::list<std::pair<K, V>>[num_buckets];
}

template <typename K, typename V> HashMap<K, V>::~HashMap() {
  delete[] buckets;
}

template <typename K, typename V> V HashMap<K, V>::get(const K &key) const {
  std::list<std::pair<K, V>> bucket = buckets[hash(key)];

  for (auto record : bucket) {
    if (record.first == key) {
      return record.second;
    }
  }

  throw std::invalid_argument("key not found");
}

template <typename K, typename V> unsigned int HashMap<K, V>::size() const {
  return num_elems;
}

template <typename K, typename V> void HashMap<K, V>::clear() {
  for (int i = 0; i < num_buckets; ++i) {
    buckets[i].clear();
  }
  num_elems = 0;
}

// template <typename K, typename V>
// void HashMap<K, V>::for_each(
//     std::function<void(const K &, const V &)> action) const {
//   for (unsigned int b = 0; b < num_buckets; ++b) {
//     for (auto it = buckets[b].begin(); it != buckets[b].end(); ++it) {
//       action(it->first, it->second);
//     }
//   }
// }
#endif // HASHMAP_IPP
