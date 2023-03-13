#include <Window.hpp>

MyWindow::MyWindow()
{
    Initialization();
    status = 0;
    window = nullptr;
    WIDTH = 960;
    HEIGHT = 540;
}
bool MyWindow::Initialization()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Error when initalized SDL video" << std::endl; 
        return false;
    }else std::cout << "Initializing SDL video success" << std::endl;
    
    return true;
}

void MyWindow::Start()
{

    status = 1;

    window = SDL_CreateWindow(
        "Show me please!", 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, 
        HEIGHT, 
        SDL_WINDOW_SHOWN 
    );

    if(window == nullptr) 
    {
        std::cout << "Unable to run!" << std::endl;
        return ;
    }

    std::cout << "ShowMePls is running" << std::endl;
    SDL_SetWindowBordered(window, SDL_TRUE);
    
    display = SDL_GetWindowSurface(window);

    return ;
}

void MyWindow::Interacting()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            status = 0;
        }
    }
}

void MyWindow::loadBackground(const char *dir, const char *name)
{
    int n = strlen(dir) + strlen(name) + 2;
    char* link = new char[n];

    link[0] = '\0';
    strcat(link, dir);
    strcat(link, name);
     
    background = SDL_LoadBMP(link);

    if(background == nullptr) 
        std::cout << "Unable to load bakground" << std::endl;

    return ;
}

void MyWindow::render()
{
    SDL_Rect scale;
    scale.x = 0; scale.y = 0;
    scale.w = WIDTH; scale.h = HEIGHT;
    SDL_BlitSurface(background, nullptr, display, &scale);
    SDL_UpdateWindowSurface(window);

    return ;
}

void MyWindow::shutdown()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool MyWindow::isOpen()
{
    return status == 1;
}
bool MyWindow::isClosed()
{
    return status == 0;
}
