#pragma once

#include "game.hpp"

class Actor : public Object {
protected:
    int _level, _health, _attack;
public:
    Actor(const std::string& name, const int level, const int max_hp, const int attack);
    std::string getName(void) const;
    virtual int calculateMaxHealth(const int level) const = 0;
    virtual int calculateAttack(const int level) const = 0;
    virtual int getDamage(const int level) const = 0;
    int getHP(void) const;
    void setHP(int hp);
    int getLevel(void) const;
    int attack(Actor& a);
};

