#include "view.h"
#include <ncurses.h>
#include "game.h"

void init_view() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);

    // color
    start_color();

    init_pair(BLACK_INDEX, COLOR_WHITE, COLOR_BLACK);
    init_pair(WHITE_INDEX, COLOR_BLACK, COLOR_WHITE);
    init_pair(RED_INDEX, COLOR_BLACK, COLOR_RED);
    init_pair(GREEN_INDEX, COLOR_BLACK, COLOR_GREEN);
    init_pair(CYAN_INDEX, COLOR_BLACK, COLOR_CYAN);
    init_pair(MAGENTA_INDEX, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(YELLOW_INDEX, COLOR_BLACK, COLOR_YELLOW);
    init_pair(BLUE_INDEX, COLOR_BLACK, COLOR_BLUE);

    init_color(ORANGE_INDEX, 1000, 517, 0);
    init_pair(ORANGE_INDEX, COLOR_BLACK, ORANGE_INDEX);

}

void draw_border() {
    for (int i = 0; i < SIZE; i++) {
        // horizontal lines
        mvaddch(0, (i + 1) * 2, '-');
        mvaddch(SIZE + 1, (i + 1) * 2, '-');

        // vertical lines
        mvaddch(i + 1, 0, '|');
        mvaddch(i + 1, (SIZE + 1) * 2, '|');
    }

    // corners
    mvaddch(0, 0, '+');                         // TL
    mvaddch(0, (SIZE + 1) * 2, '+');            // TR
    mvaddch(SIZE + 1, 0, '+');                  // BL
    mvaddch(SIZE + 1, (SIZE + 1) * 2, '+');     // BR
}

void draw_game()
{
    // drawing cell that ant is on
    attron(COLOR_PAIR(map[ant.y][ant.x]));
    mvaddch(ant.y + 1, 2 + (ant.x * 2), ' ');
    attroff(COLOR_PAIR(map[ant.y][ant.x]));
}