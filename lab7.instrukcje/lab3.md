# Szablony — kolejka cykliczna (RingBuffer)

## Wprowadzenie

Szablony w C++ pozwalają pisać kod działający na różnych typach danych bez powielania logiki. W tym laboratorium od zera zaimplementujesz szablonową **kolejkę FIFO o stałym rozmiarze** (bufor cykliczny).

Kolejka:
- dodaje elementy na koniec (`push`),
- usuwa z początku (`pop`),
- gdy jest pełna — `push` zwraca `false` i **nie dodaje** elementu,
- gdy jest pusta — `pop` zwraca `false`.

Dane trzymasz w tablicy o stałym rozmiarze ustalonym w czasie kompilacji — **bez `new` i `delete`**.

```
Stan początkowy:  [ _ | _ | _ | _ ]   count=0

push(10):         [10 | _ | _ | _ ]   head=0, tail=1, count=1
push(20):         [10 | 20 | _ | _ ]  head=0, tail=2, count=2
push(30):         [10 | 20 | 30 | _ ] head=0, tail=3, count=3

pop():            [ _ | 20 | 30 | _ ]  head=1, count=2  → zwraca 10
```

## Wymagania ogólne

- **Wszystkie klasy piszesz od zera** — jedyny plik, który implementujesz, to `ring_buffer.hpp`.
- Metody szablonowe implementuj **poza definicją klasy**.
- Skorzystaj z dostarczonych plików: `Makefile`, `main.cpp` (testy podzielone na etapy), `output.txt`.
- Po ukończeniu etapu odkomentuj odpowiednią sekcję w `main.cpp` i porównaj wynik z oczekiwanym.
- Dozwolone nagłówki: `<iostream>`, `<optional>`, `<initializer_list>`, `<cstddef>`.

## Pliki startowe

- `Makefile`
- `main.cpp`
- `output.txt`

## Pliki, które tworzysz

- `ring_buffer.hpp`

---

## Etap 1: Definicja klasy i podstawowe operacje [4 pkt]

W pliku `ring_buffer.hpp` zdefiniuj klasę szablonową `RingBuffer` z argumentami:

| Argument | Znaczenie | Domyślna wartość |
|----------|-----------|------------------|
| `T` | typ przechowywanych elementów | — |
| `Capacity` | maksymalna liczba elementów (`size_t`) | `8` |

Klasa powinna zawierać **prywatne pola**:
- `T data[Capacity]` — tablica elementów,
- `size_t head` — indeks pierwszego (najstarszego) elementu,
- `size_t tail` — indeks miejsca, gdzie trafi następny element,
- `size_t count` — aktualna liczba elementów.

Zaimplementuj:

| Metoda | Opis |
|--------|------|
| `RingBuffer()` | pusty bufor: `count = 0`, `head = 0`, `tail = 0` |
| `bool isEmpty() const` | `true`, gdy `count == 0` |
| `bool isFull() const` | `true`, gdy `count == Capacity` |
| `size_t size() const` | zwraca `count` |
| `bool push(const T& value)` | jeśli pełny → `false`; wstaw `value` pod `tail`, przesuń `tail` cyklicznie (`(tail + 1) % Capacity`), zwiększ `count`, zwróć `true` |

---

## Etap 2: `pop`, `front`, `back`, `operator<<` [4 pkt]

Dodaj:

| Metoda | Opis |
|--------|------|
| `bool pop()` | jeśli pusty → `false`; przesuń `head` cyklicznie, zmniejsz `count`, zwróć `true` |
| `std::optional<T> front() const` | pusty bufor → pusty `optional`; inaczej `data[head]` |
| `std::optional<T> back() const` | pusty bufor → pusty `optional`; inaczej element pod `(tail + Capacity - 1) % Capacity` |
| `friend operator<<` | wypisuje elementy od najstarszego do najnowszego, oddzielone spacją |

Przykład:
```
RingBuffer<int, 4> q;
q.push(10); q.push(20); q.push(30);
std::cout << q;   // 10 20 30
q.pop();
std::cout << q;   // 20 30
```

---

## Etap 3: Konstruktor z `initializer_list` [3 pkt]

Dodaj konstruktor:

```cpp
RingBuffer(std::initializer_list<T> list);
```

Zasady:
1. Elementy wstawiaj po kolei przez `push`.
2. Jeśli lista ma więcej elementów niż `Capacity`, **pomiń nadmiar**.
3. Gdy `push` zwróci `false`, przestań dodawać.

Przykład:
```cpp
RingBuffer<int, 3> q = {1, 2, 3, 4, 5};  // w buforze: 1 2 3
```

---

## Etap 4: Specjalizacja `RingBuffer<T, 1>` [4 pkt]

Napisz **pełną specjalizację** klasy:

```cpp
template <typename T>
class RingBuffer<T, 1> { ... };
```

Dla bufora o pojemności 1:
- `push` **zawsze** zwraca `true`:
  - pusty bufor → normalne dodanie,
  - pełny bufor → **nadpisz** istniejący element (bez zmiany `count` powyżej 1).
- `pop`, `front`, `back`, `isEmpty`, `isFull`, `size`, `operator<<` — działają analogicznie do wersji ogólnej.
- W konstruktorze domyślnym wypisz na `std::cerr`:
  ```
  Using RingBuffer<T, 1> specialization
  ```

**Uwaga:** specjalizacja klasy wymaga implementacji **wszystkich** metod używanych w testach.

---

## Rozwiązanie

- `ring_buffer.hpp`
- `main.cpp`
- `Makefile`

## Checklista

- [ ] Kod kompiluje się z `-std=c++17 -Wall -Wextra`
- [ ] Brak alokacji dynamicznej
- [ ] Metody zdefiniowane poza klasą
- [ ] Wszystkie etapy zgadzają się z `output.txt`
