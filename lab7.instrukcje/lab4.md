# Szablony — stos o stałym rozmiarze (FixedStack)

## Wprowadzenie

Celem tego laboratorium jest od zera napisanie szablonowego **stosu (LIFO)** o stałym rozmiarze. W przeciwieństwie do kolejki FIFO (lab 3), stos dodaje i usuwa elementy z **tego samego końca** („wierzchu").

```
push(1):  [ 1 ]
push(2):  [ 1 | 2 ]       ← wierzch
push(3):  [ 1 | 2 | 3 ]
pop():    [ 1 | 2 ]       → zwraca 3
top():    2
```

Stos przechowuje elementy w tablicy statycznej — **bez `new` i `delete`**. Rozmiar tablicy ustalasz argumentem szablonowym `Capacity`.

## Wymagania ogólne

- **Wszystkie klasy piszesz od zera** — implementujesz wyłącznie plik `fixed_stack.hpp`.
- Metody szablonowe implementuj **poza definicją klasy**.
- Skorzystaj z dostarczonych plików: `Makefile`, `main.cpp`, `output.txt`.
- Po każdym etapie odkomentuj odpowiednią część `main.cpp`.
- Dozwolone nagłówki: `<iostream>`, `<optional>`, `<initializer_list>`, `<cstddef>`, `<utility>`.

## Pliki startowe

- `Makefile`
- `main.cpp`
- `output.txt`

## Pliki, które tworzysz

- `fixed_stack.hpp`

---

## Etap 1: Definicja klasy i `push` [4 pkt]

W pliku `fixed_stack.hpp` zdefiniuj klasę szablonową `FixedStack` z argumentami:

| Argument | Znaczenie | Domyślna wartość |
|----------|-----------|------------------|
| `T` | typ przechowywanych elementów | — |
| `Capacity` | maksymalna liczba elementów (`size_t`) | `8` |

Klasa powinna zawierać **prywatne pola**:
- `T data[Capacity]` — tablica elementów,
- `size_t topIndex` — liczba elementów na stosie (indeks następnego wolnego miejsca; `0` = pusty stos).

Zaimplementuj:

| Metoda | Opis |
|--------|------|
| `FixedStack()` | pusty stos: `topIndex = 0` |
| `bool isEmpty() const` | `true`, gdy `topIndex == 0` |
| `bool isFull() const` | `true`, gdy `topIndex == Capacity` |
| `size_t size() const` | zwraca `topIndex` |
| `bool push(const T& value)` | jeśli pełny → `false`; wstaw `value` pod `data[topIndex]`, zwiększ `topIndex`, zwróć `true` |

---

## Etap 2: `pop`, `top`, `operator<<` [4 pkt]

Dodaj:

| Metoda | Opis |
|--------|------|
| `bool pop()` | jeśli pusty → `false`; zmniejsz `topIndex`, zwróć `true` |
| `std::optional<T> top() const` | pusty stos → pusty `optional`; inaczej `data[topIndex - 1]` |
| `std::optional<T> popValue()` | jeśli pusty → pusty `optional`; inaczej zwróć element z wierzchu **i** usuń go (jak `pop` + odczyt w jednej operacji) |
| `friend operator<<` | wypisuje elementy **od spodu do wierzchu**, oddzielone spacją |

Przykład:
```
FixedStack<int, 4> s;
s.push(10); s.push(20); s.push(30);
std::cout << s;          // 10 20 30
auto v = s.popValue();   // v = 30
std::cout << s;          // 10 20
```

---

## Etap 3: Konstruktor z `initializer_list` i `clear` [3 pkt]

Dodaj:

| Metoda | Opis |
|--------|------|
| `FixedStack(std::initializer_list<T> list)` | wstawia elementy po kolei przez `push`; nadmiar ponad `Capacity` pomijaj |
| `void clear()` | usuwa wszystkie elementy (`topIndex = 0`) |

Przykład:
```cpp
FixedStack<char, 3> s = {'a', 'b', 'c', 'd'};  // w stosie: a b c (d odrzucone)
s.clear();                                       // pusty
```

---

## Etap 4: Specjalizacja `FixedStack<T, 0>` [4 pkt]

Napisz **pełną specjalizację** klasy:

```cpp
template <typename T>
class FixedStack<T, 0> { ... };
```

Stos o pojemności 0 **nigdy nie przechowuje elementów**:
- `push` zawsze zwraca `false`,
- `pop` zawsze zwraca `false`,
- `top()` i `popValue()` zawsze zwracają pusty `optional`,
- `isEmpty()` zawsze `true`, `isFull()` zawsze `true`,
- `size()` zawsze `0`,
- `clear()` nic nie robi,
- `operator<<` nic nie wypisuje.

W konstruktorze domyślnym wypisz na `std::cerr`:
```
Using FixedStack<T, 0> specialization
```

**Uwaga:** specjalizacja klasy wymaga implementacji **wszystkich** metod używanych w testach.

---

## Etap 5: Metoda `merge` [3 pkt]

Do **ogólnej** wersji szablonu (nie do specjalizacji `Capacity = 0`) dodaj metodę:

```cpp
FixedStack<T, Capacity> merge(const FixedStack<T, Capacity>& other) const;
```

Metoda zwraca **nowy stos** zawierający:
1. najpierw elementy z `this` (od spodu do wierzchu),
2. potem elementy z `other` (od spodu do wierzchu).

Jeśli łączna liczba elementów przekracza `Capacity`, **pomiń nadmiarowe** elementy z `other` (najpierw zapełnij z `this`, potem dodawaj z `other` aż do pełna).

Przykład (`Capacity = 4`):
```
this:   [1, 2]       → spód: 1, wierzch: 2
other:  [3, 4, 5]    → wynik: [1, 2, 3, 4]  (5 odrzucone)
```

---

## Rozwiązanie

- `fixed_stack.hpp`
- `main.cpp`
- `Makefile`

## Checklista

- [ ] Kod kompiluje się z `-std=c++17 -Wall -Wextra`
- [ ] Brak alokacji dynamicznej
- [ ] Metody zdefiniowane poza klasą
- [ ] Specjalizacja `FixedStack<T, 0>` kompiluje się i przechodzi testy
- [ ] Wszystkie etapy zgadzają się z `output.txt`
