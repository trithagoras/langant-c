#include "game.h"
#include <stdio.h>

/*
 * How to use program:
 * To change the number of rules, change the following variables:
 *  - rules     -> game.c @ line  9
 *  - colors    -> game.c @ line 10
 * BEWARE: always ensure rules and colors have the same size. e.g. the same number of elements. Otherwise,
 *         undefined behaviour occurs.
 *
 * To change the size of the simulation:
 *  - SIZE      -> game.h @ line 8
 * BEWARE: the size of each cell is dependent on your terminal's font size, meaning
 *         large game sizes will only be able to be seen by reducing terminal's font size, and even some
 *         game sizes won't be able to be seen due to terminal font size minimum limit).
 *
 * BEWARE: screen refreshes are minimized for optimization purposes (reducing draw calls), meaning
 * resizing the terminal leads to undefined behaviour.
 *
 * CONTROLS:
 *  - [q]      quit
 *  - [SCROLL] change game speed
 */

int main() {
    start();
    return 0;
}
