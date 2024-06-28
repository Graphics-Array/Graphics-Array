// SimpleGL
#include<SDL2/SDL.h>
#include<stdbool.h>
#include<stdio.h>
//Global variables
SDL_Window *win=NULL;
SDL_Renderer *ren=NULL;
bool init(const char *title,int width, int height){
	SDL_Init(SDL_INIT_EVERYTHING);
	win=SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
	ren=SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);
	return 0;
}
void quit(){
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	SDL_Quit();
}
/*
int main (){
	puts("include SimpleGL.h in your project");
	return 0;
}
*/