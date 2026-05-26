#pragma once

#include "Character.hpp"
#include <string>

class Rogue : public Character, public CanUseMelee {
private:
  int basicAttackDamage;
  int backstabDamage;

public:
  Rogue(const std::string &name, int health = 90, int basicDmg = 12,
        int backstabDmg = 30);

  void attack(Character *target) override;
  void backstab(Character *target);
};
