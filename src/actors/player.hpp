#pragma once

#include <vector>

#include "items/item.hpp"

class Player : public Actor {
private:
    int _xp;
    int _strength;
    std::vector<Item> inventory;
public:
    Player(const std::string& name, const int level, const int xp);
    int calculateMaxHealth(const int level) const override;
    int calculateAttack(const int level) const override;
    int getDamage(const int level) const override;
    int xp_to_advance(const int level) const;
    int getXP(void) const;
    void setXP(int xp);
    int getLevel(void) const;
    void incLevel(void);
};

