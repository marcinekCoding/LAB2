#pragma once
#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>

// =========================================================================
// 1. PODSTAWOWY SZABLON KLASY Z DYNAMICZNĄ PAMIĘCIĄ
// Kompendium wiedzy o klasach szablonowych i zarządzaniu pamięcią
// =========================================================================
template <typename T, size_t DomyślnyRozmiar = 10> 
class SzablonowaKlasa {
protected: // protected, aby klasy dziedziczące (pochodne) miały do tego dostęp
    T* tablica;       // Wskaźnik - przykład dynamicznej alokacji (WYMAGA Rule of Three!)
    size_t pojemnosc;
    size_t ilosc_elementow;

public:
    // A. Konstruktory
    SzablonowaKlasa();
    SzablonowaKlasa(size_t rozmiar);
    
    // B. Konstruktor z listą inicjalizacyjną (pozwala na: auto x = {1, 2, 3}; )
    SzablonowaKlasa(std::initializer_list<T> lista);

    // =====================================================================
    // 2. ZASADA WIELKIEJ TRÓJKI (Rule of Three) - Niezbędne gdy masz 'new'!
    // =====================================================================
    
    // 1/3 Destruktor (Zwalnianie pamięci, chroni przed wyciekami)
    ~SzablonowaKlasa();

    // 2/3 Konstruktor kopiujący (Tworzenie obiektu na podstawie innego: Klasa a = b;)
    SzablonowaKlasa(const SzablonowaKlasa& inna);

    // 3/3 Operator przypisania (Nadpisywanie istniejącego obiektu: a = b;)
    // Brak tego to najczęstsza przyczyna błędu "Double Free"!
    SzablonowaKlasa& operator=(const SzablonowaKlasa& inna);

    // =====================================================================
    // 3. PRZECIĄŻANIE OPERATORÓW (Operator Overloading)
    // =====================================================================

    // Operator[] (Odczyt i zapis: k[0] = 5;) - Zwraca referencję!
    T& operator[](size_t index);
    
    // Wersja operatora[] dla obiektów stałych (Tylko odczyt: cout << k[0];)
    const T& operator[](size_t index) const;

    // Operator dodawania (Tworzy i zwraca NOWY obiekt)
    SzablonowaKlasa operator+(const SzablonowaKlasa& inna) const;

    // Operator strumienia (<<) - ZAPRZYJAŹNIONY SZABLON (friend)
    // Złota zasada kompilatora: Zawsze używaj INNYCH literek (T_, Rozmiar_)!
    template <typename T_, size_t Rozmiar_>
    friend std::ostream& operator<<(std::ostream& os, const SzablonowaKlasa<T_, Rozmiar_>& obiekt);
};


// =========================================================================
// 4. IMPLEMENTACJA METOD SZABLONOWYCH POZA KLASĄ (Zawsze w pliku .hpp!)
// Przed każdą metodą musi być "template <...>" oraz "NazwaKlasy<T, Rozmiar>::"
// =========================================================================

// Implementacja konstruktora domyślnego
template <typename T, size_t Rozmiar>
SzablonowaKlasa<T, Rozmiar>::SzablonowaKlasa() : pojemnosc(Rozmiar), ilosc_elementow(0) {
    tablica = new T[pojemnosc]; // Dynamiczna alokacja
}

// Implementacja konstruktora z std::initializer_list
template <typename T, size_t Rozmiar>
SzablonowaKlasa<T, Rozmiar>::SzablonowaKlasa(std::initializer_list<T> lista) : pojemnosc(Rozmiar), ilosc_elementow(0) {
    tablica = new T[pojemnosc];
    for (const auto& element : lista) {
        if (ilosc_elementow < pojemnosc) {
            tablica[ilosc_elementow++] = element;
        }
    }
}

// DESTRUKTOR (Zwalnia pamięć)
template <typename T, size_t Rozmiar>
SzablonowaKlasa<T, Rozmiar>::~SzablonowaKlasa() {
    delete[] tablica; // Jeśli alokowałeś tablicę to "delete[]". Jeśli 1 element to "delete".
}

// KONSTRUKTOR KOPIUJĄCY (Alokuje NOWĄ pamięć i kopiuje wartości)
template <typename T, size_t Rozmiar>
SzablonowaKlasa<T, Rozmiar>::SzablonowaKlasa(const SzablonowaKlasa& inna) 
    : pojemnosc(inna.pojemnosc), ilosc_elementow(inna.ilosc_elementow) {
    tablica = new T[pojemnosc]; 
    for (size_t i = 0; i < ilosc_elementow; ++i) {
        tablica[i] = inna.tablica[i]; // Przepisywanie danych
    }
}

