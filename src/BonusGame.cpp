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
double credits = 123456;
bool winsABonus = false;
//------------------------

BonusGame::BonusGame(SDL_Renderer* renderer, SDL_Event& event,
		eGameState& eGameState) :
		GameState(renderer), m_tBackgorund(), m_event(&event), m_ptrGameState(
				&eGameState), m_ChoiceWin(renderer,
				"Resources/DoubleUpDice.png", 0, 0, 530, 75), m_btnX2(renderer,
				"Resources/DoubleUpDice.png", 0, 0, S_BONUSBTN_W, S_BONUSBTN_H), m_btnX5(
				renderer, "Resources/DoubleUpDice.png", 0, 0, S_BONUSBTN_W,
				S_BONUSBTN_H), m_btnX10(renderer, "Resources/DoubleUpDice.png",
				0, 0, S_BONUSBTN_W, S_BONUSBTN_H) {
	this->m_renderer = renderer;
	m_tBackgorund.LoadFromFile(renderer, "Resources/DoubleUpDice2.jpg");

	m_ChoiceWin.SetPosition(0, 0);
	m_btnX2.SetPosition(50, 120);
	m_btnX5.SetPosition(50, 270);
	m_btnX10.SetPosition(50, 420);
	LoadMusicFiles();
}

BonusGame::~BonusGame() {
	std::cerr << "BonusGame Object deleted.\n";
	Close();
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
	//SDL_Rect clip[2];
	SDL_Rect clip4 { 0, 0, 540, 80 };
	//SDL_Rect clip5 {0, 0, 545 ,85};
	//clip[0]=clip4;
	//clip[1]=clip5;
	m_ChoiceWin.Render(m_renderer, &clip4, 0, 0, 540, 80);
	//SDL_Delay(1000);
	//m_bonus->GetChoiceWin().Render(m_renderer, &clip5, 0, 0, 555, 95);

}

void BonusGame::HandleEvent() {
	switch (m_event->type) {
	case SDL_QUIT:
		*m_ptrGameState = QUIT;
		break;

	case SDL_MOUSEBUTTONDOWN: {
		if (m_btnX2.IsSelected()) {
			std::cout << "m_btnX2.IsPressed()" << std::endl;
			Mix_PlayChannel(-1, ButtonPress, 0);
			SDL_Delay(1000);
			Mix_PlayChannel(-1, RollDice, 0);
			int ResultDice = BonusGame::ResultDice();
			if (ResultDice < 5) {
				credits = calculateWin(credits, 2);
				 *m_ptrGameState = WIN;
				winsABonus = true;
			}
		} else if (m_btnX5.IsSelected()) {
			std::cout << "m_btnX5.IsPressed()" << std::endl;
			Mix_PlayChannel(-1, ButtonPress, 0);
			SDL_Delay(1000);
			Mix_PlayChannel(-1, RollDice, 0);
			int ResultDice = BonusGame::ResultDice();
			if (ResultDice > 4 && ResultDice < 10) {
				credits = calculateWin(credits, 5);
				SDL_Delay(1500);
				 *m_ptrGameState = WIN;
				winsABonus = true;
			}
		} else if (m_btnX10.IsSelected()) {
			std::cout << "m_btnX10.IsPressed()" << std::endl;
			Mix_PlayChannel(-1, ButtonPress, 0);
			SDL_Delay(1000);
			Mix_PlayChannel(-1, RollDice, 0);

			int ResultDice = BonusGame::ResultDice();
			if (ResultDice > 9 && ResultDice < 13) {
				credits = calculateWin(credits, 10);
				SDL_Delay(1500);
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

void BonusGame::Close() {	//Free the sound effects
	Mix_FreeChunk(RollDice);
	Mix_FreeChunk(ButtonPress);


}
