#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "GameState.h"

#include "../Graphics/DisplayManager.h"
#include "../Graphics/Texture.h"

class PauseState : public GameState
{
	public:
		void Init();
		void Clean();
		
		void Pause();
		void Resume();
		
		void HandleEvents(Game* game);
		void Update(Game* game);
		void Draw(Game* game);
		
		// Implement Singleton Pattern
		static PauseState* Instance()
		{
			return &m_PauseState;
		}
		
	protected:
		
		PauseState() {}
		
	private:
		static PauseState m_PauseState;
};

#endif