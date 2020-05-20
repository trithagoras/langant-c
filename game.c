#include "game.h"
#include <ncurses.h>
#include <stdlib.h>
#include "view.h"
#include <pthread.h>
#include <unistd.h>

int map[SIZE][SIZE];

// Grows chaotically. It is not known whether this ant ever produces a highway.
//int rules[] = {1, -1, 1};
//int colors[] = {BLACK_INDEX, MAGENTA_INDEX, YELLOW_INDEX};

// Grows symmetrically.
//int rules[] = {1, -1, -1, 1};
//int colors[] = {BLACK_INDEX, RED_INDEX, YELLOW_INDEX, GREEN_INDEX};

// Fills space in a square around itself.
//int rules[] = {-1, 1, 1, 1, 1, 1, -1, -1, 1};
//int colors[] = {BLACK_INDEX, MAGENTA_INDEX, YELLOW_INDEX, GREEN_INDEX, RED_INDEX, ORANGE_INDEX, CYAN_INDEX, BLUE_INDEX, WHITE_INDEX};

// Langton's Ant initial implementation
int rules[] = {-1, 1};
int colors[] = {BLACK_INDEX, WHITE_INDEX};

int rule_count = sizeof(rules) / sizeof(int);

struct Ant ant;

int game_delay = 100000;

void start() {
    init_view();

    // init map
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            map[row][col] = colors[0];
        }
    }

    // ant init config
    ant = (struct Ant){.y = SIZE / 2, .x = SIZE / 2, .dir = 0};

    // open new thread so that game_delay doesn't affect draw() or get_input()
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, game_thread, NULL);

    main_loop();
}

void end() {
    endwin();
    exit(0);
}

void main_loop() {
    draw_border();
    while (1) {
        get_input();
        usleep(500);
    }
}

void *game_thread() {
    while (ant.y >= 0 && ant.y < SIZE && ant.x >= 0 && ant.x < SIZE) {
        step();
        draw_game();
        usleep(game_delay);
    }
    return NULL;
}

void step() {
    // check what color ant is on
    for (int i = 0; i < rule_count; i++) {
        int color = colors[i];

        // if ant is on this color
        if (map[ant.y][ant.x] == color) {
            // get turning rule based on current color
            int rule = rules[i];

            // change color to next
            map[ant.y][ant.x] = next_color(color);
            turn(rule);
            move_forward();
            return;
        }
    }
}

void turn(int dir) {
    if (dir == 1) {
        // turning right
        if (ant.dir == 3) {
            ant.dir = 0;
        }
        else {
            ant.dir++;
        }
    }
    else {
        // turning left
        if (ant.dir == 0) {
            ant.dir = 3;
        }
        else {
            ant.dir--;
        }
    }
}

int next_color(int color) {
    for (int i = 0; i < rule_count; i++) {
        if (colors[i] == color) {
            if (i == rule_count - 1) {
                return colors[0];
            }

            return colors[i + 1];
        }
    }
    return -1;
}

void move_forward() {
    switch (ant.dir) {
        case 0:
            ant.x++;
            break;
        case 1:
            ant.y++;
            break;
        case 2:
            ant.x--;
            break;
        case 3:
            ant.y--;
            break;
        default:
            break;
    }
}

void get_input() {
    switch (getch()) {
        case 'q':
        case 'Q':
            end();
            break;
        case KEY_UP:
            game_delay = MIN(game_delay + GAME_DELAY_STEP, MAX_GAME_DELAY);
            break;
        case KEY_DOWN:
            game_delay = MAX(game_delay - GAME_DELAY_STEP, MIN_GAME_DELAY);
            break;
    }
}