#ifndef VISUALIZER
#define VISUALIZER

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <LowLevel.hpp>

namespace SYS
{
    extern SDL_Window* window;
    extern bool isOpen;
    bool Initialization();
    void Start();
    void Interacting();
}
#endif
