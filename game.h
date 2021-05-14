#ifndef SDLLIFE_GAME_H
#define SDLLIFE_GAME_H

#include <SDL2/SDL.h>
#include <math.h>

#define WIDTH 1200
#define HEIGHT 800
#define NUM_CELLS 100
#define CELL_WIDTH (WIDTH / NUM_CELLS)
#define CELL_HEIGHT (HEIGHT/ NUM_CELLS)

enum GameState {
    RUNNING, PAUSED, QUIT
};

enum CellState {
    DEAD, LIVING
};

typedef struct {
    enum GameState state;
    int board[NUM_CELLS * NUM_CELLS];
} Game;

void init_game(Game *game);

void fill_game_board(Game *game);

void step(Game *game);

int count_neighbors(int board[NUM_CELLS * NUM_CELLS], int x, int y);

void copy_array(int board[NUM_CELLS * NUM_CELLS], int values[NUM_CELLS * NUM_CELLS]);

#endif //SDLLIFE_GAME_H
