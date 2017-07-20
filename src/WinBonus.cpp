/*
 * WinBonus.cpp
 *
 *  Created on: 14.07.2017 г.
 *      Author: Rossi
 */

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
	LoadMusicFiles();
}

WinBonus::~WinBonus()
{
	std::cerr << "BonusGame Object deleted.\n";
	Close();
}

void WinBonus::Draw()
{
	Screen::Draw();
}

void WinBonus::Render()
{
	// Text credit
	SDL_Color color { 0, 0, 0 };
	int x = 300;
	int y = SCREEN_HEIGHT - 80;
	m_tText.LoadFromRendererdText(m_renderer,"New Credit is :" + DoubleToString(*m_ptrCredit), color);
	// PlayChannel winning
	Mix_PlayChannel(-1, winning, 0);
	Uint32 timerDelay = SDL_GetTicks();
	while (SDL_GetTicks() - timerDelay < 2500 && *m_ptrGameState != QUIT)
	{
		//render Backgorund
		m_tBackgorund.Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		//render the text credit
		m_tText.Render(m_renderer, x, y, m_tText.GetWidth(), m_tText.GetHeight());
		Draw();

	}
	*m_ptrGameState = PLAY;
}

void WinBonus::LoadMusicFiles()
{
	winning = Mix_LoadWAV("ResourcesMusic/Winning.wav");
	if (winning == nullptr) {
		std::cout << "Failed to load scratch Winning! SDL_mixer Error:"
				<< Mix_GetError() << std::endl;
		return;
	}
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

//Free the sound effects
void WinBonus::Close()
{
	Mix_FreeChunk(winning);

}
