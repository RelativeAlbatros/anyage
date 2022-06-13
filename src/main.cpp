#include <unistd.h>
#include <iostream>
#include <string>
#include <ncurses.h>
#include "Game.hpp"

int main(int argc, char *argv[], char **envp) {
  std::string player_name;

  Game game;

  print("choose a character name: ");
  player_name = read();
  Player player(player_name);

  sleep(3);
  return 0;
}
