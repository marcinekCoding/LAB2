#pragma once
#include <exception>
#include <iostream>
#include <string>

class NoManaException : public std::exception {
public:
  const char *what() const noexcept override {
    return "Not enough mana to perform this action.";
  }
};
class Character {
private:
  std::string name;
  int health;
  int maxHealth;

public:
  Character(std::string nazwa, int ilosc = 100)
      : name(nazwa), maxHealth(ilosc), health(ilosc) {}

  const std::string &getName() { return name; }
  int getHealth() { return health; }
  bool isAlive() { return health > 0; }
  void takeDamage(int damage) {
    if (this->isAlive()) {
      health -= damage;
    }
  }
  void heal(int add) {
    health += add;
    if (health > maxHealth) {
      health = maxHealth;
    }
  }
  virtual void attack(Character *target) = 0; // virtualna metoda
  virtual ~Character() = default;
};

class CanCastSpells {
public:
  int mana;
  int maxMana;
  CanCastSpells(int mana) : mana(mana), maxMana(mana) {}
  int getMana() { return mana; }
  int getMaxMana() { return maxMana; }
  void addMana(int amount) {
    mana += amount;
    if (mana > maxMana) {
      mana = maxMana;
      std::cout << "dodano " << amount << " zostalo " << mana << "\n";
    }
  }
  void useMana(int amount) {
    if (mana - amount < 0) {
      // rzuci exception
    } else {
      mana -= amount;
      std::cout << "dodano " << amount << " zostalo " << mana << "\n";
    }
  }
  virtual void castSpell(Character *target) = 0;
};

class CanUseMelee {
public:
  virtual void performMeleeAttack(Character *target) = 0;
};

class Warrior : public Character, public CanUseMelee {
private:
  int maleeDamage;

public:
  Warrior(const std::string &name, int health = 120, int damage = 15)
      : Character(name, health), maleeDamage(damage) {}

  void CanUseMelee(Character *target) { std::cout << "wykonuje atak"; }
  void attack(Character *target) override {
    CanUseMelee(target);
    std::cout << "zadano obrazenia graczowi: " << target->getName() << " :"
              << maleeDamage << "\n";
  }
};

class Mage : public Character, public CanCastSpells, public CanUseMelee {
private:
  int spellDamage;

public:
  Mage(const std::string &name, int health = 80, int mana = 150,
       int damage = 20)
      : Character(name, health), CanCastSpells(mana), spellDamage(damage) {}

  void castSpell(Character *target) override {
    target->takeDamage(spellDamage);
    useMana(10);
  }
  void attack(Character *target) override {
    castSpell(target);
    std::cout << "zadano obrazenia graczowi: " << target->getName() << " :"
              << spellDamage << "\n";
  }
};

class BattleMage : public Character, public CanCastSpells, public CanUseMelee {
  int meleeDmg;
  int spellDamage;
  BattleMage(std::string name, int health, int mana, int meleeDmg = 10,
             int spellDamage = 15)
      : Character(name, health), CanCastSpells(mana), meleeDmg(meleeDmg),
        spellDamage(spellDamage) {}

<<<<<<< HEAD
  void attack(Character *target) override {
    srand(static_cast<unsigned int>(time(0)));
    int choice = rand() % 2;

    if (choice == 0) {
      std::cout << "BattleMage " << getName() << " prepares to cast a spell..."
                << std::endl;
      try {
        castSpell(target);
      } catch (const NoManaException &e) {
        std::cout << "BattleMage " << getName()
                  << " tried to cast a spell but is "
                     "out of mana! "
                  << e.what() << std::endl;
        std::cout << "BattleMage " << getName()
                  << " resorts to a melee attack instead!" << std::endl;
        performMeleeAttack(target);
      }
    } else {
      std::cout << "BattleMage " << getName()
                << " prepares for a melee attack..." << std::endl;
      performMeleeAttack(target);
    }
  }
};
=======
  void attack(Character *target) override {}
};
>>>>>>> e4ae0b57653a064dbcb90653183cee24cb4a4ffc
