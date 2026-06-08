#pragma once
#include "card_grid.hpp"

enum class Karty
{
    As = 0,
    Walet = 11,
    Queen = 12,
    King = 13,
};

template <size_t Players, size_t Cards>
class CardGrid<int, Players, Cards>
{
protected:
    int deal[Players][Cards];

public:
    CardGrid(std::initializer_list<std::initializer_list<int>> list);
    CardGrid() = default;

    template <size_t Players_, size_t Cards_>
    friend std::ostream &operator<<(std::ostream &os, const CardGrid<int, Players_, Cards_> &c);

    int *operator[](size_t idx);
    const int *operator[](size_t idx) const;

    CardGrid<int, Players, Cards> &operator+(const CardGrid<int, Players, Cards> &m2);

    
};

template <size_t Players, size_t Cards>
std::ostream &operator<<(std::ostream &os, const CardGrid<int, Players, Cards> &c){
    int i = 1;
    for (const auto &person : c.deal)
    {
        os << "Person " << i << ": ";
        for (const auto &card : person)
        {
            if (card == 0)
                os << std::left << std::setw(4) << "A";
            else if (card == 11)
                os << std::left << std::setw(4) << "W";
            else if (card == 12)
                os << std::left << std::setw(4) << "Q";
            else if (card == 13)
                os << std::left << std::setw(4) << "K";
            else
                os << std::left << std::setw(4) << card;
        }
        os << "\n";
        ++i;
    }
    return os;
}

template <size_t Players, size_t Cards>
CardGrid<int, Players, Cards>::CardGrid(std::initializer_list<std::initializer_list<int>> list)
{
    for (auto &i : deal)
        for (auto &j : i)
            j = 0;

    size_t i = 0;
    for (const auto &player_hand : list)
    {
        if (i >= Players) break;
        size_t j = 0;
        for (const auto &card : player_hand)
        {
            if (j >= Cards) break;
            deal[i][j] = card;
            ++j;
        }
        ++i;
    }
}

template <size_t Players, size_t Cards>
int* CardGrid<int, Players, Cards>::operator[](size_t idx){
    return deal[idx];
}

template <size_t Players, size_t Cards>
const int* CardGrid<int, Players, Cards>::operator[](size_t idx) const {
    return deal[idx];
}

template <size_t Players, size_t Cards>
CardGrid<int, Players, Cards> &CardGrid<int, Players, Cards>::operator+(const CardGrid<int, Players, Cards> &m2)
{
    size_t i = 0;
    for (auto &player : deal)
    {
        size_t j = 0;
        for (auto &card : player)
        {
            card = (card + m2[i][j]) % 14; // Zmiana %10 na %14 (skoro krol to 13) albo wg Twojego uznania
            j++;
        }
        i++;
    }
    return *this;
}
