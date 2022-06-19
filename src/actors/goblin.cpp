#include "actors/goblin.hpp"
#include "actors/actor.hpp"

#include <string>

Goblin::Goblin(const std::string& name, const int level) 
: Actor(name, level, calculateMaxHealth(level), calculateAttack(level))
{
}

int Goblin::calculateMaxHealth(const int level) const {
    return 13 * level + 57;
}

int Goblin::calculateAttack(const int level) const {
    return 15 * level;
}

int Goblin::getDamage(const int level) const {
    return calculateAttack(level) * 3;
}

