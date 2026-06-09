#pragma once
#include "hasher.hpp"
#include <cstddef>
#include <optional>
#include <ostream>
template <typename K, typename V> class KeyValuePair {
protected:
  K key;
  V value;
  KeyValuePair<K, V> *next;

public:
  KeyValuePair(K key, V value) : key(key), value(value), next(nullptr) {}
};

template <typename K, typename V, int Capacity> class Dictionary {
protected:
  KeyValuePair<K, V> *table[Capacity];

public:
  Dictionary();
  ~Dictionary();

  std::size_t hash(const K &key);
  void insert(const K &key, const V &value);

  template <typename K_, typename V_, int Capacity_>
  friend std::ostream &operator<<(std::ostream &os,
                                  const Dictionary<K_, V_, Capacity_> &d);

  const V &operator[](const K &key);
  std::optional<V> get(const K &key) const;
  bool remove(const K &key);
};
template <typename K, typename V, int Capacity>
Dictionary<K, V, Capacity>::Dictionary() {
  for (auto *it : table) {
    it = nullptr;
  }
}
template <typename K, typename V, int Capacity>
Dictionary<K, V, Capacity>::~Dictionary() {
  for (auto *value : table) {
    auto *next = value;
    auto *curr = value;

    while (next != nullptr) {
      curr = next;
      next = curr->next;
      curr = nullptr;
    }

    value = nullptr;
  }
}
template <typename K, typename V, int Capacity>
size_t Dictionary<K, V, Capacity>::hash(const K &key) {
  size_t rtr = Hash<K>(key);
  rtr = rtr % Capacity;
  return rtr;
}
template <typename K, typename V, int Capacity>
void Dictionary<K, V, Capacity>::insert(const K &key, const V &value) {
  size_t idx = hash(key);

  auto *nowy = new KeyValuePair<K, V>(key, value);

  if (table[idx] == nullptr) {
    table[idx] = nowy;
  } else {
    auto *temp = table[idx];
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = nowy;
  }
}
template <typename K, typename V, int Capacity>
std::ostream &operator<<(std::ostream &os,
                         const Dictionary<K, V, Capacity> &d) {
  // operaoyt wypisyuwania
  for (const auto *it : d.table) {
    os << "Key: " << it->key << "\n";
    auto *temp = it;
    while (temp != nullptr) {
      os << temp->value << " ";
      temp = temp->next;
    }
    os << "\n";
  }
}
template <typename K, typename V, int Capacity>
const V &Dictionary<K, V, Capacity>::operator[](const K &key) {
  size_t idx = hash(key);
  auto *nowy = new KeyValuePair<K, V>(key, V{});

  if (table[idx] == nullptr) {
    table[idx] = nowy;
    return nowy->value;
  }
  // tutaj nie wiem do konca o co chodzi w poleceniu
  auto *temp = table[idx];
  while (temp->next != nullptr) {
    if (temp->key == key) {
      return temp->value;
    }
    temp = temp->next;
  }
  temp->next = nowy;
  return nowy->value;
}
template <typename K, typename V, int Capacity>
std::optional<V> Dictionary<K, V, Capacity>::get(const K &key) const {
  size_t idx = hash(key);
  if (table[idx] == nullptr) {
    return std::nullopt;
  }
  auto *temp = table[idx];
  while (temp->next != nullptr) {
    if (temp->key == key) {
      return temp->value;
    }
    temp = temp->next;
  }
  return std::nullopt;
}

template <typename K, typename V, int Capacity>
bool Dictionary<K, V, Capacity>::remove(const K &key) {
  size_t idx = hash(key);
  if (table[idx] == nullptr) {
    return false;
  }
  auto *temp = table[idx];
  KeyValuePair<K, V> *prev = nullptr;

  while (temp != nullptr) {
    if (temp->key == key) {
      prev->next = temp->next;
      temp = nullptr;
      // czy musze robic free?
      return true;
    }
    prev = temp;
    temp = temp->next;
  }
  return false;
}