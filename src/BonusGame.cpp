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

bool winsABonus = false;


BonusGame::BonusGame(SDL_Renderer* renderer, SDL_Event& event,
		eGameState& eGameState, double* credit) :
		m_ptrCredit(credit), GameState(renderer), m_tBackgorund(), m_event(
				&event), m_ptrGameState(&eGameState), m_buttonX2(renderer,
				"Resources/buttons-BonusGame.png", 0, 0, BONUSBTN_W,
				BONUSBTN_H), m_buttonX5(renderer,
				"Resources/buttons-BonusGame.png", 0, 0, BONUSBTN_W,
				BONUSBTN_H), m_buttonX10(renderer,
				"Resources/buttons-BonusGame.png", 0, 0, BONUSBTN_W, BONUSBTN_H) {
	this->m_renderer = renderer;
	m_tBackgorund.LoadFromFile(renderer, "Resources/DoubleUpDice2.jpg");

	LoadMusicFiles();
	LoadDieFiles();
	LoadChoiceWinFiles();

}

BonusGame::~BonusGame() {
	std::cerr << "BonusGame Object deleted.\n";
	Close();
}
void BonusGame::Draw() {
	GameState::Draw();
}

void BonusGame::Render() {
	//render background
	m_tBackgorund.Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	//Render buttons
	SDL_Rect rectOnScreen1 { 0, 0, BONUSBTN_W, BONUSBTN_H };
	m_buttonX2.Render(m_renderer, &rectOnScreen1, 50, 150, BONUSBTN_W,
			BONUSBTN_H);
	SDL_Rect rectOnScreen2 { BONUSBTN_W, 0, BONUSBTN_W, BONUSBTN_H };
	m_buttonX5.Render(m_renderer, &rectOnScreen2, 50, 320, BONUSBTN_W,
			BONUSBTN_H);
	SDL_Rect rectOnScreen3 { BONUSBTN_W * 2, 0, BONUSBTN_W, BONUSBTN_H };
	m_buttonX10.Render(m_renderer, &rectOnScreen3, 50, 490, BONUSBTN_W,
			BONUSBTN_H);

	RenderChoiceWin();
	m_spriteDieTexture.Render(m_renderer, 480, 450, 163, 168, &m_spriteDie[0]);
	m_spriteDieTexture.Render(m_renderer, 700, 400, 163, 168, &m_spriteDie[5]);

}

