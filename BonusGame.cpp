/*
 * BonusGame.cpp
 *
 *  Created on: 10.07.2017 г.
 *      Author: Rossi
 */
#include "BonusGame.h"
#include <iostream>
using std::cerr;
#include <sstream>
using std::stringstream;
#include <stdlib.h>
#include <string>
#include <time.h>
#include "Globals.h"
#include <iostream>
using std::cout;

//--------------R----------

bool winsABonus = false;
//------------------------

BonusGame::BonusGame(SDL_Renderer* renderer, SDL_Event& event,
		eGameState& eGameState) :
		 GameState(renderer), m_tBackgorund(), m_event(&event), m_ptrGameState(
				&eGameState),m_dCredit(-1), m_btnX2(renderer, "Resources/DoubleUpDice.png", 0,
				0, S_BONUSBTN_W, S_BONUSBTN_H), m_btnX5(renderer,
				"Resources/DoubleUpDice.png", 0, 0, S_BONUSBTN_W, S_BONUSBTN_H), m_btnX10(
				renderer, "Resources/DoubleUpDice.png", 0, 0, S_BONUSBTN_W,
				S_BONUSBTN_H)

{
	this->m_renderer = renderer;
	m_tBackgorund.LoadFromFile(renderer, "Resources/DoubleUpDice2.jpg");
	m_btnX2.SetPosition(50, 120);
	m_btnX5.SetPosition(50, 270);
	m_btnX10.SetPosition(50, 420);
	LoadMusicFiles();
	LoadDieFiles();
	LoadChoiceWinFiles();

}

BonusGame::~BonusGame() {
	std::cerr << "BonusGame Object deleted.\n";
	Close();
}

double* BonusGame::GetCredit() {
	return &m_dCredit;
}

void BonusGame::Draw() {
	GameState::Draw();
}

void BonusGame::Render() {
	m_tBackgorund.Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	SDL_Rect clip1 { 0, 100, S_BONUSBTN_W, S_BONUSBTN_H };
	m_btnX2.Render(m_renderer, &clip1, 30, 100, S_BONUSBTN_W, S_BONUSBTN_H);
	SDL_Rect clip2 { 0, 250, S_BONUSBTN_W, S_BONUSBTN_H };
	m_btnX5.Render(m_renderer, &clip2, 30, 250, S_BONUSBTN_W, S_BONUSBTN_H);
	SDL_Rect clip3 { 0, 400, S_BONUSBTN_W, S_BONUSBTN_H };
	m_btnX10.Render(m_renderer, &clip3, 30, 400, S_BONUSBTN_W, S_BONUSBTN_H);
	RenderChoiceWin();
	m_spriteDieTexture.Render(m_renderer, 400, 200, 200, 191, &m_spriteDie[0]);
	m_spriteDieTexture.Render(m_renderer, 600, 200, 200, 191, &m_spriteDie[5]);

}

