#include <iostream>
#include <Visualizer.hpp>

int main(int argc, char *argv[])
{
    if(!SYS::Initialization())
    {
        std::cout << "Unable to run!" << std::endl;
        return 0;
    }else std::cout << "ShowMePls is running!" << std::endl;

    SYS::window = SDL_CreateWindow(
                        "Show me please!",
					    SDL_WINDOWPOS_CENTERED,
					    SDL_WINDOWPOS_CENTERED - 20,
					    1280, 700, 0 
                      );
    
    bool isOpen = true;

    while(isOpen == true)
    {
        SDL_Event event;

        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                isOpen = false;
            }
        }
    }

    SDL_DestroyWindow(SYS::window);
    SDL_Quit();

	return 0;
}

