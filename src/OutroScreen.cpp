#include "OutroScreen.h"
#include "Globals.h"
#include "Recovery.h"
#include <iostream>
using std::cout;
#include <sstream>
using std::stringstream;

double OutroScreen::m_dCredit = -1;
int OutroScreen::m_iStart = 0;

OutroScreen::OutroScreen(SDL_Renderer* renderer, SDL_Event* ptrEvent, eGameState* gameState) :
	Screen(renderer),
	m_ptrEvent(ptrEvent),
	m_ptrGameState(gameState),
	m_tBackground(),
	m_bShowPlayButton(true),
	m_iTextY(0)
{
	m_tBackground.LoadFromFile(renderer, "Resources/outropictures.png");
//	m_tCredit.InitFont("Resources/font.ttf", 22);

}

OutroScreen::~OutroScreen() {
	m_ptrEvent = nullptr;
	m_ptrGameState = nullptr;
	std::cout << "Deleted OutroScreen.\n";
}

void OutroScreen::SetTimer(int time)
{
	m_iStart = time;
}

void OutroScreen::Draw() {
	Screen::Draw();
}

void OutroScreen::Render() {
	Recovery::Save(m_dCredit);

	m_tBackground.Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	std::stringstream ss;
	ss << "Congratulations you have won: " << m_dCredit * DENOM << " BGN";
	m_tCredit.LoadFromRendererdText(m_renderer, "Resources/font.ttf",
		ss.str().c_str(), SDL_Color{ 255, 255, 200 }, 24);
	m_tCredit.Render(m_renderer, (SCREEN_WIDTH - m_tCredit.GetWidth()) / 2, m_iTextY,
		m_tCredit.GetWidth(), m_tCredit.GetHeight());
	ss.str();
}

void OutroScreen::HandleEvent() 
{
	switch(m_ptrEvent->type)
	{
	case SDL_QUIT:
		*m_ptrGameState = QUIT;
		break;
	case SDL_MOUSEBUTTONDOWN:
		
		break;
	}
}

void OutroScreen::Delay() 
{
	m_iTextY = -50 - m_tCredit.GetHeight();

	while(m_iStart > SDL_GetTicks() - 5000)
	{
		Render();
		AnimText();
		Draw();
	} 

	*m_ptrGameState = INTRO;
}

void OutroScreen::SetCredit(double credit)
{
	m_dCredit = credit;
}

void OutroScreen::AnimText()
{
	if(m_iTextY <= 50 + m_tCredit.GetHeight())
		m_iTextY++;
}