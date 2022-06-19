#include <string>
#include <cmath>

#include "player.hpp"

Player::Player(Game g, const std::string& name, const int level, const int xp)
: Actor(name, level, calculateMaxHealth(level), calculateAttack(level)),
_xp(xp)
{
}

int Player::calculateMaxHealth(const int level) const {
    return 7 * (level^2) + 10 * level;
}

int Player::calculateAttack(const int level) const {
    return 11 * sqrt(level) - 5;
}

int Player::getDamage(const int level) const {
    return calculateAttack(level) * 4;
}

int Player::xp_to_advance(const int level) const {
    return (500*(level^2) - 500 * level);
}

int Player::getXP(void) const {
    return _xp;
}

void Player::setXP(int xp) {
    _xp = xp;
    if (xp >= xp_to_advance(getLevel()))
        incLevel();
}

int Player::getLevel(void) const {
    return _level;
}

void Player::incLevel(void) {
    _level += 1;
    _health = calculateMaxHealth(getLevel());
}
