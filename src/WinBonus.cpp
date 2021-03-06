#include "WinBonus.h"
#include <iostream>
using std::cerr;

WinBonus::WinBonus(SDL_Renderer* renderer, SDL_Event& event,
		eGameState& eGameState, double* credit) :
		Screen(renderer), m_tBackgorund(), m_event(&event),
		m_ptrGameState(&eGameState), m_ptrCredit(credit)
{
	this->m_renderer = renderer;
	m_tBackgorund.LoadFromFile(renderer, "Resources/win.png");
	m_tText.InitFont("Resources/font.ttf", 50);
}

WinBonus::~WinBonus()
{
	std::cerr << "BonusGame Object deleted.\n";
}

void WinBonus::Draw()
{
	Screen::Draw();
}

void WinBonus::Render()
{	
	//Play greeting sound
	Mix_PlayChannel(-1, Music::getWinning(), 0);
	SDL_Color color { 0, 0, 0 };
		int x = 300;
		int y = SCREEN_HEIGHT - 80;

	m_tText.LoadFromRendererdText(m_renderer, "Resources/font.ttf",
		"New Credit is :" + DoubleToString(*m_ptrCredit), color, 50);

	Uint32 timerDelay = SDL_GetTicks();
	while (SDL_GetTicks() - timerDelay < 3000 && *m_ptrGameState != QUIT)
	{
		//render Backgorund
		m_tBackgorund.Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

		//render Text
		m_tText.Render(m_renderer, x, y, m_tText.GetWidth(), m_tText.GetHeight());
		SDL_RenderPresent(m_renderer);
	}

	*m_ptrGameState = PLAY;
}

void WinBonus::HandleEvent()
{
	switch (m_event->type)
	{
	case SDL_QUIT:
		*m_ptrGameState = QUIT;
		break;
	}
}

std::string WinBonus::DoubleToString(double x) const
{
	std::stringstream ss;
	ss << x;
	std::string res = ss.str();
	return res;
}

