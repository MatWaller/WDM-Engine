#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "../Graphics/DisplayManager.h"
#include "../Graphics/Texture.h"


class Game
{
  public:
    Game();
    void Init(int width, int height);
    void HandleEvents(Game* game);
    void Update();
    void Draw();
    void Quit();
    void Clean();
    bool Running();

  private:
    bool m_bRunning;
};
#endif