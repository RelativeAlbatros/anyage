#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <exception>
#include <vector>
#include <ncurses.h>

#include "game.hpp"

void debug(const std::string& message) {
    std::ofstream Log("game.log");
    Log << "[??] " + message + "\n";
    Log.close();
}

void print_to_log(Game& g, const std::string& message) {
    for(int i=0; i<message.length(); i++) {
        waddch(g.log_window, message[i]);
    }
}

std::string read(void) {
    std::string input;

    // let the terminal do the line editing
    nocbreak();
    echo();

    // this reads from buffer after <ENTER>, not "raw" 
    // so any backspacing etc. has already been taken care of
    int ch = getch();
    while ( ch != '\n' )
    {
        input.push_back( ch );
        ch = getch();
    }

    // restore your cbreak / echo settings here
    return input;
}

Object::Object(const std::string& name, const std::string& desc)
: _name(name), _description(desc)
{
}

Object::Object(const std::string& name)
: _name(name), _description("")
{
}

void Object::setDescription(const std::string& desc) {
    _description = desc;
}

void Object::setName(const std::string& name) {
    _name = name;
}

Item::Item(const std::string& name) 
: Object(name) 
{
}

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

std::string Actor::attack(Actor& target) {
    target.setHP(target.getHP() - getDamage(getLevel()));
    if (target.getHP() <= 0) {
        return "dead";
    }
    return "";
}

/* Enemy::Enemy(const std::string& name, const int level) */
/* : Actor(name, level, calculateMaxHealth(level), calculateAttack(level)) */ 
/* { */
/* } */

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

std::string Goblin::attack(Actor& target) {
    target.setHP(target.getHP() - getDamage(getLevel()));
    if (target.getHP() <= 0) {
        return getName() + " killed " + target.getName();
    }
    return "";
}

Player::Player(const std::string& name, const int level, const int xp)
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

std::string Player::attack(Actor& target) {
    target.setHP(target.getHP() - getDamage(getLevel()));
    if (target.getHP() <= 0) {
        return getName() + " killed " + target.getName();
    }
    return "";
}

Game::Game(const std::string& name)
: game_title(name) {
    // ncurses window init
    initscr();
    keypad(stdscr, TRUE);
    nocbreak();
    echo();
    world_window = newwin((int) 4 * LINES/5, COLS, 0, 0);
    log_window = newwin((int) LINES/5, COLS, LINES - (int) (LINES/5), 0);
}

Game::~Game() {
    endwin();
}

void tick(void) {
}

void Game::add_object(Object o) {
    items_table.push_back(o);
}

std::vector<Object> Game::getItemList() const {
    return items_table;
}
