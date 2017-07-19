#include "OutroScreen.h"
#include "Globals.h"
#include <iostream>

OutroScreen::OutroScreen(SDL_Renderer* renderer, SDL_Event* ptrEvent, 
	eGameState* gameState) :
	Screen(renderer),
	m_ptrEvent(ptrEvent),
	m_ptrGameState(gameState),
	m_tBackground(renderer)
{
	m_tBackground.LoadFromFile(renderer, "Resources/intro.png");
}

OutroScreen::~OutroScreen()
{  
	m_ptrEvent = nullptr;
	m_ptrGameState = nullptr;
	std::cout << "Deleted OutroScreen.\n";
}

void OutroScreen::Draw()
{
	Screen::Draw();
}

void OutroScreen::Render()
{
	m_tBackground.Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void OutroScreen::HandleEvent()
{
	switch(m_ptrEvent->type)
	{
	case SDL_QUIT:
		*m_ptrGameState = QUIT;
		break;
	}
}
