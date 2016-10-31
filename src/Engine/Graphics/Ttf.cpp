#include "Ttf.h"


SDL_Texture *textTexture;
SDL_Surface *textSurface;
SDL_Rect textRect;
TTF_Font *font;
int height, width;


void Ttf::create(std::string stringText, SDL_Color stringColor, char* fontPath, int fontSize){
     if( TTF_Init() == -1 ) {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
     }
     font = TTF_OpenFont( fontPath, fontSize );
     if( font == NULL ) {
         printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() ); 
     }else{

     }

     textSurface = TTF_RenderText_Solid( font, stringText.c_str(), stringColor );
    
     if( textSurface == NULL ) {
         printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
     }else{
         textTexture = SDL_CreateTextureFromSurface( displayManager.renderer, textSurface );
         if(textTexture == NULL){
              printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
         }else{
              height = textSurface->w;
              width = textSurface->w;
         }
         SDL_FreeSurface( textSurface );
     }
}

Ttf::~Ttf(){
    free();
}

void Ttf::free(){
     if( textTexture != NULL ){
        SDL_DestroyTexture( textTexture );
     }
}

void Ttf::render(int x, int y){
     SDL_Rect renderQuad = { x, y, height , width};
     SDL_RenderCopy( displayManager.renderer, textTexture, NULL, &renderQuad);
}