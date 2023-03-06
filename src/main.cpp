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
        glClearColor(0.0f, 0.5f, 1.0f, 1.0f);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(SYS::window);
    }

    SDL_DestroyWindow(SYS::window);
    SDL_Quit();

	return 0;
}

