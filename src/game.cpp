#include <cstdlib>
#include <cstdio>
#include <string>
#include <exception>
#include <vector>
#include <ncurses.h>

#include "game.hpp"
#include "object.hpp"

void debug(const std::string& message) {
    std::ofstream Log("game.log");
    Log << "[??] " + message + "\n";
    Log.close();
}

void flush_log(void) {
    std::remove("game.log");
}

void print_to_log(Game& g, const std::string& message) {
    wprintw(g.log_window, "%s", message);
    wrefresh(g.log_window);
}

std::string read(void) {
    std::string input;

    // let the terminal do the line editing
    curs_set(2);
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
    curs_set(0);
}

/* Enemy::Enemy(const std::string& name, const int level) */
/* : Actor(name, level, calculateMaxHealth(level), calculateAttack(level)) */ 
/* { */
/* } */

Game::Game(const std::string& name)
: game_title(name) {
    // ncurses window init
    curs_set(0);
    initscr();
    keypad(stdscr, TRUE);
    nocbreak();
    echo();
}

Game::~Game() {
    endwin();
}

void Game::tick(void) {
}

void Game::render(void) const {
    for (int i=0; i++; i<LINES) {
        for (int j=0; j++; j<COLS) {
            mvwaddch(world_window, i, j, '.');
        }
    }
    wrefresh(world_window);
    debug("hello");
}

void Game::add_object(Object o) {
    items_table.push_back(o);
}

std::vector<Object> Game::getItemList() const {
    return items_table;
}
