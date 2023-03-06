#ifndef SCREEN 
#define SCREEN

#include "SDL_surface.h"
#include <SDL2/SDL.h>

struct Screen 
{
    SDL_Surface* background;
    SDL_Surface* display;

    void loadBackground(const char* dir, const char* name);
    void draw(SDL_Window*& window);
};

#endif
