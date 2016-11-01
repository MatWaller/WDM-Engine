#include "PauseState.h"
#include "PlayState.h"


PauseState PauseState::m_PauseState;
Texture  pauseSprite;

void PauseState::Init()
{	
    pauseSprite.create("Assets/Images/bitmap.bmp", 100, 100);
	printf("PauseState Init Successful\n");
}

void PauseState::Clean()
{
	printf("PauseState Clean Successful\n");
}

void PauseState::Pause()
{
	printf("PauseState Paused\n");
}

void PauseState::Resume()
{
	printf("PauseState Resumed\n");
}

void PauseState::HandleEvents(Game* game) {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				game->Quit();
			break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_SPACE:
                        game->PopState();
                    break;
                }
            break;
		}
	}
}

void PauseState::Update(Game* game) {
}

void PauseState::Draw(Game* game) {
    // let the state draw the screen
    // Draw Black Background Layer.
    SDL_SetRenderDrawColor(displayManager.renderer, 0xFA, 0xd7, 0xf8, 0x00);

    // Clear Renderer.
    SDL_RenderClear(displayManager.renderer);

    pauseSprite.render(0,0);

	SDL_RenderPresent(displayManager.renderer);
}

