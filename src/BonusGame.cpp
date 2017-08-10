/*
 * BonusGame.cpp
 *
 *  Created on: 10.07.2017 г.
 *      Author: Rossi
 */
#include "BonusGame.h"
#include "Game.h"
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
	m_ptrCredit(credit), Screen(renderer), m_tBackgorund(), m_event(&event),
	m_ptrGameState(&eGameState), m_buttonX2(), m_buttonX5(), m_buttonX10(),
	m_btnMusicPlus(), m_btnMusic(), m_btnMusicMinus(), m_btnMusicPause() 
{
	//------BUTTONS--------------------------
	m_buttonX2.m_texture.LoadFromFile(renderer, "Resources/buttons-BonusGame.png");
	m_buttonX2.SetDimentions(BONUSBTN_W, BONUSBTN_H);

	m_buttonX5.m_texture.LoadFromFile(renderer,	"Resources/buttons-BonusGame.png");
	m_buttonX5.SetDimentions(BONUSBTN_W, BONUSBTN_H);

	m_buttonX10.m_texture.LoadFromFile(renderer, "Resources/buttons-BonusGame.png");
	m_buttonX10.SetDimentions(BONUSBTN_W, BONUSBTN_H);

	m_btnMusicPlus.m_texture.LoadFromFile(renderer, "Resources/IncreasesB.png");
	m_btnMusicPlus.SetDimentions(BUTTON_VOLUME_SIZE , BUTTON_VOLUME_SIZE);

	m_btnMusic.m_texture.LoadFromFile(renderer, "Resources/PlayB.png");
	m_btnMusic.SetDimentions(BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE);

	m_btnMusicMinus.m_texture.LoadFromFile(renderer, "Resources/DecreasesB.png");
	m_btnMusicMinus.SetDimentions(BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE);

	m_btnMusicPause.m_texture.LoadFromFile(renderer, "Resources/Pause.png");
	m_btnMusicPause.SetDimentions(BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE);

	m_tBackgorund.LoadFromFile(renderer, "Resources/DoubleUpDice2.jpg");
	setResDie1(m_resDie1);
	setResDie2(m_resDie2);
	setDiceResult(m_diceResult);
	this->m_renderer = renderer;
	this->m_resDie1 = m_resDie1;
	this->m_resDie2 = m_resDie2;
	this->m_diceResult = m_diceResult;
	this->m_win = m_win;
	LoadDieFiles();
	LoadChooseWinFiles();
}

BonusGame::~BonusGame() 
{
	std::cerr << "BonusGame Object deleted.\n";

}

void BonusGame::Draw() 
{
	Screen::Draw();
}

