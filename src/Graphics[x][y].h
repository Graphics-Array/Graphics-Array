#ifndef GRAPHICS_X_Y_H
#define GRAPHICS_X_Y_H

#include <SDL2/SDL.h>
#include <stdbool.h>

extern SDL_Window *win;
extern SDL_Renderer *ren;

bool init(const char *title, int width, int height);
void quit();

#endif
