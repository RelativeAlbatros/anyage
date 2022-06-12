#include <cstdlib>
#include <string>
#include <ctime>
#include <exception>
#include <vector>

#include "Game.hpp"

Object::Object(const std::string& name, const std::string& desc)
: _name(name), _description(desc)
{
}

Object::Object(const std::string& name)
: _name(name), _description("")
{
}

/* Actor::Actor(std::string ) */
/* : Object() */
/* { */
/* } */

Game::Game() {
  /* TCODConsole::initRoot(80, 50, game_title+version, true); */
}

Game::~Game() {
}

std::vector <Object> Game::getItemList() const {
  return items_table;
}

void Game::add_object(Object o) {
    items_table.push_back(o);
}

