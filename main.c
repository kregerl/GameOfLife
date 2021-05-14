#include <stdio.h>
#include <time.h>
#include "game.h"
#include "input.h"
#include "rendering.h"


int main() {
    srand(time(NULL));
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Could not initialize sdl2: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow("Game of Life",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WIDTH, HEIGHT,
                                          SDL_WINDOW_SHOWN);

    if (window == NULL) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
                                                SDL_RENDERER_ACCELERATED |
                                                SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    Game game;
    init_game(&game);


    SDL_Event e;
    while (game.state != QUIT) {
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    game.state = QUIT;
                    break;

                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym) {
                        case SDLK_SPACE:
                            if (game.state == PAUSED) {
                                game.state = RUNNING;
                            } else if (game.state == RUNNING) {
                                game.state = PAUSED;
                            }
                            break;
                        case SDLK_s:
                            if (game.state == PAUSED) {
                                step(&game);
                            }
                            break;
                        case SDLK_r:
                            if (game.state == PAUSED) {
                                memset(&(game.board), 0, NUM_CELLS * NUM_CELLS * sizeof(int));
                            }
                            break;
                        case SDLK_f:
                            init_game(&game);
                            break;

                        default: {
                            break;
                        }
                    }
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    click_on_board(&game, e.button.x, e.button.y);
                    break;

                default: {
                }
            }
        }


        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        render_game(renderer, &game);
        SDL_RenderPresent(renderer);
        if (game.state == RUNNING) {
            step(&game);
        }
        SDL_Delay(100);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
