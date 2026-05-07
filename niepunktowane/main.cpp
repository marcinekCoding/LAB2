#include <iostream>
#include "vector3.hpp"
#include "holey_string.hpp"

void dump_memory(const void *dowolny, size_t wielkosc)
{
    const unsigned char *rzut = reinterpret_cast<const unsigned char *>(dowolny);
    for (int i = 0; i < wielkosc; i += 8)
    {
        std::cout << static_cast<const void*>(rzut+i)<< " :";
        int limit = wielkosc - i;
        for (int j = 0; j < 8; j++)
        {
            if (j < limit)
            {
                std::cout << std::hex << (int)rzut[i + j] << " ";
            }
            else
            {
                std::cout << " ";
            }
        }

        for (size_t j = 0; j < 8; ++j)
        {
            if (i + j < wielkosc)
            {
                char c = rzut[i + j];
                // Czy to znak sterujący czy litera?
                if (c >= 32 && c <= 126)
                    std::cout << c;
                else
                    std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
}

void funkcja(void *dow, int bajty)
{
}

int main()
{
    std::cout << "STAGE 1" << std::endl;

    // STAGE 1: instatiate a Vector3 here

    std::cout << "STAGE 2 and 3" << std::endl;

    const int array_size = 10;
    l2::Vector3 tablica1[array_size];
    l2::Vector3 *tablica2 = new l2::Vector3[array_size];
    std::vector<l2::Vector3> tablica3;

    for (int i = 0; i < array_size; i++)
    {
        double val = static_cast<double>(i);
        l2::Vector3 temp = {{val, val, val}};
        tablica1[i] = temp;
        tablica2[i] = temp;
        tablica3.push_back(temp);
        // std::cout<<"tablica 1: "<<(&tablica1)<<"\n";
        // std::cout<<"tablica 2: "<<(&tablica2)<<"\n";
        // std::cout << "tablica 3: " << tablica3.data() << "\n";
    }
    dump_memory(&"ala ma kota", 11);
    delete[] tablica2;

    // STAGE 2: stack, heap and std::vector

    std::cout << "STAGE 4" << std::endl;

    l2::HoleyString stringi;
    l2::holey_string_assign(stringi,"hello");
    l2::holey_string_hide(stringi,"world");
    l2::holey_string_print(stringi);
    dump_memory(&stringi,16);
    std::cout << "STAGE 5" << std::endl;

    // STAGE 5: test your memcpy and memmove implementations here

    return 0;
}