void BonusGame::Render() 
{
	//render background
	m_tBackgorund.Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

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

	//Render Music
	SDL_Rect rectMusicPlus{ 0, 0, BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE };
	m_btnMusicPlus.Render(m_renderer, &rectMusicPlus, SCREEN_WIDTH - 45, 5,
		BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE);

	SDL_Rect rectMusic{ 0, 0, BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE };
	if(m_bShowPlayButton)
	{
		m_btnMusic.Render(m_renderer, &rectMusic, SCREEN_WIDTH - 99, 5,
			BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE);
	}
	else
	{
		m_btnMusicPause.Render(m_renderer, &rectMusic, SCREEN_WIDTH - 99, 5,
			BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE);
	}
	SDL_Rect rectMusicMinus{ 0, 0, BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE };
	m_btnMusicMinus.Render(m_renderer, &rectMusicMinus, SCREEN_WIDTH - 153, 5,
		BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE);

	//render inscription Choice Win
	RenderChooseWin();
}
void BonusGame::HandleEvent()
{
	switch (m_event->type)
	{
	case SDL_QUIT:
		*m_ptrGameState = QUIT;
		break;

	case SDL_MOUSEBUTTONDOWN:
	{
		//process event with the music buttons
		MusicController();
		if(m_buttonX2.IsSelected())
		{
			Mix_PlayChannel(-1, Music::getButtonBonus(), 0);
			Mix_PlayChannel(-1, Music::getRollDice(), 0);
			delay(3000);

			m_diceResult = m_resDie1 + m_resDie2;
			cout<<m_diceResult<<"?"<<std::endl;
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
			Mix_PlayChannel(-1, Music::getButtonBonus(), 0);
			Mix_PlayChannel(-1, Music::getRollDice(), 0);
			delay(3000);

			m_diceResult = m_resDie1 + m_resDie2;
			cout<<m_diceResult<<"?"<<std::endl;
			SDL_Delay(2000);
			if(m_diceResult> 4 && m_diceResult < 10)
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
		Mix_PlayChannel(-1, Music::getButtonBonus(), 0);
		Mix_PlayChannel(-1, Music::getRollDice(), 0);
			delay(3000);

			m_diceResult = m_resDie1 + m_resDie2;
			cout<<m_diceResult<<"?"<<std::endl;
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



void BonusGame::LoadDieFiles() 
{
	m_spriteDieTexture.LoadFromFile(m_renderer, "Resources/Die.png");
	//Load sprite sheet texture
	for(int i = 0; i < 6; i++) 
	{
		m_spriteDie[i].x = i * 155;
		m_spriteDie[i].y = 0;
		m_spriteDie[i].w = 155;
		m_spriteDie[i].h = 148;
	}
}

int BonusGame::RandomNumberGenerator() 
{
	int dieResult = (rand() % 6) + 1;
	return dieResult;
}

void BonusGame::RenderDice() 
{
	m_resDie1=RandomNumberGenerator();
	m_resDie2=RandomNumberGenerator();
	m_spriteDieTexture.Render(m_renderer, 480, 450, 155, 148,
		&m_spriteDie[m_resDie1 - 1]);
	m_spriteDieTexture.Render(m_renderer, 680, 400, 155, 148,
		&m_spriteDie[m_resDie2 - 1]);
}
void BonusGame::LoadChooseWinFiles()
{
	m_tChooseWin.LoadFromFile(m_renderer, "Resources/ChooseWin.png");
	//Load sprite sheet texture
	int w = 297;
	int h = 40;
	for(int i = 0; i < 3; i++) 
	{
		m_ChoiceWin[i].x = 0;
		m_ChoiceWin[i].y = i * h;
		m_ChoiceWin[i].w = w;
		m_ChoiceWin[i].h = h;
	}
}

void BonusGame::RenderChooseWin()
{
	//if(Game::SwitchFrame(1000) == true)
	{
		int result = rand() % 3;

		m_tChooseWin.Render(m_renderer, 50, 70, 297, 40, &m_ChoiceWin[result]);
		SDL_RenderPresent(m_renderer);
	}
}

//Delay
void BonusGame::delay(Uint32 ms) {
	Render();
	Uint32 timerDelay = SDL_GetTicks();
	while(SDL_GetTicks() - timerDelay < ms && *m_ptrGameState != QUIT) 
	{
		RenderDice();
		SDL_RenderPresent(m_renderer);
	}
}

void BonusGame::setWin(int winIndex) 
{
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
		Mix_PlayMusic(Music::getBackgraund(), -1);
	}
	else if(m_btnMusicPlus.IsSelected())
	{
		m_iCounterVolumeMusic += 10;
		if(m_iCounterVolumeMusic > 100)
			m_iCounterVolumeMusic = 100;
		Mix_VolumeMusic(m_iCounterVolumeMusic);
		std::cout << m_iCounterVolumeMusic << std::endl;
	}
	else if(m_btnMusicMinus.IsSelected())
	{
		m_iCounterVolumeMusic -= 10;
		if(m_iCounterVolumeMusic < 10)
			m_iCounterVolumeMusic = 10;
		Mix_VolumeMusic(m_iCounterVolumeMusic);
	}
}

int BonusGame::getResDie1() const 
{
	return m_resDie1;
}

void BonusGame::setResDie1(int res)
{
	m_resDie1 = res;
}

int BonusGame::getResDie2() const 
{
	return m_resDie2;
}

void BonusGame::setResDie2(int resD)
{
	m_resDie2 = resD;
}

int BonusGame::getDiceResult() const {
	return m_diceResult;
}

void BonusGame::setDiceResult(int diceRes) {
	m_diceResult = diceRes;
}
