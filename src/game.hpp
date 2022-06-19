#ifndef GAME_H
#define GAME_H

#include <vector>
#include <fstream>
#include <string>
#include <cstdio>
#include <ncurses.h>

/* macros */
#define ANYAGE_VERSION "v0.11"

class Game {
public:
    explicit Game(const std::string& name);
    ~Game();
    void tick(void);
    void render(void) const;
    void add_object(Object o);
    std::vector<Object> getItemList() const;

    WINDOW *world_window;
    WINDOW *log_window;
private:
    std::vector<std::vector<struct Cell> > cells;
    std::string game_title;
    std::vector<Object> items_table;

    int _max_x, _max_y;
};

struct Cell {
    int x, y;
};

/* functions */
void debug(const std::string& message);
void flush_log();
void print_to_log(Game& g, const std::string& message);
std::string read(void);

#endif
