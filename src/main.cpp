#include <unistd.h>
#include <iostream>
#include <string>
#include <ncurses.h>

#include "util/util.hpp"
#include "game.hpp"
#include "actors/all.hpp"

KeyEvents key_events;

int main(int argc, char *argv[], char **envp) {
  Game game("goblin quest");

  std::string player_name = read();
  debug(player_name);
  Player p(player_name, 1, 0);
  Enemy g("goblin", 1);
  
  game.render();

  return 0;
}
