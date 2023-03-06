#include "LowLevel.hpp"
#include <SDL_surface.h>
#include <SDL_timer.h>
#include <Screen.hpp>
#include <SDL2/SDL_video.h>
#include <Visualizer.hpp>

bool SYS::isOpen = false;
SDL_Window* SYS::window = nullptr;

bool SYS::Initialization()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Error when initalized SDL video" << std::endl; 
        return false;
    }else std::cout << "Initializing SDL video success" << std::endl;


    return true;
}

void SYS::Start()
{
    std::cout << "ShowMePls is running" << std::endl;

    SYS::isOpen = true;

    SYS::window = SDL_CreateWindow(
        "Show me please!", 
        SDL_WINDOWPOS_CENTERED,
        0,
        1280, 
        720, 
        SDL_WINDOW_SHOWN 
    );
    SDL_SetWindowBordered(SYS::window, SDL_TRUE);
    return ;
}

void SYS::Interacting()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            SYS::isOpen = false;
        }
    }
}

