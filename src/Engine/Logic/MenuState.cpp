#include "MenuState.h"
#include "PlayState.h"
MenuState MenuState::m_MenuState;
Texture  menuSprite;

void MenuState::Init()
{	
    menuSprite.create("Assets/Images/sprites.png", 100, 100);
	printf("MenuState Init Successful\n");
}

void MenuState::Clean()
{
	printf("MenuState Clean Successful\n");
}

void MenuState::Pause()
{
	printf("MenuState Paused\n");
}

void MenuState::Resume()
{
	printf("MenuState Resumed\n");
}

void MenuState::HandleEvents(Game* game) {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				game->Quit();
				break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_SPACE:
                        game->ChangeState(PlayState::Instance());
                    break;
                }
            break;
		}
	}
}

void MenuState::Update(Game* game) {
}

void MenuState::Draw(Game* game) {
    // let the state draw the screen
    // Draw Black Background Layer.
    SDL_SetRenderDrawColor(displayManager.renderer, 0xFA, 0xd7, 0x00, 0x00);

    // Clear Renderer.
    SDL_RenderClear(displayManager.renderer);

    menuSprite.render(0,0);

	SDL_RenderPresent(displayManager.renderer);
}

