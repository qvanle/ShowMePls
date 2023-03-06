#include "SDL_surface.h"
#include "SDL_video.h"
#include <Screen.hpp>
#include <iostream>

void Screen::loadBackground(const char *dir, const char* name)
{
    int n = strlen(dir) + strlen(name) + 5;
    char* link = new char[n];
    link[0] = '\0';
    strcat(link, dir);
    strcat(link, name);
    background = SDL_LoadBMP(link);
}

void Screen::draw(SDL_Window*& window)
{
    SDL_Rect scale;
    scale.x = 0;
    scale.y = 0;
    scale.w = 1280;
    scale.h = 720;

    display = SDL_GetWindowSurface(window);
    SDL_BlitSurface(background, nullptr, display, &scale);
    SDL_UpdateWindowSurface(window);
}
