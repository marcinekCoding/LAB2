#include <iostream>
#include "vars.hpp"

static int global_static=0;
int global_extern=0;
void print_vars(){
    std::cout<<"global_extern: "<<global_extern<<"\nglobal_static "<<global_static<<"\n";
}

void inc_vars(){
    std::cout<<"\nIncreasing...\n";
    global_extern++;
    global_static++;
}