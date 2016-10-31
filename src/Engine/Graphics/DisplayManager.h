#ifndef _DisplayManager_
// Avoid multiple inclusions.
#define _DisplayManager_
#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>

using namespace std;


class DisplayManager
{
    public:
    SDL_Window* window;
    SDL_Surface* screenSurface;
    SDL_Renderer* renderer;
    void init(int SCREEN_WIDTH, int SCREEN_HEIGHT);
    int UpdateScreen();
    int showSimpleMessageBox(char* title, char* message);
};

extern DisplayManager displayManager;


#endif // _DisplayManager_