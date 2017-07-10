#include "GameState.h"
#include <iostream>
using std::cout;

GameState::GameState(SDL_Renderer* renderer) :
	m_renderer(renderer)
{

}

GameState::~GameState()
{
	std::cout << "GameState deleted.\n";
}

void GameState::Draw()
{
	SDL_RenderPresent(m_renderer);
	SDL_RenderClear(m_renderer);
}
