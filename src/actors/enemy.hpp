#pragma once

#include <string>
#include "actor.hpp"

class Enemy : public Actor {
public:
    Enemy(const std::string& name, const int level);
    int calculateMaxHealth(const int level) const override;
    int calculateAttack(const int level) const override;
    int getDamage(const int level) const override;
};

