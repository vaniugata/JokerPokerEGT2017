#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <string>

class Texture
{
private:
	SDL_Texture* m_texture;

public:
	SDL_Rect m_rectSource;
	SDL_Rect m_rectDestination;

//MEMBER FUNCTIONS
	Texture();
	~Texture();

	void LoadFromFile(SDL_Renderer* renderer, std::string path);

//SETTERS
	void SetDestRect(int x, int y, int w, int h);

	void Render(SDL_Renderer& renderer, SDL_Rect& source, SDL_Rect& destination);

private:
	void Free();
};
#endif;