#include "Screen.h"
#include <iostream>
using std::cout;

Screen::Screen(SDL_Renderer* renderer) :
	m_renderer(renderer)
{

}

Screen::~Screen()
{
	std::cout << "Scene deleted.\n";
}

void Screen::Draw()
{
	SDL_RenderPresent(m_renderer);
	SDL_RenderClear(m_renderer);
}
