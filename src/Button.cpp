#include <SDL_surface.h>
#include <Button.hpp>
#include <filesystem>
#include <string>

Button::Button()
{
    status = 0;
}

void Button::setTextures(const char* link)
{
    dir = link;
    std::filesystem::path folder(dir);

    for(auto&p : std::filesystem::directory_iterator(folder))
    {
        SDL_Surface* temp;
        temp = SDL_LoadBMP(p.path().string().c_str());
        textures.push_back(temp);
        SDL_FreeSurface(temp);
    }
}

void Button::setText(const char* s)
{
    Text = s;
}

void Button::setStatus(int k)
{
    status = k;
}

int Button::getStatus()
{
    return status;
}

void Button::FreeTextures()
{
    for(int i = 0; i < (int) textures.size(); i++)
        SDL_FreeSurface(textures[i]);
    textures.clear();
}

SDL_Surface* Button::getTexture()
{
    return textures[status];
}
