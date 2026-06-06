#pragma once
#include <iostream>
#include "matrix.hpp"
#include <initializer_list>

template <typename T, size_t N = 4>
class SquareMatrix : public Matrix<T,N,N>
{
private:
    T det;

public:
    T computeDeterminant();
    SquareMatrix(std::initializer_list<std::initializer_list<T>> list) : Matrix<T,N,N>(list)
    {
        det = computeDeterminant();
    }
    T getDet(){return det;}
    static SquareMatrix<T,N> identity(){
        SquareMatrix<T,N> nowa;
        for(auto& it : nowa.elements) {
            for(auto& el : it) {
                el = 0;      
            }
        }
        for(int i = 0 ; i<N;i++) {
            nowa.elements[i][i] = 1;
        }
        return nowa;
    }
};

template <typename T, size_t N>
T SquareMatrix<T,N>::computeDeterminant(){
    T A[N][N];
    std::copy(&this->elements[0][0], &this->elements[0][0] + N * N, &A[0][0]);
    int swaps = 0;

    for (std::size_t i = 0; i < N; ++i) {
        std::size_t maxRow = i;
        for (std::size_t k = i + 1; k < N; ++k) {
            if (std::abs(A[k][i]) > std::abs(A[maxRow][i]))
                maxRow = k;
        }

        if (std::abs(A[maxRow][i]) < 1e-12)
            return T{};

        if (i != maxRow) {
            std::swap_ranges(A[i], A[i] + N, A[maxRow]);
            swaps++;
        }

        for (std::size_t k = i + 1; k < N; ++k) {
            T factor = A[k][i] / A[i][i];
            for (std::size_t j = i; j < N; ++j)
                A[k][j] -= factor * A[i][j];
        }
    }

    T determinant = (swaps % 2 == 0) ? 1 : -1;
    for (std::size_t i = 0; i < N; ++i)
        determinant *= A[i][i];

    return determinant;
}
