#include "Game.h"
#include "Globals.h"
#include <iostream>
using std::cerr;
#include <SDL_image.h>
#include <SDL_ttf.h>

Game::Game() : 
	m_window(nullptr), m_renderer(nullptr), 
	m_eGameState(INTRO), m_event()
{
	InitSDL();

	m_tBackground = new Texture;
	m_tBackground->LoadFromFile(m_renderer, "../../Resources/back2.png");

	m_paytable = new PaytableObject(m_renderer);
}

Game::~Game()
{
	delete m_tBackground;
	delete m_paytable;

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

void Game::RenderScreen()
{
	SDL_RenderPresent(m_renderer);
	SDL_RenderClear(m_renderer);
}

void Game::Update()
{
	//draw background
	m_tBackground->Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	//draw paytable
	m_paytable->Render(m_renderer);
}

void Game::ProcessInput()
{
	if(m_event.key.keysym.sym == SDLK_SPACE)
	{
		m_paytable->IncreaseBet();
	}
}

void Game::InitSDL()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
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
}

void Game::Close()
{
	SDL_DestroyWindow(m_window);
	m_window = nullptr;

	SDL_Quit();
}
