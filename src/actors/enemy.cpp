#include "enemy.hpp"
#include "actor.hpp"

#include <string>

Enemy::Enemy(const std::string& name, const int level) 
: Actor(name, level, calculateMaxHealth(level), calculateAttack(level))
{
}

int Enemy::calculateMaxHealth(const int level) const {
    return 13 * level + 57;
}

int Enemy::calculateAttack(const int level) const {
    return 15 * level;
}

int Enemy::getDamage(const int level) const {
    return calculateAttack(level) * 3;
}

