#pragma once
#include <iostream>

template <typename K> struct Hash {
  size_t operator()(const K &key) const { return std::hash<K>{}(key); }
};

template <> struct Hash<int> {
  size_t operator()(int key) const { return key; }
};