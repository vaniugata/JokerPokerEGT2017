#ifndef SCREEN_H
#define SCREEN_H
#include"Music.h"
#include "includesSDL2.h"

class Screen 
{
protected:
	SDL_Renderer* m_renderer;

public:
	Screen(SDL_Renderer* renderer);
	virtual~Screen();

	virtual void Draw();
	virtual void Render() = 0;
	virtual void HandleEvent() = 0;
};
#endif

