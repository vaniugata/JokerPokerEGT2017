#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "Texture.h"


class GameObject
{
private:
	Texture m_texture;

public:
	GameObject(SDL_Renderer* renderer, std::string path);
	virtual~GameObject();

	void Update();
	void Render(SDL_Renderer* renderer, int x, int y, int w, int h);
};
#endif
