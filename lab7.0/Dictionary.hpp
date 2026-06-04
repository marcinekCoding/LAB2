#pragma once
#include <unordered_map>
#include <vector>
#include "hasher.hpp"
#include <iostream>

template <typename K, typename V>
class KeyValuePair
{
public:
    K key;
    V value;
    KeyValuePair<K, V> *next;

public:
    KeyValuePair(K key, V value) : key(key), value(value), next(nullptr) {}
    ~KeyValuePair() = default;
};

template <typename K, typename V, int Capacity>
class Dictionary
{
private:
    KeyValuePair<K, V> *table[Capacity];

public:
    Dictionary()
    {
        for (auto &it : table)
        {
            it = nullptr;
        }
    }
    ~Dictionary()
    {
        for (auto *it : table)
        {
            auto *dada = it;
            while (dada != nullptr)
            {
                auto *mama = dada;
                dada = dada->next;
                delete mama;
            }
        }
    }

    size_t hash(const K &key)
    {
        Hash<K> h;
        size_t hash = h(key);
        hash %= Capacity;
        return hash;
    }
    void insert(const K &key, const V &value)
    {
        KeyValuePair<K, V> nowy = new KeyValuePair(key, value);
        size_t idx = hash(key);

        if (table[idx] == nullptr)
        {
            table[idx] = nowy;
        }
        else
        {
            while (table[idx]->next != nullptr)
            {
                table[idx] = table[idx]->next;
            }
            table[idx]->next = nowy;
        }
    }

    friend std::ostream& operator<<(std:ostream& os, const Dictionary& dict)
    {
        for (auto *it : dict.table)
        {
            std::cout << "Klucz: " << it->key << "\n";
            auto *temp = it;
            while (temp != nullptr)
            {
                os<< "Wartosc: " << it->value << "\n";
                temp = temp->next;
            }
        }
        return os;
    }

    V& operator[](K& key){

    }
};
