#include <iostream>
#include "card_grid.hpp"
#include "card_grid_int.hpp"
#include <initializer_list>
#include <string>

int main() {
    CardGrid<int,3,5> dacz = {{'3','1','2'},{'1','6'},{'1','5','2','8'}};
    CardGrid<int,3,5> poker = {{1,2,3,4},{10,1},{2,2,2,9}};
    dacz = dacz + poker;
    std::cout << dacz;

};