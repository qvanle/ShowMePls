#ifndef WINDOW
#define WINDOW

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <glad/glad.h>
#include <iostream>

class MyWindow 
{
private:
    SDL_Window* window;
    SDL_GLContext context; 
    bool status;
    bool isInitialized;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
public:
    bool Initialize();
    bool isOpen();
    bool Start();
    void Interacting();
    void shutdown();
    void updateWithGL();
};
#endif
