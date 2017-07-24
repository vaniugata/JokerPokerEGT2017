#include "ButtonObject.h"
#include <iostream>
using std::cout;

ButtonObject::ButtonObject(SDL_Renderer* renderer, std::string path,
	int x, int y, int w, int h) :
	 m_iWidth(w), m_iHeight(h)
{
	m_pTopLeft.x = x;
	m_pTopLeft.y = y;
}

ButtonObject::~ButtonObject()
{
	std::cout << "Button deleted.\n";
}

int ButtonObject::GetWidth() const
{
	return m_iWidth;
}

int ButtonObject::GetHeight() const
{
	return m_iHeight;
}

void ButtonObject::SetPosition(int x, int y)
{
	m_pTopLeft.x = x;
	m_pTopLeft.y = y;
}

void ButtonObject::SetDimentions(int w, int h)
{
	this->m_iWidth = w;
	this->m_iHeight = h;
}

void ButtonObject::Render(SDL_Renderer* renderer, SDL_Rect* clip, \
 int x, int y, int w, int h)
{
	SDL_Rect in {clip->x, clip->y + clip->h, clip->w, clip->h };

	m_pTopLeft.x = x;
	m_pTopLeft.y = y;

	m_texture.Render(renderer, m_pTopLeft.x, m_pTopLeft.y,
		w, h, clip);
	if(IsSelected())
	{
		m_texture.Render(renderer, m_pTopLeft.x, m_pTopLeft.y,
			w, h, &in);
	}
}

bool ButtonObject::IsSelected()
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	if( (x > m_pTopLeft.x && x < m_pTopLeft.x + m_iWidth ) && 
		(y > m_pTopLeft.y && y < m_pTopLeft.y + m_iHeight ) )
	{
		//Mix_PlayChannel(-1,m_mMusic.getButton(),0);
		return true;
	}

	return false;
}

