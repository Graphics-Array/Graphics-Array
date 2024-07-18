#include <SDL2/SDL.h>
#include <stdio.h>

SDL_Renderer *ren = NULL;

typedef struct {
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
} Color;

void Draw_rect(Color color, int width, int height, int xpos, int ypos) {
    SDL_Rect rect;
    rect.x = xpos; // X position
    rect.y = ypos; // Y position
    rect.w = width; // Width
    rect.h = height; // Height

    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); // Black background
    SDL_RenderClear(ren);

    SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a); // Rectangle color
    SDL_RenderFillRect(ren, &rect);

    SDL_RenderPresent(ren);
}
void Draw_triangle(Color color, int x1, int y1, int x2, int y2, int x3, int y3) {
    SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a);
    
    // Draw the three sides of the triangle
    SDL_RenderDrawLine(ren, x1, y1, x2, y2);
    SDL_RenderDrawLine(ren, x2, y2, x3, y3);
    SDL_RenderDrawLine(ren, x3, y3, x1, y1);

    SDL_RenderPresent(ren);
}

void Draw_circle(Color color, int cx, int cy, int radius) {
    SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a);
    int d = 3 - 2 * radius;
    int x = 0, y = radius;

    while (y >= x) {
        SDL_RenderDrawPoint(ren, cx + x, cy + y);
        SDL_RenderDrawPoint(ren, cx - x, cy + y);
        SDL_RenderDrawPoint(ren, cx + x, cy - y);
        SDL_RenderDrawPoint(ren, cx - x, cy - y);
        SDL_RenderDrawPoint(ren, cx + y, cy + x);
        SDL_RenderDrawPoint(ren, cx - y, cy + x);
        SDL_RenderDrawPoint(ren, cx + y, cy - x);
        SDL_RenderDrawPoint(ren, cx - y, cy - x);
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
    SDL_RenderPresent(ren);
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("SDL Rectangle", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL) {
        SDL_DestroyWindow(win);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    Color red = {255, 0, 0, 255}; // Define a red color
  //  Draw_rect(red, 200, 200, 200, 200);
  ////  Color blue={0, 0,255,255};
//	Draw_circle(blue,140,55,300);
	Draw_triangle(red, 50, 55, 60, 20, 66, 80);
    SDL_Event e;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }
        SDL_Delay(100); // Delay to prevent high CPU usage
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
