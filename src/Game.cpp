#include "Game.h"
#include "Globals.h"
#include <iostream>
using std::cerr;
#include "includesSDL2.h"
//--------------R----------
double credits = 123456;
bool isClickWin = false;
//------------------------

Game::Game() : 
	m_window(nullptr), m_renderer(nullptr), 
	m_eGameState(INTRO), m_event()
{
	InitSDL();

	m_tBackground = new Texture;
	m_tBackground->LoadFromFile(m_renderer, "Resources/back2.png");

	m_paytable = new PaytableObject(m_renderer);
	deck = new Deck(m_renderer);
//	-----------------R---------------------
	m_bonus = new BonusGame(m_renderer);
//	-----------------------------------------
}

Game::~Game()
{
	delete m_tBackground;
	delete m_paytable;
	delete deck;
	//-------R------------
		delete m_bonus;
	//------------------------
	std::cout << "Game deleted.\n";
	Close();
}

SDL_Renderer* Game::GetRenderer() const
{
	return  m_renderer;
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
	m_tBackground->Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	//draw paytable
	m_paytable->Render(m_renderer);
	//draw bet buttons
	SDL_Rect clip1 {T_BTN_W_BET, 0, T_BTN_W_BET, T_BTN_H_BET };
	m_paytable->GetBetOneBtn().Render(m_renderer, &clip1, 750, 500);
	SDL_Rect clip2 { 0, 0, T_BTN_W_BET, T_BTN_H_BET };
	m_paytable->GetBetMaxBtn().Render(m_renderer, &clip2, 650, 500);

	deck->RenderHand(m_renderer);
}

//------------------------------------R--------------------------------
void Game::RenderBonusGame()
{
		//draw Bonus
		m_bonus->Render(m_renderer);
		//draw bet buttons
		SDL_Rect clip1 {0, 100, S_BONUSBTN_W, S_BONUSBTN_H};
		m_bonus->GetWinX2().Render(m_renderer, &clip1, S_BONUSBTN_W, S_BONUSBTN_H);
		SDL_Rect clip2{ 0, 250, S_BONUSBTN_W, S_BONUSBTN_H };
		m_bonus->GetWinX5().Render(m_renderer, &clip2, S_BONUSBTN_W, S_BONUSBTN_H);
		SDL_Rect clip3{ 0, 400, S_BONUSBTN_W, S_BONUSBTN_H};
		m_bonus->GetWinX10().Render(m_renderer, &clip3, S_BONUSBTN_W, S_BONUSBTN_H);
		SDL_Rect clip4 {0, 0, 540 ,80};
		m_bonus->GetChoiceWin().Render(m_renderer, &clip4, 540, 80);
//		SDL_Rect clip5 {0, 0, 545 ,85};
//		m_bonus->GetChoiceWin().Render(m_renderer, &clip5, 545, 85);

}
void Game::RenderBonusWin()
{
	m_bonus->RenderWin(m_renderer);
}
//-----------------------------------------------------------------------
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
		ProcessMouseWin();

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
		deck->deal();
		m_paytable->RenderBetList(m_renderer, deck->evaluateHand());
		
	}
}


void Game::ProcessMouseInput()
{
	if(m_paytable->GetBetOneBtn().IsPressed() )
	{
		m_paytable->IncreaseBet();
	}

	if(m_paytable->GetBetMaxBtn().IsPressed() )
	{
		m_paytable->SetMaxBet();
	}

	
}
//-----------------------R-----------------------
void Game::ProcessMouseWin() {

		if(m_bonus->GetWinX2().IsPressed() )
		{
			Mix_PlayChannel( -1,m_bonus->ButtonPress, 0 );
			Mix_PlayChannel( -1,m_bonus->RollDice, 0 );
			int ResultDice = m_bonus->ResultDice();
			if( ResultDice < 5){
				credits = m_bonus->calculateWin(credits,2);
				RenderBonusWin();
				Mix_PlayChannel( -1,m_bonus->Winning, 0 );
				SDL_Delay(2000);
				isClickWin = true;
			}else{
				//?
			}
		}

		if(m_bonus->GetWinX5().IsPressed() )
		{
			Mix_PlayChannel( -1,m_bonus->ButtonPress, 0 );
			Mix_PlayChannel( -1,m_bonus->RollDice, 0 );
			int ResultDice = m_bonus->ResultDice();
			if( ResultDice > 4 && ResultDice < 10 )
			{
				credits = m_bonus->calculateWin(credits,5);
				RenderBonusWin();
				Mix_PlayChannel( -1,m_bonus->Winning, 0 );
				SDL_Delay(2000);
				isClickWin = true;
			}else{
				//?
			}

		}
		if(m_bonus->GetWinX10().IsPressed() )
		{
			Mix_PlayChannel( -1,m_bonus->ButtonPress, 0 );
			Mix_PlayChannel( -1,m_bonus->RollDice, 0 );
			int ResultDice = m_bonus->ResultDice();
			if(ResultDice > 9 && ResultDice < 13)
			{
				credits = m_bonus->calculateWin(credits,10);
				RenderBonusWin();
				Mix_PlayChannel( -1,m_bonus->Winning, 0 );
				SDL_Delay(2000);
				isClickWin = true;
			}else{
				//?
			}
		}
}
//---------------------------------------------------
void Game::InitSDL()
{
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError();
		return;
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
	if(! (IMG_Init(imgFlags) & imgFlags ) )
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
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cerr<< "SDL_mixer could not initialize! SDL_mixer Error: "  << SDL_GetError();
		return;
	}
}

void Game::Close()
{
	SDL_DestroyWindow(m_window);
	m_window = nullptr;

	SDL_Quit();
}
