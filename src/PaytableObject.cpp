#include "PaytableObject.h"
#include "Globals.h"
#include <iostream>
using std::cerr;
#include <sstream>
using std::stringstream;

int PaytableObject::coef = 2;
int PaytableObject::oldCoef = 1;

PaytableObject::PaytableObject(SDL_Renderer* renderer) :
	m_texture(), 
	m_btnBetOne(renderer, "Resources/betButtons.png", \
		0, 0, S_BETBTN_W, S_BETBTN_H),
	m_btnbetMax(renderer, "Resources/betButtons.png", \
		0, 0, S_BETBTN_W, S_BETBTN_H)
{
	m_texture.LoadFromFile(renderer, "Resources/paytable2.png");
	InitFont("Resources/font.ttf");

	m_btnBetOne.SetPosition(SCREEN_WIDTH - m_btnBetOne.GetWidth(), \
	SCREEN_HEIGHT - m_btnBetOne.GetHeight() );
	m_btnbetMax.SetPosition(SCREEN_WIDTH - 2 * m_btnBetOne.GetWidth(), \
		SCREEN_HEIGHT - m_btnBetOne.GetHeight() );


}

PaytableObject::~PaytableObject()
{
	std::cerr << "PaytableObject deleted.\n";
}

ButtonObject& PaytableObject::GetBetOneBtn() 
{
	return m_btnBetOne;
}

ButtonObject & PaytableObject::GetBetMaxBtn()
{
	return m_btnbetMax;
}

void PaytableObject::InitFont(std::string path)
{
	m_font = TTF_OpenFont(path.c_str(), 18);
	if(m_font == nullptr)
	{
		std::cerr << "Failed to load "<< path << " font! SDL_ttf Error:" << TTF_GetError();
		return;
	}
}

void PaytableObject::Render(SDL_Renderer * renderer)
{
	//render the table
	int x = SCREEN_WIDTH - m_texture.GetWidth() * PAYTABLE_TEXTURE_SCALE_FACTOR;
	int y = 0;
	int w = m_texture.GetWidth() * PAYTABLE_TEXTURE_SCALE_FACTOR;
	int h = m_texture.GetHeight() * PAYTABLE_TEXTURE_SCALE_FACTOR;
	m_texture.Render(renderer, x, y, w, h);

	//render the text
	RenderCardCombinations(renderer);
	//render the bet
	RenderBetList(renderer,-1);
}

void PaytableObject::RenderCardCombinations(SDL_Renderer * renderer)
{
	SDL_Color color{ 255, 255, 255 };

	int x = SCREEN_WIDTH - m_texture.GetWidth() * PAYTABLE_TEXTURE_SCALE_FACTOR + X_BORDER_OFFSET;
	for(int i = 0; i < m_vecHands.size(); i++)
	{
		
		int y = Y_BORDER_OFFSET + m_tText.GetHeight() * i;
		
		m_tText.LoadFromRendererdText(renderer, m_font, m_vecHands[i], color);
		m_tText.Render(renderer, x, y, m_tText.GetWidth(), m_tText.GetHeight() );
	}
	
}

void PaytableObject::RenderBetList(SDL_Renderer * renderer,int index)
{
     static SDL_Color color{ 255, 255, 255 };

	int x = SCREEN_WIDTH - m_texture.GetWidth() * PAYTABLE_TEXTURE_SCALE_FACTOR
		+ X_BORDER_OFFSET + TEXT_BLANK_SPACE;

	std::stringstream ss;
	for (int i = 0; i < m_vecBets.size(); i++)
	{
		int y = Y_BORDER_OFFSET + m_tText.GetHeight() * i;
		
		ss << m_vecBets[i];
		m_tText.LoadFromRendererdText(renderer, m_font, ss.str(), color);
		m_tText.Render(renderer, x, y, m_tText.GetWidth(), m_tText.GetHeight());
		ss.str("");
	}
	m_tText.LoadFromRendererdText(renderer, m_font, ss.str(), { 0,255,0 });

	

}



void PaytableObject::IncreaseBet()//Увеличете залога
{
	for(int i = 0; i < m_vecBets.size(); i++)
		m_vecBets[i] /= oldCoef;
	
	for(int i = 0; i < m_vecBets.size(); i++)
		m_vecBets[i] *= coef;

	coef++;
	oldCoef++;

	if(coef >= 12)
	{
		for(int i = 0; i < m_vecBets.size(); i++)
			m_vecBets[i] /= oldCoef;
		
		oldCoef = 1;
		coef = 2;
	}
}

void PaytableObject::SetMaxBet()
{
	int arrMaxBets[] { 8000, 1300, 1000, 500, 200, 70, 50, 30, 20, 10, 10 };

	for(int i = 0; i < m_vecBets.size(); i++)
	{
		m_vecBets[i] = arrMaxBets[i];
	}

	coef = 11;
	oldCoef = 10;
}

