#include "actor.hpp"

Actor::Actor(const std::string& name, const int level, const int max_hp, const int attack)
: Object(name), _level(level), _health(max_hp), _attack(attack)
{
}

std::string Actor::getName(void) const {
    return _name;
}

int Actor::getDamage(const int level) const {
    return _attack;
}

int Actor::getHP(void) const {
    return _health;
}

void Actor::setHP(int hp) {
    debug("setting health " + std::to_string(hp));
    _health = hp;
}

int Actor::getLevel(void) const {
    return _level;
}

int Actor::attack(Actor& target) {
    target.setHP(target.getHP() - getDamage(getLevel()));
    if (target.getHP() <= 0) {
        return 1;
    }
    return 0;
}

