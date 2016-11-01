#include "PlayState.h"

PlayState PlayState::m_PlayState;
Texture  playSprite;

void PlayState::Init()
{	
    playSprite.create("Assets/Images/sprites.png", 100, 100);
	printf("PlayState Init Successful\n");
}

void PlayState::Clean()
{
	printf("PlayState Clean Successful\n");
}

void PlayState::Pause()
{
	printf("PlayState Paused\n");
}

void PlayState::Resume()
{
	printf("PlayState Resumed\n");
}

void PlayState::HandleEvents(Game* game) {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				game->Quit();
				break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_SPACE:
                        game->PushState(PauseState::Instance());
                    break;
                }
            break;
		}
	}
}

void PlayState::Update(Game* game) {
}

void PlayState::Draw(Game* game) {
    // let the state draw the screen
    // Draw Black Background Layer.
    SDL_SetRenderDrawColor(displayManager.renderer, 0xFA, 0xd7, 0xf8, 0x00);

    // Clear Renderer.
    SDL_RenderClear(displayManager.renderer);

    playSprite.render(0,0);

	SDL_RenderPresent(displayManager.renderer);
}

