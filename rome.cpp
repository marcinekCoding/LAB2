#include <string>
#include <vector>
#include <iostream>
#include "rome.hpp"

namespace rome
{
    Province create_province(std::string name)
    {
        Province nowa;
        nowa.name = name;
        return nowa;
    }

    void add_city(Province *province, std::string city)
    {
        province->cities.push_back(city);
    }

    std::string description(Province *province)
    {
        std::string opis;
        opis = province->name;
        int s = province->cities.size();
        for (int i = 0; i < s; i++)
        {
            if(i==s-1){
                opis+=opis += " " + province->cities[i]+".";
            }
            opis += " " + province->cities[i]+",";
        }
        return opis;
    }
}