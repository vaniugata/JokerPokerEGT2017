#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "includesSDL2.h"

class GameState
{
protected:
	SDL_Renderer* m_renderer;

public:
	GameState(SDL_Renderer* renderer);
	virtual~GameState();

	virtual void Draw();
	virtual void Render() = 0;
	virtual void HandleEvent() = 0;
};
#endif