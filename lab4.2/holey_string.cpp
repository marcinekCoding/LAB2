#include "holey_string.hpp"
#include <iostream>

namespace l2
{

void holey_string_assign(HoleyString& hs, const std::string& val)
{
    int wielk = val.size();
    for(int i=0;i<wielk;i++) 
    {
        hs.string[i].c=val[i];
    }
}

void holey_string_hide(HoleyString& hs, const std::string& val)
{
     /**
     * This code works - but only because I guessed the hole is one byte after the char.
     * That is Undefined Behaviour (UB). I used it to make some platform specific hack.
     *
     * Classic: It works on my machine!
     */
    for (size_t i = 0; i < HoleyString::capacity && i < val.size(); ++i)
        *((&hs.string[i].c) + 1) = val[i];
}

void holey_string_print(const HoleyString& hs)
{
    int i=0;
    while(hs.string[i].c!='\0')
    {
        std::cout<<hs.string[i].c;
        i++;
    }
    std::cout<<std::endl;
}

}  // namespace l2