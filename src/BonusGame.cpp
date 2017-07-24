/*
 * BonusGame.cpp
 *
 *  Created on: 10.07.2017 г.
 *      Author: Rossi
 */
#include "BonusGame.h"
#include <iostream>
#include <string>
#include <time.h>
#include "Globals.h"
#include "Recovery.h"
#include "ButtonObject.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::rand;
using std::srand;
using std::time;
using std::cerr;

int BonusGame::m_win = 0;

BonusGame::BonusGame(SDL_Renderer* renderer, SDL_Event& event,
	eGameState& eGameState, double* credit) :
	m_ptrCredit(credit), Screen(renderer), m_tBackgorund(), m_event(&event), m_ptrGameState(
		&eGameState), m_buttonX2(renderer,
			"Resources/buttons-BonusGame.png", 0, 0, BONUSBTN_W,
			BONUSBTN_H), m_buttonX5(renderer,
				"Resources/buttons-BonusGame.png", 0, 0, BONUSBTN_W,
				BONUSBTN_H), m_buttonX10(renderer,
					"Resources/buttons-BonusGame.png", 0, 0, BONUSBTN_W,
					BONUSBTN_H), m_btnMusicPlus(renderer,
						"Resources/IncreasesB.png", 0, 0, BUTTON_VOLUME_SIZE,
						BUTTON_VOLUME_SIZE), m_btnMusic(renderer, "Resources/PlayB.png",
							0, 0, BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE), m_btnMusicMinus(
								renderer, "Resources/DecreasesB.png", 0, 0, BUTTON_VOLUME_SIZE,
								BUTTON_VOLUME_SIZE), m_btnMusicPause(renderer,
									"Resources/Pause.png", 0, 0, BUTTON_VOLUME_SIZE,
									BUTTON_VOLUME_SIZE) {

	this->m_renderer = renderer;
	this->m_resDie1 = m_resDie1;
	this->m_resDie2 = m_resDie2;
	this->m_diceResult = m_diceResult;
	this->m_win = m_win;
	m_tBackgorund.LoadFromFile(renderer, "Resources/DoubleUpDice2.jpg");
	LoadMusicFiles();
	LoadDieFiles();
	LoadChoiceWinFiles();
	m_mMusic.LoadMusic();
	Mix_PlayMusic(m_mMusic.getBackgraund(), -1);

}

BonusGame::~BonusGame() {
	std::cerr << "BonusGame Object deleted.\n";
	Close();
}

void BonusGame::Draw() {
	Screen::Draw();
}

void BonusGame::Render() {
	//render background
	m_tBackgorund.Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	//render inscription Choice Win
	RenderChoiceWin();
	//Render buttons
	SDL_Rect rectOnScreen1{ 0, 0, BONUSBTN_W, BONUSBTN_H };
	m_buttonX2.Render(m_renderer, &rectOnScreen1, 50, 150, BONUSBTN_W,
		BONUSBTN_H);
	SDL_Rect rectOnScreen2{ BONUSBTN_W, 0, BONUSBTN_W, BONUSBTN_H };
	m_buttonX5.Render(m_renderer, &rectOnScreen2, 50, 320, BONUSBTN_W,
		BONUSBTN_H);
	SDL_Rect rectOnScreen3{ BONUSBTN_W * 2, 0, BONUSBTN_W, BONUSBTN_H };
	m_buttonX10.Render(m_renderer, &rectOnScreen3, 50, 490, BONUSBTN_W,
		BONUSBTN_H);

	SDL_Rect rectMusicPlus{ 0, 0, BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE };
	m_btnMusicPlus.Render(m_renderer, &rectMusicPlus, SCREEN_WIDTH - 45, 5,
		BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE);

	SDL_Rect rectMusic{ 0, 0, BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE };
	if(m_bShowPlayButton) {
		m_btnMusic.Render(m_renderer, &rectMusic, SCREEN_WIDTH - 99, 5,
			BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE);
	}
	else {
		m_btnMusicPause.Render(m_renderer, &rectMusic, SCREEN_WIDTH - 99, 5,
			BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE);
	}

	SDL_Rect rectMusicMinus{ 0, 0, BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE };
	m_btnMusicMinus.Render(m_renderer, &rectMusicMinus, SCREEN_WIDTH - 153, 5,
		BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE);
}

