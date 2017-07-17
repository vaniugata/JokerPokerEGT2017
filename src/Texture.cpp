#include "Texture.h"
#include "Globals.h"
#include <iostream>
#include "includesSDL2.h"


Texture::Texture(SDL_Renderer* renderer, std::string path) : 
	m_texture(nullptr), m_font(nullptr), m_iWidth(100), m_iHeight(100)
{

}

Texture::~Texture()
{
	Free();
	std::cout << "Texture deleted.\n";
}

int Texture::GetWidth() const
{
	return this->m_iWidth;
}

int Texture::GetHeight() const
{
	return this->m_iHeight;
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

	m_iWidth = surface->w;
	m_iHeight = surface->h;

	SDL_FreeSurface(surface);
	surface = nullptr;
}

void Texture::LoadFromRendererdText(SDL_Renderer * renderer, std::string text, SDL_Color color)
{
	SDL_Surface* textSurface = TTF_RenderText_Solid(m_font, text.c_str(), color);
	if(textSurface == nullptr)
	{
		std::cerr << "Unable to render text surface! SDL_ttf Error: " \
			<< TTF_GetError();
		return;
	}

	m_texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	if(m_texture == nullptr)
	{
		std::cerr << "Unable to create texture from rendered text! SDL Error:" \
			<< SDL_GetError();
		return;
	}

	m_iWidth = textSurface->w;
	m_iHeight = textSurface->h;

	SDL_FreeSurface(textSurface);
}

void Texture::Render(SDL_Renderer* renderer, int x, int y, int w, int h, SDL_Rect* clip)
{
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;

	SDL_RenderCopy(renderer, m_texture, clip, &dest);
}

void Texture::InitFont(std::string path, int fontSize)
{
	m_font = TTF_OpenFont(path.c_str(), fontSize);
	if(m_font == nullptr)
	{
		std::cerr << "Failed to load " << path << " font! SDL_ttf Error:" << TTF_GetError();
		return;
	}
}


void Texture::Free()
{
	SDL_DestroyTexture(m_texture);
	m_texture = nullptr;

	TTF_CloseFont(m_font);
	m_font = nullptr;

	m_iWidth = m_iHeight = 0;
}
