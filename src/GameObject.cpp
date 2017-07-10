#include "GameObject.h"
#include "Globals.h"
#include <iostream>
using std::cerr;

GameObject::GameObject(SDL_Renderer* renderer = NULL, std::string path = "") : 
	m_texture()
{
	m_texture.LoadFromFile(renderer, path);
}

GameObject::~GameObject()
{
	std::cerr << "GameObject deleted.\n";
}

void GameObject::Update()
{
}

void GameObject::Render(SDL_Renderer * renderer, int x, int y, int w, int h)
{
	x = SCREEN_WIDTH - m_texture.GetWidth();
	y = 0;

	m_texture.Render(renderer, x, y, w, h);
}

