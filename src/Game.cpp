#include "Game.h"
#include "Globals.h"
#include <iostream>
using std::cerr;
#include "includesSDL2.h"

Game::Game() :
		m_dCredit(-1),m_window(nullptr), m_renderer(nullptr),
	m_eGameState(INTRO), m_event()
{
	InitSDL();

	m_tBackground = new Texture;
	m_tBackground->LoadFromFile(m_renderer, "Resources/back2.png");

	m_paytable = new PaytableObject(m_renderer);
	deck = new Deck(m_renderer);
}

Game::~Game()
{
	delete m_tBackground;
	delete m_paytable;
	delete deck;
	std::cout << "Game deleted.\n";
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
		m_tBackground->Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		//draw paytable
		m_paytable->Render(m_renderer);
		//draw bet buttons
		SDL_Rect clip1{ T_BTN_W_BET, 0, T_BTN_W_BET, T_BTN_H_BET };
		m_paytable->GetBetOneBtn().Render(m_renderer, &clip1, 750, 500);
		SDL_Rect clip2{ 0, 0, T_BTN_W_BET, T_BTN_H_BET };
		m_paytable->GetBetMaxBtn().Render(m_renderer, &clip2, 650, 500);

		deck->RenderHand(m_renderer);
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
			deck->deal();
			m_paytable->SetWinnerIndex(deck->evaluateHand());
			std::cout << "Hand value: "<< deck->evaluateHand() << "\n";
			std::cout << "Credit:" << m_dCredit << "\n";

		}
		else if(m_event.key.keysym.sym == SDLK_d)
		{
			m_eGameState = BONUS;
		}
}


void Game::ProcessMouseInput()
{
	if(m_paytable->GetBetOneBtn().IsSelected())
		{
			m_paytable->IncreaseBet();
		}

		if(m_paytable->GetBetMaxBtn().IsSelected())
		{
			m_paytable->SetMaxBet();
		}


}

void Game::InitSDL()
{
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
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
