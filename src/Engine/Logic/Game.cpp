#include "Game.h"

Texture test;

Game::Game(){
}

void Game::Init(int w, int h){
    Game::m_bRunning = true;
    displayManager.init(w, h);
    test.create("Assets/Images/sprites.png", NULL, NULL);
}

bool Game::Running(){
    return Game::m_bRunning;
}

void Game::HandleEvents(Game* game){
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				game->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
						game->Quit();
				}
				break;
		}
	}
}

void Game::Update(){
    
}

void Game::Draw(){
    // Draw Black Background Layer.
    SDL_SetRenderDrawColor(displayManager.renderer, 0x00, 0x00, 0x00, 0x00);

    // Clear Renderer.
    SDL_RenderClear(displayManager.renderer);

	test.render(0,0);

	SDL_RenderPresent(displayManager.renderer);
}

void Game::Quit() {
    Game::m_bRunning = false;
}

void Game::Clean(){

}