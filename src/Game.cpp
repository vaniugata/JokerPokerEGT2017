#include "Game.h"
#include "Globals.h"
#include "Music.h"
#include "includesSDL2.h"
#include "Evaluation\EvalKingsOrBetter.h"
#include "Evaluation\EvalTwoPair.h"
#include "Evaluation\EvalThreeOfKind.h"
#include "Evaluation\EvalStraight.h"
#include "Evaluation\EvalFlush.h"
#include "Evaluation\EvalFullHouse.h"
#include "Evaluation\EvalFourOfAKind.h"
#include "Evaluation\EvalStraightFlush.h"
#include "Evaluation\EvalWildRoyalFlush.h"
#include "Evaluation\EvalFiveOfAKind.h"
#include "Evaluation\EvalNaturalRoyalFlush.h"
#include "OutroScreen.h"
#include "Recovery.h"

#include <iostream>
using std::cerr;
#include <sstream>
Game::Game() :
	m_dCredit(0), m_window(nullptr), m_renderer(nullptr),
	m_eGameState(INTRO), m_event(), m_ptrDeck(nullptr),
	m_bIsGameOver(false), m_bIsBonus(false)
{
	InitSDL();

	m_tBackground = Texture(m_renderer);
	m_tBackground.LoadFromFile(m_renderer, "Resources/back2.png");

	m_tCredit = Texture(m_renderer);
	m_tCredit.InitFont("Resources/font.ttf", 28);

	m_tGameOver = Texture(m_renderer);
	m_tGameOver.InitFont("Resources/ARCADECLASSIC.TTF", 28);

	m_paytable = new PaytableObject(m_renderer);

	m_btnCashOut = new  ButtonObject(m_renderer, "Resources/cash-out-btn.png",
		0, 0, INTRO_BTN_W, INTRO_BTN_H);

	m_btnDealDraw = new  ButtonObject(m_renderer, "Resources/round-button.png",
			0, 0, DEALDRAWBTN_W, DEALDRAWBTN_H);

	m_ptrDeck = new Deck(m_renderer);
	//Card evaluation
	m_vecEvaluations.push_back(new EvalKingsOrBetter());
	m_vecEvaluations.push_back(new EvalTwoPair());
	m_vecEvaluations.push_back(new EvalThreeOfKind());
	m_vecEvaluations.push_back(new EvalStraight());
	m_vecEvaluations.push_back(new EvalFlush());
	m_vecEvaluations.push_back(new EvalFullHouse());
	m_vecEvaluations.push_back(new EvalFourOfAKind());
	m_vecEvaluations.push_back(new EvalStraightFlush());
	m_vecEvaluations.push_back(new EvalWildRoyalFlush());
	m_vecEvaluations.push_back(new EvalFiveOfAKind());
	m_vecEvaluations.push_back(new EvalNaturalRoyalFlush());
}

Game::~Game()
{
	delete m_paytable;
	delete m_btnCashOut;
	delete m_btnDealDraw;
	std::cout << "Game deleted.\n";
	for(int i = 0; i < m_vecEvaluations.size(); i++)
	{
		delete m_vecEvaluations[i];
	}

	Close();
}

SDL_Renderer* Game::GetRenderer() const
{
	return  m_renderer;
}
double* Game::GetCredit()
{
	return &m_dCredit;
}

void Game::SetGameState(eGameState gs)
{
	this->m_eGameState = gs;
}

void Game::Draw()
{

	SDL_RenderPresent(m_renderer);
	SDL_RenderClear(m_renderer);
}

