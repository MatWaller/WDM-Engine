#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "Engine/header.h"
#include "Engine/Graphics/Texture.h"
#include "Engine/Graphics/Ttf.h"

// Define character and background textures.
Texture character, background;

// Define Font textures.
Ttf ttfText;


bool quit = false;

SDL_Event e;

void load(), tick();

int main()
{
    // Initialise DisplayManager using the SCREEN_WIDTH, AND SCREEN_HEIGHT
    displayManager.init(SCREEN_WIDTH, SCREEN_HEIGHT);

    // Create Textures, Text Textures and Sound objects.
    load();

    // Keep game running until quit has been set to true.
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            // If the window is closed set quit to true and exit.
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        // Run tick on every loop itteration.
        tick();
    }
    displayManager.showSimpleMessageBox("Completed", "The application has completed.");
    return 0;
}

void load()
{
    // Set SDL_Color RGB to yellow.
    SDL_Color stringColor = {0,255,255};

    // Load Character Sprite png providing NULL for heigh and width (default height/width)
    character.create("Assets/Images/sprites.png",NULL, NULL);

    // Create a background texture from file and resize.
    background.create("Assets/Images/bitmap.bmp",SCREEN_WIDTH, SCREEN_HEIGHT);

    //  Create a TTF Texture from a loaded font and given text.
    ttfText.create("Eddie Smells", stringColor, "Assets/font/GoodDog.otf", 50);
}

void tick()
{
    // Draw Black Background Layer.
    SDL_SetRenderDrawColor(displayManager.renderer, 0x00, 0x00, 0x00, 0x00);

    // Clear Renderer.
    SDL_RenderClear(displayManager.renderer);

    // Clipping Array Declaration.
    SDL_Rect gSpriteClips[4];

    // Clipping Array Definition For Circles.
    gSpriteClips[ 0 ] = {0,0,100,100};
    gSpriteClips[ 1 ] = {100,0,100,100};
    gSpriteClips[ 2 ] = {0,100,100,100};
    gSpriteClips[ 3 ] = {100,100,100,100};

    // Render TTF Texture.
    ttfText.render(200,200);

    // Render Circle Textures in each corner.

    character.setAlpha(20);

    character.render(0,0,&gSpriteClips[0]);
    character.render( SCREEN_WIDTH - gSpriteClips[ 1 ].w, 0, &gSpriteClips[ 1 ] );
    character.render( 0, SCREEN_HEIGHT - gSpriteClips[ 2 ].h, &gSpriteClips[ 2 ] );
    character.render( SCREEN_WIDTH - gSpriteClips[ 3 ].w, SCREEN_HEIGHT - gSpriteClips[ 3 ].h, &gSpriteClips[ 3 ] );

    // Update the screen with rendering performed.
    SDL_RenderPresent(displayManager.renderer);
}