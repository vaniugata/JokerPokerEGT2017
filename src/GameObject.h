#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "Texture.h"


class GameObject
{
protected:
	SDL_Renderer* m_renderer;

public:
	GameObject(SDL_Renderer* renderer);
	virtual~GameObject();

	virtual void Render(SDL_Rect* clip, int x, int y, int w, int h)  = 0;
	virtual void HandleEvent(SDL_Event* event) = 0;
};
#endif
