#ifndef SDLLIFE_RENDERING_H
#define SDLLIFE_RENDERING_H

#include "game.h"

#define ALPHA 255

void render_game(SDL_Renderer *renderer, Game *game);

void render_cells(SDL_Renderer *renderer, const int board[NUM_CELLS * NUM_CELLS]);

void render_grid(SDL_Renderer *renderer, const SDL_Color *color);

#endif //SDLLIFE_RENDERING_H
