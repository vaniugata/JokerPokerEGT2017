#include "Game.h"
#include "Globals.h"
#include <iostream>
using std::cerr;
#include <SDL_image.h>

Game::Game() : m_window(nullptr), m_renderer(nullptr), m_eGameState(INTRO),
	m_event()
{
	m_engine = new Engine;
	m_texture = new Texture;
	InitSDL();
	LoadMedia();
}

Game::~Game()
{
	delete m_texture;

	delete m_engine;
	std::cout << "Game deleted.\n";
	Close();
}

Texture * Game::GetTexture()
{
	return m_texture;
}

SDL_Renderer * Game::GetRenderer()
{
	return m_renderer;
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

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);

	//initialize image loading
	int imgFlags = IMG_INIT_PNG;
	if(! (IMG_Init(imgFlags) & imgFlags ) )
	{
		std::cerr << "SDL_image could not initialize! SDL_image Error: " << SDL_GetError();
		return;
	}
}

void Game::LoadMedia()
{
	m_texture->LoadFromFile(m_renderer, "../../Resources/arrow.png");
}

void Game::Close()
{
	SDL_DestroyRenderer(m_renderer);
	m_renderer = nullptr;

	SDL_DestroyWindow(m_window);
	m_window = nullptr;

	SDL_Quit();
}
