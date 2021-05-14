#include "input.h"

void click_on_board(Game *game, int mouseX, int mouseY) {
    int row = mouseX / CELL_WIDTH, col = mouseY / CELL_HEIGHT;
    if (game->state == PAUSED) {
        if (game->board[row * NUM_CELLS + col] == DEAD) {
            game->board[row * NUM_CELLS + col] = LIVING;
        } else if (game->board[row * NUM_CELLS + col] == LIVING) {
            game->board[row * NUM_CELLS + col] = DEAD;
        }
    }
}

