#include <iostream>
#include "vars.hpp"

int main() {
    print_vars();
    inc_vars();
    print_vars();
        std::cout<<"global_extern: "<<global_extern;

    return 0;
}