#include "Intro.h"
#include "Globals.h"
#include <iostream>
using std::cout;

Intro::Intro(SDL_Renderer* renderer, SDL_Event& event, eGameState& eGameState) : 
	GameState(renderer), m_tBackgorund(), m_event(&event),
	m_ptrGameState(&eGameState), 
	m_btnNewGame(renderer, "Resources/new-game-btn.png", 0, 0, 214 , 53),
	m_btnResumeGame(renderer, "Resources/resume-game-btn.png", 0, 0, 214, 53)
{
	//this->m_renderer = renderer;
	m_tBackgorund.LoadFromFile(renderer, "Resources/intro.png");
}

Intro::~Intro()
{
	std::cout << "Intro Deleted.\n";
}

void Intro::Draw()
{
	GameState::Draw();
}

void Intro::Render()
{
	//render background
	m_tBackgorund.Render(m_renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	//Render new game btn
	SDL_Rect r{0,0, 214, 53};
	m_btnNewGame.Render(m_renderer, &r, 20, 350, r.w, r.h);
	m_btnResumeGame.Render(m_renderer, &r, 20, 450, r.w, r.h);
}

void Intro::HandleEvent()
{
	switch(m_event->type)
	{
	case SDL_QUIT:
		*m_ptrGameState = QUIT;
		break;

	case SDL_MOUSEBUTTONDOWN:
		if(m_btnNewGame.IsPressed())
			*m_ptrGameState = PLAY;

		else if(m_btnResumeGame.IsPressed())
			*m_ptrGameState = PLAY;
		
		break;
	}

}
