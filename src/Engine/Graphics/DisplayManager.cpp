#include "DisplayManager.h"

SDL_Window* window;
SDL_Surface* screenSurface;
SDL_Renderer* renderer;

DisplayManager displayManager;

void DisplayManager::init(int SCREEN_WIDTH, int SCREEN_HEIGHT){
    //Initialize SDL
     if(SDL_Init( SDL_INIT_VIDEO ) < 0 ){
          printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
     }else{
        window = SDL_CreateWindow( "SDL Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, (SDL_WINDOW_SHOWN, SDL_WINDOW_OPENGL) );
        if( window == NULL ){
             printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }else{
             screenSurface = SDL_GetWindowSurface( window );
             renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
        }
     }
}

int DisplayManager::UpdateScreen(){
    SDL_FillRect(screenSurface, NULL, 0x000000);
}

// This needs to be move to the helpers class.
int DisplayManager::showSimpleMessageBox(char *title,char *message){
    return SDL_ShowSimpleMessageBox(0, title, message, window);
}
