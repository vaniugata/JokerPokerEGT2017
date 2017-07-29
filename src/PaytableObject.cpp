#include "PaytableObject.h"
#include "Globals.h"
#include "Game.h"
#include <iostream>
using std::cout;
#include <sstream>
using std::stringstream;

int PaytableObject::m_iNextBetCoef = 2;
int PaytableObject::m_iPrevBetCoef = 1;

PaytableObject::PaytableObject(SDL_Renderer* renderer) :
	m_texture(), 
	m_iWinnerIndex(-1)
{
	m_texture.LoadFromFile(renderer, "Resources/paytable2.png");
	
	m_btnBetOne.m_texture.LoadFromFile(renderer, "Resources/betButtons.png");

	m_btnBetOne.SetDimentions(S_BETBTN_W, S_BETBTN_H);

		m_btnBetOne.SetPosition(SCREEN_WIDTH - m_btnBetOne.GetWidth(), \
	SCREEN_HEIGHT - m_btnBetOne.GetHeight() );

		m_btnBetMax.m_texture.LoadFromFile(renderer, "Resources/betButtons.png");

		m_btnBetMax.SetDimentions(S_BETBTN_W, S_BETBTN_H);

	m_btnBetMax.SetPosition(SCREEN_WIDTH - 2 * m_btnBetOne.GetWidth(), \
		SCREEN_HEIGHT - m_btnBetOne.GetHeight() );
}

PaytableObject::~PaytableObject()
{
	std::cout << "PaytableObject deleted.\n";

	TTF_CloseFont(m_font);
	m_font = nullptr;
}

const std::vector<int>& PaytableObject::GetBet() const
{
	return m_vecBets;
}

void PaytableObject::SetWinnerIndex(int index)
{
	this->m_iWinnerIndex = index;
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
	RenderBetList(renderer, m_iWinnerIndex);
}

void PaytableObject::RenderCardCombinations(SDL_Renderer * renderer)
{
	SDL_Color color{ 255, 255, 255 };
	SDL_Color colorWin{ 0, 255, 0 };

	int x = SCREEN_WIDTH - m_texture.GetWidth() * PAYTABLE_TEXTURE_SCALE_FACTOR + X_BORDER_OFFSET;
	for(int i = 0; i < m_vecHands.size(); i++)
	{
		
		int y = Y_BORDER_OFFSET + m_tText.GetHeight() * i;
		
		m_tText.LoadFromRendererdText(renderer, "Resources/font.ttf", m_vecHands[i], color, 18);
		m_tText.Render(renderer, x, y, m_tText.GetWidth(), m_tText.GetHeight() );

		if(m_iWinnerIndex == i)
		{
			if(Game::SwitchFrame(500) == false)
			{
				m_tText.LoadFromRendererdText(renderer, "Resources/font.ttf",
					m_vecHands[i], colorWin, 18);
				m_tText.Render(renderer, x, y, m_tText.GetWidth(), m_tText.GetHeight());
			}
			else if(Game::SwitchFrame(500) == true)
			{
				m_tText.LoadFromRendererdText(renderer, "Resources/font.ttf",
					m_vecHands[i], color, 18);
				m_tText.Render(renderer, x, y, m_tText.GetWidth(), m_tText.GetHeight());
			}
		}
	}
	
}

void PaytableObject::RenderBetList(SDL_Renderer * renderer, int winnerIndx)
{
	SDL_Color color{ 255, 255, 255 };
	SDL_Color colorWin{ 0, 255, 0 };

	int x = SCREEN_WIDTH - m_texture.GetWidth() * PAYTABLE_TEXTURE_SCALE_FACTOR
		+ X_BORDER_OFFSET + TEXT_BLANK_SPACE;

	std::stringstream ss;
	for (int i = 0; i < m_vecBets.size(); i++)
	{
		int y = Y_BORDER_OFFSET + m_tText.GetHeight() * i;

		ss << m_vecBets[i];
		m_tText.LoadFromRendererdText(renderer, "Resources/font.ttf",
			ss.str(), color, 18);
		m_tText.Render(renderer, x, y, m_tText.GetWidth(), m_tText.GetHeight());
		ss.str("");

		if(winnerIndx == i)
		{
			ss << m_vecBets[i];
			m_tText.LoadFromRendererdText(renderer, "Resources/font.ttf",
				ss.str(), colorWin, 18);
			m_tText.Render(renderer, x, y, m_tText.GetWidth(), m_tText.GetHeight());
			ss.str("");
		}
	}
}

void PaytableObject::IncreaseBet()
{
	for(int i = 0; i < m_vecBets.size(); i++)
	{
		m_vecBets[i] /= m_iPrevBetCoef;
		m_vecBets[i] *= m_iNextBetCoef;
	}
	m_iNextBetCoef++;
	m_iPrevBetCoef++;

	if(m_iNextBetCoef >= 12)
	{
		for(int i = 0; i < m_vecBets.size(); i++)
			m_vecBets[i] /= m_iPrevBetCoef;
		
		m_iPrevBetCoef = 1;
		m_iNextBetCoef = 2;
	}
}

void PaytableObject::SetMaxBet()
{
	int arrMaxBets[] { 8000, 1300, 1000, 500, 200, 70, 50, 30, 20, 10, 10 };

	for(int i = 0; i < m_vecBets.size(); i++)
	{
		m_vecBets[i] = arrMaxBets[i];
	}

	m_iNextBetCoef = 11;
	m_iPrevBetCoef = 10;
}