#ifndef TEXTURE_H
#define TEXTURE_H

#include "includesSDL2.h"
#include <string>


class Texture
{
private:
	SDL_Texture* m_texture;
	TTF_Font* m_font;

	int m_iWidth;
	int m_iHeight;

//MEMBER FUNCTIONS
public:
	Texture(SDL_Renderer* renderer = nullptr, std::string path = "");
	~Texture();

//GETTERS
	int GetWidth() const;
	int GetHeight() const;

//SETTERS
	void SetBlendMode(SDL_BlendMode bm);
	void SetAlpha(Uint8 a);

	void LoadFromFile(SDL_Renderer* renderer, std::string path);

	void LoadFromRendererdText(SDL_Renderer * renderer, \
		std::string fontPath, std::string text, SDL_Color color, int fontSize);

	void Render(SDL_Renderer* renderer, int x, int y, int w, int h, SDL_Rect* clip = NULL);

	void InitFont(std::string path, int fontSize);


private:
	void Free();
};
#endif
