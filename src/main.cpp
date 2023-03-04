#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <iostream>

bool init()
{	
    // returns true on success else return false
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
    {
        std::cout << "Error when initialized SDL video" << std::endl;
        return false;
	}else std::cout << "Initializing SDL video success" << std::endl;
    
    return true;
}

int main(int argc, char *argv[])
{
    
    if(!init()) 
    {
        std::cout << "Unable to initalize" << std::endl;
        return 0;
    }

	SDL_Window* window = SDL_CreateWindow(
                        "Show me please!",
					    SDL_WINDOWPOS_CENTERED,
					    SDL_WINDOWPOS_CENTERED,
					    1000, 1000, 0
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


    SDL_DestroyWindow(window);
    SDL_Quit();

	return 0;
}

