#include <unistd.h>
#include <iostream>
#include <string>
#include <ncurses.h>

#include "util/log.hpp"
#include "game.hpp"
#include "actors/player.hpp"

KeyEvents key_events;

int main(int argc, char *argv[], char **envp) {
  Game game("goblin quest");

  print_to_log(game, "choose a character name: ");
  std::string player_name = read();
  debug(player_name);
  Player p(game, player_name, 1, 0);
  Goblin g(game, "g", 1);
  
  game.render();

  return 0;
}
