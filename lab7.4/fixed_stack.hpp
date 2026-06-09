#pragma once

#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <optional>

// TODO: Zaimplementuj klasę szablonową FixedStack zgodnie z instrukcją (lab4.md).
// Metody definiuj poza klasą.

template <typename T, std::size_t Capacity = 8>
class FixedStack {
    // Etap 1: pola + konstruktor + push + isEmpty/isFull/size
    // Etap 2: pop + top + popValue + operator<<
    // Etap 3: konstruktor z initializer_list + clear
    // Etap 5: merge
};

// Etap 4: specjalizacja FixedStack<T, 0>
// template <typename T>
// class FixedStack<T, 0> { ... };
