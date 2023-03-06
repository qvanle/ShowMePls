#ifndef VISUALIZER
#define VISUALIZER

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <iostream>

namespace SYS
{
    SDL_Window* window;
    
    bool Initialization()
    {
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
        {
            std::cout << "Error when initalized SDL video" << std::endl; 
            return false;
        }else std::cout << "Initializing SDL video success" << std::endl;
    
        return true;
    }
}

#endif