void BonusGame::HandleEvent()
{
	switch(m_event->type)
	{
	case SDL_QUIT:
	case SDL_MOUSEBUTTONDOWN:
	{
		//process event with the music buttons
		MusicController();

		if(m_buttonX2.IsSelected())
		{
			Mix_PlayChannel(-1, ButtonPress, 0);
			Mix_PlayChannel(-1, RollDice, 0);
			delay(3000);
			m_diceResult = getResDie1() + getResDie2();
			SDL_Delay(2000);
			if(m_diceResult < 5)
			{
				*m_ptrCredit += m_win * 2;
				Recovery::Save(*m_ptrCredit, 0, m_win);
				m_win = 0;
				*m_ptrGameState = WIN;
			}
			else
			{
				*m_ptrGameState = PLAY;
			}
		}
		else if(m_buttonX5.IsSelected())
		{
			Mix_PlayChannel(-1, ButtonPress, 0);
			Mix_PlayChannel(-1, RollDice, 0);
			delay(3000);
			m_diceResult = getResDie1() + getResDie2();
			SDL_Delay(2000);
			if(m_diceResult > 4 && m_diceResult < 10)
			{
				*m_ptrCredit += m_win * 5;
				Recovery::Save(*m_ptrCredit, 0, m_win);
				m_win = 0;
				*m_ptrGameState = WIN;
			}
			else
			{
				*m_ptrGameState = PLAY;
			}
		}
		else if(m_buttonX10.IsSelected())
		{
			Mix_PlayChannel(-1, ButtonPress, 0);
			Mix_PlayChannel(-1, RollDice, 0);
			delay(3000);
			m_diceResult = getResDie1() + getResDie2();
			SDL_Delay(2000);
			if(m_diceResult > 9 && m_diceResult < 13)
			{
				*m_ptrCredit += m_win * 10;
				Recovery::Save(*m_ptrCredit, 0, m_win);
				m_win = 0;
				*m_ptrGameState = WIN;
			}
			else
			{
				*m_ptrGameState = PLAY;
			}
		}
		break;
	}// MUISEBUTTONDOWN
	} //switch event type
}//handle event

void BonusGame::LoadMusicFiles() {
	ButtonPress = Mix_LoadWAV("ResourcesMusic/ButtonPress.wav");
	if(ButtonPress == nullptr) {
		std::cout << "Failed to load scratch ButtonPress! SDL_mixer Error:"
			<< Mix_GetError() << std::endl;
		return;
	}

	RollDice = Mix_LoadWAV("ResourcesMusic/RollDice.wav");
	if(RollDice == nullptr) {
		std::cout << "Failed to load scratch RollDice! SDL_mixer Error:"
			<< Mix_GetError() << std::endl;
		return;
	}
}

void BonusGame::LoadDieFiles() {
	m_spriteDieTexture.LoadFromFile(m_renderer, "Resources/Die.png");
	//Load sprite sheet texture
	for(int i = 0; i < 6; i++) {
		m_spriteDie[i].x = i * 155;
		m_spriteDie[i].y = 0;
		m_spriteDie[i].w = 155;
		m_spriteDie[i].h = 148;
	}
}

int BonusGame::RandomNumberGenerator() {
	int dieResult = (rand() % 6) + 1;
	return dieResult;
}

void BonusGame::RenderDice() {
	setResDie1(RandomNumberGenerator());
	setResDie2(RandomNumberGenerator());
	m_spriteDieTexture.Render(m_renderer, 480, 450, 155, 148,
		&m_spriteDie[getResDie1() - 1]);
	m_spriteDieTexture.Render(m_renderer, 680, 400, 155, 148,
		&m_spriteDie[getResDie2() - 1]);
}

void BonusGame::LoadChoiceWinFiles() {
	m_tChoiceWin.LoadFromFile(m_renderer, "Resources/ChoiseWin.png");
	//Load sprite sheet texture
	int w = 297;
	int h = 40;
	for(int i = 0; i < 3; i++) {
		m_ChoiceWin[i].x = 0;
		m_ChoiceWin[i].y = i * h;
		m_ChoiceWin[i].w = w;
		m_ChoiceWin[i].h = h;
	}
}

void BonusGame::RenderChoiceWin() {
	for(int i = 0; i < (rand() % 3) + 1; i++) {
		m_tChoiceWin.Render(m_renderer, 50, 70, 297, 40, &m_ChoiceWin[i]);
	}
}

//Delay
void BonusGame::delay(Uint32 ms) {
	Uint32 timerDelay = SDL_GetTicks();
	while(SDL_GetTicks() - timerDelay < ms && *m_ptrGameState != QUIT) {
		RenderDice();
		SDL_RenderPresent(m_renderer);
	}
}
void BonusGame::setWin(int winIndex) {
	m_win = winIndex;
}

void BonusGame::MusicController()
{
	if(m_btnMusic.IsSelected() && m_bShowPlayButton == true)
	{
		m_bShowPlayButton = false;

		Mix_PauseMusic();
	}
	else if(m_btnMusicPause.IsSelected() && m_bShowPlayButton == false)
	{
		m_bShowPlayButton = true;
		Mix_PlayMusic(m_mMusic.getBackgraund(), -1);
	}
	else if(m_btnMusicPlus.IsSelected())
	{
		m_iCounterVolumeMusic += 10;
		if(m_iCounterVolumeMusic > 100)
			m_iCounterVolumeMusic = 100;
		Mix_VolumeMusic(m_iCounterVolumeMusic);
		cout << m_iCounterVolumeMusic << endl;
	}
	else if(m_btnMusicMinus.IsSelected())
	{
		m_iCounterVolumeMusic -= 10;
		if(m_iCounterVolumeMusic < 10)
			m_iCounterVolumeMusic = 10;
		Mix_VolumeMusic(m_iCounterVolumeMusic);
	}
}

void BonusGame::Close() {
	//Free the sound effects
	Mix_FreeChunk(RollDice);
	Mix_FreeChunk(ButtonPress);
}

int BonusGame::getResDie1() const {
	return m_resDie1;
}

void BonusGame::setResDie1(int resDie1) {
	m_resDie1 = resDie1;
}

int BonusGame::getResDie2() const {
	return m_resDie2;
}

void BonusGame::setResDie2(int resDie2) {
	m_resDie2 = resDie2;
}
