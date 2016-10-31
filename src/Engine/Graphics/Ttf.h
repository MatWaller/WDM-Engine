#ifndef _Ttf_
// Avoid multiple inclusions.
#define _Ttf_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h> 
#include <stdio.h> 
#include <string> 
#include <cmath>

#include "../header.h"



using namespace std;
class Ttf
{
    private: 
        std::string stringText;
        SDL_Color stringColor;
    public:
        ~Ttf();
        void create(std::string stringText, SDL_Color stringColor, char* path, int fontSize);
        void setText(std::string stringText);
        void setColor(SDL_Color stringColor);
        void render(int x, int y);
        void free();
        SDL_Texture *textTexture;
        SDL_Surface *textSurface;
        SDL_Rect textRect;
        TTF_Font *font;
        int height, width;

};
#endif // _Ttf_