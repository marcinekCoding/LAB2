#include "matrix.hpp"

template <typename T, size_t Rows, size_t Cols>
Matrix<T, Rows, Cols>::Matrix(std::initializer_list<std::initializer_list<T>> list)
{
    // sprawdzanie
    if (list.size() > Rows)
    {
        std::cout << "sory mordo nie damy rady tego zrobic";
        return;
    }
    int wiersz = 0;
    for (auto &wew : list)
    {
        int i = 0;
        for (auto &it : wew)
        {
            if (i >= Cols)
            {
                break;
            }
            elements[wiersz][i] = it;
            i++;
        }
        // jezeli brakuje wypelnien
        if (i != Cols)
        {
            for (i; i < Cols; i++)
            {
                elements[wiersz][i] = T();
            }
        }
        wiersz++;
    }
}
template <typename T, size_t Rows, size_t Cols>
std::ostream& operator<<(std::ostream &os, const Matrix<T,Rows,Cols>&m)
{
    for(const auto& wiersz : m.elements) {
        for(const auto& komorka : wiersz) {
            os << komorka;
        }
        os << "\n";
    }
    return os;
}
