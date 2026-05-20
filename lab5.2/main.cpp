#include <iostream>
#include "punkt.hpp"
#include "szablon.hpp"

void test(Punkt2D p)
{
    std::cout << "Test: " << p << std::endl;
}

int main()
{
    Pudelko<int> male(600);
    Pudelko<Pudelko<int>> big_box(male);
    Pudelko<std::string> napis("gowenko");
    std::cout << big_box;
    return 0;
}