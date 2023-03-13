#ifndef WINDOW
#define WINDOW

#include <SDL_rect.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <SYSTEM.hpp>
#include <SDL_surface.h>
#include <SDL_timer.h>
#include <SDL2/SDL.h>

class MyWindow
{
private:
    SDL_Window* window;
    SDL_Surface* background;
    SDL_Surface* display;
    int status;
public:
    MyWindow();
    bool isOpen();
    bool isClosed();
    void loadBackground(const char* dir, const char* name);
    bool Initialization();
    void Start();
    void Interacting();
    void render();
    void shutdown();
};

#endif
