#include "LowLevel.hpp"
#include "SDL_surface.h"
#include "SDL_video.h"
#include "Screen.hpp"
#include <Visualizer.hpp>

int main(int argc, char *argv[])
{
    if(!SYS::Initialization())
    {
        std::cout << "Unable to run!" << std::endl;
        return 0;
    }
    
    SYS::Start();
    Screen homeScreen;
    homeScreen.loadBackground(GLOBAL::BGFolder, "home.bmp");
    homeScreen.draw(SYS::window);

    while(SYS::isOpen)
    {
        SYS::Interacting();
    }

    SDL_DestroyWindow(SYS::window);
    SDL_Quit();

	return 0;
}

