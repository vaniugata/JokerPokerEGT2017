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
		GameState(renderer),  m_tBackgorund(), m_event(&event), m_ptrGameState(&eGameState)
{
	this->m_renderer = renderer;
	m_tBackgorund.LoadFromFile(renderer, "Resources/win.png");
	InitFont("Resources/font.ttf");
}

WinBonus::~WinBonus()
{
	std::cerr << "BonusGame Object deleted.\n";
		Close();
}

void WinBonus::Draw()
{
	GameState::Draw();
}

void WinBonus::Render()
{
		m_tBackgorund.Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		//render the text
		SDL_Color color { 255, 255, 255 };
		int x = SCREEN_WIDTH / 3;
		int y = SCREEN_HEIGHT - 100;
		std::string credits = "123456";
		//m_tText.LoadFromRendererdText(m_renderer, m_font, credits, color);
		m_tText.Render(m_renderer, x, y, m_tText.GetWidth(), m_tText.GetHeight());


}

void WinBonus::InitFont(std::string path) {
	m_font = TTF_OpenFont(path.c_str(), 50);
	if (m_font == nullptr) {
		std::cerr << "Failed to load " << path << " font! SDL_ttf Error:"
				<< TTF_GetError();
		return;
	}
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

}

void WinBonus::Close() {	//Free the sound effects

	Mix_FreeChunk(winning);

}
