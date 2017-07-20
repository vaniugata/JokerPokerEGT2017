#include "OutroScreen.h"
#include "Globals.h"
#include <iostream>
using std::cout;
#include <sstream>
using std::stringstream;

double OutroScreen::m_dCredit = -1;

OutroScreen::OutroScreen(SDL_Renderer* renderer, SDL_Event* ptrEvent, 
	eGameState* gameState) :
	Screen(renderer),
	m_ptrEvent(ptrEvent),
	m_ptrGameState(gameState),
	m_tBackground(renderer)
{
	m_tBackground.LoadFromFile(renderer, "Resources/intro.png");
	m_tCredit.InitFont("Resources/font.ttf", 22);
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

	std::stringstream ss;
	ss << "Congratulations you have won: " << m_dCredit * DENOM << " BGN";
	m_tCredit.LoadFromRendererdText(m_renderer, ss.str().c_str(), SDL_Color{255, 255, 200});
	m_tCredit.Render(m_renderer, (SCREEN_WIDTH - m_tCredit.GetWidth() ) / 2, 50,
		m_tCredit.GetWidth(), m_tCredit.GetHeight() );
	ss.str();
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

void OutroScreen::Delay()
{
	int oldTime = SDL_GetTicks();
	while(true)
	{
		if(oldTime == SDL_GetTicks() - 5000)
		{
			*m_ptrGameState = INTRO;
			break;
		}
	}	
}

void OutroScreen::SetCredit(double credit)
{
	m_dCredit = credit;
}