void Game::Render()
{
	//draw background
	m_tBackground.Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	//draw paytable
	m_paytable->Render(m_renderer);
	//draw buttons
	SDL_Rect clip1{ T_BTN_W_BET, 0, T_BTN_W_BET, T_BTN_H_BET };
	m_paytable->GetBetOneBtn().Render(m_renderer, &clip1,
		SCREEN_WIDTH - BET_BTN_W - 10, SCREEN_HEIGHT - BET_BTN_H - 5,
		BET_BTN_W, BET_BTN_H);
	SDL_Rect clip2{ 0, 0, T_BTN_W_BET, T_BTN_H_BET };
	m_paytable->GetBetMaxBtn().Render(m_renderer, &clip2,
		SCREEN_WIDTH - 2 * BET_BTN_W - 10, SCREEN_HEIGHT - BET_BTN_H - 5,
		BET_BTN_W, BET_BTN_H);
	SDL_Rect clipCashOut{ 0, 0, INTRO_BTN_W, INTRO_BTN_H };
	m_btnCashOut->Render(m_renderer, &clipCashOut,
		0, SCREEN_HEIGHT - m_btnCashOut->GetHeight() + 5,
		INTRO_BTN_W, INTRO_BTN_H);

	SDL_Rect clipDealDraw{ 0, 0,DEAL_W, DEAL_H / 2 };
	if(m_ptrDeck->GetKillCount() == 1) { clipDealDraw.x += DEAL_W; }
	else if(m_ptrDeck->GetKillCount() == 2 && 
		m_iWinIndex >= 5 && m_iWinIndex <= 10) { clipDealDraw.x += 2 * DEAL_W; }
	m_btnDealDraw->Render(m_renderer, &clipDealDraw,      //Button Deal/Draw
			600, SCREEN_HEIGHT - m_btnDealDraw->GetHeight() + 5,
			DEALDRAWBTN_W, DEALDRAWBTN_H);

	if(m_ptrDeck != nullptr)
	{
		m_ptrDeck->RenderStart(m_renderer);
		RenderRound(m_ptrDeck);
	}
	RenderGameInfo();
	if(m_bIsGameOver) { RenderGameOver(); }
}

void Game::RenderRound(Deck* deck)
{
	deck->RenderHand(m_renderer);
	deck->RenderHoldBtns(m_renderer);
	deck->RenderHoldStamps(m_renderer);	
}

void Game::RenderGameInfo()
{
	SDL_Color clrText{ 255,255,255 };
	SDL_Color clrCredit{ 235, 235, 0 };
	std::stringstream ss;

	//Credit
	ss << "Credits: ";
	m_tCredit.LoadFromRendererdText(m_renderer, ss.str(), clrText);
	m_tCredit.Render(m_renderer, 150, SCREEN_HEIGHT - 2 * m_tCredit.GetHeight() - 10,
		m_tCredit.GetWidth(), m_tCredit.GetHeight());
	ss.str("");
	int iTextW = m_tCredit.GetWidth();
	ss << m_dCredit;
	m_tCredit.LoadFromRendererdText(m_renderer, ss.str(), clrCredit);
	m_tCredit.Render(m_renderer,150 + iTextW, SCREEN_HEIGHT - 2 * m_tCredit.GetHeight() - 10,
		m_tCredit.GetWidth(), m_tCredit.GetHeight());
	ss.str("");

	//Bet
	ss << "Bet: ";
	m_tCredit.LoadFromRendererdText(m_renderer, ss.str(), clrText);
	m_tCredit.Render(m_renderer, 280, SCREEN_HEIGHT - 2 * m_tCredit.GetHeight() - 10,
		m_tCredit.GetWidth(), m_tCredit.GetHeight());
	iTextW = m_tCredit.GetWidth();
	ss.str("");
	ss << m_paytable->GetBet().at(10);
	m_tCredit.LoadFromRendererdText(m_renderer, ss.str(), clrCredit);
	m_tCredit.Render(m_renderer,280 + iTextW, SCREEN_HEIGHT - 2 * m_tCredit.GetHeight() - 10,
		m_tCredit.GetWidth(), m_tCredit.GetHeight());
	ss.str("");
}

void Game::RenderGameOver()
{
	m_tGameOver.LoadFromRendererdText(m_renderer, std::string("GAME OVER"),
		SDL_Color{255,255,255});
	m_tGameOver.Render(m_renderer, 
		(SCREEN_WIDTH - m_tGameOver.GetWidth() ) / 2, 300,
	m_tGameOver.GetWidth(), m_tGameOver.GetHeight() );
}

void Game::HandleEvent()
{
	switch(this->m_event.type)
	{
	case SDL_QUIT:
		SetGameState(QUIT);
		break;

	case SDL_KEYDOWN:
		ProcessKeyInput();
		break;

	case SDL_MOUSEBUTTONDOWN:
		ProcessMouseInput();
		break;
	}
}

void Game::ProcessKeyInput()
{
	if(m_event.key.keysym.sym == SDLK_SPACE)
	{
		m_paytable->IncreaseBet();
	}

	else if(m_event.key.keysym.sym == SDLK_d)
	{
		ProcessRound();
	}//sdlk d

	else if(m_event.key.keysym.sym == SDLK_b)
	{
		m_eGameState = BONUS;
	}
	else if(m_event.key.keysym.sym == SDLK_w)
		{
			m_eGameState = WIN;
		}
}

