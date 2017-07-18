#ifndef GAME_STATE_H
#define GAME_STATE_H
#include "includesSDL2.h"


class Scene
{
protected:
	SDL_Renderer* m_renderer;

public:
	Scene(SDL_Renderer* renderer);
	virtual~Scene();

	virtual void Draw();
	virtual void Render() = 0;
	virtual void HandleEvent() = 0;
};

#endif

