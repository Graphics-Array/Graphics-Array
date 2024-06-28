#ifndef GRAPHICS_X_Y_H_INCLUDED
#define GRAPHICS_X_Y_H_INCLUDED

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

// Global variables
SDL_Window *win;
SDL_Renderer *ren;
 

// Function prototypes
bool init(const char *title, int width, int height);
void quit();

#endif // GRAPHICS_X_Y_H_INCLUDED
