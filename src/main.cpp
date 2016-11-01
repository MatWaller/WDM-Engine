#include "Engine/Logic/Game.h"

int main()
{
    Game game;
    game.Init(640, 480);

    while(game.Running()){
        game.HandleEvents(&game);
        game.Update();
        game.Draw();
    }

    game.Clean();
    return 0;
}   