void Game::ProcessMouseInput()
{
	int countIsSelected = 0;
	if(m_btnCashOut->IsSelected())
	{
		OutroScreen::SetCredit(m_dCredit);
		m_eGameState = OUTRO;
	}
	else if(m_paytable->GetBetOneBtn().IsSelected())
	{
		m_paytable->IncreaseBet();
	}
	else if(m_paytable->GetBetMaxBtn().IsSelected())
	{
		m_paytable->SetMaxBet();
	}
	else if(m_ptrDeck != nullptr && m_ptrDeck->GetKillCount() == 1)
	{
		m_ptrDeck->HoldSelectedCards();
	}
	if(m_btnDealDraw->IsSelected())
	{
		ProcessRound();
	}
}

void Game::ProcessRound()
{
	m_bIsGameOver = false;

	//Deal 5 cards on the screen
	m_ptrDeck->deal();
	//Save to recovery file
	Recovery::Save(m_dCredit);
	//TODO: Invoke sound for flipping the cards
	//Charge the fee to play a round
	if(m_ptrDeck->GetKillCount() == 1){ m_dCredit -= m_paytable->GetBet().at(10);}

	if(m_ptrDeck->GetKillCount() == 2)
	{
		//Evaluate hand
		 m_iWinIndex = 11;
		std::vector<Card> hand = m_ptrDeck->GetSortedHand();
		std::vector<Evaluation*>::iterator it;
		for(it = m_vecEvaluations.begin(); it != m_vecEvaluations.end(); it++)
		{
			if((*it)->EvaluateHand(hand) < m_iWinIndex && (*it)->EvaluateHand(hand) != -1)
			{
				m_iWinIndex = (*it)->EvaluateHand(hand);
			}
			std::cout << "Evaluated hand: " << (*it)->EvaluateHand(hand) << "\n";
		}
		//Add win ammount to credit
		if(m_iWinIndex >= 0 && m_iWinIndex <= m_paytable->GetBet().size() - 1)
		{
			m_dCredit += m_paytable->GetBet().at(m_iWinIndex);

			Recovery::Save(m_dCredit, m_paytable->GetBet().at(10), m_paytable->GetBet().at(m_iWinIndex) );
			//set the current win in the paytable
			m_paytable->SetWinnerIndex(m_iWinIndex);
		}
		//Check for bonus state
		if(m_iWinIndex >= 5 && m_iWinIndex <= 10) { m_bIsBonus = true; }
	}


	if(m_ptrDeck->GetKillCount() == 3)
	{
		delete m_ptrDeck;
		m_ptrDeck = nullptr;
		m_paytable->SetWinnerIndex(-1);
		m_ptrDeck = new Deck(m_renderer);
		m_bIsGameOver = true;
		if(m_bIsBonus)
		{
			BonusGame::setWin(m_paytable->GetBet().at(m_iWinIndex));
			m_bIsBonus = false;
			m_eGameState = BONUS; 
		}
	}
}

void Game::InitSDL()
{
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError();
		return;
	}

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cerr << "SDL MUSIC PROBLEM INITIALIZE" << std::endl;
	}

	m_window = SDL_CreateWindow("Joker Poker", \
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, \
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(m_window == nullptr)
	{
		std::cerr << "Window could not be created! SDL Error: " << SDL_GetError();
		return;
	}
	// -1 is the index of the first supported rendering driver 
	m_renderer = SDL_CreateRenderer(m_window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(m_renderer == nullptr)
	{
		std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError();
		return;
	}

	SDL_SetRenderDrawColor(m_renderer, 100, 50, 100, 0);

	//initialize image loading
	int imgFlags = IMG_INIT_PNG;
	if(!(IMG_Init(imgFlags) & imgFlags))
	{
		std::cerr << "SDL_image could not initialize! SDL_image Error: " << SDL_GetError();
		return;
	}

	//initalize text loading
	if(TTF_Init() == -1)
	{
		std::cerr << "DL_ttf could not initialize! SDL_ttf Error:" << SDL_GetError();
		return;
	}
	//Initialize SDL_mixer
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << SDL_GetError();
		return;
	}
}

void Game::Close()
{
	SDL_DestroyWindow(m_window);
	m_window = nullptr;

	SDL_Quit();
}
