#include "IntroScreen.h"
#include "Globals.h"
#include "Recovery.h"
#include <iostream>
using std::cout;
#include <sstream>
using std::stringstream;


IntroScreen::IntroScreen(SDL_Renderer* renderer, SDL_Event& event, eGameState& eGameState,
	double* credit,int* bet) :
	m_ptrBet(bet),
	m_ptrCredit(credit),
	Screen(renderer), 
	m_tBackgorund(),
	m_tInfo(),
	m_ptrEvent(&event),
	m_ptrGameState(&eGameState), 
	m_btnNewGame(renderer, "Resources/new-game-btn.png", 0, 0, 
		INTRO_BTN_W , INTRO_BTN_H),
	m_btnResumeGame(renderer, "Resources/resume-game-btn.png", 0, 0,
		INTRO_BTN_W, INTRO_BTN_H),
	m_btnCashIn(renderer, "Resources/cash-in-btn.png", 0, 0,
		INTRO_BTN_W, INTRO_BTN_H),
	m_btnInfo(renderer, "Resources/game-info-btn.png", 0,0,
		INTRO_BTN_W, INTRO_BTN_H),

		m_btnMusicPlus(renderer, "Resources/IncreasesB.png", 0,0, BUTTON_VOLUME_SIZE,BUTTON_VOLUME_SIZE),
		m_btnMusic(renderer, "Resources/PlayB.png" , 0,0,BUTTON_VOLUME_SIZE,BUTTON_VOLUME_SIZE),
		m_btnMusicMinus(renderer, "Resources/DecreasesB.png" ,0,0,BUTTON_VOLUME_SIZE,BUTTON_VOLUME_SIZE),
		m_btnMusicPause(renderer, "Resources/Pause.png", 0,0, BUTTON_VOLUME_SIZE,BUTTON_VOLUME_SIZE)


{

	m_tBackgorund.LoadFromFile(renderer, "Resources/intro.png");
	m_tCredit.InitFont("Resources/font.ttf", 32);
	m_tInfo.LoadFromFile(renderer, "Resources/info.png");

	m_mMusic.LoadMusic();
	Mix_PlayMusic(m_mMusic.getBackgraund(),1);
}

IntroScreen::~IntroScreen()
{
	std::cout << "Intro Deleted.\n";
	m_ptrCredit = nullptr;
	m_ptrEvent = nullptr;
	m_ptrGameState = nullptr;
}

void IntroScreen::Draw()
{
	Screen::Draw();
}

void IntroScreen::Render()
{

	//render background
	m_tBackgorund.Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	//Render buttons
	SDL_Rect rectOnScreen{0,0, 214, 53};
	m_btnInfo.Render(m_renderer, &rectOnScreen, 20, 150, rectOnScreen.w, rectOnScreen.h);
	m_btnNewGame.Render(m_renderer, &rectOnScreen, 20, 250, rectOnScreen.w, rectOnScreen.h);
	m_btnResumeGame.Render(m_renderer, &rectOnScreen, 20, 350, rectOnScreen.w, rectOnScreen.h);
	m_btnCashIn.Render(m_renderer, &rectOnScreen, 20, 450, rectOnScreen.w, rectOnScreen.h);

	//Render credit
	std::stringstream creditText;
	creditText << "Credits: " << *m_ptrCredit;
	m_tCredit.LoadFromRendererdText(m_renderer, "Resources/font.ttf", 
		creditText.str(), SDL_Color{255,255,255}, 32);
	m_tCredit.Render(m_renderer, 20, 0, m_tCredit.GetWidth(), m_tCredit.GetHeight());

	SDL_Rect rectMusicPlus{0,0, BUTTON_VOLUME_SIZE, BUTTON_VOLUME_SIZE};
	m_btnMusicPlus.Render(m_renderer, &rectMusicPlus, SCREEN_WIDTH-45, 5, BUTTON_VOLUME_SIZE,BUTTON_VOLUME_SIZE);

	SDL_Rect rectMusic{0,0, BUTTON_VOLUME_SIZE ,BUTTON_VOLUME_SIZE};
	if (m_bShowPlayButton)
	{
		m_btnMusic.Render(m_renderer, &rectMusic, SCREEN_WIDTH - 99, 5 , BUTTON_VOLUME_SIZE,BUTTON_VOLUME_SIZE);
	}
	else
	{
		m_btnMusicPause.Render(m_renderer, &rectMusic, SCREEN_WIDTH - 99, 5 , BUTTON_VOLUME_SIZE,BUTTON_VOLUME_SIZE);
	}
	SDL_Rect rectMusicMinus{0,0, BUTTON_VOLUME_SIZE ,BUTTON_VOLUME_SIZE};
			m_btnMusicMinus.Render(m_renderer, &rectMusicMinus, SCREEN_WIDTH - 153, 5, BUTTON_VOLUME_SIZE,BUTTON_VOLUME_SIZE);
	if(m_bShowInfo == true)
		RenderInfoWindow();
}

void IntroScreen::HandleEvent()
{
	switch(m_ptrEvent->type)
	{
	case SDL_QUIT:
		*m_ptrGameState = QUIT;
		break;

	case SDL_MOUSEBUTTONDOWN:
		if(m_btnNewGame.IsSelected() && *m_ptrCredit > 0)
		{
			Mix_PlayChannel(-1,m_mMusic.getButton(),0);
			Recovery::Save(*m_ptrCredit);
			*m_ptrGameState = PLAY;

		}

		else if(m_btnResumeGame.IsSelected())
		{
			Mix_PlayChannel(-1,m_mMusic.getButton(),0);
			*m_ptrGameState = PLAY;
			*m_ptrCredit = Recovery::Read().credit;
		}

		else if(m_btnMusic.IsSelected() && m_bShowPlayButton == true)
		{
			m_bShowPlayButton = false;
		}
		else if(m_btnMusicPause.IsSelected() && m_bShowPlayButton == false)
		{
			m_bShowPlayButton = true;
		}


		else if(m_btnCashIn.IsSelected())
			CashIn(10);

			EvaluateInfoRendering();
		break;
	}

}

void IntroScreen::CashIn(double ammount)
{
	if(*m_ptrCredit == -1) { *m_ptrCredit = 0; }
	*m_ptrCredit += ammount;
}

void IntroScreen::RenderInfoWindow()
{
	m_tInfo.Render(m_renderer, (SCREEN_WIDTH - m_tInfo.GetWidth() ), 0, 
		m_tInfo.GetWidth(), m_tInfo.GetHeight() );
}

void IntroScreen::EvaluateInfoRendering()
{
	if(m_btnInfo.IsSelected() && m_bShowInfo == false)
	{
		Mix_PlayChannel(-1, m_mMusic.getButton(), 0);
		m_bShowInfo = true;
	 }
	
	else if(m_btnInfo.IsSelected() && m_bShowInfo == true)
	{
		Mix_PlayChannel(-1, m_mMusic.getButton(), 0);
		m_bShowInfo = false;
	}
}

