#pragma once
#include <iostream>

class Punkt2D
{
    double _x, _y;

public:
    //Punkt2D(double x = 0, double y = 0) : _x(x), _y(y) {}
    explicit Punkt2D(double z) : _x(z), _y(z) {}
    Punkt2D &operator+=(const Punkt2D &inny)
    {
        this->_x += inny._x;
        this->_y += inny._y;
        return *this;
    }

    Punkt2D operator+(const Punkt2D &inny) 
    {
        Punkt2D wynik = *this;
        wynik += inny; // wykorzystujemy już napisany operator +=
        return wynik;
    }

    double x() const { return _x; }
    double y() const { return _y; }

    // Nie zapomnij zwrócić strumienia os na końcu!
};
std::ostream &operator<<(std::ostream &os, const Punkt2D &p)
{
    os << "(" << p.x() << ", " << p.y() << ")";
    return os;
}