#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <ctime>

class NoManaException : public std::exception
{
private:
    std::string text_blad;

public:
    NoManaException(std::string txt) : text_blad(txt) {}
    const char *what() const noexcept override
    {
        return text_blad.c_str();
    }
};

class CanCastSpells
{
public:
    int mana;
    int maxMana;

    CanCastSpells(int mana, int max) : mana(mana), maxMana(max) {}
    int getMana() { return mana; }
    void getMaxMana(int amount)
    {
        mana += amount;
        if (mana > maxMana)
        {
            mana = maxMana;
        }
        std::cout << "dodano " << amount << " many | pozostalo: " << mana << "\n";
    }
    void useMana(int amount)
    {
        if (mana - amount < 0)
        {
            NoManaException mana("too low mana");
            throw mana;
        }
        else
        {
            mana -= amount;
        }
        std::cout << "zuzyto " << amount << " many | pozostalo: " << mana << "\n";
    }
    virtual void castSpell(Character *target) = 0;
};

class CanUseMelee
{
public:
    virtual void performMeleeAttack(Character *target) = 0;
};
class Character
{
private:
    std::string name;
    int health;
    int maxHealth;

public:
    Character(std::string nazwa, int ilosc = 100) : name(nazwa), maxHealth(ilosc), health(ilosc) {}

    const std::string &getName() { return name; }
    int getHealth() { return health; }
    bool isAlive() { return health > 0; }
    void takeDamage(int damage)
    {
        if (this->isAlive())
        {
            health -= damage;
        }
    }
    void heal(int add)
    {
        health += add;
        if (health > maxHealth)
        {
            health = maxHealth;
        }
    }
    virtual void attack(Character *target) = 0; // virtualna metoda
    virtual ~Character() = default;
};

class Warrior : public Character, public CanUseMelee
{
private:
    int maleeDamage;

public:
    Warrior(const std::string &name, int health = 120, int damage = 15)
        : Character(name, health), maleeDamage(damage) {}
    void performMeleeAttack(Character *target) override
    {
        target->takeDamage(maleeDamage);
    }
    void attack(Character *target) override
    {
        performMeleeAttack(target);
        std::cout << "zadano obrazenia graczowi: " << target->getName() << " :" << maleeDamage << "\n";
    }
};

class Mage : public Character, public CanCastSpells
{
private:
    int spellDamage;

public:
    Mage(const std::string &name, int health = 80, int mana = 150, int damage = 20)
        : Character(name, health), CanCastSpells(mana, mana), spellDamage(damage) {}
    void castSpell(Character *target) override
    {
        useMana(10);
        target->takeDamage(spellDamage);
    }
    void attack(Character *target) override
    {
        castSpell(target);
        std::cout << "zadano obrazenia graczowi: " << target->getName() << " :" << spellDamage << "\n";
    }
};

class BattleMage : public Character, public CanCastSpells, public CanUseMelee
{
private:
    int meleeDmg;
    int spellDmg;

public:
    BattleMage(const std::string &name, int health, int mana, int meleeDmg, int spellDmg)
        : Character(name, health), CanCastSpells(mana, mana), meleeDmg(meleeDmg), spellDmg(spellDmg) {}

    void attack(Character *target) override
    {
        try
        {
            srand(time(0));
            int los = rand() % 2;
            if (los == 1)
            {
                castSpell(target);
                mana += 2;
            }
            else
            {
                performMeleeAttack(target);
            }
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
};