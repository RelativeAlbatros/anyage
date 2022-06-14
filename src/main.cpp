#include <unistd.h>
#include <iostream>
#include <string>
#include <ncurses.h>

#include "game.hpp"

int main(int argc, char *argv[], char **envp) {
  Game game("goblin quest");

  print_to_log(game, "choose a character name: ");
  std::string player_name = read();
  debug(player_name);
  Player p(player_name, 1, 0);
  game.add_object(p);
  Goblin g("g", 1);
  game.add_object(g);
  
  for (;;) {
    if (p.attack(g) == "dead") {
        delete &g;
        debug("killed");
        return 0;
    }
  }

  return 0;
}
