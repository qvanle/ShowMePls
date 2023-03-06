#include <Visualizer.hpp>

int main(int argc, char *argv[])
{
    if(!SYS::Initialization())
    {
        std::cout << "Unable to run!" << std::endl;
        return 0;
    }
    
    SYS::Start();

    while(SYS::isOpen)
    {
        SYS::Interacting();
    }

    SDL_DestroyWindow(SYS::window);
    SDL_Quit();

	return 0;
}

