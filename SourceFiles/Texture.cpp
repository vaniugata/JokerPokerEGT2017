#include "Texture.h"
#include <iostream>
#include <SDL_image.h>

Texture::Texture() : m_texture(nullptr)
{

}

Texture::~Texture()
{
	Free();
	std::cout << "Texture deleted.\n";
}

void Texture::LoadFromFile(SDL_Renderer* renderer, std::string path)
{
	Free();

	SDL_Surface* surface = IMG_Load(path.c_str() );
	if(surface == nullptr)
	{
		std::cerr << "Unable to load image" << path << " ! SDL_image Error: " << \
			SDL_GetError();
		return;
	}

	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 255, 0));

	m_texture = SDL_CreateTextureFromSurface(renderer, surface);

	m_rectSource.w = surface->w;
	m_rectSource.h = surface->h;

	SDL_FreeSurface(surface);
	surface = nullptr;
}

void Texture::SetDestRect(int x, int y, int w, int h)
{
	if(x < 0 || y < 0 || w < 0 || h < 0)
	{
		std::cout << "Rect dimentions cant be less than 0.";
		return;
	}

	m_rectDestination.x = x;
	m_rectDestination.y = y;
	m_rectDestination.w = w;
	m_rectDestination.y = h;
}

void Texture::Render(SDL_Renderer& renderer, SDL_Rect & source, SDL_Rect & destination)
{
	SDL_RenderCopy(&renderer, m_texture, &source, &destination);
}

void Texture::Free()
{
	SDL_DestroyTexture(m_texture);
	m_texture = nullptr;

	m_rectSource.x = m_rectDestination.x = 0;
	m_rectSource.y = m_rectDestination.y = 0;
	m_rectSource.w = m_rectDestination.w = 0;
	m_rectSource.h = m_rectDestination.h = 0;
}
