#pragma once

#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <optional>

// TODO: Zaimplementuj klasę szablonową RingBuffer zgodnie z instrukcją (lab3.md).
// Metody definiuj poza klasą.

template <typename T, std::size_t Capacity = 8>
class RingBuffer {
    // Etap 1: pola + konstruktor + push + isEmpty/isFull/size
    // Etap 2: pop + front + back + operator<<
    // Etap 3: konstruktor z initializer_list
};

// Etap 4: specjalizacja RingBuffer<T, 1>
// template <typename T>
// class RingBuffer<T, 1> { ... };
