#include "Intro.h"
#include "Globals.h"
#include <iostream>
using std::cout;
#include <sstream>
using std::stringstream;

Intro::Intro(SDL_Renderer* renderer, SDL_Event& event, eGameState& eGameState,
	double* credit) :
	m_ptrCredit(credit),
	Scene(renderer), 
	m_tBackgorund(),
	m_event(&event),
	m_ptrGameState(&eGameState), 
	m_btnNewGame(renderer, "Resources/new-game-btn.png", 0, 0, 
		INTRO_BTN_W , INTRO_BTN_H),
	m_btnResumeGame(renderer, "Resources/resume-game-btn.png", 0, 0,
		INTRO_BTN_W, INTRO_BTN_H),
	m_btnCashIn(renderer, "Resources/cash-in-btn.png", 0, 0,
		INTRO_BTN_W, INTRO_BTN_H)
{

	m_tBackgorund.LoadFromFile(renderer, "Resources/intro.png");
	m_tCredit.InitFont("Resources/font.ttf", 72);
//	m_tCredit.LoadFromFile(renderer, "Resources/credit-field.png");

}

Intro::~Intro()
{
	std::cout << "Intro Deleted.\n";
	m_ptrCredit = nullptr;
	m_event = nullptr;
	m_ptrGameState = nullptr;
}

void Intro::Draw()
{
	Scene::Draw();
}

void Intro::Render()
{
	//render background
	m_tBackgorund.Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	//Render buttons
	SDL_Rect rectOnScreen{0,0, 214, 53};

	m_btnNewGame.Render(m_renderer, &rectOnScreen, 20, 250, rectOnScreen.w, rectOnScreen.h);

	m_btnResumeGame.Render(m_renderer, &rectOnScreen, 20, 350, rectOnScreen.w, rectOnScreen.h);

	m_btnCashIn.Render(m_renderer, &rectOnScreen, 20, 450, rectOnScreen.w, rectOnScreen.h);

	//Render credit
	std::stringstream creditText;
	creditText << "Credit: " << *m_ptrCredit;
	m_tCredit.LoadFromRendererdText(m_renderer, creditText.str(), SDL_Color{255,255,255});
	m_tCredit.Render(m_renderer, 20, 0, m_tCredit.GetWidth(), m_tCredit.GetHeight());
}

void Intro::HandleEvent()
{
	switch(m_event->type)
	{
	case SDL_QUIT:
		*m_ptrGameState = QUIT;
		break;

	case SDL_MOUSEBUTTONDOWN:
		if(m_btnNewGame.IsSelected())
			*m_ptrGameState = PLAY;

		else if(m_btnResumeGame.IsSelected())
			*m_ptrGameState = PLAY;

		else if(m_btnCashIn.IsSelected())
			CashIn(10);
		std::cout << *m_ptrCredit;
		break;
	}

}

void Intro::CashIn(double ammount)
{
	if(*m_ptrCredit == -1) { *m_ptrCredit = 0; }
	*m_ptrCredit += (ammount * DENOM);
}

