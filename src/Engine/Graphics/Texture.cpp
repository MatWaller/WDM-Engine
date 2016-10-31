#import "Texture.h"

SDL_Texture *texture;
SDL_Surface *image;
SDL_Rect imageRect;

void Texture::create(char* path, int width = NULL, int height = NULL){
    free();
    int imgFlags = (IMG_INIT_PNG, IMG_INIT_JPG);
    if( !( IMG_Init( imgFlags ) & imgFlags ) ){
        SDL_Quit();
        IMG_Quit();
    }

    image = IMG_Load(path);
    if(image == NULL){
        SDL_Quit();
        IMG_Quit();
    }

    // Making cyan which is red 0, green 255, blue 255 the transparent key.
    SDL_SetColorKey( image, SDL_TRUE, SDL_MapRGB( image->format, 0, 0xFF, 0xFF ) );
    texture = SDL_CreateTextureFromSurface(displayManager.renderer, image);
    
    if(height != NULL || width != NULL){
        imageRect.h = height;
        imageRect.w = width;
    }else{
        imageRect.h = image->h;
        imageRect.w = image->w;
    }

    SDL_FreeSurface( image );
}

Texture::~Texture(){
    free();
}

void Texture::free(){
     if( texture != NULL ){
        SDL_DestroyTexture( texture );
     }
}

void Texture::setColor( Uint8 red, Uint8 green, Uint8 blue ){
     SDL_SetTextureColorMod( texture, red, green, blue );
}

void Texture::setBlendMode( SDL_BlendMode blending ){
     SDL_SetTextureBlendMode( texture, blending );
}

void Texture::setAlpha( Uint8 alpha ){
     SDL_SetTextureAlphaMod( texture, alpha );
}

void Texture::render(int x, int y, SDL_Rect* clip = NULL, double angle, SDL_Point* center, SDL_RendererFlip flip ){
     SDL_Rect renderQuad = { x, y, imageRect.w, imageRect.h };

     if( clip != NULL ) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
     }

     SDL_RenderCopyEx( displayManager.renderer, texture, clip, &renderQuad, angle, center, flip );
}