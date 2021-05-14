#include "game.h"

void init_game(Game *game) {
    game->state = PAUSED;
    fill_game_board(game);
}

void fill_game_board(Game *game) {
    for (int x = 0; x < NUM_CELLS * NUM_CELLS; x++) {
        int random = rand() % 3;
        if (random > 0) {
            game->board[x] = DEAD;
        } else {
            game->board[x] = LIVING;
        }
    }
}

void step(Game *game) {
    int next_generation[NUM_CELLS * NUM_CELLS];
    for (int i = 0; i < NUM_CELLS; i++) {
        for (int j = 0; j < NUM_CELLS; j++) {
            int living_neighbors = count_neighbors(game->board, i, j);
            if (game->board[i * NUM_CELLS + j] == LIVING) {
                if (living_neighbors == 3 || living_neighbors == 2) {
                    next_generation[i * NUM_CELLS + j] = LIVING;
                } else {
                    next_generation[i * NUM_CELLS + j] = DEAD;
                }
            } else if (game->board[i * NUM_CELLS + j] == DEAD) {
                if (living_neighbors == 3) {
                    next_generation[i * NUM_CELLS + j] = LIVING;
                } else {
                    next_generation[i * NUM_CELLS + j] = DEAD;
                }
            }
        }
    }
    copy_array(game->board, next_generation);
}

int count_neighbors(int board[NUM_CELLS * NUM_CELLS], int x, int y) {
    int neighbors = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        if (i >= 0 && i < WIDTH) {
            for (int j = y - 1; j <= y + 1; j++) {
                if (j >= 0 && j < HEIGHT) {
                    if (board[i * NUM_CELLS + j] == LIVING) {
                        neighbors++;
                    }
                }
            }
        }
    }
    neighbors -= board[x * NUM_CELLS + y];
    return neighbors;
}

void copy_array(int board[NUM_CELLS * NUM_CELLS], int values[NUM_CELLS * NUM_CELLS]) {
    for (int i = 0; i < NUM_CELLS; i++) {
        for (int j = 0; j < NUM_CELLS; j++) {
            board[i * NUM_CELLS + j] = values[i * NUM_CELLS + j];
        }
    }
}