#pragma once
#include <exception>
#include <string>
#include <iostream>

class AwariaSilnika : public std::exception
{
private:
    std::string text_blad;

public:
    AwariaSilnika(std::string txt) : text_blad(txt) {}
    const char* what() const noexcept override
    {
        return text_blad.c_str();
    }
};

class Maszyna // bazowa
{
public:
    virtual void pracuj() = 0;
    virtual ~Maszyna() = default;
};

class Koparka : public Maszyna
{
public:
    void pracuj() override
    {
        std::cout << "\nkoparka w dupie wiertarka\n";
    }
};

class Dzwig : public Maszyna
{
public:
    int udzwig = 5;
    void pracuj() override
    {
        if (udzwig > 10)
        {
            AwariaSilnika awaria("udzwig za duzy");
            throw awaria;
        }
        else
        {
            std::cout << "dzwig podnosi sie w mig";
        }
    }
    void podkrecSilnik()
    {
        udzwig = 15;
    }
};