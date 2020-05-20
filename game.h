#ifndef LANGANT_GAME_H
#define LANGANT_GAME_H

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

// Size of playing board
#define SIZE 32

#define MIN_GAME_DELAY 1000
#define MAX_GAME_DELAY 800000
#define GAME_DELAY_STEP 10000

// Amount of rules being played with (e.g. basic implementation = LR = 2 rules)
extern int rule_count;
//#define RULES 4

// Delay in microseconds between each evolution.
extern int game_delay;

/*
 * Definition of the rules. e.g. [-1, 1] (means turn left at first color, right at second color)
 *
 * Rule set:
 * rules  = [         -1,           1,           1]
 * colors = [BLACK_INDEX, WHITE_INDEX, GREEN_INDEX]
 *
 * means turn left at black and change to white; turn right at white and change to green; turn right at green and change to black
 */
extern int rules[];

/*
 * Colors of the rules. e.g. [BLACK, WHITE] (means black turns into white and white turns into black)
 *
 * Rule set:
 * rules  = [         -1,           1,           1]
 * colors = [BLACK_INDEX, WHITE_INDEX, GREEN_INDEX]
 *
 * means turn left at black and change to white; turn right at white and change to green; turn right at green and change to black
 */
extern int colors[];

/* the current state of the board.
 * map[ROW][COL]
 * 1 = black, 2 = first color, 3 = second color, ...
 */
extern int map[SIZE][SIZE];

void start();

void main_loop();

// Thread that runs the evolve step. dependent on game_speed.
void *game_thread();

void end();

void get_input();

void step();

// Moves in the direction being faced
void move_forward();

/*
 * Turns in direction:
 *  1 = right (clockwise)
 * -1 = left  (anti-clockwise)
 */
void turn(int dir);

int next_color(int color);

struct Ant {
    int y;
    int x;
    /*
     * 0 = RIGHT = >
     * 1 = DOWN  = V
     * 2 = LEFT  = <
     * 3 = UP    = ^
     */
    int dir;
};

struct Ant ant;

#endif //LANGANT_GAME_H

