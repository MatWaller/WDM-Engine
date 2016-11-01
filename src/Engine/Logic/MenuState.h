#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "GameState.h"
#include "PlayState.h"


#include "../Graphics/DisplayManager.h"
#include "../Graphics/Texture.h"

class MenuState : public GameState
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
		static MenuState* Instance()
		{
			return &m_MenuState;
		}
		
	protected:
		
		MenuState() {}
		
	private:
		static MenuState m_MenuState;
};

#endif

