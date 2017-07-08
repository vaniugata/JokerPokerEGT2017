#include "PaytableObject.h"
#include "Globals.h"
#include <iostream>
using std::cerr;

PaytableObject::PaytableObject(SDL_Renderer * renderer) :
	m_texture()
{
	m_texture.LoadFromFile(renderer, "../../Resources/paytable2.png");
	InitFont("../../Resources/font.ttf");
}

PaytableObject::~PaytableObject()
{
	std::cerr << "PaytableObject deleted.\n";
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
	RenderBetList(renderer);
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

void PaytableObject::RenderBetList(SDL_Renderer * renderer)
{
	SDL_Color color { 255, 255, 255 };

	int x = SCREEN_WIDTH - m_texture.GetWidth() * PAYTABLE_TEXTURE_SCALE_FACTOR 
		+ X_BORDER_OFFSET + TEXT_BLANK_SPACE;

	for(int i = 0; i < m_vecBets.size(); i++)
	{
		int y = Y_BORDER_OFFSET + m_tText.GetHeight() * i;

		m_tText.LoadFromRendererdText(renderer, m_font, m_vecBets[i].text, color);
		m_tText.Render(renderer, x, y, m_tText.GetWidth(), m_tText.GetHeight() );
	}
}

void PaytableObject::IncreaseBet()
{
	std::cerr << "Increase bet.\n";
}

