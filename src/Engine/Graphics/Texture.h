#ifndef _Texture_
// Avoid multiple inclusions.
#define _Texture_
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../header.h"


using namespace std;
class Texture
{
    public:
        ~Texture();
        SDL_Texture *texture;
        SDL_Surface *image;
        SDL_Rect imageRect;
        void setColor( Uint8 red, Uint8 green, Uint8 blue );
        void setBlendMode( SDL_BlendMode blending );
        void setAlpha( Uint8 alpha );
        void create(char* path, int width, int height);
        void free(), render(int x, int y, SDL_Rect* clip = NULL,  
        double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
};
#endif // _Texture_