void BonusGame::HandleEvent() {
	switch (m_event->type) {
	case SDL_QUIT:
		*m_ptrGameState = QUIT;
		break;

	case SDL_MOUSEBUTTONDOWN: {
		if (m_buttonX2.IsSelected()) {
			std::cout << "m_btnX2.IsPressed()" << std::endl;
			Mix_PlayChannel(-1, ButtonPress, 0);
			Mix_PlayChannel(-1, RollDice, 0);
			RenderDice();
			int ResultDice = BonusGame::ResultDice();
			if (ResultDice < 5) {
				*m_ptrCredit = calculateWin(*m_ptrCredit, 2);
				*m_ptrGameState = WIN;
				winsABonus = true;
			}
		} else if (m_buttonX5.IsSelected()) {
			std::cout << "m_btnX5.IsPressed()" << std::endl;
			Mix_PlayChannel(-1, ButtonPress, 0);
			Mix_PlayChannel(-1, RollDice, 0);
			RenderDice();
			int ResultDice = BonusGame::ResultDice();
			if (ResultDice > 4 && ResultDice < 10) {
				*m_ptrCredit = calculateWin(*m_ptrCredit, 5);
				*m_ptrGameState = WIN;
				winsABonus = true;
			}
		} else if (m_buttonX10.IsSelected()) {
			std::cout << "m_btnX10.IsPressed()" << std::endl;
			Mix_PlayChannel(-1, ButtonPress, 0);
			Mix_PlayChannel(-1, RollDice, 0);
			RenderDice();
			int ResultDice = BonusGame::ResultDice();
			if (ResultDice > 9 && ResultDice < 13) {
				*m_ptrCredit = calculateWin(*m_ptrCredit, 10);
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
	for (int i = 0; i < 6; i++) {
		m_spriteDie[i].x = i * 163;
		m_spriteDie[i].y = 0;
		m_spriteDie[i].w = 163;
		m_spriteDie[i].h = 168;
	}
}
void BonusGame::RenderDice() {
	for (int i = 0; i < 6; i++) {

	std::cout<<":RenderDice()"<<std::endl;
		m_spriteDieTexture.Render(m_renderer, 480, 450, 163, 168,
				&m_spriteDie[i * rand() % 6 + 1]);
		m_spriteDieTexture.Render(m_renderer, 680, 400, 163, 168,
				&m_spriteDie[i * rand() % 6 + 1]);


	}
}

void BonusGame::LoadChoiceWinFiles() {
	m_tChoiceWin.LoadFromFile(m_renderer, "Resources/ChoiseWin.png");
	//Load sprite sheet texture
	int w = 280;
	int h = 35;
	for (int i = 0; i < 3; i++) {
		m_ChoiceWin[i].x = 0;
		m_ChoiceWin[i].y = i * h;
		m_ChoiceWin[i].w = w;
		m_ChoiceWin[i].h = h;

	}
}

void BonusGame::RenderChoiceWin() {
	int w = 280;
	int h = 35;
	SDL_Rect rect[3] { 0, 0, w, h };
	for (int i = 0; i < 3; i++) {
		m_tChoiceWin.Render(m_renderer, 50, 70, 350, 50, &rect[i]);
	}
}

void BonusGame::DoAnimation() {
//	bool quit = false;
//	while (*m_ptrGameState == BONUS) {
////	//Clear screen
////	SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
////	SDL_RenderClear(m_renderer);
//		//Current animation frame
//		int frame = 0;
//		//Render current frame/Изтриване на текущата рамка
//		SDL_Rect* currentClip = &m_ChoiceWin[frame * 3];
//		m_tChoiceWin.Render(m_renderer, 50, 70, 350, 50, currentClip);
//		//Update screen
//		//SDL_RenderPresent(m_renderer);
//		//Go to next frame/Отидете на следващия кадър
//		++frame;
//
//		//Cycle animation
//		if (frame * 3 <= 3) {
//			frame = 0;
//		}
//	}
}

void BonusGame::TimerBonus() {
//	//Reset start time on return keypress
//	SDL_Event e;
//	if (e.type == SDL_KEYDOWN) {
//		//Start/stop
//		if (e.key.keysym.sym == SDLK_s) {
//			if (timer.isStarted()) {
//				timer.stop();
//			} else {
//				timer.start();
//			}
//		}
//		//Pause/unpause
//		else if (e.key.keysym.sym == SDLK_p) {
//			if (timer.isPaused()) {
//				timer.unpause();
//			} else {
//				timer.pause();
//			}
//		}
//	}
//
//	//Set text to be rendered
//	timeText.str("");
//	timeText << "Seconds since start time " << (timer.getTicks() / 1000.f);

//	//Render text
//	if (!gTimeTextTexture.loadFromRenderedText(timeText.str().c_str(),
//			textColor)) {
//		printf("Unable to render time texture!\n");
//	}
//
//	//Clear screen
//	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//	SDL_RenderClear (gRenderer);
//
//	//Render textures
//	gStartPromptTexture.render(
//			(SCREEN_WIDTH - gStartPromptTexture.getWidth()) / 2, 0);
//	gPausePromptTexture.render(
//			(SCREEN_WIDTH - gPausePromptTexture.getWidth()) / 2,
//			gStartPromptTexture.getHeight());
//	gTimeTextTexture.render((SCREEN_WIDTH - gTimeTextTexture.getWidth()) / 2,
//			(SCREEN_HEIGHT - gTimeTextTexture.getHeight()) / 2);
//
//	//Update screen
}

void BonusGame::Close() {	//Free the sound effects
	Mix_FreeChunk(RollDice);
	Mix_FreeChunk(ButtonPress);

}
