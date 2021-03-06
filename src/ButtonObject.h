#ifndef BUTTON_OBJECT_H
#define BUTTON_OBJECT_H

#include "Texture.h"
#include "Globals.h"
class ButtonObject
{
public:
	Texture m_texture;
private:
	SDL_Point m_pTopLeft;
	int m_iWidth;
	int m_iHeight;

//	Music m_mMusic;
public:
	ButtonObject(SDL_Renderer* renderer = NULL, std::string path = "", 
		int x = 0, int y = 0, int w = 100, int h = 100);
	virtual~ButtonObject();

	//getters
	//On screen dimentions
	int GetWidth() const;
	int GetHeight() const;

	//setters
	void SetPosition(int x, int y);
	void SetDimentions(int w, int h);

	void Render(SDL_Renderer* renderer, SDL_Rect* clip, 
		int x = 0, int y = 0, int w = 100, int h = 100);

	bool IsSelected();



};
#endif
