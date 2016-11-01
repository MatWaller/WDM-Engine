#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <vector>


#include "../Graphics/DisplayManager.h"
#include "../Graphics/Texture.h"


class GameState; 
class Game
{
  public:
    Game();
    void Init(int width, int height);

    void ChangeState(GameState* state); // new function
	void PushState(GameState* state);  // new function
	void PopState(); // new function

    void HandleEvents();
    void Update();
    void Draw();
    void Quit();
    void Clean();
    bool Running();

  private:
    bool m_bRunning;
    std::vector<GameState*> states;
};
#endif