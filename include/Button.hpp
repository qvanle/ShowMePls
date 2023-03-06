#ifndef BUTTON
#define BUTTON

#include "SDL_surface.h"
#include <vector>
#include <SDL2/SDL.h>
#include <SDL_surface.h>

struct Button 
{
    std::vector<SDL_Surface> textures;    
    int status;
};

#endif