void BonusGame::HandleEvent() {
	switch (m_event->type) {
	case SDL_QUIT:
		*m_ptrGameState = QUIT;
		break;

	case SDL_MOUSEBUTTONDOWN: {
		if (m_btnX2.IsPressed()) {
			std::cout << "m_btnX2.IsPressed()" << std::endl;
			Mix_PlayChannel(-1, ButtonPress, 0);
			Mix_PlayChannel(-1, RollDice, 0);
			int ResultDice = BonusGame::ResultDice();
			if (ResultDice < 5) {
				m_dCredit = calculateWin(m_dCredit, 2);
				SDL_Delay(1000);
				*m_ptrGameState = WIN;
				winsABonus = true;
			}
		} else if (m_btnX5.IsPressed()) {
			std::cout << "m_btnX5.IsPressed()" << std::endl;
			Mix_PlayChannel(-1, ButtonPress, 0);
			Mix_PlayChannel(-1, RollDice, 0);
			int ResultDice = BonusGame::ResultDice();
			if (ResultDice > 4 && ResultDice < 10) {
				m_dCredit = calculateWin(m_dCredit, 5);
				SDL_Delay(1000);
				*m_ptrGameState = WIN;
				winsABonus = true;
			}
		} else if (m_btnX10.IsPressed()) {
			std::cout << "m_btnX10.IsPressed()" << std::endl;
			Mix_PlayChannel(-1, ButtonPress, 0);
			Mix_PlayChannel(-1, RollDice, 0);
			int ResultDice = BonusGame::ResultDice();
			if (ResultDice > 9 && ResultDice < 13) {
				m_dCredit = calculateWin(m_dCredit, 10);
				SDL_Delay(1000);
				*m_ptrGameState = WIN;
				winsABonus = true;
			}
		}
		break;
	}
	}

}
int BonusGame::ResultDice() {
	int rollADie1, rollADie2, totalDice;
	srand(time(NULL));
	rollADie1 = rand() % 6 + 1;
	rollADie2 = rand() % 6 + 1;
	totalDice = rollADie1 + rollADie2;
	std::cout << "totalDice = rollADie1 + rollADie2 = " << totalDice
			<< std::endl;
	return totalDice;

}
double BonusGame::calculateWin(double credits, int totalDice) {
	double res = 0;
	res = credits * (double) totalDice;
	return res;
}

void BonusGame::LoadMusicFiles() {
	//Load music
	//gMusic = Mix_LoadMUS( "beat.wav" );

	//Load sound effects

	ButtonPress = Mix_LoadWAV("ResourcesMusic/ButtonPress.wav");
	if (ButtonPress == nullptr) {
		std::cout << "Failed to load scratch ButtonPress! SDL_mixer Error:"
				<< Mix_GetError() << std::endl;
		return;
	}

	RollDice = Mix_LoadWAV("ResourcesMusic/RollDice.wav");
	if (RollDice == nullptr) {
		std::cout << "Failed to load scratch RollDice! SDL_mixer Error:"
				<< Mix_GetError() << std::endl;
		return;
	}

}

void BonusGame::LoadDieFiles() {
	m_spriteDieTexture.LoadFromFile(m_renderer, "Resources/Die.png");
	//Load sprite sheet texture
	int offsetX = 200;
	int offsetY = 0;
	int coef[6] = { 0, 1, 2, 0, 1, 2 };
	for (int i = 0; i < 6; i++) {
		if (i == 3) {
			offsetY = 191;
		}
		m_spriteDie[i].x = coef[i] * offsetX;
		m_spriteDie[i].y = offsetY;
		m_spriteDie[i].w = 200;
		m_spriteDie[i].h = 191;
	}
}
void BonusGame::RenderDice() {
	for (int i = 0; i < 6; i++) {
		m_spriteDieTexture.Render(m_renderer, 400, 200, 200, 191,
				&m_spriteDie[i * rand() % 6 + 1]);
		m_spriteDieTexture.Render(m_renderer, 600, 200, 200, 191,
				&m_spriteDie[i * rand() % 6 + 1]);
	}
}

void BonusGame::LoadChoiceWinFiles() {
	m_tChoiceWin.LoadFromFile(m_renderer, "Resources/DoubleUpDice.png");
	//Load sprite sheet texture
	int position = 0;
	int w = 540;
	int h = 80;
	for (int i = 0; i < 3; i++) {
		if (i == 1) {
			position = 5;
		}
		m_ChoiceWin[i].x = position;
		m_ChoiceWin[i].y = position;
		m_ChoiceWin[i].w = w;
		m_ChoiceWin[i].h = h;
		position = 0;
	}
}

void BonusGame::RenderChoiceWin() {
	int w = 540;
	int h = 80;
	SDL_Rect rect[3] { 0, 0, w, h };
	for (int i = 0; i < 3; i++) {
		m_tChoiceWin.Render(m_renderer, 0, 0, w, h, &rect[i]);
	}
}

void BonusGame::Close() {	//Free the sound effects
	Mix_FreeChunk(RollDice);
	Mix_FreeChunk(ButtonPress);

}
