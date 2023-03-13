#ifndef BUTTON
#define BUTTON

#include <vector>
#include <SDL_surface.h>
#include <filesystem>

class Button 
{
private:
    std::vector<SDL_Surface*> textures;    
    int status;
    const char* dir;
    const char* Text;
public:
    Button();
    void setTextures(const char* link);
    void setText(const char* s);
    void setStatus(int k);
    int getStatus();
    void FreeTextures();
    SDL_Surface* getTexture();
};

#endif
