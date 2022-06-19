#pragma once

#include <string>
#include "actors/actors.hpp"

class Goblin : public Actor {
public:
    Goblin(const std::string& name, const int level);
    int calculateMaxHealth(const int level) const override;
    int calculateAttack(const int level) const override;
    int getDamage(const int level) const override;
};

