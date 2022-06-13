#include <unistd.h>
#include <iostream>
#include <string>
#include <ncurses.h>
#include "Game.hpp"

int main(int argc, char *argv[], char **envp) {
  std::string player_name;

  Game game("goblin quest");

  print("choose a character name: ");
  player_name = read();
  Player player(player_name, 1, 0);

  return 0;
}
