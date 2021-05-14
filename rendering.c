#include "rendering.h"

const SDL_Color GRID_COLOR = {
        .r = 92,
        .g = 92,
        .b = 92
};

const SDL_Color LIVING_CELL_COLOR = {
        .r = 255,
        .g = 255,
        .b = 255
};

const SDL_Color DEAD_CELL_COLOR = {
        .r = 0,
        .g = 0,
        .b = 0
};

void render_game(SDL_Renderer *renderer, Game *game) {
    render_grid(renderer, &GRID_COLOR);
    render_cells(renderer, game->board);

}

void render_cells(SDL_Renderer *renderer, const int board[NUM_CELLS * NUM_CELLS]) {
    for (int i = 0; i < NUM_CELLS; i++) {
        for (int j = 0; j < NUM_CELLS; j++) {
            int cell = board[i * NUM_CELLS + j];
            if (cell == DEAD) {
                SDL_SetRenderDrawColor(renderer, DEAD_CELL_COLOR.r, DEAD_CELL_COLOR.g, DEAD_CELL_COLOR.b, ALPHA);
            } else {
                SDL_SetRenderDrawColor(renderer, LIVING_CELL_COLOR.r, LIVING_CELL_COLOR.g, LIVING_CELL_COLOR.b, ALPHA);
            }

            SDL_Rect rect;
            rect.x = i * CELL_WIDTH + 1;
            rect.y = j * CELL_HEIGHT + 1;
            rect.w = CELL_WIDTH - 1;
            rect.h = CELL_HEIGHT - 1;

            SDL_RenderFillRect(renderer, &rect);
        }
    }
    SDL_SetRenderDrawColor(renderer, DEAD_CELL_COLOR.r, DEAD_CELL_COLOR.g, DEAD_CELL_COLOR.b, ALPHA);
}


void render_grid(SDL_Renderer *renderer, const SDL_Color *color) {
    SDL_SetRenderDrawColor(renderer, color->r, color->b, color->g, ALPHA);
    for (int i = 1; i < NUM_CELLS; i++) {
        SDL_RenderDrawLine(renderer, i * CELL_WIDTH, 0, i * CELL_WIDTH, HEIGHT);
        SDL_RenderDrawLine(renderer, 0, i * CELL_HEIGHT, WIDTH, i * CELL_HEIGHT);
    }
    SDL_SetRenderDrawColor(renderer, DEAD_CELL_COLOR.r, DEAD_CELL_COLOR.g, DEAD_CELL_COLOR.b, ALPHA);
}


