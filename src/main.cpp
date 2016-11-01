#include "Engine/Logic/Game.h"
#include "Engine/Logic/MenuState.h"
#include <iostream>

int main()
{
    Game game;
    game.Init(640, 480);
    game.ChangeState(MenuState::Instance());
    while(game.Running()){
        game.HandleEvents();
        game.Update();
        game.Draw();
    }

    game.Clean();
    return 0;
}   