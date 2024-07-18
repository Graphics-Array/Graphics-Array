#include <SDL2/SDL.h>
#include <stdbool.h>

// Global variables for window and renderer
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface * Surface = NULL;
SDL_Surface * load_image = NULL;
bool active = true;

// Function prototypes
int init();
void quit();
void events();
void load_media ();

int main() {
    init();

    while (active) {
        events();

        // Update/rendering logic can go here

    }

    quit();
    return 0;
}

int init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    if (window == NULL) {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        fprintf(stderr, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    return 0;
}

void quit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                active = false;
                break;
            // Handle other events here if needed
            default:
                break;
        }
    }
}

void load_media (const char* filename){
file_format_parser_extension(filename);
switch (file){
	case AUDIO:
		switch (audio_format){
			case mp3:
			case wav:
		}
	break;
	case IMAGE:
	switch (image_format){
			case bmp:
			case png:
			case jpg:
		}
}
}

int file_format_parser_extension(const char* filename) {
    const char* extension = strrchr(filename, '.'); // Find last occurrence of '.'
    if (extension == NULL) {
        // Handle case where no extension found
        return UNKNOWN; // Or return default type
    }

    // Move past the '.'
    extension++; 

    // Compare extensions
    if (strcmp(extension, "mp3") == 0 || strcmp(extension, "wav") == 0) {
        return AUDIO;
    } else if (strcmp(extension, "bmp") == 0 || strcmp(extension, "png") == 0 || strcmp(extension, "jpg") == 0) {
        return IMAGE;
    } else {
        return UNKNOWN; // Handle unsupported file types
    }
}
}

void load_bmp(const char *fileNameAndPath){
	SDL_Surface * load_image = SDL_LoadBMP(fileNameAndPath);	
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_Rect dstrect = { xpos, ypos, imgWidth, imgHeight}; 
	SDL_RenderCopy(renderer, texture, NULL, &dstrect);
	SDL_RenderPresent(renderer);
	}
