#include <iostream>
#include <vector>
#include <limits>

enum class Status
{
    Sukces,
    Blad
};

struct Operacja
{
    Status status;
    int kod;
};

int main()
{

    char znak = 'a';
    int x = 4;
    std::cout << "rozmiar znaku: " << sizeof(znak) << std::endl;
    std::cout << "rozmiar x: " << sizeof(x) << std::endl;

    std::cout << "wyrowniane znaku: " << alignof(znak) << std::endl;
    std::cout << "wyrownanie x: " << alignof(x) << std::endl;

    std::cout << "ich adresy to : " << &x << " oraz " << (void *)&znak << "\n";

    // ETAP 2
    unsigned short n = std::numeric_limits<unsigned short>::max();
    n++;
    std::cout << "zmienna n: " << n << "\n";

    short s = std::numeric_limits<short>::max();
    s++;
    std::cout << "zmienna s: " << s << "\n";

    // ETAP 3
    int liczba = 10;
    int *ptr = &liczba; // wskaznik
    *ptr = 100;
    std::cout << "liczba to: " << liczba << std::endl;
    int &wsk = liczba;
    wsk = 30;
    std::cout << "liczba to: " << liczba << std::endl;
    int *pustywskaznik = nullptr;

    // ETAP 4

    Operacja operacja;
    operacja.kod = 1023;
    operacja.status = Status::Sukces;

    // ETAP 5
    const int stala = 42;
    //int *ptrs=&stala; blad!
    float pi = 3.14f;
    int nowy_pi=static_cast<int>(pi);
    std::cout<<nowy_pi<<"\n";

    //Etap 6
    int tajnaLiczba=257;
    unsigned char* bajty = reinterpret_cast<unsigned char*>(&tajnaLiczba);
    std::cout<<static_cast<int>(bajty[0]);

    //Etap 7
    int *tablica = new int[5];
    int *ptrt = tablica;
    tablica[0]=7;
    delete[] tablica;
}