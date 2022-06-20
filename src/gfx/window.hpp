#pragma once

#include <ncurses.h>

class Screen {
private:
    int _max_x = getmaxx(stdscr);
    int _max_y = getmaxy(stdscr);
    int _height_world = (4*LINES)/5;
    int _width_world = COLS;

    int _start_x_log = 0;
    int _start_y_log = (4*LINES)/5;
    int _height_log = LINES/5;
    int _width_log = COLS;
public:
    WINDOW *world_window = newwin(_height_world, _width_world, 0, 0);
    box(world_window, 0, 0);

    log_window = newwin((int) LINES/5, COLUMNS, (int) 4*(LINES/5), 0);
    wborder(log_window, '|', '|', '_','_','+','+','+','+');
    wrefresh();
};

extern Screen &main_screen;
