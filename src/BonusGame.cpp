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

BonusGame::BonusGame(SDL_Renderer* renderer) :m_texture(),
	m_ChoiceWin(renderer, "Resources/DoubleUpDice.png",	0, 0, 530, 75),
	m_btnX2(renderer, "Resources/DoubleUpDice.png",0, 0, S_BONUSBTN_W,S_BONUSBTN_H),
	m_btnX5(renderer, "Resources/DoubleUpDice.png",0, 0, S_BONUSBTN_W, S_BONUSBTN_H),
	m_btnX10(renderer, "Resources/DoubleUpDice.png",0, 0, S_BONUSBTN_W, S_BONUSBTN_H)
{
	m_texture.LoadFromFile(renderer, "Resources/DoubleUpDice2.jpg");
	InitFont("Resources/font.ttf");
	m_bonusText.LoadFromFile(renderer, "Resources/win.png");
	m_ChoiceWin.SetPosition( 0 , 0 );
	m_btnX2.SetPosition ( 50 , 120 );
	m_btnX5.SetPosition ( 50 , 270 );
	m_btnX10.SetPosition( 50 , 420 );
	//Load sound effects
	ButtonPress = Mix_LoadWAV("ResourcesMusic/ButtonPress.wav");
	RollDice = Mix_LoadWAV("ResourcesMusic/RollDice.wav");
	Winning = Mix_LoadWAV("ResourcesMusic/Winning.wav");
}

BonusGame::~BonusGame()
{
	std::cerr << "BonusGame Object deleted.\n";
}
ButtonObject& BonusGame::GetChoiceWin()
{
	return m_ChoiceWin;
}

ButtonObject& BonusGame::GetWinX2()
{
	return m_btnX2;
}

ButtonObject & BonusGame::GetWinX5()
{
	return m_btnX5;
}

ButtonObject & BonusGame::GetWinX10()
{
	return m_btnX10;
}

void BonusGame::InitFont(std::string path)
{
	m_font = TTF_OpenFont(path.c_str(), 50);
	if(m_font == nullptr)
	{
		std::cerr << "Failed to load "<< path << " font! SDL_ttf Error:"
				<< TTF_GetError();
		return;
	}
}

void BonusGame::Render(SDL_Renderer * renderer)
{
	//render the bonus
	int x = 0;
	int y = 0;
	int w = SCREEN_WIDTH ;
	int h = SCREEN_HEIGHT;
	m_texture.Render(renderer, x, y, w, h);
}
void BonusGame::RenderCalculateWin(SDL_Renderer * renderer)
{
	SDL_Color color{ 255, 255, 255 };

	int x = SCREEN_WIDTH/3;
	int y = SCREEN_HEIGHT-100;
	std::string newWin = "Credits :  757777" ;
	std::ostringstream ss;
	//ss<<credits;
	//std::string credits(ss.str());
	//newWin = calculateWin(4.5,2);
	m_tText.LoadFromRendererdText(renderer, m_font, newWin, color);
	m_tText.Render(renderer, x, y, m_tText.GetWidth(), m_tText.GetHeight() );

}
void BonusGame::RenderWin(SDL_Renderer * renderer)
{
	//render the Win screеn
		int x = 0;
		int y = 0;
		int w = SCREEN_WIDTH ;
		int h = SCREEN_HEIGHT;
		m_bonusText.Render(renderer, x, y, w, h);
		//render the text
		RenderCalculateWin(renderer);
}

int BonusGame::ResultDice()
{
	int rollADie1, rollADie2, totalDice;
	srand(time(NULL));
	rollADie1 = rand() % 6 + 1;
	rollADie2 = rand() % 6 + 1;
	totalDice = rollADie1 + rollADie2;
	std::cout<<"totalDice = rollADie1 + rollADie2 = "<<totalDice<<std::endl;
	return totalDice;

}
double BonusGame::calculateWin( double credits,int totalDice)
{
	double res = 0;
	res = credits * (double)totalDice;
	return res;
}

