#pragma once

#include <ncurses.h>

struct Screen {
    int _max_x = getmaxx(stdscr),
    int _max_y = getmaxy(stdscr),

    WINDOW *world_window = newwin((int) 4*LINES/5, COLUMNS, 0, 0);
    wborder(world_window, '|', '|', '_','_','+','+','+','+');

    log_window = newwin((int) LINES/5, COLUMNS, (int) 4*(LINES/5), 0);
    wborder(log_window, '|', '|', '_','_','+','+','+','+');
};

extern Screen &main_screen;
