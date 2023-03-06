#ifndef VISUALIZER
#define VISUALIZER

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <iostream>

namespace SYS
{
    extern SDL_Window* window;
    extern SDL_GLContext context; 
    extern bool isOpen;
    bool Initialization();
    void Start();
    void Interacting();
}
#endif
