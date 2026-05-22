#pragma once
#include <iostream>

template <typename typ>
class Pudelko
{
private:
    typ *zawartosc;

public:
    Pudelko(typ wartosc)
    {
        zawartosc = new typ(wartosc);
    }
    ~Pudelko()
    {
        delete zawartosc;
        zawartosc = nullptr;
    }

    typ& operator*() const
    {
        return *zawartosc;
    }

    friend std::ostream &operator<<(std::ostream &os, const Pudelko<typ>& box)
    {
        os << *box; 
        return os;
    }
    
};

