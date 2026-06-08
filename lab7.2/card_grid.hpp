#pragma once
#include <iostream>
#include <initializer_list>
#include <iomanip>

template <typename T, size_t Players = 4, size_t Cards = 4>
class CardGrid
{
protected:
    T deal[Players][Cards];

public:
    CardGrid(std::initializer_list<std::initializer_list<T>> list);
    CardGrid() = default;

    template <typename T_, size_t Players_, size_t Cards_>
    friend std::ostream &operator<<(std::ostream &os, const CardGrid<T_, Players_, Cards_> &c);

    T *operator[](size_t idx);
    const T *operator[](size_t idx) const;

    CardGrid<T, Players, Cards> &operator+(const CardGrid<T, Players, Cards> &m2);
};

template <typename T, size_t Players, size_t Cards>
CardGrid<T, Players, Cards>::CardGrid(std::initializer_list<std::initializer_list<T>> list)
{
    // bezpieczne wypelnienie
    for (auto &i : deal)
    {
        for (auto &j : i)
        {
            j = T{};
        }
    }
    size_t i = 0;
    for (const auto &player_hand : list)
    {
        if (i >= Players)
            break;
        size_t j = 0;
        for (const auto &card : player_hand)
        {
            if (j >= Cards)
                break;
            deal[i][j] = card;
            ++j;
        }
        ++i;
    }
}

template <typename T, size_t Players, size_t Cards>
std::ostream &operator<<(std::ostream &os, const CardGrid<T, Players, Cards> &c)
{
    int i = 1;
    for (const auto &person : c.deal)
    {
        os << "Person " << i << ": ";
        for (const auto &card : person)
        {
            os << std::left << std::setw(4) << card;
        }
        os << "\n";
        ++i;
    }
    return os;
}

template <typename T, size_t Players, size_t Cards>
CardGrid<T, Players, Cards> &CardGrid<T, Players, Cards>::operator+(const CardGrid<T, Players, Cards> &m2)
{
    size_t i = 0;
    for (auto &player : deal)
    {
        size_t j = 0;
        for (auto &card : player)
        {
            card = (card + m2[i][j])%10;
            j++;
        }
        i++;
    }
    return *this;
}

template <typename T, size_t Players, size_t Cards>
T* CardGrid<T, Players, Cards>::operator[](size_t idx){
    return deal [idx];
}
template <typename T, size_t Players, size_t Cards>
const T* CardGrid<T, Players, Cards>::operator[](size_t idx) const {
    return deal [idx];
}
