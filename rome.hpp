#pragma once

#include <string>
#include <vector>
#include <iostream>
namespace rome
{
    struct Province
    {
        std::string name;
        std::vector<std::string> cities;
    };

    Province create_province(std::string name);
    void add_city(Province *province, std::string city);
    std::string description(Province *province);

}
