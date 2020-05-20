#ifndef LANGANT_VIEW_H
#define LANGANT_VIEW_H

/*
 * If adding new colors, note:
 *  1. 0 is not assignable
 *  2. add the following line to view.c:
 *      init_pair(####, COLOR_BLACK, COLOR_****);
 *      where #### is the name of the macro and **** is the color of the background
 *  3. There is a maximum number of colors that can be used (ncurses.COLORS)
 *
 *  If you wish to create a color with RGB, note the
 *  int init_color(short index, short red, short green, short blue) method in ncurses. (value between 0 and 1000)
 *
 *  e.g.
 *  #define GRAY_INDEX 10
 *  init_color(GRAY_INDEX, 500, 500, 500);
 *  init_pair(GRAY_INDEX, COLOR_BLACK, GRAY_INDEX);
 */

#define BLACK_INDEX 1
#define WHITE_INDEX 2
#define RED_INDEX 3
#define GREEN_INDEX 4
#define CYAN_INDEX 5
#define MAGENTA_INDEX 6
#define YELLOW_INDEX 7
#define BLUE_INDEX 8
#define ORANGE_INDEX 9

void init_view();

void draw_game();

void draw_border();

#endif //LANGANT_VIEW_H
