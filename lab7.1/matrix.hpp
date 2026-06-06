#pragma once
#include <iostream>

template <typename T, size_t Rows = 4, size_t Cols = 4>
class Matrix
{
protected:
    T elements[Rows][Cols];

public:
    Matrix(std::initializer_list<std::initializer_list<T>> list);
    friend std::ostream &operator<<(std::ostream &os, const Matrix<T, Rows, Cols> &m);

    const T *operator[](int wiersz) const;
    friend Matrix<T, Rows, Cols> operator+(const Matrix &macierz1, const Matrix &macierz2);
    friend Matrix<T, Rows, Cols> operator-(const Matrix &macierz1, const Matrix &macierz2);
    Matrix<T, Cols, Rows> transpose();
    Matrix() = default;
};

template <typename T, size_t Rows, size_t Cols>
const T *Matrix<T, Rows, Cols>::operator[](int wiersz) const
{
    return elements[wiersz];
}

template <typename T, size_t Rows, size_t Cols>
Matrix<T, Rows, Cols> operator+(const Matrix<T, Rows, Cols> &macierz1, const Matrix<T, Rows, Cols> &macierz2)
{
    auto nowa = macierz1;

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
Matrix<T, Rows, Cols> operator-(const Matrix<T, Rows, Cols> &macierz1, const Matrix<T, Rows, Cols> &macierz2)
{
    auto nowa = macierz1;

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
Matrix<T, Cols, Rows> Matrix<T, Rows, Cols>::transpose(){
    Matrix<T,Cols,Rows> nowa;

    for (auto i = 0; i < Rows; ++i)
    {
        for (auto j = 0; j < Cols; ++j)
        {
            nowa[j][i] = this->elements[i][j];
        }
    }

    return nowa;
}
