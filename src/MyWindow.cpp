#include "SDL_surface.h"
#include "glad/glad.h"
#include <MyWindow.hpp>

bool MyWindow::Initialize()
{
    background = 0;
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Error when initalized SDL video" << std::endl; 
        return false;
    }else std::cout << "Initializing SDL video success" << std::endl;

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    
    status = false;
    SCREEN_WIDTH = 1280;
    SCREEN_HEIGHT = 720;

    return true;
}
bool MyWindow::isOpen()
{
    return status;
}
bool MyWindow::Start()
{
    // create window
    window = SDL_CreateWindow(
        "Show me please!", 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED - 25,
        SCREEN_WIDTH, 
        SCREEN_HEIGHT, 
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP
    );
    if(window == nullptr) 
    {
        std::cout << "Failed to create window." << std::endl;
        return false;
    }

    // load openGL
    context = SDL_GL_CreateContext(window);
    if(!gladLoadGLLoader(SDL_GL_GetProcAddress))
    {
        std::cout << "Failed to initial GLAD(openGL)." << std::endl;
        return false;
    }
    
    // change openGL buffer size
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    status = true;
    glClearColor(0.38f, 0.17, 0.42, 1.0f);

    std::cout << "A window have been started!" << std::endl;

    return true;
}

void MyWindow::Interacting()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            status = false;
        }
    }
}
void MyWindow::shutdown()
{
    status = false;
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void MyWindow::updateWithGL()
{
    SDL_GL_SwapWindow(window);
}

void MyWindow::loadBackground(const char *dir, const char *name)
{
    // concatnate file link
    int n = strlen(dir) + strlen(name);
    char* file = new char[n + 2];
    file[0] = '\0';
    strcat(file, dir);
    strcat(file, name);
    
    // load file
    SDL_Surface* image = SDL_LoadBMP(file);
    
    // import image to openGL
    glGenTextures(1, &background);
    glBindTexture(GL_TEXTURE_2D, background);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->w, image->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    SDL_FreeSurface(image);
}
void draw()
{

    return ;
}
