#include "Graphics[x][y].h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

// Global variables
// SDL_Window *win = NULL;
// SDL_Renderer *ren = NULL;

bool init(const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return false;
    }
    win = SDL_CreateWindow(title, 100, 100, width, height, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL) {
        SDL_DestroyWindow(win);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }
    return true;
}

void quit() {
    if (ren) {
        SDL_DestroyRenderer(ren);
    }
    if (win) {
        SDL_DestroyWindow(win);
    }
    SDL_Quit();
}
