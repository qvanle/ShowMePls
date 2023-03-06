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
        SDL_WINDOWPOS_CENTERED - 25,
        1280, 
        700, 
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP
    );
    
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

