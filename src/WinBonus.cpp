/*
 * WinBonus.cpp
 *
 *  Created on: 14.07.2017 г.
 *      Author: Rossi
 */

#include "WinBonus.h"
#include <iostream>
using std::cerr;


WinBonus::WinBonus(SDL_Renderer* renderer,SDL_Event& event ,eGameState& eGameState) :
		Scene(renderer),  m_tBackgorund(), m_event(&event), m_ptrGameState(&eGameState)
{
	this->m_renderer = renderer;
	m_tBackgorund.LoadFromFile(renderer, "Resources/win.png");
	m_tText.InitFont("Resources/font.ttf", 18);
	LoadMusicFiles();
}

WinBonus::~WinBonus()
{
	std::cerr << "BonusGame Object deleted.\n";
		Close();
}

void WinBonus::Draw()
{
	Scene::Draw();
}

void WinBonus::Render()
{
		m_tBackgorund.Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		//render the text
		SDL_Color color { 255, 255, 255 };
		std::cout<<"I am Render WinBonus2"<<std::endl;
		m_tText.LoadFromRendererdText(m_renderer,"11111111111", color);
		std::cout<<"I am Render WinBonus3"<<std::endl;
		int x = SCREEN_WIDTH / 3;
		int y = SCREEN_HEIGHT - 100;
		m_tText.Render(m_renderer, x, y, m_tText.GetWidth(), m_tText.GetHeight());
		Mix_PlayChannel(-1, winning, 0);
		SDL_Delay(2000);
		*m_ptrGameState = PLAY;

}

void WinBonus::LoadMusicFiles() {

	winning = Mix_LoadWAV("ResourcesMusic/Winning.wav");
	if (winning == nullptr) {
		std::cout << "Failed to load scratch Winning! SDL_mixer Error:"
				<< Mix_GetError() << std::endl;
		return;
	}

}

void WinBonus::HandleEvent()
{
	switch (m_event->type) {
		case SDL_QUIT:
			*m_ptrGameState = QUIT;
			break;
	}
}
std::string WinBonus::DoubleToString(double x) const {
		std::stringstream ss;
		ss << x;
		std::string res = ss.str();
		return res;
	}

void WinBonus::Close() {	//Free the sound effects

	Mix_FreeChunk(winning);

}
