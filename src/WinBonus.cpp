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
<<<<<<< HEAD
{
=======
{	
	//render Backgorund
	m_tBackgorund.Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	//Play greeting sound
	Mix_PlayChannel(-1, winning, 0);
>>>>>>> origin/master
	//render the text
	SDL_Color color { 0, 0, 0 };
	int x = 300;
	int y = SCREEN_HEIGHT - 80;
	m_tText.LoadFromRendererdText(m_renderer,"New Credit is :" + DoubleToString(*m_ptrCredit), color);
	Uint32 timerDelay = SDL_GetTicks();
<<<<<<< HEAD
	while (SDL_GetTicks() - timerDelay < 3000 && *m_ptrGameState != QUIT)
	{
=======
	while (SDL_GetTicks() - timerDelay < 4000 && *m_ptrGameState != QUIT)
	{
		std::cout<<"eeeeeeeeeeee"<<std::endl;
>>>>>>> origin/master
		//render Backgorund
		Mix_PlayChannel(-1, winning, 0);
		m_tBackgorund.Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
<<<<<<< HEAD
		m_tText.Render(m_renderer, x, y, m_tText.GetWidth(), m_tText.GetHeight());
		SDL_RenderPresent(m_renderer);
=======
		m_tText.LoadFromRendererdText(m_renderer,"New Credit is :" + DoubleToString(*m_ptrCredit), color);

		int x = 300;
		int y = SCREEN_HEIGHT - 80;
		m_tText.Render(m_renderer, x, y, m_tText.GetWidth(), m_tText.GetHeight());
		Draw();
>>>>>>> origin/master
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
