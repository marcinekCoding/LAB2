#pragma once
#include <string>
#include <iostream>

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

class Warrior : public Character
{
private:
    int maleeDamage;

public:
    Warrior(const std::string &name, int health = 120, int damage = 15)
        : Character(name, health), maleeDamage(damage) {}

    void attack(Character *target) override
    {
        std::cout << "zadano obrazenia graczowi: " << target->getName() << " :" << maleeDamage << "\n";
    }
};

class Mage : public Character
{
private:
    int spellDamage;

public:
    Mage(const std::string &name, int health = 80, int mana = 150, int damage = 20)
        : Character(name, health), spellDamage(damage) {}

    void attack(Character *target) override
    {
        target->takeDamage(spellDamage);
        std::cout << "zadano obrazenia graczowi: " << target->getName() << " :" << spellDamage << "\n";
    }
};