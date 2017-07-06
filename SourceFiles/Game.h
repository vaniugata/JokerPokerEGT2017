#ifndef GAME_H
#define GAME_H

#include "Texture.h"
#include "Engine.h"

#include <SDL.h>

typedef enum
{
	INTRO,
	PLAY,
	OUTRO,
	QUIT,
} eGame_State;

class Game
{
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	Engine* m_engine;

	Texture* m_texture;

public:
	eGame_State m_eGameState;
	SDL_Event m_event;

//MEMBER FUNCTIONS
	Game();
	~Game();

//GETTERS
	Texture* GetTexture();
	SDL_Renderer* GetRenderer();

private:
	void InitSDL();
	void LoadMedia();
	void Close();
};
#endif