// OPERATOR PRZYPISANIA (Usuwa stare dane i kopiuje nowe)
template <typename T, size_t Rozmiar>
SzablonowaKlasa<T, Rozmiar>& SzablonowaKlasa<T, Rozmiar>::operator=(const SzablonowaKlasa& inna) {
    // 1. Zabezpieczenie przed przypisaniem obiektu do samego siebie (a = a;)
    if (this == &inna) return *this;

    // 2. Zwolnienie starej pamięci
    delete[] tablica;

    // 3. Skopiowanie stanu
    pojemnosc = inna.pojemnosc;
    ilosc_elementow = inna.ilosc_elementow;

    // 4. Zaalokowanie nowej pamięci i przepisanie
    tablica = new T[pojemnosc];
    for (size_t i = 0; i < ilosc_elementow; ++i) {
        tablica[i] = inna.tablica[i];
    }

    // 5. Koniecznie zwracamy siebie (*this)
    return *this; 
}

// Operator dostępu [] (Zabezpieczenie przed wyjściem za zakres)
template <typename T, size_t Rozmiar>
T& SzablonowaKlasa<T, Rozmiar>::operator[](size_t index) {
    if (index >= ilosc_elementow) throw std::out_of_range("Indeks poza zakresem!");
    return tablica[index];
}

template <typename T, size_t Rozmiar>
const T& SzablonowaKlasa<T, Rozmiar>::operator[](size_t index) const {
    if (index >= ilosc_elementow) throw std::out_of_range("Indeks poza zakresem!");
    return tablica[index];
}

// Operator dodawania (np. scalanie kolekcji)
template <typename T, size_t Rozmiar>
SzablonowaKlasa<T, Rozmiar> SzablonowaKlasa<T, Rozmiar>::operator+(const SzablonowaKlasa& inna) const {
    SzablonowaKlasa<T, Rozmiar> wynik; 
    // ... jakaś logika tworząca 'wynik' ...
    return wynik; // Zwracamy przez wartość nowo utworzony obiekt!
}

// Przyjacielski operator << (Wypisywanie do strumienia)
template <typename T_, size_t Rozmiar_>
std::ostream& operator<<(std::ostream& os, const SzablonowaKlasa<T_, Rozmiar_>& obiekt) {
    os << "[ ";
    for (size_t i = 0; i < obiekt.ilosc_elementow; ++i) {
        os << obiekt.tablica[i] << " ";
    }
    os << "]";
    return os;
}


// =========================================================================
// 5. DZIEDZICZENIE PO KLASIE SZABLONOWEJ
// =========================================================================
template <typename T, size_t Rozmiar = 10>
class KlasaPochodna : public SzablonowaKlasa<T, Rozmiar> {
    // Musisz przekazać T i Rozmiar do klasy bazowej w ostrych nawiasach!
public:
    // Konstruktor klasy pochodnej wymusza wywołanie konstruktora bazowego!
    KlasaPochodna() : SzablonowaKlasa<T, Rozmiar>() {
        // ...
    }

    void uzyjZmiennejZBazy() {
        // MEGA WAŻNE: Gdy dziedziczysz po szablonie, zmienne z protected
        // musisz poprzedzać 'this->'. Inaczej kompilator wywali 
        // "was not declared in this scope".
        
        // ilosc_elementow = 5;       // ŹLE! 
        this->ilosc_elementow = 5;    // DOBRZE!
        this->tablica[0] = T{};       // DOBRZE!
    }
};


// =========================================================================
// 6. SPECJALIZACJA SZABLONU (Inna implementacja dla np. T = int)
// =========================================================================
// T znika z list '<...>' przy template, bo 'zamrażamy' go na 'int'
template <size_t Rozmiar> 
class SzablonowaKlasa<int, Rozmiar> { // Wstawiamy 'int' bezpośrednio w definicji
private:
    int* tablica; // Tu twardo wpisujemy typ int zamiast T
    size_t pojemnosc;

public:
    SzablonowaKlasa() : pojemnosc(Rozmiar) {
        tablica = new int[pojemnosc];
        std::cout << "To jest w pełni oddzielna implementacja tylko dla 'int'!\n";
    }

    ~SzablonowaKlasa() {
        delete[] tablica;
    }
    // Uwaga: specjalizując klasę, musisz na nowo zadeklarować i napisać 
    // wszystkie potrzebne zmienne oraz metody. To oddzielny twór!
};
