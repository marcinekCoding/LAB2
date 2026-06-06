#pragma once
#include <iostream>

template <typename T, size_t Rows = 4, size_t Cols = 4>
class Matrix
{
protected:
    T elements[Rows][Cols];

public:
    Matrix(std::initializer_list<std::initializer_list<T>> list);
    template <typename T_, size_t Rows_, size_t Cols_>
    friend std::ostream &operator<<(std::ostream &os, const Matrix<T_, Rows_, Cols_> &m);

    const T *operator[](int wiersz) const;
    Matrix<T, Rows, Cols> operator+(const Matrix<T, Rows, Cols> &macierz1);
    Matrix<T, Rows, Cols> operator-(const Matrix<T, Rows, Cols> &macierz);
    Matrix<T, Cols, Rows> transpose();
    T *operator[](int row);
    Matrix() = default;
};

template <typename T, size_t Rows, size_t Cols>
const T *Matrix<T, Rows, Cols>::operator[](int wiersz) const 
{
    return elements[wiersz];
}

template <typename T, size_t Rows, size_t Cols>
Matrix<T, Rows, Cols> Matrix<T, Rows, Cols>::operator+(const Matrix<T, Rows, Cols> &macierz2)
{
    auto nowa = *this;

    for (auto i = 0; i < Rows; ++i)
    {
        for (auto j = 0; j < Cols; ++j)
        {
            nowa.elements[i][j] += macierz2.elements[i][j];
        }
    }

    return nowa;
}

template <typename T, size_t Rows, size_t Cols>
Matrix<T, Rows, Cols> Matrix<T, Rows, Cols>::operator-(const Matrix<T, Rows, Cols> &macierz2)
{
    auto nowa = *this;

    for (auto i = 0; i < Rows; ++i)
    {
        for (auto j = 0; j < Cols; ++j)
        {
            nowa.elements[i][j] -= macierz2.elements[i][j];
        }
    }

    return nowa;
}

template <typename T, size_t Rows, size_t Cols>
Matrix<T, Cols, Rows> Matrix<T, Rows, Cols>::transpose()
{
    Matrix<T, Cols, Rows> nowa;

    for (auto i = 0; i < Rows; ++i)
    {
        for (auto j = 0; j < Cols; ++j)
        {
            nowa[j][i] = this->elements[i][j];
        }
    }

    return nowa;
}
template <typename T, size_t Rows, size_t Cols>
T *Matrix<T, Rows, Cols>::operator[](int row)
{
    return elements[row];
}

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
            for (int j = i; j < Cols; j++)
            {
                elements[wiersz][j] = T();
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
