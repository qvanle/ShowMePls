#include <iostream>

#include <SDL2/SDL.h>

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized: " << SDL_GetError() << std::endl;
    }else 
    {
        std::cout << "SDL video system is ready to go" << std::endl;
    }
    return 0;
}
