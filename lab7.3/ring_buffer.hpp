#pragma once
#include <cstddef>
#include <iostream>

// TODO: Zaimplementuj klasę szablonową RingBuffer zgodnie z instrukcją
// (lab3.md). Metody definiuj poza klasą.

template <typename T, std::size_t Capacity = 8> class RingBuffer {
  // Etap 1: pola + konstruktor + push + isEmpty/isFull/size
protected:
  T data[Capacity];
  size_t head;
  size_t tail;
  size_t count;

public:
  RingBuffer() : head(0), tail(0), count(0) {}
  bool isEmpty() const { return count == 0; }
  bool isFull() const { return count == Capacity; }
  size_t size() const { return count; }
  bool push(const T &value);
  // Etap 2: po p + front + back + operator<<
  // Etap 3: konstruktor z initializer_list
};

// Etap 4: specjalizacja RingBuffer<T, 1>
// template <typename T>
// class RingBuffer<T, 1> { ... };
template <typename T, std::size_t Capacity>
bool RingBuffer<T, Capacity>::push(const T &value) {
  if (isFull())
    return false;

  tail = static_cast<size_t>(value);
}