#include <cstdlib>
#include <cstdio>
#include <string>
#include <exception>
#include <vector>
#include <ncurses.h>

#include "Game.hpp"

void debug(std::string message) {
    std::ofstream Log((game_title+".log").c_str());
    Log << "[??] " + message;
    Log.close();
}

void print(std::string message) {
    for(int i=0; i<message.length(); i++) {
        waddch(stdscr, message[i]);
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

int xp_to_advance(int level) {
    return (500*(level^2) - 500 * level);
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

Actor::Actor(const std::string& name)
: Object(name)
{
}

int Actor::getHP() const {
    return _health;
}

void Actor::setHP(int hp) {
    debug("setting health " + std::to_string(hp));
    _health = hp;
}

int Actor::getLevel() const {
    return _level;
}

void Actor::attack(Actor& target) {
    target.setHP(target.getHP() - _strength);
}

Enemy::Enemy(const std::string& name) 
: Actor(name)
{
}

Goblin::Goblin(const std::string& name) 
: Enemy(name)
{
}

Player::Player(const std::string& name) 
: Actor(name)
{
    print("hello");
    print("Player " + name + " has appeared\n");
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
}

Game::Game() {
    // ncurses window init
    initscr();
    keypad(stdscr, TRUE);
    nocbreak();
    echo();
}

Game::~Game() {
    endwin();
}

std::vector <Object> Game::getItemList() const {
    return items_table;
}

void Game::add_object(Object o) {
    items_table.push_back(o);
}

