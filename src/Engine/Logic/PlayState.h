#ifndef _PLAY_STATE_H_
#define _PLAY_STATE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "GameState.h"
#include "PauseState.h"


#include "../Graphics/DisplayManager.h"
#include "../Graphics/Texture.h"

class PlayState : public GameState
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
		static PlayState* Instance()
		{
			return &m_PlayState;
		}
		
	protected:
		
		PlayState() {}
		
	private:
		static PlayState m_PlayState;
};

#endif

